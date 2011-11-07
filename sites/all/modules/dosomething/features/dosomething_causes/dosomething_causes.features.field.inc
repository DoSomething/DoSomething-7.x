<?php
/**
 * @file
 * dosomething_causes.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_causes_field_default_fields() {
  $fields = array();

  // Exported field: 'node-poll-field_description'
  $fields['node-poll-field_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '255',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'tips_and_tools',
    ),
    'field_instance' => array(
      'bundle' => 'poll',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Suggested maximum length 150 characters.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_description',
      'label' => 'Short Description',
      'required' => '1',
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-poll-field_picture'
  $fields['node-poll-field_picture'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_picture',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => NULL,
        'description_field' => '0',
        'list_default' => 1,
        'list_field' => '0',
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
      'type_name' => 'tips_and_tools',
    ),
    'field_instance' => array(
      'bundle' => 'poll',
      'default_value' => '',
      'deleted' => '0',
      'description' => '580px by 580px max',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_picture',
      'label' => 'Picture',
      'required' => '0',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => 'pictures/actionguide',
        'file_extensions' => '',
        'max_filesize' => 0,
        'max_resolution' => '0',
        'min_resolution' => 0,
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => '1',
        'module' => 'image',
        'settings' => array(
          'body_preset' => NULL,
          'image_path' => 'pictures/actionguide',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
          'teaser_preset' => NULL,
          'use_default_image' => 0,
        ),
        'type' => 'image_image',
        'weight' => '2',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-poll-taxonomy_vocabulary_5'
  $fields['node-poll-taxonomy_vocabulary_5'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_5',
      'field_permissions' => array(
        'type' => '0',
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_5',
          ),
        ),
        'profile2_private' => FALSE,
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'poll',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomy_vocabulary_5',
      'label' => 'Causes/Issues',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'options',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'options_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-poll-taxonomyextra'
  $fields['node-poll-taxonomyextra'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomyextra',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'vocabulary_1',
            'parent' => 0,
          ),
          1 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_9',
          ),
          2 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_5',
          ),
          3 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_6',
          ),
          4 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_11',
          ),
          5 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_18',
          ),
          6 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_17',
          ),
          7 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_15',
          ),
          8 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_19',
          ),
          9 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_4',
          ),
          10 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_16',
          ),
          11 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_2',
          ),
          12 => array(
            'parent' => 0,
            'vocabulary' => 'vocabulary_3',
          ),
        ),
        'profile2_private' => FALSE,
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'poll',
      'default_value' => array(
        0 => array(
          'tid' => 'autocreate',
          'vid' => '1',
          'name' => 'anima',
          'vocabulary_machine_name' => 'vocabulary_1',
        ),
      ),
      'deleted' => '0',
      'description' => 'Debris left over after upgrade from Drupal 6',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 10,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomyextra',
      'label' => 'Taxonomy upgrade extras',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '8',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('580px by 580px max');
  t('Causes/Issues');
  t('Debris left over after upgrade from Drupal 6');
  t('Picture');
  t('Short Description');
  t('Suggested maximum length 150 characters.');
  t('Taxonomy upgrade extras');

  return $fields;
}
