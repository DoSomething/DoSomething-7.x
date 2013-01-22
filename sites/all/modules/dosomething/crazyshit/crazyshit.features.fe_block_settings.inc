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
  $export['visibility'] = array();

  // doit
  $theme = array();

  $export['theme']['doit'] = $theme;

  // ds
  $theme = array();

  $export['theme']['ds'] = $theme;

  // picsforpets
  $theme = array();

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
