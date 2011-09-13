<?php
/**
 * @file
 * dosomething_webform_grant_application.features.inc
 */

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_webform_grant_application_default_webform_submission_entity_type() {
  $items = array();
  $items['grant_application'] = entity_import('webform_submission_entity_type', '{ "type" : "grant_application", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
