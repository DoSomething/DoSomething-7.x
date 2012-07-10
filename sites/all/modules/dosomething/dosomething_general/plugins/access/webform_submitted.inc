<?php

/**
 * @file
 * Plugin to provide access control based upon role membership.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("User: submitted webform"),
  'description' => t('Control access based on a webform submission.'),
  'callback' => 'dosomething_general_webform_submitted',
  'default' => array('nids' => array()),
  'settings form' => 'dosomething_general_webform_submitted_settings',
  'settings form submit' => 'dosomething_general_webform_submitted_settings_submit',
  'summary' => 'dosomething_general_webform_submitted_summary',
  'required context' => new ctools_context_required(t('User'), 'user'),
);

/**
 * Settings for the webform submitted access control.
 */
function dosomething_general_webform_submitted_settings($form, &$form_state, $conf) {
  $form['settings']['nids'] = array(
    '#type' => 'textarea',
    '#title' => t('NIDs'),
    '#default_value' => implode("\n", $conf['nids']),
    '#description' => t('Returns true only if the user has submitted any or all of these webform NIDs.'),
  );
  $form['settings']['one_form'] = array(
    '#type' => 'select',
    '#title' => t('Logic'),
    '#description' => t('Set to return TRUE if the user has submitted ONE of these webforms or ALL of these webforms.'),
    '#default_value' => $conf['one_form'],
    '#options' => array(0 => 'ALL', 1 => 'ONE'),
  );
  return $form;
}

/**
 * Compress the NIDs into an array.
 */
function dosomething_general_webform_submitted_settings_submit($form, &$form_state) {
  $form_state['values']['settings']['nids'] = explode("\n", $form_state['values']['settings']['nids']);
}

/**
 * Check for access.
 */
function dosomething_general_webform_submitted($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data) || !isset($context->data->roles)) {
    return FALSE;
  }

  module_load_include('inc', 'webform', 'includes/webform.submissions');

  $filter = array(
    'nid' => $conf['nids'],
    'uid' => $context->data->uid,
  );
  $subs = webform_get_submissions($filter);
  $nids = array();
  foreach ($subs as $sub) {
    $nids[$sub->nid] = $sub->nid;
  }
  // If we're checking for only submitted ONE of the forms
  if ($conf['one_form']) {
    return (count($nids) > 0);
  }
  // If we're checking if user submitted ALL forms
  else {
    return (count($nids) == count($conf['nids']));
  }
}

/**
 * Provide a summary description based upon the checked roles.
 */
function dosomething_general_webform_submitted_summary($conf, $context) {
  if (!isset($conf['nids'])) {
    $conf['nids'] = array();
  }

  return t('@identifier has submitted @logic of the following webform NIDs: @nids', array(
    '@identifier' => $context->identifier,
    '@logic' => ($conf['one_form']) ? 'ONE' : 'ALL',
    '@nids' => implode(", ", $conf['nids']),
  ));
}

