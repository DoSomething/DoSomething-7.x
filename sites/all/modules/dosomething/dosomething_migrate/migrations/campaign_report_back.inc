<?php

// Campaign Report Back
abstract class DSCampaignReportBackMigration extends DSJsonWebformMigration {
  public function __construct($node_type, $additional_fields = array()) {
    parent::__construct(MigrateGroup::getInstance('CampaignReportBack'), $node_type, $additional_fields);
    $this->addUnmigratedSources(array('changed', 'status'));
    $this->addUnmigratedDestinations(array('field_webform_school_reference', 'field_webform_geocode_zip_code', 'group_audience'));
    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
  }

  public function prepareRow($row) {
    // emfields
    foreach (array('field_embedded_video', 'field_campaign_video', 'field_botb_video', 'field_video') as $name) {
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
    $this->dependencies[] = 'DSFile';

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

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    //NULL Mappings
    $this->addUnmigratedSources(array('field_campaign_group', 'field_campaign_project_type'));
    $this->addUnmigratedDestinations(array(
      'data_campaign_project_type',
      'field_webform_mobile',
      'field_webform_email',
      'taxonomy_vocabulary_5',
      'data_your_song',
      'data_about_your_video',
      'data_official_contest_rules',
      'field_webform_school',
    ));
  }
}

class DSCampaignReportBackCampaignEbd2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_ebd_2011');
    $this->description .= 'Campaign Project - Epic Book Drive 2011';
    $this->dependencies[] = 'DSFile';

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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array(
      'data_school_group_name_1',
      'field_webform_mobile',
      'field_webform_email',
      'field_webform_school',
      'data_video',
      'taxonomy_vocabulary_5'
    ));
  }
}

class DSCampaignReportBackCampaignGys2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_gys_2011');
    $this->description .= 'Campaign Project - Green Your School 2011';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('data_your_school', 'title');
    $this->addFieldMapping('data_number_of_people_involved_in_this_project', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_how_did_you_use_technology_to_green_your_school', 'field_iyg_technology');
    $this->addFieldMapping('data_why_is_greening_your_school_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_how_did_your_project_unfold_what_was_the_best_part', 'field_campaign_essay_how');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_in_running_your_program', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno')
      ->description('Select field keys are unchanged.');
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');
    $this->addFieldMapping('data_school', 'field_signup_nid');

    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5');

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'field_webform_mobile',
      'field_webform_email',
      'field_webform_school_zip',
      'field_webform_school',
    ));
  }
}

class DSCampaignReportBackCampaignHunt2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('campaign_hunt_2011');
    $this->description .= 'Campaign Project - Scavenger Hunt 2011';
    $this->dependencies[] = 'DSFile';

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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5');

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'field_webform_mobile',
      'field_webform_school',
    ));
  }
}

class DSCampaignReportBackCannedFoodMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('canned_food');
    $this->description .= 'Canned Food Drive Report (Tackle Hunger)';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('data_name_of_school_or_group', 'title');
    $this->addFieldMapping('data_your_first_and_last_name', 'field_cannedfood_contactname');
    $this->addFieldMapping('data_state', 'field_state_plain');
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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_webform_videos', 'field_embedded_video')
      ->arguments(array('file_function' => 'file_fid'));

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'taxonomy_vocabulary_5',
      'data_contact_information',
      'data_amount_of_food_collected',
      'data_info_about_the_drive',
      'field_webform_school',
    ));
  }
}

class DSCampaignReportBackHealthySchoolsReportMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('healthy_schools_report');
    $this->description .= 'Healthy Schools Report Back';
    $this->dependencies[] = 'DSFile';

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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video')
      ->arguments(array('file_function' => 'file_fid'));

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array(
      'field_webform_email',
      'field_webform_school_zip',
      'taxonomy_vocabulary_5',
      'data_your_info',
      'data_your_project',
      'field_webform_school',
    ));
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
    $this->dependencies[] = 'DSFile';

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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array(
      'field_webform_school_zip',
      'field_webform_school',
      'taxonomy_vocabulary_5'
    ));
  }
}

class DSCampaignReportBackSfsReportGalleryMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('sfs_report_gallery');
    $this->description .= 'Staples for Students Image Submission';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('data_drive_or_school_name', 'title');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_school_supply_drive', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_what_awesome_things_did_you_do_to_make_your_drive_particularly_successful', 'field_awesome_idea');
    $this->addFieldMapping('data_anything_else_we_should_know_about_your_staples_for_students_project', 'field_anything_else');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'field_webform_email',
      'field_webform_mobile',
      'field_webform_school',
      'field_webform_videos',
      'data_pictures_from_your_drive',
      'taxonomy_vocabulary_5',
    ));
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
    $this->addFieldMapping('data_team', 'vocab_19');

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'field_webform_email',
      'field_webform_mobile',
      'field_webform_videos',
      'field_webform_pictures',
      'taxonomy_vocabulary_5',
      'field_webform_school',
    ));
  }
}

class DSCampaignReportBackTfjContestSignupMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    parent::__construct('tfj_contest_signup');
    $this->description .= 'Teens for Jeans Contest Signup';
    $this->dependencies[] = 'DSFile';

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
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    //Null Mappings
    $this->addUnmigratedDestinations(array(
      'field_webform_videos',
      'field_webform_school_zip',
      'taxonomy_vocabulary_5',
      'field_webform_school',
    ));
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
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_mobile', 'field_webform_pictures', 'field_webform_school_zip', 'field_webform_videos', 'taxonomy_vocabulary_5'));
  }
}

class DSCampaignReportBackMakeArtSaveArtMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['country'] = 'Country';
    $fields['street'] = 'Address';
    $fields['additional'] = 'Additional';
    $fields['latitude'] = 'Latitude';
    $fields['longitude'] = 'Longitude';
    $fields['loc_name'] = 'Location Name';
    parent::__construct('campaign_art_2011', $fields);
    $this->description .= 'Campaign Project - Make Art Save Art 2011';

    $this->addFieldMapping('data_first_name', 'field_art2011_first');
    $this->addFieldMapping('data_last_name', 'field_art2011_last');
    $this->addFieldMapping('field_webform_email', 'field_art2011_email');
    $this->addFieldMapping('field_webform_mobile', 'field_art2011_cell');
    $this->addFieldMapping('data_why_did_you_choose_this_design', 'field_art2011_why');
    $this->addFieldMapping('data_why_is_art_education_important_to_you', 'field_art2011_whyart');
    $this->addFieldMapping('data_date_of_birth', 'field_art2011_dob');
    $this->addFieldMapping('data_title_of_artwork', 'title');
    $this->addFieldMapping('data_zipcode', 'field_art2011_zipcode');
    $this->addFieldMapping('field_webform_school', 'field_art2011_school');
    $this->addFieldMapping('field_webform_pictures', 'field_art2011_file');
    $this->addFieldMapping('data_location_name', 'loc_name');
    $this->addFieldMapping('data_street', 'street');
    $this->addFieldMapping('data_additional', 'additional');
    $this->addFieldMapping('data_country', 'country');
    $this->addFieldMapping('data_longitude', 'longitude');
    $this->addFieldMapping('data_latitude', 'latitude');

    //Null Mappings
    $this->addUnmigratedSources(array('locations'));
    $this->addUnmigratedDestinations(array('data_location', 'field_webform_school_zip', 'field_webform_videos', 'taxonomy_vocabulary_5'));
  }
  public function prepareRow($row) {
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    // Extract the zip code from the location:
    $row->location_name = empty($location->name) ? NULL : $location->name;
    $row->zip_code = empty($location->postal_code) ? NULL : $location->postal_code;
    $row->country = empty($location->country) ? NULL : $location->country;
    $row->street = empty($location->street) ? NULL : $location->street;
    $row->additional = empty($location->additional) ? NULL : $location->additional;
    $row->latitude = empty($location->latitude) ? NULL : $location->latitude;
    $row->longitude = empty($location->longitude) ? NULL : $location->longitude;
  }
}

class DSCampaignReportBackSportsMigration extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['country'] = 'Country';
    $fields['location_name'] = 'Location Name';
    $fields['street'] = 'Street';
    $fields['additional'] = 'Additional';
    $fields['longitude'] = 'Longitude';
    $fields['latitude'] = 'Latitude';
    parent::__construct('campaign_sports_2011', $fields);
    $this->description .= 'Campaign Project - Sports Equipment 2011';

    $this->addFieldMapping('data_participants_emails', 'field_participant_emails');
    $this->addFieldMapping('field_webform_school_zip', 'field_zip_campaign');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_sports_equipment_drive', 'field_campaign_number_of_people');
    $this->addFieldMapping('field_webform_school', 'title');
    $this->addFieldMapping('data_location_name', 'location_name');
    $this->addFieldMapping('data_street', 'street');
    $this->addFieldMapping('data_additional', 'additional');
    $this->addFieldMapping('data_country', 'country');
    $this->addFieldMapping('data_longitude', 'longitude');
    $this->addFieldMapping('data_latitude', 'latitude');
    $this->addFieldMapping('data_how_many_pieces_of_sports_equipment_did_you_collect', 'field_campaign_pieces');
    $this->addFieldMapping('data_what_awesome_things_did_you_do_to_make_your_drive_particularly_successful', 'field_campaign_essay');
    $this->addFieldMapping('data_anything_else_we_should_know_about_your_sports_equipment_drive_project', 'field_anything_else');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures');
    $this->addFieldMapping('data_short_url', 'field_short_url');
    $this->addFieldMapping('data_votes', 'field_votes');
    $this->addFieldMapping('data_total_votes', 'field_total_votes');


    //Null Mappings
    $this->addUnmigratedSources(array('locations'));
    $this->addUnmigratedDestinations(array(
      'data_location',
      'field_webform_email',
      'field_webform_mobile',
      'field_webform_videos',
      'taxonomy_vocabulary_5'
    ));
  }
  public function prepareRow($row) {
    // Extract the location from the location:
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    $row->location_name = empty($location->name) ? NULL : $location->name;
    $row->country = empty($location->country) ? NULL : $location->country;
    $row->street = empty($location->street) ? NULL : $location->street;
    $row->additional = empty($location->additional) ? NULL : $location->additional;
    $row->latitude = empty($location->latitude) ? NULL : $location->latitude;
    $row->longitude = empty($location->longitude) ? NULL : $location->longitude;
    if (is_array($row->field_participant_emails)) {
      $row->field_participant_emails = implode("\n", $row->field_participant_emails);
    }
  }
}

class DSCampaignReportBackBullying extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['postal_code'] = 'Postal Code';
    parent::__construct('campaign_bully_2011', $fields);
    $this->description .= 'Campaign Project - Bullying 2011';

    $this->addFieldMapping('data_postal_code', 'postal_code');
    $this->addFieldMapping('data_what_did_you_do_to_step_up_to_bullying', 'body');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures');

    //Null Mappings
    $this->addUnmigratedSources(array('locations', 'title', 'format', 'teaser'));
    $this->addUnmigratedDestinations(array(
      'data_location',
      'field_webform_email',
      'field_webform_mobile',
      'taxonomy_vocabulary_5',
      'field_webform_school_zip',
      'field_webform_school',
    ));
  }
  public function prepareRow($row) {
    // Extract the location from the location:
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    $row->postal_code = empty($location->postal_code) ? NULL : $location->postal_code;
  }
}

class DSCampaignReportBackMacys2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['country'] = 'Country';
    $fields['location_name'] = 'Location Name';
    $fields['street'] = 'Street';
    $fields['additional'] = 'Additional';
    $fields['longitude'] = 'Longitude';
    $fields['latitude'] = 'Latitude';
    parent::__construct('campaign_macys_2011', $fields);
    $this->description .= 'Campaign Project - Macys Membership 2011';

    $this->addFieldMapping('field_webform_videos', 'field_campaign_video');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures');
    $this->addFieldMapping('data_location_name', 'location_name');
    $this->addFieldMapping('data_street', 'street');
    $this->addFieldMapping('data_additional', 'additional');
    $this->addFieldMapping('data_country', 'country');
    $this->addFieldMapping('data_longitude', 'longitude');
    $this->addFieldMapping('data_latitude', 'latitude');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('data_your_name', 'title');
    $this->addFieldMapping('data_tell_us_more_about_how_you_completed_the_project', 'field_campaign_essay_how');
    $this->addFieldMapping('data_how_many_people_were_involved_in_completing_the_project', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_why_is_taking_action_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_what_was_the_biggest_challenge_you_faced', 'field_campaign_essay_challenge');
    $this->addFieldMapping('data_do_you_plan_on_doing_this_campaign_again_next_year', 'field_campaign_next_year_yesno');
    $this->addFieldMapping('data_why_or_why_not', 'field_campaign_why_participate');

    //Null Mappings
    $this->addUnmigratedSources(array('locations'));
    $this->addUnmigratedDestinations(array(
      'data_location',
      'field_webform_mobile',
      'taxonomy_vocabulary_5',
      'field_webform_school_zip',
      'field_webform_school',
      'data_share_more_optional',
    ));
  }
  public function prepareRow($row) {
     // Extract the location from the location:
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    $row->location_name = empty($location->name) ? NULL : $location->name;
    $row->country = empty($location->country) ? NULL : $location->country;
    $row->street = empty($location->street) ? NULL : $location->street;
    $row->additional = empty($location->additional) ? NULL : $location->additional;
    $row->latitude = empty($location->latitude) ? NULL : $location->latitude;
    $row->longitude = empty($location->longitude) ? NULL : $location->longitude;
  }
}

class DSCampaignReportBackEWaste2011Migration extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['country'] = 'Country';
    $fields['location_name'] = 'Location Name';
    $fields['street'] = 'Street';
    $fields['additional'] = 'Additional';
    $fields['longitude'] = 'Longitude';
    $fields['latitude'] = 'Latitude';
    parent::__construct('campaign_ew_2011', $fields);
    $this->description .= 'Campaign Project - ewaste 2011';

    $this->addFieldMapping('field_webform_videos', 'field_campaign_video_single');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures');
    $this->addFieldMapping('data_location_name', 'location_name');
    $this->addFieldMapping('data_street', 'street');
    $this->addFieldMapping('data_additional', 'additional');
    $this->addFieldMapping('data_country', 'country');
    $this->addFieldMapping('data_longitude', 'longitude');
    $this->addFieldMapping('data_latitude', 'latitude');
    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone');
    $this->addFieldMapping('data_name', 'title');
    $this->addFieldMapping('field_webform_school', 'field_project_name');
    //$this->addFieldMapping('data_drive_or_school_name', 'field_project_name');
    $this->addFieldMapping('data_how_many_people_involved', 'field_num_people_involved');
    $this->addFieldMapping('data_zip_code', 'field_zip_campaign');
    $this->addFieldMapping('data_number_of_items_you_dropped_off', 'field_ewaste_items_collected');
    $this->addFieldMapping('data_best_buy_store_number_and_address', 'field_ewaste_bestbuy');
    $this->addFieldMapping('data_what_impact_did_your_drive_have_on_your_community', 'field_campaign_essay_how');
    $this->addFieldMapping('data_what_did_you_learn_from_your_drive_and_why_is_recycling_electronics_so_important_to_you', 'field_campaign_essay_why');
    $this->addFieldMapping('data_anything_else_we_should_know', 'field_campaign_anything_else');
    $this->addFieldMapping('data_age', 'field_project_age');
    $this->addFieldMapping('data_what_awesome_things_did_you_do_to_plan_and_promote_your_drive_that_made_it_super_successful', 'field_campaign_essay');

    //Null Mappings
    $this->addUnmigratedSources(array('locations'));
    $this->addUnmigratedDestinations(array(
      'data_location',
      'taxonomy_vocabulary_5',
      'field_webform_school_zip',
      'field_webform_email',
    ));
  }
  public function prepareRow($row) {
     // Extract the location from the location:
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    $row->location_name = empty($location->name) ? NULL : $location->name;
    $row->country = empty($location->country) ? NULL : $location->country;
    $row->street = empty($location->street) ? NULL : $location->street;
    $row->additional = empty($location->additional) ? NULL : $location->additional;
    $row->latitude = empty($location->latitude) ? NULL : $location->latitude;
    $row->longitude = empty($location->longitude) ? NULL : $location->longitude;
  }
}

class DSCampaignReportBackCancer2011 extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields['country'] = 'Country';
    $fields['location_name'] = 'Location Name';
    $fields['street'] = 'Street';
    $fields['additional'] = 'Additional';
    $fields['longitude'] = 'Longitude';
    $fields['latitude'] = 'Latitude';
    parent::__construct('campaign_cancer_2011', $fields);
    $this->description .= 'Campaign Project -Give a Spit about Cancer 2011';

    $this->addFieldMapping('data_how_many_new_donors_did_you_get_to_give_a_spit_by_joining_the_marrow_donor_registry', 'field_cancer_donors');
    $this->addFieldMapping('data_how_many_volunteers_helped_organize_your_drive', 'field_cancer_volunteers');
    $this->addFieldMapping('data_location_name', 'location_name');
    $this->addFieldMapping('data_street', 'street');
    $this->addFieldMapping('data_additional', 'additional');
    $this->addFieldMapping('data_country', 'country');
    $this->addFieldMapping('data_longitude', 'longitude');
    $this->addFieldMapping('data_latitude', 'latitude');
    $this->addFieldMapping('data_anything_else_you_want_to_tell_us_about_your_drive', 'field_cancer_anythingelse');
    $this->addFieldMapping('field_webform_pictures', 'field_campaign_pictures');
    $this->addFieldMapping('field_webform_videos', 'field_campaign_video');
    $this->addFieldMapping('field_webform_email', 'field_cancer_email');
    $this->addFieldMapping('field_webform_school', 'title');
    // $this->addFieldMapping('data_what_awesome_things_did_you_do_to_plan_and_promote_your_drive_that_made_it_super_successful', 'field_campaign_essay');

    //Null Mappings
    $this->addUnmigratedSources(array('locations', 'field_embedded_video'));
    $this->addUnmigratedDestinations(array(
      'data_location',
      'taxonomy_vocabulary_5',
      'field_webform_school_zip',
      'field_webform_mobile',
    ));
  }
  public function prepareRow($row) {
     // Extract the location from the location:
    $location = isset($row->locations[0]) ? $row->locations[0] : NULL;
    parent::prepareRow($row);
    $row->location_name = empty($location->name) ? NULL : $location->name;
    $row->country = empty($location->country) ? NULL : $location->country;
    $row->street = empty($location->street) ? NULL : $location->street;
    $row->additional = empty($location->additional) ? NULL : $location->additional;
    $row->latitude = empty($location->latitude) ? NULL : $location->latitude;
    $row->longitude = empty($location->longitude) ? NULL : $location->longitude;
    $row->field_campaign_video = empty($location->field_embedded_video) ? $row->field_campaign_video : $row->field_campaign_video + $row->field_embedded_video;
  }
}

class DSCampaignReportBackGYS2012 extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields = array();
    parent::__construct('campaign_gys_2012', $fields);
    $this->description .= 'Campaign Project - Green Your School 2012';

    $this->addFieldMapping('data_field_campaign_number_of_people', 'field_campaign_number_of_people');
    $this->addFieldMapping('data_what_did_you_do_tell_us_in_your_school_blog', 'field_further_description_title');
    $this->addFieldMapping('field_webform_pictures', 'field_picture');
    $this->addFieldMapping('field_webform_school', 'title');
    $this->addFieldMapping('data_check_off_the_projects_below_that_your_school_has_completed', 'field_gys_projects');
  }
  public function prepareRow($row) {
    $projects_mapping = array(
      'Recycling' => 1,
      'Collect and recycle at least 25 plastic or glass bottles or aluminum cans' => 2,
      'Ask your principle to put recycle bins in classrooms' => 3,
      'Use bright colors and eye catching designs to draw attention to recycle bins' => 4,
      'Create and post posters at home or at school to remind family and friends to recycle' => 5,
      'Organize an in-home recycling center and teach your family how to use it. Have separate bins for glass, plastics, and newspaper/cardboard' => 6,
      'Make a T-shirt with a recycling fact (or facts) on it, wear it to school and be ready to answer questions' => 7,
      'Write an essay about a positive impact recycling can bring your community; submit it to your school or local newspaper' => 8,
      'Once you are done perusing your favorite magazine, recycle it. Collect and recycle at least 5 magazines' => 9,
      'Create an infographic of visual representation of a topic related to recycling or the recycling process; present it to your science class or post it in your school' => 10,
      'Grab your friends and gather recyclables from a public space. Make sure everything that you pick up ends up in the right bag' => 11,
      'Energy' => 12,
      'Talk to your school administration about adopting energy-saving practices' => 13,
      'Encourage your school to become an ENERGY STAR Partner' => 14,
      'Educate your friends and younger siblings about energy efficiency' => 15,
      'Create a club that takes action around saving energy' => 16,
      'Encourage your school to put all computers in energy-saving sleep mode' => 17,
      'Explain energy-efficient lighting to your class' => 18,
      'Have teachers and students unplug chargers when devices are finished charging' => 19,
      'Teach your class how to save energy and money on the family utility bill' => 20,
      'Encourage your school to fix leaky faucets and toilets to save gallons of water' => 21,
      'Set up a carpool to school' => 22,
      'Host a lights-out day at your school, and then have people pledge to do the same at home' => 23,
      'Encourage your school to install motion sensor lights' => 24,
      'Sign the ENERGY STAR pledge' => 25,
      'Green Agriculture' => 26,
      'Start a garden and grow produce for healthy eating' => 27,
      'For school dances rent potted plants, they are reusable and aren’t shipped around the world' => 28,
      'Start a school compost' => 29,
      'Host locally-grown snack stands at your school event' => 30,
      'Rearrange your cafeteria to feature local and fresh foods' => 31,
      'Encourage natural plant species to grow in your backyard' => 32,
      'Bring It Home' => 33,
      'Turn off electronics, lights, and fans when you leave the room' => 34,
      'Unplug your electronics when you’re not using them' => 35,
      'Use the sleep setting on your computer' => 36,
      'Walk, ride a bike, or skateboard instead of using a car' => 37,
      'Talk to your family about energy-saving driving habits' => 38,
      'Keep doors and windows closed when the air conditioning or heat is on' => 39,
      'Weatherstrip air leaks around windows and doors' => 40,
      'Replace your home’s HVAC filters at least every 3 months' => 41,
      'Set your thermostat to save energy' => 42,
      'Host a clothing swap with friends' => 43,
      'Encourage your family to reduce, reuse, recycle and recover around the house' => 44,
      'Plant a rain garden at home, school or another location' => 45,
      'Challenge your family to conserve water at home' => 46,
      'Buy ENERGY STAR qualified electronics, lighting, and other products' => 47,
      'Post home energy-saving tips through social media' => 48,
      'Other' => 49,
      'Green your prom or other school dance' => 50,
      'Start a blog or video blog about the environment' => 51,
      'Make beeswax candles instead of using candles made from oil' => 52,
      'Host a poetry slam that focuses on the environment.' => 53,
      'Green the school art room' => 54,
    );
    $projects_field = array();
    foreach ($row->field_gys_projects as $project) {
      $projects_field[] = $projects_mapping[$project];
    }
    $row->field_gys_projects = $projects_field;
  }

}

class DSCampaignReportBackTrashy2011 extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields = array();
    //$fields['field_webform_geocode_zip_code'] = 'field_webform_geocode_zip_code';
    parent::__construct('campaign_trashy_2011', $fields);
    $this->description .= 'Campaign Project - Trashy 2011';

    $this->addFieldMapping('data_first_name', 'field_first_name');
    $this->addFieldMapping('data_last_name', 'field_name_l');
    $this->addFieldMapping('field_webform_email', 'field_email_1');
    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone');
    $this->addFieldMapping('data_select_the_stat_you_shared', 'field_dbt_which_stat');
    $this->addFieldMapping('data_how_many_facebook_friends_do_you_have', 'field_number_of_friends');
    $this->addFieldMapping('data_select_the_project_you_completed', 'field_dbt_project_name');
    $this->addFieldMapping('data_anything_else_you_want_to_tell_us_about_your_shared_stat_or_project', 'field_dbt_anything_else');
    $this->addFieldMapping('data_how_many_people_were_involved_in_your_project', 'field_dbt_project_number');

    $this->addFieldMapping('field_webform_pictures', 'field_trashy_img')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

  }
  public function prepareRow($row) {
    $statmap = array(
      'Cat #1' => 1,
      'Text #1' => 2,
      'Cat #2' => 3,
      'Text #2' => 4,
    );
    $row->field_dbt_which_stat = isset($row->field_dbt_which_stat) ? $statmap[$row->field_dbt_which_stat] : NULL;
  }
  public function prepare($entity, $row) {
  }
}

class DSCampaignReportBackCampaignBfb2012 extends DSCampaignReportBackMigration {
  public function __construct() {
    $fields = array();
    parent::__construct('campaign_bfb_2012', $fields);
    $this->description .= 'Campaign Project - Battle for the Bands 2012';

    $this->addFieldMapping('data_school', 'title');
    $this->addFieldMapping('data_first_name', 'field_bfb_name');
    $this->addFieldMapping('data_last_name', 'field_bfb_lastname');
    $this->addFieldMapping('data_team_name', 'field_bfb_team');
    $this->addFieldMapping('data_city', 'field_bfb_city');
    $this->addFieldMapping('data_state', 'field_state');
    $this->addFieldMapping('data_what_kinwhat_kind_of_video_are_you_submittingd_of_video_are_you_submitting', 'field_bfb_video');
    $this->addFieldMapping('data_email_addresses_of_other_people_in_your_video', 'field_bfb_emails');
    $this->addFieldMapping('data_why_is_music_education_important_to_you', 'field_bfb_education');
    $this->addFieldMapping('data_how_did_your_video_come_together', 'field_bfb_together');
    $this->addFieldMapping('data_what_was_the_biggest_challenge', 'field_bfb_challenge');
    $this->addFieldMapping('field_webform_videos', 'field_video')
      ->arguments(array('file_function' => 'file_fid'));

    $this->addUnmigratedSources(array('locations'));
    $this->addUnmigratedDestinations(array(
      'data_almost_done_just_a_few_more_questions',
      'field_webform_email',
      'field_webform_mobile',
      'field_webform_school_zip',
      'field_webform_pictures',
      'field_webform_school',
      'taxonomy_vocabulary_5',
      'field_geocode_data',
    ));
  }

  public function prepareRow($row) {
  }

  public function prepare($entity, $row) {
  }
}
