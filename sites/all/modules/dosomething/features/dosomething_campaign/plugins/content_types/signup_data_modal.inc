<?php

/**
 * @file
 * signup_data_form content type.
 *
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Signup Data Modal Form'),
  'description' => t('Prompts user for Signup Data in a DS Modal if data does not exist'),
  'category' => t('DoSomething Campaign'),
  'edit form' => 'signup_data_modal_edit_form',
  'render callback' => 'signup_data_modal_render',
  'admin info' => 'signup_data_modal_admin_info',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'modal_form_id' => 'dosomething_modal_example_form',
    'type' => 'scale',
    'width' => '0.7',
    'height' => '0.8',
    'opacity' => '0.3',
    'bg_color' => '#ccc',
    'close_text_lbl' => 'Close',
    'mobile_breakpoint' => '600',
    'mobile_width' => 1.0,
    'mobile_height' => 1.0,
  ),
);

/**
 * Callback for content type admin info.
 */
function signup_data_modal_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = t('Displays <em>@modal_form_id</em> in a <em>@type</em> modal.', array(
      '@modal_form_id' => $conf['modal_form_id'],
      '@type' => $conf['type'],
    ));
    $block->content = 'Width: ' . $conf['width']. ' | Height: ' . $conf['height']. ' | Close Text: ' . $conf['close_text_lbl'];
    return $block;
  }
}

/**
 * Callback for content type render.
 */
function signup_data_modal_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $nid = $context->data->nid;
  // If we already have user signup data for this node:
  if (dosomething_signups_get_signup_data($user->uid, $nid)) {
    // Don't render anything.
    return;
  }
  // Build JS settings for desktop modal:
  $desktop_class = 'ds-signup-data-desktop';
  $desktop_options = array(
    $desktop_class => array(
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
  $desktop_modal_link = dosomething_modal_form_link('Desktop', $conf['modal_form_id'], $desktop_options);
  // Build JS settings for mobile modal:
  $mobile_class = 'ds-signup-data-mobile';
  $mobile_options = array(
    $mobile_class => array(
      'modalSize' => array(
        // Mobile modal should always scale.
        'type' => 'scale',
        'width' => $conf['mobile_width'],
        'height' =>$conf['mobile_height'],
      ),
      'modalOptions' => array(
        'opacity' => $conf['opacity'],
        'background-color' => $conf['bg_color'],
      ),
      'closeText' => $conf['close_text_lbl'],
    ),
  );
  $mobile_modal_link = dosomething_modal_form_link('Mobile', $conf['modal_form_id'], $mobile_options);
  $block = new stdClass();
  // Output both modal links in a hidden div:
  $block->content = '<div style="display:none;">' . $desktop_modal_link . ' | ' . $mobile_modal_link . '</div>';
  // Check browser viewport to determine which modal link to auto-click:
  drupal_add_js('jQuery(window).bind("load", function() { 
    if (jQuery(window).width() < ' . $conf['mobile_breakpoint'] . ') {
      jQuery(".ctools-modal-' . $mobile_class . '").click();
    } 
    else {
      jQuery(".ctools-modal-' . $desktop_class . '").click();      
    }
  });', 'inline');
  return $block;
}

/**
 * Callback for content type edit form.
 */
function signup_data_modal_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['modal_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Modal Form ID'),
    '#required' => TRUE,
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
  $form['modal_options']['desktop'] = array(
    '#type' => 'fieldset',
    '#title' => t('Desktop'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['modal_options']['desktop']['type'] = array(
    '#type' => 'select',
    '#title' => t('Desktop Modal Type'),
    '#required' => TRUE,
    '#default_value' => $conf['type'],
    '#options' => array('scale' => 'scale', 'fixed' => 'fixed'),
    '#description' => "<ul><li>Fixed: enter px values for height/width.</li><li>Scale: enter a percentage, e.g. 0.8</li></ul>",
  );
  $form['modal_options']['desktop']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop Modal Width'),
    '#required' => TRUE,
    '#default_value' => $conf['width'],
  );
  $form['modal_options']['desktop']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop Modal Height'),
    '#required' => TRUE,
    '#default_value' => $conf['height'],
  );
  $form['modal_options']['mobile'] = array(
    '#type' => 'fieldset',
    '#title' => t('mobile'),
    '#description' => 'Modal window will always be set to Scale on mobile.',
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['modal_options']['mobile']['mobile_breakpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Breakpoint'),
    '#required' => TRUE,
    '#default_value' => $conf['mobile_breakpoint'],
    '#description' => 'The px width at which the mobile modal should be used',
  );
  $form['modal_options']['mobile']['mobile_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Modal Width'),
    '#required' => TRUE,
    '#default_value' => $conf['mobile_width'],
    '#description' => 'Percentage for width scale, e.g. 0.95',
  );
  $form['modal_options']['mobile']['mobile_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Modal Height'),
    '#required' => TRUE,
    '#default_value' => $conf['mobile_height'],
    '#description' => 'Percentage for height scale, e.g. 0.95',
  );
  $form['modal_options']['overlay'] = array(
    '#type' => 'fieldset',
    '#title' => t('Overlay'),
    '#required' => TRUE,
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['modal_options']['overlay']['opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Opacity'),
    '#required' => TRUE,
    '#default_value' => $conf['opacity'],
    '#description' => 'Enter a percentage, e.g. 0.3',
  );
  $form['modal_options']['overlay']['bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Color'),
    '#required' => TRUE,
    '#default_value' => $conf['bg_color'],
  );
  return $form;
}

/**
 * Submit callback for signup_data_modal_edit_form().
 */
function signup_data_modal_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}