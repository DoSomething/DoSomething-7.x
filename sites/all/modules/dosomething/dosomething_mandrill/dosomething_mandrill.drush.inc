<?php

/**
 *  Implements hook_drush_command()
 */
function dosomething_mandrill_drush_command() {
  return array(
    'dispatch-events' => array(
      'description' => 'Send Mandrill messages based on user events - birthday, membership aniversary, etc.',
      'aliases' => array('dispatch'),
      'drupal dependencies' => array('dosomething_mandrill'),
    ),
  );
}

/*
 * Drush command to trigger sending Mandrill based messages to Drupal based user
 * accounts for:
 *
 * - Birthdays - dsevent-birthday
 * - 90 Days since registration - dsevent-reg-90
 * - Registration aniverasry - dsevent-reg-365
 *     Every year up to the first user registration (2008)
 */
function drush_dosomething_mandrill_dispatch_events($op, $target_date = NULL) {
  try {
    
    $results = dosomething_mandrill_dispatch_events($op, $target_date);
    
    drush_print(dt($results['send_status'] . " sending Mandrill messages."));
    drush_print(dt($results['sent'] . " messages sent..."));

  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}