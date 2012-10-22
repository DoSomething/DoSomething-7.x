<?php
/**
 * @file
 * dosomething_clubs.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dosomething_clubs_default_fe_block_settings() {
  $export = array();

  // doit
  $theme = array();

  $theme['views-campaign_list_for_clubs-block'] = array(
    'module' => 'views',
    'delta' => 'campaign_list_for_clubs-block',
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

  $theme['views-clubs_to_do_list-block'] = array(
    'module' => 'views',
    'delta' => 'clubs_to_do_list-block',
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

  $theme['views-campaign_list_for_clubs-block'] = array(
    'module' => 'views',
    'delta' => 'campaign_list_for_clubs-block',
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

  $theme['views-clubs_to_do_list-block'] = array(
    'module' => 'views',
    'delta' => 'clubs_to_do_list-block',
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

  // picsforpets
  $theme = array();

  $theme['views-campaign_list_for_clubs-block'] = array(
    'module' => 'views',
    'delta' => 'campaign_list_for_clubs-block',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-clubs_to_do_list-block'] = array(
    'module' => 'views',
    'delta' => 'clubs_to_do_list-block',
    'theme' => 'picsforpets',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['picsforpets'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
