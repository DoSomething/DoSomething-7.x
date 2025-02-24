<?php
/**
 * @file
 * dosomething_campaign_report_back.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_campaign_report_back_field_default_fields() {
  $fields = array();

  // Exported field: 'node-campaign_report_back-field_body_anonymous'.
  $fields['node-campaign_report_back-field_body_anonymous'] = array(
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
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

  // Exported field: 'node-campaign_report_back-field_body_logged_in'.
  $fields['node-campaign_report_back-field_body_logged_in'] = array(
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The content from this field will only be shown to logged in users.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
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

  // Exported field: 'node-campaign_report_back-field_mandrill_key'.
  $fields['node-campaign_report_back-field_mandrill_key'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mandrill_key',
      'field_permissions' => array(
        'type' => '1',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => array(
        0 => array(
          'value' => 'dsplain',
        ),
      ),
      'deleted' => '0',
      'description' => 'In order to trigger Mandrill based transactional email messages when a submission is made to this form a "key" needs to be provided based on settings in the Mail System and Mandrill Template module settings.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mandrill_key',
      'label' => 'Mandrill Key',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-campaign_report_back-field_report_back_magic_fields'.
  $fields['node-campaign_report_back-field_report_back_magic_fields'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_report_back_magic_fields',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'field_webform_email' => 'Email',
          'field_webform_mobile' => 'Mobile Phone Number',
          'field_webform_school' => 'School',
          'field_webform_school_reference' => 'School Reference',
          'field_webform_school_zip' => 'School Zip Code',
          'field_webform_pictures' => 'Pictures',
          'field_webform_videos' => 'Video',
          'taxonomy_vocabulary_5' => 'Issues',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => array(
        0 => array(
          'value' => 'field_webform_email',
        ),
        1 => array(
          'value' => 'field_webform_mobile',
        ),
        2 => array(
          'value' => 'field_webform_school',
        ),
        3 => array(
          'value' => 'field_webform_school_reference',
        ),
        4 => array(
          'value' => 'field_webform_school_zip',
        ),
        5 => array(
          'value' => 'field_webform_pictures',
        ),
        6 => array(
          'value' => 'field_webform_videos',
        ),
        7 => array(
          'value' => 'taxonomy_vocabulary_5',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_report_back_magic_fields',
      'label' => 'Enabled Fields',
      'required' => 0,
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

  // Exported field: 'node-campaign_report_back-group_audience'.
  $fields['node-campaign_report_back-group_audience'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
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
      'locked' => '0',
      'module' => 'og',
      'no_ui' => TRUE,
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'group',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'default_value_function' => 'og_field_audience_default_value',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
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
          'size' => '60',
        ),
        'type' => 'group_audience_autocomplete',
        'weight' => '7',
      ),
      'widget_type' => 'group_audience',
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_geocode_data'.
  $fields['webform_submission_entity-campaign_report_back-field_geocode_data'] = array(
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
      'locked' => '0',
      'module' => 'geofield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
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
            'field_webform_school_zip' => 'field_webform_school_zip',
          ),
          'geocoder_handler' => 'google',
        ),
        'type' => 'geocoder',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_webform_pictures'.
  $fields['webform_submission_entity-campaign_report_back-field_webform_pictures'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_pictures',
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
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
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
          'weight' => '4',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_pictures',
      'label' => 'Pictures',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
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
          'insert_absolute' => FALSE,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_490x200' => 0,
            'image_action_results_thumbnail' => 0,
            'image_blog_landscape' => 0,
            'image_blog_large_image' => 0,
            'image_blog_large_thumbnail' => 0,
            'image_blog_portrait' => 0,
            'image_blog_square' => 0,
            'image_boot_camp_bio' => 0,
            'image_campaign_blog_thumbnail' => 0,
            'image_campaign_microsite_logo' => 0,
            'image_campaigns_image' => 0,
            'image_campaigns_logo' => 0,
            'image_carousel_center' => 0,
            'image_carousel_inner' => 0,
            'image_carousel_outer' => 0,
            'image_cause_main' => 0,
            'image_cause_vertical' => 0,
            'image_content_main' => 0,
            'image_explore_action_guides' => 0,
            'image_fb_post_image' => 0,
            'image_front_slider' => 0,
            'image_gallery_thumbnail' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
            'image_p4p_fake_button' => 0,
            'image_petdetail_regular' => 0,
            'image_petdetail_retina' => 0,
            'image_project_gallery_thumb' => 0,
            'image_project_related_thumb' => 0,
            'image_related-posts' => 0,
            'image_robocall_celeb_photo' => 0,
            'image_robocall_celeb_thumbnail_205x115' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
            'image_search_results_thumbnail' => 0,
            'image_social_scholarship_images_petition_735x150' => 0,
            'image_social_scholarship_stat_image_190x190' => 0,
            'image_sponsor_logo' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'image_thumbnail_regular' => 0,
            'image_thumbnail_retina' => 0,
            'image_tips_tools_node' => 0,
            'image_upcoming_somethings_thumb' => 0,
            'image_whats_happening_now_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_webform_school'.
  $fields['webform_submission_entity-campaign_report_back-field_webform_school'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_school',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_school',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'html5_tools',
        'settings' => array(),
        'type' => 'telwidget',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_webform_school_reference'.
  $fields['webform_submission_entity-campaign_report_back-field_webform_school_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_school_reference',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'ds_school',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'none',
            'property' => 'sid',
            'type' => 'none',
          ),
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'ds_school',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
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
          'weight' => '5',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_school_reference',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'dosomething_school',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'dosomething_school_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_webform_school_zip'.
  $fields['webform_submission_entity-campaign_report_back-field_webform_school_zip'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_school_zip',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
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
      'field_name' => 'field_webform_school_zip',
      'label' => 'School Zip Code',
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
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-field_webform_videos'.
  $fields['webform_submission_entity-campaign_report_back-field_webform_videos'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_videos',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'mediafield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'media',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'default',
          ),
          'type' => 'media',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_videos',
      'label' => 'Videos',
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
          'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp3 mov m4v mp4 mpeg avi ogg wmv ico',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-group_audience'.
  $fields['webform_submission_entity-campaign_report_back-group_audience'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
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
      'locked' => '0',
      'module' => 'og',
      'no_ui' => TRUE,
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'group',
    ),
    'field_instance' => array(
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'default_value_function' => 'og_field_audience_default_value',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og',
          'settings' => array(),
          'type' => 'og_list_default',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
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
        'weight' => '10',
      ),
      'widget_type' => 'group_audience',
    ),
  );

  // Exported field: 'webform_submission_entity-campaign_report_back-taxonomy_vocabulary_5'.
  $fields['webform_submission_entity-campaign_report_back-taxonomy_vocabulary_5'] = array(
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
      'locked' => '0',
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
      'bundle' => 'campaign_report_back',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'taxonomy_vocabulary_5',
      'label' => 'Issues',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '8',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body (anonymous user)');
  t('Body (logged in user)');
  t('Campaign');
  t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.<br />
The content from this field will only be shown to anonymous users.');
  t('Enabled Fields');
  t('Geocode Data');
  t('In order to trigger Mandrill based transactional email messages when a submission is made to this form a "key" needs to be provided based on settings in the Mail System and Mandrill Template module settings.');
  t('Issues');
  t('Mandrill Key');
  t('Pictures');
  t('School');
  t('School Zip Code');
  t('The content from this field will only be shown to logged in users.');
  t('Videos');

  return $fields;
}
