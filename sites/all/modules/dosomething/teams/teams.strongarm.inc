<?php
/**
 * @file
 * teams.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function teams_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_team_challenge';
  $strongarm->value = array();
  $export['menu_options_team_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_team_challenge';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_team_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_team_challenge';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_team_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_team_challenge';
  $strongarm->value = '0';
  $export['node_preview_team_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_team_challenge';
  $strongarm->value = 0;
  $export['node_submitted_team_challenge'] = $strongarm;

  return $export;
}
