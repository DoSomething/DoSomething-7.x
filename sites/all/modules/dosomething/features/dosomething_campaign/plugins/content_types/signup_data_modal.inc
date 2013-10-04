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
  );
}

/**
 * Implements hook_content_type_render().
 */
function dosomething_campaign_signup_data_modal_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  drupal_add_library('ds_neue', 'ds-neue');
  // @todo: Pass through params from edit form instead of hard-coding these values:
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
  $block = new stdClass();
  $block->content = dosomething_modal_form_link('DoSomething User School Form', 'dosomething_user_school_form', $options);
  return $block;
}
