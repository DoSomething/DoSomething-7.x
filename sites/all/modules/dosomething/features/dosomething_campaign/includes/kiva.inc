<?php

/**
 * @file
 * Code for Kiva campaign.
 */

/**
 * Form callback for signup beta form.
 */
function dosomething_campaign_beta_signup_form($form, &$form_state, $nid, $num_betas = 6) {
  $form['alpha_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your First Name:'),
    '#required' => TRUE,
  );
  $form['alpha_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Cell #:'),
    '#required' => TRUE,
  );
  $form['alpha_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Email:'),
    '#required' => TRUE,
  );
  $form['beta_mobiles'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  for ($i = 0; $i < $num_betas; $i++) {
    $form['beta_mobiles']['beta_mobile_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("Friend's cell #:"),
    );   
  }
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Share'),
  );
  return $form;
}

/**
 * Form validation callback for signup beta form.
 * @todo: Make dynamic?
 */
function dosomething_campaign_beta_signup_form_validate($form, &$form_state) {
  // Check for valid email address:
  if (!valid_email_address($form_state['values']['alpha_email'])) {
     form_set_error('alpha_email', t('Please provide a valid email address.'));
  }
  // Check for valid alpha cell:
  $alpha_mobile = $form_state['values']['alpha_mobile'];
  $alpha_mobile = preg_replace('#[^0-9]#', '', $alpha_mobile);
  if (!dosomething_general_valid_cell($alpha_mobile)) {
    form_set_error('alpha_mobile', t('Please provide a valid cell number.'));  
  }
  // Check for valid beta cell numbers:
  for ($i = 0; $i < 6; $i++) {
    if (!empty($form_state['values']['beta_mobile_' . $i])) {
      $beta_mobile = $form_state['values']['beta_mobile_' . $i];
      $beta_mobile = preg_replace('#[^0-9]#', '', $beta_mobile);
      if (!dosomething_general_valid_cell($beta_mobile)) {
        form_set_error('beta_mobile_' . $i, t('Please provide a valid cell number.'));  
      }
    }
  }
}

/**
 * Form submit callback for signup beta form.
 * @todo: Make dynamic?
 */
function dosomething_campaign_beta_signup_form_submit($form, &$form_state) {
  $args = array();

  $alpha_name = $form_state['values']['alpha_name'];
  $args['first_name'] = $alpha_name;

  $alpha_mobile = $form_state['values']['alpha_mobile'];
  $alpha_mobile = preg_replace('#[^0-9]#', '', $alpha_mobile);
  $alpha_email = $form_state['values']['alpha_email'];

  $beta_mobiles = array();
  // @todo: Make # of betas dymamic?  You could actually store the # of beta signups field on the campaign node.
  // Don't want to store it as a hidden form field in case anybody messes with it.
  for ($i = 0; $i < 6; $i++) {
    if (!empty($form_state['values']['beta_mobile_' . $i])) {
      $beta_mobile = $form_state['values']['beta_mobile_' . $i];
      $beta_mobile = preg_replace('#[^0-9]#', '', $beta_mobile);
      $beta_mobiles[] = $beta_mobile;
    }
  }

  // Load campaign node to get signup values.
  $nid = $form_state['values']['nid'];
  // @todo: Revisit this to make it dynamic.  For now, hardcoded to only work for Kiva campaign.
  if ($nid != 729307) {
    return;
  }

  // Call signup functions:
  $node = node_load($form_state['values']['nid']);
  $mailchimp_group = $node->field_mailchimp_group_id[LANGUAGE_NONE][0]['value'];
  $alpha_optin = $node->field_campaign_alphas_campaign[LANGUAGE_NONE][0]['value'];
  $beta_optin =$node->field_campaign_betas_campaign[LANGUAGE_NONE][0]['value'];
  
  // Mailchimp Signup:
  dosomething_subscribe_mailchimp_signup($alpha_email, $mailchimp_group);

  // Send Mandrill transactional email message
  $message['body'] = $alpha_name;
  dosomething_mandrill_dispatch($alpha_email, '25women', $message);

  // Mobilecommons Alpha+Beta signup:
  if (module_exists('dosomething_subscribe_mobilecommons')) {
    $response = dosomething_subscribe_mobilecommons_referral_signup($alpha_mobile, $alpha_optin, $beta_mobiles, $beta_optin, $args);
  }

  // Send to confirmation page with the relevant query string variables.
  drupal_goto('node/729332', array(
    'query' => array(
      'first_name' => $alpha_name, 
      'email' => $alpha_email,
    )
  ));
}
