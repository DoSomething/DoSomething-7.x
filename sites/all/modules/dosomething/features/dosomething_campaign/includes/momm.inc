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
    '#markup' => '<h1>Almost there. Tell us your school to register your workshop!</h1>',
  );
  $form['school_state'] = array(
    '#type' => 'select',
    '#title' => t("What state is your school in?"),
    // Add an empty item for default:
    '#options' => array_merge(array('' => ''),_dosomething_school_get_states()),
    '#ajax' => array(
      'callback' => 'dosomething_campaign_momm_signup_ajax_gsid_callback',
      'wrapper' => 'autocomplete-by-state-ajax-replace',
    ),
  );
  $form['gsid'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div id="autocomplete-by-state-ajax-replace">',
    '#suffix' => '</div>',
  );
  // When the user changes value in the state field, 
  // We'll display the gsid as textfield and change the autocomplete_path to match.
  if (!empty($form_state['values']['school_state'])) {
    $form['gsid']['#type'] = 'textfield';
    $form['gsid']['#autocomplete_path'] = 'ds_school/api/autocomplete/' . $form_state['values']['school_state'];
    $form['gsid']['#title'] = t("Start typing your school's name. We'll offer suggestions.");
    $form['gsid']['#ajax'] = array(
      'callback' => 'dosomething_campaign_momm_signup_ajax_school_not_found_callback',
      'wrapper' => 'school-not-found-ajax-replace',
    );
  }
  $form['school_not_found'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div id="school-not-found-ajax-replace">',
    '#suffix' => '</div>',
  );
  // If "school not found" was selected from dropdown:
  if (!empty($form_state['values']['gsid']) && $form_state['values']['gsid'] == DOSOMETHING_SCHOOL_NOT_FOUND_KEY ) {
    // Display help text:
    $form['school_not_found']['#type'] = 'item';
    $form['school_not_found']['#markup'] = 'Please email <a href="mailto://money@dosomething.org" target="_blank">money@dosomething.org</a> to add your school.';
  }
  $form['not_affiliated'] = array(
    '#type' => 'checkbox',
    '#prefix' => '<hr>',
    '#title' => t('I am not affiliated with a school.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Register')
  );
  return $form;
}

/**
 * AJAX callback for gsid form element.
 */
function dosomething_campaign_momm_signup_ajax_gsid_callback($form, $form_state) {
  return $form['gsid'];
}

/**
 * AJAX callback for school_not_found form element.
 */
function dosomething_campaign_momm_signup_ajax_school_not_found_callback($form, $form_state) {
  return $form['school_not_found'];
}

/**
 * Form validation handler for dosomething_campaign_momm_signup_data_form().
 *
 * @see dosomething_campaign_momm_signup_data_form()
 */
function dosomething_campaign_momm_signup_data_form_validate(&$form, &$form_state) {
  $school_name = check_plain($form_state['values']['gsid']);
  // If "school not found" selected:
  if ($school_name == check_plain(DOSOMETHING_SCHOOL_NOT_FOUND_KEY)) {
    // No other validation is needed.
    return;
  }
  // If no school value and no checkbox, they didn't select anything.
  if (empty($school_name) && !$form_state['values']['not_affiliated']) {
    // Set error to prevent submit.
    form_set_error('gsid', "Please select a school from the list, or check 'unaffiliated' if you're not in a school.");
    return;
  }
  // If a school name has been selected:
  if (!empty($school_name)) {
    // This preg_match() looks for the last pattern like [33334] and if found extracts the numeric portion.
    $result = preg_match('/\[([0-9]+)\]$/', $school_name, $matches);
    // If a number was found:
    if ($result > 0) {
      $gsid = $matches[$result];
      // Lookup the ds_school entity ID:
      $school_id = dosomething_school_find_sid_by_gsid($gsid);
      // If it exists, set in the form_state['values']:
      if ($school_id) {
        $form_state['values']['gsid'] = $gsid;
        $form_state['values']['school_id'] = $school_id;
      }
    }
  }
}

/**
 * Form submission handler for dosomething_campaign_momm_signup_data_form().
 *
 * @see dosomething_campaign_momm_signup_data_form_validate()
 */
function dosomething_campaign_momm_signup_data_form_submit(&$form, &$form_state) {
  global $user;
  // Initalize array to store data into signups table:
  $signup_data = array();

  // Check for "Not affiliated" value first:
  if ($form_state['values']['not_affiliated'] == 1) {
    $signup_data['no_school'] = 'not affiliated';
  }
  // Else if a school has been found:
  elseif (isset($form_state['values']['school_id'])) { 
    // Write gsid to signups table:
    $signup_data['gsid'] = $form_state['values']['gsid'];
  }
  // Else if "school not listed" if that option was selected:
  elseif ($form_state['values']['gsid'] == DOSOMETHING_SCHOOL_NOT_FOUND_KEY) {
    $signup_data['no_school'] = 'school not listed';
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
