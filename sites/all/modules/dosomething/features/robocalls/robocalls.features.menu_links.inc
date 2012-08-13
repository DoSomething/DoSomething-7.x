<?php
/**
 * @file
 * robocalls.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function robocalls_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:http://localhost:8080/causecall
  $menu_links['main-menu:http://localhost:8080/causecall'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://localhost:8080/causecall',
    'router_path' => '',
    'link_title' => 'Robo Calls',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-39',
    'parent_path' => 'awesome-things',
  );
  // Exported menu link: main-menu:http://localhost:8080/causecall/about
  $menu_links['main-menu:http://localhost:8080/causecall/about'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://localhost:8080/causecall/about',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'http://localhost:8080/causecall',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Robo Calls');


  return $menu_links;
}
