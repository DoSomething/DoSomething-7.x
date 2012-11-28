<?php

function dosomething_general_webform_component_render_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Webform Component Renderer'),
    'description' => t('Webform Component Renderer'),
    'category' => t('DoSomething'),
    'required context' => array(
      new ctools_context_required(t('Webform Submission'), 'webform_submission_entity'),
    ),
  );
}

function dosomething_general_webform_component_render_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $submission = $context[0]->data;
  $node = node_load($submission->nid);

  $new = array();
  foreach ($conf['webform_cid'] as $cid) {
    $new[$cid] = $node->webform['components'][$cid];
  }
  $node->webform['components'] = $new;

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $block->content = webform_submission_render($node, $submission, NULL, 'html');
  return $block;
}

function dosomething_general_webform_component_render_content_type_admin_title($subtype, $conf, $context) {
  return t('Webform Component Renderer');
}

function dosomething_general_webform_component_render_content_type_edit_form($form, &$form_state) {
  $conf = isset($form_state['input']['webform_nid']) ? $form_state['input'] : $form_state['conf'];

  $form['webform_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform NID'),
    '#default_value' => $conf['webform_nid'],
  );

  $form['webform_cid'] = array(
    '#type' => 'textfield',
    '#title' => t('Component IDs, separated by commas'),
    '#default_value' => implode(', ', $conf['webform_cid']),
  );

  return $form;
}

function dosomething_general_webform_component_render_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('webform_nid') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
  $form_state['conf']['webform_cid'] = array_map('intval',explode(",",$form_state['values']['webform_cid']));
}
