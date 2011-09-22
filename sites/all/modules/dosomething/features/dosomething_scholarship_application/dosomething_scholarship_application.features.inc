<?php
/**
 * @file
 * dosomething_scholarship_application.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function dosomething_scholarship_application_node_info() {
  $items = array(
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
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_scholarship_application_default_webform_submission_entity_type() {
  $items = array();
  $items['scholarship_application'] = entity_import('webform_submission_entity_type', '{ "type" : "scholarship_application", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
