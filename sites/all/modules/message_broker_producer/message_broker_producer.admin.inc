<?php

/**
 * @file
 * Content administration and module settings UI.
 */

/**
 * Configuration form
 */
function message_broker_producer_config_form($form, &$form_state) {

  $form['authentication'] = array(
    '#type' => 'fieldset',
    '#title' => t('RabbitMQ Authentication')
  );
  $form['authentication']['message_broker_producer_rabbitmq_host'] = array(
    '#type' => 'textfield',
    '#title' => t('host'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_rabbitmq_host', 'localhost'),
  );
  $form['authentication']['message_broker_producer_rabbitmq_port'] = array(
    '#type' => 'textfield',
    '#title' => t('port'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_rabbitmq_port', '5672'),
  );
  $form['authentication']['message_broker_producer_rabbitmq_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_rabbitmq_username', 'guest'),
  );
  $form['authentication']['message_broker_producer_rabbitmq_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_rabbitmq_password', 'guest'),
  );
  $form['authentication']['message_broker_producer_rabbitmq_vhost'] = array(
    '#type' => 'textfield',
    '#title' => t('vhost'),
    '#required' => FALSE,
    '#default_value' => variable_get('message_broker_producer_rabbitmq_vhost', ''),
  );

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Producer Configuration')
  );
  $form['configuration']['message_broker_producer_application_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('message_broker_producer_application_id', '-1'),
  );
  $form['configuration']['message_broker_producer_rabbitmq_transactional_exchange'] = array(
    '#type' => 'textfield',
    '#title' => t('Target Exchange'),
    '#required' => TRUE,
    '#default_value' => variable_get('essage_broker_producer_rabbitmq_transactional_exchange', 'transactionalExchange'),
  );

  return system_settings_form($form);
}

/**
 * List RabbitMQ status
 */
function message_broker_producer_status() {

  $status = '';

  // List queues
  /* @todo: permission access issues for www user
   *
   * http://unix.stackexchange.com/questions/15264/executing-a-shell-command-from-php-with-shell-exec
   * Added:
   * http    ALL=(username) /usr/local/sbin/rabbitmqctl
   * to /etc/sudoers
   *
   * Program Execution in PHP: exec, system, passthru, and shell_exec, oh my!
   * http://chipmunkninja.com/Program-Execution-in-PHP%3A-exec-m@
   *
   * works
   * $directoryListing = shell_exec('ls -la /usr/local/sbin');
   */
  $queues = shell_exec('/usr/local/sbin/rabbitmqctl list_queues');
  if ($queues == NULL) {
    $status['queues'] = 'Queue Listing - No RabbitMQ queues found, check that RabbitMQ is running.';
  }
  else {
    $status['queues'] = print_r($queues, TRUE);
  }

  // List exchanges
  $exchanges = shell_exec('/usr/local/sbin/rabbitmqctl list_exchanges');
  if ($exchanges == NULL) {
    $status['exchanges'] = 'Exchange Listing - No RabbitMQ exchanges found, check that RabbitMQ is running.';
  }

  // List bindings
  $bindings = shell_exec('rabbitmqctl list_exchanges');
  if ($bindings == NULL) {
    $status['bindings'] = 'Bindings Listing - No RabbitMQ bindings found, check that RabbitMQ is running.';
  }

  // Test link to produce tranactionals queue entry
  $test_links['all'] = 'Generate ' . l('test producer entry', 'admin/config/services/message-broker-producer/test') . '.';
  $test_links['campaign-signup'] = 'Generate ' . l('test campaign-signup producer entry', 'admin/config/services/message-broker-producer/test/campaign-signup') . '.';
  $test_links['user-register'] = 'Generate ' . l('test user-register producer entry', 'admin/config/services/message-broker-producer/test/user-register') . '.';

  return theme('message_broker_producer_status', array('status' => $status, 'test_links' => $test_links));
}
