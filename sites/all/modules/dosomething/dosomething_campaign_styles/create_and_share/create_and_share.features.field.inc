<?php
/**
 * @file
 * create_and_share.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function create_and_share_field_default_fields() {
  $fields = array();

  // Exported field: 'node-create_and_share_campaign-field_cas_allow_anonymous_voting'.
  $fields['node-create_and_share_campaign-field_cas_allow_anonymous_voting'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_allow_anonymous_voting',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Can users "vote", regardless of their logged in status?',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
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
      'field_name' => 'field_cas_allow_anonymous_voting',
      'label' => 'Allow Anonymous Voting',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-create_and_share_campaign-field_cas_allow_lazy_loading'.
  $fields['node-create_and_share_campaign-field_cas_allow_lazy_loading'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_allow_lazy_loading',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Allow lazy loading of all images in the gallery?',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cas_allow_lazy_loading',
      'label' => 'Allow Lazy Loading',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-create_and_share_campaign-field_cas_allow_notifications'.
  $fields['node-create_and_share_campaign-field_cas_allow_notifications'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_allow_notifications',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Allow notifications?',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cas_allow_notifications',
      'label' => 'Allow Notifications',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-create_and_share_campaign-field_cas_image_font'.
  $fields['node-create_and_share_campaign-field_cas_image_font'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_image_font',
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
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'private',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'deleted' => '0',
      'description' => 'If applicable, the font to use to write text to the image.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 4,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cas_image_font',
      'label' => 'Image Font',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'create_and_share/fonts',
        'file_extensions' => 'ttf eot',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'insert' => 0,
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
            'image_club_gallery_photos_120x120' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_crazy_facebook_picture' => 0,
            'image_crazy_image_dimensions' => 0,
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
            'image_robocalls_gallery_thumb' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
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
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-create_and_share_campaign-field_cas_notification_pages'.
  $fields['node-create_and_share_campaign-field_cas_notification_pages'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_notification_pages',
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
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The page(s) that notifications should be allowed on.  One per line.  Use regular expression syntax to denote abstracted paths.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cas_notification_pages',
      'label' => 'Notification Pages',
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
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_flagged'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_flagged'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_flagged',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => 0,
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
          'weight' => 7,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_flagged',
      'label' => 'Flagged',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '38',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_image'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_image',
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
      'bundle' => 'create_and_share_campaign',
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
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_image',
      'label' => 'Image',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'create_and_share',
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
            'image_club_gallery_photos_120x120' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_crazy_facebook_picture' => 0,
            'image_crazy_image_dimensions' => 0,
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
            'image_robocalls_gallery_thumb' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
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
          'preview_image_style' => 'crazy_image_dimensions',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_thumbs_down_count'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_thumbs_down_count'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_thumbs_down_count',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => '0',
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
          'weight' => 5,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_thumbs_down_count',
      'label' => 'Thumbs Down Count',
      'required' => 0,
      'settings' => array(
        'max' => '',
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
        'weight' => '36',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_thumbs_up_count'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_thumbs_up_count'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_thumbs_up_count',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => '0',
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
          'weight' => 4,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_thumbs_up_count',
      'label' => 'Thumbs Up Count',
      'required' => 0,
      'settings' => array(
        'max' => '',
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
        'weight' => '35',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_total_count'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_total_count'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_total_count',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => '0',
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
          'weight' => 3,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_total_count',
      'label' => 'Total Count',
      'required' => 0,
      'settings' => array(
        'max' => '',
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
        'weight' => '34',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-create_and_share_campaign-field_cas_weight'.
  $fields['webform_submission_entity-create_and_share_campaign-field_cas_weight'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cas_weight',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_float',
    ),
    'field_instance' => array(
      'bundle' => 'create_and_share_campaign',
      'default_value' => array(
        0 => array(
          'value' => '0.0',
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
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_cas_weight',
      'label' => 'Weight',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '0.0',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '37',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Allow Anonymous Voting');
  t('Allow Lazy Loading');
  t('Allow Notifications');
  t('Allow lazy loading of all images in the gallery?');
  t('Allow notifications?');
  t('Can users "vote", regardless of their logged in status?');
  t('Flagged');
  t('If applicable, the font to use to write text to the image.');
  t('Image');
  t('Image Font');
  t('Notification Pages');
  t('The page(s) that notifications should be allowed on.  One per line.  Use regular expression syntax to denote abstracted paths.');
  t('Thumbs Down Count');
  t('Thumbs Up Count');
  t('Total Count');
  t('Weight');

  return $fields;
}
