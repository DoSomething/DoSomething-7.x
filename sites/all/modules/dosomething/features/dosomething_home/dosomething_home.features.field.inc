<?php
/**
 * @file
 * dosomething_home.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_home_field_default_fields() {
  $fields = array();

  // Exported field: 'node-scroller-field_description'
  $fields['node-scroller-field_description'] = array(
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
      'bundle' => 'scroller',
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
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'above',
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
        'weight' => '-4',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-scroller-field_link'
  $fields['node-scroller-field_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_link',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'profile2_private' => FALSE,
        'title' => 'none',
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
      'type_name' => 'scroller',
    ),
    'field_instance' => array(
      'bundle' => 'scroller',
      'default_value' => array(
        0 => array(
          'url' => '',
          'attributes' => 'N;',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_link',
      'label' => 'Link',
      'required' => '0',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
      ),
      'weight' => '1',
      'widget' => array(
        'active' => '1',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '1',
      ),
      'widget_type' => 'link',
    ),
  );

  // Exported field: 'node-scroller-field_picture'
  $fields['node-scroller-field_picture'] = array(
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
        'default_image' => 0,
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
      'bundle' => 'scroller',
      'default_value' => '',
      'deleted' => '0',
      'description' => 'WIDTH: 445px HEIGHT: 395px',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_picture',
      'label' => 'Picture',
      'required' => '0',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => 'pictures/actionguide',
        'file_extensions' => 'jpg jpeg png gif',
        'max_filesize' => '',
        'max_resolution' => '0',
        'min_resolution' => '0',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'weight' => '1',
      'widget' => array(
        'active' => '1',
        'module' => 'image',
        'settings' => array(
          'image_path' => 'pictures/actionguide',
          'max_filesize' => '0',
          'max_number_images' => '0',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'bar',
          'use_default_image' => 0,
        ),
        'type' => 'image_image',
        'weight' => '1',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-scroller-taxonomyextra'
  $fields['node-scroller-taxonomyextra'] = array(
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
      'bundle' => 'scroller',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Debris left over after upgrade from Drupal 6',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
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
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => 0,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Debris left over after upgrade from Drupal 6');
  t('Link');
  t('Picture');
  t('Short Description');
  t('Suggested maximum length 150 characters.');
  t('Taxonomy upgrade extras');
  t('WIDTH: 445px HEIGHT: 395px');

  return $fields;
}
