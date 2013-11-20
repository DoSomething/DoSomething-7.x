<?php

/**
 * Take data received throughout the workflow and submit it to the database
 * using dosomething_reportbacks helper methods.
 */
class ConductorActivitySubmitDoSomethingReportBack extends ConductorActivity {

  /**
   * Mobile Commons campaign IDs to opt the user out of.
   *
   * @var array
   */
  public $campaign_opt_outs;

  /**
   * Node ID of the campaign.
   *
   * @var int
   */
  public $nid;

  /**
   * Organization code of the campaign.
   *
   * @var int
   */
  public $organization_code;

  /**
   * Conductor activity name to retrieve the picture info, if any.
   *
   * @var string
   */
  public $picture_activity_name;

  /**
   * Key/Value pair defining where data retrieved through the workflow should get 
   * submitted. Key is the field names in the report back form, and Value is the
   * activity name to get the data from.
   *
   * @var array
   */
  public $submission_fields;

  /**
   * Response to send back to the user upon completion. Accepts either int for
   * Mobile Commons opt-in path ID or string to set the response message here.
   *
   * @var mixed
   */
  public $success_response;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Use the mobile number to retrieve the user object or create one if none exists
    $user = sms_flow_get_or_create_user_by_cell($mobile);
    if ($user) {

      $rbFieldData = array();

      // Cycle through array of submission fields 
      foreach ($this->submission_fields as $fieldName => $activityName) {
        $rbFieldData[$fieldName] = $state->getContext($activityName . ':message');
      }

      // Save report back data to the database
      $rbData = dosomething_reportback_insert_reportback($user->uid, $this->nid, $this->organization_code, $rbFieldData);

      // Save and submit a photo submission
      if (!empty($this->picture_activity_name) && $state->getContext($this->picture_activity_name) !== FALSE) {
        // Picture info pulled from context should be a URL
        $pictureUrl = $state->getContext($this->picture_activity_name);

        // Get URI for where to save this file
        $pictureFilename = dosomething_reportback_get_reportback_file_uri($rbData, basename($pictureUrl));

        // Download and save the file
        $pictureContents = file_get_contents($pictureUrl);
        $file = file_save_data($pictureContents, $pictureFilename);
        // file_save_data saves the uid from global $user, which is uid 0 when this code executes.
        // So, set the file uid from $user we have already:
        $file->uid = $user->uid;
        // And write it to the file:
        file_save($file);

        // Save the picture info to the database
        dosomething_reportback_insert_reportback_file($rbData['rbid'], $file->fid);
      }
    }

    // If numeric, response sent back to user is a Mobile Commons opt-in path
    if (is_numeric($this->success_response)) {
      dosomething_general_mobile_commons_subscribe($mobile, $this->success_response);
      $state->setContext('ignore_no_response_error', TRUE);
    }
    // Otherwise, use the string as the return message
    else {
      $state->setContext('sms_response', $this->success_response);
    }

    // Opt users out of specified Mobile Commons campaigns
    if (!empty($this->campaign_opt_outs)) {
      sms_mobile_commons_campaign_opt_out($mobile, $this->campaign_opt_outs);
    }

    // End the activity
    $state->markCompleted();
  }

}