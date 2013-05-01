<?php

/**
 * Determine if account exists for this mobile number. Adjust output depending 
 * on existence or absence of account.
 */
class ConductorActivityCreateDrive extends ConductorActivity {
  
  // URL for campaign - used to get gid of the user's team
  public $campaign_url;

  // nid of the webform node to associate report backs with
  public $sign_up_nid;
  
  // Response sent to users in case of error
  public $response_error;

  // Response sent to users when it's found that they are already in a drive
  public $response_in_drive;

  // Response sent to users when drive join is successful, and they've created a new account
  public $response_new_account;

  // Response sent to users when drive join is successful, and they already have an account
  public $response_success;

  public function run($workflow) {
    
    // Collect current values based of state location
    $state = $this->getState();
    $school_id = $state->getContext('school_sid');
    $mobile = $state->getContext('sms_number');
    $user_reply = $state->getContext($this->name . ':message');

    if ($user_reply === FALSE) {
      // Temporarily set the global user. Some hook_form_alter implementations work off the assumption
      // that the user doing the form submitting should be available from the global user
      global $user;
      $original_user = $user;
      $old_state = drupal_save_session(FALSE);

      // See sms_flow.module - lookup user by mobile number based on Context value
      $user = dosomething_api_user_lookup($mobile);

      // Force load webform submission functionality
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      
      // Determine if the user is already signed up
      $count = webform_get_submission_count($this->sign_up_nid, $user->uid);
      
      if ($count == 0) {
        // Build out array for webform submission
        $form_state = array(
          'submitted' => true,
          'bundle' => 'campaign_sign_up',
          'values' => array(
            'submission' => NULL,
            'submitted' => array(),
            'details' => array(
              'nid' => $this->sign_up_nid,
              'sid' => NULL,
              'uid' => $user->uid,
            ),
            'op' => t('Submit'),
            'submit' => t('Submit'),
            'form_id' => 'webform_client_form_'.$this->sign_up_nid,
          ),
        );
        $form_state['webform_entity']['submission']->submitted['field_webform_mobile'][LANGUAGE_NONE][0]['value'] = $mobile;
        $form_state['webform_entity']['submission']->submitted['field_webform_school_reference'][LANGUAGE_NONE][0]['target_id'] = $school_id;
        $form_state['webform_entity']['submission']->bundle = $form_state['webform_entity']['bundle'] = 'campaign_sign_up';

        drupal_form_submit('webform_client_form_' . $this->sign_up_nid, $form_state, node_load($this->sign_up_nid));

        if (form_get_errors()) {
          $state->setContext('sms_response', $this->response_error);
          $this->removeOutput('strip_signature_post_create_drive');
          $state->markCompleted();

          return;
        }
        else {
          // If new_account_password is set, indicates a new user was created previously in the flow
          $new_account_password = $state->getContext('new_account_password');
          if ($new_account_password !== FALSE) {
            $state->setContext('sms_response', t($this->response_new_account, array('@pass' => $new_account_password)));
          }
          else {
            $state->setContext('sms_response', $this->response_success);
          }
        }
      }
      else {
        $state->setContext('sms_response', $this->response_in_drive);
      } 

      // Gets the GID of the drive this user is a part of. Then sets that value to
      // drives_invite_gid to be used in a later activity for doing a FTAF.
      $my_teams = teams_get_my_teams_for_url($this->campaign_url);
      $team_sid = $my_teams[0];
      $gid = og_get_group('webform_submission_entity', $team_sid, true)->gid;
      $state->setContext('drives_invite_gid', $gid);

      $state->markSuspended();

      $user = $original_user;
      drupal_save_session($old_state);
    }
    else {
      // We've received a response which should be friends' numbers, continue to next activity.
      // ftaf_prompt:message is where ConductorActivitySmsFlowFtaf expects the invitee numbers to be.
      $state->setContext('ftaf_prompt:message', $user_reply);
      $this->removeOutput('end');
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