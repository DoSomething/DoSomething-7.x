<?php

function dosomething_campaign_styles_campaign_sign_up_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Campaign Sign-up/Report-Back'),
    'description' => t('Campaign Sign-up/Report back auto-switching widget'),
    'category' => t('DoSomething'),
  );
}

function dosomething_campaign_styles_campaign_sign_up_content_type_render($subtype, $conf, $panel_args, $context) {
  if ($context = og_context()) {
    global $user;

    $query = new EntityFieldQuery;
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', array('campaign_contact_form', 'campaign_sign_up', 'campaign_report_back'), 'IN')
      ->fieldCondition('group_audience', 'gid', $context->gid, '=')
      ->execute();

    foreach ($result['node'] as $res) {
      ${$res->type} = $res->nid;
    }

    $block = (object)module_invoke('webform', 'block_view', 'client-block-'.$campaign_contact_form);

    if (user_is_logged_in()) {
      $query = new EntityFieldQuery;
      $sign_ups = $query
        ->entityCondition('entity_type', 'webform_submission_entity')
        ->propertyCondition('uid', $user->uid)
        ->propertyCondition('nid', $campaign_sign_up)
        ->execute();

      if (!empty($sign_ups) || true) {
        $block = new stdClass();
        $block->content = $conf['report_back_html'];
      }
    }
    return $block;
  }
}

function dosomething_campaign_styles_campaign_sign_up_content_type_admin_title($subtype, $conf, $context) {
  return t('Campaign Sign-Up');
}

function dosomething_campaign_styles_campaign_sign_up_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['report_back_html'] = array(
    '#type' => 'textarea',
    '#title' => t('Signup Form NID'),
    '#description' => t('The webform for the campaign short form'),
    '#default_value' => $conf['report_back_html'],
  );

  return $form;
}

function dosomething_campaign_styles_campaign_sign_up_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('report_back_html') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

