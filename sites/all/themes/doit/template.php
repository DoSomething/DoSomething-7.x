<?php

/**
 * Implements hook_preprocess_html()).
 */
function doit_preprocess_html(&$variables, $hook) {
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

  if(drupal_is_front_page()) {
    $variables['head_title_array'] = array(
      'title' => variable_get('site_name', 'Do Something'),
      'name' => variable_get('site_slogan', 'Largest organization for teens and social cause')
    );
    $variables['head_title'] = implode($variables['head_title_array'], ' | ');
  }
  
  /*
   * Remove all global stylesheets and
   * load user registration HTML templates
   * if this is a user-registration template page or campaign join page.
   */
  if (doit_is_user_registration_template_page() || doit_is_campaign_join_template_page()) {

    $variables['theme_hook_suggestions'][] = 'html__user__registration';
    $css = drupal_add_css();

    // Exclude all stylesheets except the following:
    // ['https://c308566.ssl.cf1.rackcdn.com/din-511.css']
    // ['sites/all/themes/doit/css/user-registration.css']

    unset(
      $css['sites/all/themes/doit/css/style.css'],
      $css['sites/all/themes/doit/css/tweetbutton.css'],
      $css['sites/all/themes/doit/css/views.css'],
      $css['sites/all/modules/chartbeat/chartbeat.css'],
      $css['public://css_injector/css_injector_6.css'],
      $css['sites/all/modules/ctools/css/ctools.css'],
      $css['modules/system/system.base.css'],
      $css['modules/system/system.menus.css'],
      $css['modules/system/system.messages.css'],
      $css['modules/system/system.theme.css'],
      $css['sites/all/modules/date/date_api/date.css'],
      $css['sites/all/modules/date/date_popup/themes/datepicker.1.7.css'],
      $css['sites/all/modules/dosomething/connections/css/connections-rules.css'],
      $css['modules/field/theme/field.css'],
      $css['modules/node/node.css'],
      $css['modules/poll/poll.css'],
      $css['modules/search/search.css'],
      $css['modules/user/user.css'],
      $css['sites/all/modules/views/css/views.css'],
      $css['sites/all/modules/views_slideshow/views_slideshow.css'],
      $css['sites/all/modules/panels/css/panels.css'],
      $css['sites/all/modules/dosomething/dosomething_blocks/css/twitter-widget.css']
    );

    $variables['user_styles'] = drupal_get_css($css);

  }
  
  drupal_alter('html_templates', $variables);

  if (doit_is_neue_page()) {
    $variables['theme_hook_suggestions'][] = 'html__neue';
    $css = drupal_add_css();
    $variables['classes_array'] = array();
    if (drupal_is_front_page()) {
      $variables['classes_array'][] = 'homepage';
    }
    $variables['classes'] = implode(' ', $variables['classes_array']);
  }

}

/**
 * Implements hook_preprocess_page().
 */
function doit_preprocess_page(&$variables) {
  $theme_path = drupal_get_path('theme', 'doit');
  $current_path = current_path();

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

  // Load Webfonts specific to the page
  if (module_exists('dosomething_perfomance_toolbox')) {
    dosomething_perfomance_toolbox_webfonts();
  }

  // Check it this is a node page
  $obj = menu_get_object();

  if(drupal_is_front_page() && theme_get_setting('doit_homepage_neue')) {
    _doit_load_menu_templates($variables);
    array_push( $variables['theme_hook_suggestions'], 'page__neue__front' );
    drupal_add_library('ds_neue', 'ds-neue');
  }

  $menu_obj = menu_get_object();
  if (is_object($menu_obj) && isset($menu_obj->type) && $menu_obj->type == 'page' && theme_get_setting('doit_pages_neue')) {
    _doit_load_menu_templates($variables);
    array_push( $variables['theme_hook_suggestions'], 'page__neue' );
    drupal_add_library('ds_neue', 'ds-neue');
  }

  // Bootstrap with campaign assets (tpl, css, js)
  if (isset($obj->nid)) {
    if ($obj->type == 'campaign') {
      // Load CSS and JS for admin toggle button
      global $user;
      if (in_array('administrator', array_values($user->roles))) {
        drupal_add_js($theme_path . '/js/admin-toggle.js', array(
          'scope' => 'footer',
          'every_page' => TRUE,
        ));
        drupal_add_css($theme_path . '/css/admin-toggle.css');
      }
    }
    elseif ($obj->type == 'project') {

      _doit_load_menu_templates($variables);

      // Add campaigns type specific page type
      array_push( $variables['theme_hook_suggestions'], 'page__neue' );

      $org_code = _doit_load_project_org_code($obj);

      if ($org_code) {
        // Add campaigns specific page type
        array_push( $variables['theme_hook_suggestions'], 'page__project__' . $org_code );
      }

      _doit_load_project_assets($obj, $org_code);

      // Add Project Content Type-specific CSS
      drupal_add_css($theme_path . '/css/neue-drupal/neue-plupload.css');
    }

  }
  // If campaign join page:
  if (doit_is_campaign_join_template_page()) {
    // Load page template:
    $variables['theme_hook_suggestions'][] = 'page__campaign__join';
    // Use default user-registration page specfic CSS/JS files:
    drupal_add_js(drupal_get_path('theme', 'doit') . '/js/user-registration.js');
    drupal_add_css(drupal_get_path('theme', 'doit') . '/css/user-registration.css');
  }

  $destination = drupal_get_destination();
  // Load user-registration page templates and gate values if this is a user-registration template page:
  if (doit_is_user_registration_template_page()) {
    // Use user-registration page template:
    $variables['theme_hook_suggestions'][] = 'page__user__registration';
    // Use default user-registration page specfic CSS/JS files:
    drupal_add_js(drupal_get_path('theme', 'doit') . '/js/user-registration.js');
    drupal_add_css(drupal_get_path('theme', 'doit') . '/css/user-registration.css');
    $default_gate = TRUE;
    // If there is a destination set in the query string:
    if ($destination['destination'] != $current_path) {
      $dest_path_parts = explode('/', $destination['destination']);
      // If the destination == node/[nid]:
      if ($dest_path_parts[0] == 'node' && is_numeric($dest_path_parts[1]) && !isset($dest_path_parts[2])) {
        // Load the node:
        $node = node_load($dest_path_parts[1]);
        // Check for TFJ nid.
        $tfj_nid = variable_get('tfj_campaign_nid', 731115);
        // If the destination node is the TFJ campaign, or its a regular gated node:
        if ( $node->nid == $tfj_nid || (module_exists('dosomething_login') && dosomething_login_is_gated_node($node)) ) {
          // Load node values for gate copy and image.
          $default_gate = FALSE;
          $variables['page'] = array_merge($variables['page'], dosomething_login_get_gate_vars($node));
          if (isset($node->field_gate_page_title[LANGUAGE_NONE][0]['value']) && $current_path == 'user/registration') {
            drupal_set_title($node->field_gate_page_title[LANGUAGE_NONE][0]['value']);
          }
        }
      }
    }
    // If default gate, use gate variables from DoSomething Login config page:
    if ($default_gate && module_exists('dosomething_login')) {
      $variables['page'] = array_merge($variables['page'], dosomething_login_get_gate_vars());
      $page_title = variable_get('dosomething_login_gate_page_title', NULL);
      if ($page_title && $current_path == 'user/registration') {
        drupal_set_title(variable_get('dosomething_login_gate_page_title'));
      }
    }
    // Determine what page we're on, and populate other gate variables accordingly.
    $is_user_password_page = FALSE;
    if ($current_path == 'user/registration') {
      $gate_link_path = 'user/login';
      $gate_link_text = 'sign in';
    }
    else {
      $gate_link_path = 'user/registration';
      $gate_link_text = 'register';
      if ($current_path == 'user/password') {
        $variables['page']['gate_headline'] = t('Forgot your password?');
        $variables['messages'] = theme('status_messages');
        $is_user_password_page = TRUE;
      }
      else {
        $variables['page']['gate_headline'] = t('Sign In');
      }
    }
    // If there's a destination in the URL, gate links need it.
    if ($destination['destination'] != $current_path) {
      $gate_link_query = array('query' => array('destination' => $destination['destination']));
    }
    else {
      $gate_link_query = array();
    }
    $variables['page']['gate_link'] = l(t($gate_link_text), $gate_link_path, $gate_link_query);
    if ($is_user_password_page) {
      $variables['page']['gate_go_back_link'] = l(t('go back'), 'user/login', $gate_link_query);
    }
    else {
      $variables['page']['gate_go_back_link'] = FALSE;
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function doit_preprocess_node(&$vars) {

  // Project node type:
  if ($vars['node']->type == 'project') {
    
    $org_code = _doit_load_project_org_code($vars['node']);
    // If the camapign has org code set:
    if ($org_code) {
      // Loads campaign specific tpl:
      array_push( $vars['theme_hook_suggestions'], 'node__project__' . $org_code );
    }

    // Store node object to pass into each section.
    //@todo: clean this up. pretty sure we can just pass in $vars instead of $params to make it less confusing.
    $params['node'] = $vars['node'];

    // Various sections use rules and regs file, so store its uri in parmas.
    $params['rules_regs_file_uri'] = FALSE;
    if (isset($vars['node']->field_rules_regs_file[LANGUAGE_NONE][0]['fid'])) {
      $params['rules_regs_file_uri'] = file_create_url($vars['node']->field_rules_regs_file[LANGUAGE_NONE][0]['uri']);
    }

    // Various sections also use the sponsors values, so store them in params too.
    if (isset($vars['node']->field_sponsors[LANGUAGE_NONE][0]['value'])) {
      // Store in vars for node template to access:
      $vars['sponsors'] = dosomething_project_get_field_sponsors_values($vars['node']);
      // Store in params for other section templates to access also:
      $params['sponsors'] = $vars['sponsors'];
      $vars['content']['sponsors']['#markup'] = theme('project_section_sponsors', $params);
    }

    // Section - Header:
    $vars['content']['header']['#markup'] = theme('project_section_header', $params);

    // Loop through project section display field values to set the corresponding project sections:
    foreach($vars['node']->field_project_section_display[LANGUAGE_NONE] as $key => $section_name) {
      $section_name = $section_name['value'];
      // If this is the SMS Referral section, pass through actual SMS Referral form as param:
      if ($section_name == 'sms_referral') {
        $params['sms_referral_form'] = $vars['content']['sms_referral_form'];
      }
      // If this is the SMS Referral section, pass through actual SMS Referral form as param:
      elseif ($section_name == 'reportback') {
        $params['reportback_form'] = $vars['content']['reportback_form'];
      }
      // Set the content section for this $section_name:
      $vars['content'][$section_name]['#markup'] = theme('project_section_' . $section_name, $params);
    }

  }
}

/**
 * Help function to load menu templates
 */
function _doit_load_menu_templates(&$variables) {
  $variables['page']['navigation'] = array();
  $variables['page']['navigation']['main_menu'] = array( 
    '#type' => 'markup',
    '#markup' => theme('main_menu')
  );

  $variables['page']['footer'] = array();
  $variables['page']['footer']['footer_menu'] = array( 
    '#type' => 'markup',
    '#markup' => theme('footer_menu')
  );
}

/**
 * Loads campaign css and js files.
 */
function _doit_load_project_assets($node, $org_code = NULL) {

  // @todo - we may need to refactor based on campaign related nodes
  if ($node->type != 'project') return;

  # Add neue library:
  drupal_add_library('ds_neue', 'ds-neue-campaign');

  # Add admin CSS/JS:
  global $user;
  if (in_array('administrator', array_values($user->roles))) {
    drupal_add_js(path_to_theme() . '/js/neue-drupal/admin-tabs.js', array(
      'scope' => 'footer',
      'every_page' => TRUE,
    ));
    drupal_add_css(path_to_theme() . '/css/neue-drupal/admin-tabs.css');
  }

  $org_code = $org_code ? $org_code : _doit_load_project_org_code($node);

  $path_to_theme = path_to_theme();
  $css_path = $path_to_theme . '/projects/css';
  $js_path = $path_to_theme . '/projects/js';

  if ($org_code) {
    $org_code_css = $css_path . '/' . $org_code . '/' . $org_code . '.css';
    $org_code_js = $js_path . '/' . $org_code . '/' . $org_code . '.js';
    // Add campaign specific css and js if files exist:
    if (file_exists($org_code_css)) {
      drupal_add_css($org_code_css);
    }
    if (file_exists($org_code_js)) {
      drupal_add_js($org_code_js);
    }
  }
  
}

/**
 * Loads campaign org code. @todo We should move this once fleshed out a bit more
 */
function _doit_load_project_org_code($node) {
  $org_code_items = field_get_items('node', $node, 'field_organization_code', $node->language);
  return $org_code_items ? $org_code_items[0]['value'] : FALSE;
}


// preprocess maintenance page copy for 500 error
function doit_preprocess_maintenance_page(&$vars) {
    global $conf;
    if ($conf['maintenance_mode'] === 0) {

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

function doit_form_alter(&$form, &$form_state, $form_id) {

  switch($form_id) {
    case 'search_api_page_search_form_demo':      
      if (doit_is_neue_page()) {
        $form['#attributes']['class'] = array('search');
        $form['keys_1']['#title'] = NULL;
        $form['keys_1']['#type'] = 'searchfield';
        // @TODO: move this to a style sheet some where
        $form['submit_1']['#attributes']['style'] = 'display: none;';
      }
      break;
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
 * Implements theme_pager().
 */
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
          if (doit_is_neue_page()) {
            $data = '<span class="btn small inactive">' . $i  . '</span>';
          }
          else {
            $data = $i;
          }

          $items[] = array(
            'class' => array('pager-current'),
            'data' => $data,
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
    return theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Implements theme_pager_link().
 */
function doit_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ prev') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  if (doit_is_neue_page()) {
    $attributes['class'] = 'btn small';
  }
  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
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

/**
 * Returns TRUE if current path is user-registration/password/login type page.
 */
function doit_is_user_registration_template_page() {
  // If anon user, check for user registration paths.
  if (!user_is_logged_in()) {
    $current_path = current_path();
    $user_reg_paths = array('user/registration', 'user/password', 'user', 'user/login');
    foreach ($user_reg_paths as $user_reg_path) {
      if ($current_path == $user_reg_path) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Returns TRUE if current path is a campaign join page.
 */
function doit_is_campaign_join_template_page() {
  if (user_is_logged_in() && arg(0) == 'campaign' && arg(1) == 'join' && is_numeric(arg(2))) {
    $node = node_load(arg(2));
    return dosomething_login_is_gated_signup_node($node);
  }
  return FALSE;
}

/**
 * Returns TRUE if current path is a Neue page.
 */
function doit_is_neue_page() {
  $node = menu_get_object();
  if (
    ($node && isset($node->type) && $node->type == 'project') ||
    (drupal_is_front_page() && theme_get_setting('doit_homepage_neue')) ||
    ($node && $node->type == 'page') && theme_get_setting('doit_pages_neue')
  ) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_css_alter().
 */
function doit_css_alter(&$css) {
  if (doit_is_neue_page()) {
    $styles = array();
    // @todo - optimize me
    $whitelist = array('ds-neue', 'contextual', 'admin_menu', 'neue', 'plupload');
    foreach($css as $path => $info) {
      foreach($whitelist as $namespace) {
        if (strpos($path, $namespace) !== false) {
            $styles[$path] = $info;
        }
      }
    }

    $css = $styles;
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_action_items(&$vars) {
  $node = $vars['node'];
  $vars['action_items'] = array();
  if (module_exists('dosomething_project')) {
    // Loop through the action items:
    $vars['action_items'] = dosomething_project_get_field_collection_values($node, 'field_action_items', 'action_item');
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_faq(&$vars) {
  $node = $vars['node'];
  $vars['faq_items'] = array();
  if (module_exists('dosomething_project')) {
    // Loop through the FAQ:
    $vars['faq_items'] = dosomething_project_get_field_collection_values($node, 'field_faq', 'faq');
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_header(&$vars) {
  $node = $vars['node'];
  $vars['project_url'] = 'http://' .$_SERVER['HTTP_HOST'] .$_SERVER['REQUEST_URI'];
  $vars['h1_style'] = '';
  $vars['project_date'] = FALSE;
  $vars['project_logo_uri'] = FALSE;
  $vars['twitter_share_msg'] = '';
  // If logo is set:
  if (isset($node->field_banner_logo[LANGUAGE_NONE][0]['fid'])) {
    $vars['project_logo_uri'] = file_create_url($node->field_banner_logo[LANGUAGE_NONE][0]['uri']);
    $vars['project_logo_alt'] = $node->field_banner_logo[LANGUAGE_NONE][0]['alt'];
    // Hide the H1:
    $vars['h1_style'] = 'style="display:none;"';
  }
  // If start date is set:
  if (isset($node->field_project_dates[LANGUAGE_NONE][0]['value'])) {
    $date_format = 'F j';
    // Did the campaign start yet?
    $start_time = strtotime($node->field_project_dates[LANGUAGE_NONE][0]['value']);
    $start_time_diff = time() - $start_time;
    if ($start_time_diff < 0) {
      $vars['project_date'] = 'Starts ' . format_date($start_time, 'custom', $date_format);
    }
    // Else check if there is an end date set:
    elseif (isset($node->field_project_dates[LANGUAGE_NONE][0]['value2'])) {
      // Did the campaign end?
      $end_time = strtotime($node->field_project_dates[LANGUAGE_NONE][0]['value2']);
      $end_time_diff = time() - $end_time;
      if ($end_time_diff < 0) {
        $vars['project_date'] = 'Ends ' . format_date($end_time, 'custom', $date_format);
      }
      else {
        $vars['project_date'] = 'Ended ' . format_date($end_time, 'custom', $date_format);
      }
    }
  }
  // Twitter share message:
  if (isset($node->field_twitter_share_msg[LANGUAGE_NONE][0]['value'])) {
    $vars['twitter_share_msg'] = rawurlencode($node->field_twitter_share_msg[LANGUAGE_NONE][0]['value']);
  }
  // For this header section, overwrite $sponsors variable with the sponsor theme section to render.
  // If sponsors variable exists, it was set in preprocess_node, checking for sponsors field values.
  if (isset($vars['sponsors'])) {
    $vars['sponsors'] = theme('project_section_sponsors', $vars);
  }
  // If it wasn't set, set to FALSE to prevent displaying the sponsors section.
  else {
    $vars['sponsors'] = FALSE;
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_gallery(&$vars) {
  $vars['gallery'] = views_embed_view('reportback_gallery', 'default', $vars['node']->nid);
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_info(&$vars) {
  $node = $vars['node'];
  $vars['project_info_items'] = array();
  if (module_exists('dosomething_project')) {  
    // Loop through the project info items:
    $vars['project_info_items'] = dosomething_project_get_field_collection_values($node, 'field_project_info_items', 'project_info_item');
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_profiles(&$vars) {
  $node = $vars['node'];
  $vars['profiles'] = array();
  if (module_exists('dosomething_project')) { 
    // Loop through the project profiles:
    $vars['profiles'] = dosomething_project_get_field_collection_values($node, 'field_project_profiles', 'project_profile');
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_prizes(&$vars) {
  // Loop through the action items:
  $node = $vars['node'];
  $vars['prizes'] = array();
  if (module_exists('dosomething_project')) { 
    $vars['prizes'] = dosomething_project_get_field_collection_values($node, 'field_prizes', 'prize');
  }
}


/**
 * Implements hook_preprocess_hook().
 */
function doit_preprocess_project_section_sponsors(&$vars) {
  // Loop through the action items:
  $node = $vars['node'];
  $vars['sponsors'] = array();
  if (module_exists('dosomething_project')) {  
    // Loop through the sponsors :
    $vars['sponsors'] = dosomething_project_get_field_sponsors_values($node);
  }
}
