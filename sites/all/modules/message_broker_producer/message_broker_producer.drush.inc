<?php

/**
 *  Implements hook_drush_command
 *
 *  ex:dispatch-drips
 *  drush dispatch-drips <operation (dsdrip-momm)> <target drop (1-5)> <YYYY-MM-DD> <test flag (1 or 0)>
 */
function message_broker_producer_drush_command() {
  return array(
    'message-broker-producer-test' => array(
      'description' => 'Sends test producer test entry to RabbitMQ.',
      'aliases' => array('producer-test'),
      'drupal dependencies' => array('message_broker_producer'),
    ),
  );
}

/*
 * Drush command to trigger sending Mandrill based message based on Drupal
 * producer entry:
 *
 */
function drush_message_broker_producer_test() {
  try {
    
    $results = message_broker_producer_test();
    drush_print(dt('Test producer entry sent...'));

  }
  catch (Exception $e) {
    drush_log(dt('Sorry, there was an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}