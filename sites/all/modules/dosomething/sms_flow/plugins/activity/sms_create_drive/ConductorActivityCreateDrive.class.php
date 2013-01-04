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

    global $user;
    $original_user = $user;
    $old_state = drupal_save_session(FALSE);
    $user = dosomething_general_find_user_by_cell($mobile);

    // See sms_flow.module - lookup user by mobile number based on Context value
    $account = _sms_flow_find_user_by_cell($mobile);

    // Force load webform submission functionality
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    
    // Determine if the user is already signed up
    $count = webform_get_submission_count(self::JEANS12_CAMPAIGN_SIGN_UP_NID, $account->uid);
    
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
            'uid' => $account->uid,
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

      if (form_get_errors()) {
        print_r(form_get_errors());
        $state->setContext('sms_response', t('SO MUCH PAIN'));
      }
      else {
        $state->setContext('sms_response', t('Thanks! You\'re added to the Teans for Jeans team.'));
      }
    }
    else {
      $state->setContext('sms_response', t('Oops, it looks like you\'ve alrady signed up for a team.'));
    } 

    $user = $original_user;
    drupal_save_session($old_state);

    $state->markCompleted();
  }

}