<?php

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
  $form = array();

  $form['helptext'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => t('Enter the zip code and select the shelter where you snammed your animal pic.'),
  );
  $form['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Zip:'),
    '#required' => TRUE,
    '#weight' => 0,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#weight' => 0,
    '#ajax' => array(
      'callback' => 'dosomething_picsforpets_shelters_lookup_form_options_submit_ajax',
      'wrapper' => 'shelter-results',
    ),
    '#submit' => array('dosomething_picsforpets_shelters_lookup_options_form_submit'),
  );

  // Initialize the options variable
  $options = '';
  if (isset($form_state['results'])) {
    $options = $form_state['results'];
  }
  $options['new'] = t('I want to use a shelter not on the list.');

  $form['results'] = array(
    '#tree' => TRUE,
    '#prefix' => '<div id="shelter-results">',
    '#suffix' => '</div>',
    '#weight' => 2,
    '#type' => 'radios',
    '#options' => $options,
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
    #'#ajax' => array(
    #  'callback' => 'dosomething_picsforpets_shelters_load_more_ajax',
    #  'wrapper' => 'shelter-results-more',
    #),
    '#submit' => array('dosomething_picsforpets_shelters_select_shelter_submit'),
  );
  return $form;
}

/**
 * Form submission handler for the shelter lookup form with options.
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
  if (count($shelter_nids) == 11) {
    $form_state['view_more'] = TRUE;
    unset($shelter_nids[10]);
  }
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
  $form_state['more_times'] += 1;
  $zip = $form_state['values']['zip'];
  // We retreive an extra result and then throw it away so that we know if we
  // should show the 'view more' button.
  $shelter_nids = dosomething_picsforpets_shelters_get_shelters_by_zip($zip, $form_state['more_times'] * 10, 11);
  if (count($shelter_nids) == 11) {
    $form_state['view_more'] = TRUE;
    unset($shelter_nids[10]);
  }
  else {
    $form_state['view_more'] = FALSE;
  }
  $options = dosomething_picsforpets_shelters_formatted_results($shelter_nids, 'options');
  $form_state['more_results'] = $options;
  // We append the results to the former results list so we have the appropriate
  // content for non JS submissions.
  $form_state['more_results_all'] = $form_state['more_results_all'] + $options;
  $form_state['results'] = $form_state['results'] + $options;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback for the submit button on the shelter options lookup form.
 */
function dosomething_picsforpets_shelters_lookup_form_options_submit_ajax($form, &$form_state) {
  return $form['results'];
}

function dosomething_picsforpets_shelters_select_shelter_submit($form, &$form_state) {
  $selected_shelter = NULL;
  if (!empty($form_state['values']['results'])) {
    $selected_shelter = $form_state['values']['results'];
  }
  $shelter = node_load($selected_shelter);
  dpm("you picked " . $shelter->title);
}
