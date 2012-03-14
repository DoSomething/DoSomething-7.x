<?php

/**
 * This is the first activity in any workflow.
 */
class ConductorActivityDSCreateReportBack extends ConductorActivity {

  // This is the nid of the webform node that all project reports should
  // be associated with.
  const REPORT_BACK_NID = 718313;

  public function option_definition() {
    $options = parent::option_definition();
    // The attribute to set in context.
    return $options;
  }

  /**
   * Create a user object from the context built up during this workflow run.
   */
  public function run() {
    $state = $this->getState();

    $mobile = $state->getContext('sms_number');

    $userAccountFound = FALSE;

    // If we have a user with this mobile, lets update their info.
    $state->markCompeted();
    $account = dosomething_sms_load_user_by_cell($mobile);

    // If we haven't found an account, let's create one.
    if (!$account) {
      $account = new stdClass;
      $account->name = $mobile;

      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($account->name)) {
        $suffix++;
        $account->name = $base_name . '-' . $suffix;
      }
      $account->mail = $mobile . '@mobile';
      $account->status = 1;
      user_save($account);

      $profile_values = array(
        'type' => 'main',
        'field_user_mobile' =>  array(
          LANGUAGE_NONE => array(
            array(
              'value' => $mobile,
            ),
          ),
        ),
      );
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      profile2_save($profile);
    }

    $submission = new stdClass;
    $submission->bundle = 'project_report';
    // Always use the project report webform.
    $submission->nid = self::REPORT_BACK_NID;
    $submission->data = array();
    $submission->uid = $account->uid;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = TRUE;
    $submission->sid = NULL;

    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);

    $wrapper->field_project_title->set($state->getContext('title:message'));
    $wrapper->field_project_goal->set($state->getContext('goal:message'));
    $wrapper->field_update_people_involved->set($state->getContext('involved:message'));
    $wrapper->field_num_people_impacted->set($state->getContext('helped:message'));
    if ($userAccountFound) {
      $state->setContext('sms_response', t('Thanks!  We are thrilled to hear about your project!'));
    }
    else {
      $state->setContext('sms_response', t('Thanks!  We\'d love to learn more about your, to register text ZIVTECH to 38383!'));
    }

    $wrapper->save();

    $state->markCompeted();
  }

}
