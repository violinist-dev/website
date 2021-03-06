<?php

/**
 * @file
 * Bulk export of filters generated by Drush Ctools Export Bonus.
 * Use drush cbrff modulename to rebuild filters.
 */

/**
 * Implements hook_drush_ctex_bonus_filters().
 */
function wk_config_drush_ctex_bonus_filters() {
  $filters = array();

  $filters['1'] = (object) array(
    'format' => '1',
    'name' => 'Simple styled text',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<div> <form> <input> <table> <h1> <h2> <h3> <h4> <h5> <h6> <tr> <td> <th> <tbody> <a> <em> <strong> <i> <b> <cite> <code> <ul> <ol> <li> <dl> <dt> <dd> <blockquote> <span> <font> <p> <br> <hr> <img> <strike>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'media_filter' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '-42',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_officer' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          '[:West Kingdom/Web Minister:]' => 'Gregor Eilburg',
          'group_shorten_function' => '',
        ),
      ),
    ),
  );

  $filters['styled_text_with_images'] = (object) array(
    'format' => 'styled_text_with_images',
    'name' => 'Styled Text with Headers and Images',
    'cache' => '1',
    'status' => '1',
    'weight' => '-9',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'wysiwyg' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(
          'valid_elements' => 'a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
span[style],
table[style|border|cellpadding|cellspacing],
th[style],
tbody,
tr[style],
td[style|colspan|rowspan],
br,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img,hr',
          'allow_comments' => '0',
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(
            0 => 'westkingdom.org',
          ),
          'style_color' => array(
            'color' => 'color',
            'background' => 0,
            'background-color' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font' => 0,
            'font-family' => 0,
            'font-size' => 0,
            'font-size-adjust' => 0,
            'font-stretch' => 0,
            'font-style' => 0,
            'font-variant' => 0,
            'font-weight' => 0,
          ),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-indent' => 'text-indent',
            'text-decoration' => 0,
            'text-transform' => 0,
            'letter-spacing' => 0,
            'word-spacing' => 0,
            'white-space' => 0,
            'direction' => 0,
            'unicode-bidi' => 0,
          ),
          'style_box' => array(
            'margin' => 0,
            'margin-top' => 0,
            'margin-right' => 0,
            'margin-bottom' => 0,
            'margin-left' => 0,
            'padding' => 0,
            'padding-top' => 0,
            'padding-right' => 0,
            'padding-bottom' => 0,
            'padding-left' => 0,
          ),
          'style_border-1' => array(
            'border' => 'border',
            'border-top' => 0,
            'border-right' => 0,
            'border-bottom' => 0,
            'border-left' => 0,
            'border-width' => 0,
            'border-top-width' => 0,
            'border-right-width' => 0,
            'border-bottom-width' => 0,
            'border-left-width' => 0,
          ),
          'style_border-2' => array(
            'border-color' => 'border-color',
            'border-top-color' => 0,
            'border-right-color' => 0,
            'border-bottom-color' => 0,
            'border-left-color' => 0,
            'border-style' => 0,
            'border-top-style' => 0,
            'border-right-style' => 0,
            'border-bottom-style' => 0,
            'border-left-style' => 0,
          ),
          'style_dimension' => array(
            'width' => 'width',
            'height' => 0,
            'line-height' => 0,
            'max-height' => 0,
            'max-width' => 0,
            'min-height' => 0,
            'min-width' => 0,
          ),
          'style_positioning' => array(
            'vertical-align' => 'vertical-align',
            'bottom' => 0,
            'clip' => 0,
            'left' => 0,
            'overflow' => 0,
            'right' => 0,
            'top' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'clear' => 0,
            'display' => 0,
            'float' => 0,
            'position' => 0,
            'visibility' => 0,
          ),
          'style_list' => array(
            'list-style' => 'list-style',
            'list-style-image' => 'list-style-image',
            'list-style-position' => 'list-style-position',
            'list-style-type' => 'list-style-type',
          ),
          'style_table' => array(
            'border-collapse' => 0,
            'border-spacing' => 0,
            'caption-side' => 0,
            'empty-cells' => 0,
            'table-layout' => 0,
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '-42',
        'status' => '1',
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => '-41',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_officer' => array(
        'weight' => '-40',
        'status' => '1',
        'settings' => array(
          '[:West Kingdom/Web Minister:]' => 'Gregor Eilburg',
          'group_shorten_function' => '',
        ),
      ),
    ),
  );

  $filters['simple_styles_only'] = (object) array(
    'format' => 'simple_styles_only',
    'name' => 'Deprecated Simple Styles',
    'cache' => '1',
    'status' => '1',
    'weight' => '-8',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <i> <b> <strike> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <br> <h1> <h2> <h3> <h4> <h5>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(),
      ),
      'ckeditor_link_filter' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-41',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_officer' => array(
        'weight' => '-40',
        'status' => '1',
        'settings' => array(
          '[:West Kingdom/Web Minister:]' => 'Gregor Eilburg',
          'group_shorten_function' => '',
        ),
      ),
    ),
  );

  $filters['4'] = (object) array(
    'format' => '4',
    'name' => 'Unrestricted Styled Text',
    'cache' => '0',
    'status' => '1',
    'weight' => '-7',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_officer' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          '[:West Kingdom/Web Minister:]' => 'Gregor Eilburg',
          'group_shorten_function' => '',
        ),
      ),
      'filter_tokens' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  $filters['2'] = (object) array(
    'format' => '2',
    'name' => 'Raw HTML',
    'cache' => '0',
    'status' => '1',
    'weight' => '-6',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_officer' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          '[:West Kingdom/Web Minister:]' => 'Gregor Eilburg',
          'group_shorten_function' => '',
        ),
      ),
      'filter_tokens' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  $filters['5'] = (object) array(
    'format' => '5',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '-5',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $filters;
}
