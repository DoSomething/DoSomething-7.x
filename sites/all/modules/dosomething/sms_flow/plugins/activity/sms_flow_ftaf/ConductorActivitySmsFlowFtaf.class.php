<?php

/**
 * Process phone numbers and forward invites on to users using sms_flow_start()
 */
class ConductorActivitySmsFlowFtaf extends ConductorActivity {

	// Mobile Commons optin path for inviter to be joined into
	public $alpha_optin = 0;

	// Mobile Commons optin path for the invitee to be joined into
	public $beta_optin = 0;

	// Response sent to inviter if process succeeds
	public $response_success = '';

	// Response sent to inviter if process fails
	public $response_fail = '';

	public function option_definition() {
		$options = parent::option_definition();
		$options['alpha_optin'] = array('default' => 0);
		$options['beta_optin'] = array('default' => 0);
		$options['response_success'] = array('default' => '');
		$options['response_fail'] = array('default' => '');

		return $options;
	}
  
  public function run($workflow) {
  	$state = $this->getState();
  	$mobile = $state->getContext('sms_number');
  	$message = $state->getContext('ftaf_prompt:message');

  	$numbers = explode(',', $message);

  	$vetted_numbers = array();
  	foreach ($numbers as $number) {
  		$number = trim($number);
  		$number = preg_replace("/[^0-9]/", "", $number);

			if (dosomething_general_valid_cell($number)) {
				$vetted_numbers[] = $number;
			}
			else {
				continue;
			}
  	}

  	$response = $this->response_fail;
  	if (count($vetted_numbers) > 0) {
  		print_r($vetted_numbers);
  		$args = array(
  			// TODO: determine how to get drive/club name from the profile
  			//'ds_club_name' => $club_name,
  		);
  		sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $vetted_numbers, FALSE, $args, FALSE);
  		$response = $this->response_success;
  	}

  	$state->setContext('sms_response', $response);
  	$state->markCompleted();
  }
}

