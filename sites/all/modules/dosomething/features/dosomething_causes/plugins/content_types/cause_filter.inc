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

/**
 * WTF are we doing for causes with multiple parents??!!
 */
function dosomething_causes_cause_filter_content_type_render($subtype, $conf, $panel_args, $context) {
  drupal_add_js(drupal_get_path('module', 'dosomething_causes') . '/js/dosomething_causes_ajax.js');
  $block = new stdClass();

  $tid = $panel_args[0];
  $vocabulary = taxonomy_vocabulary_machine_name_load(CAUSE_VOCABULARY_MACHINE_NAME);

  $tree = taxonomy_get_tree($vocabulary->vid, $tid, 1, true);
  // Yeah. WTF are we doing with multi-parent terms?
  // We need to maintain "state" somehow by passing something else to the panel...
  while (count($tree) == 0) {
    $tid = array_shift(taxonomy_get_parents($tid))->tid;
    $tree = taxonomy_get_tree($vocabulary->vid, $tid, 1, true);
  }

  $params = array(
    'links' => array(),
    'attributes' => array(
      'id' => 'cause-filter',
      'data-tid' => $tid,
    ),
  );

  $links = array();
  foreach ($tree as $term) {
    $params['links']['taxonomy-term-'.$term->tid] = array(
      'title' => $term->name,
      'href' => 'taxonomy/term/'.$term->tid,
      'attributes' => array(
        'data-tid' => $term->tid,
      ),
    );
  }
  $block->content = theme('links', $params);
  return $block;
}
