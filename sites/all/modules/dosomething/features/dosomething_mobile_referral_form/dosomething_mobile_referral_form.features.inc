<?php
/**
 * @file
 * dosomething_mobile_referral_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_mobile_referral_form_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function dosomething_mobile_referral_form_node_info() {
  $items = array(
    'mobile_referral_form' => array(
      'name' => t('Mobile Referral Form'),
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
function dosomething_mobile_referral_form_default_webform_submission_entity_type() {
  $items = array();
  $items['mobile_referral_form'] = entity_import('webform_submission_entity_type', '{ "type" : "mobile_referral_form", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
