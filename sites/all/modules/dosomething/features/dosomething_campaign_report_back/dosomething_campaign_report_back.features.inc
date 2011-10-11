<?php
/**
 * @file
 * dosomething_campaign_report_back.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_report_back_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_report_back_node_info() {
  $items = array(
    'campaign_report_back' => array(
      'name' => t('Campaign Report Back'),
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
function dosomething_campaign_report_back_default_webform_submission_entity_type() {
  $items = array();
  $items['campaign_report_back'] = entity_import('webform_submission_entity_type', '{ "type" : "campaign_report_back", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
