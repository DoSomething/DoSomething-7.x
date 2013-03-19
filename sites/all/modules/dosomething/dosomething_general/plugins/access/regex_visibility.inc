<?php

/**
 * @file
 * Plugin to provide access control/visibility based on a RegEx match.
 */

$plugin = array(
  'title' => t('Regular Expression Matches'),
  'description' => t('Control access given a regular expression..'),
  'callback' => 'ctools_regex_ctools_access_check',
  'settings form' => 'ctools_regex_ctools_access_settings',
  'summary' => 'ctools_regex_ctools_access_summary',
  'default' => array('context' => 0, 'expression' => ''),
);

/**
 * Settings form
 */
function ctools_regex_ctools_access_settings($form, &$form_state, $conf) {
  $form['settings']['note'] = array(
    '#type' => 'markup',
    '#markup' => "<p>Regular expressions are a powerful way to match against dynamic data.  RegEx is also very dangerous if used wrong...<b>If you're not sure what you're doing, don't use this!</b>",
  );

  $form['settings']['context'] = array(
    '#type' => 'select',
    '#title' => t('Context'),
    '#description' => t('What context should the regular expression match against?'),
    '#options' => array(
      0 => t('Current path (default)'),
      1 => t('Request URI (includes query strings)'),
      2 => t('Query string'),
    )
  );

  $form['settings']['expression'] = array(
    '#type' => 'textarea',
    '#title' => t('Expression'),
    '#default_value' => $conf['expression'],
    '#description' => t('This expression will attempt to match against the criteria chosen above.'),
  );

  $form['#validate'][] = 'ctools_regex_ctools_validate';

  return $form;
}

/**
 *  Validates the settings form to check for valid regular expression.
 */
function ctools_regex_ctools_validate($form, &$form_state) {
  $regex = $form_state['input']['settings']['expression'];

  if (@preg_match('/' . $regex . '/si', '/crazy/about') === FALSE) {
    form_set_error('settings][expression', t('Your regular expression is invalid.  Remember to escape your meta characters.  The delimeter is a forward-slash ("/")'));
  }
}

/**
 * Check for access.
 */
function ctools_regex_ctools_access_check($context, $something, $conf) {
  $what = $context['context'];
  $expression = $context['expression'];

  $match = '';
  switch ($what) {
    case 0:
      $match = request_path();
    break;
    case 1:
      $match = request_uri();
    break;
    case 2:
      $match = $_SERVER['QUERY_STRING'];
    break;
  }

  $m = preg_match('/' . $expression . '/si', $match);
  return !empty($m);
}

/**
 * Provide a summary description.
 */
function ctools_regex_ctools_access_summary($conf, $context) {
  return t('Matches a regular expression');
}