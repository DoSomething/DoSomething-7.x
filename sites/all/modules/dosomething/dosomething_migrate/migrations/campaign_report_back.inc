<?php

// Campaign Report Back

abstract class DSCampaignReportBackMigration extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('CampaignReportBack'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
    $this->addUnmigratedDestinations(array('field_webform_geocode_zip_code', 'field_webform_school'));
  }

  public function prepareRow($row) {
    // emfields
    foreach (array('field_embedded_video', 'field_campaign_video', 'field_botb_video') as $name) {
      if (!empty($row->$name)) {
        if (is_array($row->$name)) {
          foreach ($row->$name as &$value) {
            $value = $this->fidFromEmField($value, $row->uid);
          }
        }
        else {
          $row->$name = $this->fidFromEmField($row->$name, $row->uid);
        }
      }
    }

    // Extract the zip code from the location:
    $row->locations = empty($row->locations[0]->postal_code) ? NULL : $row->locations[0]->postal_code;
  }
}

/*
class DSCampaignReportBackBotbMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('botb');
    $this->description .= 'Battle of the Bands submission';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackCampaignBfb2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_bfb_2011');
    $this->description .= 'Campaign Project - Battle for the Bands 2011';

    $this->addFieldMapping('data_school_group_name', 'title');
    $this->addFieldMapping('data_is_this_address_school_or_home', 'field_campaign_address_type')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_project_or_video', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_why_is_music_education_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_how_did_your_work_unfold_what_was_the_best_part', 'field_campaign_essay_how');
    $this->addFieldMapping('data_why_did_you_choose_to_run_this_advocacy_project', 'field_why_run_advocacy_project');
    $this->addFieldMapping('data_did_you_cover_another_artists_song_in_your_video_or_was_it_an_original', 'field_botb_cover')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_the_name_of_the_artist_or_group', 'field_botb_cover_artist');
    $this->addFieldMapping('data_the_name_of_the_song', 'field_botb_cover_song');
    $this->addFieldMapping('data_what_impact_did_your_project_have_on_your_school_community', 'field_impact_project_had_on_com');
    $this->addFieldMapping('data_how_many_boxes_of_books_do_you_plan_to_collect_35_books_in_a_box', 'field_what_is_your_goal_number_');
    $this->addFieldMapping('data_does_your_video_feature_a', 'field_botb_style')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_if_you_chose_other_what_type_of_group_performed_in_your_video', 'field_botb_style_other');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_you_faced', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_agree_to_the_official_contest_rules', 'field_botb_agreement')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_anything_else_we_should_know_about_your_battle_for_the_bands_advocacy_project', 'field_botb_other');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_how_did_you_head_about_us', 'vocab_15')
    ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');
    $this->addFieldMapping('data_post_a_link_to_your_video', 'field_botb_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_campaign_project_type', 'field_campaign_project_type');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));

    //NULL Mappings
    $this->addUnmigratedSources(array('field_campaign_group', 'field_campaign_project_type'));
    $this->addUnmigratedDestinations(array('data_campaign_project_type', 'field_webform_mobile', 'field_webform_email', 'field_webform_school', 'field_webform_school_zip'));

  }
}

class DSCampaignReportBackCampaignEbd2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_ebd_2011');
    $this->description .= 'Campaign Project - Epic Book Drive 2011';

    $this->addFieldMapping('data_school_group_name', 'field_campaign_group');
    $this->addFieldMapping('data_why_is_educational_equality_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_book_drive', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_how_did_your_work_unfold_what_was_the_best_part', 'field_campaign_essay_how');
    $this->addFieldMapping('data_friends_mobile_number', 'field_your_cell_phone_notrequir');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_you_faced', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');
    $this->addFieldMapping('data_anything_else_awesome_we_should_know', 'field_campaign_anything_else');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_school_group_name', 'field_campaign_group');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('data_school_group_name_1', 'field_webform_mobile', 'field_webform_email', 'field_webform_school', 'field_webform_school_zip', 'data_video'));

  }
}

class DSCampaignReportBackCampaignGys2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_gys_2011');
    $this->description .= 'Campaign Project - Green Your School 2011';

    $this->addFieldMapping('data_number_of_people_involved_in_this_project', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_how_did_you_use_technology_to_green_your_school', 'field_iyg_technology');
    $this->addFieldMapping('data_why_is_greening_your_school_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_how_did_your_project_unfold_what_was_the_best_part', 'field_campaign_essay_how');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_in_running_your_program', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');

    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_your_school', 'title');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_mobile', 'field_webform_email', 'field_webform_school', 'field_webform_school_zip'));
  }
}

class DSCampaignReportBackCampaignHunt2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_hunt_2011');
    $this->description .= 'Campaign Project - Scavenger Hunt 2011';

    $this->addFieldMapping('data_which_of_this_days_challenges_did_you_complete', 'field_which_challenge');
    $this->addFieldMapping('data_team_name', 'title');
    $this->addFieldMapping('data_tell_us_more_about_how_your_team_tackled_this_challenge', 'field_campaign_essay_how');
    $this->addFieldMapping('data_how_many_people_were_involved_in_completing_this_challenge', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_your_youtube_username', 'field_youtube_username');
    $this->addFieldMapping('data_why_is_taking_action_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_you_faced', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');
    $this->addFieldMapping('data_challenge_type', 'field_campaign_project_type');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_mobile', 'field_webform_school', 'field_webform_school_zip'));
  }
}

class DSCampaignReportBackCannedFoodMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('canned_food');
    $this->description .= 'Canned Food Drive Report (Tackle Hunger)';

    $this->addFieldMapping('data_name_of_school_or_group', 'title');
    $this->addFieldMapping('data_your_first_and_last_name', 'field_cannedfood_contactname');
    $this->addFieldMapping('data_state', 'field_state_plain')
      ->issuePriority(MigrateFieldMapping::ISSUE_PRIORITY_LOW)
      ->description("field_state_plain has 60 values but data_state only has 58. 'Canada' and something else were removed.");
    $this->addFieldMapping('data_city', 'field_city');
    $this->addFieldMapping('data_zip_code', 'field_zip_code_0');
    $this->addFieldMapping('data_birthdate', 'field_campaign_birthdate');
    $this->addFieldMapping('data_where_did_you_hear_about_us', 'field_where_did_you_hear');
    $this->addFieldMapping('data_total_pounds_of_food_collected', 'field_total_pounds');
    $this->addFieldMapping('data_number_of_cans_collected', 'field_number_cans');
    $this->addFieldMapping('data_number_of_boxes_and_items_of_food', 'field_cannedfood_itemsboxes');
    $this->addFieldMapping('data_number_of_students_who_participated_in_the_drive', 'field_cannedfood_studentsinvolv');
    $this->addFieldMapping('data_number_of_students_in_your_school', 'field_cannedfood_students');
    $this->addFieldMapping('data_where_did_you_donate', 'field_cannedfood_donationcenter');
    $this->addFieldMapping('data_tell_us_more_about_your_drive_what_creative_things_did_you_do_to_really_rock_this_is_your_chance_to_shine', 'field_tell_us_more_about_your_d');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_email', 'field_email_1');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number_1');
    $this->addFieldMapping('field_webform_pictures', 'field_fooddrive_photo')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_videos', 'field_embedded_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_name_of_school_or_group', 'title');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));

  }
}

/*
class DSCampaignReportBackFeedTheNeedMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('feed_the_need');
    $this->description .= 'Feed the Need Drive';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackHealthySchoolsReportMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('healthy_schools_report');
    $this->description .= 'Healthy Schools Report Back';

    $this->addFieldMapping('data_project_name', 'field_healthy_schools_report_na');
    $this->addFieldMapping('data_city', 'field_campaign_city');
    $this->addFieldMapping('data_state', 'field_campaign_state_0');
    $this->addFieldMapping('data_how_many_people_are_on_your_team', 'field_healthy_schools_report_te');
    $this->addFieldMapping('data_how_many_people_participated', 'field_healthy_schools_report_pa');
    $this->addFieldMapping('data_what_kind_of_project_did_you_do', 'field_healthy_schools_report_ty')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_tell_us_about_your_project', 'field_campaign_essay');
    $this->addFieldMapping('data_how_did_you_get_other_students_excited_and_involved', 'field_healthy_schools_report_ho');

    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone_0');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_school', 'field_webform_school_zip'));
  }
}

/*
class DSCampaignReportBackHpArtMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('hp_art');
    $this->description .= 'HP Art';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackIncreaseyourgreenReportMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('increaseyourgreen_report');
    $this->description .= 'Increase Your Green Report';

    # $this->addFieldMapping('', '');

  }
}

class DSCampaignReportBackIyg2010Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('iyg_2010');
    $this->description .= 'Increase Your Green 2010';

    # $this->addFieldMapping('', '');

  }
}
*/

class DSCampaignReportBackSaveOurMusicMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('save_our_music');
    $this->description .= 'Save Our Music';

    $this->addFieldMapping('data_school_you_attend', 'field_school');
    $this->addFieldMapping('data_first_name', 'field_name');
    $this->addFieldMapping('data_last_name', 'field_name_last');
    $this->addFieldMapping('data_address', 'field_plumgrant_address');
    $this->addFieldMapping('data_city', 'field_city');
    $this->addFieldMapping('data_state', 'field_state_plain');
    $this->addFieldMapping('data_zip_code', 'field_zip_code_2');
    $this->addFieldMapping('data_where_did_you_hear_about_us', 'field_where_did_you_hear');
    $this->addFieldMapping('data_why_is_music_education_important_to_you', 'field_som_why_important');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_save_our_music_projects', 'field_num_people_involved');
    $this->addFieldMapping('data_describe_your_projects', 'field_som_project_teaser');
    $this->addFieldMapping('data_what_were_your_biggest_accomplishments', 'field_som_accomplishments');
    $this->addFieldMapping('data_insert_links_to_associated_projects_youve_already_posted', 'field_som_project_links');
    $this->addFieldMapping('data_ell_us_more_what_else_should_we_know_about_your_save_our_music_efforts', 'field_som_project_more');
    $this->addFieldMapping('data_how_many_signatures_did_you_collect', 'field_som_petition_count');
    $this->addFieldMapping('data_tell_us_more_about_your_petition', 'field_som_petition_more');
    $this->addFieldMapping('data_how_many_letters_were_sent', 'field_som_letter_count');
    $this->addFieldMapping('data_tell_us_more_about_your_letter_writing_campaign', 'field_som_letter_more');
    $this->addFieldMapping('data_how_many_instruments_were_collected', 'field_som_instrument_count');
    $this->addFieldMapping('data_tell_us_more_about_your_instrument_drive', 'field_som_instrument_more');

    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_required');
    $this->addFieldMapping('field_webform_videos', 'field_embedded_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_pictures', 'field_project_photo')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_school_you_attend', 'field_school');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));
  }
}

class DSCampaignReportBackSfsReportGalleryMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('sfs_report_gallery');
    $this->description .= 'Staples for Students Image Submission';

    $this->addFieldMapping('data_drive_or_school_name', 'title');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_school_supply_drive', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_what_awesome_things_did_you_do_to_make_your_drive_particularly_successful', 'field_awesome_idea');
    $this->addFieldMapping('data_anything_else_we_should_know_about_your_staples_for_students_project', 'field_anything_else');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));

    $this->addFieldMapping('data_drive_or_school_name', 'title');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_mobile', 'field_webform_videos', 'field_webform_school_zip', 'field_webform_school', 'data_pictures_from_your_drive'));
  }
}

class DSCampaignReportBackStaplesReasonMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('staples_reason');
    $this->description .= 'Staples Reason for Helping';

    $this->addFieldMapping('data_reason', 'title');
    $this->addFieldMapping('data_first_name', 'field_name_f');
    $this->addFieldMapping('data_last_name', 'field_name_l');
    $this->addFieldMapping('data_state', 'field_where_from')
      ->arguments(array('source_type' => 'value'))
      ->description("field_where_from is unstructured, might not map cleanly.");
    $this->addFieldMapping('data_yes_i_am_13_years_of_age_or_older', 'field_thirteen');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_mobile', 'field_webform_videos', 'field_webform_school_zip', 'field_webform_school', 'field_webform_pictures'));
  }
}

class DSCampaignReportBackTfjContestSignupMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('tfj_contest_signup');
    $this->description .= 'Teens for Jeans Contest Signup';

    $this->addFieldMapping('data_name_of_your_school_or_group', 'title');
    $this->addFieldMapping('data_full_name', 'field_campaign_name');
    $this->addFieldMapping('data_state', 'field_campaign_state_0');
    $this->addFieldMapping('data_address', 'field_campaign_address');
    $this->addFieldMapping('data_city', 'field_campaign_city');
    $this->addFieldMapping('data_zip_code', 'field_campaign_zip');
    $this->addFieldMapping('data_your_age', 'field_your_age');
    $this->addFieldMapping('data_how_did_you_hear_about_teens_for_jeans', 'field_tfj_contest_howheard');
    $this->addFieldMapping('data_how_many_jeans_did_your_group_collect', 'field_tfj_contest_jeans_collect');
    $this->addFieldMapping('data_how_many_people_donated_jeans_to_your_drive', 'field_tfj_contest_participants');
    $this->addFieldMapping('data_tell_us_more_about_your_drive___what_creative_things_did_you_do_to_get_people_to_donate_more', 'field_tfj_contest_tellusmore');

    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('data_name_of_your_school_or_group', 'title');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_videos', 'field_webform_school_zip', 'field_webform_school'));
  }
}

class DSCampaignReportBackTroopLetterMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('troop_letter');
    $this->description .= 'Support Our Troops Letter';

    $this->addFieldMapping('data_zip_code', 'field_zip_code_2');
    $this->addFieldMapping('data_letter', 'field_troop_letter_body');

    $this->addFieldMapping('field_webform_email', 'field_email');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_mobile', 'field_webform_pictures', 'field_webform_school', 'field_webform_school_zip', 'field_webform_videos'));
  }
}
