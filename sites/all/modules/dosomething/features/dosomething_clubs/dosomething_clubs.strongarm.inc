<?php
/**
 * @file
 * dosomething_clubs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_clubs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__club';
  $strongarm->value = array(
    'extra_fields' => array(
      'form' => array(
        'body' => array(
          'weight' => 0,
        ),
        'title' => array(
          'weight' => '1',
        ),
        'revision_information' => array(
          'weight' => '16',
        ),
        'author' => array(
          'weight' => '17',
        ),
        'options' => array(
          'weight' => '18',
        ),
        'comment_settings' => array(
          'weight' => '20',
        ),
        'menu' => array(
          'weight' => '10',
        ),
        'taxonomy' => array(
          'weight' => '8',
        ),
        'path' => array(
          'weight' => '13',
        ),
        'locations' => array(
          'weight' => '14',
        ),
        'og_description' => array(
          'weight' => '-3',
        ),
        'og_selective' => array(
          'weight' => '13',
        ),
        'og_register' => array(
          'weight' => '11',
        ),
        'og_directory' => array(
          'weight' => '12',
        ),
        'path_redirect' => array(
          'weight' => '21',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
        'nodewords' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
      ),
      'display' => array(),
    ),
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__club'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'DefaultMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_club';
  $strongarm->value = array();
  $export['menu_options_club'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_club';
  $strongarm->value = 'navigation:0';
  $export['menu_parent_club'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_club';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_club'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_club';
  $strongarm->value = '1';
  $export['node_preview_club'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_club';
  $strongarm->value = 0;
  $export['node_submitted_club'] = $strongarm;

  return $export;
}
