<?php
/**
 * @file
 * dosomething_webform_campaign_report_back.features.inc
 */

/**
 * Implementation of hook_default_webform_submission_entity_type().
 */
function dosomething_webform_campaign_report_back_default_webform_submission_entity_type() {
  $items = array();
  $items['campaign_report_back'] = entity_import('webform_submission_entity_type', '{ "type" : "campaign_report_back", "data" : null, "rdf_mapping" : [] }');
  return $items;
}
