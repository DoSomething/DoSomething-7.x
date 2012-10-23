<?php
/**
 * @file
 * dosomething_fb_apps.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dosomething_fb_apps_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_fb_app_data_gathering_form';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_fb_app_data_gathering_form';
  $strongarm->value = 1;
  $export['enable_revisions_page_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fb_canvas_process_iframe';
  $strongarm->value = 0;
  $export['fb_canvas_process_iframe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_webform_submission_entity__fb_app_data_gathering_form';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_webform_submission_entity__fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_fb_app_data_gathering_form';
  $strongarm->value = array();
  $export['menu_options_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_fb_app_data_gathering_form';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_fb_app_data_gathering_form';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_fb_app_data_gathering_form';
  $strongarm->value = '0';
  $export['node_preview_fb_app_data_gathering_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_fb_app_data_gathering_form';
  $strongarm->value = 0;
  $export['node_submitted_fb_app_data_gathering_form'] = $strongarm;

  return $export;
}
