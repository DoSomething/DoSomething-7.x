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

  $export['version'] = '2.0';

  $export['views-campaign_list_for_clubs-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'campaign_list_for_clubs-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'doit' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'doit',
        'weight' => '-19',
      ),
      'ds_flatiron' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ds_flatiron',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-clubs_to_do_list-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'clubs_to_do_list-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'doit' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'doit',
        'weight' => '-17',
      ),
      'ds_flatiron' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ds_flatiron',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
