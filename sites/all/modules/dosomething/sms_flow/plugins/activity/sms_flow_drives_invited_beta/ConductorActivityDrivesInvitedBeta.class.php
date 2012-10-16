<?php

/**
 * Activity to process persons invited to a drive. Joins person into the
 * drive, and then sends a positive feedback sms to the person who invited them.
 * Also acts like an sms_prompt activity, suspending and waiting for a response before
 * before continuing on to the next activity.
 */
class ConductorActivityDrivesInvitedBeta extends ConductorActivity {

  // Mobile Commons campaign id to place alpha user in when sending feedback message
  public $alpha_campaign_id = 0;

  // Message returned upon successful join into a club
  public $success_message = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['alpha_campaign_id'] = array('default' => '');
    $options['success_message'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();

    if ($state->getContext($this->name . ':message') === FALSE) {

      $mobile = $state->getContext('sms_number');
      $name = $state->getContext('ask_name:message');

      // If we have a user with this mobile, update their info.
      $account = dosomething_general_find_user_by_cell($mobile);

      // Create account for this user if none is found
      if (!$account) {
        $account = new stdClass;

        $suffix = 0;
        $account->name = $name;
        while (user_load_by_name($account->name)) {
          $suffix++;
          $account->name = $name . '-' . $suffix;
        }

        $pass = user_password(6);
        require_once('includes/password.inc');
        $hashed_pass = user_hash_password($pass);
        $account->pass = $hashed_pass;
        $account->mail = $mobile . '@mobile';
        $account->status = 1;

        $account = user_save($account);

        $profile_values = array('type' => 'main');
        $profile = profile2_create($profile_values);
        $profile->uid = $account->uid;
        
        $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;
        $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $name;

        try {
          profile2_save($profile);
        }
        catch( Exception $e ) {
        }

        $this->success_message .= t('Ur password to login and view your drive at DoSomething.org/mytfjdrive is @pass', array('@pass' => $pass));
      }

      // TODO: join beta into corresponding drive. Is it just a straight up webform submit?
      // $submission = new stdClass;
      // $submission->bundle = 'campaign_report_back';
      // $submission->nid = self::REPORT_BACK_NID;
      // $submission->data = array();
      // $submission->uid = $account->uid;
      // $submission->submitted = REQUEST_TIME;
      // $submission->remote_addr = ip_address();
      // $submission->is_draft = FALSE;
      // $submission->sid = NULL;

      // $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
      // $wrapper->value()->data[1]['value'][0] = $first_name;

      // $wrapper->save();
      
      // Send feedback message to Alpha
      $alphaMobile = sms_flow_find_alpha($mobile);
      if ($alphaMobile) {
        $alphaMsg = "Good news! You invited $mobile and he/she joined your drive.";
        $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
        $return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
      }

      $this->success_message .= t('Want to invite more friends? Reply back w/ their cell #s separated by commas and we\'ll send them an invite for u!');
      $state->setContext('sms_response', $this->success_message);

      $state->markSuspended();
    }
    else {
      $state->markCompleted();
    }
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}
