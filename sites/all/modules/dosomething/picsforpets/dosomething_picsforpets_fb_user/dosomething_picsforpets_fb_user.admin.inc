<?php

/**
 * @file
 * Administrative functions for PicsForPets Facebook Users module.
 */

/**
 * Menu callback: PicsForPets Facebook Users settings form.
 */
function dosomething_picsforpets_fb_user_settings_form() {
  $form = array();

  $form['dosomething_picsforpets_fb_user_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
    '#size' => 20,
    '#maxlengh' => 50,
    '#description' => t('Enter your pics for pets App ID here.'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_id', ''),
  );

  $form['dosomething_picsforpets_fb_user_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('App Secret'),
    '#size' => 40,
    '#maxlengh' => 50,
    '#description' => t('Enter your pics for pets App Secret here.'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_secret', ''),
  );

  $form['dosomething_picsforpets_fb_user_app_url'] = array(
    '#type' => 'textfield',
    '#title' => t('App URL'),
    '#size' => 20,
    '#maxlengh' => 50,
    '#description' => t('Enter your pics for pets App URL here.'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_url', ''),
  );

  $form['dosomething_picsforpets_fb_user_app_secure_url'] = array(
    '#type' => 'textfield',
    '#title' => t('App Secure URL'),
    '#size' => 20,
    '#maxlengh' => 50,
    '#description' => t('Enter your pics for pets App Secure URL here.'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_secure_url', ''),
  );

  return system_settings_form($form);
}
