<?php

/**
 * Activity to process and submit report back forms for GAS 2012
 */
class ConductorActivityGAS2012ReportBack extends ConductorActivity {

  const REPORT_BACK_NID = 724780;

  public function run() {
    $state = $this->getState();

    $mobile = $state->getContext('sms_number');

    // Get values to add to webform submission
    $whyParticipated = $state->getContext('why_participated:message');
    $howManyHelped = $state->getContext('how_many_helped:message');
    $howManySwabbed = $state->getContext('how_many_swabbed:message');

    // Get or create a user by the user's cell phone number
    $account = _sms_flow_find_user_by_cell($mobile);
    if (!$account) {
      $account = new stdClass;
      $account->name = $mobile;

      $suffix = 0;
      $base_name = $account->name;
      while (user_load_by_name($acount->name)) {
        $suffix++;
        $account->name = $base_name . '-' . $suffix;
      }
      $account->mail = $mobile . '@mobile';
      $account->status = 1;

      $account = user_save($account);

      $profile_values = array('type' => 'main');
      $profile = profile2_create($profile_values);
      $profile->uid = $account->uid;
      $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

      try {
        profile2_save($profile);
      }
      catch( Exception $e ) {}
    }

    // Create and submit webform submission
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
    $wrapper->value()->data[2]['value'][0] = $whyParticipated;
    $wrapper->value()->data[3]['value'][0] = $howManyHelped;
    $wrapper->value()->data[4]['value'][0] = $howManySwabbed;
    $wrapper->save();

    // Push user to opt-in FTAF path
    $optInUrl = 'http://dosomething.mcommons.com/profiles/join';
    $optInFields = array(
      'opt_in_path' => 132311,
      'person[phone]' => urlencode($mobile),
    );
    $optInFieldsQuery = http_build_query($optInFields);

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CULROPT_URL, $optInUrl);
    curl_setopt($ch, CURLOPT_POST, count($optInFields));
    curl_setopt($ch, CURLOPT_POSTFIELDS, $optInFieldsQuery);
    $optInResult = curl_exec($ch);
    curl_close($ch);

    // End this worklow and respond with webform submission confirmation
    $state->setContext('sms_response', t('That\'s great! Thanks for telling us about your drive.'));
    $state->markCompleted();
  }

}