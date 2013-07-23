<?php

/**
 * @file
 * Page callbacks for dosomething_campaigns module.
 */

function dosomething_campaign_join_page($nid) {
  global $user;
  // If user has already joined and is non admin, redirect to the campaign.
  if (dosomething_campaign_is_user_signed_up($user->uid, $nid) && !dosomething_campaign_can_user_override_join($user)) {
    drupal_goto('node/' . $nid);
  }
  return drupal_get_form('dosomething_campaign_join_page_form', $nid, $user->uid);
}

function dosomething_campaign_join_page_form($form, &$form_state, $nid, $uid) {
  $form['uid'] = array(
  	'#type' => 'hidden',
  	'#value' => $uid 
  );
  $form['nid'] = array(
  	'#type' => 'hidden',
  	'#value' => $nid 
  );
  $form['submit'] = array(
  	'#type' => 'submit',
  	'#value' => t('Start')
  );

  $form['#submit'][] = 'dosomething_campaign_join_page_form_submit';

  return $form;
}

function dosomething_campaign_join_page_form_submit($form, &$form_state) {
  //  Lets submit and redirect.
  $campaign_nid = $form_state['values']['nid'];
  $campaign_node = node_load($campaign_nid);
  global $user;
  dosomething_campaign_signup($user, $campaign_node);
  // Me knows this is bad.  Could not get redirect working properly.
  drupal_goto('node/' . $campaign_nid);
}
