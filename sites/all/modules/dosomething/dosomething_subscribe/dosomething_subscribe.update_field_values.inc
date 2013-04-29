<?php
/**
 * @file
 * Code for one-time import, used to import hard coded values into relevant node fields.
 */

/**
 * Updates field values based on node type.
 */
function dosomething_subscribe_update_field_values() {


  // For node type: grant_applications (dosomething_petitions_ideas)
  $mobilecommons = 150463;
  $mailchimp = 'Grants2013';

  // For node type: petitions (dosomething_petitions_ideas)
  $mobilecommons = 147563;
  $mailchimp = 'UserSubmittedPetitions2013';

  // For node node type: project_report
	$mobilecommons = 150223;
	$mailchimp = 'Projects2012';

  // if ($form_id == 'webform_client_form_' . variable_get('million_webform', 728731)) { 
  // NID is not million users 728731, i also do not have a million_webform present
  $form['#submit'][] = 'dosomething_general_million_users_opt_in';  

  //if ($form_id == 'webform_client_form_' . variable_get('volunteer_webform', 728802)) {
  //dosomething_general_volunteer_webform_submit
  //nid 728802 volunteer text responder application
  //$mobile_commons_bucket = variable_get('volunteer_mobile_commons_bucket', 150443);
  // variable volunteer_mobile_commons_bucket is not defined
  $nid = 728802;
  $mobilecommons = 150443;
  $mailchimp = 'Volunteers2013';

}