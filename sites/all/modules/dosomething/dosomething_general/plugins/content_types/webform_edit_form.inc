<?php

function dosomething_general_webform_edit_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Webform Edit Form for Node'),
    'description' => t('Edit form for a webform, edit a past submission if exists'),
    'category' => t('DoSomething'),
  );
}

function dosomething_general_webform_edit_form_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  module_load_include('inc', 'webform', 'includes/webform.submissions');

  $node = node_load($conf['webform_nid']);

  $submission = reset(webform_get_submissions(array(
    'nid' => $node->nid,
    'uid' => $user->uid,
  )));

  $form = drupal_get_form('webform_client_form_' . $node->nid, $node, $submission);

  $block = new stdClass();
  $block->content = $form;
  return $block;
}

function dosomething_general_webform_edit_form_content_type_admin_title($subtype, $conf, $context) {
  return t('Webform Edit Form for Node');
}

function dosomething_general_webform_edit_form_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['webform_nid'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#title' => t('Webform NID'),
    '#description' => t('The webform to display the edit/submit form for'),
    '#default_value' => $conf['webform_nid'],
  );

  return $form;
}

function dosomething_general_webform_edit_form_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('webform_nid') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
