<?php
/**
 * @file
 * dosomething_project_report.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_project_report_ctools_plugin_api() {
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
function dosomething_project_report_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dosomething_project_report_node_info() {
  $items = array(
    'project_report' => array(
      'name' => t('Project Report'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project_update' => array(
      'name' => t('Project Update'),
      'base' => 'node_content',
      'description' => t('An update for an existing project'),
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
function dosomething_project_report_default_webform_submission_entity_type() {
  $items = array();
  $items['project_report'] = entity_import('webform_submission_entity_type', '{
    "type" : "project_report",
    "data" : null,
    "metatags" : [],
    "rdf_mapping" : []
  }');
  return $items;
}
