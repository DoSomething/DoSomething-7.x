<?php
/**
 * @file
 * dosomething_fb_apps.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_fb_apps_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_fb_app_data_gathering_form';
  $strongarm->value = array();
  $export['menu_options_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_fb_app_data_gathering_form';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_fb_app_data_gathering_form';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_fb_app_data_gathering_form';
  $strongarm->value = '0';
  $export['node_preview_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_fb_app_data_gathering_form';
  $strongarm->value = 0;
  $export['node_submitted_fb_app_data_gathering_form'] = $strongarm;

  return $export;
}
