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

  // ds
  $theme = array();

  $theme['dosomething_blocks-dosomething_facebook_activity'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_facebook_activity',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-71',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['dosomething_blocks-dosomething_make_impact'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_make_impact',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-73',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['dosomething_blocks-dosomething_twitter_stream'] = array(
    'module' => 'dosomething_blocks',
    'delta' => 'dosomething_twitter_stream',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-72',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['dosomething_login-become_member'] = array(
    'module' => 'dosomething_login',
    'delta' => 'become_member',
    'theme' => 'ds',
    'status' => '1',
    'weight' => '-74',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
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
