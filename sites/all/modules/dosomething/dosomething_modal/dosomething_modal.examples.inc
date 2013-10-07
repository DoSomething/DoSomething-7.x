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
  drupal_add_library('ds_neue', 'ds-neue');
   // Create a list of clickable links.
  $links = array();

  // Example, with default options (defined in dosomething_modal_get_default_js_settings)
  $links[] = dosomething_modal_form_link('DoSomething Modal Example (Default options)', 'dosomething_modal_example_form');

  // Example with options set so user can't close out the modal.
  $options = array(
    'ds-required-modal' => array(
      'closeText' => ''
    )
  );
  $links[] = dosomething_modal_form_link('DoSomething Modal Example (Required modal)', 'dosomething_modal_example_form', $options);

  // Example with modalSize set to scale, different overlay options:
  $options = array(
    'ds-scale-modal' => array(
      'modalSize' => array(
        'type' => 'scale',
        'width' => 0.7,
        'height' => 0.7,
      ),
      'modalOptions' => array(
        'opacity' => .3,
        'background-color' => '#ccc',
      ),
    ),
  );
  $links[] = dosomething_modal_form_link('DoSomething Modal Example (Scale)', 'dosomething_modal_example_form', $options);

  // Output user school form as an example:
  if (module_exists('dosomething_user')) {
    $links[] = dosomething_modal_form_link('DoSomething User School Form', 'dosomething_user_school_form', $options);	
  }

  // Render links as a list:
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
