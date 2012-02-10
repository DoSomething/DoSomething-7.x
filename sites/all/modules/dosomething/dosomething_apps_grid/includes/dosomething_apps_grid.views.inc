<?php

/**
 * @file
 * Contains Views module hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function dosomething_apps_grid_views_plugins() {
  $path = drupal_get_path('module', 'dosomething_apps_grid') . '/includes';
  return array(
    //'module' => 'dosomething_apps_grid',
    'style' => array(
      'dosomething_apps_grid' => array(
        'title' => t('DoSomething Apps Grid'),
        'help' => t('Displays items in a grid.'),
        'handler' => 'dosomething_apps_grid_plugin_style',
        'path' => $path,
        'theme' => 'dosomething_apps_grid',
        'theme file' => 'theme.inc',
        'theme path' => $path,
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => TRUE,
        'even empty' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
