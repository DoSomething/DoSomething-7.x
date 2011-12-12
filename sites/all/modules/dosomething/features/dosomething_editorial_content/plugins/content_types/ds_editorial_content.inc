<?php

$plugin = array(
  'title' => t('Editorial Content'),
  'single' => TRUE,
  'content_types' => array('dosomething_editorial_content'),
  'render callback' => 'dosomething_editorial_content_content_type_render',
  'edit form' => 'dosomething_editorial_content_content_type_edit_form',
  'category' => t('DoSomething'),
);

function dosomething_editorial_content_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $element = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'editorial-content',
      ),
    ),
  );
  if (!empty($conf['nid'])) {
    $editorial = node_load($conf['nid']);
    $element['node'] = node_view($editorial, 'teaser');
  }

  $block->content = $element;
  return $block;
}

function dosomething_editorial_content_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $result = db_query("SELECT nid, title FROM {node} WHERE type = 'editorial_content_' AND status = 1");
  foreach ($result as $record) {
    $options[$record->nid] = check_plain($record->title) . " ($record->nid)";
  }

  $form['nid'] = array(
    '#title' => t('Editorial Content'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $options,
    '#default_value' => !empty($conf['nid']) ? $conf['nid'] : array(),
  );

  return $form;
}

function dosomething_editorial_content_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['nid'] = $form_state['values']['nid'];
}
