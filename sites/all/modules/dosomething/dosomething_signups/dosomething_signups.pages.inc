<?php

/**
 * @file
 * Page callbacks for dosomething_signups module.
 */

/**
 * Page callback for campaign/join/% page.
 */
function dosomething_signups_join_page($node) {
  global $user;
  // If user can't override join page, check to see if signed up already.
  if (!dosomething_signups_can_user_override_join($user)) {
    // If node type is campaign:
    if ($node->type == 'campaign') {
      // If user already signed up:
      if (dosomething_campaign_is_user_signed_up($user->uid, $node->nid)) {
        // Redirect to campaign node.
        drupal_goto('node/' . $node->nid);
      }
    }
    // Else check if user already signed up in dosomething_signups:
    elseif ($node->type == 'project' && dosomething_signups_is_user_signed_up($user->uid, $node->nid)) {
      // Redirect to node.
      drupal_goto('node/' . $node->nid);
    }
  }
  // Load relevant page variables from the node:
  drupal_set_title($node->title);
  $page = dosomething_login_get_gate_vars($node);
  $page['form'] = drupal_get_form('dosomething_signups_join_page_form', $node);
  return $page;
}

/**
 * Form for join page.
 */
function dosomething_signups_join_page_form($form, &$form_state, $node) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $node->nid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start'),
  );
  return $form;
}

/**
 * Form submit handler for join page form.
 */
function dosomething_signups_join_page_form_submit($form, &$form_state) {
  $node = node_load($form_state['values']['nid']);
  global $user;
  // Sanity check:
  if ($user->uid == 0) {
    return;
  }
  if ($node->type == 'campaign') {
    dosomething_campaign_signup($user, $node);
  }
  else {
    dosomething_signups_signup($user, $node);
  }
  $form_state['redirect'] = 'node/' . $node->nid;
}
