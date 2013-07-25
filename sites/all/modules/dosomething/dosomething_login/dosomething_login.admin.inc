<?php

/**
 * @file
 * Used for admin pages in dosomething_login functionality. 
 **/

/**
 * Returns a system_settings_form used to set dosomething_login variables.
 */
function dosomething_login_admin_settings_form() {
  $form = array();
  // Prefix all variable names with dosomething_login:
  $prefix = 'dosomething_login_gate_';
  // Default values (for when none are set but email/cell is present):
  $form['gate'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Registration Page Settings'),
    '#collapsible' => FALSE,
    '#description' => t('Default text to use for registration form if a campaign is not specified.'),
  );
  $form['gate'][$prefix . 'page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#description' => 'The TITLE attribute in the HTML HEAD',
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'page_title'),
  );
  $form['gate'][$prefix . 'headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Headline'),
    '#description' => 'H1 headline on the page',
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'headline'),
  );
  $form['gate'][$prefix . 'subheadline'] = array(
    '#type' => 'textfield',
    '#title' => t('Subtitle'),
    '#description' => 'H2 subheadline',
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'subheadline'),
  );
  $form['gate'][$prefix . 'description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => 'Copy below the subheadline',
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'description'),
  );
  $form['gate'][$prefix . 'color'] = array(
    '#type' => 'textfield',
    '#title' => t('Copy Accent Color'),
    '#description' => 'HEX, RGB/a or CSS color shorthand used for the headline and subheadline color',
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'color'),
  );
  return system_settings_form($form);
}
