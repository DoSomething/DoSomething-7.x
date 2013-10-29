<?php

/**
 * @file
 * delete_signup_form content type.
 *
 */
$plugin = array(
 // 'single' => TRUE,
  'title' => t('User Delete Signup Form'),
  'description' => t('Allows user to delete signup for the current campaign.'),
  'category' => t('DoSomething Campaign'),
  'edit form' => 'delete_signup_form_edit_form',
  'render callback' => 'delete_signup_form_render',
  'admin info' => 'delete_signup_form_admin_info',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'help_text' => 'This form is visible only to DoSomething Staff.  Submit it to remove your signup from this campaign (for testing purposes).',
    'submit_label' => 'Remove Signup',
  ),
);

/**
 * Callback for content type admin info.
 */
function delete_signup_form_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = t('Delete Signup Form: <em>@submit_label</em>', array(
      '@submit_label' => $conf['submit_label'],
    ));
    $block->content = 'Help Text: ' . $conf['help_text'];
    return $block;
  }
}

/**
 * Callback for content type render.
 */
function delete_signup_form_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $nid = $context->data->nid;
  $form = drupal_get_form('dosomething_signups_delete_signup_form', $nid, $conf['submit_label']);
  $block = new stdClass();
  $block->content = '<p>' . $conf['help_text'] . '</p>' . $form;
  return $block;
}

/**
 * Callback for content type edit form.
 */
function delete_signup_form_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['help_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Help Text'),
    '#required' => TRUE,
    '#default_value' => $conf['help_text'],
    '#description' => 'Help text to display above submit button to reassure DS Staff nothing is broken.',
  );
  $form['submit_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Label'),
    '#required' => TRUE,
    '#default_value' => $conf['submit_label'],
    '#description' => 'Label to display on the submit button.',
  );
  return $form;
}

/**
 * Submit callback for delete_signup_form_edit_form().
 */
function delete_signup_form_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}