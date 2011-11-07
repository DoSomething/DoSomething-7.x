<?php
/**
 * @file
 * dosomething_grant_application.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_grant_application_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_grant_application';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_grant_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_grant_application';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_grant_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodereference_url_paths';
  $strongarm->value = array(
    0 => 'node/add/%type/%nid',
    1 => 'node/%webform_node/%nid',
  );
  $export['nodereference_url_paths'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_grant_application';
  $strongarm->value = array();
  $export['node_options_grant_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_grant_application';
  $strongarm->value = 1;
  $export['node_preview_grant_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_grant_application';
  $strongarm->value = 1;
  $export['node_submitted_grant_application'] = $strongarm;

  return $export;
}
