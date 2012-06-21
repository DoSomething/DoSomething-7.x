<?php

class ConductorActivityTeamsCreateTeam extends ConductorActivitySMSPrompt {

  const SIGNUP_NID = 722347;

  public function run($workflow) {
    $state = $this->getState();

    $mobile = $state->getContext('sms_number');

    if ($mobile[0] == '1') $mobile = substr($mobile, 1);

    // check if the team leader info is an actual account
    if (teams_team_exists($state->getContext('team_name:message'), self::SIGNUP_NID)) {
      $state->setContext('sms_response', t('A team with that name has already been created. Text JOINTEAM or STARTTEAM to try again.'));
    }
    else {
      global $user;
      $original_user = $user;
      $old_state = drupal_save_session(FALSE);
      $user = dosomething_general_find_user_by_cell($mobile);
      $profile = profile2_load_by_user($user);

      $form_state = array(
        'submitted' => true,
        'bundle' => 'campaign_sign_up',
        'values' => array(
          'submission' => NULL,
          'submitted' => array(),
          'details' => array(
            'nid' => self::SIGNUP_NID,
            'sid' => NULL,
          ),
          'form_id' => 'webform_client_form_'.self::SIGNUP_NID,
        ),
      );
      $form_state['webform_entity']['submission']->submitted['field_webform_mobile'][LANGUAGE_NONE][0]['value'] = $mobile;
      $form_state['webform_entity']['submission']->submitted['field_team_name'][LANGUAGE_NONE][0]['value'] = $state->getContext('team_name:message');
      $form_state['webform_entity']['submission']->bundle = $form_state['webform_entity']['bundle'] = 'campaign_sign_up';

      drupal_form_submit('webform_client_form_' . self::SIGNUP_NID, $form_state, node_load(self::SIGNUP_NID), $submission);

      if (form_get_errors()) {
        $state->setContext('sms_response', t('Oops, we had trouble creating your team. Try again with JOINTEAM or STARTTEAM or go to dosomething.org/hunt.'));
      }
      else {
        $state->setContext('sms_response', t('Thanks! You\'ve created a team.'));
      }

      $user = $original_user;
      drupal_save_session($old_state);
    }

    $state->markCompeted();
  }
}
