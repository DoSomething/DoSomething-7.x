<?php

// Scholarship Application

abstract class DSScholarshipApplicationMigration extends DSJsonNodeMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('ScholarshipApplication'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
  }
}


class DSScholarshipApplicationGeneralMigration extends DSScholarshipApplicationMigration {
  public function __construct($webform) {
    parent::__construct('general_scholarship_app');
    $this->description = 'General Scholarship Application';
    // $this->addFieldMapping('name', 'field_name');
    // $this->addFieldMapping('school', 'field_plumgrant_highschool');
    // $this->addFieldMapping('email', 'field_email');
    // $this->addFieldMapping('mobile', 'field_phone_number');
    // $this->addFieldMapping('zip', 'field_zip_code_2');

    $this->addFieldMapping('data_how_did_you_hear_about_this_opportunity', 'field_how_did_you_hear_about_bo');
    $this->addFieldMapping('data_what_causes_or_issues_are_you_most_passionate_about_and_why', 'field_what_causes_or_issues_are');
    $this->addFieldMapping('data_how_have_you_gotten_involved_with_your_causes_what_leadership_roles_have_you_taken_on', 'field_what_activities_have_you_');
    $this->addFieldMapping('data_what_are_your_future_plans_for_your_community_service_projects_and_goals_for_your_education', 'field_what_are_your_future_plan');
    $this->addFieldMapping('data_recommenders_name', 'field_recommenders_name_0');
    $this->addFieldMapping('data_recommenders_phone_number', 'field_recommenders_phone_numb_0');
    $this->addFieldMapping('data_recommenders_email', 'field_recommenders_email_0');
    $this->addFieldMapping('data_recommenders_relationship_to_you', 'field_recommenders_relationsh_0');
    $this->addFieldMapping('data_application_complete', 'field_application_complete');     // TODO: select field
  }
}

class DSScholarshipApplicationAttMigration extends DSScholarshipApplicationMigration {
  public function __construct() {
    parent::__construct('scholarships_att');
    $this->description = 'Scholarships ATT';

    $this->addFieldMapping('data_why_you_should_be_chosen', 'field_scholarship_att_whyyou');
    $this->addFieldMapping('data_whats_your_favorite_song_to_rock_out_to', 'field_scholarship_att_song');
    $this->addFieldMapping('data_whos_your_celebrity_crush', 'field_scholarship_att_crush');
    $this->addFieldMapping('data_who_can_we_contact_for_a_recommendation', 'field_scholarship_att_rec');
  }
}

class DSScholarshipApplicationSixFlagsMigration extends DSScholarshipApplicationMigration {
  public function __construct() {
    parent::__construct('sixflags_scholarships_app');
    $this->description = 'Six Flags Friends Scholarships';

    $this->addFieldMapping('data_what_causes_or_issues_are_you_most_passionate_about_and_why', 'field_what_causes_or_issues_are');
    $this->addFieldMapping('data_how_have_you_gotten_involved_with_your_causes_what_leadership_roles_have_you_taken_on', 'field_what_activities_have_you_');
    $this->addFieldMapping('data_what_are_your_future_plans_for_your_community_service_projects_and_goals_for_your_education', 'field_what_are_your_future_plan');
    $this->addFieldMapping('data_why_do_you_think_its_important_for_young_people_to_get_involved_with_issues_that_affect_their_communities_and_the_world', 'field_why_do_you_think_its_impo');
    $this->addFieldMapping('data_this_ones_easy_what_do_you_do_for_fun', 'field_this_ones_easy_what_do_yo');
    $this->addFieldMapping('data_recommenders_name', 'field_recommenders_name_0');
    $this->addFieldMapping('data_recommenders_phone_number', 'field_recommenders_phone_numb_0');
    $this->addFieldMapping('data_recommenders_email', 'field_recommenders_email_0');
    $this->addFieldMapping('data_recommenders_relationship_to_you', 'field_recommenders_relationsh_0');
  }
}