<?php
/**
 * @file
 * dosomething_program_short_form.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_program_short_form_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_program_short_form';
  $strongarm->value = array();
  $export['menu_options_program_short_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_program_short_form';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_program_short_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_program_short_form';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_program_short_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_program_short_form';
  $strongarm->value = '1';
  $export['node_preview_program_short_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_program_short_form';
  $strongarm->value = 0;
  $export['node_submitted_program_short_form'] = $strongarm;

  return $export;
}
