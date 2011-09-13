<?php
/**
 * @file
 * dosomething_webform_campaign_sign_up.features.inc
 */

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_webform_campaign_sign_up_default_webform_submission_entity_type() {
  $items = array();
  $items['campaign_sign_up'] = entity_import('webform_submission_entity_type', '{ "type" : "campaign_sign_up", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
