<?php

/**
 * Final step in Alcoa 50 Cans report back SMS flow.
 */
class ConductorActivity50CansReportBack extends ConductorActivity {

  const REPORT_BACK_NID = 725607;

  private $responseSuccess = 'That\'s all we\'ve got! Thanks for participating and congrats again on all of your amazing work.';

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $args = $_REQUEST['args'];
    $pplDonated = $args;

    $profileUrl = 'https://secure.mcommons.com/api/profile?phone_number=' . $mobile;

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_URL, $profileUrl);
    $xml = curl_exec($ch);
    curl_close();

    // Get 50cans_collected and 50cans_helped_run value from profile
    $cansCollected = 0;
    $cansCollectedPattern = '#\<custom_column name\="50cans_collected"\>(.*?)\<\/custom_column\>#is';
    $matchFound = preg_match($cansCollectedPattern, $xml, $cansCollectedMatches);
    if ($matchFound && count($cansCollectedMatches) >= 2) {
      $cansCollected = trim($cansCollectedMatches[1]);
    }

    $pplHelpedRun = 0;
    $pplHelpedPattern = '#\<custom_column name\="50cans_helped_run"\>(.*?)\<\/custom_column\>#is';
    $matchFound = preg_match($pplHelpedPattern, $xml, $pplHelpedMatches);
    if ($matchFound && count($pplHelpedMatches) >= 2) {
      $pplHelpedRun = trim($pplHelpedMatches[1]);
    }

    // Get or create user's account
    $account = sms_flow_get_or_create_user_by_cell($mobile);
    
    // Build report back submission and submit
    $submission = new stdClass;
    $submission->bundle = 'campaign_report_back';
    $submission->nid = self::REPORT_BACK_NID;
    $submission->data = array();
    $submission->uid = $account->uid;
    $submission->submitted = REQUEST_TIME;
    $submission->remote_addr = ip_address();
    $submission->is_draft = FALSE;
    $submission->sid = NULL;

    $wrapper = entity_metadata_wrapper('webform_submission_entity', $submission);
    $wrapper->value()->data[2]['value'][0] = $pplHelpedRun;
    $wrapper->value()->data[3]['value'][0] = $pplDonated;
    $wrapper->value()->data[4]['value'][0] = $cansCollected;
    $wrapper->save();

    $state->setContext('sms_response', $this->responseSuccess);
    $state->markCompleted();
  }
}