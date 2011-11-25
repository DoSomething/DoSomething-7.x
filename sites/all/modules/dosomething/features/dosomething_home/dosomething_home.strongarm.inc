<?php
/**
 * @file
 * dosomething_home.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_home_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scroller';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_scroller'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scroller';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_scroller'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scroller';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_scroller'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scroller';
  $strongarm->value = '1';
  $export['node_preview_scroller'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scroller';
  $strongarm->value = 0;
  $export['node_submitted_scroller'] = $strongarm;

  return $export;
}
