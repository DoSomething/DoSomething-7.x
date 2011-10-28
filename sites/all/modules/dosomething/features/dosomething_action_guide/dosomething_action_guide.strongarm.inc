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
  $strongarm->name = 'comment_action_guide';
  $strongarm->value = '2';
  $export['comment_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_action_guide';
  $strongarm->value = 0;
  $export['comment_anonymous_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_action_guide';
  $strongarm->value = '3';
  $export['comment_controls_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_action_guide';
  $strongarm->value = 0;
  $export['comment_default_mode_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_action_guide';
  $strongarm->value = '2';
  $export['comment_default_order_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_action_guide';
  $strongarm->value = '50';
  $export['comment_default_per_page_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_action_guide';
  $strongarm->value = '1';
  $export['comment_form_location_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_action_guide';
  $strongarm->value = 1;
  $export['comment_preview_action_guide'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_action_guide';
  $strongarm->value = '0';
  $export['comment_subject_field_action_guide'] = $strongarm;

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
