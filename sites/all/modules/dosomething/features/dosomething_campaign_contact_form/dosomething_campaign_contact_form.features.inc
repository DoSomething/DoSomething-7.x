<?php
/**
 * @file
 * dosomething_campaign_contact_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_campaign_contact_form_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_campaign_contact_form_node_info() {
  $items = array(
    'campaign_contact_form' => array(
      'name' => t('Campaign Contact Form'),
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
function dosomething_campaign_contact_form_default_webform_submission_entity_type() {
  $items = array();
  $items['campaign_contact_form'] = entity_import('webform_submission_entity_type', '{ "type" : "campaign_contact_form", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
