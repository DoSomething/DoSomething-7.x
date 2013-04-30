<?php
/**
 * @file
 * create_and_share.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function create_and_share_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__create_and_share_campaign';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__create_and_share_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_create_and_share_campaign';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_create_and_share_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_create_and_share_campaign';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_create_and_share_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_create_and_share_campaign';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_create_and_share_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_create_and_share_campaign';
  $strongarm->value = '1';
  $export['node_preview_create_and_share_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_create_and_share_campaign';
  $strongarm->value = 1;
  $export['node_submitted_create_and_share_campaign'] = $strongarm;

  return $export;
}
