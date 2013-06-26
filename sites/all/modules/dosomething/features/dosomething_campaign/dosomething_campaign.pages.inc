<?php

/**
 * @file
 * Page callbacks for dosomething_campaigns module.
 */

function dosomething_campaign_join_page($nid) {
  global $user;
  
  // If user has already joined, redirect to the campaign.
  if (dosomething_campaign_is_user_signed_up($user->uid, $nid)) {
    drupal_goto('node/' . $nid);
  }

  $node = node_load($nid);
  
  $page = theme(
  	'campaign_join_page',
  	array(
  	  'node' => $node,
  	  'uid' => $user->uid,
  	  'form' => drupal_get_form('dosomething_campaign_join_page_form', $nid, $user->uid)
  	)
  );

  print $page;	
  drupal_exit();
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

  global $user;
  dosomething_campaign_signup($user, $campaign_nid);

  // Me knows this is bad.  Could not get redirect working properly
  drupal_goto('node/' . $campaign_nid);
}
