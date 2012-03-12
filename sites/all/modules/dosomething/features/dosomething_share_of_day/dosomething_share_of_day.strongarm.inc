<?php
/**
 * @file
 * dosomething_share_of_day.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_share_of_day_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_share_of_day';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_share_of_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_share_of_day';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_share_of_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_share_of_day';
  $strongarm->value = array();
  $export['node_options_share_of_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_share_of_day';
  $strongarm->value = '1';
  $export['node_preview_share_of_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_share_of_day';
  $strongarm->value = 1;
  $export['node_submitted_share_of_day'] = $strongarm;

  return $export;
}
