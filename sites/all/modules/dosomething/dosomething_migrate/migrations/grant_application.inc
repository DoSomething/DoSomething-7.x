<?php

// Grant Application

abstract class DSGrantApplicationMigration extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('GrantApplication'), $node_type);
    $this->addUnmigratedSources(array('changed', 'status'));
    $this->addUnmigratedDestinations(array('field_webform_geocode_address', 'field_webform_geocode_zip_code'));
  }

  public function prepareRow($row) {
    // There's a lot of garbage in the date fields. Excude anything that doesn't
    // have a number (other than zero to filter out 0/0/0) and some kind of
    // separator.
    foreach (array('field_birthdate', 'field_project_date') as $field) {
      if (!empty($row->$field)) {
        // TODO: Check that this actually works with pre-1970 birthdays...
        if (preg_match('![1-9]+[- ,\.\/]!', $row->$field) && ($timestamp = strtotime($row->$field))) {
          $row->$field = $timestamp;
        }
        else {
var_dump($field, "Could not parse!", $row->$field);
          $row->$field = NULL;
        }
      }
    }
  }
}


class DSGrantApplicationAspcaMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('aspca_grant_app');
    $this->description .= 'ASPCA Grant App';
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
    $this->addFieldMapping('data_legal_1', 'field_legal_1_0')
      ->description('Keys is Boolean in integer (0/1).');
    $this->addFieldMapping('data_legal_2', 'field_legal_2_0')
      ->description('Keys is Boolean in integer (0/1).');
    $this->addFieldMapping('data_legal_3', 'field_legal_3_0')
      ->description('Keys is Boolean in integer (0/1).');
    $this->addFieldMapping('data_legal_4', 'field_legal_4')
      ->description('Keys is Boolean in integer (0/1).');

#    $this->addFieldMapping('field_webform_birthdate', '');
    $this->addAddressFieldMapping('field_webform_address', NULL, array(
      'thoroughfare'            => 'field_your_address', # Node: Your Address (text)
      'locality'                => 'field_city_0', # Node: City (text)
      'administrative_area'     => 'field_state_plain', # Node: State (text)
      'postal_code'             => 'field_zip_code_0', # Node: Zip Code (text)
    ))->defaultValue('US');
    $this->addFieldMapping('field_webform_email', 'field_your_email_address');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number_1');
    $this->addFieldMapping('field_webform_name', 'field_your_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_your_do_something_project');
    $this->addFieldMapping('field_webform_project_dates', 'field_project_dates');
    $this->addFieldMapping('field_webform_project_summary', 'field_description');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_youtube_or_video_url');
    $this->addFieldMapping('data_username', 'title');
    $this->addFieldMapping('data_your_high_school', 'field_your_high_school');
    $this->addFieldMapping('data_your_college_if_applicable', 'field_your_college_if_applica_0');

    //Null Mappings
    //$this->addUnmigratedSources(array(''));
    $this->addUnmigratedDestinations(array('data_how_did_you_hear_about_us', 'data_birth_date', 'data_school', 'data_school_zip_code', 'field_webform_birthdate', 'field_webform_school', 'field_webform_school_zip'));
  }
}

class DSGrantApplicationGeneralMigration extends DSGrantApplicationMigration {
  public function __construct() {
   parent::__construct('general_grant_app');
    $this->description .= 'General Grant Application';
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
    $this->addFieldMapping('data_is_this_application_complete', 'field_application_status')
      ->description('Select field keys are unchanged.');

    $this->addFieldMapping('field_webform_birthdate', 'field_birthdate');
    $this->addAddressFieldMapping('field_webform_address', NULL, array(
      'thoroughfare'            => 'field_plumgrant_address',
      'locality'                => 'field_city_1',
      'administrative_area'     => 'field_state_plain',
      'postal_code'             => 'field_zip_code_2',
    ))->defaultValue('US');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number_1');
    $this->addFieldMapping('field_webform_name', 'field_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_project');
    $this->addFieldMapping('field_webform_project_dates', 'field_project_date');
    $this->addFieldMapping('field_webform_project_summary', 'field_description');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_plumgrant_videourl');
    $this->addFieldMapping('data_email', 'title');
    $this->addFieldMapping('data_your_high_school', 'field_plumgrant_highschool');
    $this->addFieldMapping('data_your_college_if_applicable', 'field_your_college_if_applicabl');
  
    //Null Mappings
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));
  }
}

class DSGrantApplicationGrantMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant');
    $this->description .= 'Grant';
    $this->addFieldMapping('data_your_facebook_page_url', 'field_your_facebook_page_url');
    $this->addFieldMapping('data_your_twitter_handle', 'field_your_twitter_handle');
    $this->addFieldMapping('data_principal_deans_name', 'field_your_school_deans_name');
    $this->addFieldMapping('data_principal_deans_email', 'field_deans_email_0');
    $this->addFieldMapping('data_principal_deans_phone_number', 'field_deans_phone_number_0');
    $this->addFieldMapping('data_which_grant_are_you_applying_for', 'field_which_grant')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_you_are_applying_as', 'field_you_are_applying_as')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_other_group_members_emails', 'field_other_group_members_email');
    $this->addFieldMapping('data_how_did_you_hear_about_this_grant', 'field_how_did_you_hear_about_bo')
      ->arguments(array('source_type' => 'value'));
    $this->addFieldMapping('data_how_many_people_are_directly_involved_in_your_project', 'field_num_people_involved');
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
    $this->addFieldMapping('data_is_this_application_complete', 'field_application_status')
      ->description('Select field keys are unchanged.');

    $this->addFieldMapping('field_webform_birthdate', 'field_recipient_birthdate');
    $this->addAddressFieldMapping('field_webform_address', NULL, array(
      'thoroughfare'            => 'field_address',
      'locality'                => 'field_city',
      'administrative_area'     => 'field_state',
      'postal_code'             => 'field_zip_code_3',
    ))->defaultValue('US');
    $this->addFieldMapping('field_webform_email', 'field_email');
    $this->addFieldMapping('field_webform_mobile', 'field_phone_number');
    $this->addFieldMapping('field_webform_name', 'field_name');
    $this->addFieldMapping('field_webform_photo_url', 'field_photo_album_url');
    $this->addFieldMapping('field_webform_project', 'field_your_project');
    $this->addFieldMapping('field_webform_project_dates', 'field_project_date');
    $this->addFieldMapping('field_webform_project_summary', 'field_describe');
    $this->addFieldMapping('field_webform_project_website', 'field_personal_project_website');
    $this->addFieldMapping('field_webform_video_url', 'field_youtube_or_video_url');
    $this->addFieldMapping('data_please_submit_a_budget_detailing_how_you_would_use_the_grant_money', 'field_budget_0');
    $this->addFieldMapping('data_high_school', 'field_plumgrant_highschool');
    $this->addFieldMapping('data_college_if_applicable', 'field_your_college_if_applicabl');
    $this->addFieldMapping('data_where_did_you_hear_about_us', 'field_where_did_you_hear');
  
    //Null Mappings
    $this->addUnmigratedSources(array('title'));
    $this->addUnmigratedDestinations(array('field_webform_school', 'field_webform_school_zip'));
  }
}
/*
class DSGrantApplicationGrantJudgeMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant_judge');
    $this->description .= 'Grant Judging Form';
  }
}
*/
