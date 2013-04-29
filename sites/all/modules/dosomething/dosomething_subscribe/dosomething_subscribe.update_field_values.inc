<?php
/**
 * @file
 * Code for one-time import, used to import hard coded values into relevant node fields.
 * This file can eventually be removed once everything is working beautifully.
 */

/**
 * Updates field values based on node type.
 */
function dosomething_subscribe_update_field_values() {

  // For node type: grant_applications (dosomething_petitions_ideas)
  $mobilecommons = 150463;
  $mailchimp = 'Grants2013';
  $nids = dosomething_subscribe_get_nids('grant_application');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  // Petitions Ideas webform - dosomething_petitions_form_alter -> dosomething_petitions_ideas
  $nid = 728676;
  $mobilecommons = 147563;
  $mailchimp = 'UserSubmittedPetitions2013';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

  // if node_type == petition
  // dosomething_petitions_optin:
  //dosomething_general_webform_email_and_mobile_subscribe($form, $form_state);
  //dosomething_general_mobile_commons_subscribe($val, PETITIONS_MCOMMONS);
  $mailchimp = 'Petitions2012'; //from dosomething_general_webform_email_and_mobile_subscribe
  $mobilecommons = 117371; //dosomething_general_mobile_commons_subscribe($val, PETITIONS_MCOMMONS);
  $nids = dosomething_subscribe_get_nids('petition');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  // For node node type: project_report
	$mobilecommons = 150223;
	$mailchimp = 'Projects2012';
  $nids = dosomething_subscribe_get_nids('project_report');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  // Volunteer webform:
  // if ($form_id == 'webform_client_form_' . variable_get('volunteer_webform', 728802)) {
  // dosomething_general_volunteer_webform_submit
  // nid 728802 volunteer text responder application
  // $mobile_commons_bucket = variable_get('volunteer_mobile_commons_bucket', 150443);
  // variable volunteer_mobile_commons_bucket is not defined
  $nid = 728802;
  $mobilecommons = 150443;
  $mailchimp = 'Volunteers2013';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

}

function dosomething_subscribe_get_nids($node_type) {
  $nids = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->fields('n', array('type'))
      ->condition('n.type', $node_type)
      ->execute()
      ->fetchCol(); // returns an indexed array
  return $nids;
}

function dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons) {
  $node = node_load($nid);
  $node->field_mc_optin[LANGUAGE_NONE][0]['value'] = $mobilecommons;
  $node->field_mailchimp_group_id[LANGUAGE_NONE][0]['value'] = $mailchimp;
  node_save($node);  
}