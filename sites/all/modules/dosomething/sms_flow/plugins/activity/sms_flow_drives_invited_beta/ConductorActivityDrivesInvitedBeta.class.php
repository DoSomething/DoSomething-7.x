<?php

/**
 *
 */
class ConductorActivityDrivesInvitedBeta extends ConductorActivity {

  public function run($workflow) {
  	$state = $this->getState();
  	$mobile = $state->getContext('sms_number');

    // TODO: join these betas into their corresponding drives
    
    // Send feedback message to Alpha
    // TODO: change campaign_id, use Alpha's phone number to send to
    $alphaMsg = "Great stuff, <alpha name>. You invited $mobile and he/she joined your drive.";
    $alphaOptions = array('campaign_id' => 28024);
  	$return = sms_mobile_commons_send(3018073377, $alphaMsg, $alphaOptions);

    // TODO: create an FTAF Conductor flow that this person then gets placed into
    $state->setContext('sms_response', t("TODO: reconstruct FTAF functionality"));
    $state->markCompeted();
  }

}
