<?php
/**
 * @file
 * Admin settings and configurations for Hunt Report Back module
 */

/**
 * Form builder function for module settings.
 */
function hunt_report_back_settings() {

  // A field set for basic configuration
  $form['basic'] = array(
  	'#type' => 'fieldset',
  	'#title' => t('Basic'),
    '#collapsible' => TRUE
  );

  // A field set for challenge specific content
  $form['challenges'] = array(
    '#type' => 'fieldset',
    '#title' => t('Challenges'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE
  );


  $default_date = array(
  	'month' => 7,
  	'day' => 17,
  	'year' => 2013
  );

  // Report back start date
  $form['basic']['hunt_report_back_start_date'] = array(
  	'#type' => 'date',
  	'#title' => t('Start date'),
  	'#default_value' => variable_get('hunt_report_back_start_date', $default_date)
  );

  // Report back end date
  $form['basic']['hunt_report_back_end_date'] = array(
  	'#type' => 'date',
  	'#title' => t('End date'),
  	'#default_value' => variable_get('hunt_report_back_end_date', $default_date)
  );

  //  The time of day to toggle avaialble challenges
  $form['basic']['hunt_report_back_update_time'] = array(
  	'#type' => 'textfield',
  	'#title' => t('Update Time'),
  	'#size' => 20,
  	'#description' => t('This is the time when the challenges should update daily'),
  	'#default_value' => variable_get('hunt_report_back_update_time', '10:00')
  );

  // The number of challenges available
  $challenge_limit = variable_get('hunt_report_back_challenge_limit', 11);
  // $form['basic']['hunt_report_back_challenge_limit'] = array(
  // 	'#type' => 'select',
  // 	'#title' => t('Number of Challenges'),
  // 	'#options' => array_combine(range(1,20), range(1,20)),
  // 	'#default_value' => $challenge_limit
  // );

  // The redirect path after submission
  $form['basic']['hunt_report_back_redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Submission Redirect Location'),
    '#size' => 20,
    '#default_value' => variable_get('hunt_report_back_redirect', 'hunt')
  );

  for($i=1; $i<=$challenge_limit; $i++) {
  	$challenge = 'hunt_report_back_challenge_' . $i;

  	$form['challenges'][$challenge] = array(
  	  '#type' => 'fieldset',
  	  '#title' => t('Challenge #!challenge', array('!challenge' => $i)),
  	  '#collapsible' => TRUE,
  	  '#collapsed' => TRUE
  	);

  	$form['challenges'][$challenge][$challenge . '_name'] = array(
  	  '#type' => 'textfield',
  	  '#title' => t('Name'),
  	  '#default_value' => variable_get($challenge . '_name', '')
  	);

  	$form['challenges'][$challenge][$challenge . '_question'] = array(
  	  '#type' => 'textfield',
  	  '#title' => t('Question'),
  	  '#default_value' => variable_get($challenge . '_question', '')
  	);
  }

  return system_settings_form($form);
}
