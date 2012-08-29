<?php

/**
 * @file
 *   Holds module specific forms for PicsForPets FB Apps.
 */

/**
 * Form for the zip code popup associated with the proximity based view filter.
 */
function dosomething_fb_apps_enter_zip_form($form, &$form_state) {
  $form['container-title'] = array (
    '#type' =>  'container',
    '#attributes' => array (
      'class' => array('container-title'),
      ),
    );

  $form['container-title']['helptext'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => t('Enter your zipcode so we can show you the pets closest to you.'),
  );

  $form['container'] = array (
    '#type' =>  'container',
    '#attributes' => array (
      'class' => array('zip-search-container'),
    ),
  );

  $form ['container']['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Zip:'),
    '#required' => TRUE,
  );

  $form ['container']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('dosomething_fb_apps_enter_zip_form_submit'),
  );
  $form['message'] = array(
    '#type' =>  'container',
    '#attributes' => array (
      'id' => 'enter-zip-field-message',
    ),
  );

  return $form;
}

function dosomething_fb_apps_enter_zip_form_validate($form, &$form_state) {
  $found_zip = db_query('SELECT zip FROM {zipcodes} WHERE zip = :zip', array(':zip' => $form_state['values']['zip']))->fetchField();
  if (!$found_zip) {
    form_set_error('zip', 'The zip code you entered does not appear to be valid or is not one we know about.');
  }
}

function dosomething_fb_apps_enter_zip_form_submit($form, &$form_state) {
  global $user;
  $fbid = fboauth_fbid_load($user->uid);
  $zip = $form_state['values']['zip'];
  $record = array(
    'fbid' => $fbid,
    'zip' => $zip,
  );
  $found_user = db_query('SELECT fbid FROM {ds_fb_user_zips} WHERE fbid = :fbid', array('fbid' => $fbid))->fetchField();
  if (!$found_user) {
    drupal_write_record('ds_fb_user_zips', $record);
  }
  else {
    drupal_write_record('ds_fb_user_zips', $record, 'fbid');
  }
  //$form_state['redirect'] = array($_GET['q'], array('query' => array('sort_by' => 'closest_to_me')));
}
