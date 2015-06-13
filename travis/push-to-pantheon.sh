#!/bin/bash

#
# Exit with a message if the previous function returned an error.
#
# Usage:
#
#   aborterr "Description of what went wrong"
#
function aborterr() {
  if [ $? != 0 ]
  then
    echo "$1" >&2
    exit 1
  fi
}

#
# Check the result of the last operation, and either print progress or call aborterr
#
# Usage:
#
#   check "Something the script did" "Message to display if it did not work"
#
function check() {
  aborterr "$2"
  echo "$1"
}

# Add vendor/bin and $HOME/bin to our $PATH
export PATH="$TRAVIS_BUILD_DIR/bin:$HOME/bin:$PATH"

# Do not attempt to push the site up to Pantheon unless the PPASS
# environment variable is set.  If we receive a PR from an external
# repository, then the secure environment variables will not be set;
# if we test PRs, we cannot send them to Pantheon in this instance.
if [ -n "$PPASS" ]
then
  # Dynamic hosts through Pantheon mean constantly checking interactively
  # that we mean to connect to an unknown host. We ignore those here.
  echo "StrictHostKeyChecking no" > ~/.ssh/config

  # Capture the commit message
  export TRAVIS_COMMIT_MSG="$(git log --format=%B --no-merges -n 1)"

  # Install Terminus
  curl https://github.com/pantheon-systems/cli/releases/download/0.5.5/terminus.phar -L -o $HOME/bin/terminus
  chmod +x $HOME/bin/terminus

  # Set up Terminus and aliases, and wake up the site
  echo "Log in to Pantheon via Terminus"
  # Redirect output when logging in.  Terminus prints the email address
  # used during login to stdout, which will end up in the log.  It's better
  # to conceal the email address used, to make it harder for a third party
  # to try to log in via a brute-force password-guessing attack.
  terminus auth login "$PEMAIL" --password="$PPASS" >/dev/null 2>&1
  check "Logged in to Pantheon via Terminus" "Could not log in to Pantheon with Terminus"
  echo "Fetch aliases via Terminus"
  mkdir -p $HOME/.drush
  terminus sites aliases
  aborterr "Could not fetch aliases via Terminus"
  echo "Wake up the site $PSITE"
  terminus site wake --site="$PSITE" --env="$PENV"
  check "Site wakeup successful" "Could not wake up site"
  PUUID=$(terminus site info --site="$PSITE" --field=id)
  aborterr "Could not get UUID for $PSITE"

  # Identify the automation user
  git config --global user.email "bot@westkingdom.org"
  git config --global user.name "West Kingdom Automation"

  # Clone the Pantheon repository into a separate directory, then
  # move the .git file to the location where we placed our composer targets
  cd $TRAVIS_BUILD_DIR
  REPO="ssh://codeserver.dev.$PUUID@codeserver.dev.$PUUID.drush.in:2222/~/repository.git"
  git clone --depth 1 "$REPO" $HOME/pantheon
  check "git clone successful" "Could not clone repository from $REPO"
  mv $HOME/pantheon/.git $TRAVIS_BUILD_DIR/htdocs
  cd $TRAVIS_BUILD_DIR/htdocs

  # Do the settings.php shuffle for an empty settings.php
  # This prevents permissions issues with the sites/default directory
  cp sites/default/default.settings.php sites/default/settings.php

  # Output of the diff vs upstream.
  echo "Here's the status change!"
  git status

  # Make sure we are in git mode
  terminus site connection-mode --site="$PSITE" --env="$PENV" --set=git
  check "Changed connection mode to 'git' for $PSITE $PENV environment" "Could not change connection mode to 'git' for $PSITE $PENV environment"

  # Push our built files up to Pantheon
  git add --all
  aborterr "'git add --all' failed"
  git commit -a -m "Makefile build by CI: '$TRAVIS_COMMIT_MSG'"
  aborterr "'git commit' failed"
  git push origin master
  aborterr "'git push' failed"

  # We'll run 'drush status' once to fire up the ssh connection
  # (get rid of the junk line it prints on first run)
  echo "Drush status on the remote site:"
  drush --strict=0 @pantheon.$PSITE.$PENV status

  # Check to see if there is already a site installed on the specified environment
  BOOTSTRAPPED=$(drush  --strict=0 @pantheon.$PSITE.$PENV status "Drupal bootstrap")
  aborterr "Could not look up status of $PSITE on Pantheon"
  if [ -z "$BOOTSTRAPPED" ]
  then
    # We need to go back to sftp mode to run site-install
    terminus site connection-mode --site="$PSITE" --env="$PENV" --set=sftp
    check "Changed connection mode to 'sftp' for $PSITE $PENV environment" "Could not change connection mode to 'sftp' for $PSITE $PENV environment"
    # Wipe the site before running site-install
    terminus site wipe --site="$PSITE" --env="$PENV"
    # Create a new site with site-install.
    drush --strict=0 @pantheon.$PSITE.$PENV -y site-install standard --site-name="$SITE_NAME Pantheon Test Site" --account-name=admin --account-pass="[REDACTED]"
    # Because the site password is in the log, generate a new random
    # password for the site, and change it.  The site owner can use
    # `drush uli` to log in.
    RANDPASS=$(cat /dev/urandom | env LC_CTYPE=C tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1 )
    drush --strict=0 @pantheon.$PSITE.$PENV user-password admin --password="$RANDPASS"
    aborterr "Could not reset password on Pantheon test site"
  else
    # If the database already exists, just run updatedb to bring it up-to-date
    # with the code we just pushed.
    # n.b. If we wanted to re-run our behat tests on the pantheon site, then
    # we would probably want to install a fresh site every time.
    drush --strict=0 @pantheon.$PSITE.$PENV updatedb
    aborterr "updatedb failed on Pantheon site"
  fi
fi
