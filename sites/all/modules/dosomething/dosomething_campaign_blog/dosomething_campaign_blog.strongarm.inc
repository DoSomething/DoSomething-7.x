<?php
/**
 * @file
 * dosomething_campaign_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_campaign_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_campaign_blog_post';
  $strongarm->value = array();
  $export['menu_options_campaign_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_campaign_blog_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_campaign_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_campaign_blog_post';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_campaign_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_campaign_blog_post';
  $strongarm->value = '2';
  $export['node_preview_campaign_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_campaign_blog_post';
  $strongarm->value = 1;
  $export['node_submitted_campaign_blog_post'] = $strongarm;

  return $export;
}
