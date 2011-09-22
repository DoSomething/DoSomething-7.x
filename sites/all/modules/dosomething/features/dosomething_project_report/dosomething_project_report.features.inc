<?php
/**
 * @file
 * dosomething_project_report.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function dosomething_project_report_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function dosomething_project_report_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
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
  );
  return $items;
}

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_project_report_default_webform_submission_entity_type() {
  $items = array();
  $items['project_report'] = entity_import('webform_submission_entity_type', '{ "type" : "project_report", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
