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
    elseif (dosomething_signups_is_user_signed_up($user->uid, $node->nid)) {
      // Redirect to node.
      drupal_goto('node/' . $node->nid);
    }
  }
  // Load relevant page variables from the node:
  drupal_set_title($node->title);
  $page['nid'] = $node->nid;
  $page['gate_headline'] = $node->field_gate_headline[LANGUAGE_NONE][0]['value'];
  $page['gate_subheadline'] = $node->field_gate_subheadline[LANGUAGE_NONE][0]['value'];
  $page['gate_description']= $node->field_gate_description[LANGUAGE_NONE][0]['value'];
  $page['gate_image_src'] = file_create_url($node->field_gate_image[LANGUAGE_NONE][0]['uri']);
  $page['gate_image_alt'] = $node->field_gate_image[LANGUAGE_NONE][0]['alt'];
  $page['gate_color'] = $node->field_gate_color[LANGUAGE_NONE][0]['value'];
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
  $form_state['redirect'] = 'node/' . $node->nid;
}
