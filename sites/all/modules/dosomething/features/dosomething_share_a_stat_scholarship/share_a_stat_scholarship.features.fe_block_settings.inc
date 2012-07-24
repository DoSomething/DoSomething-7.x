<?php
/**
 * @file
 * share_a_stat_scholarship.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function share_a_stat_scholarship_default_fe_block_settings() {
  $export = array();

  // doit
  $theme = array();

  $theme['webform-client-block-723323'] = array(
    'module' => 'webform',
    'delta' => 'client-block-723323',
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

  $theme['webform-client-block-723323'] = array(
    'module' => 'webform',
    'delta' => 'client-block-723323',
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
