<?php
/**
 * @file
 * dosomething_entityqueue.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_entityqueue_field_default_fields() {
  $fields = array();

  // Exported field: 'entityqueue-dosomething_project-eq_dosomething_project'
  $fields['entityqueue-dosomething_project-eq_dosomething_project'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'entityqueue',
      ),
      'field_name' => 'eq_dosomething_project',
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'entityreference_entity_field',
        'handler_settings' => array(
          'author_only' => 0,
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'field_essay_build_it:value',
            'property' => 'sid',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'project_report' => 'project_report',
          ),
          'title_field' => 'field_project_title',
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'webform_submission_entity',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'dosomething_project',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'entityqueue',
      'field_name' => 'eq_dosomething_project',
      'label' => 'Queue items',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => 60,
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => 0,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Queue items');

  return $fields;
}
