<?php
/**
 * @file
 * dosomething_webform_scholarship_application.features.inc
 */

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_webform_scholarship_application_default_webform_submission_entity_type() {
  $items = array();
  $items['scholarship_application'] = entity_import('webform_submission_entity_type', '{ "type" : "scholarship_application", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
