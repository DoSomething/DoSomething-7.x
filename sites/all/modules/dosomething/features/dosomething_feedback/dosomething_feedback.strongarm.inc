<?php
/**
 * @file
 * dosomething_feedback.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_feedback_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'browscap_monitor';
  $strongarm->value = 1;
  $export['browscap_monitor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unfuddle_api_pass';
  $strongarm->value = 'mayoguy';
  $export['unfuddle_api_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unfuddle_api_project';
  $strongarm->value = '38035';
  $export['unfuddle_api_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unfuddle_api_url';
  $strongarm->value = 'https://zivtech.unfuddle.com';
  $export['unfuddle_api_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unfuddle_api_user';
  $strongarm->value = 'dosomethingbot';
  $export['unfuddle_api_user'] = $strongarm;

  return $export;
}
