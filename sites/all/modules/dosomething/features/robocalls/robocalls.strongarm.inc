<?php
/**
 * @file
 * robocalls.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function robocalls_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_robo_calls';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_robo_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_robo_calls';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_robo_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_robo_calls';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_robo_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_robo_calls';
  $strongarm->value = '1';
  $export['node_preview_robo_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_robo_calls';
  $strongarm->value = 1;
  $export['node_submitted_robo_calls'] = $strongarm;

  return $export;
}
