<?php

function teams_drush_command() {
  return array(
    'teams-hunt' => array(
      'description' => 'Import images from Mobile Commons.',
    ),
    'teams-hunt-report' => array(
      'description' => 'Pull completed challenges per team.',
      'arguments' => array(
        'path' => 'Export csv filename, full path preferred',
      ),
    ),
  );
}

function drush_teams_hunt_report($path) {
  $nids = array(722991, 722992, 722993, 722994, 722995, 722996, 722997, 722998, 722999, 723000);
  $signup = 722347;
  $headers = array();
  for ($i = 1; $i <= count($nids); $i++) {
    $headers[] = $i.'_a';
    $headers[] = $i.'_b';
    $headers[] = $i.'_c';
    $headers[] = 'pic_'.$i;
  }

  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', $signup)
    ->fieldCondition('group_group', 'value', 1, '=')
    ->execute();
  $teams = $result['webform_submission_entity'];

  $etids = array_keys($teams);
  $gids = og_get_group_ids('webform_submission_entity', $etids);

  $result_rows = array(array_merge(array('sid'), $headers));
  foreach ($gids as $sid => $gid) {
    $result_row = array();
    $result_row['sid'] = $sid;
    foreach ($headers as $header) {
      $result_row[$header] = FALSE;
    }

    // get group members
    $query = new EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('gid', $gid)
      ->propertyCondition('entity_type', 'user')
      ->execute();

    $memberships = entity_load('og_membership', array_keys($result['og_membership']));
    $uids = array();
    foreach ($memberships as $membership) {
      $uids[] = $membership->etid;
    }

    // get the submissions they've done
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    if (!empty($uids)) {
      $subs = webform_get_submissions(array('uid' => $uids, 'nid' => $nids));
      if (!empty($subs)) {
        foreach ($subs as $sub) {
          // capture completed challenges
          foreach ($sub->data[1]['value'] as $challenge) {
            $result_row[$challenge] = TRUE;
          }
          // capture pics
          if (!empty($sub->field_webform_pictures)) {
            $day = array_search($sub->nid, $nids) + 1;
            $result_row['pic_'.$day] = TRUE;
          }
        }
      }
    }
    $result_rows[] = $result_row;
  }
  $fp = fopen($path, 'w');
  foreach ($result_rows as $row) {
    fputcsv($fp, $row);
  }
  fclose($fp);
}

function drush_teams_hunt() {
  // map image upload date to a webform node ID
  $date_mapping = array(
    '7/10/2012' => 722991,
    '7/11/2012' => 722992,
    '7/12/2012' => 722993,
    '7/13/2012' => 722994,
    '7/14/2012' => 722995,
    '7/15/2012' => 722996,
    '7/16/2012' => 722997,
    '7/17/2012' => 722998,
    '7/18/2012' => 722999,
    '7/19/2012' => 723000,
  );

  // convert array keys to serialized DateTime objects for easy referencing
  foreach ($date_mapping as $key => $nid) {
    $date = DateTime::createFromFormat('n/j/Y', $key);
    $date_mapping[serialize($date)] = $nid;
    unset($date_mapping[$key]);
  }

  // prep for the XML download loop
  $process = array();
  $last_parsed = variable_get('teams_hunt_last_processed', 0);

  // loop through, downloading XML files as many times as we need until we
  // see a message ID we've already parsed.
  $page = 1;
  $xml = teams_get_mcommons_xml($page);
  do {
    $process[] = $xml;
    $xml = teams_get_mcommons_xml(++$page);
    $highest = $xml->messages->message[0]['id'];
  } while ($highest > $last_parsed);

  // we want to go in increasing order of message IDs, so let's flip our XML
  // array.
  $process = array_reverse($process);

  // iterate through each file we downloaded
  foreach ($process as $xml) {
    // iterate through the messages in the file backwards (lowest message ID to highest)
    for ($i = count($xml->messages->message)-1; $i >= 0; $i--) {
      $message = $xml->messages->message[$i];

      // don't parse this message if it's ID is lower than one we've already parsed
      if ($message['id'] <= $last_parsed) continue;
      // don't parse this message if it doesn't have an MMS message (unlikely)
      if (!isset($message->mms)) continue;

      // compare the date on the message to the mapping array
      $date = DateTime::createFromFormat('Y-m-d H:i:s T', $message->received_at);
      $date->setTimezone(new DateTimeZone('America/New_York'));
      foreach ($date_mapping as $map_date => $nid) {
        $diff = $date->diff(unserialize($map_date));
        if ($diff->y == 0 && $diff->m == 0 && $diff->d == 0) {
          // let's not blow anything up by using some stupidly cached something somewhere
          drupal_static_reset();

          $mobile = $message->phone_number;
          if ($mobile[0] == '1') $mobile = substr($mobile, 1);

          // load up the account and let's ignore anyone that doesn't have one
          $account = dosomething_general_find_user_by_cell($mobile);
          if (!$account) continue;

          // download the file from mobile commons and save it to the file table
          $f_name = basename($message->mms->image_url);
          $attach = file_get_contents($message->mms->image_url);
          $attach = file_save_data($attach, 'public://'.$f_name);

          // create a webform_submission_entity for saving!
          $field = teams_get_dummy_field(node_load($nid));
          $submission = (object) array(
            'sid' => NULL,
            'nid' => $nid,
            'uid' => $account->uid,
            'submitted' => REQUEST_TIME,
            'remote_addr' => ip_address(),
            'is_draft' => 0,
            'data' => array(
              $field => array('value' => array('dummy')),
            ),
            'bundle' => 'team_challenge',
            'field_webform_pictures' => array(
              LANGUAGE_NONE => array(
                (array) $attach,
              ),
            ),
          );
          entity_save('webform_submission_entity', $submission);

          break;
        }
      }
      $id = (int) $message['id'];
      variable_set('teams_hunt_last_processed', $id);
    }
  }
}

function teams_get_dummy_field($node) {
  foreach ($node->webform['components'] as $key => $comp) {
    if ($comp['form_key'] == 'dummy') {
      return $key;
    }
  }
  return -1;
}

function teams_get_mcommons_xml($page) {
  $url = 'https://secure.mcommons.com/api/messages?mms=true';

  $current = "$url&page=$page&limit=100";

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_URL, $current);
  $xml = curl_exec($ch);
  curl_close($ch);

  $xml = new SimpleXMLElement($xml);
  return $xml;
}
