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

