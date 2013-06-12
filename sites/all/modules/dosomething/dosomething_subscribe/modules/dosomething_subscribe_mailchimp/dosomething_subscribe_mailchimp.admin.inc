<?php

/**
 * @file
 * Used for admin pages in dosomething_subscribe functionality. 
 **/

/**
 * Returns a form used to set dosomething_subscribe_mailchimp variables.
 */
function dosomething_subscribe_mailchimp_admin_settings_form() {
  $form = array();
  $key_state = variable_get('dosomething_subscribe_mailchimp_is_api_key_valid');
  // Alter Mailchimp Key description based on current API key state variable:
  if (!$key_state) {
    $description = "Invalid API key reported on " . format_date(variable_get('dosomething_subscribe_mailchimp_api_key_invalid_time')) . ".  Please enable the key in Mailchimp and validate, or enter a new valid API key.";
  }
  else {
    $description = 'API key last validated on ' . format_date(variable_get('dosomething_subscribe_mailchimp_api_key_last_validated')) . '.';

  }
  $form['mailchimp_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Mailchimp API Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('mailchimp_api_key'),
    '#description' => $description,
  );
  $form['mailchimp_use_secure'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Secure Connection'),
    '#default_value' => variable_get('mailchimp_use_secure', TRUE),
    '#description' => t('Communicate with the MailChimp API over a secure connection.')
  ); 
  $form['mailchimp_batch_limit'] = array(
    '#type' => 'select',
    '#options' => array(
      '100' => '100',
      '250' => '250',
      '500' => '500',
      '1000' => '1000',
      '2500' => '2500',
      '5000' => '5000',
      '7500' => '7500',
      '10000' => '10000',
    ),
    '#title' => t('Batch limit'),
    '#required' => TRUE,
    '#description' => t('Maximum number of signups to process in a single cron run. Mailchimp suggests keeping this below 5000-10000.'),
    '#default_value' => variable_get('mailchimp_batch_limit', 100),
  );
  $form['dosomething_subscribe_mailchimp_notify_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Notification Email'),
    '#required' => TRUE,
    '#default_value' => variable_get('dosomething_subscribe_mailchimp_notify_email', 'developers@dosomething.org'),
    '#description' => t('Used to notify in case of an invalid API key error.')
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit and Validate',
  );
  return $form;
}

/**
 * Submit handler saves variables, and checks that the API key is valid against the Mailchimp service.
 */
function dosomething_subscribe_mailchimp_admin_settings_form_submit($form, &$form_state) {
  // Set variables:
  variable_set('mailchimp_api_key', $form_state['values']['mailchimp_api_key']);
  variable_set('mailchimp_use_secure', $form_state['values']['mailchimp_use_secure']);
  variable_set('mailchimp_batch_limit', $form_state['values']['mailchimp_batch_limit']);
  variable_set('dosomething_subscribe_mailchimp_notify_email', $form_state['values']['dosomething_subscribe_mailchimp_notify_email']);
  // Check connection to Mailchimp API with inputted API key.
  $mcapi = dosomething_subscribe_mailchimp_get_api_object();
  // Run a simple request in order to see if we get any errors.
  $response = $mcapi->getVerifiedDomains();
  if ($mcapi->errorCode) {
    if ($mcapi->errorCode == DOSOMETHING_SUBSCRIBE_MAILCHIMP_INVALID_API_KEY_ERROR_CODE) {
      dosomething_subscribe_mailchimp_invalid_api_notify();
    }
    drupal_set_message('Mailchimp API - Error Code ' . $mcapi->errorCode . ': ' . $mcapi->errorMessage, 'error');
  }
  else {
    // If API key was previously invalid, make it all better.
    variable_set('dosomething_subscribe_mailchimp_is_api_key_valid', TRUE);
    variable_set('dosomething_subscribe_mailchimp_api_key_last_validated', time());
    // Notify that service has been restored.
    drupal_mail('dosomething_subscribe_mailchimp', 'restored_api_key', variable_get('dosomething_subscribe_mailchimp_notify_email', 'developers@dosomething.org'), $language);
    // Log the good news.
    watchdog('dosomething_subscribe_mailchimp', 'API key is now valid for @key.', array('@key' => variable_get('mailchimp_api_key')));
  }
}

/**
 * Page callback for the Cron queue report.
 */
function dosomething_subscribe_mailchimp_queue_status_page() {
  $rows = array();
  $result = db_query("SELECT item_id, data, created FROM {queue} WHERE name = :name ORDER BY item_id",
    array(':name' => DOSOMETHING_SUBSCRIBE_MAILCHIMP_QUEUE_CRON),
    array('fetch' => PDO::FETCH_ASSOC));
  foreach ($result as $item) {
    $item['created'] = format_date($item['created'], 'short');
    $signup_data = unserialize($item['data']);
    $item['email'] = $signup_data['email'];
    $item['group_name'] = $signup_data['group_name'];
    $item['list_id'] = $signup_data['list_id'];
    $item['merge_vars'] = serialize($signup_data['merge_vars']);
    unset($item['data']);
    $rows[] = $item;
  }
  if (!empty($rows)) {
    $header = array(t('Item ID'), t('Created'), t('Email'), t('Group Name'), t('List ID'), t('Merge Vars'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
  }
  else {
    return t('There are no items in the queue.');
  }
}
