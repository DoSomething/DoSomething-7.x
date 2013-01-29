<?php

/**
 * 
 */
class ConductorActivityMLKAlphaInvite extends ConductorActivity {

  private $game_id = 1;
  private $type_override = 'sms_game';

  public function option_definition() {
    $options = parent::option_definition();
    $options['alpha_optin'] = array('default' => '');
    $options['beta_optin'] = array('default' => '');
    $options['sms_response'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $user_response = $_REQUEST['args'];
    preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $user_response), $numbers);
    $numbers = $numbers['numbers'];

    // Get user's first name to send in text. Default to mobile number if name can't be found.
    $inviter_name = $mobile;
    $account = _sms_flow_find_user_by_cell($mobile);
    if ($account) {
      $profile = profile2_load_by_user($account);
      if (isset($profile['main'])) {
        $inviter_name = $profile['main']->field_user_first_name[LANGUAGE_NONE][0]['value'];
      }
    }

    $args = array(
      'mlk_game_inviter' => $inviter_name,
    );

    // Setup values and call sms_flow_start to save the alpha-beta relationship and opt-in users into next paths
    $form['details']['nid'] = $this->game_id;
    sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $numbers, $form, $args, FALSE, $this->type_override);
    
    if (empty($this->sms_response)) {
      // Setting sms_no_response_required to TRUE will allow workflow to end without
      // sending a respone to the user and trigger no error.
      $state->setContext('ignore_no_response_error', TRUE);
    }
    else {
      $state->setContext('sms_response', $this->sms_response);
    }
    $state->markCompleted();
  }

}
