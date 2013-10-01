<?php

/**
 * @file
 * Page callbacks for dosomething_modal examples.
 */

/**
 * Page callback: Displays examples of dosomething_modal instances.
 *
 * This is a trimmed down version of the example page found in the ctools/ctools_ajax_sample module.
 *
 * @return array
 *   A render array for a page containing a list of content.
 *
 * @see dosomething_modal_menu()
 */
function dosomething_modal_example_page() {
  // Include necessary CTools stuff:
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  // Create our own javascript that will be used to theme the modals.
  $ds_style = array(
    'ds-modal-small' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 400,
        'height' => 250,
      ),
      'modalOptions' => array(
        'opacity' => .5,
        'background-color' => '#000',
      ),
      'animation' => 'fadeIn',
      // modalTheme value corresponds to the prototype.name in the JS file we link to below.
      'modalTheme' => 'DosomethingModalRequiredBase',
      'throbber' => theme('image', array('path' => ctools_image_path('ajax-loader.gif', 'ctools_ajax_sample'), 'alt' => t('Loading...'), 'title' => t('Loading'))),
    ),
    'ds-modal-large' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 500,
        'height' => 350,
      ),
      'modalOptions' => array(
        'opacity' => .5,
        'background-color' => '#000',
      ),
      'animation' => 'fadeIn',
      // modalTheme value corresponds to the prototype.name in the JS file we link to below.
      'modalTheme' => 'DosomethingModalBase',
      'closeText' => 'Close',
      'throbber' => theme('image', array('path' => ctools_image_path('ajax-loader.gif', 'ctools_ajax_sample'), 'alt' => t('Loading...'), 'title' => t('Loading'))),
    ),
  );
  drupal_add_js($ds_style, 'setting');
  // Link to JS for modalTheme DosomethingModalBase:
  ctools_add_js('dosomething-modal', 'dosomething_modal');
  // Link to JS for modalTheme DosomethingModalRequiredBase
  ctools_add_js('dosomething-modal-required', 'dosomething_modal');
  ctools_add_css('dosomething-modal', 'dosomething_modal');
 
   // Create a list of clickable links.
  $links = array();
  // The class passed to dosomething_modal_form_button is defined as the key of the $ds_style array above.
  $links[] = dosomething_modal_form_button('DoSomething Modal Example (Required)', 'dosomething_modal_example_form', 'ds-modal-small');
  $links[] = dosomething_modal_form_button('DoSomething Modal Example (Not Required)', 'dosomething_modal_example_form', 'ds-modal-large');
  if (module_exists('dosomething_user')) {
    $links[] = dosomething_modal_form_button('DoSomething User School Form (Not Required)', 'dosomething_user_school_form', 'ds-modal-large');	
  }
  $output = theme('item_list', array('items' => $links, 'title' => t('DS Modal Form Button Examples')));
  // This container will have data AJAXed into it via the dosomething_modal_example_form_submit.
  $output .= '<div id="ctools-sample">No forms have been submitted.</div>';
  return array('markup' => array('#markup' => $output));
}


/**
 * Form constructor for the DoSomething Modal Example Form.
 *
 * @see dosomething_modal_example_form_submit()
 *
 * @ingroup forms
 */
function dosomething_modal_example_form($form, &$form_state) {
  $form = array();
  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => 'Please select a username:',
    '#required' => TRUE,
    '#autocomplete_path' => 'user/autocomplete',
    '#description' => "This is an example form that doesn't save any information."
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Form submission handler for dosomething_modal_example_form().
 *
 * @see dosomething_modal_example_form()
 */
function dosomething_modal_example_form_submit(&$form, &$form_state) {
  $name = check_plain($form_state['values']['username']);
  // Tell the browser to close the modal.
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][] = ajax_command_html('#ctools-sample', 'You selected ' . $name);
}
