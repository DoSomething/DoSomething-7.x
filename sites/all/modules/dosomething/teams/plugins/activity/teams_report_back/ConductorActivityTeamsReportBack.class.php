<?php

class ConductorActivityTeamsReportBack extends ConductorActivitySMSPrompt {

  public $nid;
  public $cid;
  public $value;
  public $response;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    global $user;
    $original_user = $user;
    $old_state = drupal_save_session(FALSE);
    $user = dosomething_general_find_user_by_cell($mobile);

    module_load_include('inc', 'webform', 'includes/webform.submissions');

    $form_state = array(
      'submitted' => true,
      'bundle' => 'campaign_sign_up',
      'values' => array(
        'submission' => NULL,
        'submitted' => array(
          $this->cid => $this->value,
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

    $user = $original_user;
    drupal_save_session($old_state);

    $state->markCompeted();
  }
}
