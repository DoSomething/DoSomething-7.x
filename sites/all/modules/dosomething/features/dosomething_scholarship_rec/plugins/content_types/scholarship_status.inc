<?php

function dosomething_scholarship_rec_scholarship_status_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Scholarship Status'),
    'description' => t('Status of a scholarship application with attached recommendations'),
    'category' => t('DoSomething'),
  );
}

function dosomething_scholarship_rec_scholarship_status_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $subs = webform_get_submissions(array('nid' => $conf['app_nid'], 'uid' => $user->uid));
  $apps = $sids = array_keys($subs);

  $block = new StdClass();

  foreach ($subs as $sub) {
    // set up some stuff for easy access later. It's MVC in one foreach look!
    $complete_link = l('Complete it now', 'node/'.$sub->nid);

    // APPLICATION STATUS
    $content = array();
    $content['status'] = array(
      '#markup' => 'Application status: ' . (($sub->is_draft) ? "Draft ($complete_link)" : 'Submitted'),
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    );

    $content['recommendation_status'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'recommendation-status-wrapper',
      ),
    );

    // Loop through each recommendation form.
    $params = array('node_type' => 'scholarship_recommendation', 'nid' => $sub->nid);
    $rec_forms = dosomething_scholarship_rec_scholarship_status_load('node', 'field_application_form', $params);
    foreach ($rec_forms as $rec_form) {
      $rec_form = reset(entity_load('node', array($rec_form->nid)));
      $content['recommendation_status'][$rec_form->nid] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => 'recommendation-status',
          'id' => 'recommendation-status-'.$rec_form->nid,
        ),
      );

      $content['recommendation_status'][$rec_form->nid]['title'] = array(
        '#markup' => $rec_form->title,
        '#prefix' => '<h4>',
        '#suffix' => '</h4>',
      );
      // get the related recommendation request form
      // NOTE: We're ASSUMING (reasonably) that there will be a request form for each recommendation form
      $params = array('node_type' => 'scholarship_recommendation_reque', 'nid' => $rec_form->nid);
      $req_form = dosomething_scholarship_rec_scholarship_status_load('node', 'field_recommendation_form', $params);
      $req_form = reset($req_form);

      // get any submissions on the rec request form
      $params = array('nid' => $req_form->nid, 'bundle' => 'scholarship_recommendation_reque', 'sid' => $sub->sid);
      $req_subs = dosomething_scholarship_rec_scholarship_status_load('submission', 'field_application', $params);

      if ($req_subs === FALSE) {
        $content['recommendation_status'][$rec_form->nid]['send_request'] = array(
          '#markup' => l('Submit a recommendation request', 'node/'.$req_form->nid, array('query' => array('sid' => $sub->sid))),
        );
      }
      else {
        // get submissions for each request submission
        foreach ($req_subs as $key => $req_sub) {
          $req_sub = reset(entity_load('webform_submission_entity', array($key)));
          $content['recommendation_status'][$rec_form->nid][$req_sub->sid] = array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => 'recommendation-status-line',
            ),
          );

          $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['recommender_name'] = array(
            '#prefix' => '<strong>',
            '#suffix' => '</strong> ',
            '#markup' => $req_sub->field_webform_name[LANGUAGE_NONE][0]['value'] . ' (' . $req_sub->field_webform_email[LANGUAGE_NONE][0]['email'] . ')',
          );
          $params = array('nid' => $rec_form->nid, 'bundle' => 'scholarship_recommendation', 'sid' => $key);
          $rec_subs = dosomething_scholarship_rec_scholarship_status_load('submission', 'field_rec_request', $params);

          if ($rec_subs === FALSE) {
            $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['request_pending'] = array(
              '#markup' => 'Request pending. ' . l('Resend email', "email-rec-request/{$req_sub->sid}"),
            );
          }
          else {
            $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['rec_received'] = array(
              '#markup' => 'Recommendation received.',
            );
          }
        }
      }
    }

    $block->content[] = $content;
  }

  $block->title = 'Application Status';
  return $block;
}

function dosomething_scholarship_rec_scholarship_status_content_type_admin_title($subtype, $conf, $context) {
  return t('Scholarship status');
}

function dosomething_scholarship_rec_scholarship_status_content_type_edit_form($form, &$form_state) {
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'scholarship_application_with_rec')
    ->execute();

  $nodes = entity_load('node', array_keys(reset($result)));
  $options = array();
  foreach ($nodes as $node) {
    $options[$node->nid] = $node->title;
  }

  $form['app_nid'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#title' => 'Scholarship application',
  );
  return $form;
}

function dosomething_scholarship_rec_scholarship_status_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('app_nid') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dosomething_scholarship_rec_scholarship_status_load($type, $field, $params) {
  if ($type == 'submission') $type = 'webform_submission_entity';

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', $type);

  if ($type == 'webform_submission_entity') {
    $q
      ->propertyCondition('nid', $params['nid'])
      ->propertyCondition('bundle', $params['bundle'])
      ->fieldCondition($field, 'target_id', $params['sid']);
  }
  else if ($type == 'node') {
    $q
      ->propertyCondition('type', $params['node_type'])
      ->fieldCondition($field, 'nid', $params['nid']);
  }

  return reset($q->execute());
}
