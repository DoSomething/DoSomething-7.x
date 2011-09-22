<?php
/**
 * @file
 * dosomething_webform_action_guide.features.inc
 */

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_webform_action_guide_default_webform_submission_entity_type() {
  $items = array();
  $items['action_guide'] = entity_import('webform_submission_entity_type', '{ "type" : "action_guide", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
