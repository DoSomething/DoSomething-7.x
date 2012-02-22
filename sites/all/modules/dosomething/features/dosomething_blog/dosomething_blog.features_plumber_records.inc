<?php
/**
 * @file
 * dosomething_blog.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function dosomething_blog_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'dosomething_blog__field__taxonomy_term-vocabulary_5-field_causes_image';
  $features_plumber_record->feature = 'dosomething_blog';
  $features_plumber_record->component = 'field';
  $features_plumber_record->component_val = 'taxonomy_term-vocabulary_5-field_causes_image';
  $export['dosomething_blog__field__taxonomy_term-vocabulary_5-field_causes_image'] = $features_plumber_record;

  return $export;
}
