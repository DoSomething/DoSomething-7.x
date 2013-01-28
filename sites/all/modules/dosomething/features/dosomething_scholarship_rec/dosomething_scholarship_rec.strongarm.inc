<?php
/**
 * @file
 * dosomething_scholarship_rec.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_scholarship_rec_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__scholarship_application_with_rec';
  $strongarm->value = array(
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
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scholarship_application_with_rec';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scholarship_recommendation';
  $strongarm->value = array();
  $export['menu_options_scholarship_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scholarship_recommendation_reque';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_scholarship_recommendation_reque'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scholarship_application_with_rec';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scholarship_recommendation';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scholarship_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scholarship_recommendation_reque';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scholarship_recommendation_reque'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholarship_application_with_rec';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholarship_recommendation';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scholarship_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholarship_recommendation_reque';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scholarship_recommendation_reque'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scholarship_application_with_rec';
  $strongarm->value = '0';
  $export['node_preview_scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scholarship_recommendation';
  $strongarm->value = '0';
  $export['node_preview_scholarship_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scholarship_recommendation_reque';
  $strongarm->value = '0';
  $export['node_preview_scholarship_recommendation_reque'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scholarship_application_with_rec';
  $strongarm->value = 0;
  $export['node_submitted_scholarship_application_with_rec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scholarship_recommendation';
  $strongarm->value = 0;
  $export['node_submitted_scholarship_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scholarship_recommendation_reque';
  $strongarm->value = 0;
  $export['node_submitted_scholarship_recommendation_reque'] = $strongarm;

  return $export;
}
