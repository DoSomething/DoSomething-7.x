<?php

function dosomething_campaign_counter_campaign_counter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Campaign Counter'),
    'description' => t('Counter text for a campaign'),
    'category' => t('DoSomething'),
  );
}

function dosomething_campaign_counter_campaign_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $block = new stdClass();
  $sign_up_count = webform_get_submission_count($conf['signup_nid']);
  if ($conf['count_field'] == '#count') {
    $count = webform_get_submission_count($conf['report_back_nid']);
  }
  else {
    // load all webform entities for this node
    // aggregate the count of the fields
    // cache this somehow. dunno how yet.
  }
  $block->content = $count;

  //$context->etid
  return $block;
}

function dosomething_campaign_counter_campaign_counter_content_type_admin_title($subtype, $conf, $context) {
  return t('Campaign Counter');
}

function dosomething_campaign_counter_campaign_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['signup_nid'] = array(
    '#type' => 'select',
    '#title' => t('Signup Form NID'),
    '#description' => t('The webform for the campaign short form'),
    '#default_value' => $conf['signup_nid'],
    '#options' => dosomething_campaign_counter_campaign_counter_list('campaign_contact_form'),
  );

  $form['report_back_nid'] = array(
    '#type' => 'select',
    '#title' => t('Report Back NID'),
    '#description' => t('The webform for the campaign report back'),
    '#default_value' => $conf['report_back_nid'],
    '#options' => dosomething_campaign_counter_campaign_counter_list('campaign_report_back'),
  );

  $form['count_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Report Back Counter'),
    '#description' => t('The field name of the webform field to aggregate (sum), or #count to just count the number of report backs'),
    '#default_value' => $conf['count_field'],
  );

  return $form;
}

function dosomething_campaign_counter_campaign_counter_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('signup_nid', 'report_back_nid', 'count_field') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dosomething_campaign_counter_campaign_counter_list($type) {
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', $type)
    ->execute();

  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);

  $return = array();
  foreach ($nodes as $nid=>$node) {
    $return[$nid] = $node->title;
  }
  return $return;
}

