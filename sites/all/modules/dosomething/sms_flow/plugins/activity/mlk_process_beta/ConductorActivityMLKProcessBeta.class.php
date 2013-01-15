<?php

/**
 * For use in the MLK 2013 SMS game. A beta has received an invite from an alpha
 * and is either accepting or rejecting the invite. If accepted, send the 
 * positive feedback message to the alpha.
 */
class ConductorActivityMLKProcessBeta extends ConductorActivity {

  public $game_id = 1;
  public $invite_type = 'sms_game';

  public function option_definition() {
    $options = parent::option_definition();
    $options['accept_responses'] = array('default' => array());
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Check if the user accepted the invite
    $user_response = strtolower($_REQUEST['args']);
    $invite_accepted = FALSE;
    foreach ($this->accept_responses as $val) {
      if (stripos($user_response, $val) === 0) {
        $invite_accepted = TRUE;
        break;
      }
    }

    if ($invite_accepted) {
      // TODO
      // Find alpha who sent invite to this user
      // if (alpha found) {
      //   if (alpha's already received a confirmation message from somebody == false)
      //     Send alpha new message
      // }  
      $beta_response = 'You\'ve joined your friend! Text KEYWORD to do thing. [TODO: get final message for this].';
    }
    else {
      $beta_response = 'You decided not to help out your friend. [TODO: get final message for this]';
    }
    
    $state->setContext('sms_response', $beta_response);
    $state->markCompleted();
  }

}