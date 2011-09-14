<?php
/**
 * @file
 * dosomething_user_fields.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function dosomething_user_fields_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-field_user_email'
  $fields['user-user-field_user_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_user_email',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'email',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_user_email',
      'label' => 'E-mail',
      'required' => 1,
      'settings' => array(
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'user-user-field_user_school'
  $fields['user-user-field_user_school'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_user_school',
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
          'campaign_ebd_2011' => 0,
          'campaign_gys_2011' => 0,
          'canned_food' => 0,
          'cause' => 0,
          'cause_video' => 0,
          'celebs_gone_good' => 0,
          'chatterbox' => 0,
          'club' => 0,
          'club_event' => 0,
          'custom_voting' => 0,
          'ds101_action_kit' => 0,
          'ds_award_judging' => 0,
          'dsaward_app' => 0,
          'dsaward_rec' => 0,
          'dsu_askprof' => 0,
          'dsu_guides' => 0,
          'easy_idea' => 0,
          'ebd_signup' => 0,
          'editorial_project' => 0,
          'final_grant_update' => 0,
          'forum' => 0,
          'general_grant_app' => 0,
          'grant' => 0,
          'grant_alumni' => 0,
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
          'project_update' => 0,
          'save_our_music' => 0,
          'scholarships_att' => 0,
          'school' => 'school',
          'scroller' => 0,
          'sixflags_scholarships_app' => 0,
          'staff_blog' => 0,
          'staples_2011_signup' => 0,
          'tackle_hunger' => 0,
          'tfj_contest_signup' => 0,
          'tips_and_tools' => 0,
          'troop_letter' => 0,
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
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_user_school',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'user_register_form' => 1,
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
        'weight' => '11',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('E-mail');
  t('School');

  return $fields;
}
