<?php
/**
 * @file
 * robocalls.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function robocalls_default_fe_block_settings() {
  $export = array();

  // doit
  $theme = array();

  $theme['menu_block-5'] = array(
    'module' => 'menu_block',
    'delta' => '5',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '-72',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'causecall*',
    'title' => 'Robo Calls',
    'cache' => -1,
  );

  $theme['views-43e5f8c3da7cdbaf9be68f0db57cc6a0'] = array(
    'module' => 'views',
    'delta' => '43e5f8c3da7cdbaf9be68f0db57cc6a0',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-c6ff9c796a4b9eeb0843eebedec7be2a'] = array(
    'module' => 'views',
    'delta' => 'c6ff9c796a4b9eeb0843eebedec7be2a',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['webform-client-block-723985'] = array(
    'module' => 'webform',
    'delta' => 'client-block-723985',
    'theme' => 'doit',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['doit'] = $theme;

  // ds
  $theme = array();

  $theme['menu_block-5'] = array(
    'module' => 'menu_block',
    'delta' => '5',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'causecall*',
    'title' => 'Robo Calls',
    'cache' => -1,
  );

  $theme['views-43e5f8c3da7cdbaf9be68f0db57cc6a0'] = array(
    'module' => 'views',
    'delta' => '43e5f8c3da7cdbaf9be68f0db57cc6a0',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-c6ff9c796a4b9eeb0843eebedec7be2a'] = array(
    'module' => 'views',
    'delta' => 'c6ff9c796a4b9eeb0843eebedec7be2a',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['webform-client-block-723985'] = array(
    'module' => 'webform',
    'delta' => 'client-block-723985',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
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
