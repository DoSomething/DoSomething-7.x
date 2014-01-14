<?php 

/**
 * @file
 * Code for tfj campaign.
 */

/**
 * Form constructor for the TFJ signup data form.
 *
 * @see dosomething_campaign_tfj_signup_data_form_submit()
 *
 * @ingroup forms
 */
function dosomething_campaign_tfj_signup_data_form($form, &$form_state) {
  $form = array();
  $form['#attributes'] = array('onKeyPress'=>"return window.suppressEnter(event);");
  $form['header'] = array(
    '#markup' => '<h1>Almost there!</h1><h2>Sign up your school to get a free banner and enter to win a $4,000 scholarship.</h2>',
  );
  $form['school_state'] = array(
    '#type' => 'select',
    '#title' => t("What state is your school in?"),
    // Add an empty item for default:
    '#options' => array_merge(array('' => ''),_dosomething_school_get_states()),
    '#ajax' => array(
      'callback' => 'dosomething_campaign_tfj_signup_ajax_gsid_callback',
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
      'callback' => 'dosomething_campaign_tfj_signup_ajax_school_not_found_callback',
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
    $form['school_not_found']['#markup'] = 'Sorry about that! Please email <a href="mailto://teensforjeans@dosomething.org" target="_blank">teensforjeans@dosomething.org</a> with your state and the name of your school.';
  }
  $form['not_affiliated'] = array(
    '#type' => 'checkbox',
    '#title' => t("I won't be participating with a school."),
  );
  $form['address_header'] = array(
    '#markup' => '<h3>Enter your shipping address below:</h3>',
  );
  $form['address_name'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Your Name'),
    ),
  );
  $form['address1'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Address 1'),
    ),
  );
  $form['address2'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Address 2'),
    ),
  );
  $form['address_city'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('City'),
    ),
  );
  $form['address_state'] = array(
    '#type' => 'select',
    '#options' => array_merge(array('' => 'State'),_dosomething_school_get_states()),
  );
  $form['address_zip'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Zip'),
    ),
  );
  $form['poster_footer'] = array(
    '#markup' => '<p><em>Banners will arrive in 1-2 weeks.</em></p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#attributes' => array(
      'class' => array(
        'btn',
        'btn-cta-medium'
      )
    )
  );

  return $form;
}

/**
 * AJAX callback for gsid form element.
 */
function dosomething_campaign_tfj_signup_ajax_gsid_callback($form, $form_state) {
  return $form['gsid'];
}

/**
 * AJAX callback for school_not_found form element.
 */
function dosomething_campaign_tfj_signup_ajax_school_not_found_callback($form, $form_state) {
  return $form['school_not_found'];
}

/**
 * Form validation handler for dosomething_campaign_tfj_signup_data_form().
 *
 * @see dosomething_campaign_tfj_signup_data_form()
 */
function dosomething_campaign_tfj_signup_data_form_validate(&$form, &$form_state) {
  $school_name = check_plain($form_state['values']['gsid']);
  // If "school not found" selected:
  if ($school_name == check_plain(DOSOMETHING_SCHOOL_NOT_FOUND_KEY)) {
    // No other validation is needed.
    return;
  }
  // If no school value and no checkbox, they didn't select anything.
  if (empty($school_name) && !$form_state['values']['not_affiliated']) {
    // Set error to prevent submit.
    form_set_error('gsid', "Please select a school from the list, or check \"I won't be participating with a school\" if you're not in a school.");
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
  // If an address field has been populated, make sure they all have values:
  if (!empty($form_state['values']['address_name']) || !empty($form_state['values']['address1']) || !empty($form_state['values']['address_city']) || !empty($form_state['values']['address_state']) || !empty($form_state['values']['address_zip'])) {
    if (empty($form_state['values']['address_name'])) {
      form_set_error('address_name', 'Please enter your name.');
    }
    if (empty($form_state['values']['address1'])) {
      form_set_error('address1', 'Please enter your address.');
    }
    if (empty($form_state['values']['address_city'])) {
      form_set_error('address_city', 'Please enter your city.');
    }
    if (empty($form_state['values']['address_state'])) {
      form_set_error('address_state', 'Please select your state.');
    }
    if (empty($form_state['values']['address_zip'])) {
      form_set_error('address_zip', 'Please enter your zipcode.');
    }
  }
}

/**
 * Form submission handler for dosomething_campaign_tfj_signup_data_form().
 *
 * @see dosomething_campaign_tfj_signup_data_form_validate()
 */
function dosomething_campaign_tfj_signup_data_form_submit(&$form, &$form_state) {
  global $user;
  $tfj_nid = variable_get('tfj_campaign_nid', 731115);

  // Initalize array to store data into signups table:
  $signup_data = array();

  // Check for "Not affiliated" value first:
  if ($form_state['values']['not_affiliated'] == 1) {
    $signup_data = -1;
  }
  // Else if a school has been found:
  elseif (isset($form_state['values']['school_id'])) {
    // Save school id to user profile.
    dosomething_user_update_school($user, $form_state['values']['school_id']);  
    // Write gsid to signups table:
    $signup_data = $form_state['values']['gsid'];
  }
  // Else if "school not listed" if that option was selected:
  elseif ($form_state['values']['gsid'] == DOSOMETHING_SCHOOL_NOT_FOUND_KEY) {
    $signup_data = 0;
  }
  
  // If we have enough address values to actually mail something to someone:
  if (!empty($form_state['values']['address_name']) && !empty($form_state['values']['address1']) && !empty($form_state['values']['address_city']) && !empty($form_state['values']['address_state']) && !empty($form_state['values']['address_zip'])) {
    // Submit to Address List:
    $address_data = array(
      'uid' => $user->uid,
      'nid' => $tfj_nid,
      'email' => $user->mail,
      'name' => $form_state['values']['address_name'],
      'address1' => $form_state['values']['address1'],
      'address2' => $form_state['values']['address2'],
      'city' => $form_state['values']['address_city'],
      'state' => $form_state['values']['address_state'],
      'zip' => $form_state['values']['address_zip'],
    );
    dosomething_campaign_submit_signup_address($address_data);
  }

  // Update signups record with signup_data.
  if (module_exists('dosomething_signups')) {
    dosomething_signups_update_signup_data($user->uid, $tfj_nid, $signup_data);
  }
  // Tell the browser to close the modal.
  // @see dosomething_modal_form_builder() for where this is executed.
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  // Manually create a Drupal message div for confirmation:
  $form_state['ajax_commands'][] = ajax_command_after('#breadcrumb', '<div class="messages status">Got it. Thanks for the info!</div>');
}

/**
 * Returns either a link to the TFJ gate, or a form to signup an auth user.
 *
 * @param string $label 
 *  Label to display on the signup button.
 * @param array $classes 
 *  Array of css classes to apply to the signup button.
 *
 * @return string
 *  HTML of either the link, or the rendered form to print.
 */
function dosomething_campaign_tfj_get_signup_button($label = 'Do This', $classes = array('btn', 'btn-cta-large')) {
  global $user;
  $tfj_nid = variable_get('tfj_campaign_nid', 731115);
  // If anonymous user, return link to the TFJ gate page:
  if ($user->uid == 0) {
    return l($label, 'user/login', array(
      'attributes' => array('class' => $classes),
      'query' => array('destination' => 'node/' . $tfj_nid),
    ));
  }
  // Otherwise, return the rendered Campaign Join form:
  return render(drupal_get_form('dosomething_campaign_tfj_join_form', $label, $classes));
}

/**
 * Form constructor for the join form for logged-in user who hasn't signed up yet.
 *
 * @see dosomething_campaign_tfj_signup_data_form_submit()
 *
 * @param string $label
 *  Label to display on the submit button.
 *
 * @ingroup forms
 */
function dosomething_campaign_tfj_join_form($form, &$form_state, $label, $classes) {
  $form = array();
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $label,
    '#attributes' => array(
      'class' => $classes,
    ),
  );
  return $form;
}

/**
 * Form submission handler for dosomething_campaign_tfj_join_form().
 *
 * @see dosomething_campaign_tfj_join_form()
 */
function dosomething_campaign_tfj_join_form_submit(&$form, &$form_state) {
  global $user;
  $node = node_load(variable_get('tfj_campaign_nid', 731115));
  dosomething_campaign_signup($user, $node);
}

/**
 * Page callback for TFJ Report page.
 *
 * @see dosomething_campaign_menu()
 */
function dosomething_campaign_tfj_report_page() {
  return 'There are currently <strong>' . dosomething_campaign_get_distinct_schools_from_signups() . '</strong> schools signed up for Teens for Jeans.';
}

/*
 * Selects the count of distinct schools from dosomething_campaign_signups for TFJ.
 *
 * @return int
 */
function dosomething_campaign_get_distinct_schools_from_signups() {
  $nid = variable_get('tfj_campaign_nid', 731115);
  $table = 'dosomething_campaign_signups';
  $result = db_select($table)
    ->fields($table, array('data'))
    ->condition('nid', $nid)
    // Filter out non-gsid values:
    ->condition('data', 0, '>')
    ->distinct()
    ->countQuery()
    ->execute()
    ->fetchField();
  return $result;
}
