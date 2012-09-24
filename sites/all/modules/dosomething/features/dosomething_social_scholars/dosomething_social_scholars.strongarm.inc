<?php
/**
 * @file
 * dosomething_social_scholars.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_social_scholars_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_social_scholarship';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_social_scholarship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_social_scholarship';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_social_scholarship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_social_scholarship';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_social_scholarship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_social_scholarship';
  $strongarm->value = '1';
  $export['node_preview_social_scholarship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_social_scholarship';
  $strongarm->value = 0;
  $export['node_submitted_social_scholarship'] = $strongarm;

  return $export;
}
