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
  );
}

function drush_sms_flow_mcommons_rb_image_update($nid, $campaign_id, $var_last_processed) {

  // Prep for XML download loop
  $process = array();
  $page = 1;
  $page_count = 1;
  $msgPerPage = 100;
  $start_time = variable_get($var_last_processed, 0);
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

  if (!empty($processed_start_time)) {
    variable_set($var_last_processed, trim($processed_start_time));
  }

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

function _sms_flow_get_mcommons_mms_xml($page, $campaign_id, $limit, $start_time) {
  $url = "https://secure.mcommons.com/api/messages?mms=true&page=$page&limit=$limit&campaign_id=$campaign_id&start_time=$start_time";

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_URL, $url);
  $xml = curl_exec($ch);
  curl_close($ch);

  $xml = new SimpleXMLElement($xml);
  return $xml;
}