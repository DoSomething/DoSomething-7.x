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
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dosomething_scholarship_rec_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_entityqueue_default_queues().
 */
function dosomething_scholarship_rec_entityqueue_default_queues() {
  $items = array();
  $items['foot_locker_maybe'] = entity_import('entityqueue', '{
    "name" : "foot_locker_maybe",
    "parent_name" : null,
    "type" : "webform_submission_entity",
    "subqueue" : "1",
    "label" : "Foot Locker Maybe",
    "subqueue_label" : "",
    "uid" : "1",
    "data" : {
      "target_bundles" : { "scholarship_application_with_rec" : "scholarship_application_with_rec" },
      "min_size" : "0",
      "max_size" : "0"
    },
    "eq_webform_submission_entity" : { "und" : [ { "target_id" : "1395639" } ] },
    "rdf_mapping" : []
  }');
  $items['foot_locker_no'] = entity_import('entityqueue', '{
    "name" : "foot_locker_no",
    "parent_name" : null,
    "type" : "webform_submission_entity",
    "subqueue" : "1",
    "label" : "Foot Locker No",
    "subqueue_label" : "",
    "uid" : "1",
    "data" : {
      "target_bundles" : { "scholarship_application_with_rec" : "scholarship_application_with_rec" },
      "min_size" : "0",
      "max_size" : "0"
    },
    "eq_webform_submission_entity" : [],
    "rdf_mapping" : []
  }');
  $items['foot_locker_yes'] = entity_import('entityqueue', '{
    "name" : "foot_locker_yes",
    "parent_name" : null,
    "type" : "webform_submission_entity",
    "subqueue" : "1",
    "label" : "Foot Locker Yes",
    "subqueue_label" : "",
    "uid" : "1",
    "data" : {
      "target_bundles" : { "scholarship_application_with_rec" : "scholarship_application_with_rec" },
      "min_size" : "0",
      "max_size" : "0"
    },
    "eq_webform_submission_entity" : [],
    "rdf_mapping" : []
  }');
  return $items;
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
