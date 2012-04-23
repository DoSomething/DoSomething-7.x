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
 * answer: just show the cause closest to A, because this makes sense?
 */
function dosomething_causes_cause_filter_content_type_render($subtype, $conf, $panel_args, $context) {
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'jquery.form');
  drupal_add_js(drupal_get_path('module', 'dosomething_causes') . '/js/dosomething_causes_ajax.js');
  $block = new stdClass();

  $tid = $panel_args[0];
  $vocabulary = taxonomy_vocabulary_machine_name_load(CAUSE_VOCABULARY_MACHINE_NAME);

  $tree = taxonomy_get_tree($vocabulary->vid, $tid, 1, true);
  $term = end(entity_load('taxonomy_term', array($tid)));
  if (!isset($term->field_cause_master_parent[LANGUAGE_NONE][0]['tid'])) {
    while (count($tree) == 0) {
      $tid = end(taxonomy_get_parents($tid))->tid;
      $tree = taxonomy_get_tree($vocabulary->vid, $tid, 1, true);
    }
  }
  else {
    $tree = taxonomy_get_tree($vocabulary->vid, $term->field_cause_master_parent[LANGUAGE_NONE][0]['tid']);
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
    $img = theme('image_style', array(
      'style_name' => 'cause_vertical',
      'path' => $term->field_causes_image[LANGUAGE_NONE][0]['uri'],
      'alt' => $term->name,
    ));
    // add the vertical label
    $img .= '<div class="term-label">'.$term->name.'</div>';

    // add the description box
    $title = '<h2>'.$term->name.'</h2>';
    $img .= '<div class="term-description">'.$title.$term->description.'</div>';
    $params['links']['taxonomy-term-'.$term->tid] = array(
      'title' => $img,
      'href' => 'taxonomy/term/'.$term->tid,
      'html' => true,
      'attributes' => array(
        'data-tid' => $term->tid,
      ),
    );
  }
  $left = theme('image', array(
    'path' => drupal_get_path('module', 'dosomething_causes') . '/images/yellow-arrow-left.png',
    'attributes' => array(
      'id' => 'browse-left',
      'class' => 'cause-scroller-arrow',
    ),
  ));
  $right = theme('image', array(
    'path' => drupal_get_path('module', 'dosomething_causes') . '/images/yellow-arrow-right.png',
    'attributes' => array(
      'id' => 'browse-right',
      'class' => 'cause-scroller-arrow',
    )
  ));

  $block->content = '<div id="cause-scroller-wrapper" class="clearfix">' . $left;
  $block->content.= '<div id="cause-filter-wrapper">' . theme('links', $params) . '</div>';
  $block->content.= $right . '</div>';

  drupal_add_css(drupal_get_path('module', 'dosomething_causes') . '/css/dosomething_causes.css');
  return $block;
}
