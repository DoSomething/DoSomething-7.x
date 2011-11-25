<?php
/**
 * @file
 * dosomething_dev.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_dev_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimages_generate';
  $strongarm->value = '2';
  $export['dummyimages_generate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dummyimages_service';
  $strongarm->value = 'flickholdr';
  $export['dummyimages_service'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_js';
  $strongarm->value = '0';
  $export['preprocess_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xhprof_enabled';
  $strongarm->value = '1';
  $export['xhprof_enabled'] = $strongarm;

  return $export;
}
