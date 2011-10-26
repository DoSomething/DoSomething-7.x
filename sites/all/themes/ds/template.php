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

  // load css specific to pages
  // causes landing page
  if(arg(0) == 'cause') {
    drupal_add_css(drupal_get_path('theme', 'ds') . '/css/ds/causes-landing.css');
  }

  $variables['secondary_menu_items'] = ds_menu_secondary_links($variables);
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
 * Get the secondary links for all possible main menu links.
 *  This is used to build html for all hidden and shown
 *  secondary links.
 */
function ds_menu_secondary_links($variables) {
  $secondary_menu_items = ds_menu_navigation_links('main-menu');
  if (count($secondary_menu_items)) {
    foreach ($secondary_menu_items as $mlid => &$links) {
      $links['attributes']['class'][] = 'links';
      $links['attributes']['class'][] = $mlid;
      if (isset($variables['main_menu'][$mlid . ' active-trail'])) {
        $links['links'] = $variables['secondary_menu'];
        $links['attributes']['class'][] = 'active';
      }
      else {
        $links['attributes']['class'][] = 'hidden';
      }
    }
    drupal_add_js(drupal_get_path('theme', 'ds') . '/js/ds-main-menu.js');
  }
  return $secondary_menu_items;
}

/**
 * Return an array of links for a navigation menu.
 *  Note that this is specifc for level 2.
 *
 * @param $menu_name
 *   The name of the menu.
 *
 * @return
 *   An array of links of the specified menu.
 */
function ds_menu_navigation_links($menu_name) {
  // Don't even bother querying the menu table if no menu is specified.
  if (empty($menu_name)) {
    return array();
  }

  // Get the menu hierarchy for the current page.
  $mlids = array();

  $main_tree = menu_build_tree($menu_name);
  $router_item = menu_get_item();
  $links = array();
  foreach ($main_tree as $tree) {
    if (!empty($tree['below'])) {
      $links['menu-' . $tree['link']['mlid']] = array();
      $count = 0;
      foreach ($tree['below'] as $item) {
        if (!$item['link']['hidden']) {
          $class = '';
          $l = $item['link']['localized_options'];
          $l['href'] = $item['link']['href'];
          $l['title'] = $item['link']['title'];
          if ($item['link']['in_active_trail']) {
            $class = ' active-trail';
            $l['attributes']['class'][] = 'active-trail';
          }
          // Normally, l() compares the href of every link with $_GET['q'] and sets
          // the active class accordingly. But local tasks do not appear in menu
          // trees, so if the current path is a local task, and this link is its
          // tab root, then we have to set the class manually.
          if ($item['link']['href'] == $router_item['tab_root_href'] && $item['link']['href'] != $_GET['q']) {
            $l['attributes']['class'][] = 'active';
          }
          // Keyed with the unique mlid to generate classes in theme_links().
          $l['attributes']['class'][] = 'main-menu-parent-' . $tree['link']['mlid'];
          $l['attributes']['class'][] = 'secondary-menu-item-' . $count;
          $links['menu-' . $tree['link']['mlid']]['links']['menu-' . $item['link']['mlid'] . $class] = $l;
        }
        $count++;
      }
    }
  }
  return $links;
}

