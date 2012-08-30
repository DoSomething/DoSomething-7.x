<?php
/**
 * @file
 * dosomething_drives.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_drives_field_default_fields() {
  $fields = array();

  // Exported field: 'node-drive_form-group_audience'
  $fields['node-drive_form-group_audience'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'group_audience',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'og' => array(
          'columns' => array(
            'gid' => 'gid',
          ),
          'table' => 'og',
        ),
      ),
      'indexes' => array(
        'gid' => array(
          0 => 'gid',
        ),
      ),
      'module' => 'og',
      'no_ui' => TRUE,
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'group',
    ),
    'field_instance' => array(
      'bundle' => 'drive_form',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og',
          'settings' => array(),
          'type' => 'og_list_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'group_audience',
      'label' => 'Campaign',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'custom settings' => FALSE,
          'label' => 'Full',
          'type' => 'og_list_default',
        ),
        'teaser' => array(
          'custom settings' => FALSE,
          'label' => 'Teaser',
          'type' => 'og_list_default',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'og',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'group/autocomplete',
          'opt_group' => 'auto',
          'size' => 60,
        ),
        'type' => 'group_audience_autocomplete',
        'weight' => 0,
      ),
      'widget_type' => 'group_audience',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Campaign');

  return $fields;
}
