<?php 

/**
 * @file
 * Code for MOMM campaign.
 */

/**
 * Form constructor for the user profile school field form.
 *
 * @see dosomething_campaign_momm_signup_data_form_submit()
 *
 * @ingroup forms
 */
function dosomething_campaign_momm_signup_data_form($form, &$form_state) {
  $form = array();
  $form['header'] = array(
    '#markup' => '<h1>What school do you go to?</h1>',
  );
  $form['school_state'] = array(
    '#type' => 'select',
    '#title' => t("What state is your school in?"),
    '#options' => _dosomething_school_get_states(),
  );
  $form['gsid'] = array(
    '#type' => 'textfield',
    '#title' => t("Start typing your school's name. We'll offer suggestions."),
    '#autocomplete_path' => 'ds_school/api/autocomplete',
  );
  $form['no_school'] = array(
    '#type' => 'radios',
    '#prefix' => '<hr><p>Or:</p>',
    '#options' => array(
      'school not listed' => t('My school is not listed.'),
      'not affiliated' => t('I am not affiliated with a school.'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update My Information'),
    '#attributes' => array('class' => array('btn', 'primary')),
  );
  return $form;
}

/**
 * Form submission handler for dosomething_campaign_momm_signup_data_form().
 *
 * @see dosomething_campaign_momm_signup_data_form()
 */
function dosomething_campaign_momm_signup_data_form_submit(&$form, &$form_state) {
  global $user;
  $signup_data = array();
  $school_name = check_plain($form_state['values']['gsid']);
  // Find value inbetween the []'s:
  preg_match_all("^\[(.*?)\]^", $school_name, $gsid, PREG_PATTERN_ORDER);
  $gsid = $gsid[1][0];
  // If school_id, write it to profile.
  if (!empty($gsid)) {
    //@todo: get school ID by GSID
    dosomething_user_update_school($user, $school_id);
    $signup_data['school_id'] = $gsid;
  }
  else {
    $signup_data['no_school'] = $form_state['values']['no_school'];
  }
  // Update signups record with signup_data.
  if (module_exists('dosomething_signups')) {
    $nid = variable_get('momm_campaign_nid', 731098);
    dosomething_signups_update_signup_data($user->uid, $nid, $signup_data);
  }
  // Tell the browser to close the modal.
  // @see dosomething_modal_form_builder() for where this is executed.
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
}
