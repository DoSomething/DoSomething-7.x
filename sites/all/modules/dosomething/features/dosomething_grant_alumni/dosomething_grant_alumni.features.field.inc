<?php
/**
 * @file
 * dosomething_grant_alumni.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_grant_alumni_field_default_fields() {
  $fields = array();

  // Exported field: 'node-grant_alumni-body'
  $fields['node-grant_alumni-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
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
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'descriptions of winners of Do Something Grants, created by staff',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'trim_length' => 600,
          'type' => 'text_summary_or_trimmed',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Updates',
      'required' => 0,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-grant_alumni-field_alumni_project'
  $fields['node-grant_alumni-field_alumni_project'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_alumni_project',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'action_guide' => 0,
          'blank_page' => 0,
          'cause' => 0,
          'celebs_gone_good' => 0,
          'chatterbox' => 0,
          'club' => 0,
          'club_event' => 0,
          'easy_idea' => 0,
          'feature_content' => 0,
          'feedapi_node' => 0,
          'final_grant_update' => 0,
          'forum' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'help_ticket' => 0,
          'increaseyourgreen_signup' => 0,
          'issue' => 0,
          'member_opportunity' => 0,
          'multichoice' => 0,
          'page' => 0,
          'plum_grant_app' => 0,
          'poll' => 0,
          'project' => 'project',
          'project_update' => 0,
          'quiz' => 0,
          'rant_rave' => 0,
          'scroller' => 0,
          'story' => 0,
          'test_grant_app' => 0,
          'tips_and_tools' => 0,
          'volunteer_opp' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(
            0 => '',
          ),
          'display_name' => 'default',
          'view_name' => '--',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(),
      ),
      'deleted' => '0',
      'description' => 'This is an auto complete field. Start typing and the project should pop up. Hopefully... ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_alumni_project',
      'label' => 'Enter Name of the Project (already in our system) ',
      'required' => '0',
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'weight' => '7',
      'widget' => array(
        'active' => '1',
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '12',
      ),
      'widget_type' => 'nodereference_autocomplete',
    ),
  );

  // Exported field: 'node-grant_alumni-field_city_2'
  $fields['node-grant_alumni-field_city_2'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_city_2',
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
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_city_2',
      'label' => 'City',
      'required' => '0',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '6',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '11',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-grant_alumni-field_contact_information'
  $fields['node-grant_alumni-field_contact_information'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contact_information',
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
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_contact_information',
      'label' => 'Contact Information',
      'required' => '0',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '5',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '10',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-grant_alumni-field_description'
  $fields['node-grant_alumni-field_description'] = array(
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
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Suggested maximum length 150 characters.',
      'display' => array(
        'default' => array(
          'label' => 'above',
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
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'search_result' => array(
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
        'weight' => '1',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-grant_alumni-field_grant_type'
  $fields['node-grant_alumni-field_grant_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_grant_type',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Seed' => 'Seed',
          'Growth' => 'Growth',
          'Be Amazing' => 'Be Amazing',
          'BIC 4 GOOD' => 'BIC 4 GOOD',
          'Boot Camp' => 'Boot Camp',
          'Change for the Children' => 'Change for the Children',
          'Get Well Soon' => 'Get Well Soon',
          'Animal Action' => 'Animal Action',
          'Plum' => 'Plum',
          'Take Action' => 'Take Action',
          'Healthy Living' => 'Healthy Living',
          'Spring Into Action' => 'Spring Into Action',
          'Teach Something' => 'Teach Something',
          'Key Change' => 'Key Change',
          'After School' => 'After School',
          'Dating Abuse' => 'Dating Abuse',
          'General Do Something' => 'General Do Something',
          'Disaster Grant' => 'Disaster Grant',
          'Power in Numbers' => 'Power in Numbers',
          'Do Something Award Winner' => 'Do Something Award Winner',
          'Green Grant' => 'Green Grant',
          'GameStop' => 'GameStop',
          'Youth to Youth' => 'Youth to Youth',
          'Smart Driving' => 'Smart Driving',
          'Other' => 'Other',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => 'Plum',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_grant_type',
      'label' => 'Select the grant that you received',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => '1',
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '5',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-grant_alumni-field_money_for'
  $fields['node-grant_alumni-field_money_for'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_money_for',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'scholarship' => 'scholarship',
          'grant' => 'grant',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '\'award\' will be added as an option when the awards_archive nodes are converted to grant_alumni',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '-1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'mobile' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'rss' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_money_for',
      'label' => 'What was the money for?',
      'required' => '0',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-1',
      'widget' => array(
        'active' => '1',
        'module' => 'options',
        'settings' => array(
          'default_value_php' => NULL,
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-grant_alumni-field_picture'
  $fields['node-grant_alumni-field_picture'] = array(
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
      'bundle' => 'grant_alumni',
      'default_value' => '',
      'deleted' => '0',
      'description' => '580px by 580px max',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'square_thumbnail',
          ),
          'type' => 'image',
          'weight' => '-3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-3',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '-3',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '-3',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_picture',
      'label' => 'Picture',
      'required' => '0',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => 'pictures/actionguide',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '0',
        'min_resolution' => '0',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'weight' => '-3',
      'widget' => array(
        'active' => '1',
        'module' => 'image',
        'settings' => array(
          'body_preset' => NULL,
          'image_path' => 'pictures/actionguide',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'bar',
          'teaser_preset' => NULL,
          'use_default_image' => 0,
        ),
        'type' => 'image_image',
        'weight' => '2',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-grant_alumni-field_recipient_age'
  $fields['node-grant_alumni-field_recipient_age'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_recipient_age',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_recipient_age',
      'label' => 'Recipient\'s Age',
      'required' => '0',
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '9',
      'widget' => array(
        'active' => '1',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '15',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-grant_alumni-field_recipient_birthdate'
  $fields['node-grant_alumni-field_recipient_birthdate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_recipient_birthdate',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          0 => 'year',
          1 => 'month',
          2 => 'day',
        ),
        'repeat' => '',
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datestamp',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_recipient_birthdate_short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '10',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_recipient_birthdate_short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '10',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_recipient_birthdate_short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '10',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_recipient_birthdate_short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_recipient_birthdate_short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_recipient_birthdate',
      'label' => 'Recipient\'s Birth Date',
      'required' => '1',
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'blank',
        'default_value_code' => NULL,
        'default_value_code2' => NULL,
        'user_register_form' => FALSE,
      ),
      'weight' => '10',
      'widget' => array(
        'active' => '1',
        'module' => 'date',
        'settings' => array(
          'default_value_custom' => '',
          'default_value_custom2' => '',
          'display_all_day' => 0,
          'increment' => '1',
          'input_format' => 'site-wide',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => '',
          'text_parts' => array(),
          'year_range' => '-30:+30',
        ),
        'type' => 'date_select',
        'weight' => '16',
      ),
      'widget_type' => 'date_select',
    ),
  );

  // Exported field: 'node-grant_alumni-field_scholarship_type'
  $fields['node-grant_alumni-field_scholarship_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_scholarship_type',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'eMission' => 'eMission',
          'Epic Book Drive' => 'Epic Book Drive',
          'e-Waste Drive Scholarship' => 'e-Waste Drive Scholarship',
          'General Do Something Scholarship' => 'General Do Something Scholarship',
          'Green Your School' => 'Green Your School',
          'Healthy Schools Challenge' => 'Healthy Schools Challenge',
          'Join the Surge' => 'Join the Surge',
          'Do Good, Look Good Scholarship' => 'Do Good, Look Good Scholarship',
          'Scavenger Hunt' => 'Scavenger Hunt',
          'Six Flags Friends' => 'Six Flags Friends',
          'Sports Equipment Drive Scholarship' => 'Sports Equipment Drive Scholarship',
          'Staples Design Contest' => 'Staples Design Contest',
          'Thumb Wars Design Contest' => 'Thumb Wars Design Contest',
          'We <3 Action' => 'We <3 Action',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'scholarship_update',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'mobile' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'rss' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_scholarship_type',
      'label' => 'Which scholarship?',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '1',
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '7',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-grant_alumni-field_state_plain'
  $fields['node-grant_alumni-field_state_plain'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_state_plain',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'AK' => 'AK',
          'AL' => 'AL',
          'AR' => 'AR',
          'AS' => 'AS',
          'AZ' => 'AZ',
          'CA' => 'CA',
          'CO' => 'CO',
          'CT' => 'CT',
          'DC' => 'DC',
          'DE' => 'DE',
          'FL' => 'FL',
          'FM' => 'FM',
          'GA' => 'GA',
          'GU' => 'GU',
          'HI' => 'HI',
          'IA' => 'IA',
          'ID' => 'ID',
          'IL' => 'IL',
          'IN' => 'IN',
          'KS' => 'KS',
          'KY' => 'KY',
          'LA' => 'LA',
          'MA' => 'MA',
          'MD' => 'MD',
          'ME' => 'ME',
          'MH' => 'MH',
          'MI' => 'MI',
          'MN' => 'MN',
          'MO' => 'MO',
          'MP' => 'MP',
          'MS' => 'MS',
          'MT' => 'MT',
          'NC' => 'NC',
          'ND' => 'ND',
          'NE' => 'NE',
          'NH' => 'NH',
          'NJ' => 'NJ',
          'NM' => 'NM',
          'NV' => 'NV',
          'NY' => 'NY',
          'OH' => 'OH',
          'OK' => 'OK',
          'OR' => 'OR',
          'PA' => 'PA',
          'PR' => 'PR',
          'PW' => 'PW',
          'RI' => 'RI',
          'SC' => 'SC',
          'SD' => 'SD',
          'TN' => 'TN',
          'TX' => 'TX',
          'UT' => 'UT',
          'VA' => 'VA',
          'VI' => 'VI',
          'VT' => 'VT',
          'WA' => 'WA',
          'WI' => 'WI',
          'WV' => 'WV',
          'WY' => 'WY',
          'Canada' => 'Canada',
          'Puerto Rico' => 'Puerto Rico',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'youth_grant_app',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_state_plain',
      'label' => 'State',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '3',
      'widget' => array(
        'active' => '1',
        'module' => 'options',
        'settings' => array(
          'default_value_php' => NULL,
        ),
        'type' => 'options_select',
        'weight' => '8',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-grant_alumni-field_webform_project_submission'
  $fields['node-grant_alumni-field_webform_project_submission'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_project_submission',
      'field_permissions' => array(
        'type' => '0',
      ),
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
          'author_only' => 1,
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
        'profile2_private' => FALSE,
        'target_type' => 'webform_submission_entity',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
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
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_webform_project_submission',
      'label' => 'Enter Name of the Project (already in our system)',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-grant_alumni-field_year_awarded'
  $fields['node-grant_alumni-field_year_awarded'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_year_awarded',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'grant_alumni',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_year_awarded',
      'label' => 'Year in which grant was awarded',
      'required' => '0',
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '8',
      'widget' => array(
        'active' => '1',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '14',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-grant_alumni-taxonomy_vocabulary_5'
  $fields['node-grant_alumni-taxonomy_vocabulary_5'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_5',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
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
            'vocabulary' => 'vocabulary_5',
            'parent' => '0',
          ),
        ),
        'profile2_private' => 1,
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'hold down ctrl button to select more than one',
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
      'field_name' => 'taxonomy_vocabulary_5',
      'label' => 'Issues',
      'required' => '0',
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-grant_alumni-upload'
  $fields['node-grant_alumni-upload'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'upload',
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'default_file' => 0,
        'display_default' => '1',
        'display_field' => 1,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'grant_alumni',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => NULL,
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'upload',
      'label' => 'File attachments',
      'required' => 0,
      'settings' => array(
        'description_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp4 mov mp3 php3',
        'max_filesize' => '8 MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'file',
        'settings' => array(
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '6',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('\'award\' will be added as an option when the awards_archive nodes are converted to grant_alumni');
  t('580px by 580px max');
  t('City');
  t('Contact Information');
  t('Enter Name of the Project (already in our system)');
  t('Enter Name of the Project (already in our system) ');
  t('File attachments');
  t('Issues');
  t('Picture');
  t('Recipient\'s Age');
  t('Recipient\'s Birth Date');
  t('Select the grant that you received');
  t('Short Description');
  t('State');
  t('Suggested maximum length 150 characters.');
  t('This is an auto complete field. Start typing and the project should pop up. Hopefully... ');
  t('Updates');
  t('What was the money for?');
  t('Which scholarship?');
  t('Year in which grant was awarded');
  t('descriptions of winners of Do Something Grants, created by staff');
  t('hold down ctrl button to select more than one');

  return $fields;
}
