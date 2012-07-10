<?php

/**
 * @file
 * Plugin to provide access control based upon webform submissions.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("User: submitted this webform"),
  'description' => t('Control access based on a webform submission.'),
  'callback' => 'dosomething_general_current_webform_submitted',
  'default' => array('nids' => array()),
  'summary' => 'dosomething_general_current_webform_submitted_summary',
  'required context' => array(
    new ctools_context_required(t('User'), 'user'),
    new ctools_context_required(t('Webform Node'), 'node'),
  ),
);

/**
 * Check for access.
 */
function dosomething_general_current_webform_submitted($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.

  module_load_include('inc', 'webform', 'includes/webform.submissions');

  $filter = array(
    'uid' => $context[0]->data->uid,
    'nid' => $context[1]->data->nid,
  );
  $subs = webform_get_submissions($filter);
  return (count($subs) > 0);
}

/**
 * Provide a summary description based upon the NIDs and logic.
 */
function dosomething_general_current_webform_submitted_summary($conf, $context) {
  if (!isset($conf['nids'])) {
    $conf['nids'] = array();
  }

  return t('@identifier has submitted the webform from @wf', array(
    '@identifier' => $context[0]->identifier,
    '@wf' => $context[1]->identifier,
  ));
}

