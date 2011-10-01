<?php

function ds_preprocess_html(&$variables, $hook) {
  // dsm($variables);
  // dsm($hook);
}

function ds_preprocess_page(&$variables) {
  // dsm($variables);
  // dsm($variables['page']);
  
  // Add Formalize to even out most form elements
  drupal_add_js(drupal_get_path('theme', 'ds') . '/js/formalize/jquery.formalize.min.js');
  // replace select boxes to allow custom theming
  drupal_add_js(drupal_get_path('theme', 'ds') . '/js/jQuery-SelectBox/jquery.selectBox.min.js', array('scope' => 'footer'));
  // drupal_add_css(drupal_get_path('theme', 'ds') . '/js/jQuery-SelectBox/jquery.selectBox.css');
  drupal_add_js(drupal_get_path('theme', 'ds') . '/js/ds-select.js', array('scope' => 'footer'));
}

function ds_preprocess_block(&$variables) {
  // dsm($variables['elements']['#block']);

  // set a .block-title class on the title
  $variables['title_attributes_array']['class'][] = 'block-title';

  // load css specific to blocks
  if($variables['elements']['#block']->module == 'dosomething_login') {
    // block-dosomething-login-become-member
    if($variables['elements']['#block']->delta == 'become_member') {
      drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/block-dosomething-login-become-member.css');                                                                                                              
    }
  }
  if($variables['elements']['#block']->module == 'dosomething_blocks') {
    // dosomething_make_impact
    if($variables['elements']['#block']->delta == 'dosomething_make_impact') {
      drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/dosomething_make_impact.css');
    }
    // dosomething_facebook_activity
    if($variables['elements']['#block']->delta == 'dosomething_facebook_activity') {
      drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/dosomething_facebook_activity.css');
    }
    // block-dosomething-blocks-dosomething-twitter-stream
    if($variables['elements']['#block']->delta == 'dosomething_facebook_activity') {
      drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/block-dosomething-blocks-dosomething-twitter-stream.css');
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