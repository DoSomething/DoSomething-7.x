<?php
/**
 * @file
 * dosomething_member_opportunity.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_member_opportunity_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_member_opportunity';
  $strongarm->value = 0;
  $export['comment_anonymous_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_member_opportunity';
  $strongarm->value = '3';
  $export['comment_controls_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_member_opportunity';
  $strongarm->value = 0;
  $export['comment_default_mode_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_member_opportunity';
  $strongarm->value = '2';
  $export['comment_default_order_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_member_opportunity';
  $strongarm->value = '50';
  $export['comment_default_per_page_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_member_opportunity';
  $strongarm->value = '1';
  $export['comment_form_location_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_member_opportunity';
  $strongarm->value = '0';
  $export['comment_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_member_opportunity';
  $strongarm->value = 1;
  $export['comment_preview_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_member_opportunity';
  $strongarm->value = '0';
  $export['comment_subject_field_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_grant_judge';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_grant_judge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_member_opportunity';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_grant_judge';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_grant_judge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_member_opportunity';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_grant_judge';
  $strongarm->value = array();
  $export['node_options_grant_judge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_member_opportunity';
  $strongarm->value = array();
  $export['node_options_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_grant_judge';
  $strongarm->value = 1;
  $export['node_preview_grant_judge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_member_opportunity';
  $strongarm->value = '1';
  $export['node_preview_member_opportunity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_grant_judge';
  $strongarm->value = 1;
  $export['node_submitted_grant_judge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_member_opportunity';
  $strongarm->value = 1;
  $export['node_submitted_member_opportunity'] = $strongarm;

  return $export;
}
