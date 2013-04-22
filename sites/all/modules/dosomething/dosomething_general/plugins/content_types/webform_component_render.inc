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
  static $n;

  $submission = $context[0]->data;
  if (empty($n)) {
    $n = menu_get_object('node', 1, 'node/' . $submission->nid);
  }

  // Weird: You couldn't use this plugin twice before because it was overriding the actual node the first time.
  // This fixes it.
  $i = clone $n;
  $new = array();
  foreach ($conf['webform_cid'] as $cid) {
    $new[$cid] = isset($i->webform['components'][$cid]) ? $i->webform['components'][$cid] : array();
  }

  $i->webform['components'] = $new;

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $content = webform_submission_render($i, $submission, NULL, ((!empty($conf['raw']) || !empty($conf['output'])) ? 'raw' : 'html'));

  if (!empty($conf['output'])) {
    preg_match_all('#([A-Za-z0-9\-\_ ]+)\:\s+(.*)#i', $content, $data);

    $content = '';
    foreach ($data[1] AS $key => $label) {
      $content .= str_replace(array('{label}', '{value}'), array($label, $data[2][$key]), $conf['output']);
    }
  }

  $block->content = $content;
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

  $form['raw'] = array(
    '#type' => 'checkbox',
    '#title' => t('Output the raw value of this/these field(s)?'),
    '#default_value' => !empty($conf['raw']),
  );

  $form['output'] = array(
    '#type' => 'textarea',
    '#title' => t('Output format:'),
    '#attributes' => array('placeholder' => t('How would you like the output to show up? You may use full HTML here.  Use {label} for the label, and {value} for the value.')),
    '#default_value' => $conf['output'],
  );

  return $form;
}

function dosomething_general_webform_component_render_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('webform_nid') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
  $form_state['conf']['webform_cid'] = array_map('intval',explode(",",$form_state['values']['webform_cid']));
  $form_state['conf']['raw'] = $form_state['values']['raw'];
  $form_state['conf']['output'] = $form_state['values']['output'];
}
