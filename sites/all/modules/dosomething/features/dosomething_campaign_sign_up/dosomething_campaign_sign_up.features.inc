<?php
/**
 * @file
 * dosomething_campaign_sign_up.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_sign_up_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_sign_up_node_info() {
  $items = array(
    'campaign_sign_up' => array(
      'name' => t('Campaign Sign Up'),
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
function dosomething_campaign_sign_up_default_webform_submission_entity_type() {
  $items = array();
  $items['campaign_sign_up'] = entity_import('webform_submission_entity_type', '{ "type" : "campaign_sign_up", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
