West Kingdom Website Repository
===============================

This repository holds the code for the regognized website for the
Kingdom of the West of the Society for Creative Anachronism, Inc.

This project is based on the pattern shown in the [pantheon-systems/example-drupal7-composer](https://github.com/pantheon-systems/example-drupal7-composer) project.


Directory of Files
------------------

-  **drupal:** Drupal root
-  **features:** Behat tests
-  **scripts:** Define configuration and environment for tests
-  **bin:** Scripts provided from Composer dependencies.


Configuration
-------------

Uses drush_ctex_bonus to export configuration, which is imported again via the [install-configuration](https://github.com/westkingdom/website/blob/master/scripts/install-configuration) script.


Deploying Changes
-----------------

After making any change to the site, create a pull request on GitHub. This will cause all of the unit tests to run on Circle CI.

Once the tests pass, merge the PR into the `master` branch as usual. This will automatically deploy the site to the live site at http://westkingdom.org. 

If you would like to test on the stage site (http://stage.westkingdom.org) first, then push code to the 'stage' branch. Inspect the deployed site and ensure that everything is operational. The staging site is protected with basic authentication to discourage web browsers. The username is `WEST` and the password is `WEST`.

Testing Locally
---------------

Run:

./bin/local-test

