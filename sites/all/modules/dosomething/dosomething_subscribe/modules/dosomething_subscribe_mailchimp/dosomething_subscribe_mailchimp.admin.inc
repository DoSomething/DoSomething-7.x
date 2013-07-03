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
  $key_state = variable_get('dosomething_subscribe_mailchimp_is_api_state_valid');
  // Alter Mailchimp Key description based on current API key state variable:
  if (!$key_state) {
    $description = "<span style='background:yellow;padding:4px;font-weight:bold;'>Invalid API state reported on " . format_date(variable_get('dosomething_subscribe_mailchimp_api_state_invalid_time')) . ".</span>";
  }
  else {
    $description = 'API state last validated on ' . format_date(variable_get('dosomething_subscribe_mailchimp_api_state_last_validated')) . '.';

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
  // Get current state.
  $is_current_state_valid = variable_get('dosomething_subscribe_mailchimp_is_api_state_valid', FALSE);
  // Set submitted values as variables.
  variable_set('mailchimp_api_key', $form_state['values']['mailchimp_api_key']);
  variable_set('mailchimp_use_secure', $form_state['values']['mailchimp_use_secure']);
  variable_set('mailchimp_batch_limit', $form_state['values']['mailchimp_batch_limit']);
  variable_set('dosomething_subscribe_mailchimp_notify_email', $form_state['values']['dosomething_subscribe_mailchimp_notify_email']);
  // Check connection to Mailchimp API with inputted API key.
  $mcapi = dosomething_subscribe_mailchimp_get_api_object();
  if ($mcapi) {
    // Notify that service has been restored if valid key was FALSE, and set it to TRUE.
    if (!$is_current_state_valid) {
      variable_set('dosomething_subscribe_mailchimp_is_api_state_valid', TRUE);
      global $language;
      drupal_mail('dosomething_subscribe_mailchimp', 'restored_api_state', variable_get('dosomething_subscribe_mailchimp_notify_email', 'developers@dosomething.org'), $language);
      // Log the good news.
      watchdog('dosomething_subscribe_mailchimp', 'MC API state restored with key @key.', array('@key' => variable_get('mailchimp_api_key')));
    }
  }
}

/**
 * Page callback for the Cron queue report.
 */
function dosomething_subscribe_mailchimp_queue_status_page() {
  $rows = array();
  // Select DOSOMETHING_SUBSCRIBE_MAILCHIMP_QUEUE_CRON records from queue table.
  $query = db_select("queue", "q")
    ->fields("q", array("item_id", "data", "created"))
    ->condition('name', DOSOMETHING_SUBSCRIBE_MAILCHIMP_QUEUE_CRON, '=')
    ->extend('TableSort')->extend('PagerDefault')->limit(50);
  $result = $query->execute();

  while ($record = $result->fetchObject()) {
    $signup_data = unserialize($record->data);
    $rows[] = array(
      $record->item_id,
      format_date($record->created, 'short'),
      $signup_data['email'],
      $signup_data['group_name'],
      $signup_data['list_id'],
      serialize($signup_data['merge_vars']),
    );
  }

  if (!empty($rows)) {
    $header = array(t('Item ID'), t('Created'), t('Email'), t('Group Name'), t('List ID'), t('Merge Vars'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output . theme("pager");;
  }
  else {
    return t('There are no items in the queue.');
  }
}

/**
 * Page callback for the Grouping ID variable report.
 */
function dosomething_subscribe_mailchimp_grouping_ids_status_page() {
  $map = variable_get('dosomething_subscribe_mailchimp_grouping_ids', array());
  $groupings_last_updated = variable_get('dosomething_subscribe_mailchimp_grouping_ids_updated');
  $output = "Last updated: " . format_date($groupings_last_updated);
  foreach ($map as $list_id => $groupings) {
    $output .= '<h1>' . $list_id . '</h1>';
    $header = array($list_id . ' - Group Name', 'Grouping ID');
    foreach($groupings as $group_name => $grouping_id) {
      $rows[] = array($group_name, $grouping_id);
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  }
  $output .= render(drupal_get_form('dosomething_subscribe_mailchimp_reset_grouping_ids_form'));
  return $output;
}

/**
 * Form callback for resetting Grouping IDs variable.
 */
function dosomething_subscribe_mailchimp_reset_grouping_ids_form($form, &$form_state) {
  $form['header'] = array(
    '#markup' => '<h1>Manual Sync</h1><p>The Grouping IDs automatically refresh on a daily basis.  You can manually refresh them by submitting this form, but it should be done only when necessary, as to keep Mailchimp API requests to a minimum.</p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sync Grouping IDs from Mailchimp API'),
  );
  return $form;
}

/**
 * Submit handler to reset Grouping IDs variable.
 */
function dosomething_subscribe_mailchimp_reset_grouping_ids_form_submit() {
  dosomething_subscribe_mailchimp_set_grouping_id_vars();
  drupal_set_message("Grouping IDs refreshed.");
}
