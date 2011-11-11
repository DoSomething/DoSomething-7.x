<?php
/**
 * @file
 * dosomething_scholarship_application.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_scholarship_application_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_scholarship_application_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_scholarship_application_node_info() {
  $items = array(
    'scholarship' => array(
      'name' => t('Scholarship'),
      'base' => 'node_content',
      'description' => t('Scholarship information node'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scholarship_application' => array(
      'name' => t('Scholarship Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_webform_submission_entity_type().
 */
function dosomething_scholarship_application_default_webform_submission_entity_type() {
  $items = array();
  $items['scholarship_application'] = entity_import('webform_submission_entity_type', '{ "type" : "scholarship_application", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
