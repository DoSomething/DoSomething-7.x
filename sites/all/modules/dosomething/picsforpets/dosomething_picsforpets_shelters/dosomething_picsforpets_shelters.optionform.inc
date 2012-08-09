<?php

/**
 * @file
 *   Creates the page callback and related functions for the menu entry at
 *   pics-for-pets/shelter-search-options
 */

/**
 * Generates the lookup form when used in the context of selecting your shelter.
 * Well store the result of the final selection in the only reliable place (the
 * user's session data. This form is mostly a duplicate of the one above as most
 * but not all functionality needs to be duplicated.
 */
function dosomething_picsforpets_shelters_options_form($form, &$form_state) {
  // Initialize variables.
  $form_state['more_times'] = isset($form_state['more_times']) ? $form_state['more_times'] : 0;
  $form_state['view_more'] = isset($form_state['view_more']) ? $form_state['view_more'] : FALSE;
  $form_state['add-shelter'] = isset($form_state['add-shelter']) ?  $form_state['add-shelter'] : FALSE;
  $form_state['submit-new-address'] = isset($form_state['submit-new-address']) ? $form_state['submit-new-address'] : FALSE;
  $form = array();

  $form['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'dosomething_picsforpets_shelters') . '/js/shelter_options.js',
    ),
  );

  $form['helptext'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => t('Enter the zip code and select the shelter where you snapped your animal pic.'),
  );
  $form['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Zip:'),
    '#weight' => 0,
  );
  $form['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#weight' => 0,
    '#ajax' => array(
      'callback' => 'dosomething_picsforpets_shelters_lookup_form_options_submit_ajax',
      'wrapper' => 'shelter-results',
    ),
    '#submit' => array('dosomething_picsforpets_shelters_lookup_options_form_submit'),
    '#validate' => array('dosomething_picsforpets_shelters_lookup_options_form_validate'),
  );

  // Initialize the options variable
  $options = array();
  if (isset($form_state['results'])) {
    $options = $form_state['results'];
  }
  if (!empty($form_state['results'])) {
    $options['-1'] = t('I want to use a shelter not on the list.');
  }
  $form['results'] = array(
    '#prefix' => '<div id="shelter-results">',
    '#suffix' => '</div>',
    '#weight' => 2,
    '#type' => 'radios',
    '#attributes' => array(
      'class' => array('shelter-results-option-list'),
    ),
    '#options' => $options,
  );
  $form['results']['shelter-add'] = array(
    '#type' => 'fieldset',
    '#weight' => 3,
    '#attributes' => array(
      'class' => array('conditional-address-fieldset'),
    ),
    'shelter_name' => array(
      '#type' => 'textfield',
      '#title' => t('Shelter Name'),
    ),
    'address' => array(
      '#type' => 'textfield',
      '#title' => t('Address'),
    ),
    'city' => array(
      '#type' => 'textfield',
      '#title' => t('City'),
    ),
    'state' => array(
      '#type' => 'textfield',
      '#title' => t('State'),
    ),
    'shelter_zip' => array(
      '#type' => 'textfield',
      '#title' => t('Zip'),
    ),
    'hours' => array(
      '#type' => 'textarea',
      '#title' => t('Hours'),
    ),
  );
  if (!empty($form_state['view_more'])) {
    $form['results']['view_more_button'] = array(
      '#type' => 'submit',
      '#value' => t('View More'),
      '#weight' => 4,
      '#ajax' => array(
        'callback' => 'dosomething_picsforpets_shelters_lookup_form_options_submit_ajax',
        'wrapper' => 'shelter-results',
      ),
      '#submit' => array('dosomething_picsforpets_shelters_options_load_more'),
    );
  }
  $form['select-shelter'] = array(
    '#type' => 'submit',
    '#value' => t('Select'),
    '#weight' => 5,
    '#ajax' => array(
      'callback' => 'dosomething_picsforpets_shelters_lookup_form_options_submit_ajax',
      'wrapper' => 'shelter-results',
    ),
    '#submit' => array('dosomething_picsforpets_shelters_select_shelter_submit'),
    '#validate' => array('dosomething_picsforpets_shelters_select_shelter_validate'),
  );
  return $form;
}

/**
 * Validation handler for the "Search" button. Ensures that a zip code has been
 * entered.
 */
function dosomething_picsforpets_shelters_lookup_options_form_validate($form, &$form_state) {
  if (empty($form_state['values']['zip'])) {
    form_set_error('zip', 'A zip code is required to search for shelters near you.');
  }
}

/**
 * Validation handler for the "Select" button. Ensures that if a new address is
 * being added, then all fields are required.
 */
function dosomething_picsforpets_shelters_select_shelter_validate($form, &$form_state) {
  // If they are not trying to add a new shelter then we don't need to validate.
  if ($form_state['values']['results'] != -1) {
    return;
  }
  $address_elements = array(
    'shelter_name' => t('Shelter Name'),
    'address' => t('Address'),
    'city' => t('City'),
    'state' => t('State'),
    'shelter_zip' => t('Zip'),
    'hours' => t('Hours'),
  );
  $errors = FALSE;
  foreach ($address_elements as $field => $title) {
    if (empty($form_state['values'][$field])) {
      $errors = TRUE;
      form_set_error($field, t('@field is required.', array('@field' => $title)));
    }
  }
  if (!$errors) {
    $form_state['submit-new-address'] = TRUE;
  }
}

/**
 * Form submission handler for the "Search" button on the shelter lookup form
 * with options.
 */
function dosomething_picsforpets_shelters_lookup_options_form_submit($form, &$form_state) {
  // Reset the variables if we are hitting the search button rather than
  // 'view more'.
  if (isset($form_state['values']['op']) && $form_state['values']['op'] == 'Search') {
    $form_state['more_times'] = 0;
    $form_state['view_more'] = FALSE;
    $form_state['more_results'] = '';
    $form_state['more_results_all'] = array();
  }
  $zip = $form_state['values']['zip'];
  // We retreive an extra result and then throw it away so that we know if we
  // should show the 'view more' button.
  $shelter_nids = dosomething_picsforpets_shelters_get_shelters_by_zip($zip, 0, 11);
  // Show the more button?
  $form_state['view_more'] = dosomething_picsforpets_shelters_more_shelters($shelter_nids);
  $options = dosomething_picsforpets_shelters_formatted_results($shelter_nids, 'options');
  $form_state['results'] = $options;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the view more button on the shelter options lookup form.
 */
function dosomething_picsforpets_shelters_options_load_more($form, &$form_state) {
  // Make sure we initialize the variable.
  $form_state['more_results_all'] = isset($form_state['more_results_all']) ? $form_state['more_results_all'] : array();

  // Update the number of times the more button has been clicked so we know how
  // many results to skip in our result set.
  $form_state['more_times']++;

  // Fetch the originally submitted zip code.
  $zip = $form_state['values']['zip'];
  // In some cases (Ajaxy magic we're doing on webform entity) the value of the
  // zip is not getting passed through to the $form_state['values'] array
  // properly. In this case, let's just check to see if it's actully in the
  // $form_state['input'] array.
  if (empty($zip) && !empty($form_state['input']['zip'])) {
    $zip = $form_state['input']['zip'];
  }

  // We retreive an extra result and then throw it away so that we know if we
  // should show the 'view more' button.
  $shelter_nids = dosomething_picsforpets_shelters_get_shelters_by_zip($zip, $form_state['more_times'] * 10, 11);
  // Show the more button?
  $form_state['view_more'] = dosomething_picsforpets_shelters_more_shelters($shelter_nids);
  // Get the returned results as a list of options.
  $options = dosomething_picsforpets_shelters_formatted_results($shelter_nids, 'options');
  // Add the data to the form state.
  $form_state['more_results'] = $options;
  // We append the results to the former results list so we have the appropriate
  // content for non JS submissions.
  $form_state['more_results_all'] = $form_state['more_results_all'] + $options;
  $form_state['results'] = $form_state['results'] + $options;
  // Instruct the form to rebuild with the new content.
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "Select" button on the shelter options form.
 * This has different behavior depending on the form state.
 */
function dosomething_picsforpets_shelters_select_shelter_submit($form, &$form_state) {
  $selected_shelter = $form_state['values']['results'];
  if ($selected_shelter > 0) {
    $form_state['add-shelter'] = FALSE;
    $shelter_data = node_load($selected_shelter);
    $address = field_get_items('node', $shelter_data, 'field_pfp_address');
    $_SESSION['shelter'] = array(
      'shelter_nid' => $selected_shelter,
      'shelter_name' => $shelter_data->title,
      'address' =>  $address[0]['thoroughfare'],
      'city' => $address[0]['locality'],
      'state' => $address[0]['administrative_area'],
      'shelter_zip' =>  $address[0]['postal_code'],
      'hours' => '',
    );
    drupal_set_message('Thanks. We\'ve received your choosen shelter.');
  }
  // Otherwise they're trying to add a new shelter so check if they already
  // entered data. We'll store the new shelter on the $_SESSION array so we can
  // pull it off on other forms later.
  elseif ($form_state['submit-new-address']) {
    $shelter = array(
      'shelter_nid' => 0,
      'shelter_name' => $form_state['values']['shelter_name'],
      'address' => $form_state['values']['address'],
      'city' => $form_state['values']['city'],
      'state' => $form_state['values']['state'],
      'shelter_zip' => $form_state['values']['shelter_zip'],
      'hours' => $form_state['values']['hours'],
    );
    $_SESSION['shelter'] = $shelter;
    drupal_set_message('Thanks. We\'ve received the address of your shelter.');
  }
  // Otherwise they only clicked the select button but didn't add a new address.
  else {
    $form_state['add-shelter'] = TRUE;
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Ajax callback for all submit buttons on the shelter options lookup form.
 */
function dosomething_picsforpets_shelters_lookup_form_options_submit_ajax($form, &$form_state) {
  drupal_add_js(array('picsforpetsShelterOptions' => array('showSelect' => TRUE)), 'setting');
  // If being called from an embedded form, nest the return results.
  if (isset($form['#nested_pets_form'])) {
    return $form['shelter-popup']['results'];
  }
  else {
    return $form['results'];
  }
}
