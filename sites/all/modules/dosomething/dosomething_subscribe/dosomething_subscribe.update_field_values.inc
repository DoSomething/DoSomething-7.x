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

  //////// Bulk update nodes by type: //////////////

  // Grant Application (see dosomething_petitions_ideas)
  $mobilecommons = 150463;
  $mailchimp = 'Grants2012';
  $nids = dosomething_subscribe_get_nids('grant_application');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  // Petition
  $mailchimp = 'Petitions2012'; //from dosomething_general_webform_email_and_mobile_subscribe
  $mobilecommons = 117371; //dosomething_general_mobile_commons_subscribe($val, PETITIONS_MCOMMONS);
  $nids = dosomething_subscribe_get_nids('petition');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  // Project_report
	$mobilecommons = 150223;
	$mailchimp = 'Projects2012';
  $nids = dosomething_subscribe_get_nids('project_report');
  foreach ($nids as $nid) {
    dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);
  }

  //////// Individual nodes: /////////////////

  // Volunteer webform:
  // if ($form_id == 'webform_client_form_' . variable_get('volunteer_webform', 728802)) {
  // dosomething_general_volunteer_webform_submit
  // nid 728802 volunteer text responder application
  // $mobile_commons_bucket = variable_get('volunteer_mobile_commons_bucket', 150443);
  // variable volunteer_mobile_commons_bucket is not defined
  $nid = 728802;
  $mobilecommons = '150443';
  $mailchimp = 'Volunteers2013';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

  // 727601: Do Something Awards Application
  /*
  // This is commented out for now, scholarship_application_with_rec doesn't 
  // have the mailchimp field added yet because the features are so cray.
  $nid = 727601;
  $mailchimp = 'DSA2013Applicants';
  dosomething_subscribe_update_node_fields($nid, $mailchimp);
  */

  // 727716: DO SOMETHING AWARDS NOMINATION FORM
  $nid = 727716;
  $mailchimp = 'DSA2013Nominees';
  dosomething_subscribe_update_node_fields($nid, $mailchimp);

  // 728929  gun-policy has a conditional signup.  Based on birthdate field, subscribe to two different groups.
  //@todo: 1) do we even need this? 2) how would we do conditionals?
  $nid = 728929;
  $mailchimp = 'ControlSurvey2013'; // Young People
  $mailchimp_2 = 'GunControlReport2013'; // Old People.
  dosomething_subscribe_update_node_fields($nid, $mailchimp);

  // 719564: Contact Me About Boot Camp
  $nid = 719564;
  $mailchimp = 'Bootcamp2012NYC';
  $mobilecommons = '153803';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

  // 719546: Contact Me About Scholarships
  $nid = 719546;
  $mailchimp = 'ScholarshipInterest2012';
  $mobilecommons = '150493';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

  // 719550: Contact Me About Clubs
  $nid = 719550;
  $mailchimp = 'Clubs2012';
  $mobilecommons = '124101';
  dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons);

  // 719551: Contact Me About Grants
  $nid = 719551;
  $mailchimp = 'Grants2012';
  $mobilecommons = '150463';
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
/**
 * Updates given node for nid with given mailchimp and mobilecommons ids.
 */
function dosomething_subscribe_update_node_fields($nid, $mailchimp, $mobilecommons = NULL) {
  watchdog('dosomething_subscribe', 'Updating fields for ' . $nid . ' mailchimp=' . $mailchimp . ' mobilecommons=' . $mobilecommons);
  $node = node_load($nid);
  watchdog('dosomething_subscribe', 'Node ' . $node->nid . ' loaded');
  $node->field_mailchimp_group_id[LANGUAGE_NONE][0]['value'] = $mailchimp;
  if ($mobilecommons) {
    $node->field_mc_optin[LANGUAGE_NONE][0]['value'] = $mobilecommons;
  }
  watchdog('dosomething_subscribe', 'Node ' . $node->nid . ' updated');
  node_save($node);
  watchdog('dosomething_subscribe', 'Node ' . $node->nid . ' saved');
}