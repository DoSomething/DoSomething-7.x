<?php

/**
 * Determine if account exists for this mobile number. Adjust output depending 
 * on existence or absence of account.
 */
class ConductorActivityCreateDrive extends ConductorActivity {
  
    // nid of the webform node to associate report backs with
  const JEANS12_CAMPAIGN_SIGN_UP_NID = 725896;

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
      $user = _sms_flow_find_user_by_cell($mobile);

      // Force load webform submission functionality
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      
      // Determine if the user is already signed up
      $count = webform_get_submission_count(self::JEANS12_CAMPAIGN_SIGN_UP_NID, $user->uid);
      
      if ($count == 0) {
        // Build out array for webform submission
        $form_state = array(
          'submitted' => true,
          'bundle' => 'campaign_sign_up',
          'values' => array(
            'submission' => NULL,
            'submitted' => array(),
            'details' => array(
              'nid' => self::JEANS12_CAMPAIGN_SIGN_UP_NID,
              'sid' => NULL,
              'uid' => $user->uid,
            ),
            'op' => t('Submit'),
            'submit' => t('Submit'),
            'form_id' => 'webform_client_form_'.self::JEANS12_CAMPAIGN_SIGN_UP_NID,
          ),
        );
        $form_state['webform_entity']['submission']->submitted['field_webform_mobile'][LANGUAGE_NONE][0]['value'] = $mobile;
        $form_state['webform_entity']['submission']->submitted['field_webform_school_reference'][LANGUAGE_NONE][0]['target_id'] = $school_id;
        $form_state['webform_entity']['submission']->bundle = $form_state['webform_entity']['bundle'] = 'campaign_sign_up';

        drupal_form_submit('webform_client_form_' . self::JEANS12_CAMPAIGN_SIGN_UP_NID, $form_state, node_load(self::JEANS12_CAMPAIGN_SIGN_UP_NID));

        // Set the gid invitees can use to join the proper drive
        $my_teams = teams_get_my_teams_for_url('teensforjeans');
        $team_sid = $my_teams[0];
        $gid = og_get_group('webform_submission_entity', $team_sid, true)->gid;
        $state->setContext('drives_invite_gid', $gid);

        if (form_get_errors()) {
          $state->setContext('sms_response', t('Sorry! We ran into a problem creating your drive. Text JEANS to try again or visit http://doso.me/6 to try online.'));
          $this->removeOutput('strip_signature_3');
          $state->markCompleted();

          return;
        }
        else {
          // If new_account_password is set, indicates a new user was created previously in the flow
          $new_account_password = $state->getContext('new_account_password');
          if ($new_account_password !== FALSE) {
            $state->setContext('sms_response', t('Great! Your school is signed up for a T4J drive. Login at http://doso.me/6. Ur password is: @pass. Once 5 people are signed up, you\'ll get a banner. Text us friends\' #s to invite them', array('@pass' => $pass)));
          }
          else {
            $state->setContext('sms_response', t('Great! Your school is signed up for a T4J drive. Login at http://doso.me/6. Once 5 people sign up, you\'ll get a banner. Text us your friends\' #s to invite them'));
          }
        }
      }
      else {
        $state->setContext('sms_response', t('You already signed up for a drive! Login at http://doso.me/6 to visit it. Once 5 people sign up, you\'ll get a T4J banner. Text us ur friends\' #s to invite them'));
      } 

      $state->markSuspended();

      $user = $original_user;
      drupal_save_session($old_state);
    }
    else {
      // We've received a response which should be friends' numbers, continue to next activity
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