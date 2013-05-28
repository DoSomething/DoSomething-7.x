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
  $prefix = 'dosomething_login_user_register_';
  // Default values (for when none are set but email/cell is present):
  $form['defaults'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default User Registration'),
    '#collapsible' => FALSE,
    '#description' => t('Default text to use for registration form if a campaign is not specified.'),
  );
  $form['defaults'][$prefix . 'title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'title'),
  );
  $form['defaults'][$prefix . 'headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Headline'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'headline'),
  );
  $form['defaults'][$prefix . 'headline'] = array(
    '#type' => 'textarea',
    '#title' => t('Headline'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'headline'),
  );
  $form['defaults'][$prefix . 'sidebar_headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Sidebar Headline'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'sidebar_headline'),
  );
  $form['defaults'][$prefix . 'sidebar_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Sidebar Content'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'sidebar_content'),
  );
  return system_settings_form($form);
}
