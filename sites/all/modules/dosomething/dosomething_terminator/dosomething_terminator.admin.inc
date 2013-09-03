<?php

/**
 * @file
 * Used for admin pages in dosomething_terminator functionality. 
 **/

/**
 * Returns a form used to set dosomething_terminator variables.
 */
function dosomething_terminator_admin_settings_form() {
  $form = array();
  $form['dosomething_terminator_is_terminating'] = array(
    '#type' => 'checkbox',
    '#title' => t('Terminate nodes'),
    '#default_value' => variable_get('dosomething_terminator_is_terminating', FALSE),
  );
  $form['dosomething_terminator_current_node_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Node type to kill'),
    '#default_value' => variable_get('dosomething_terminator_current_node_type', NULL),
  );
  $form['dosomething_terminator_batch_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Batch size'),
    '#default_value' => variable_get('dosomething_terminator_batch_size', 100),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save Settings',
  );
  return $form;
}

/**
 * Page callback for the Terminator queue report.
 */
function dosomething_terminator_queue_status_page() {
  $rows = array();
  $query = db_select("queue", "q")
    ->fields("q", array("item_id", "data", "created"))
    ->condition('name', DOSOMETHING_TERMINATOR_QUEUE_CRON, '=')
    ->extend('TableSort')->extend('PagerDefault')->limit(50);
  $result = $query->execute();

  while ($record = $result->fetchObject()) {
    $signup_data = unserialize($record->data);
    $rows[] = array(
      $record->item_id,
      format_date($record->created, 'short'),
      $signup_data['node_type'],
      serialize($signup_data['nids']),
    );
  }

  if (!empty($rows)) {
    $header = array(t('Item ID'), t('Created'), t('Node Type'), t('Nids'),);
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output . theme("pager");;
  }
  else {
    return t('There are no items in the queue.');
  }
}