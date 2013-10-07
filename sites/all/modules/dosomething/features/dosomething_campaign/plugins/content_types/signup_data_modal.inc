<?php

/**
 * @file
 * signup_data_form content type.
 *
 */

/**
 * Implements hook_ctools_content_types().
 */
function dosomething_campaign_signup_data_modal_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Signup Data Modal Form'),
    'description' => t('Prompts user for Signup Data in a DS Modal if data does not exist'),
    'category' => t('DoSomething Campaign'),
    'defaults' => array(
      'modal_form_id' => 'dosomething_modal_example_form',
      'type' => 'scale',
      'width' => '0.7',
      'height' => '0.8',
      'opacity' => '0.3',
      'bg_color' => '#ccc',
      'close_text_lbl' => 'Close',
    ),
  );
}

/**
 * Implements hook_content_type_render().
 */
function dosomething_campaign_signup_data_modal_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  drupal_add_library('ds_neue', 'ds-neue');
  $link_name = 'ds-signup-data-modal';
  // Build JS settings:
  $options = array(
    $link_name => array(
      'modalSize' => array(
        'type' => $conf['type'],
        'width' => $conf['width'],
        'height' =>$conf['height'],
      ),
      'modalOptions' => array(
        'opacity' => $conf['opacity'],
        'background-color' => $conf['bg_color'],
      ),
      'closeText' => $conf['close_text_lbl'],
    ),
  );
  $block = new stdClass();
  $block->content = dosomething_modal_form_link('Signup Data Form', $conf['modal_form_id'], $options);
  $link_class_name = 'ctools-modal-' . $link_name;
  // Click the link to make modal automatically appear:
  // drupal_add_js('jQuery(document).ready(function () { $(".' . $link_class_name . '").click(Drupal.CTools.Modal.clickAjaxLink).click();', 'inline');
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function dosomething_campaign_signup_data_modal_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['modal_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Modal Form ID'),
    '#default_value' => $conf['modal_form_id'],
    '#description' => 'The Drupal Form ID of the form to render in the modal.  This value must exist in the dosomething_modal_form_builder_access function.',
  );
  $form['modal_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Modal Options'),
  );
  $form['modal_options']['close_text_lbl'] = array(
    '#type' => 'textfield',
    '#title' => t('Close Button label'),
    '#default_value' => $conf['close_text_lbl'],
    '#description' => "Leave empty if user should not be able to close the modal.",
  );
  $form['modal_options']['modal_size'] = array(
    '#type' => 'fieldset',
    '#title' => t('Size'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['modal_options']['modal_size']['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#default_value' => $conf['scale'],
    '#options' => array('scale' => 'scale', 'fixed' => 'fixed'),
    '#description' => "<ul><li>Fixed: enter px values for height/width.</li><li>Scale: enter a percentage, e.g. 0.8</li></ul>",
  );
  $form['modal_options']['modal_size']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $conf['width'],
  );
  $form['modal_options']['modal_size']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $conf['height'],
  );
  $form['modal_options']['overlay'] = array(
    '#type' => 'fieldset',
    '#title' => t('Overlay'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['modal_options']['overlay']['opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Opacity'),
    '#default_value' => $conf['opacity'],
    '#description' => 'Enter a percentage, e.g. 0.3',
  );
  $form['modal_options']['overlay']['bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Color'),
    '#default_value' => $conf['bg_color'],
  );
  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function dosomething_campaign_signup_data_modal_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}