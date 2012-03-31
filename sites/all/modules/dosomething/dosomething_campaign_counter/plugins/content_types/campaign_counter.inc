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
  $count_text = $conf['counter_label'];
  if ($conf['count_field'] == '#count') {
    $count = webform_get_submission_count($conf['report_back_nid']);
    $count_text = 'people did it';
  }
  else {
    // load all webform entities for this node
    $query = new EntityFieldQuery;
    $result = $query
      ->entityCondition('entity_type', 'webform_submission_entity')
      ->propertyCondition('bundle', 'campaign_report_back')
      ->propertyCondition('nid', $conf['report_back_nid'])
      ->execute();
    $subs = array_keys($result['webform_submission_entity']);

    $node = node_load($conf['report_back_nid']);
    foreach ($node->webform['components'] as $component) {
      if ($component['form_key'] == $conf['count_field']) {
        $fid = $component['cid'];
        break;
      }
    }
    if (isset($fid)) {
      $count = dosomething_campaign_counter_campaign_counter_get_count($conf['report_back_nid'], $fid, $subs);
    }
  }

  dosomething_campaign_counter_campaign_counter_spanize($count);
  dosomething_campaign_counter_campaign_counter_spanize($sign_up_count);

  $args = array(
    'top_label' => $count_text,
    'top_number' => $count,
    'bottom_label' => 'people doing it',
    'bottom_number' => $sign_up_count,
  );
  $block->content = theme('ds_counter', $args);

  return $block;
}

function dosomething_campaign_counter_campaign_counter_spanize(&$number) {
  $number = str_split($number);

  for ($i = 3; $i < count($number); $i++) {
    $number[$i] = $number[$i].',';
  }

  $span_open = '<span class="counter-number">';
  $span_close = '</span>';

  $number = $span_open . implode($span_close.$span_open, $number) . $span_close;
}

function dosomething_campaign_counter_campaign_counter_get_count($nid, $field, &$subs, $reset = false) {
  $data = array();
  $count = 0;
  if (!$reset && ($cache = cache_get('dosomething_campaign_counter', 'cache_block')) && !empty($cache->data)) {
    $data = $cache->data;
    if (isset($data[$nid]) && $data[$nid]['field'] == $field) {
      $count = $data[$nid]['count'];
      foreach ($subs as $key => $sub) {
        if ($sub <= $data[$nid]['last']) {
          unset($subs[$key]);
        }
      }
    }
  }
  if (!empty($subs)) {
    $subs = webform_get_submissions($nid, $subs);
    $biggest = 0;
    foreach ($subs as $sub) {
      $count += $sub->data[$field]['value'][0];
      if ($sub->sid > $biggest) $biggest = $sub->sid;
    }
    $data[$nid]['last'] = $biggest;
  }

  $data[$nid]['field'] = $field;
  $data[$nid]['count'] = $count;

  cache_set('dosomething_campaign_counter', $data, 'cache_block');

  return $count;
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

  $form['counter_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Counter Label'),
    '#description' => t('Label to display for the \'thing\' counter'),
    '#default_value' => $conf['counter_label'],
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
  foreach (array('signup_nid', 'report_back_nid', 'count_field', 'counter_label') as $key) {
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

