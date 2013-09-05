<?php

/**
 * @file
 * Used for admin pages in dosomething_terminator functionality. 
 **/

/**
 * Form constructor for the Terminator admin settings form.
 *
 * @ingroup forms
 */
function dosomething_terminator_admin_settings_form() {
  $form = array();
  $form['dosomething_terminator_is_terminating'] = array(
    '#type' => 'checkbox',
    '#title' => t('Run Terminator cron queue'),
    '#default_value' => variable_get('dosomething_terminator_is_terminating', FALSE),
    '#description' => "What's in the queue?  Check " . l('the Terminator report.', 'admin/reports/dosomething_terminator'),
  );
  $form['dosomething_terminator_batch_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Batch size'),
    '#default_value' => variable_get('dosomething_terminator_batch_size', 100),
  );
  return system_settings_form($form);
}

/**
 * Page callback: Displays batches queued for the Terminator.
 *
 * @return array
 *   A render array for a page containing a list of content.
 *
 * @see dosomething_terminator_menu()
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
    return t('There are no items to be terminated.');
  }
}