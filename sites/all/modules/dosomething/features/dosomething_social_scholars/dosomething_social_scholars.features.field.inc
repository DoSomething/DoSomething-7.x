<?php
/**
 * @file
 * dosomething_social_scholars.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_social_scholars_field_default_fields() {
  $fields = array();

  // Exported field: 'node-social_scholarship-body'.
  $fields['node-social_scholarship-body'] = array(
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_alphas_campaign'.
  $fields['node-social_scholarship-field_alphas_campaign'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_alphas_campaign',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Optional.  A campaign number on Mobile Commons for Alphas.',
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
          'weight' => 7,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_alphas_campaign',
      'label' => 'Alphas Campaign',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_betas_campaign'.
  $fields['node-social_scholarship-field_betas_campaign'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_betas_campaign',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Optional.  A mobile commons ID for betas.',
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
          'weight' => 8,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_betas_campaign',
      'label' => 'Betas Campaign',
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
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_color_scheme'.
  $fields['node-social_scholarship-field_color_scheme'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_color_scheme',
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
          'green' => 'Green',
          'red' => 'Red',
          'black' => 'Black',
          'gray' => 'Gray',
          'white' => 'White',
          'yellow' => 'Yellow',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 15,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_color_scheme',
      'label' => 'Color Scheme',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_email_mailchimp_bucket'.
  $fields['node-social_scholarship-field_email_mailchimp_bucket'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email_mailchimp_bucket',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If this is a campaign share a stat, the user will be presented with a shortform after they complete the actual share a stat.  Put the mailchimp bucket their email should land in after they fill it out.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 18,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email_mailchimp_bucket',
      'label' => 'Email mailchimp bucket',
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
        'weight' => '21',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_facebook_share_language'.
  $fields['node-social_scholarship-field_facebook_share_language'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_facebook_share_language',
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
        'max_length' => '500',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Text to accompany the Facebook share links.  These will correspond, in order, with the order of the images that were uploaded above (e.g. the first description will accompany the first image, the second with the second image, etc...)',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_facebook_share_language',
      'label' => 'Facebook "Share" Language',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_fb_language'.
  $fields['node-social_scholarship-field_fb_language'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_fb_language',
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
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The Language for the Facebook "Recommend" button',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
      'field_name' => 'field_fb_language',
      'label' => 'Facebook "Recommend" Language',
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_is_a_campaign_share_a_stat'.
  $fields['node-social_scholarship-field_is_a_campaign_share_a_stat'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_is_a_campaign_share_a_stat',
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
      'bundle' => 'social_scholarship',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Check this box if this share a stat is linked to a campaign.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 16,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_is_a_campaign_share_a_stat',
      'label' => 'Is a campaign Share a Stat?',
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
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_linked_campaign'.
  $fields['node-social_scholarship-field_linked_campaign'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_linked_campaign',
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
      'locked' => '0',
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
          'campaign_blog_post' => 0,
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
          'club' => 0,
          'club_event' => 0,
          'crazy_shit' => 0,
          'decade_2011_signup' => 0,
          'drive_form' => 0,
          'ds_award_judging' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'editorial_content_' => 0,
          'ewaste_signup_2011' => 0,
          'fb_app_data_gathering_form' => 0,
          'final_grant_update' => 0,
          'grant_alumni' => 0,
          'grant_application' => 0,
          'grant_judge' => 0,
          'help_ticket' => 0,
          'member_opportunity' => 0,
          'mobile_referral_form' => 0,
          'page' => 0,
          'petition' => 0,
          'poll' => 0,
          'press' => 0,
          'program_short_form' => 0,
          'project_report' => 0,
          'project_update' => 0,
          'quiz' => 0,
          'robo_calls' => 0,
          'scholarship' => 0,
          'scholarship_application' => 0,
          'scholarship_application_with_rec' => 0,
          'scholarship_recommendation' => 0,
          'scholarship_recommendation_reque' => 0,
          'school' => 0,
          'scroller' => 0,
          'share_of_day' => 0,
          'shelter' => 0,
          'social_scholarship' => 0,
          'sponsor' => 0,
          'team_challenge' => 0,
          'tips_and_tools' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'references_1',
          'view_name' => 'campaign_list_for_clubs',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 14,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_linked_campaign',
      'label' => 'Linked campaign',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_logo_image'.
  $fields['node-social_scholarship-field_logo_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_logo_image',
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
      'bundle' => 'social_scholarship',
      'deleted' => '0',
      'description' => 'An image that will appear in the header, should you want it to.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 17,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_logo_image',
      'label' => 'Logo Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'share-a-stat-headers',
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
          'preview_image_style' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_logo_text'.
  $fields['node-social_scholarship-field_logo_text'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_logo_text',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The text that will appear in front of the logo image, if applicable.  If left blank, this share a stat will use the title instead.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 21,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_logo_text',
      'label' => 'Logo text',
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
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_official_rules_document'.
  $fields['node-social_scholarship-field_official_rules_document'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_official_rules_document',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_official_rules_document',
      'label' => 'Official Rules Document',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'social_scholarships/official_rules',
        'file_extensions' => 'txt doc pdf',
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
            'image_campaign_report_back_style' => 0,
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
            'image_explore_action_guides' => 0,
            'image_front_slider' => 0,
            'image_gallery_thumbnail' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
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
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_petition_image'.
  $fields['node-social_scholarship-field_petition_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_petition_image',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
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
      'field_name' => 'field_petition_image',
      'label' => 'Petition Image',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'social_scholarships',
        'file_extensions' => 'jpg jpeg png gif',
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
            'image_campaign_blog_thumbnail' => 0,
            'image_campaign_microsite_logo' => 0,
            'image_campaign_report_back_style' => 0,
            'image_campaigns_image' => 0,
            'image_campaigns_logo' => 0,
            'image_cause_main' => 0,
            'image_cause_vertical' => 0,
            'image_club_gallery_photos_120x120' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_explore_action_guides' => 0,
            'image_front_slider' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_petition_link'.
  $fields['node-social_scholarship-field_petition_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_petition_link',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The link to the petition (or other) that will be below the --- OR --- line on the images page.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
      'field_name' => 'field_petition_link',
      'label' => 'Petition Link',
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

  // Exported field: 'node-social_scholarship-field_redirect_message'.
  $fields['node-social_scholarship-field_redirect_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_redirect_message',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The message that appears after a use is redirected to the "redirect to" URL.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 10,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_redirect_message',
      'label' => 'Redirect message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
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

  // Exported field: 'node-social_scholarship-field_redirect_to_path'.
  $fields['node-social_scholarship-field_redirect_to_path'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_redirect_to_path',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Either: The relative path to the page NOT including the first / (e.g. blog/7-facts-about-kittens)
<br />OR: The full url to a webpage (e.g. http://www.google.com)',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_redirect_to_path',
      'label' => 'Redirect to path',
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
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_shortform_image'.
  $fields['node-social_scholarship-field_shortform_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_shortform_image',
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
      'bundle' => 'social_scholarship',
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
          'weight' => 19,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_shortform_image',
      'label' => 'Shortform replacement image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'sas-images',
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
          'preview_image_style' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_social_scholars_images'.
  $fields['node-social_scholarship-field_social_scholars_images'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_social_scholars_images',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'social_scholarship',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
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
      'field_name' => 'field_social_scholars_images',
      'label' => 'Images',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'gif jpg jpeg png',
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
            'image_campaign_blog_thumbnail' => 0,
            'image_campaign_microsite_logo' => 0,
            'image_campaign_report_back_style' => 0,
            'image_campaigns_image' => 0,
            'image_campaigns_logo' => 0,
            'image_cause_main' => 0,
            'image_cause_vertical' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_explore_action_guides' => 0,
            'image_front_slider' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
            'image_project_gallery_thumb' => 0,
            'image_project_related_thumb' => 0,
            'image_related-posts' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
            'image_search_results_thumbnail' => 0,
            'image_sponsor_logo' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'image_tips_tools_node' => 0,
            'image_upcoming_somethings_thumb' => 0,
            'image_whats_happening_now_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_sponsor_image'.
  $fields['node-social_scholarship-field_sponsor_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sponsor_image',
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
      'bundle' => 'social_scholarship',
      'deleted' => '0',
      'description' => '(Optional) sponsor image that will appear at the bottom of all pages for this Share a Stat.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 20,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_sponsor_image',
      'label' => 'Sponsor image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'share-a-stat/sponsors',
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
          'preview_image_style' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'node-social_scholarship-field_tip_to_show_on_form'.
  $fields['node-social_scholarship-field_tip_to_show_on_form'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tip_to_show_on_form',
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
      'bundle' => 'social_scholarship',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This tip will show up on the top of the form.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 11,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tip_to_show_on_form',
      'label' => 'Tip to show on form',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-social_scholarship-field_share_your_own_image'.
  $fields['webform_submission_entity-social_scholarship-field_share_your_own_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_share_your_own_image',
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
      'bundle' => 'social_scholarship',
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
          'weight' => 1,
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_share_your_own_image',
      'label' => 'Share your own image',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'share-a-stat',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2 MB',
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
        'weight' => '5',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(Optional) sponsor image that will appear at the bottom of all pages for this Share a Stat.');
  t('Alphas Campaign');
  t('An image that will appear in the header, should you want it to.');
  t('Betas Campaign');
  t('Body');
  t('Check this box if this share a stat is linked to a campaign.');
  t('Color Scheme');
  t('Either: The relative path to the page NOT including the first / (e.g. blog/7-facts-about-kittens)
<br />OR: The full url to a webpage (e.g. http://www.google.com)');
  t('Email mailchimp bucket');
  t('Facebook "Recommend" Language');
  t('Facebook "Share" Language');
  t('If this is a campaign share a stat, the user will be presented with a shortform after they complete the actual share a stat.  Put the mailchimp bucket their email should land in after they fill it out.');
  t('Images');
  t('Is a campaign Share a Stat?');
  t('Linked campaign');
  t('Logo Image');
  t('Logo text');
  t('Official Rules Document');
  t('Optional.  A campaign number on Mobile Commons for Alphas.');
  t('Optional.  A mobile commons ID for betas.');
  t('Petition Image');
  t('Petition Link');
  t('Redirect message');
  t('Redirect to path');
  t('Share your own image');
  t('Shortform replacement image');
  t('Sponsor image');
  t('Text to accompany the Facebook share links.  These will correspond, in order, with the order of the images that were uploaded above (e.g. the first description will accompany the first image, the second with the second image, etc...)');
  t('The Language for the Facebook "Recommend" button');
  t('The link to the petition (or other) that will be below the --- OR --- line on the images page.');
  t('The message that appears after a use is redirected to the "redirect to" URL.');
  t('The text that will appear in front of the logo image, if applicable.  If left blank, this share a stat will use the title instead.');
  t('This tip will show up on the top of the form.');
  t('Tip to show on form');

  return $fields;
}
