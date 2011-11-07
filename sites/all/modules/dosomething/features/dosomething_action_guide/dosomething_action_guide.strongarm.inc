<?php
/**
 * @file
 * dosomething_action_guide.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_action_guide_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_action_guide';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_action_guide';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_action_guide';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_action_guide';
  $strongarm->value = 1;
  $export['node_preview_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_action_guide';
  $strongarm->value = 1;
  $export['node_submitted_action_guide'] = $strongarm;

  return $export;
}
