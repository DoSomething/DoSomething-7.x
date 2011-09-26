<?php
/**
 * @file
 * dosomething_fb_social_plugins.fb_social.inc
 */

/**
 * Implementation of hook_fb_social_default_presets().
 */
function dosomething_fb_social_plugins_fb_social_default_presets() {
  $export = array();

  $fb_social_preset = new stdClass;
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Activity Feed';
  $fb_social_preset->description = '';
  $fb_social_preset->plugin_type = 'activityfeed';
  $fb_social_preset->settings = array(
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'site' => 'dosomething.zivtech.com',
    'width' => '300',
    'height' => '300',
    'header' => 1,
    'colorscheme' => 'light',
    'font' => 'arial',
    'border_color' => '',
    'recommendations' => 1,
  );
  $export['FB Activity Feed'] = $fb_social_preset;

  $fb_social_preset = new stdClass;
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Comments';
  $fb_social_preset->description = '';
  $fb_social_preset->plugin_type = 'comments';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        '1in3_abuse_old' => 0,
        'dsaward_app' => 0,
        '301_redirects' => 0,
        'abc_family' => 0,
        'api_key' => 0,
        'aspca_grant_app' => 0,
        'action_guide' => 0,
        'bc_bio_form' => 0,
        'campaign_bfb_2011' => 0,
        'campaign_bully_2011' => 0,
        'campaign_ebd_2011' => 0,
        'campaign_gys_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_hunt_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'canned_food' => 0,
        'cause' => 0,
        'cause_video' => 0,
        'celebs_gone_good' => 0,
        'chatterbox' => 0,
        'club' => 0,
        'club_event' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'dsu_guides' => 0,
        'decade_2011_signup' => 0,
        'ds101_action_kit' => 0,
        'dsaward_rec' => 0,
        'easy_idea' => 0,
        'editorial_project' => 0,
        'ebd_signup' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'final_grant_update' => 0,
        'general_grant_app' => 0,
        'general_scholarship_app' => 0,
        'grant' => 0,
        'grant_alumni' => 0,
        'grant_application' => 0,
        'grant_judge' => 0,
        'gys_2011' => 0,
        'healthy_schools' => 0,
        'healthy_schools_report' => 0,
        'help_ticket' => 0,
        'huffpo' => 0,
        'increaseyourgreen_signup' => 0,
        'issue' => 0,
        'page' => 0,
        'poll' => 0,
        'press' => 0,
        'project' => 0,
        'project_update' => 0,
        '911_registration' => 0,
        'save_our_music' => 0,
        'scavenger_2011_signup' => 0,
        'scholarship_application' => 0,
        'scholarship_update' => 0,
        'scholarships_att' => 0,
        'scroller' => 0,
        'sixflags_scholarships_app' => 0,
        'staff_blog' => 0,
        'staples_2011_signup' => 0,
        'staples_members' => 0,
        'staples_reason' => 0,
        'sfs_report_gallery' => 0,
        'troop_letter' => 0,
        'tackle_hunger' => 0,
        'tfj_contest_signup' => 0,
        'tips_and_tools' => 0,
        'webform' => 0,
        'club_first_meeting_cash' => 0,
        'ewaste_signup_2011' => 0,
        'grants_database' => 0,
        'ididthis' => 0,
      ),
    ),
    'plugin_location' => array(
      'display_teasers' => 0,
    ),
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'numposts' => '0',
    'width' => '550',
    'colorscheme' => 'dark',
    'migrated' => 0,
  );
  $export['FB Comments'] = $fb_social_preset;

  $fb_social_preset = new stdClass;
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Like';
  $fb_social_preset->description = '';
  $fb_social_preset->plugin_type = 'like';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        '1in3_abuse_old' => 0,
        'dsaward_app' => 0,
        '301_redirects' => 0,
        'abc_family' => 0,
        'api_key' => 0,
        'aspca_grant_app' => 0,
        'action_guide' => 0,
        'bc_bio_form' => 0,
        'campaign_bfb_2011' => 0,
        'campaign_bully_2011' => 0,
        'campaign_ebd_2011' => 0,
        'campaign_gys_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_hunt_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'canned_food' => 0,
        'cause' => 0,
        'cause_video' => 0,
        'celebs_gone_good' => 0,
        'chatterbox' => 0,
        'club' => 0,
        'club_event' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'dsu_guides' => 0,
        'decade_2011_signup' => 0,
        'ds101_action_kit' => 0,
        'dsaward_rec' => 0,
        'easy_idea' => 0,
        'editorial_project' => 0,
        'ebd_signup' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'final_grant_update' => 0,
        'general_grant_app' => 0,
        'general_scholarship_app' => 0,
        'grant' => 0,
        'grant_alumni' => 0,
        'grant_application' => 0,
        'grant_judge' => 0,
        'gys_2011' => 0,
        'healthy_schools' => 0,
        'healthy_schools_report' => 0,
        'help_ticket' => 0,
        'huffpo' => 0,
        'increaseyourgreen_signup' => 0,
        'issue' => 0,
        'page' => 0,
        'poll' => 0,
        'press' => 0,
        'project' => 0,
        'project_update' => 0,
        '911_registration' => 0,
        'save_our_music' => 0,
        'scavenger_2011_signup' => 0,
        'scholarship_application' => 0,
        'scholarship_update' => 0,
        'scholarships_att' => 0,
        'scroller' => 0,
        'sixflags_scholarships_app' => 0,
        'staff_blog' => 0,
        'staples_2011_signup' => 0,
        'staples_members' => 0,
        'staples_reason' => 0,
        'sfs_report_gallery' => 0,
        'troop_letter' => 0,
        'tackle_hunger' => 0,
        'tfj_contest_signup' => 0,
        'tips_and_tools' => 0,
        'webform' => 0,
        'club_first_meeting_cash' => 0,
        'ewaste_signup_2011' => 0,
        'grants_database' => 0,
        'ididthis' => 0,
      ),
    ),
    'opengraph_tags' => 0,
    'plugin_location' => array(
      'location' => '0',
      'display_teasers' => 0,
    ),
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'send' => 0,
    'layout' => 'button_count',
    'show_faces' => 1,
    'width' => '350',
    'action' => 'recommend',
    'font' => 'verdana',
    'colorscheme' => 'light',
  );
  $export['FB Like'] = $fb_social_preset;

  return $export;
}
