<?php
/**
 * @file
 * dosomething_grant_application.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_grant_application_node_info() {
  $items = array(
    'grant_application' => array(
      'name' => t('Grant Application'),
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
function dosomething_grant_application_default_webform_submission_entity_type() {
  $items = array();
  $items['grant_application'] = entity_import('webform_submission_entity_type', '{ "type" : "grant_application", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
