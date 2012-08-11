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
    'link_title' => 'Robo Call Links',
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
    'weight' => '-50',
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
  // Exported menu link: main-menu:menu-position/15
  $menu_links['main-menu:menu-position/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/15',
    'router_path' => 'menu-position/%',
    'link_title' => 'Robo Calls (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'http://localhost:8080/causecall',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Robo Call Links');
  t('Robo Calls (menu position rule)');


  return $menu_links;
}
