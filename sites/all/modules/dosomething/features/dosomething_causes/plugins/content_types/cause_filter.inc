<?php

function dosomething_causes_cause_filter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Cause Filter'),
    'description' => t('Image issue filter for the top of the cause pages'),
    'category' => t('DoSomething'),
  );
}

function dosomething_causes_cause_filter_content_type_admin_title($subtype, $conf, $context) {
  return t('Cause Filter');
}

/*
function dosomething_causes_cause_filter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // add items to $form
}

function dosomething_causes_cause_filter_content_type_edit_form_submit(&$form, &$form_state) {
  // array of keys
  foreach (array() as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
 */
function dosomething_causes_cause_filter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = 'test';
  return $block;
}
