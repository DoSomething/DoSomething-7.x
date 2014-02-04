<?php

/**
 *  Implements hook_drush_command
 *
 *  ex:dispatch-drips
 *  drush dispatch-drips <operation (dsdrip-momm)> <target drop (1-5)> <YYYY-MM-DD> <test flag (1 or 0)>
 */
function dosomething_mandrill_drush_command() {
  return array(
    'dispatch-drips' => array(
      'description' => 'Send Mandrill messages based on drip campaigns. A drip consists of a series of drop messages.',
      'aliases' => array('mandrill-dispatch-drip'),
      'drupal dependencies' => array('dosomething_mandrill'),
    ),
  );
}

/*
 * Drush command to trigger sending Mandrill based messages to Drupal user
 * accounts for:
 *
 * - Mind on Your Money campaign - dsdrip-momm
 *
 * ex: drush mandrill-dispatch-drip dsdrip-momm 1 0 2013-11-04
 *
 * Optional target date, defaults to current date (minus a week) if not provided.
 *
 * @param string $op
 *   The drip operation to perform. ex: dsdrip-momm for the Mind on Your Money
 *   campaign.
 *
 * @param int $target_drop
 *   drip campaigns consist of a series of messages. The drop defines what
 *   message in the series to send and the related logic to target certain users
 *   who have signed up for the campaign. In the case of MOMM, each drop is a
 *   week apart from the time the user signed up.
 *
 * @param string $target_date
 *   The target date to base the drip query on. Use ISO 8601 (YYYY-MM-DD) date
 *   format.
 *
 * @param int $test_flag
 *   Enable (1) or disable (0) the use of test data when sending a drip message.
 */
function drush_dosomething_mandrill_dispatch_drips($op, $target_drop = 1, $target_date = NULL, $test_flag = TRUE) {
  try {
    
    $results = dosomething_mandrill_dispatch_drip($op, $target_drop, $target_date, $test_flag);
    
    drush_print(dt('Operation: ' . $op));
    drush_print(dt('Target Drop: ' . $target_drop));
    drush_print(dt('Target Date: ' . $target_date));
    drush_print(dt('Test Flag: ' . $test_flag));
    drush_print(dt($results['send_status']));
    drush_print(dt($results['sent'] . " messages sent..."));

  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}