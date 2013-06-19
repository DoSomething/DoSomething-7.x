<?php

/**
 * @file
 * Plugin to provide access control/visibility based on a cookie value.
 */

$plugin = array(
  'title' => t('Cookie matches'),
  'description' => t('Control access given a cookie value.'),
  'callback' => 'ctools_cookie_ctools_access_check',
  'settings form' => 'ctools_cookie_ctools_access_settings',
  'summary' => 'ctools_cookie_ctools_access_summary',
  'default' => array('context' => 0, 'expression' => ''),
);

/**
 * Settings form
 */
function ctools_cookie_ctools_access_settings($form, &$form_state, $conf) {
  $form['settings']['cookie'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie Name'),
    '#description' => t('What is the key of the cookie?'),
    '#default_value' => $conf['cookie'],
  );

  $form['settings']['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#default_value' => $conf['value'],
    '#description' => t('What should the value of the cookie be?'),
  );

  return $form;
}

/**
 * Check for access.
 */
function ctools_cookie_ctools_access_check($context, $something, $conf) {
  $cookie = $context['cookie'];
  $value = $context['value'];

  if (!empty($_COOKIE[$cookie])) {
    if ($vals = unserialize($_COOKIE[$cookie])) {
      foreach ($vals as $val) {
        if ($value == $val) {
          return true;
        }
      }
    }
    else if ($_COOKIE[$cookie] == $value) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

/**
 * Provide a summary description.
 */
function ctools_cookie_ctools_access_summary($conf, $context) {
  return t('Matches a cookie value');
}