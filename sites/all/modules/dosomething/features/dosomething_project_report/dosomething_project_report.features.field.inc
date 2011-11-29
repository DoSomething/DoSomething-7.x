<?php
/**
 * @file
 * dosomething_project_report.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_project_report_field_default_fields() {
  $fields = array();

  // Exported field: 'node-project_report-field_body_anonymous'
  $fields['node-project_report-field_body_anonymous'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_body_anonymous',
      'field_permissions' => array(
        'type' => '2',
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
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.<br />
The content from this field will only be shown to anonymous users.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_body_anonymous',
      'label' => 'Body (anonymous user)',
      'required' => 0,
      'settings' => array(
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-project_report-field_body_logged_in'
  $fields['node-project_report-field_body_logged_in'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_body_logged_in',
      'field_permissions' => array(
        'type' => '2',
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
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The content from this field will only be shown to logged in users.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_body_logged_in',
      'label' => 'Body (logged in user)',
      'required' => 0,
      'settings' => array(
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-vocabulary_5-field_causes_image'
  $fields['taxonomy_term-vocabulary_5-field_causes_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_causes_image',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'vocabulary_5',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_causes_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_award_winner'
  $fields['webform_submission_entity-project_report-field_award_winner'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_award_winner',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'no',
          1 => 'yes',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_award_winner',
      'label' => 'DoSomething Award Winner',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_essay_believe_it'
  $fields['webform_submission_entity-project_report-field_essay_believe_it'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_essay_believe_it',
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
        'max_length' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Describe your project/organization and how it addresses the problem(s) above.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_essay_believe_it',
      'label' => 'Why is it important to you?',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '21',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_essay_build_it'
  $fields['webform_submission_entity-project_report-field_essay_build_it'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_essay_build_it',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Describe the steps you will take/took to create your project or organization.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_essay_build_it',
      'label' => 'What\'s your plan of action?',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_essay_see_it'
  $fields['webform_submission_entity-project_report-field_essay_see_it'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_essay_see_it',
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
        'max_length' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Tell us about the community you are helping and the problem(s) being solved.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_essay_see_it',
      'label' => 'What\'s the problem you are trying to solve?',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_fb_like_count'
  $fields['webform_submission_entity-project_report-field_fb_like_count'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_fb_like_count',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'profile2_private' => FALSE,
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
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
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '18',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_fb_like_count',
      'label' => 'Facebook like count',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_hours_volunteered'
  $fields['webform_submission_entity-project_report-field_hours_volunteered'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_hours_volunteered',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'profile2_private' => FALSE,
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'how many hours have you spent on this project',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '15',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_hours_volunteered',
      'label' => 'Total hours volunteered (to date)',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '23',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_link'
  $fields['webform_submission_entity-project_report-field_link'] = array(
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
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_link',
      'label' => 'Web site link',
      'required' => 0,
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
        'title' => 'optional',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_num_people_impacted'
  $fields['webform_submission_entity-project_report-field_num_people_impacted'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_num_people_impacted',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'profile2_private' => FALSE,
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '(i.e. Number of people you provided food for through your collection, etc.) Use digits, for example: "20", "100"',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_num_people_impacted',
      'label' => 'How many people has your project helped?',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_num_people_inspired'
  $fields['webform_submission_entity-project_report-field_num_people_inspired'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_num_people_inspired',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '',
        'min' => '',
        'prefix' => '',
        'profile2_private' => FALSE,
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '(i.e. Number of people who donated canned goods to your canned food drive, etc.)',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '7',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_num_people_inspired',
      'label' => 'How many people have you inspired to take action?',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_others_involved'
  $fields['webform_submission_entity-project_report-field_others_involved'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_others_involved',
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
        'max_length' => '',
        'profile2_private' => FALSE,
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'project',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_others_involved',
      'label' => 'How Can Others Help? ',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_picture'
  $fields['webform_submission_entity-project_report-field_picture'] = array(
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
      'bundle' => 'project_report',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_picture',
      'label' => 'Project Photo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_action_guide'
  $fields['webform_submission_entity-project_report-field_project_action_guide'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_action_guide',
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
        'profile2_private' => FALSE,
        'referenceable_types' => array(
          '1in3_abuse_old' => 0,
          '301_redirects' => 0,
          '911_registration' => 0,
          'abc_family' => 0,
          'action_guide' => 0,
          'api_key' => 0,
          'aspca_grant_app' => 0,
          'awards_archive' => 0,
          'bc_bio_form' => 0,
          'blog' => 0,
          'campaign' => 0,
          'campaign_art_2011' => 0,
          'campaign_bfb_2011' => 0,
          'campaign_bully_2011' => 0,
          'campaign_ebd_2011' => 0,
          'campaign_ew_2011' => 0,
          'campaign_gys_2011' => 0,
          'campaign_hunt_2011' => 0,
          'campaign_macys_2011' => 0,
          'campaign_report_back' => 0,
          'campaign_sign_up' => 0,
          'campaign_sports_2011' => 0,
          'cancer_2011_signup' => 0,
          'canned_food' => 0,
          'cause' => 0,
          'cause_video' => 0,
          'club' => 0,
          'club_event' => 0,
          'club_first_meeting_cash' => 0,
          'decade_2011_signup' => 0,
          'ds101_action_kit' => 0,
          'ds_award_judging' => 0,
          'dsaward_app' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'ebd_signup' => 0,
          'editorial_project' => 0,
          'ewaste_signup_2011' => 0,
          'feed' => 0,
          'feed_item' => 0,
          'final_grant_update' => 0,
          'general_grant_app' => 0,
          'general_scholarship_app' => 0,
          'grant' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'grant_judge' => 0,
          'grants_database' => 0,
          'gys_2011' => 0,
          'healthy_schools' => 0,
          'healthy_schools_report' => 0,
          'help_ticket' => 0,
          'huffpo' => 0,
          'ididthis' => 0,
          'increaseyourgreen_signup' => 0,
          'issue' => 0,
          'page' => 0,
          'poll' => 0,
          'press' => 0,
          'project' => 0,
          'project_report' => 0,
          'project_update' => 0,
          'save_our_music' => 0,
          'scavenger_2011_signup' => 0,
          'scholarship_application' => 0,
          'scholarship_update' => 0,
          'scholarships_att' => 0,
          'school' => 0,
          'scroller' => 0,
          'sfs_report_gallery' => 0,
          'sixflags_scholarships_app' => 0,
          'staples_2011_signup' => 0,
          'staples_members' => 0,
          'staples_reason' => 0,
          'tackle_hunger' => 0,
          'tfj_contest_signup' => 0,
          'tips_and_tools' => 0,
          'troop_letter' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '21',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_action_guide',
      'label' => 'OPTIONAL - Link DoSomething action guides or fact pages to this project',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '25',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_clubs'
  $fields['webform_submission_entity-project_report-field_project_clubs'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_clubs',
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
        'profile2_private' => FALSE,
        'referenceable_types' => array(
          '1in3_abuse_old' => 0,
          '301_redirects' => 0,
          '911_registration' => 0,
          'abc_family' => 0,
          'action_guide' => 0,
          'api_key' => 0,
          'aspca_grant_app' => 0,
          'awards_archive' => 0,
          'bc_bio_form' => 0,
          'campaign_bfb_2011' => 0,
          'campaign_bully_2011' => 0,
          'campaign_ebd_2011' => 0,
          'campaign_ew_2011' => 0,
          'campaign_gys_2011' => 0,
          'campaign_hunt_2011' => 0,
          'campaign_macys_2011' => 0,
          'campaign_report_back' => 0,
          'campaign_sign_up' => 0,
          'campaign_sports_2011' => 0,
          'canned_food' => 0,
          'cause' => 0,
          'cause_video' => 0,
          'celebs_gone_good' => 0,
          'chatterbox' => 0,
          'club' => 'club',
          'club_event' => 0,
          'club_first_meeting_cash' => 0,
          'custom_voting' => 0,
          'decade_2011_signup' => 0,
          'ds101_action_kit' => 0,
          'ds_award_judging' => 0,
          'dsaward_app' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'ebd_signup' => 0,
          'editorial_project' => 0,
          'ewaste_signup_2011' => 0,
          'final_grant_update' => 0,
          'forum' => 0,
          'general_grant_app' => 0,
          'general_scholarship_app' => 0,
          'grant' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'grant_judge' => 0,
          'grants_database' => 0,
          'gys_2011' => 0,
          'healthy_schools' => 0,
          'healthy_schools_report' => 0,
          'help_ticket' => 0,
          'ididthis' => 0,
          'increaseyourgreen_signup' => 0,
          'issue' => 0,
          'page' => 0,
          'poll' => 0,
          'press' => 0,
          'project' => 0,
          'project_report' => 0,
          'project_update' => 0,
          'save_our_music' => 0,
          'scavenger_2011_signup' => 0,
          'scholarship_application' => 0,
          'scholarship_update' => 0,
          'scholarships_att' => 0,
          'scroller' => 0,
          'sfs_report_gallery' => 0,
          'sixflags_scholarships_app' => 0,
          'staff_blog' => 0,
          'staples_2011_signup' => 0,
          'staples_members' => 0,
          'staples_reason' => 0,
          'tackle_hunger' => 0,
          'tfj_contest_signup' => 0,
          'tips_and_tools' => 0,
          'troop_letter' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The club or clubs responsible for this project (if any). This setting will determine if the project is listed on each club\'s page.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '17',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_clubs',
      'label' => 'Did you do this project with a DoSomething Club?',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_goal'
  $fields['webform_submission_entity-project_report-field_project_goal'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_goal',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'What is the GOAL of your project? <i>Ex. Reduce litter in my neighborhood by 50%</i>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 27,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_goal',
      'label' => 'Goal',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_impact'
  $fields['webform_submission_entity-project_report-field_project_impact'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_impact',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Ex. <i>Picked up 8 bags of trash.</i>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 26,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_impact',
      'label' => 'Measurable impact',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_inspiration'
  $fields['webform_submission_entity-project_report-field_project_inspiration'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_inspiration',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'no',
          1 => 'yes',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
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
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_inspiration',
      'label' => 'Did DoSomething.org’s content or programs inspire you to start, or help you to grow your project?',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_related_campaign'
  $fields['webform_submission_entity-project_report-field_project_related_campaign'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_related_campaign',
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
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '22',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_related_campaign',
      'label' => 'Related Campaign or Program',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '26',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_report_zip'
  $fields['webform_submission_entity-project_report-field_project_report_zip'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_report_zip',
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
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter the zip codes in which your project made an impact.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_report_zip',
      'label' => 'Locations',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_start_date'
  $fields['webform_submission_entity-project_report-field_project_start_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_start_date',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'profile2_private' => FALSE,
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 28,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_start_date',
      'label' => 'Start date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_title'
  $fields['webform_submission_entity-project_report-field_project_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_title',
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
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '19',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_title',
      'label' => 'Title',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_type'
  $fields['webform_submission_entity-project_report-field_project_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          2 => 'project idea',
          3 => 'ongoing project',
          4 => 'completed project',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'please select the most appropriate one, thanks!',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_type',
      'label' => 'Project Type',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_project_webform_age'
  $fields['webform_submission_entity-project_report-field_project_webform_age'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_webform_age',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
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
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '23',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_webform_age',
      'label' => 'Age',
      'required' => 0,
      'settings' => array(
        'max' => '150',
        'min' => '0',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'html5_tools',
        'settings' => array(),
        'type' => 'numberfield',
        'weight' => '27',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_update_people_involved'
  $fields['webform_submission_entity-project_report-field_update_people_involved'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_update_people_involved',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'append_position' => NULL,
        'max' => '',
        'min' => '',
        'prefix' => '',
        'profile2_private' => FALSE,
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project_update',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '(i.e. 5 staff and 25 volunteers for a total of 30, or 35 club members.)
Use numbers only (no text).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_update_people_involved',
      'label' => 'How many people are directly involved in your project?',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_webform_videos'
  $fields['webform_submission_entity-project_report-field_webform_videos'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_videos',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'mediafield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'media',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_small',
          ),
          'type' => 'media',
          'weight' => '25',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_videos',
      'label' => 'Video',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp3 mov m4v mp4 mpeg avi ogg wmv ico',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 0,
            'vimeo' => 'vimeo',
            'youtube' => 'youtube',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 0,
            'video' => 'video',
          ),
          'browser_plugins' => array(
            'library' => 0,
            'media_default--media_browser_1' => 0,
            'media_internet' => 'media_internet',
            'upload' => 0,
          ),
          'file_extensions' => 'mp3 mov m4v mp4 mpeg avi ogg wmv',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-taxonomy_vocabulary_5'
  $fields['webform_submission_entity-project_report-taxonomy_vocabulary_5'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_5',
      'field_permissions' => array(
        'type' => '2',
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
            'parent' => 0,
          ),
        ),
        'profile2_private' => FALSE,
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select the cause and issue that are closest to your project. Other users will be looking for projects in these categories and by tagging your project with these other people will be able to see what you are doing!',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'taxonomy_vocabulary_5',
      'label' => 'Issues',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(i.e. 5 staff and 25 volunteers for a total of 30, or 35 club members.)
Use numbers only (no text).');
  t('(i.e. Number of people who donated canned goods to your canned food drive, etc.)');
  t('(i.e. Number of people you provided food for through your collection, etc.) Use digits, for example: "20", "100"');
  t('Age');
  t('Body (anonymous user)');
  t('Body (logged in user)');
  t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.<br />
The content from this field will only be shown to anonymous users.');
  t('Describe the steps you will take/took to create your project or organization.');
  t('Describe your project/organization and how it addresses the problem(s) above.');
  t('Did DoSomething.org’s content or programs inspire you to start, or help you to grow your project?');
  t('Did you do this project with a DoSomething Club?');
  t('DoSomething Award Winner');
  t('Enter the zip codes in which your project made an impact.');
  t('Ex. <i>Picked up 8 bags of trash.</i>');
  t('Facebook like count');
  t('Goal');
  t('How Can Others Help? ');
  t('How many people are directly involved in your project?');
  t('How many people has your project helped?');
  t('How many people have you inspired to take action?');
  t('Image');
  t('Issues');
  t('Locations');
  t('Measurable impact');
  t('OPTIONAL - Link DoSomething action guides or fact pages to this project');
  t('Project Photo');
  t('Project Type');
  t('Related Campaign or Program');
  t('Select the cause and issue that are closest to your project. Other users will be looking for projects in these categories and by tagging your project with these other people will be able to see what you are doing!');
  t('Start date');
  t('Tell us about the community you are helping and the problem(s) being solved.');
  t('The club or clubs responsible for this project (if any). This setting will determine if the project is listed on each club\'s page.');
  t('The content from this field will only be shown to logged in users.');
  t('Title');
  t('Total hours volunteered (to date)');
  t('Video');
  t('Web site link');
  t('What is the GOAL of your project? <i>Ex. Reduce litter in my neighborhood by 50%</i>');
  t('What\'s the problem you are trying to solve?');
  t('What\'s your plan of action?');
  t('Why is it important to you?');
  t('how many hours have you spent on this project');
  t('please select the most appropriate one, thanks!');

  return $fields;
}
