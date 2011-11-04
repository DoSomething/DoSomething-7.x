<?php
/**
 * @file
 * dosomething_layout.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dosomething_layout_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer:node/21
  $menu_links['menu-footer:node/21'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/21',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-46',
  );
  // Exported menu link: menu-footer:node/3
  $menu_links['menu-footer:node/3'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Exported menu link: menu-footer:taxonomy/term/27
  $menu_links['menu-footer:taxonomy/term/27'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'taxonomy/term/27',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Disaster Response and Relief',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => '<front>',
  );
  // Exported menu link: menu-footer:taxonomy/term/29
  $menu_links['menu-footer:taxonomy/term/29'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'taxonomy/term/29',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Animal Welfare',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => '<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Animal Welfare');
  t('Disaster Response and Relief');
  t('Help');


  return $menu_links;
}
