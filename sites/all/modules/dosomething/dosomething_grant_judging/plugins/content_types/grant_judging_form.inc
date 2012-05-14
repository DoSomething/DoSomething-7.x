<?php

/**
 * Implements hook_ctools_content_types().
 */
function dosomething_grant_judging_grant_judging_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Grant Judging Form'),
    'description' => t('Grant Judging form for adding a judgment webform to another webform'),
    'category' => t('DoSomething'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function dosomething_grant_judging_grant_judging_form_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  // for now we assume that the sid is coming from the URL of the panel.

  $node = node_load($conf['judge_form_nid']);

  $current_sid = $panel_args[0];
  $current_submission = webform_get_submission($node->nid, $current_sid);

  $filters = array(
    'nid' => $node->nid,
    'uid' => $user->uid,
  );

  $submissions = webform_get_submissions($filters);
  $submission = null;

  foreach ($submissions as $sub) {
    if ($sub->field_grant_judge_application[LANGUAGE_NONE][0]['target_id'] == $current_sid) {
      $submission = $sub;
    }
  }

  $form = drupal_get_form('webform_client_form_' . $node->nid, $node, $submission);
  $name = $current_submission->field_webform_name[LANGUAGE_NONE][0]['value'];
  $default_value = "$name ($current_sid)";

  $wrapper = &$form['submitted']['field_grant_judge_application'];
  $field = &$wrapper[LANGUAGE_NONE][0]['target_id'];

  $field['#default_value'] = $default_value;
  $field['#value'] = $default_value;
  $field['#type'] = 'hidden';
  $field['#theme'] = 'hidden';
  unset($field['#theme_wrappers']);

  $block = new StdClass();
  $block->content = $form;
  return $block;
}

/**
 * Implements hook_content_type_admin_title().
 */
function dosomething_grant_judging_grant_judging_form_content_type_admin_title($subtype, $conf, $context) {
  return t('Grant Judgment form');
}

/**
 * Implements hook_content_type_edit_form().
 */
function dosomething_grant_judging_grant_judging_form_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['judge_form_nid'] = array(
    '#type' => 'select',
    '#title' => t('Judging form NID'),
    '#description' => t('NID of the judgment form to use for juding grants'),
    '#default_value' => $conf['judge_form_nid'],
    '#options' => dosomething_grant_judging_grant_judging_form_select_list(),
  );

  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function dosomething_grant_judging_grant_judging_form_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('judge_form_nid') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Helper function to list available nodes of type grant_judge, which is a
 * grant judging webform content type.
 */
function dosomething_grant_judging_grant_judging_form_select_list() {
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'grant_judge')
    ->execute();

  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);

  $return = array();
  foreach ($nodes as $nid=>$node) {
    $return[$nid] = $node->title;
  }
  return $return;
}

