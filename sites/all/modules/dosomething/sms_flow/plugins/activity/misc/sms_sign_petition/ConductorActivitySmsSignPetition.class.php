<?php

/**
 * Activity to handle signing of petitions via SMS.
 */
class ConductorActivitySmsSignPetition extends ConductorActivity {

  // Array of petition data sets
  public $petitions;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Verify mdata_id is supported
    $mdataID = intval($_REQUEST['mdata_id']);
    $petition = NULL;
    foreach ($this->petitions as $p) {
      if ($p['mdata_id'] == $mdataID) {
        $petition = $p;
      }
    }

    if (!$petition) {
      watchdog('sms_petition', 'Received response from an unsupported mData ID %mdata_id', array('%mdata_id' => $mdataID));
      self::selectNextOutput('end');
    }
    else {
      $userMsg = $state->getContext('sms_petition_incoming_response');

      // If there's a number in the message, then assume it's for the FTAF
      if (self::hasPhoneNumbers($userMsg)) {
        // Set values to be used by sms_flow_generic_ftaf activity
        $state->setContext('ftaf_prompt:message', $userMsg);
        $state->setContext('ftaf_beta_optin', $petition['ftaf_beta_optin']);
        $state->setContext('ftaf_id_override', $petition['nid']);

        self::selectNextOutput('sms_flow_generic_ftaf');
      }
      // TODO: if any values are invalid, give a different message instead
      elseif (!self::hasValidInfo($userMsg)) {
        // Invalid input, so end the workflow
        self::selectNextOutput('end');
      }
      else {
        // Parse message for first name and last initial
        $msgWords = explode(' ', $userMsg);
        $firstName = $msgWords[0];
        $lastName = substr($msgWords[1], 0, 1);

        $user = sms_flow_get_or_create_user_by_cell($mobile);
        if ($user) {
          // Update the user's profile
          $profile = profile2_load_by_user($user, 'main');
          if (empty($profile->field_user_first_name[LANGUAGE_NONE][0]['value'])) {
            $profile->field_user_first_name[LANGUAGE_NONE][0]['value'] = $firstName;
          }
          // Only updating profile names if current values are empty
          if (empty($profile->field_user_last_name[LANGUAGE_NONE][0]['value'])) {
            $profile->field_user_last_name[LANGUAGE_NONE][0]['value'] = $lastName;
          }
          profile2_save($profile);

          // Create and save the webform submission
          $sub = new stdClass;
          $sub->bundle = 'petition';
          $sub->nid = $petition['nid'];
          $sub->uid = $user->uid;
          $sub->submitted = REQUEST_TIME;
          $sub->remote_addr = ip_address();
          $sub->is_draft = FALSE;
          $sub->sid = NULL;

          $wrapper = entity_metadata_wrapper('webform_submission_entity', $sub);
          $wrapper->value()->field_webform_email_or_cell[LANGUAGE_NONE][0]['value'] = $mobile;
          $wrapper->value()->field_webform_first_name[LANGUAGE_NONE][0]['value'] = $firstName;
          $wrapper->value()->field_webform_last_name[LANGUAGE_NONE][0]['value'] = $lastName;
          $wrapper->value()->field_webform_petition_signature[LANGUAGE_NONE][0]['value'] = 1;
          $wrapper->save();

          // Update the petitions count
          dosomething_petitions_increment_signature_count($petition['nid']);

          // If user was invited by an Alpha, send back confirmation message
          $alphaMobile = sms_flow_find_alpha(substr($mobile, -10), $petition['nid']);
          if ($alphaMobile) {
            // TODO: get message to send to user. Send via an opt-in or send function...?
            // $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
            // sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);
            // OR (I think the opt-in would be preferred)
            // sms_mobile_commons_opt_in($alphaMobile, $optInPath);
          }

          // Setup success message upon successful FTAF
          $state->setContext('ftaf_response_success', $petition['ftaf_response_success']);

          // Prompt user for FTAF next
          self::selectNextOutput('ftaf_prompt');
        }
        else {
          // In case of error, just end the workflow
          self::selectNextOutput('end');
        }
      }
    }

    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

  /**
   * Check if the user response has valid info for us to go forward and sign the petition
   *
   * @param $msg Response string from the user
   *
   * @return TRUE if msg is fine. FALSE otherwise.
   */
  private function hasValidInfo($msg) {
    $msgWords = explode(' ', $msg);
    $firstName = $msgWords[0];
    $lastName = substr($msgWords[1], 0, 1);

    if (empty($firstName) || empty($lastName)) {
      return FALSE;
    }
    // TODO: also check for questions and other preset non-valid responses

    return TRUE;
  }

  /**
   * If there's a number in the message and not the user's phone number, 
   * then assume it's for the FTAF.
   *
   * @param $msg Message string to parse for numbers
   *
   * @return TRUE if number(s) found. FALSE if none are found.
   */
  private function hasPhoneNumbers($msg) {
    preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $msg), $numbers);
    if (!empty($numbers['numbers'])) {
      // Remove any items where the value equals the user's number
      $userNum = $state->getContext('sms_number');
      $userNumKeys = array_keys($numbers['numbers'], $userNum);
      
      // If keys remain after removing all numbers that match this user's num
      if (count($userNumKeys) < count($numbers['numbers'])) {
        return TRUE;
      }
    }
    
    return FALSE;
  }

  /**
   * Helper function to manage the output links and leave only the one we want
   * to go to next.
   *
   * @param $outputName Name of the output link to go to. Options: ftaf_prompt, sms_flow_generic_ftaf, end.
   */
  private function selectNextOutput($outputName) {
    switch ($outputName) {
      case 'ftaf_prompt':
        $this->removeOutput('sms_flow_generic_ftaf');
        $this->removeOutput('end');
        break;
      case 'sms_flow_generic_ftaf':
        $this->removeOutput('ftaf_prompt');
        $this->removeOutput('end');
        break;
      case 'end':
      default:
        $this->removeOutput('ftaf_prompt');
        $this->removeOutput('sms_flow_generic_ftaf');
        break;
    }
  }

}