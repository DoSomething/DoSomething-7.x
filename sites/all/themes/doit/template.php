<?php

function doit_preprocess_html(&$variables, $hook) {
  // dsm($hook);
  // dsm($variables);
  $theme_path = drupal_get_path('theme', 'doit');
  $variables['selectivizr'] = '<!--[if (gte IE 6)&(lte IE 8)]>';
  // mootools causes AJAX conflicts. Selectivizr works without it.
  // $variables['selectivizr'] .= '<script type="text/javascript" src="/' . $theme_path . '/js/mootools-core-1.4.1-full-nocompat-yc.js'  . '"></script>';
  // instead, let's just use what we need. See: https://github.com/keithclark/JQuery-Extended-Selectors
  $variables['selectivizr'] .= '<script type="text/javascript" src="/' . $theme_path . '/js/jquery-extra-selectors.js' . '"></script>';
  $variables['selectivizr'] .= '<script type="text/javascript" src="/' . $theme_path . '/js/selectivizr/selectivizr-min.js'  . '"></script>';
  $variables['selectivizr'] .= '<![endif]-->';
  // HTML5 Shiv
  $variables['shiv'] = '<!--[if lt IE 9]><script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->';
  $variables['placeholder_shiv'] = '<!--[if lt IE 9]><script type="text/javascript" src="/' . $theme_path . '/js/do-it-placeholder.js'  . '"></script><![endif]-->';

}

function doit_preprocess_page(&$variables) {
  $theme_path = drupal_get_path('theme', 'doit');
  if (!isset($variables['secondary_links_theme_function'])) {
    $variables['secondary_links_theme_function'] = 'links__system_secondary_menu';
  }

  drupal_alter('page_templates', $variables);

  // Add Social Tracking for Google Analytics
  drupal_add_js($theme_path . '/js/ga_social_tracking.js', array(
    'every_page' => TRUE,
  ));

  // Add Formalize to even out most form elements
  drupal_add_js($theme_path . '/js/formalize/jquery.formalize.min.js', array(
    'scope' => 'footer',
    'every_page' => TRUE
  ));

  // replace select boxes to allow custom theming
  drupal_add_js($theme_path . '/js/jQuery-SelectBox/jquery.selectBox.min.js', array(
    'scope' => 'footer',
    'every_page' => TRUE,
  ));
  drupal_add_js($theme_path . '/js/doit-select.js', array(
    'scope' => 'footer',
    'every_page' => TRUE,
  ));

  // Add lets_talk_dialogue.js to 'Talk to Us' footer menu item.
  if (isset($variables['page']['footer']['menu_menu-footer']['90436']['#below']['93450']) && arg(0) !== 'admin') {
    // Add additional css class to 'Talk to Us' footer menu item.
    $variables['page']['footer']['menu_menu-footer']['90436']['#below']['93450']['#attributes']['class'][] = 'talk-to-us';
    drupal_add_js(drupal_get_path('module', 'dosomething_blocks') .'/js/lets_talk_dialog.js', 'file');
  }

  // Add lettering.js for vital stat counter.
  drupal_add_js($theme_path . '/js/jquery.lettering-0.6.min.js', array(
    'scope' => 'footer',
    'every_page' => TRUE,
  ));
  drupal_add_js($theme_path . '/js/doit-lettering.js', array(
    'scope' => 'footer',
    'every_page' => TRUE,
  ));

  // Add search facets js
  drupal_add_js($theme_path . '/js/show-search-facets.js', array(
    'scope' => 'footer',
    'every_page' => TRUE,
  ));

  // Set the webform title to use the submitted title value rather than what is set in webform_submission_title()
  if (!empty($variables['page']['content']['system_main']['#theme'])) {
    if ($variables['page']['content']['system_main']['#theme'] == 'webform_submission_page') {
      drupal_set_title($variables['page']['content']['system_main']['#submission']->field_project_title['und'][0]['value']);
    }
  }

  // gate beta campaign page
  $beta_campaign = variable_get('beta_campaign_nid', 724796);
  if (!user_is_logged_in() && ( (arg(0) == 'node') && (arg(1) == $beta_campaign))) {
    drupal_goto('user/registration?destination=node/' . $beta_campaign);
  }

  // Load Webfonts specific to the page
  if (module_exists('dosomething_perfomance_toolbox')) {
    dosomething_perfomance_toolbox_webfonts();
  }

  // Check it this is a node page
  $obj = menu_get_object();

  // Bootstrap with campaign assets (tpl, css, js)
  if (isset($obj->nid)) _doit_load_campaign_assets($obj);

}

/**
 * Loads campaign specific tpl, css and js files
 */
function _doit_load_campaign_assets($node) {

  // @todo - we may need to refactor based on campaign related nodes
  if ($node->type != 'campaign') return;

  $theme_path = drupal_get_path('theme', 'doit');
  $css_path =  $theme_path . '/css/campaigns';
  $js_path =  $theme_path . '/js/campaigns';

  // Add global css and js
  drupal_add_css($css_path . '/campaigns.css');
  drupal_add_js($js_path . '/campaigns.js');

  $org_code_items = field_get_items('node', $node, 'field_organization_code', $node->language);

  // If the camapign has org code set
  if( $org_code_items ) {
    $org_code = $org_code_items[0]['value'];
    // Add campaign specific tpl, css and js
    array_push( $vars['theme_hook_suggestions'], 'node__campaign__' . $org_code );
    drupal_add_css($css_path . '/' . $org_code . '/' . $org_code . '.css');
    drupal_add_js($js_path . '/' . $org_code . '/' . $org_code . '.js');
  }
}

// preprocess maintenance page copy for 500 error
function doit_preprocess_maintenance_page(&$vars) {
    if ($GLOBALS['conf']['maintenance_mode'] === 0) {

      // Include fonts in error page
      dosomething_perfomance_toolbox_webfonts();

      /* we have an error */
      $vars['content'] = '<p>' . t("We're on it! For now, try refreshing the page.") . '</p>';
    }
}

function doit_preprocess_block(&$variables) {
  $theme_path = drupal_get_path('theme', 'doit');

  // set a .block-title class on the title
  $variables['title_attributes_array']['class'][] = 'block-title';
}

function doit_preprocess_rotoslider_slider(&$variables) {
  $theme_path = drupal_get_path('theme', 'doit');
  $variables['element']['#attached']['css'][] = $theme_path . '/css/doit/dosomething-rotoslider.css';
  $variables['element']['#attached']['js'][] = $theme_path . '/js/doit-rotoslider.js';
  if (!empty($variables['image'])) {
    $initial = $variables['items'][0];
    $variables['element']['descriptions']['do-this'] = array(
      '#type' => 'link',
      '#title' => t('Do This'),
      '#href' => $initial['uri']['path'],
      '#options' => $initial['uri']['options'] + array(
        'attributes' => array(
          'class' => array(
            'do-this-link',
          ),
        ),
      ),
    );
  }
}

/**
 * Overrides theme_date_display_range().
 */
function doit_date_display_range($vars) {
  $date1 = $vars['date1'];
  $date2 = $vars['date2'];
  $timezone = $vars['timezone'];
  $attributes_start = $vars['attributes_start'];
  $attributes_end = $vars['attributes_end'];

  // Wrap the result with the attributes.
  return t('!start-date - !end-date', array(
    '!start-date' => '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>',
    '!end-date' => '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . $timezone. '</span>',
  ));
}

/**
 * Overwrites all user profiled pics with Facebook photo.
 * user_picture is empty by design if they are not connected to Facebook.
 */
function doit_preprocess_user_picture(&$variables) {
  $variables['user_picture'] = '';
    $account = $variables['account'];
    if ($account && module_exists('fboauth') && $fbid = fboauth_fbid_load($account->uid)) {
      $filepath = 'https://graph.facebook.com/' . $fbid . '/picture?type=large';
      $alt = t("@user's picture", array('@user' => format_username($account)));
      if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
        $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
      }
      else {
        $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
      }
      if (!empty($account->uid) && user_access('access user profiles')) {
        $attributes = array(
          'attributes' => array('title' => t('View user profile.')),
          'html' => TRUE,
        );
        $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
      }
    }
}

/**
 * Overwrites theme_webform_view_messages().
 */
function doit_webform_view_messages($variables) {
  global $user;

  $node = $variables['node'];
  $teaser = $variables['teaser'];
  $page = $variables['page'];
  $submission_count = $variables['submission_count'];
  $user_limit_exceeded = $variables['user_limit_exceeded'];
  $total_limit_exceeded = $variables['total_limit_exceeded'];
  $allowed_roles = $variables['allowed_roles'];
  $closed = $variables['closed'];
  $cached = $variables['cached'];

  $type = 'status';

  if ($closed) {
    $message = t('Submissions for this form are closed.');
  }
  // If open and not allowed to submit the form, give an explanation.
  elseif (array_search(TRUE, $allowed_roles) === FALSE && $user->uid != 1) {
    if (empty($allowed_roles)) {
      // No roles are allowed to submit the form.
      $message = t('Submissions for this form are closed.');
    }
    elseif (isset($allowed_roles[2]) || !$user->uid) {
      // The "authenticated user" role is allowed to submit and the user is currently logged-out.
      // We send them to register in this case.
      // If the form does not allow 'members', then they will get a message
      // that they can't edit when they come back.
      $login = url('user/login', array('query' => drupal_get_destination()));
      drupal_set_message(t('You must <a href="!login">login</a> or register to view this form.', array('!login' => $login)));
      drupal_goto('user/registration', array('query' => drupal_get_destination()));
    }
    else {
      // The user must be some other role to submit.
      $message = t('You do not have permission to view this form.');
    }
  }

  // If the user has exceeded the limit of submissions, explain the limit.
  elseif ($user_limit_exceeded && !$cached) {
    if ($node->webform['submit_interval'] == -1 && $node->webform['submit_limit'] > 1) {
      $message = t('You have submitted this form the maximum number of times (@count).', array('@count' => $node->webform['submit_limit']));
    }
    elseif ($node->webform['submit_interval'] == -1 && $node->webform['submit_limit'] == 1) {
      $message = t('You have already submitted this form.');
    }
    else {
      $message = t('You may not submit another entry at this time.');
    }
    $type = 'error';
  }
  elseif ($total_limit_exceeded && !$cached) {
    if ($node->webform['total_submit_interval'] == -1 && $node->webform['total_submit_limit'] > 1) {
      $message = t('This form has received the maximum number of entries.');
    }
    else {
      $message = t('You may not submit another entry at this time.');
    }
  }

  // If the user has submitted before, give them a link to their submissions.
  if ($submission_count > 0 && $node->webform['submit_notice'] == 1 && !$cached) {
    if (empty($message)) {
      $message = t('You have already submitted this form.') . ' ' . t('<a href="!url">View your previous submissions</a>.', array('!url' => url('node/' . $node->nid . '/submissions')));
    }
    else {
      $message .= ' ' . t('<a href="!url">View your previous submissions</a>.', array('!url' => url('node/' . $node->nid . '/submissions')));
    }
  }

  if ($page && isset($message)) {
    drupal_set_message($message, $type, FALSE);
  }
}

/**
 * Implements hook_date_part_label_date();
 * Set start and end date labels.
 */
function doit_date_part_label_date($vars) {
  $part_type = $vars['part_type'];
  $element = $vars['element'];
  if (stripos($element['#date_title'], 'start date')) {
    return t('Start Date', array(), array('context' => 'datetime'));
  }
  if (stripos($element['#date_title'], 'end date')) {
    return t('End Date', array(), array('context' => 'datetime'));
  }
}


function doit_image_formatter($variables) {
  // dsm('doit_image_formatter');
  // dsm($variables);
  $item = $variables['item'];
  $image = array(
    'path' => (isset($item['uri']) ? $item['uri'] : ''),
    'alt' => (isset($item['alt']) ? $item['alt'] : ''),
  );

  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  // Do not output an empty 'title' attribute.
  if (isset($image['title'])) {
    if (drupal_strlen($item['title']) > 0) {
      $image['title'] = $item['title'];
    }
  }

  if ($variables['image_style']) {
    $image['style_name'] = $variables['image_style'];
    $output = theme('image_style', $image);
  }
  else {
    $output = theme('image', $image);
  }

  if (!empty($variables['path']['path'])) {
    $path = $variables['path']['path'];
    $options = $variables['path']['options'];
    // When displaying an image inside a link, the html option must be TRUE.
    $options['html'] = TRUE;
    $output = l($output, $path, $options);
  }

  return $output;
}


function doit_field($variables) {
  // dsm($variables);
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    if ($variables['element']['#field_type'] == 'image') {
      $title = '';
      if (isset($item['#item']['title'])) {
        $title = $item['#item']['title'];
      }

      if (strlen($title) > 0) {
        $variables['item_attributes'][$delta] .= ' data-img-title="' . $title . '" ';
      }
    }
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements template_preprocess_field().
 */
function doit_preprocess_field(&$vars, $hook) {

  switch ($vars['element']['#field_name']) {
    case 'field_campaign_faq':
      $questions = array();
      foreach ($vars['items'] as $item) {
        $item = current($item['entity']['field_collection_item']);
        $questions[] = array(
          'question' => $item['field_faq_question'][0]['#markup'],
          'answer' => $item['field_faq_answer'][0]['#markup']
        );
      }
      $vars['questions'] = $questions;
      break;
  }
}

function doit_pager(&$variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = 5;
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Override of theme_search_api_page_results().
 */
function doit_search_api_page_results(array $variables) {

  $index = $variables['index'];
  $results = $variables['results'];
  $items = $variables['items'];
  $keys = $variables['keys'];

  $search_performance = '<p class="search-performance">' . format_plural($results['result count'],
      'The search found 1 result in @sec seconds.',
      'The search found @count results in @sec seconds.',
      array('@sec' => round($results['performance']['complete'], 3))) . '</p>';

  if (!$results['result count']) {
    $output = "<h2>" . t('Your search yielded no results') . "</h2>";
    $output .= $search_performance;
    return $output;
  }

  $output = "<h2>" . t('You Searched ') . t('“') . $keys . t('”') . "</h2>";
  $output .= $search_performance;

  if ($variables['view_mode'] == 'search_api_page_result') {
    $output .= '<ul class="search-results">';
    foreach ($results['results'] as $item) {
      $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'item' => isset($items[$item['id']]) ? $items[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
    }
    $output .= '</ul>';
  }
  else {
    // This option can only be set when the items are entities.
    $output .= '<div class="search-results">';
    $render = entity_view($index->item_type, $items, $variables['view_mode']);
    $output .= render($render);
    $output .= '</div>';
  }

  return $output;
}

/**
 * Theme function for displaying search results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - result: One item of the search results, an array containing the keys
 *     'id' and 'score'.
 *   - item: The loaded item corresponding to the result.
 *   - keys: The keywords of the executed search.
 */
function doit_search_api_page_result(array $variables) {
  $index = $variables['index'];
  $id = $variables['result']['id'];
  $item = $variables['item'];

  $wrapper = $index->entityWrapper($item, FALSE);

  $url = $index->datasource()->getItemUrl($item);
  $name = $index->datasource()->getItemLabel($item);

  if (!empty($variables['result']['excerpt'])) {
    $text = $variables['result']['excerpt'];
  }
  else {
    $fields = $index->options['fields'];
    $fields = array_intersect_key($fields, drupal_map_assoc($index->getFulltextFields()));
    $fields = search_api_extract_fields($wrapper, $fields);
    $text = '';
    $length = 0;
    foreach ($fields as $field) {
      if (search_api_is_list_type($field['type']) || !isset($field['value'])) {
        continue;
      }
      $val_length = drupal_strlen($field['value']);
      if ($val_length > $length) {
        $text = $field['value'];
        $length = $val_length;
      }
    }
    if ($text && function_exists('text_summary')) {
      $text = text_summary($text);
    }
  }

  $output = '';
  // We need to insert images into the search results so we're mapping the
  // content type to the image field we want to use. For now we're only
  // concerned about a few content types. This list may grow as needed.
  $type_field_map = array(
    'blog' => 'field_picture',
    'campaign' => 'field_campain_main_image',
    'cause_video' => '',
    'editorial_content' => 'field_editorial_image',
    'tips_and_tools' => 'field_picture',
  );
  if (isset($item->type) && in_array($item->type, array_keys($type_field_map))) {
    if (isset($item->{$type_field_map[$item->type]}) && !empty($item->{$type_field_map[$item->type]}[LANGUAGE_NONE][0])) {
      $output .= theme('image_formatter', array(
        'item' => array('uri' => $item->{$type_field_map[$item->type]}[LANGUAGE_NONE][0]['uri']),
        'image_style' => 'search_results_thumbnail'
      ));
    }
    else {
      $output .= theme('image', array('path' => drupal_get_path('theme', 'doit') . '/css/images/default-search-image.jpg', 'height' => '60px', 'width' => '60px'));
    }
  }
  else {
     $output .= theme('image', array('path' => drupal_get_path('theme', 'doit') . '/css/images/default-search-image.jpg', 'height' => '60px', 'width' => '60px'));
  }

  // Fix for bug / request #955: Move title next to image
  $output .= '<h3>' . ($url ? l($name, $url['path'], $url['options']) : check_plain($name)) . "</h3>\n";

  if ($text) {
    $output .= $text;
  }

  return $output;
}
