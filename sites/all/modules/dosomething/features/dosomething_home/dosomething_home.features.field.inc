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
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Link');
  t('Picture');
  t('Short Description');
  t('Suggested maximum length 150 characters.');
  t('WIDTH: 445px HEIGHT: 395px');

  return $fields;
}
