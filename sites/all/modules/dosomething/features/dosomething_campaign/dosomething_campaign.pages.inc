<?php

/**
 * @file
 * Page callbacks for dosomething_campaigns module.
 */

/**
 * Page callback for campaign/join/% page.
 */
function dosomething_campaign_join_page($nid) {
  global $user;
  // If user has already joined and is non admin, redirect to the campaign.
  if (dosomething_campaign_is_user_signed_up($user->uid, $nid) && !dosomething_campaign_can_user_override_join($user)) {
    drupal_goto('node/' . $nid);
  }
  // Populate page content with relevant gate values from the campaign node.
  $node = node_load($nid);
  drupal_set_title($node->title);
  $page['gate_headline'] = $node->field_gate_headline[LANGUAGE_NONE][0]['value'];
  $page['gate_subheadline'] = $node->field_gate_subheadline[LANGUAGE_NONE][0]['value'];
  $page['gate_description']= $node->field_gate_description[LANGUAGE_NONE][0]['value'];
  $page['gate_image_src'] = file_create_url($node->field_gate_image[LANGUAGE_NONE][0]['uri']);
  $page['gate_image_alt'] = $node->field_gate_image[LANGUAGE_NONE][0]['alt'];
  $page['form'] = drupal_get_form('dosomething_campaign_join_page_form', $nid, $user->uid);
  return $page;
}

/**
 * Form for campaign join form.
 */
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

/**
 * Form submit function for campaign join form.
 */
function dosomething_campaign_join_page_form_submit($form, &$form_state) {
  //  Lets submit and redirect.
  $campaign_node = node_load($form_state['values']['nid']);
  global $user;
  dosomething_campaign_signup($user, $campaign_node);
  // Me knows this is bad.  Could not get redirect working properly.
  drupal_goto('node/' . $campaign_node->nid);
}
