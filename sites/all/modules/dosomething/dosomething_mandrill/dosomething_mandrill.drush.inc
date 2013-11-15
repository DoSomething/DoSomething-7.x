<?php

/**
 *  Implements hook_drush_command()
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
 */
function drush_dosomething_mandrill_dispatch_drips($op, $target_drop=1, $test_flag=TRUE, $target_date=NULL) {
  try {
    
    $results = dosomething_mandrill_dispatch_drip($op, $target_drop, $test_flag, $target_date);
    
    drush_print(dt($results['send_status']));
    drush_print(dt($results['sent'] . " messages sent..."));

  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}