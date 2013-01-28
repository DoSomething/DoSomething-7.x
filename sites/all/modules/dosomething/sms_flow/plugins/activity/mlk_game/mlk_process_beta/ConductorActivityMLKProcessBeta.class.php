<?php

/**
 * For use in the MLK 2013 SMS game. A beta has received an invite from an alpha
 * and is either accepting or rejecting the invite. If accepted, send the 
 * positive feedback message to the alpha.
 */
class ConductorActivityMLKProcessBeta extends ConductorActivity {

  // Mobile Commons campaign ID to place the Alpha into
  private $alpha_campaign_id = 107981;

  // Identifier for the MLK game
  private $game_id = 1;

  // Type of entry to submit to the sms_flow_records table
  private $type_override = 'sms_game';

  // Array of strings denoting an acceptance response
  protected $accept_responses = array();

  // Message to send if user accepted
  protected $beta_message_accept = '';

  // Message to send if user rejected
  protected $beta_message_reject = '';

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
      $beta = substr($mobile, -10);

      // TODO: what to do about users who are invited by more than one person
      // Find the Alpha who invited this user
      $alpha = sms_flow_find_alpha($beta, $this->game_id, $this->type_override);
      if ($alpha) {
        // Mark this user as having accepted the invite from the found alpha
        sms_flow_update_accepted_status($alpha, $beta, $this->game_id, $this->type_override);

        // Determine if Alpha already received a message from a Beta joining
        // $alpha_received_msg = sms_flow_alpha_received_message($alpha, $this->game_id, $this->type_override);
        // if (!$alpha_received_msg) {
        //   $alpha_msg = 'This is the message returned to the alpha. [TODO: get final message for this]';
        //   $alpha_options = array('campaign_id' => $this->alpha_campaign_id);
        //   $return = sms_mobile_commons_send($alpha, $alpha_msg, $alpha_options);
        // }
      }

      $beta_response = $this->beta_message_accept;
    }
    else {
      $beta_response = $this->beta_message_reject;
    }
    
    $state->setContext('sms_response', $beta_response);
    $state->markCompleted();
  }

}