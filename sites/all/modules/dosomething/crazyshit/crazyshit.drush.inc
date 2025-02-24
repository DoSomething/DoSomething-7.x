<?php

function crazyshit_drush_command() {
  return array(
    'crazy-messages' => array(
      'description' => 'Send aggregate notifications from Crazy $#!T',
    ),
    'crazy-migrate' => array(
      'description' => 'Migrates Crazy $#!T Module to a new machine.',
    ),
    'crazy-image-fix' => array(
      'description' => 'Images lose text on image style fixes.  This fixes them.'
    ),
  );
}

function drush_crazyshit_crazy_migrate() {
  try {

    drush_log('Enabling infinite scroll module.', 'notice');
    $modules = array(
      'views_infinite_scroll',
    );
    drush_invoke_process('@self', 'en', $modules, array('--yes', '--verbose'));

    $file = drupal_get_path('module', 'crazyshit') . '/node/webform.structure.txt';
    drush_log('Creating the webform...', 'notice');
    dosomething_general_save_node_from_file($file, 'crazy/submit', 'crazy_webform_id');

    drush_log('Clearing cache...', 'notice');
    cache_clear_all();

    drush_log('Crazy $#!T Campaign is set up!', 'success');
  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}

function drush_crazyshit_crazy_image_fix() {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $s = webform_get_submissions(array('nid' => variable_get('crazy_webform_id')));

  drush_print(dt('Starting...'));

  $count = count($s);
  $i = 0;
  foreach ($s AS $sid => $submission) {
    if (!empty($submission)) {
      $path = drupal_realpath('public://') . '/styles/crazy_image_dimensions/public/crazyshit/' . basename($submission->field_crazy_crazy_picture[LANGUAGE_NONE][0]['uri']);

      $top = $submission->field_crazy_top_text[LANGUAGE_NONE][0]['value'];
      $bottom = $submission->field_crazy_bottom_text[LANGUAGE_NONE][0]['value'];

      if (!empty($top) || !empty($bottom)) {
        include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'crazyshit') . '/includes/image.php';
        write_text_to_image($path, $top, $bottom);
      }

      $m = 'Finished !c / !count';
    }
    else {
      $m = 'Ignored !c / !count';
    }

    $i++;
    drush_print(dt($m, array('!c' => $i, '!count' => $count)));
  }

  drush_print(dt('Finished!'));
}

function drush_crazyshit_crazy_messages() {
  $last = strtotime('7 days ago');
  $now = REQUEST_TIME;

  $notifications = db_select('crazy_notifications', 'n')
    ->fields('n', array('fid', 'type', 'notifid'));
  $notifications->addExpression("COUNT(*)", 'count');
  $notifications
    ->condition('fb', 0)
    ->condition('timestamp', array($last, $now), "BETWEEN")
    #->condition('origin', 1)
    ->groupBy('type')
    ->groupBy('uid');

  $n = $notifications->execute()->fetchAll();
  if (!empty($n)) {
    $users = array();
    foreach ($n AS $key => $info) {
      $users[$info->fid]/*[$info->type]*/ += $info->count;
    }

    include DRUPAL_ROOT . '/' . drupal_get_path('module', 'crazyshit') . '/plugin.php';
    $types = array(
      2 => 'bs',
      11 => 'vouch'
    );

    require_once DRUPAL_ROOT . '/' . libraries_get_path('facebook') . '/facebook.php';

    // Do Something App
    $config = array(
      'appId' => '105775762330',
      'secret' => '68e767e16e139277b1e7d2e2ba16a4f6'
    );
    // Initialize Facebook
    $facebook = new Facebook($config);

    $b = $i = $c = 0;
    $batches = array();
    foreach ($users AS $id => $counts) {
      $c = $counts;#max($counts);
     # $best = array_search($c, $counts);
      
      if ($i == $batch_limit) {
        $b++;
        $i = 0;
      }

      // Single batch request.
      $batches["$b"][] = array(
        'method' => 'POST',
        'relative_url' => '/' . $id . '/notifications',
        'body' => 'access_token=105775762330|pmFm2r3S-p7merbypvN2EANG4UI&href=' . CRAZY_ROOT . '&template=' . t($fb_messages['notification'], array('!n' => $c)),
      );

      $i++;
    }

    if (!empty($batches)) {
      // Loops through all batches and sends them in bulk.
      foreach ($batches AS $key => $batch) {
        $b = json_encode($batch);
        $res = $facebook->api('?batch=' . urlencode($b), 'POST');
      }
    }

    $ns = db_select('crazy_notifications', 'n')
      ->fields('n', array('notifid'))
      ->condition('fb', 0)
      ->condition('timestamp', array($last, $now), 'BETWEEN')
      ->execute();

    $keys = dosomething_general_array_vals_multi($ns->fetchAll());
    if (!empty($keys)) {
      db_update('crazy_notifications')
        ->fields(array(
          'fb' => 1
        ))
        ->condition('notifid', $keys, 'IN')
        ->execute();
    }
  }

  echo "Done.";
}
