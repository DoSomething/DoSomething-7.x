<?php 

/**
 * @file
 * Code for MOMM campaign.
 */

/**
 * Form constructor for the user profile school field form.
 *
 * @see dosomething_campaign_momm_signup_data_form_submit()
 *
 * @ingroup forms
 */
function dosomething_campaign_momm_signup_data_form($form, &$form_state) {
  $form = array();
  // JS will only work if ds_neue library has already been loaded somewhere on the page.
  // Making the call to add the library from this form callback would give mixed results.
  $form['#attached']['js'][] = drupal_get_path('module', 'ds_neue') . '/js/location-finder.js';
  $form['header'] = array(
    '#markup' => '<h1>What school do you go to?</h1>',
  );
  $form['location_finder'] = array(
    '#markup' => theme('ds_neue_location_finder', array(
      'help_text' => t('Enter the zip code of your school.'),
      'results_text' => t('Nearest schools for zipcode:'),
      )
    ),
  );
  $form['school_id'] = array(
    '#title' => 'School ID',
    '#description' => 'This field will be hidden, and pre-populated with the Location Finder results',
    '#type' => 'textfield',
  );
  $form['no_school'] = array(
    '#type' => 'radios',
    '#prefix' => '<hr><p>Or:</p>',
    '#options' => array(
      'school not listed' => t('My school is not listed.'),
      'not affiliated' => t('I am not affiliated with a school.'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update My Information'),
    '#attributes' => array('class' => array('btn', 'primary')),
  );
  return $form;
}

/**
 * Form submission handler for dosomething_campaign_momm_signup_data_form().
 *
 * @see dosomething_campaign_momm_signup_data_form()
 */
function dosomething_campaign_momm_signup_data_form_submit(&$form, &$form_state) {
  global $user;
  $signup_data = array();
  $school_id = check_plain($form_state['values']['school_id']);
  // If school_id, write it to profile.
  if (!empty($school_id)) {
    dosomething_user_update_school($user, $school_id);
    $signup_data['school_id'] = $school_id;
  }
  else {
    $signup_data['no_school'] = $form_state['values']['no_school'];
  }
  // Update signups record with signup_data.
  if (module_exists('dosomething_signups')) {
    $nid = variable_get('momm_campaign_nid', 731098);
    dosomething_signups_update_signup_data($user->uid, $nid, $signup_data);
  }
  // Tell the browser to close the modal.
  // @see dosomething_modal_form_builder() for where this is executed.
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
}
