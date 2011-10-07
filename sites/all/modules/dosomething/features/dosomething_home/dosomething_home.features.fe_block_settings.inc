<?php
/**
 * @file
 * dosomething_home.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dosomething_home_default_fe_block_settings() {
  $export = array();

  // ds
  $theme = array();

  $theme['panels_mini-home_page'] = array(
    'module' => 'panels_mini',
    'delta' => 'home_page',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-25',
    'region' => 'footer',
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
