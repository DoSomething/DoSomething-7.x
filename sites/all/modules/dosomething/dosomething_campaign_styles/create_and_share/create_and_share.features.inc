<?php
/**
 * @file
 * create_and_share.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function create_and_share_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function create_and_share_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function create_and_share_node_info() {
  $items = array(
    'create_and_share_campaign' => array(
      'name' => t('Create and Share Campaign'),
      'base' => 'node_content',
      'description' => t('Create and Share Campaign (Craziest Thing, Pics 4 Pets)'),
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
function create_and_share_default_webform_submission_entity_type() {
  $items = array();
  $items['create_and_share_campaign'] = entity_import('webform_submission_entity_type', '{
    "type" : "create_and_share_campaign",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
