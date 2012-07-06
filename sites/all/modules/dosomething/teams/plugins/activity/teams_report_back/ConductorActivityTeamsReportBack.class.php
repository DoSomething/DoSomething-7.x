<?php

class ConductorActivityTeamsReportBack extends ConductorActivitySMSPrompt {

  public $nid;
  public $cid;
  public $value;
  public $response;
  public $base_url;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    if ($mobile[0] == '1') $mobile = substr($mobile, 1);

    global $user;
    $original_user = $user;
    $old_state = drupal_save_session(FALSE);
    $user = dosomething_general_find_user_by_cell($mobile);

    if (!teams_in_group($base_url)) {
      $state->setContext('sms_response', t('Hmm, looks like you\'re not a part of a team yet. Text STARTTEAM or JOINTEAM to get on one, then try again.'));
    }
    else {
      module_load_include('inc', 'webform', 'includes/webform.submissions');

      $form_state = array(
        'submitted' => true,
        'bundle' => 'team_challenge',
        'values' => array(
          'submission' => NULL,
          'submitted' => array(
            $this->cid => array(
              $this->value,
            ),
          ),
          'details' => array(
            'nid' => $this->nid,
            'sid' => NULL,
            'uid' => $user->uid,
          ),
          'op' => t('Submit'),
          'submit' => t('Submit'),
          'form_id' => 'webform_client_form_'.$this->nid,
        ),
      );
      $form_state['webform_entity']['submission']->bundle = $form_state['webform_entity']['bundle'] = 'team_challenge';

      drupal_form_submit('webform_client_form_' . $this->nid, $form_state, node_load($this->nid), $submission);

      if (form_get_errors()) {
        $state->setContext('sms_response', t('Oops, we had trouble logging your points. Head over to dosomething.org/hunt and try there.'));
      }
      else {
        $state->setContext('sms_response', $this->response);
      }
    }

    $user = $original_user;
    drupal_save_session($old_state);

    $state->markCompeted();
  }
}
