<?php

function dosomething_general_webform_counter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Webform Submission Counter'),
    'description' => t('Counter text for a webform'),
    'category' => t('DoSomething'),
  );
}

function dosomething_general_webform_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $block = new stdClass();
  $count = webform_get_submission_count($conf['webform_nid']);

  $list = array(
    'items' => array(
      '<span class="counter-labels">'.$conf['counter_label'].'</span><span class="digits">'.$count.'</span>',
    ),
    'type' => 'ul',
  );

  $block->content = '<div class="counter">';
  $block->content.= theme('item_list', $list);
  $block->content.= '</div>';

  return $block;
}

function dosomething_general_webform_counter_content_type_admin_title($subtype, $conf, $context) {
  return t('Webform Counter');
}

function dosomething_general_webform_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['webform_nid'] = array(
    '#type' => 'select',
    '#title' => t('Signup Form NID'),
    '#description' => t('The webform for the campaign short form'),
    '#default_value' => $conf['webform_nid'],
    '#options' => dosomething_general_webform_counter_list(),
  );

  $form['counter_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Counter Label'),
    '#description' => t('Label to display for the \'thing\' counter'),
    '#default_value' => $conf['counter_label'],
  );

  return $form;
}

function dosomething_general_webform_counter_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('webform_nid', 'counter_label') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dosomething_general_webform_counter_list() {
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'webform')
    ->execute();

  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);

  $return = array();
  foreach ($nodes as $nid=>$node) {
    $return[$nid] = $node->title;
  }
  return $return;
}
