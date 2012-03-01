<?php
/**
 * @file
 * dosomething_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_month_day_year';
  $strongarm->value = 'F n, Y';
  $export['date_format_month_day_year'] = $strongarm;

  return $export;
}
