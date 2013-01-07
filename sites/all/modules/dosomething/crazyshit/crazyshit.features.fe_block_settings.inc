<?php
/**
 * @file
 * crazyshit.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function crazyshit_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'views-crazy_shit_landing-block' => array(
      'delta' => 'crazy_shit_landing-block',
      'module' => 'views',
    ),
    'views-crazy_shit_landing-friends_view' => array(
      'delta' => 'crazy_shit_landing-friends_view',
      'module' => 'views',
    ),
  );

  // crazyshit
  $theme = array();

  $theme['views-crazy_shit_landing-block'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-block',
    'theme' => 'crazyshit',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-crazy_shit_landing-friends_view'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-friends_view',
    'theme' => 'crazyshit',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['theme']['crazyshit'] = $theme;

  // doit
  $theme = array();

  $theme['views-crazy_shit_landing-block'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-block',
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

  $theme['views-crazy_shit_landing-friends_view'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-friends_view',
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

  $export['theme']['doit'] = $theme;

  // ds
  $theme = array();

  $theme['views-crazy_shit_landing-block'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-block',
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

  $theme['views-crazy_shit_landing-friends_view'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-friends_view',
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

  $export['theme']['ds'] = $theme;

  // picsforpets
  $theme = array();

  $theme['views-crazy_shit_landing-block'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-block',
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

  $theme['views-crazy_shit_landing-friends_view'] = array(
    'module' => 'views',
    'delta' => 'crazy_shit_landing-friends_view',
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

  $export['theme']['picsforpets'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
