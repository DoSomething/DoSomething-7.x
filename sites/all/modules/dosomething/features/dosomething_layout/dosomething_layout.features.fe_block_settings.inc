<?php
/**
 * @file
 * dosomething_layout.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dosomething_layout_default_fe_block_settings() {
  $export = array();

  // doit
  $theme = array();

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-34',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
start-something',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_utility_bar'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_utility_bar',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-22',
    'region' => 'utility',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-35',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-30',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['doit'] = $theme;

  // ds
  $theme = array();

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-23',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
start-something',
    'title' => '',
    'cache' => 8,
  );

  $theme['dosomething_blocks-dosomething_utility_bar'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_utility_bar',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-22',
    'region' => 'utility',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-30',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['ds'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
