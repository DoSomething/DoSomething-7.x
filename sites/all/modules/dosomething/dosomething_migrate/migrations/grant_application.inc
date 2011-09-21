<?php

// Grant Application

abstract class DSGrantApplicationMigration extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('GrantApplication'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
  }
}


class DSGrantApplicationAspcaMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('aspca_grant_app');
    $this->description = 'ASPCA Grant App';
    $this->addFieldMapping('data_where_did_you_hear_about_us', 'field_where_did_you_hear');
    $this->addFieldMapping('data_essay_1_see_it', 'field_essay_see_it');
    $this->addFieldMapping('data_essay_2_believe_it', 'field_essay_believe_it');
    $this->addFieldMapping('data_essay_3_build_it', 'field_essay_build_it');
    $this->addFieldMapping('data_essay_4_next_steps', 'field_essay_next_steps');
    $this->addFieldMapping('data_500_budget', 'field_500_budget');
    $this->addFieldMapping('data_total_project_budget', 'field_total_project_budget_0');
    $this->addFieldMapping('data_recommenders_name', 'field_recommenders_name_0');
    $this->addFieldMapping('data_recommenders_relationship_to_you', 'field_recommenders_relationsh_0');
    $this->addFieldMapping('data_recommenders_phone_number', 'field_recommenders_phone_numb_0');
    $this->addFieldMapping('data_recommenders_email', 'field_recommenders_email_0');
    $this->addFieldMapping('data_legal_1', 'field_legal_1_0');
    $this->addFieldMapping('data_legal_2', 'field_legal_2_0');
    $this->addFieldMapping('data_legal_3', 'field_legal_3_0');
    $this->addFieldMapping('data_legal_4', 'field_legal_4');

#    $this->addFieldMapping('field_webform_birthdate', '');
    $this->addFieldMapping('field_webform_email', 'field_your_email_address');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number_1');
    $this->addFieldMapping('field_webform_name', 'field_your_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_your_do_something_project');
#    $this->addFieldMapping('field_webform_project_dates', '');
    $this->addFieldMapping('field_webform_project_summary', 'field_description');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_youtube_or_video_url');

  }
}

class DSGrantApplicationGeneralMigration extends DSGrantApplicationMigration {
  public function __construct() {
   parent::__construct('general_grant_app');
    $this->description = 'General Grant Application';
    $this->addFieldMapping('data_your_school_deans_name', 'field_school_deans_name');
    $this->addFieldMapping('data_deans_email', 'field_deans_email');
    $this->addFieldMapping('data_deans_phone_number', 'field_deans_phone_number');
    $this->addFieldMapping('data_where_did_you_hear_about_us', 'field_where_did_you_hear');
    $this->addFieldMapping('data_essay_1___see_it', 'field_plumgrant_essay1');
    $this->addFieldMapping('data_essay_2___believe_it', 'field_plumgrant_essay2');
    $this->addFieldMapping('data_essay_3___build_it', 'field_plumgrant_essay3');
    $this->addFieldMapping('data_essay_4___next_steps', 'field_plumgrant_essay4');
    $this->addFieldMapping('data_500_budget', 'field_budget_0');
    $this->addFieldMapping('data_recommenders_name', 'field_recommenders_name_1');
    $this->addFieldMapping('data_recommenders_email', 'field_recommenders_email_1');
    $this->addFieldMapping('data_recommenders_phone_number', 'field_recommenders_phone_numb_1');
    $this->addFieldMapping('data_recommenders_relationship_to_you', 'field_recommenders_relationsh_1');
    $this->addFieldMapping('data_recommendation', 'field_reccomendation');
    $this->addFieldMapping('data_recommendation_upload', 'field_recommendation_upload');
    $this->addFieldMapping('data_legal_1', 'field_legal_1_0');
    $this->addFieldMapping('data_legal_2', 'field_legal_2_0');
    $this->addFieldMapping('data_legal_3', 'field_legal_3_0');
    $this->addFieldMapping('data_legal_4', 'field_legal_4');
    $this->addFieldMapping('data_is_this_application_complete', 'field_application_status');

    $this->addFieldMapping('field_webform_birthdate', 'field_birthdate');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number_1');
    $this->addFieldMapping('field_webform_name', 'field_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_project');
    $this->addFieldMapping('field_webform_project_dates', 'field_project_date');
    $this->addFieldMapping('field_webform_project_summary', 'field_description');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_plumgrant_videourl');
  }
}

class DSGrantApplicationGrantMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant');
    $this->description = 'Grant';
    $this->addFieldMapping('data_your_facebook_page_url', 'field_your_facebook_page_url');
    $this->addFieldMapping('data_your_twitter_handle', 'field_your_twitter_handle');
    $this->addFieldMapping('data_principal_deans_name', 'field_your_school_deans_name');
    $this->addFieldMapping('data_principal_deans_email', 'field_deans_email_0');
    $this->addFieldMapping('data_principal_deans_phone_number', 'field_deans_phone_number_0');
    $this->addFieldMapping('data_which_grant_are_you_applying_for', 'field_which_grant');
    $this->addFieldMapping('data_you_are_applying_as', 'field_you_are_applying_as');
    $this->addFieldMapping('data_other_group_members_emails', 'field_other_group_members_email');
    $this->addFieldMapping('data_how_did_you_hear_about_this_grant', 'field_how_did_you_hear_about_bo');
    $this->addFieldMapping('data_how_many_people_are_directly_involved_in_your_project', 'field_num_people_impacted');
    $this->addFieldMapping('data_how_many_people_have_you_inspired_to_take_action', 'field_num_people_inspired');
    $this->addFieldMapping('data_how_many_people_has_your_project_helped', 'field_num_people_impacted');
    $this->addFieldMapping('data_see_it', 'field_essay_one');
    $this->addFieldMapping('data_believe_it', 'field_essay_two');
    $this->addFieldMapping('data_build_it', 'field_essay_three');
    $this->addFieldMapping('data_next_steps', 'field_essay_four');
    $this->addFieldMapping('data_grant_optional_number_1', 'field_grant_optional_number_1');
    $this->addFieldMapping('data_grant_optional_essay_1', 'field_grant_optional_essay_1');
    $this->addFieldMapping('data_recommenders_name', 'field_recommenders_name_1');
    $this->addFieldMapping('data_recommenders_email', 'field_recommenders_email_1');
    $this->addFieldMapping('data_recommenders_phone_number', 'field_recommenders_phone_numb_1');
    $this->addFieldMapping('data_recommenders_relationship_to_you', 'field_recommenders_relationsh_1');
    $this->addFieldMapping('data_recommendation', 'field_reccomendation');
    $this->addFieldMapping('data_recommendation_upload', 'field_recommendation_upload');
    $this->addFieldMapping('data_legal_1', 'field_legal_1_0');
    $this->addFieldMapping('data_legal_2', 'field_legal_2_0');
    $this->addFieldMapping('data_legal_3', 'field_legal_3_0');
    $this->addFieldMapping('data_legal_4', 'field_legal_4');
    $this->addFieldMapping('data_is_this_application_complete', 'field_application_status');

    $this->addFieldMapping('field_webform_birthdate', 'field_recipient_birthdate');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number');
    $this->addFieldMapping('field_webform_name', 'field_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_your_project');
    $this->addFieldMapping('field_webform_project_dates', 'field_project_date');
    $this->addFieldMapping('field_webform_project_summary', 'field_describe');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_youtube_or_video_url');
  }
}
/*
class DSGrantApplicationGrantJudgeMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant_judge');
    $this->description = 'Grant Judging Form';
  }
}
*/