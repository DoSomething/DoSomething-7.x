<?php
/**
 * @file
 * dosomething_fb_social_plugins.fb_social.inc
 */

/**
 * Implements hook_fb_social_default_presets().
 */
function dosomething_fb_social_plugins_fb_social_default_presets() {
  $export = array();

  $fb_social_preset = new stdClass();
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

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Comments';
  $fb_social_preset->description = '';
  $fb_social_preset->plugin_type = 'comments';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        'action_guide' => 'action_guide',
        'blog' => 'blog',
        'project_update' => 'project_update',
        'tips_and_tools' => 'tips_and_tools',
        'api_key' => 0,
        'bc_bio_form' => 0,
        'campaign' => 0,
        'campaign_blog_post' => 0,
        'campaign_contact_form' => 0,
        'campaign_content_page' => 0,
        'campaign_bully_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_cancer_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'cancer_2011_signup' => 0,
        'cause_video' => 0,
        'club' => 0,
        'club_event' => 0,
        'crazy_shit' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'decade_2011_signup' => 0,
        'dsaward_rec' => 0,
        'drive_form' => 0,
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
        'dsu_guides' => 0,
        'social_scholarship' => 0,
        'sponsor' => 0,
        'team_challenge' => 0,
        'webform' => 0,
      ),
    ),
    'plugin_location' => array(
      'display_teasers' => 0,
    ),
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'numposts' => '10',
    'width' => '550',
    'colorscheme' => 'light',
    'migrated' => 0,
  );
  $export['FB Comments'] = $fb_social_preset;

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Facepile General';
  $fb_social_preset->description = 'Facepile used across site';
  $fb_social_preset->plugin_type = 'facepile';
  $fb_social_preset->settings = array(
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'href' => '',
    'size' => 'small',
    'width' => '156',
    'numrows' => '2',
    'colorscheme' => 'light',
  );
  $export['FB Facepile General'] = $fb_social_preset;

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Facepile Profile';
  $fb_social_preset->description = 'Facepile on member profile';
  $fb_social_preset->plugin_type = 'facepile';
  $fb_social_preset->settings = array(
    'block' => 1,
  );
  $fb_social_preset->fb_attrs = array(
    'href' => 'https://www.facebook.com/dosomething',
    'size' => 'small',
    'width' => '286',
    'numrows' => '2',
    'colorscheme' => 'light',
  );
  $export['FB Facepile Profile'] = $fb_social_preset;

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Like';
  $fb_social_preset->description = '';
  $fb_social_preset->plugin_type = 'like';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        'dsaward_app' => 0,
        'api_key' => 0,
        'action_guide' => 0,
        'blog' => 0,
        'bc_bio_form' => 0,
        'campaign' => 0,
        'campaign_blog_post' => 0,
        'campaign_contact_form' => 0,
        'campaign_content_page' => 0,
        'campaign_bully_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_cancer_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'cancer_2011_signup' => 0,
        'cause_video' => 0,
        'club' => 0,
        'club_event' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'decade_2011_signup' => 0,
        'dsaward_rec' => 0,
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
        'program_short_form' => 0,
        'project_report' => 0,
        'project_update' => 0,
        'scholarship' => 0,
        'scholarship_application' => 0,
        'school' => 0,
        'scroller' => 0,
        'share_of_day' => 0,
        'dsu_guides' => 0,
        'sponsor' => 0,
        'tips_and_tools' => 0,
        'webform' => 0,
      ),
    ),
    'opengraph_tags' => 1,
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
    'colorscheme' => 'dark',
  );
  $export['FB Like'] = $fb_social_preset;

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'FB Like Box';
  $fb_social_preset->description = 'FB Like Box with count';
  $fb_social_preset->plugin_type = 'like';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        'dsaward_app' => 0,
        'api_key' => 0,
        'action_guide' => 0,
        'blog' => 0,
        'bc_bio_form' => 0,
        'campaign' => 0,
        'campaign_contact_form' => 0,
        'campaign_bully_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_cancer_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'cancer_2011_signup' => 0,
        'cause_video' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'decade_2011_signup' => 0,
        'dsaward_rec' => 0,
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
        'dsu_guides' => 0,
        'tips_and_tools' => 0,
        'webform' => 0,
      ),
    ),
    'opengraph_tags' => 1,
    'plugin_location' => array(
      'location' => '0',
      'display_teasers' => 0,
    ),
    'block' => 0,
  );
  $fb_social_preset->fb_attrs = array(
    'send' => 0,
    'layout' => 'box_count',
    'show_faces' => 0,
    'width' => '60',
    'action' => 'like',
    'font' => 'verdana',
    'colorscheme' => 'light',
  );
  $export['FB Like Box'] = $fb_social_preset;

  $fb_social_preset = new stdClass();
  $fb_social_preset->disabled = FALSE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'small_like';
  $fb_social_preset->description = 'Small Like';
  $fb_social_preset->plugin_type = 'like';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
        'dsaward_app' => 0,
        '301_redirects' => 0,
        'api_key' => 0,
        'action_guide' => 0,
        'blog' => 0,
        'bc_bio_form' => 0,
        'campaign' => 0,
        'campaign_contact_form' => 0,
        'campaign_bully_2011' => 0,
        'campaign_macys_2011' => 0,
        'campaign_art_2011' => 0,
        'campaign_sports_2011' => 0,
        'campaign_ew_2011' => 0,
        'campaign_cancer_2011' => 0,
        'campaign_report_back' => 0,
        'campaign_sign_up' => 0,
        'cancer_2011_signup' => 0,
        'cause' => 0,
        'cause_video' => 0,
        'ds_award_judging' => 0,
        'awards_archive' => 0,
        'dsu_askprof' => 0,
        'decade_2011_signup' => 0,
        'dsaward_rec' => 0,
        'easy_idea' => 0,
        'editorial_content_' => 0,
        'editorial_project' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'final_grant_update' => 0,
        'grant_alumni' => 0,
        'grant_application' => 0,
        'grant_judge' => 0,
        'help_ticket' => 0,
        'huffpo' => 0,
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
        'dsu_guides' => 0,
        'staff_blog' => 0,
        'staples_members' => 0,
        'tips_and_tools' => 0,
        'webform' => 0,
        'ewaste_signup_2011' => 0,
        'member_opportunity' => 0,
        'ididthis' => 0,
      ),
    ),
    'opengraph_tags' => 0,
    'plugin_location' => array(
      'location' => '0',
      'display_teasers' => 0,
    ),
    'block' => 0,
  );
  $fb_social_preset->fb_attrs = array(
    'send' => 0,
    'layout' => 'button_count',
    'show_faces' => 0,
    'width' => '55',
    'action' => 'like',
    'font' => 'verdana',
    'colorscheme' => 'dark',
  );
  $export['small_like'] = $fb_social_preset;

  return $export;
}
