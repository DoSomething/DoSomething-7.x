<?php
/**
 * @file
 * dosomething_footer_menus.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function dosomething_footer_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-about-us-footer-menu
  $menus['menu-about-us-footer-menu'] = array(
    'menu_name' => 'menu-about-us-footer-menu',
    'title' => 'About Us Footer Menu',
    'description' => '',
  );
  // Exported menu: menu-help-menu
  $menus['menu-help-menu'] = array(
    'menu_name' => 'menu-help-menu',
    'title' => 'Help Footer Menu',
    'description' => 'Help menu for the footer.',
  );
  // Exported menu: menu-issues-menu
  $menus['menu-issues-menu'] = array(
    'menu_name' => 'menu-issues-menu',
    'title' => 'Causes/Issues Footer Menu',
    'description' => 'A menu of the terms from the issues vocabulary.',
  );
  // Exported menu: menu-news-info
  $menus['menu-news-info'] = array(
    'menu_name' => 'menu-news-info',
    'title' => 'News & Info Footer Menu',
    'description' => 'The footer news and info menu',
  );
  // Exported menu: menu-resources-menu
  $menus['menu-resources-menu'] = array(
    'menu_name' => 'menu-resources-menu',
    'title' => 'Resources Footer Menu',
    'description' => 'The resources menu used in the footer.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A menu of the terms from the issues vocabulary.');
  t('About Us Footer Menu');
  t('Causes/Issues Footer Menu');
  t('Help Footer Menu');
  t('Help menu for the footer.');
  t('News & Info Footer Menu');
  t('Resources Footer Menu');
  t('The footer news and info menu');
  t('The resources menu used in the footer.');


  return $menus;
}
