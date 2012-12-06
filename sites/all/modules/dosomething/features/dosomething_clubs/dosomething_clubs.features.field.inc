<?php
/**
 * @file
 * dosomething_clubs.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_clubs_field_default_fields() {
  $fields = array();

  // Exported field: 'node-club-field_camp'.
  $fields['node-club-field_camp'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_camp',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
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
      'field_name' => 'field_camp',
      'label' => 'My Do Something Club is going to work on',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-1',
      'widget' => array(
        'active' => 1,
        'module' => 'select_or_other',
        'settings' => array(
          'available_options' => 'epic|Epic Book Drive - our Spring book drive
hunt|The Hunt: 11 Days of Doing - our Summer volunteer team challenge
spit|Give a Spit About Cancer - our fall cancer campaign
e_waste|E-waste Drive - our fall e-waste drive
sports|Sports Equipment - our fall sports equipment drive',
          'available_options_php' => '',
          'markup_available_options_php' => '&lt;none&gt;',
          'other' => 'I\'m going to create my own project idea:',
          'other_unknown_defaults' => 'other',
          'sort_options' => 0,
        ),
        'type' => 'select_or_other_buttons',
        'weight' => '13',
      ),
      'widget_type' => 'select_or_other_buttons',
    ),
  );

  // Exported field: 'node-club-field_campaign_list'.
  $fields['node-club-field_campaign_list'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_campaign_list',
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
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '3',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_campaign_list',
      'label' => 'My Do Something Club is going to work on',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-club-field_club_address'.
  $fields['node-club-field_club_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_address',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_address',
      'label' => 'Address',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '20',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'default_value_php' => NULL,
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '17',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_club_blurb'.
  $fields['node-club-field_club_blurb'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_blurb',
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
        'max_length' => '140',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'In 140 characters or less, post your club\'s goals, next meeting date, or upcoming volunteer opportunities.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 30,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_club_blurb',
      'label' => 'Insert a blurb of text about your club',
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

  // Exported field: 'node-club-field_club_city'.
  $fields['node-club-field_club_city'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_city',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '21',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_city',
      'label' => 'City',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '21',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'default_value_php' => NULL,
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '18',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_club_leader_birthdate'.
  $fields['node-club-field_club_leader_birthdate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_leader_birthdate',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
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
      'type' => 'date',
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '-3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_club_leader_birthdate_default',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '-3',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_club_leader_birthdate_default',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '-3',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_club_leader_birthdate_default',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '-3',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'field_club_leader_birthdate_default',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '-3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_leader_birthdate',
      'label' => 'Date of birth',
      'required' => 1,
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '-3',
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => 1,
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_text',
        'weight' => '10',
      ),
      'widget_type' => 'date_text',
    ),
  );

  // Exported field: 'node-club-field_club_mailings'.
  $fields['node-club-field_club_mailings'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_mailings',
      'field_permissions' => array(
        'type' => '2',
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
          'welcome' => 'Yes, I’d like to receive a DoSomething.org Clubs Welcome Packet via snail mail with banners, stickers, and other Do Something SWAG',
          'mailings' => 'Yes, I’d like to receive additional DoSomething.org Clubs Official Mailings via snail mail twice a year with materials to help my club be successful',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'search_index' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_club_mailings',
      'label' => 'Mailings',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-club-field_club_picture'.
  $fields['node-club-field_club_picture'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_picture',
      'field_permissions' => array(
        'type' => '2',
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
        'default_image' => '98738',
        'description_field' => '0',
        'list_default' => 1,
        'list_field' => '0',
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => '',
      'deleted' => '0',
      'description' => 'We\'ll resize and crop it down to a square for you.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-6',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-6',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '-6',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '-6',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_picture',
      'label' => 'Official Club photo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'club',
        'file_extensions' => 'jpg jpeg png gif',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'weight' => '-6',
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
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'bar',
        ),
        'type' => 'image_image',
        'weight' => '26',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-club-field_club_state'.
  $fields['node-club-field_club_state'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_state',
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
          'AB' => 'AB',
          'AK' => 'AK',
          'AL' => 'AL',
          'AR' => 'AR',
          'AS' => 'AS',
          'AZ' => 'AZ',
          'BC' => 'BC',
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
          'MB' => 'MB',
          'MD' => 'MD',
          'ME' => 'ME',
          'MH' => 'MH',
          'MI' => 'MI',
          'MN' => 'MN',
          'MO' => 'MO',
          'MP' => 'MP',
          'MS' => 'MS',
          'MT' => 'MT',
          'NB' => 'NB',
          'NC' => 'NC',
          'ND' => 'ND',
          'NE' => 'NE',
          'NH' => 'NH',
          'NJ' => 'NJ',
          'NL' => 'NL',
          'NM' => 'NM',
          'NT' => 'NT',
          'NS' => 'NS',
          'NU' => 'NU',
          'NV' => 'NV',
          'NY' => 'NY',
          'OH' => 'OH',
          'OK' => 'OK',
          'ON' => 'ON',
          'OR' => 'OR',
          'PA' => 'PA',
          'PE' => 'PE',
          'PR' => 'PR',
          'PW' => 'PW',
          'QC' => 'QC',
          'RI' => 'RI',
          'SC' => 'SC',
          'SD' => 'SD',
          'SK' => 'SK',
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
          'YT' => 'YT',
          'Outside of U.S./Canada' => 'Outside of U.S./Canada',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'yacapp',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '22',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '22',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '22',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '22',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_state',
      'label' => 'State',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '22',
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '19',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-club-field_club_verified'.
  $fields['node-club-field_club_verified'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_verified',
      'field_permissions' => array(
        'type' => '2',
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
          'yes' => 'Yes',
          'no' => 'No',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => array(
        0 => array(
          'value' => 'no',
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
          'weight' => 25,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_club_verified',
      'label' => 'Verified',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-club-field_club_video'.
  $fields['node-club-field_club_video'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_video',
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
      'type_name' => 'club',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => '18',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_club_video',
      'label' => 'Video (optional)',
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
            'private' => 0,
            'public' => 'public',
            'vimeo' => 0,
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
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '29',
      ),
    ),
  );

  // Exported field: 'node-club-field_club_zip'.
  $fields['node-club-field_club_zip'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_club_zip',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'custom_voting',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '23',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '23',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '23',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '23',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_club_zip',
      'label' => 'ZIP/Postal Code',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '23',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'default_value_php' => NULL,
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '21',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_country'.
  $fields['node-club-field_country'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_country',
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
          'AF' => 'Afghanistan',
          'AX' => 'Aland Islands',
          'AL' => 'Albania',
          'DZ' => 'Algeria',
          'AS' => 'American Samoa',
          'AD' => 'Andorra',
          'AO' => 'Angola',
          'AI' => 'Anguilla',
          'AQ' => 'Antarctica',
          'AG' => 'Antigua and Barbuda',
          'AR' => 'Argentina',
          'AM' => 'Armenia',
          'AW' => 'Aruba',
          'AU' => 'Australia',
          'AT' => 'Austria',
          'AZ' => 'Azerbaijan',
          'BS' => 'Bahamas',
          'BH' => 'Bahrain',
          'BD' => 'Bangladesh',
          'BB' => 'Barbados',
          'BY' => 'Belarus',
          'BE' => 'Belgium',
          'BZ' => 'Belize',
          'BJ' => 'Benin',
          'BM' => 'Bermuda',
          'BT' => 'Bhutan',
          'BO' => 'Bolivia',
          'BA' => 'Bosnia and Herzegovina',
          'BW' => 'Botswana',
          'BV' => 'Bouvet Island',
          'BR' => 'Brazil',
          'IO' => 'British Indian Ocean Territory',
          'VG' => 'British Virgin Islands',
          'BN' => 'Brunei',
          'BG' => 'Bulgaria',
          'BF' => 'Burkina Faso',
          'BI' => 'Burundi',
          'KH' => 'Cambodia',
          'CM' => 'Cameroon',
          'CA' => 'Canada',
          'CV' => 'Cape Verde',
          'KY' => 'Cayman Islands',
          'CF' => 'Central African Republic',
          'TD' => 'Chad',
          'CL' => 'Chile',
          'CN' => 'China',
          'CX' => 'Christmas Island',
          'CC' => 'Cocos (Keeling) Islands',
          'CO' => 'Colombia',
          'KM' => 'Comoros',
          'CG' => 'Congo (Brazzaville)',
          'CD' => 'Congo (Kinshasa)',
          'CK' => 'Cook Islands',
          'CR' => 'Costa Rica',
          'HR' => 'Croatia',
          'CU' => 'Cuba',
          'CW' => 'Curaçao',
          'CY' => 'Cyprus',
          'CZ' => 'Czech Republic',
          'DK' => 'Denmark',
          'DJ' => 'Djibouti',
          'DM' => 'Dominica',
          'DO' => 'Dominican Republic',
          'EC' => 'Ecuador',
          'EG' => 'Egypt',
          'SV' => 'El Salvador',
          'GQ' => 'Equatorial Guinea',
          'ER' => 'Eritrea',
          'EE' => 'Estonia',
          'ET' => 'Ethiopia',
          'FK' => 'Falkland Islands',
          'FO' => 'Faroe Islands',
          'FJ' => 'Fiji',
          'FI' => 'Finland',
          'FR' => 'France',
          'GF' => 'French Guiana',
          'PF' => 'French Polynesia',
          'TF' => 'French Southern Territories',
          'GA' => 'Gabon',
          'GM' => 'Gambia',
          'GE' => 'Georgia',
          'DE' => 'Germany',
          'GH' => 'Ghana',
          'GI' => 'Gibraltar',
          'GR' => 'Greece',
          'GL' => 'Greenland',
          'GD' => 'Grenada',
          'GP' => 'Guadeloupe',
          'GU' => 'Guam',
          'GT' => 'Guatemala',
          'GG' => 'Guernsey',
          'GN' => 'Guinea',
          'GW' => 'Guinea-Bissau',
          'GY' => 'Guyana',
          'HT' => 'Haiti',
          'HM' => 'Heard Island and McDonald Islands',
          'HN' => 'Honduras',
          'HK' => 'Hong Kong S.A.R., China',
          'HU' => 'Hungary',
          'IS' => 'Iceland',
          'IN' => 'India',
          'ID' => 'Indonesia',
          'IR' => 'Iran',
          'IQ' => 'Iraq',
          'IE' => 'Ireland',
          'IM' => 'Isle of Man',
          'IL' => 'Israel',
          'IT' => 'Italy',
          'CI' => 'Ivory Coast',
          'JM' => 'Jamaica',
          'JP' => 'Japan',
          'JE' => 'Jersey',
          'JO' => 'Jordan',
          'KZ' => 'Kazakhstan',
          'KE' => 'Kenya',
          'KI' => 'Kiribati',
          'KW' => 'Kuwait',
          'KG' => 'Kyrgyzstan',
          'LA' => 'Laos',
          'LV' => 'Latvia',
          'LB' => 'Lebanon',
          'LS' => 'Lesotho',
          'LR' => 'Liberia',
          'LY' => 'Libya',
          'LI' => 'Liechtenstein',
          'LT' => 'Lithuania',
          'LU' => 'Luxembourg',
          'MO' => 'Macao S.A.R., China',
          'MK' => 'Macedonia',
          'MG' => 'Madagascar',
          'MW' => 'Malawi',
          'MY' => 'Malaysia',
          'MV' => 'Maldives',
          'ML' => 'Mali',
          'MT' => 'Malta',
          'MH' => 'Marshall Islands',
          'MQ' => 'Martinique',
          'MR' => 'Mauritania',
          'MU' => 'Mauritius',
          'YT' => 'Mayotte',
          'MX' => 'Mexico',
          'FM' => 'Micronesia',
          'MD' => 'Moldova',
          'MC' => 'Monaco',
          'MN' => 'Mongolia',
          'ME' => 'Montenegro',
          'MS' => 'Montserrat',
          'MA' => 'Morocco',
          'MZ' => 'Mozambique',
          'MM' => 'Myanmar',
          'NA' => 'Namibia',
          'NR' => 'Nauru',
          'NP' => 'Nepal',
          'NL' => 'Netherlands',
          'AN' => 'Netherlands Antilles',
          'NC' => 'New Caledonia',
          'NZ' => 'New Zealand',
          'NI' => 'Nicaragua',
          'NE' => 'Niger',
          'NG' => 'Nigeria',
          'NU' => 'Niue',
          'NF' => 'Norfolk Island',
          'MP' => 'Northern Mariana Islands',
          'KP' => 'North Korea',
          'NO' => 'Norway',
          'OM' => 'Oman',
          'PK' => 'Pakistan',
          'PW' => 'Palau',
          'PS' => 'Palestinian Territory',
          'PA' => 'Panama',
          'PG' => 'Papua New Guinea',
          'PY' => 'Paraguay',
          'PE' => 'Peru',
          'PH' => 'Philippines',
          'PN' => 'Pitcairn',
          'PL' => 'Poland',
          'PT' => 'Portugal',
          'PR' => 'Puerto Rico',
          'QA' => 'Qatar',
          'RE' => 'Reunion',
          'RO' => 'Romania',
          'RU' => 'Russia',
          'RW' => 'Rwanda',
          'BL' => 'Saint Barthélemy',
          'SH' => 'Saint Helena',
          'KN' => 'Saint Kitts and Nevis',
          'LC' => 'Saint Lucia',
          'MF' => 'Saint Martin (French part)',
          'PM' => 'Saint Pierre and Miquelon',
          'VC' => 'Saint Vincent and the Grenadines',
          'WS' => 'Samoa',
          'SM' => 'San Marino',
          'ST' => 'Sao Tome and Principe',
          'SA' => 'Saudi Arabia',
          'SN' => 'Senegal',
          'RS' => 'Serbia',
          'SC' => 'Seychelles',
          'SL' => 'Sierra Leone',
          'SG' => 'Singapore',
          'SK' => 'Slovakia',
          'SI' => 'Slovenia',
          'SB' => 'Solomon Islands',
          'SO' => 'Somalia',
          'ZA' => 'South Africa',
          'GS' => 'South Georgia and the South Sandwich Islands',
          'KR' => 'South Korea',
          'ES' => 'Spain',
          'LK' => 'Sri Lanka',
          'SD' => 'Sudan',
          'SR' => 'Suriname',
          'SJ' => 'Svalbard and Jan Mayen',
          'SZ' => 'Swaziland',
          'SE' => 'Sweden',
          'CH' => 'Switzerland',
          'SY' => 'Syria',
          'TW' => 'Taiwan',
          'TJ' => 'Tajikistan',
          'TZ' => 'Tanzania',
          'TH' => 'Thailand',
          'TL' => 'Timor-Leste',
          'TG' => 'Togo',
          'TK' => 'Tokelau',
          'TO' => 'Tonga',
          'TT' => 'Trinidad and Tobago',
          'TN' => 'Tunisia',
          'TR' => 'Turkey',
          'TM' => 'Turkmenistan',
          'TC' => 'Turks and Caicos Islands',
          'TV' => 'Tuvalu',
          'VI' => 'U.S. Virgin Islands',
          'UG' => 'Uganda',
          'UA' => 'Ukraine',
          'AE' => 'United Arab Emirates',
          'GB' => 'United Kingdom',
          'US' => 'United States',
          'UM' => 'United States Minor Outlying Islands',
          'UY' => 'Uruguay',
          'UZ' => 'Uzbekistan',
          'VU' => 'Vanuatu',
          'VA' => 'Vatican',
          'VE' => 'Venezuela',
          'VN' => 'Vietnam',
          'WF' => 'Wallis and Futuna',
          'EH' => 'Western Sahara',
          'YE' => 'Yemen',
          'ZM' => 'Zambia',
          'ZW' => 'Zimbabwe',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 31,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_country',
      'label' => 'Country',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'node-club-field_email'.
  $fields['node-club-field_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'troop_letter',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Please provide an email address you regularly check to receive notifications regarding your eligibility for grants, prizes, and other sweet opportunities.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
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
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_mailchimp_group_id'.
  $fields['node-club-field_mailchimp_group_id'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mailchimp_group_id',
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
      'bundle' => 'club',
      'default_value' => array(
        0 => array(
          'value' => 'Clubs2012',
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
          'weight' => '16',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_mailchimp_group_id',
      'label' => 'Mailchimp Interest Group',
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

  // Exported field: 'node-club-field_name'.
  $fields['node-club-field_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_name',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'youth_grant_app',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-7',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-7',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-7',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-7',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_name',
      'label' => 'First Name',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-7',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'default_value_php' => NULL,
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_name_last'.
  $fields['node-club-field_name_last'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_name_last',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'yacapp',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_name_last',
      'label' => 'Last Name',
      'required' => '1',
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-6',
      'widget' => array(
        'active' => '1',
        'module' => 'text',
        'settings' => array(
          'default_value_php' => NULL,
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '9.5',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_no_school_associate'.
  $fields['node-club-field_no_school_associate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_no_school_associate',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_no_school_associate',
      'label' => 'OR My club is not associated with a school (this will delete your school selection)',
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
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-club-field_noschool_club_name'.
  $fields['node-club-field_noschool_club_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_noschool_club_name',
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
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_noschool_club_name',
      'label' => 'What would you like to name this club?',
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

  // Exported field: 'node-club-field_participants'.
  $fields['node-club-field_participants'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_participants',
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
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'List the email addresses of people you\'d like to invite to your club.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 28,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_participants',
      'label' => 'Invite a Friend',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-club-field_phone_required'.
  $fields['node-club-field_phone_required'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone_required',
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
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'profile2_private' => FALSE,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'speed_catcher',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Our text messages include scholarship / volunteer opportunities, and special club leader news. Msg & data rates may apply. Text STOP to opt-out, HELP for help.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-5',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-5',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-5',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-5',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_phone_required',
      'label' => 'Cell',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-5',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '7',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-club-field_project_photo'.
  $fields['node-club-field_project_photo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_photo',
      'field_permissions' => array(
        'type' => '2',
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
      'bundle' => 'club',
      'default_value' => '',
      'deleted' => '0',
      'description' => '<p>Upload photos of your club or projects here by choosing a file then hitting "Upload".  Please don\'t use BMP files.  Max photo dimensions are 580x50 pxels.</p>',
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
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-4',
        ),
        'search_index' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '-4',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
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
      'label' => 'Club Photo Gallery',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'project_photos',
        'file_extensions' => 'jpg jpeg png gif',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
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
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'bar',
        ),
        'type' => 'image_image',
        'weight' => '28',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-club-field_responded_to_texts'.
  $fields['node-club-field_responded_to_texts'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_responded_to_texts',
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
      'bundle' => 'club',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The last date (by timestamp) that the club leader responded to a text.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 21,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_responded_to_texts',
      'label' => 'Responded to Texts',
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
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-club-field_school_reference'.
  $fields['node-club-field_school_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_school_reference',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          1 => 'target_id',
        ),
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
      'bundle' => 'club',
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
          'weight' => 27,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_school_reference',
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-club-field_send_goodies'.
  $fields['node-club-field_send_goodies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_send_goodies',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'club',
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
          'weight' => 29,
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'field_send_goodies',
      'label' => 'Yes! Mail me this semester\'s DoSomething.org Club Kit',
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
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-club-group_group'.
  $fields['node-club-group_group'] = array(
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
      'locked' => '0',
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
      'bundle' => 'club',
      'default_value' => array(
        0 => array(
          'value' => '1',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'og_ui',
          'settings' => array(),
          'type' => 'og_group_subscribe',
          'weight' => '9',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'group_group',
      'label' => 'Group type',
      'required' => 1,
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
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '8',
      ),
      'widget_type' => 'options_select',
    ),
  );

  // Exported field: 'node-club-og_node_link'.
  $fields['node-club-og_node_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'og_node_link',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'no_ui' => TRUE,
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'og_node_link_field_allowed_values',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'club',
      'default_value' => array(
        0 => array(
          'value' => 'club_event',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og_node_link',
          'settings' => array(),
          'type' => 'og_node_link_default',
          'weight' => '13',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
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
      'field_name' => 'og_node_link',
      'label' => 'Add group content',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'label' => 'above',
          'type' => 'og_node_link_default',
        ),
        'teaser' => array(
          'label' => 'above',
          'type' => 'og_node_link_default',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '11',
      ),
      'widget_type' => 'options_select',
    ),
  );

  // Exported field: 'taxonomy_term-clubs_todo_list-field_todo_image'.
  $fields['taxonomy_term-clubs_todo_list-field_todo_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_todo_image',
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
      'bundle' => 'clubs_todo_list',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_todo_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'clubs_todo_images',
        'file_extensions' => 'jpg jpeg gif png',
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-clubs_todo_list-field_todo_link'.
  $fields['taxonomy_term-clubs_todo_list-field_todo_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_todo_link',
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
      'bundle' => 'clubs_todo_list',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_todo_link',
      'label' => 'Link to',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Upload photos of your club or projects here by choosing a file then hitting "Upload".  Please don\'t use BMP files.  Max photo dimensions are 580x50 pxels.</p>');
  t('Add group content');
  t('Address');
  t('Cell');
  t('City');
  t('Club Photo Gallery');
  t('Country');
  t('Date of birth');
  t('Email');
  t('First Name');
  t('Group type');
  t('Image');
  t('In 140 characters or less, post your club\'s goals, next meeting date, or upcoming volunteer opportunities.');
  t('Insert a blurb of text about your club');
  t('Invite a Friend');
  t('Last Name');
  t('Link to');
  t('List the email addresses of people you\'d like to invite to your club.');
  t('Mailchimp Interest Group');
  t('Mailings');
  t('My Do Something Club is going to work on');
  t('OR My club is not associated with a school (this will delete your school selection)');
  t('Official Club photo');
  t('Our text messages include scholarship / volunteer opportunities, and special club leader news. Msg & data rates may apply. Text STOP to opt-out, HELP for help.');
  t('Please provide an email address you regularly check to receive notifications regarding your eligibility for grants, prizes, and other sweet opportunities.');
  t('Responded to Texts');
  t('School');
  t('State');
  t('The last date (by timestamp) that the club leader responded to a text.');
  t('Verified');
  t('Video (optional)');
  t('We\'ll resize and crop it down to a square for you.');
  t('What would you like to name this club?');
  t('Yes! Mail me this semester\'s DoSomething.org Club Kit');
  t('ZIP/Postal Code');

  return $fields;
}
