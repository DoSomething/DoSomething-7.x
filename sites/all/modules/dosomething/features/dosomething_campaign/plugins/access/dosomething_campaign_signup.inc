<?php

/**
 * @file
 * Plugin to provide access control/visibility based on whether or not a user has signed up for a campaign.
 */

$plugin = array(
  'title' => t('Node campaign: User is signed up'),
  'description' => t('Controls access based on if a user is signed up for the campaign node.'),
  'callback' => 'dosomething_campaign_signup_ctools_access_check',
  'settings form' => 'dosomething_campaign_signup_access_settings',
  'summary' => 'dosomething_campaign_signup_ctools_access_summary',
  'default' => array('is_signedup' => 0),
  'required context' => new ctools_context_required('Node', 'node'),
);

/**
 * Settings form.
 */
function dosomething_campaign_signup_access_settings($form, &$form_state, $conf) {
  $form['settings']['is_signedup'] = array(
    '#type' => 'radios',
    '#title' => t('User signup value'),
    '#options' => array(FALSE => t('Not signed up'), TRUE => ('Signed up')),
    '#default_value' => $conf['is_signedup'],
  );
  return $form;
}

/**
 * Check for access.
 *
 * @context object
 *  The loaded node.
 * @conf array
 *  The configuration settings for this instance of the access plugin.
 */
function dosomething_campaign_signup_ctools_access_check($conf, $context) {
  global $user;
  // Check whether or not the logged in user signed up for the $context node.
  $user_is_signedup = dosomething_signups_is_user_signed_up($user->uid, $context->data->nid);
  // Return whether or not that matches the setting on the access plugin instance.
  return ($user_is_signedup == $conf['is_signedup']);
}

/**
 * Provide a summary description.
 */
function dosomething_campaign_signup_ctools_access_summary($conf, $context) {
  return t('User signedup == @signed_up', array('@signed_up' => $conf['is_signedup']['value']));
}
