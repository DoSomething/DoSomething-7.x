<?php
/**
 * @file
 * dosomething_campaign_report_back.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_campaign_report_back_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_campaign_report_back';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_campaign_report_back'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_campaign_report_back';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_campaign_report_back'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_campaign_report_back';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_campaign_report_back'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_campaign_report_back';
  $strongarm->value = '1';
  $export['node_preview_campaign_report_back'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_campaign_report_back';
  $strongarm->value = 0;
  $export['node_submitted_campaign_report_back'] = $strongarm;

  return $export;
}
