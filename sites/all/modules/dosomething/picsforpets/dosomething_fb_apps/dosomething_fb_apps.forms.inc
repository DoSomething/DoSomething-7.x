<?php

/**
 * @file
 *   Holds module specific forms for PicsForPets FB Apps.
 */

/**
 * Form for the zip code popup associated with the proximity based view filter.
 */
function dosomething_fb_apps_enter_zip_form($form, &$form_state) {
  // Add a flag to the form to allow us to reset the sort on the view if needed.
  if (!empty($form_state['reset_sort'])) {
    $form['#reset_sort'] = TRUE;
  }
  else {
    $form['#reset_sort'] = FALSE;
  }

  // Add the previously selected animal filter option if it existed.
  $form['#animal_type'] = !empty($form_state['animal_type']) ? $form_state['animal_type'] : '';

  $form['container-title'] = array(
    '#type' =>  'container',
    '#attributes' => array (
      'class' => array('container-title'),
      ),
    );

  $form['container-title']['title'] = array(
    '#prefix' => '<h1>',
    '#suffix' => '</h1>',
    '#markup' => t('Where You At?'),
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

  $form['container']['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Zip:'),
    '#required' => TRUE,
  );
  $form['container']['animal_type'] = array(
    '#type' => 'hidden',
  );

  $form['container']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
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
  // Add a flag to make us go back to the proper page.
  $form_state['reset_sort'] = TRUE;
  $form_state['animal'] = $form_state['values']['animal_type'];
  $form_state['rebuild'] = TRUE;
}
