<?php
/**
 * @file
 * share_a_stat_scholarship.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function share_a_stat_scholarship_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_social_scholarship';
  $strongarm->value = array();
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
  $strongarm->value = 1;
  $export['node_submitted_social_scholarship'] = $strongarm;

  return $export;
}
