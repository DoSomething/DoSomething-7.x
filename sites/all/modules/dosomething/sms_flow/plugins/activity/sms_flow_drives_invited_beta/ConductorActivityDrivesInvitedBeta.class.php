<?php

/**
 * Activity to process persons invited to a drive. Joins person into the
 * drive, and then sends a positive feedback sms to the person who invited them.
 */
class ConductorActivityDrivesInvitedBeta extends ConductorActivity {

	public $alpha_campaign_id = 0;

	public function option_definition() {
		$options = parent::option_definition();
		$options['alpha_campaign_id'] = array('default' => '');
		return $options;
	}

  public function run($workflow) {
  	$state = $this->getState();
  	$mobile = $state->getContext('sms_number');

    // If we have a user with this mobile, update their info.
    $account = dosomething_general_find_user_by_cell($mobile);

    // Create account for this user if none is found
    if (!$account) {
      $account = new stdClass;
      $account->name = $mobile;

      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($account->name)) {
        $suffix++;
        $account->name = $base_name . '-' . $suffix;
      }
      $account->mail = $mobile . '@mobile';
      $account->status = 1;
      user_save($account);
      $profile_values = array(
        'type' => 'main',
        'field_user_mobile' => array(
          LANGUAGE_NONE => array(
            'value' => $mobile,
          ),
        ),
      );
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {
      }
    }

    // TODO: join beta into corresponding drive. Is it just a straight up webform submit?
    // $submission = new stdClass;
    // $submission->bundle = 'campaign_report_back';
    // $submission->nid = self::REPORT_BACK_NID;
    // $submission->data = array();
    // $submission->uid = $account->uid;
    // $submission->submitted = REQUEST_TIME;
    // $submission->remote_addr = ip_address();
    // $submission->is_draft = FALSE;
    // $submission->sid = NULL;

    // $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
    // $wrapper->value()->data[1]['value'][0] = $first_name;

    // $wrapper->save();
    
    // Send feedback message to Alpha
    $alphaMobile = sms_flow_find_alpha($mobile);
    $alphaMsg = "Good news! You invited $mobile and he/she joined your drive.";
    $alphaOptions = array('campaign_id' => $this->alpha_campaign_id);
  	$return = sms_mobile_commons_send($alphaMobile, $alphaMsg, $alphaOptions);

    $state->markCompeted();
  }

}
