<?php

// Campaign Signup

abstract class DSCampaignSignupMigration extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('CampaignSignup'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
    $this->addUnmigratedDestinations(array('field_webform_geocode_zip_code'));
  }

  public function prepareRow($row) {
    // Extract the zip code from the location:
    $row->locations = empty($row->locations[0]->postal_code) ? NULL : $row->locations[0]->postal_code;
  }
}


class DSCampaignSignupEbdMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('ebd_signup');
    $this->description .= 'Epic Book Drive Signup';

    $this->addFieldMapping('data_how_many_boxes_of_books_do_you_plan_to_collect_35_books_in_a_box', 'field_what_is_your_goal_number_');
    $this->addFieldMapping('data_school', 'title');
    $this->addFieldMapping('data_how_will_you_make_your_book_drive_epic', 'body');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_mobile', 'field_webform_school', 'field_webform_school_zip'));
    $this->addUnmigratedSources(array('format', 'teaser'));

  }
}

class DSCampaignSignupGysMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('gys_2011');
    $this->description .= 'Green Your School 2011';

    $this->addFieldMapping('data_how_will_you_green_your_school', 'body');
    $this->addUnmigratedSources(array('format', 'teaser'));
    $this->addFieldMapping('data_great_school_id', 'field_great_schools_id');
    $this->addFieldMapping('data_school', 'title');

    $this->addFieldMapping('field_webform_school_zip', 'locations')
      ->description('Pulling the zip code out of the locations in prepareRow()');

    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_mobile', 'field_webform_school', 'field_webform_school_zip'));
  }
}

class DSCampaignSignupHealthySchoolsMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('healthy_schools');
    $this->description .= 'Healthy Schools';

    $this->addFieldMapping('data_school_organization_name', 'field_campaign_school');
    $this->addFieldMapping('data_how_many_people_are_you_working_with', 'field_healthy_schools_team');
    $this->addFieldMapping('data_whatcha_doin', 'field_campaign_essay');
    $this->addFieldMapping('data_school_organization_name', 'field_campaign_school');
    $this->addFieldMapping('data_how_did_you_hear_about_us', 'vocab_15');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_mobile', 'field_webform_school', 'field_webform_school_zip'));
  }
}

class DSCampaignSignupIncreaseYourGreenMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('increaseyourgreen_signup');
    $this->description .= 'Increase Your Green Signup';

    $this->addFieldMapping('data_your_name', 'field_increaseyourgreen_signup_');
    $this->addFieldMapping('data_city', 'field_city');
    $this->addFieldMapping('data_state', 'field_state_plain');
    $this->addFieldMapping('data_student_leader_phone', 'field_student_leader_phone');
    $this->addFieldMapping('data_student_leader_email', 'field_student_leader_email');
    $this->addFieldMapping('data_student_leader_contact_name_if_other_than_yourself', 'field_student_leader');
    $this->addFieldMapping('data_your_schools_phone_number', 'field_increaseyourgreen_signu_2');
    $this->addFieldMapping('data_your_schools_address', 'field_increaseyourgreen_signu_3');
    $this->addFieldMapping('data_actions_planned_and_or_taken', 'field_increaseyourgreen_signu_4');
    $this->addFieldMapping('data_how_did_you_hear_about_increase_your_green', 'field_increaseyourgreen_signu_5');
    $this->addFieldMapping('data_waste_metrics_how_did_your_school_measure_the_waste_reduced_recycled_and_reused', 'field_iyg_waste_metrics');
    $this->addFieldMapping('data_what_were_the_results_list_these_numbers_and_other_specific_results_of_your_efforts', 'field_iyg_waste_metric_2');
    $this->addFieldMapping('data_about_how_many_people_total_did_you_involve_in_your_8_week_increase_your_green_efforts', 'field_iyg_people');
    $this->addFieldMapping('data_what_was_your_footprint_at_the_beginning_of_the_competition_10_13', 'field_iyg_footprint_start');
    $this->addFieldMapping('data_what_was_your_footprint_at_the_end_of_the_competition_12_8', 'field_iyg_footprint_end');
    $this->addFieldMapping('data_how_did_your_school_save_energy_answer_all_parts_of_question_below', 'field_iyg_energy_saved');
    $this->addFieldMapping('data_how_did_you_measure_your_energy_saved_what_numbers_did_you_use_to_keep_track_of_your_progress', 'field_iyg_energy_metrics');
    $this->addFieldMapping('data_innovation_let_us_know_why_your_efforts_were_unique__how_you_improved_on_whats_been_done_before', 'field_iyg_innovation');
    $this->addFieldMapping('data_anything_else_we_should_know_fill_us_in', 'field_iyg_other_info');
    $this->addFieldMapping('data_how_did_you_get_other_members_of_your_school_and_or_community_involved', 'field_iyg_people_engage');
    $this->addFieldMapping('data_how_did_you_spread_the_word_about_your_efforts_to_your_school_and_community', 'field_iyg_people_spread');
    $this->addFieldMapping('data_how_you_improved_your_school_what_policies_did_you_have_to_change_what_new_programs_practices_did_you_implement', 'field_iyg_waste_info');
    $this->addFieldMapping('data_your_schools_name', 'field_increaseyourgreen_signu_1');

    $this->addFieldMapping('field_webform_email', 'title');
    $this->addFieldMapping('field_webform_mobile', 'field_increaseyourgreen_signu_0');
    $this->addFieldMapping('data_how_did_you_spread_the_word_about_your_efforts_to_your_school_and_community', 'field_iyg_people_spread');
    $this->addFieldMapping('data_how_did_you_get_other_members_of_your_school_and_or_community_involved', 'field_iyg_people_engage');
    $this->addFieldMapping('data_how_you_improved_your_school_what_policies_did_you_have_to_change_what_new_programs_practices_did_you_implement', 'field_iyg_waste_info');
    $this->addFieldMapping('data_your_schools_name', 'field_increaseyourgreen_signu_1');

    //Null Mappings
    //$this->addUnmigratedSources(array(''));
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));

  }
}

class DSCampaignSignupScavengerMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('scavenger_2011_signup');
    $this->description .= 'Scavenger Hunt 2011 Signup';

    $this->addFieldMapping('data_team_name', 'title');
    $this->addFieldMapping('data_first_name', 'field_campaign_first_name');
    $this->addFieldMapping('data_last_name', 'field_campaign_last_name');
    $this->addFieldMapping('data_team_points', 'field_team_points');
    $this->addFieldMapping('data_subscriptions', 'field_hunt_subscriptions')
      ->description('Keys in select field are unchanged.');

    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone');

    //Null Mappings
    //$this->addUnmigratedSources(array(''));
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));

  }
}

class DSCampaignSignupStaplesMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('staples_2011_signup');
    $this->description .= 'Staples 2011 Signup';

    $this->addFieldMapping('data_name', 'title');
    $this->addFieldMapping('data_subscriptions', 'field_sfs_subscriptions')
      ->description('Keys in select field are unchanged.');
    $this->addFieldMapping('data_terms_and_conditions', 'field_sfs_terms')
      ->description('Keys is Boolean in integer (0/1).');

    $this->addFieldMapping('field_webform_email', 'field_campaign_email');
    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone_0');
    $this->addFieldMapping('data_school_name', 'field_school_name');

    //Null Mappings
    //$this->addUnmigratedSources(array(''));
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));

  }
}

class DSCampaignSignupTackleHungerMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('tackle_hunger');
    $this->description .= 'Tackle Hunger';

    $this->addFieldMapping('data_how_many_pounds_of_food_do_you_hope_to_raise', 'field_tackle_hunger_expected_lb');
    $this->addFieldMapping('data_number_of_people_participating_in_the_drive', 'field_cannedfood_studentsinvolv');
    $this->addFieldMapping('data_city', 'field_campaign_city');
    $this->addFieldMapping('data_state', 'field_campaign_state_0');
    $this->addFieldMapping('data_text_me_a_reminder', 'field_campaign_cell_reminder')
      ->description('Keys is Boolean in integer (0/1).');

    $this->addFieldMapping('field_webform_mobile', 'field_campaign_phone');
    $this->addFieldMapping('data_school_group_name', 'field_campaign_group');
    $this->addFieldMapping('data_zip_code', 'field_campaign_zip');

    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_email', 'field_webform_school', 'field_webform_school_zip'));
  }
}
