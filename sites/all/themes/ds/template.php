<?php

function ds_preprocess_html(&$variables, $hook) {
  // dsm($hook);
  // dsm($variables);
  $theme_path = drupal_get_path('theme', 'ds');
  $variables['selectivizr'] = '<!--[if (gte IE 6)&(lte IE 8)]>';
  $variables['selectivizr'] .= '<script type="text/javascript" src="' . $theme_path . '/js/mootools-core-1.4.1-full-nocompat-yc.js'  . '"></script>';
  $variables['selectivizr'] .= '<script type="text/javascript" src="' . $theme_path . '/js/selectivizr/selectivizr-min.js'  . '"></script>';
  $variables['selectivizr'] .= '<![endif]-->';
  // HTML5 Shiv
  $variables['shiv'] = '<!--[if lt IE 9]><script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->';
}

function ds_preprocess_panels_pane(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  // load css specific to panes
  // blog panes
  if ($variables['pane']->type == 'views' && $variables['pane']->subtype == 'blog_center') {
    drupal_add_css($theme_path . '/css/ds/blog-panes.css');
  }
  // dsm($variables);
}

function ds_preprocess_page(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  if (!isset($variables['secondary_links_theme_function'])) {
    $variables['secondary_links_theme_function'] = 'links__system_secondary_menu'; 
  }
  // dsm($variables);
  // dsm($variables['page']);

  // Add Formalize to even out most form elements
  drupal_add_js($theme_path . '/js/formalize/jquery.formalize.min.js');
  // replace select boxes to allow custom theming
  drupal_add_js($theme_path . '/js/jQuery-SelectBox/jquery.selectBox.min.js', array('scope' => 'footer'));
  drupal_add_js($theme_path . '/js/ds-select.js', array('scope' => 'footer'));

  // Add lets_talk_dialogue.js to 'Talk to Us' footer menu item.
  if (isset($variables['page']['footer']['menu_menu-footer']['90436']['#below']['93450']) && arg(0) !== 'admin') {
    // Add additional css class to 'Talk to Us' footer menu item.
    $variables['page']['footer']['menu_menu-footer']['90436']['#below']['93450']['#attributes']['class'][] = 'talk-to-us';
    drupal_add_js(drupal_get_path('module', 'dosomething_blocks') .'/js/lets_talk_dialog.js', 'file');
  }
}

/**
 * Implements hook_ctools_render_alter().
 *
 * This hook gives us access to the panel itself, not just one pane.
 */
function ds_ctools_render_alter(&$info, &$page, &$context) {
  if (!$page || (isset($context['task']['task type']) && $context['task']['task type'] != 'page')) {
    return;
  }

  $css_path = drupal_get_path('theme', 'ds') . '/css/ds/';

  // If this is a custom page, the name is the machine name, and is stored as
  // the name of the subtask. If it is a system page like node/%node, the name
  // is stored as the name of the handler. These names are global, not per-page.
  // Unless it is customized upon export, it will be in the form of
  // NAME_panel_context_DELTA, for example, node_view_panel_context_3.
  $name = isset($context['subtask']['name']) ? $context['subtask']['name'] : $context['handler']->name;
  switch ($name) {
    case 'club_hub':
      drupal_add_css($css_path . 'clubhub-landing.css');
      break;

    case 'action_finder':
      drupal_add_css($css_path . 'page-action-finder.css');
      break;

    case 'awesome_things':
      drupal_add_css($css_path . 'page-awesome-things.css');
      break;

    case 'grants':
      drupal_add_css($css_path . 'grants-landing.css');
      break;

    case 'members_only':
      drupal_add_css($css_path . 'members-only-landing.css');
      break;

    case 'why_become_a_member_page':
      drupal_add_css($css_path . 'dosomething-members-only.css');
      break;

    case 'scholarships':
      drupal_add_css($css_path . 'scholarships-landing.css');
      break;

    case 'resources':
      drupal_add_css($css_path . 'resources-landing.css');
      break;

    case 'start_something':
      drupal_add_css($css_path . 'dosomething-start-something.css');
      break;

    case 'member_wall':
      drupal_add_css($css_path . 'page-member-wall.css');
      break;

    case 'node_view_grants':
      drupal_add_css($css_path . 'page-node-grants.css');
      break;

    case 'projects':
      drupal_add_css($css_path . 'page-related-projects.css');
      break;

    case 'webform_view_project':
      drupal_add_css($css_path . 'dosomething-projects.css');
      break;

    case 'user_view_my_somethings':
      drupal_add_css($css_path . 'my-somethings.css');
      break;

    case 'term_view_causes':
      drupal_add_css($css_path . 'dosomething-issues.css');
      break;
  }
}

function ds_preprocess_node(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');

  // Action Tip node page
  if ($variables['type'] == 'action_guide') {
    drupal_add_css($theme_path . '/css/ds/page-node-action-guide.css');
  }
  // Club node page
  if ($variables['type'] == 'club') {
    drupal_add_css($theme_path . '/css/ds/page-node-club.css');
  }
}

function ds_preprocess_block(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  // dsm($variables['elements']['#block']);

  // set a .block-title class on the title
  $variables['title_attributes_array']['class'][] = 'block-title';

  // load css specific to blocks
  if($variables['elements']['#block']->module == 'dosomething_login') {
    // block-dosomething-login-become-member
    if($variables['elements']['#block']->delta == 'become_member') {
      drupal_add_css($theme_path . '/css/ds/block-dosomething-login-become-member.css');
    }
  }
  if($variables['elements']['#block']->module == 'dosomething_blocks') {
    // dosomething_make_impact
    if($variables['elements']['#block']->delta == 'dosomething_make_impact') {
      drupal_add_css($theme_path . '/css/ds/dosomething_make_impact.css');
    }
    // dosomething_facebook_activity
    if($variables['elements']['#block']->delta == 'dosomething_facebook_activity') {
      drupal_add_css($theme_path . '/css/ds/dosomething_facebook_activity.css');
    }
    // block-dosomething-blocks-dosomething-twitter-stream
    if($variables['elements']['#block']->delta == 'dosomething_facebook_activity') {
      drupal_add_css($theme_path . '/css/ds/block-dosomething-blocks-dosomething-twitter-stream.css');
    }
  }
  if($variables['elements']['#block']->module == 'panels_mini') {
    if($variables['elements']['#block']->delta == 'home_page') {
      // home page panels_mini second row
      drupal_add_css($theme_path . '/css/ds/dosomething_panels_mini_home_page.css');
    }
  }

  // dsm($variables);
}

function ds_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  // Determine if we are to display the breadcrumb.
  // $show_breadcrumb = theme_get_setting('zen_breadcrumb');
  // if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

    // get rid of the homepage link.

      array_shift($breadcrumb);

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = '<i>//</i>';
      $trailing_separator = $title = '';

      $item = menu_get_item();
      if (!empty($item['tab_parent'])) {
        // If we are on a non-default tab, use the tab's title.
        $title = check_plain($item['title']);
      }
      else {
        $title = drupal_get_title();
      }
      if ($title) {
        $trailing_separator = $breadcrumb_separator;
      }



      // Provide a navigational heading to give context for breadcrumb links to
      // screen-reader users.
      if (empty($variables['title'])) {
        $variables['title'] = t('You are here');
      }
      // Unless overridden by a preprocess function, make the heading invisible.
      if (!isset($variables['title_attributes_array']['class'])) {
        $variables['title_attributes_array']['class'][] = 'element-invisible';
      }
      $heading = '<h2' . drupal_attributes($variables['title_attributes_array']) . '>' . $variables['title'] . '</h2>';

      return '<div class="breadcrumb">' . $heading . implode($breadcrumb_separator, $breadcrumb) . $trailing_separator . '<b>' . $title . '</b></div>';
    }
  // }
  // Otherwise, return an empty string.
  return '';
}

/**
 * Add a custom title to the exposed filter form on the action finder page.
 */
function ds_preprocess_views_exposed_form(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  if ($variables['form']['#id'] == 'views-exposed-form-action-finder-ctools-context-1') {
    $obj = new stdClass;
    $obj->label = 'Find Something Else';
    $obj->id = 'filter-title';
    $obj->operator = NULL;
    $obj->widget = NULL;
    $title = array('title' => $obj);
    $variables['widgets'] = $title + $variables['widgets'];
    drupal_add_css($theme_path . '/css/ds/page-action-finder.css');
  }
}

function ds_preprocess_views_view(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  switch ($variables['name']) {
    case 'current_campaigns':
      drupal_add_css($theme_path . '/css/ds/dosomething-campaigns.css');
      break;

    case 'blog_center':
      if ($variables['display_id'] == 'panel_pane_1') {
        drupal_add_css($theme_path . '/css/ds/blog-panes.css');
      }
      break;

    case 'polls':
      drupal_add_css($theme_path . '/css/ds/dosomething-polls.css');
      break;
  }
  // dsm($variables);
}

function ds_preprocess_rotoslider_slider(&$variables) {
  $theme_path = drupal_get_path('theme', 'ds');
  $variables['element']['#attached']['css'][] = $theme_path . '/css/ds/dosomething-rotoslider.css';
  $variables['element']['#attached']['js'][] = $theme_path . '/js/ds-rotoslider.js';
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
function ds_date_display_range($vars) {
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
function ds_preprocess_user_picture(&$variables) {
  $variables['user_picture'] = '';
    $account = $variables['account'];
    if ($account && $fbid = fboauth_fbid_load($account->uid)) {
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
function ds_webform_view_messages($variables) {
  global $user;

  $node = $variables['node'];
  $teaser = $variables['teaser'];
  $page = $variables['page'];
  $submission_count = $variables['submission_count'];
  $limit_exceeded = $variables['limit_exceeded'];
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
    elseif (isset($allowed_roles[2])) {
      // The "authenticated user" role is allowed to submit and the user is currently logged-out.
      $login = url('user/login', array('query' => drupal_get_destination()));
      $register = url('user/registration', array('query' => drupal_get_destination()));
      if (variable_get('user_register', 1) == 0) {
        $message = t('You must <a href="!login">login</a> to view this form.', array('!login' => $login));
      }
      else {
        $message = t('You must <a href="!login">login</a> or <a href="!register">register</a> to view this form.', array('!login' => $login, '!register' => $register));
      }
    }
    else {
      // The user must be some other role to submit.
      $message = t('You do not have permission to view this form.');
    }
  }

  // If the user has exceeded the limit of submissions, explain the limit.
  elseif ($limit_exceeded && !$cached) {
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
function ds_date_part_label_date($vars) {
  $part_type = $vars['part_type'];
  $element = $vars['element'];
  if (stripos($element['#date_title'], 'start date')) {
    return t('Start Date', array(), array('context' => 'datetime'));
  }
  if (stripos($element['#date_title'], 'end date')) {
    return t('End Date', array(), array('context' => 'datetime'));
  }
}
