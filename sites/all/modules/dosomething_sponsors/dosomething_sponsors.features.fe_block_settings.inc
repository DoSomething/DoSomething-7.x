<?php
/**
 * @file
 * dosomething_sponsors.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dosomething_sponsors_default_fe_block_settings() {
  $export = array();

  // doit
  $theme = array();

  $theme['views-sponsors_who_rock-block_1'] = array(
    'module' => 'views',
    'delta' => 'sponsors_who_rock-block_1',
    'theme' => 'doit',
    'status' => '1',
    'weight' => '-41',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => -1,
  );

  $export['doit'] = $theme;

  // ds
  $theme = array();

  $theme['views-sponsors_who_rock-block_1'] = array(
    'module' => 'views',
    'delta' => 'sponsors_who_rock-block_1',
    'theme' => 'ds',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
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
