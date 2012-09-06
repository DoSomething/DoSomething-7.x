<?php
/**
 * @file
 * dosomething_scholarship_rec.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_scholarship_rec_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_scholarship_rec_node_info() {
  $items = array(
    'scholarship_application_with_rec' => array(
      'name' => t('Scholarship Application with Recommendations'),
      'base' => 'node_content',
      'description' => t('Used for scholarship applications that have recommendations attached to them.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scholarship_recommendation' => array(
      'name' => t('Scholarship Recommendation'),
      'base' => 'node_content',
      'description' => t('Recommendation form for a scholarship.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scholarship_recommendation_reque' => array(
      'name' => t('Scholarship Recommendation Request'),
      'base' => 'node_content',
      'description' => t('Request form for getting a recommendation for a scholarship app.'),
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
function dosomething_scholarship_rec_default_webform_submission_entity_type() {
  $items = array();
  $items['scholarship_application_with_rec'] = entity_import('webform_submission_entity_type', '{
    "type" : "scholarship_application_with_rec",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['scholarship_recommendation'] = entity_import('webform_submission_entity_type', '{
    "type" : "scholarship_recommendation",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['scholarship_recommendation_reque'] = entity_import('webform_submission_entity_type', '{
    "type" : "scholarship_recommendation_reque",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
