<?php

/**
 * @file
 * Page callbacks for dosomething_campaigns module.
 */

function dosomething_campaign_join($nid) {
  global $user;
  $node = node_load($nid);
  
  $page = theme(
  	'campaign_join_page',
  	array(
  	  'node' => $node,
  	  'uid' => $user->uid,
  	  'form' => drupal_get_form('dosomething_campaign_join_form', $nid, $user->uid)
  	)
  );

  print $page;	
  drupal_exit();
}

function dosomething_campaign_join_form($form, &$form_state, $nid, $uid) {
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

  $form['#submit'][] = 'dosomething_campaign_join_form_submit';

  return $form;
}

function dosomething_campaign_join_form_submit($form, &$form_state) {
  //  Lets submit and redirect

  // dosomething_campaign_join_campaign($uid, $nid);

  // Me knows this is bad.  Could not get redirect working properly
  drupal_goto('node/' . $form_state['values']['nid']);
}

