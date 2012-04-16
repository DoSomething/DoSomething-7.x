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

  // Exported field: 'node-project_update-body'
  $fields['node-project_update-body'] = array(
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
      'bundle' => 'project_update',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'trim_length' => 600,
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'What progress have you made since your original post?',
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

  // Exported field: 'node-project_update-field_embedded_video'
  $fields['node-project_update-field_embedded_video'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_embedded_video',
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
      'type_name' => 'sixflags_scholarships_app',
    ),
    'field_instance' => array(
      'bundle' => 'project_update',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '-1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '-1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_embedded_video',
      'label' => 'Video (optional)',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp3 mov m4v mp4 mpeg avi ogg wmv ico',
        'user_register_form' => FALSE,
      ),
      'weight' => '-1',
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
            'youtube' => 'youtube',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 0,
            'video' => 'video',
          ),
          'browser_plugins' => array(),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-project_update-field_project'
  $fields['node-project_update-field_project'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project',
      'field_permissions' => array(
        'type' => '0',
      ),
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
          '301_redirects' => 0,
          'action_guide' => 0,
          'api_key' => 0,
          'awards_archive' => 0,
          'bc_bio_form' => 0,
          'blog' => 0,
          'campaign' => 0,
          'campaign_art_2011' => 0,
          'campaign_bully_2011' => 0,
          'campaign_cancer_2011' => 0,
          'campaign_contact_form' => 0,
          'campaign_ew_2011' => 0,
          'campaign_macys_2011' => 0,
          'campaign_report_back' => 0,
          'campaign_sign_up' => 0,
          'campaign_sports_2011' => 0,
          'cancer_2011_signup' => 0,
          'cause' => 0,
          'cause_video' => 0,
          'club' => 0,
          'club_event' => 0,
          'club_first_meeting_cash' => 0,
          'decade_2011_signup' => 0,
          'ds_award_judging' => 0,
          'dsaward_app' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'editorial_content_' => 0,
          'editorial_project' => 0,
          'ewaste_signup_2011' => 0,
          'final_grant_update' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'grant_judge' => 0,
          'grants_database' => 0,
          'help_ticket' => 0,
          'huffpo' => 0,
          'ididthis' => 0,
          'issue' => 0,
          'page' => 0,
          'poll' => 0,
          'press' => 0,
          'project_report' => 0,
          'project_update' => 0,
          'scholarship' => 0,
          'scholarship_application' => 0,
          'scholarship_update' => 0,
          'school' => 0,
          'scroller' => 0,
          'staples_members' => 0,
          'tips_and_tools' => 0,
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
      'type_name' => 'sixflags_scholarships_app',
    ),
    'field_instance' => array(
      'bundle' => 'project_update',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This an auto complete field.  Start typing in the name of your project. If you haven\'t yet posted a project <a href="/node/add/project"> click here </a>.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '-4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_project',
      'label' => 'Project',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '6',
      ),
      'widget_type' => 'nodereference_select',
    ),
  );

  // Exported field: 'node-project_update-field_project_photo'
  $fields['node-project_update-field_project_photo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_photo',
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
      'type_name' => 'save_our_music',
    ),
    'field_instance' => array(
      'bundle' => 'project_update',
      'default_value' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'Full' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
        'Teaser' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
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
        'full' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'above',
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
      'field_name' => 'field_project_photo',
      'label' => 'Project Photo',
      'required' => '0',
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => 'project_photos',
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
          'image_path' => 'project_photos',
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
          'teaser_preset' => NULL,
          'use_default_image' => 0,
        ),
        'type' => 'image_image',
        'weight' => '3',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-project_update-field_update_people_impacted'
  $fields['node-project_update-field_update_people_impacted'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_update_people_impacted',
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
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'project_update',
    ),
    'field_instance' => array(
      'bundle' => 'project_update',
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
          'weight' => '0',
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
          'weight' => '0',
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
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_update_people_impacted',
      'label' => 'How many additional [people helped] since your original post?',
      'required' => 1,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 0,
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-project_update-field_update_people_involved'
  $fields['node-project_update-field_update_people_involved'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_update_people_involved',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'bundle' => 'project_update',
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
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '0',
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
          'weight' => '0',
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
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_update_people_involved',
      'label' => 'How many additional people have gotten involved since your original post?',
      'required' => 1,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '0',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-project_update-field_webform_project_submission'
  $fields['node-project_update-field_webform_project_submission'] = array(
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
      'bundle' => 'project_update',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If you haven\'t yet posted a project <a href="/node/718313"> click here </a>.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => 1,
          ),
          'type' => 'entityreference_label',
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
      'field_name' => 'field_webform_project_submission',
      'label' => 'Project',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-project_update-upload'
  $fields['node-project_update-upload'] = array(
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
      'bundle' => 'project_update',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => '5',
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
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-grants_scholarships-field_grant_scholarship'
  $fields['taxonomy_term-grants_scholarships-field_grant_scholarship'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_grant_scholarship',
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
          'Grant' => 'Grant',
          'Scholarship' => 'Scholarship',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'grants_scholarships',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_grant_scholarship',
      'label' => 'Grant/Scholarship',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '31',
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
          'weight' => '0',
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
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_action_guide_reference'
  $fields['webform_submission_entity-project_report-field_action_guide_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_action_guide_reference',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'field_phone_number_1:value',
            'property' => 'nid',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'action_guide' => 'action_guide',
          ),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
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
          'weight' => '17',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_action_guide_reference',
      'label' => 'Related Action Guide',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '19',
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
      'description' => 'How? e.g. Get 10 friends on a Saturday to pick up trash',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
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
      'description' => 'Why? e.g. There\'s trash all over my neighborhood',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
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

  // Exported field: 'webform_submission_entity-project_report-field_geocode_data'
  $fields['webform_submission_entity-project_report-field_geocode_data'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_geocode_data',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'geofield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_geocode_data',
      'label' => 'Geocode Data',
      'required' => 0,
      'settings' => array(
        'local_solr' => array(
          'enabled' => FALSE,
          'lat_field' => 'lat',
          'lng_field' => 'lng',
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'geocoder',
        'settings' => array(
          'geocoder_field' => array(
            'field_webform_address' => 'field_webform_address',
          ),
          'geocoder_handler' => 'google',
        ),
        'type' => 'geocoder',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_grant_winner'
  $fields['webform_submission_entity-project_report-field_grant_winner'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_grant_winner',
      'field_permissions' => array(
        'type' => '2',
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
            'vocabulary' => 'grants_scholarships',
            'parent' => '0',
          ),
        ),
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '18',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_grant_winner',
      'label' => 'Grant/Scholarship',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_impact_amount'
  $fields['webform_submission_entity-project_report-field_impact_amount'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_impact_amount',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'default_value' => array(
        0 => array(
          'value' => '1',
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
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 22,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_impact_amount',
      'label' => 'Amount',
      'required' => 1,
      'settings' => array(
        'max' => '',
        'min' => '1',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_impact_type'
  $fields['webform_submission_entity-project_report-field_impact_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_impact_type',
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
          1 => 'people helped',
          2 => 'animals helped',
          3 => 'items collected',
          4 => 'amount raised',
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
          'weight' => 23,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_impact_type',
      'label' => 'Type',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '3',
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
        'weight' => '10',
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
          'weight' => '5',
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
        'weight' => '14',
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
          'weight' => '9',
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
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_participants'
  $fields['webform_submission_entity-project_report-field_participants'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_participants',
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
      'description' => 'List the email address or mobile number of anyone who donated time or goods to your project.',
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
      'field_name' => 'field_participants',
      'label' => 'Who else participated in your project/drive?',
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
        'weight' => '16',
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
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '8',
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
      'field_permissions' => array(
        'type' => '0',
      ),
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
          'action_guide' => 0,
          'api_key' => 0,
          'awards_archive' => 0,
          'bc_bio_form' => 0,
          'blog' => 0,
          'campaign' => 0,
          'campaign_art_2011' => 0,
          'campaign_bully_2011' => 0,
          'campaign_cancer_2011' => 0,
          'campaign_contact_form' => 0,
          'campaign_content_page' => 0,
          'campaign_ew_2011' => 0,
          'campaign_macys_2011' => 0,
          'campaign_report_back' => 0,
          'campaign_sign_up' => 0,
          'campaign_sports_2011' => 0,
          'cancer_2011_signup' => 0,
          'cause_video' => 0,
          'club' => 'club',
          'club_event' => 0,
          'decade_2011_signup' => 0,
          'ds_award_judging' => 0,
          'dsaward_app' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'editorial_content_' => 0,
          'ewaste_signup_2011' => 0,
          'final_grant_update' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'grant_judge' => 0,
          'help_ticket' => 0,
          'member_opportunity' => 0,
          'page' => 0,
          'poll' => 0,
          'press' => 0,
          'project_report' => 0,
          'project_update' => 0,
          'scholarship' => 0,
          'scholarship_application' => 0,
          'school' => 0,
          'scroller' => 0,
          'share_of_day' => 0,
          'sponsor' => 0,
          'tips_and_tools' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'references_1',
          'view_name' => 'user_groups_reference_options',
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
          'weight' => '10',
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
        'module' => 'nodereference_url',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'edit_fallback' => 0,
          'fallback' => 'select',
          'node_link' => array(
            'destination' => 'default',
            'full' => 0,
            'hover_title' => '',
            'teaser' => 0,
            'title' => '',
          ),
        ),
        'type' => 'nodereference_url',
        'weight' => '15',
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
          'weight' => '14',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_project_goal',
      'label' => 'Goal',
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
        'weight' => '5',
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
          'weight' => '13',
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
        'weight' => '4',
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
          ),
          'type' => 'date_default',
          'weight' => '15',
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
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_select',
        'weight' => '7',
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
          'weight' => '0',
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
      'default_value' => array(
        0 => array(
          'value' => '3',
        ),
      ),
      'deleted' => '0',
      'description' => 'please select the most appropriate one, thanks!',
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
      'field_name' => 'field_project_type',
      'label' => 'Status',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '6',
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
      'field_permissions' => array(
        'type' => '0',
      ),
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
          'weight' => '6',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_update_people_involved',
      'label' => 'Number of People Doing It',
      'required' => 1,
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
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-field_webform_address'
  $fields['webform_submission_entity-project_report-field_webform_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_address',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'addressfield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => array(
        0 => array(
          'element_key' => 'webform_submission_entity|project_report|field_webform_address|und|0',
          'thoroughfare' => '',
          'premise' => '',
          'locality' => '',
          'administrative_area' => '',
          'postal_code' => '',
          'country' => 'US',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'addressfield',
          'settings' => array(
            'format_handlers' => array(
              0 => 'address',
            ),
            'use_widget_handlers' => 1,
          ),
          'type' => 'addressfield_default',
          'weight' => '16',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_address',
      'label' => 'Address',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(),
          'format_handlers' => array(
            'address' => 'address',
            'name-full' => 0,
            'name-oneline' => 0,
            'organisation' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => '17',
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
          'weight' => '12',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-project_report-group_group'
  $fields['webform_submission_entity-project_report-group_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'group_group',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'no_ui' => TRUE,
      'settings' => array(
        'allowed_values' => array(
          0 => 'Not a group type',
          1 => 'Group type',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'project_report',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Determine if this is an OG group.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og_ui',
          'settings' => array(),
          'type' => 'og_group_subscribe',
          'weight' => '19',
        ),
      ),
      'display_label' => 1,
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'group_group',
      'label' => 'Group',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'custom settings' => FALSE,
          'label' => 'Full',
          'type' => 'og_group_subscribe',
        ),
        'teaser' => array(
          'custom settings' => FALSE,
          'label' => 'Teaser',
          'type' => 'og_group_subscribe',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => '23',
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
          'weight' => '4',
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
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(i.e. 5 staff and 25 volunteers for a total of 30, or 35 club members.)
Use numbers only (no text).');
  t('(i.e. Number of people you provided food for through your collection, etc.) Use digits, for example: "20", "100"');
  t('Address');
  t('Body (anonymous user)');
  t('Body (logged in user)');
  t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.<br />
The content from this field will only be shown to anonymous users.');
  t('Determine if this is an OG group.');
  t('Did you do this project with a DoSomething Club?');
  t('Ex. <i>Picked up 8 bags of trash.</i>');
  t('File attachments');
  t('Geocode Data');
  t('Goal');
  t('Grant/Scholarship');
  t('Group');
  t('How Can Others Help? ');
  t('How many additional [people helped] since your original post?');
  t('How many additional people have gotten involved since your original post?');
  t('How many people are directly involved in your project?');
  t('How many people has your project helped?');
  t('How? e.g. Get 10 friends on a Saturday to pick up trash');
  t('If you haven\'t yet posted a project <a href="/node/718313"> click here </a>.');
  t('Image');
  t('Issues');
  t('List the email address or mobile number of anyone who donated time or goods to your project.');
  t('Measurable impact');
  t('Number of People Doing It');
  t('Please don\'t use BMP files.
Upload photos that are relevant to your project here.  The first photo will be used on the site when linking to your project, so make sure it\'s good! Maximum photo dimensions are 580px by 580px.  ');
  t('Project');
  t('Project Photo');
  t('Related Action Guide');
  t('Select the cause and issue that are closest to your project. Other users will be looking for projects in these categories and by tagging your project with these other people will be able to see what you are doing!');
  t('Start date');
  t('Status');
  t('The club or clubs responsible for this project (if any). This setting will determine if the project is listed on each club\'s page.');
  t('The content from this field will only be shown to logged in users.');
  t('This an auto complete field.  Start typing in the name of your project. If you haven\'t yet posted a project <a href="/node/add/project"> click here </a>.');
  t('Title');
  t('Type');
  t('Update');
  t('Updated number of new people involved in the project');
  t('Updated number of new people/animals helped');
  t('Video');
  t('Video (optional)');
  t('Web site link');
  t('What is the GOAL of your project? <i>Ex. Reduce litter in my neighborhood by 50%</i>');
  t('What progress have you made since your original post?');
  t('What\'s the problem you are trying to solve?');
  t('What\'s your plan of action?');
  t('Who else participated in your project/drive?');
  t('Why? e.g. There\'s trash all over my neighborhood');
  t('please select the most appropriate one, thanks!');

  return $fields;
}
