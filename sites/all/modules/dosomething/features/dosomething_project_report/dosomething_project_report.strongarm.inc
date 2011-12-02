<?php
/**
 * @file
 * dosomething_project_report.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_project_report_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_project_report';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_project_report'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_project_report';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_project_report'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_project_report';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_project_report'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_project_report';
  $strongarm->value = '1';
  $export['node_preview_project_report'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_project_report';
  $strongarm->value = 0;
  $export['node_submitted_project_report'] = $strongarm;

  return $export;
}
