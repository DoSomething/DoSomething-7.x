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

  // Array of message IDs to ignore with the submission
  $ignore_images = array();

  // Hardcoding required values for GGW 2012 report back
  if ($nid == 726366) {
    // Seniors taught
    $wrapper->value()->data[2]['value'][0] = '0';
    // First name
    $wrapper->value()->data[3]['value'][0] = 'SMS';
    // Last name
    $wrapper->value()->data[4]['value'][0] = 'Submissions';

    $ignore_images = array(
      188672491,188672581,188675021,188676291,188684601,188714511,188716221,188729341,188731011,188734231,188736551,188738841,188739301,188741231,188745031,188748701,188748821,188749541,188764281,188769291,188769711,188772241,188774331,188777081,188794361,188795231,188796211,188797921,188798741,188798971,188800021,188801241,188803751,188804371,188816301,188818231,188818801,188823201,188826341,188829171,188829461,188833191,188837561,188838121,188852141,188853381,188853651,188858941,188859411,188861531,188863991,188864101,188867421,188873431,188878191,188878381,188880151,188880851,188882631,188884871,188890691,188891161,188894371,188896591,188902151,188913671,188918401,188919011,188921051,188926151,188929671,188930921,188931491,188934271,188934571,188939521,188950921,188953001,188953171,188954731,188955371,188957311,188971261,188975621,188986001,188988361,188990471,188992801,188994581,189006581,189007911,189008361,189012921,189013401,189014531,189017041,189017061,189018931,189019351,189019731,189022651,189022701,189025961,189030111,189030581,189036241,189037271,189038151,189038831,189040431,189041121,189044031,189044741,189046211,189046591,189047691,189047981,189048141,189048941,189055091,189056471,189057251,189060311,189060551,189062041,189064831,189064981,189065851,189073111,189074691,189074941,189076861,189078941,189079131,189080131,189082681,189083161,189085871,189088921,189090811,189091461,189109831,189110501,189110681,189112861,189112941,189116141,189117851,189120851,189122731,189127861,189128791,189129241,189129471,189130261,189131121,189133001,189140591,189142781,189145851,189146231,189147411,189147541,189148441,189148811,189149481,189150311,189151811,189153731,189165121,189168231,189179181,189180371,189186271,18919061,189191801,189195171,189196421,189199791,189202881,189207161,189207821,189214131,189224551,189227031,189227791,189229731,189230451,189233201,189233691,189234931,189237861,189240471,189241461,189245641,189247641,189250381,189250401,189254381,189256601,189256901,189257571,189258121,189262231,189264301,189265311,189270611,189271111,189282371,189283641,189287721,189288411,189289521,189292341,189292691,189295931,189296881,189305431,189310191,189312241,189313731,189315701,189315911,189316371,189320361,189320571,189320741,189321651,189324651,189325421,189329081,189335091,189337951,189338801,189340121,189344021,189344601,189345451,189346001,189349061,189349081,189350461,189355391,189358711,189359451,189359711,189361871,189362111,189363641,189376511,189379011,189380281,18938961,189395461,189396971,189397681,189399611,189406181,189408341,189411211,189416141,189424221,189462561,189466341,189473361,189481021,189482711,189485891,189500691,189502381,189523911,189534731,189542201,189554691,189580611,189618511,189715731,189773531,189778511,189792851,189799791,189817231,189836351,189896081,190021311,190587581,190623571,
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

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_URL, $url);
  $xml = curl_exec($ch);
  curl_close($ch);

  $xml = new SimpleXMLElement($xml);
  return $xml;
}