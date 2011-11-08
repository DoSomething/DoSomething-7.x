<?php
/**
 * @file
 * dosomething_scholarship_application.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_scholarship_application_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scholarship_application';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_scholarship_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scholarship_application';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scholarship_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholarship_application';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_scholarship_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scholarship_application';
  $strongarm->value = '1';
  $export['node_preview_scholarship_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scholarship_application';
  $strongarm->value = 1;
  $export['node_submitted_scholarship_application'] = $strongarm;

  return $export;
}
