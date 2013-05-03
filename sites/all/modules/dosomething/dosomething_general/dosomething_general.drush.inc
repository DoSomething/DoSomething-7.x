<?php

/**
 * Implements hook_drush_init().
 */
function dosomething_general_drush_init() {
  // Make sure drush commands are considered background tasks by New Relic
  if (function_exists('newrelic_background_job')) {
    newrelic_background_job(TRUE);
  }
}

/**
 * Implements hook_drush_command().
 */
function dosomething_general_drush_command() {
  $commands = array();

  $commands['dosomething-export-images'] = array(
    'description' => "Export images submitted via campaign report backs into a downloadable archive.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('dsei'),
  );

  $commands['ds-merge-numbers'] = array(
    'description' => 'Merges mobile numbers into accounts.',
    'arguments' => array(
      'status' => 'li (logged in) or lo (logged out)'
    ),
  );

  $commands['ds-merge-emails'] = array(
    'description' => 'Merges emails into accounts.',
    'arguments' => array(
      'status' => 'li (logged in) or lo (logged out)'
    ),
  );

  return $commands;
}

/**
 * Connects users to phone #'s
 *
 * @param string $status
 *  li for logged in or lo for logged out
 */
function drush_dosomething_general_ds_merge_numbers($status) {
  static $count;

  // Merge phone numbers that people put into a webform into their account,
  // assuming it wasn't saved.
  if ($status == 'li') {
    /*
      select
      distinct u.uid,
      d.data,
      m.field_user_mobile_value
      FROM webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join users u on (u.uid = s.uid)
      left join profile p on (p.uid = u.uid)
      left join field_data_field_user_mobile m on (m.entity_id = p.pid)
      where d.data regexp '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$'
      and u.uid is not null
      and u.uid != 0
      and m.field_user_mobile_value is null
      GROUP BY u.uid
      limit 250
    */

    drush_print(dt('Getting counts and data.  This may take a while...'));

    $results = db_query("
      select
      u.uid,
      d.data
      FROM webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join users u on (u.uid = s.uid)
      left join profile p on (p.uid = u.uid)
      left join field_data_field_user_mobile m on (m.entity_id = p.pid)
      where d.data regexp :regex
      and u.uid is not null
      and u.uid != 0
      and m.field_user_mobile_value is null
      group by u.uid
      limit 250
    ", 
      // Need to pass the regex as a replacement, because db_query strips curly brackets in the query above.
      array(':regex' => '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$')
    )->fetchAllKeyed();

    // We need to get the total count so we can continue accordingly...
    if (empty($count)) {
      $count = db_query("
        select
        distinct u.uid,
        d.data
        FROM webform_submitted_data d
        left join webform_submissions s on (s.sid = d.sid)
        left join users u on (u.uid = s.uid)
        left join profile p on (p.uid = u.uid)
        left join field_data_field_user_mobile m on (m.entity_id = p.pid)
        where d.data regexp :regex
        and u.uid is not null
        and u.uid != 0
        and m.field_user_mobile_value is null
        group by u.uid
      ", 
        // Need to pass the regex as a replacement, because db_query strips curly brackets in the query above.
        array(':regex' => '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$')
      )->rowCount();
    }

    drush_print(dt('Starting...'));

    // We only need to run this if there are results.
    $i = 0;
    if (count($results) <= $count) {
      foreach ($results AS $uid => $mobile) {
        // Get profile information...
        $user = user_load($uid);
        $profile = profile2_load_by_user($user, 'main');

        // Apparently there are users without profiles.  Who knew?
        // Let's create a profile for them if they don't have one.
        if (!$profile) {
          $profile = profile2_create(array('type' => 'main'));
          $profile->setUser($user);
          $profile->is_new = TRUE;
        }

        // Strip non-numeric characters from the phone number.
        $mobile = preg_replace('#[^0-9]#', '', $mobile);

        // Sets the mobile number.
        $profile->field_user_mobile[LANGUAGE_NONE][0]['value'] = $mobile;

        // Saves their profile.
        $profile->save();

        // Plus plus
        $i++;

        // Hey we saved one!
        drush_print(dt("Saved UID {$uid} ({$i})"));
      }
    }

    drush_print(dt("Done."));

    if ($i < $count && $i != 0) {
      drush_print(dt("But wait, there's more.  Continuing..."));
      drush_invoke('ds-merge-numbers', array('status' => 'li'));
    }
    else {
      drush_print(dt("Okay, really done."));
    }
  }
  // If a user filled out a form with their contact information while logged out, we
  // didn't connect that submission with them.  Let's try and find 
  elseif ($status == 'lo') {
    drush_print(dt('Wait for it...'));
    /*
    select
    s.sid,
    s.uid,
    u.uid,
    d.data,
    m.field_user_mobile_value
    FROM webform_submitted_data d
    left join webform_submissions s on (s.sid = d.sid)
    left join field_data_field_user_mobile m on (m.field_user_mobile_value = d.data)
    left join profile p on (p.pid = m.entity_id)
    left join users u on (u.uid = p.uid)
    where d.data regexp '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$'
    and s.uid = 0
    and u.uid is not null
    and u.uid != 0
    limit 250;
    */

    drush_print(dt('Getting counts and data.  This may take a while...'));

    $count = cache_get('logged_out_numbers_count')->data;
    if (empty($count)) {
      $count = db_query("
        select
        s.sid,
        s.uid,
        u.uid,
        d.data,
        m.field_user_mobile_value
        FROM webform_submitted_data d
        left join webform_submissions s on (s.sid = d.sid)
        left join field_data_field_user_mobile m on (m.field_user_mobile_value = d.data)
        left join profile p on (p.pid = m.entity_id)
        left join users u on (u.uid = p.uid)
        where d.data regexp :regex
        and s.uid = 0
        and u.uid is not null
        and u.uid != 0",
        array(':regex' => '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$')
      )->rowCount();

      cache_set('logged_out_numbers_count', $count, 'cache', (time() + 10800));
    }

    $results = db_query("
      select
      s.sid,
      s.uid as s_uid,
      u.uid,
      d.data,
      m.field_user_mobile_value
      FROM webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join field_data_field_user_mobile m on (m.field_user_mobile_value = d.data)
      left join profile p on (p.pid = m.entity_id)
      left join users u on (u.uid = p.uid)
      where d.data regexp :regex
      and s.uid = 0
      and u.uid is not null
      and u.uid != 0
      limit 500
    ",
      array(':regex' => '^1?[\s\-]?[\(]?[0-9]{3}[\)]?[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$')
    )->fetchAllKeyed(0,2);

    drush_print(dt('Starting...'));

    $i = 0;
    if (count($results) <= $count) {
      foreach ($results AS $sid => $uid) {
        $submission = array_shift(entity_load('webform_submission_entity', array($sid)));

        // Just to double check...
        if ($submission->uid == 0) {
          $submission->uid = $uid;
        }

        // Save it.
        @entity_save('webform_submission_entity', $submission);
        $i++;
        drush_print(dt("Connected SID {$sid} to UID {$uid} ({$i})"));
      }
    }

    drush_print(dt("Done."));

    if ($i < $count && $i != 0) {
      drush_print(dt("But wait, there's more.  Continuing..."));
      sleep(0.5);
      drush_invoke('ds-merge-numbers', array('status' => 'lo'));
    }
    else {
      drush_print(dt("Okay, really done."));
    }
  }
}

/**
 * Connects users to emails
 *
 * @param string $status
 *  li for logged in or lo for logged out
 */
function drush_dosomething_general_ds_merge_emails($status) {
  static $count;

  // Find submissions where users put in their email, but their account
  // has their phone number as their primary email (e.g. @mobile email).
  // Change the user's email to be their actual email.
  if ($status == 'li') {
    /*
    select
    u.uid,
    d.data
    #u.mail
    from webform_submitted_data d
    left join webform_submissions s on (s.sid = d.sid)
    left join users u on (u.uid = s.uid)
    where d.data regexp '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\_\-]+\.[A-Za-z0-9\.]{2,10}$'
    and d.data not like '%@mobile%'
    #and u.mail regexp '\@mobile(\.com)?$'
    and u.uid is not null
    and u.uid != 0
    group by u.uid
    limit 1
    */

    drush_print(dt('Getting counts and data.  This may take a while...'));

    $count = db_query("
      select
      u.uid,
      d.data
      #u.mail
      from webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join users u on (u.uid = s.uid)
      where d.data regexp :regex1
      and d.data not like '%@mobile%'
      and u.mail regexp :regex2
      and u.uid is not null
      and u.uid != 0
      group by u.uid
    ", // Need to pass the regex as a replacement, because db_query strips curly brackets in the query above.
      array(
        ':regex1' => '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\.\_\-]+\.[A-Za-z0-9\.]{2,6}$',
        ':regex2' => '\@mobile(\.com)?$',
      ))->rowCount();

    $results = db_query("
      select
      u.uid,
      d.data
      #u.mail
      from webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join users u on (u.uid = s.uid)
      where d.data regexp :regex1
      and d.data not like '%@mobile%'
      and u.mail regexp :regex2
      and u.uid is not null
      and u.uid != 0
      group by u.uid
      limit 250
    ", 
      // Need to pass the regex as a replacement, because db_query strips curly brackets in the query above.
      array(
        ':regex1' => '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\.\_\-]+\.[A-Za-z0-9\.]{2,6}$',
        ':regex2' => '\@mobile(\.com)?$',
      )
    )->fetchAllKeyed();

    drush_print(dt('Starting...'));

    $i = 0;
    if (count($results) <= $count) {
      foreach ($results AS $uid => $email) {
        $user = user_load($uid);

        if (isset($user->uid)) {
          $user->mail = $email;
        }
        user_save($user);
        $i++;

        drush_print(dt("Updated UID {$uid} email to {$email} ($i)"));
      }
    }

    drush_print(dt("Done."));

    if ($i < $count && $i != 0) {
      drush_print(dt("But wait, there's more.  Continuing..."));
      drush_invoke('ds-merge-emails', array('status' => 'li'));
    }
    else {
      drush_print(dt("Okay, really done."));
    }
  }

  // Find submissions from logged out members where they put in their email address.
  // See if there's an account with that email.  If so, connect the submission to the
  // account.
  elseif ($status == 'lo') {
    drush_print(dt('Wait for it...'));
    /*
    select
    s.sid,
    s.uid as s_suid,
    u.uid,
    d.data,
    u.mail
    FROM webform_submitted_data d
    left join webform_submissions s on (s.sid = d.sid)
    left join users u on (u.mail = d.data)
    where
    d.data regexp '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\.\_\-]+\.[A-Za-z0-9\.]{2,10}$'
    and s.uid = 0
    and u.uid is not null
    and u.uid != 0
    group by s.sid
    */

    drush_print(dt('Getting counts and data.  This may take a while...'));

    $count = cache_get('logged_out_emails_count')->data;
    if (empty($count)) {
      $count = db_query("
        select
        s.sid,
        s.uid as s_suid,
        u.uid,
        d.data,
        u.mail
        FROM webform_submitted_data d
        left join webform_submissions s on (s.sid = d.sid)
        left join users u on (u.mail = d.data)
        where
        d.data regexp :regex
        and s.uid = 0
        and u.uid is not null
        and u.uid != 0
        group by s.sid",
        array(':regex' => '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\.\_\-]+\.[A-Za-z0-9\.]{2,10}$')
      )->rowCount();

      cache_set('logged_out_emails_count', $count, 'cache', (time() + 10800));
    }

    $results = db_query("
      select
      s.sid,
      s.uid as s_suid,
      u.uid,
      d.data,
      u.mail
      FROM webform_submitted_data d
      left join webform_submissions s on (s.sid = d.sid)
      left join users u on (u.mail = d.data)
      where
      d.data regexp :regex
      and s.uid = 0
      and u.uid is not null
      and u.uid != 0
      group by s.sid
      limit 500
    ",
      array(':regex' => '^[A-Za-z0-9\.\_\-]+\@[A-Za-z0-9\.\_\-]+\.[A-Za-z0-9\.]{2,10}$')
    )->fetchAllKeyed(0,2);

    drush_print(dt('Starting...'));

    $i = 0;
    if (count($results) <= $count) {
      foreach ($results AS $sid => $uid) {
        $submission = array_shift(entity_load('webform_submission_entity', array($sid)));

        // Just to double check...
        if ($submission->uid == 0) {
          $submission->uid = $uid;
        }

        // Save it.
        @entity_save('webform_submission_entity', $submission);
        $i++;
        drush_print(dt("Connected SID {$sid} to UID {$uid} ({$i})"));
      }
    }

    drush_print(dt("Done."));

    if ($i < $count && $i != 0) {
      drush_print(dt("But wait, there's more.  Continuing..."));
      sleep(0.5);
      drush_invoke('ds-merge-emails', array('status' => 'lo'));
    }
    else {
      drush_print(dt("Okay, really done."));
    }
  }
}

function drush_dosomething_general_dosomething_export_images() {
  $forms = node_load_multiple(array(), array('type' => 'campaign_report_back'));
  $base_path = 'imgdump';
  $tmpdir = file_directory_temp() . DIRECTORY_SEPARATOR . $base_path;
  // Ensure we start clean.
  if (file_exists($tmpdir)) {
    file_unmanaged_delete_recursive($tmpdir);
  }
  drupal_mkdir($tmpdir, NULL, TRUE);

  $operations = array();
  foreach ($forms as $nid => $form) {
    $form = array_shift($forms);
    $operations[] = array('_drush_dosomething_general_export_images_batch_callback', array($form->nid, $tmpdir));
  }

  batch_set(array('operations' => $operations));
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();

  if (file_exists(file_directory_temp() . DIRECTORY_SEPARATOR . "$base_path.tar")) {
    file_unmanaged_delete(file_directory_temp() . DIRECTORY_SEPARATOR . "$base_path.tar");
  }

  drush_print("Image dumps complete. Now archiving all images together.");

  $descriptor_spec = array(
    1 => array('pipe', 'w'),
    2 => array('pipe', 'w'),
  );

  $command = "tar -cf $base_path.tar $base_path";

  $process = proc_open($command, $descriptor_spec, $pipes, file_directory_temp(), $env);
  if (is_resource($process)) {
    $stdout = stream_get_contents($pipes[1]);
    fclose($pipes[1]);
    $stderr = stream_get_contents($pipes[2]);
    fclose($pipes[2]);

    $return_code = proc_close($process);

    if ($return_code) {
      $vars = array(
        '%command' => $command,
        '%code' => $return_code,
        '%stdout' => $stdout,
        '%stderr' => $stderr,
      );
      $text = "Invocation of '%command' exited with return code %code, emitting stdout:\n%stdout\n\nand stderr:\n%stderr";
      watchdog('ds_general', $vars, WATCHDOG_ERROR);
      throw new Exception(strtr($text, array_slice($vars, 0, 2)), E_ERROR);
    }
  }

  file_unmanaged_delete_recursive($tmpdir);
}

function _drush_dosomething_general_export_images_batch_callback($nid, $tmpdir) {
  ctools_include('webform.submissions', 'webform');

  $webform = node_load($nid);
  drush_print("Dumping images from {$webform->title}...");
  $tmpdir .= DIRECTORY_SEPARATOR . $nid . '-' . strtr("$webform->title", array(' ' => '.'));
  drupal_mkdir($tmpdir, NULL, TRUE);

  $submissions = webform_get_submissions($nid);
  foreach ($submissions as $submission) {
    if (empty($submission->field_webform_pictures)) {
      continue;
    }

    foreach ($submission->field_webform_pictures[LANGUAGE_NONE] as $field_contents) {
      file_unmanaged_copy($field_contents['uri'], $tmpdir . DIRECTORY_SEPARATOR . $field_contents['filename']);
    }
  }
}
