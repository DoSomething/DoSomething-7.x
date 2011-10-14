<?php
/**
 * @file
 * dosomething_blog.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dosomething_blog_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-blog-center
  $menus['menu-blog-center'] = array(
    'menu_name' => 'menu-blog-center',
    'title' => 'Blog Center',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog Center');


  return $menus;
}
