<?php
/**
 * @file
 * share_a_stat_scholarship.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function share_a_stat_scholarship_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
 * Implements hook_node_info().
 */
function share_a_stat_scholarship_node_info() {
  $items = array(
    'social_scholarship' => array(
      'name' => t('Social Scholarship'),
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
function share_a_stat_scholarship_default_webform_submission_entity_type() {
  $items = array();
  $items['social_scholarship'] = entity_import('webform_submission_entity_type', '{ "type" : "social_scholarship", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
