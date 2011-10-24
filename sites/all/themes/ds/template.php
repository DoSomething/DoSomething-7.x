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
  if($variables['elements']['#block']->module == 'panels_mini') {
    if($variables['elements']['#block']->delta == 'home_page') {
      // home page panels_mini second row
      drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/dosomething_panels_mini_home_page.css');
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
 * Add a custon title to the exposed filter form on the action finder page.
 */
function ds_preprocess_views_exposed_form(&$vars) {
  if ($vars['form']['#id'] == 'views-exposed-form-action-finder-page') {
    $obj = new stdClass;
    $obj->label = 'Find Something Else';
    $obj->id = 'filter-title';
    $obj->operator = NULL;
    $obj->widget = NULL;
    $title = array('title' => $obj);
    $vars['widgets'] = $title + $vars['widgets'];
  }
}

function ds_preprocess_views_view(&$vars) {
  if ($vars['name'] == 'current_campaigns') {
    drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/dosomething-campaigns.css');
  }  
}  

/**
 * Override of theme_menu_link().
 */
function ds_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  // Add unique classes for this particular menu item and for the depth.
  $element['#attributes']['class'][] = 'menu-' . $element['#original_link']['mlid'];
  $element['#attributes']['class'][] = 'menu-level-' . $element['#original_link']['depth'];

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

