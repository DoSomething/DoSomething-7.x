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
    '#description' => t('Enter your pics for pets App URL here. NOTE: This should be the FULL URL including the leading "http://"'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_url', ''),
  );

  $form['dosomething_picsforpets_fb_user_app_secure_url'] = array(
    '#type' => 'textfield',
    '#title' => t('App Secure URL'),
    '#size' => 20,
    '#maxlengh' => 50,
    '#description' => t('Enter your pics for pets App Secure URL here. NOTE: This should be the FULL URL including the leading "https://"'),
    '#default_value' => variable_get('dosomething_picsforpets_fb_user_app_secure_url', ''),
  );

  $form['dosomething_picsforpets_open_graph_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Open Graph Post Title'),
    '#size' => 60,
    '#maxlength' => 50,
    '#description' => t('You may define the title of the post that appears on people\'s walls through Open Graph.  Use <b>!name</b> for the pet\'s name and <b>!adjectives</b> for the pet\'s adjectives and they\'ll be replaced on the page.'),
    '#default_value' => variable_get('dosomething_picsforpets_open_graph_title', "Hi, I'm !name.  I'm !adjectives and I need a home."),
  );

  return system_settings_form($form);
}
