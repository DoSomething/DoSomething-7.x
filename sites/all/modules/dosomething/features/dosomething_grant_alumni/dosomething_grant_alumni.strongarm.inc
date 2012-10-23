<?php
/**
 * @file
 * dosomething_grant_alumni.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_grant_alumni_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__grant_alumni';
  $strongarm->value = array(
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'body' => array(
          'weight' => '4',
        ),
        'revision_information' => array(
          'weight' => '12',
        ),
        'author' => array(
          'weight' => '13',
        ),
        'options' => array(
          'weight' => '14',
        ),
        'comment_settings' => array(
          'weight' => '17',
        ),
        'menu' => array(
          'weight' => '2',
        ),
        'taxonomy' => array(
          'weight' => '-2',
        ),
        'path' => array(
          'weight' => '17',
        ),
        'attachments' => array(
          'weight' => '16',
        ),
        'path_redirect' => array(
          'weight' => '15',
        ),
        'nodewords' => array(
          'weight' => '11',
        ),
        'redirect' => array(
          'weight' => '18',
        ),
      ),
      'display' => array(),
    ),
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__grant_alumni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_grant_alumni';
  $strongarm->value = array(
    0 => 'navigation',
  );
  $export['menu_options_grant_alumni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_grant_alumni';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_grant_alumni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_grant_alumni';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_grant_alumni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_grant_alumni';
  $strongarm->value = 1;
  $export['node_preview_grant_alumni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_grant_alumni';
  $strongarm->value = 1;
  $export['node_submitted_grant_alumni'] = $strongarm;

  return $export;
}
