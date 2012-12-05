<?php

function sms_flow_drush_command() {
  return array(
    'sms-flow-mcommons-rb-image-update' => array(
      'description' => 'Pull images from Mobile Commons and update webform submissions',
      'arguments' => array(
        'nid' => 'Node id of the report back webform to update with images',
        'campaign_id' => 'Mobile Commons campaign id to look for images in',
        'var_last_processed' => 'Variable set that tracks the last known date of the last image processed',
      ),
    ),
    'sms-flow-mcommons-force-image-update' => array(
      'description' => 'Pull images from Mobile Commons and submit as a new webform submission',
      'arguments' => array(
        'nid' => 'Node id of the report back webform to update with images',
        'campaign_id' => 'Mobile Commons campaign id to look for images in',
        'start_time' => 'Start time to search for images (ex: "November 22, 2012")',
      ),
    ),
  );
}

/**
 * Downloads MMS from mobile commons and submits the images as a single report back authored by the
 * generic sms_submissions user.
 *
 * @param nid Node ID of the webform to submit results to
 * @param campaign_id
 * @param var_last_processed
 *
 * @example 
 *  - GGW Thanksgiving day blast: drush sms-flow-mcommons-force-image-update 726366 89561 "November 22, 2012"
 */
function drush_sms_flow_mcommons_force_image_update($nid, $campaign_id, $start_time = NULL) {

  // UID for the generic sms_submissions user
  $sms_sub_uid = 999583;

  // Create initial webform submission
  $init_sub = new stdClass;
  $init_sub->bundle = 'campaign_report_back';
  $init_sub->nid = $nid;
  $init_sub->data = array();
  $init_sub->uid = $sms_sub_uid;
  $init_sub->submitted = REQUEST_TIME;
  $init_sub->remote_addr = ip_address();
  $init_sub->is_draft = FALSE;
  $init_sub->sid = NULL;

  $wrapper = entity_metadata_wrapper('webform_submission_entity', $init_sub);

  // Hardcoding required values for GGW 2012 report back
  if ($nid == 726366) {
    // Seniors taught
    $wrapper->value()->data[2]['value'][0] = '0';
    // First name
    $wrapper->value()->data[3]['value'][0] = 'SMS';
    // Last name
    $wrapper->value()->data[4]['value'][0] = 'Submissions';
  }

  // Array of message IDs to ignore with the submission
  $ignore_images = array();
  if ($nid = 'asdf') {
    $ignore_images = array(
      // TODO: populate with message IDs
      193533011,
      193435941
    );
  }

  $process = _sms_flow_mms_download_loop($nid, $campaign_id, NULL, $start_time);

  // Download and save images, then submit them to the specified webform
  foreach ($process as $xml) {
    for ($i = 0; $i < count($xml->messages->message); $i++) {
      $message = $xml->messages->message[$i];

      $atts_array = (array)$message->attributes();
      $msg_id = $atts_array['@attributes']['id'];

      if (!in_array(intval($msg_id), $ignore_images)) {
        // Download and save image
        $mms = $message->mms;
        $f_name = 'public://' . basename($mms->image_url);
        $attach = file_get_contents($message->mms->image_url);
        $attach = file_save_data($attach, $f_name);
        echo "Saved file: $f_name // $msg_id\n";

        $attachArr = get_object_vars($attach);
        $wrapper->value()->field_webform_pictures[LANGUAGE_NONE][] = $attachArr;
      }
    }
  }

  $wrapper->save();
  echo "Done saving images to node:$nid for campaign_id:$campaign_id at start_time:$start_time\n";
}

function drush_sms_flow_mcommons_rb_image_update($nid, $campaign_id, $var_last_processed) {

  $process = _sms_flow_mms_download_loop($nid, $campaign_id, $var_last_processed);

  foreach ($process as $xml) {
    for ($i = 0; $i < count($xml->messages->message); $i++) {
      $message = $xml->messages->message[$i];

      // Find user. Ignore if none found.
      $mobile = $message->phone_number;
      $account = _sms_flow_find_user_by_cell($mobile);
      if (!$account)
        continue;

      // Find webform submission based on nid and account uid
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $submissions = webform_get_submissions(array('uid' => $account->uid, 'nid' => $nid));
      
      if (count($submissions) == 0)
        continue;

      // Download and save image
      $mms = $message->mms;
      $f_name = 'public://' . basename($mms->image_url);
      $attach = file_get_contents($message->mms->image_url);
      $attach = file_save_data($attach, $f_name);
      
      // Update submission with file found
      foreach($submissions as $sub) {
        // Need to save file data as an array instead of an object
        $attachArr = get_object_vars($attach);
        $sub->field_webform_pictures[LANGUAGE_NONE][] = $attachArr;
        entity_save('webform_submission_entity', $sub);

        echo "Updated submission for $mobile with image: $mms->image_url\n";
      }

    }
  }
}

function _sms_flow_mms_download_loop($nid, $campaign_id, $var_last_processed = NULL, $start_time_override = NULL) {
  // Prep for XML download loop
  $process = array();
  $page = 1;
  $page_count = 1;
  $msgPerPage = 100;
  $start_time = $val_last_processed != NULL ? variable_get($var_last_processed, 0) : 0;
  $start_time = $start_time_override != NULL ? urlencode($start_time_override) : $start_time;
  $processed_start_time = '';
  while ($page <= $page_count) {
    $xml = _sms_flow_get_mcommons_mms_xml($page, $campaign_id, $msgPerPage, $start_time);
    $process[] = $xml;

    $page_count = $xml->messages['page_count'];

    if (empty($processed_start_time)) {
      $processed_start_time = $xml->messages->message[0]->received_at;
    }

    $page++;
  }

  if (!empty($processed_start_time) && $start_time_override == NULL) {
    variable_set($var_last_processed, trim($processed_start_time));
  }

  return $process;
}

function _sms_flow_get_mcommons_mms_xml($page, $campaign_id, $limit, $start_time) {
  $url = "https://secure.mcommons.com/api/messages?mms=true&page=$page&limit=$limit&campaign_id=$campaign_id&start_time=$start_time";
echo "url: $url\n";

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_URL, $url);
  $xml = curl_exec($ch);
  curl_close($ch);

  $xml = new SimpleXMLElement($xml);
  return $xml;
}