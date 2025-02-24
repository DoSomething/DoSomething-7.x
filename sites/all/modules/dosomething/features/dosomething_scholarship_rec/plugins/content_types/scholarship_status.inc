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
  $filter = array('nid' => $conf['app_nid']);
  if (isset($_GET['app_sid']) && user_access('access all webform results')) {
    $filter['sid'] = $_GET['app_sid'];
  }
  else {
    $filter['uid'] = $user->uid;
  }
  // Can't use webform_get_submissions because it joins on the Users table.
  // New users won't have a legacy users record, only a record in beta.
  // $subs = webform_get_submissions($filter);
  $subs = dosomething_scholarship_rec_get_webform_submission($filter);
  $apps = $sids = array_keys($subs);

  $complete_link = l('Complete it now', 'node/' . $conf['app_nid']);

  $block = new StdClass();

  if (count($subs) <= 0) {
    $block->content['status'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('status-empty')),
      'text' => array(
        '#markup' => '<span>Application status: </span> You haven\'t started yet! ' . $complete_link,
        '#prefix' => '<h3>',
        '#suffix' => '</h3>',
      ),
    );
  }
  foreach ($subs as $sub) {
    // set up some stuff for easy access later. It's MVC in one foreach look!
    $status = $class = '';
    if ($sub->is_draft) {
      $status = "Draft ($complete_link)";
      $class = 'status-incomplete';
    }
    else {
      $status = 'Complete';
      $class = 'status-complete';
    }

    $content = array();
    // APPLICATION STATUS
    $content['status'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array($class)),
      'text' => array(
        '#markup' => '<span>Application status: </span>' . $status,
        '#prefix' => '<h3>',
        '#suffix' => '</h3>',
      ),
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
    $i = 0;
    foreach ($rec_forms as $rec_form) {
      $i++;
      $rec_form = reset(entity_load('node', array($rec_form->nid)));
      $content['recommendation_status'][$rec_form->nid] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('recommendation-status'),
          'id' => 'recommendation-status-'.$rec_form->nid,
        ),
      );

      $content['recommendation_status'][$rec_form->nid]['title'] = array(
        '#markup' => "<span>{$rec_form->title}: </span>",
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
        $url = 'node/'.$req_form->nid;
        $opts = array('query' => array('sid' => $sub->sid));
        $content['recommendation_status'][$rec_form->nid]['send_request'] = array(
          '#type' => 'container',
          '#attributes' => array('class' => array('send-request')),
          'text' => array(
            '#markup' => 'Incomplete | ' . l('Complete it now', $url, $opts),
          ),
          'button' => array(
            '#markup' => l('Submit Recommendation Request', $url, $opts+array('attributes' => array('class' => array('go-button'), 'id' => 'rec-' . $i))),
          ),
        );
        $content['recommendation_status'][$rec_form->nid]['#attributes']['class'][] = 'status-empty';
        $content['recommendation_status'][$rec_form->nid]['title']['#markup'] .= 'Blank';
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
            $params = array('query' => array('destination' => current_path(), 'sid' => $req_sub->sid));
            $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['request_pending'] = array(
              '#markup' => 'Request pending | ' . l('Resend email', "email-rec-request/{$req_sub->sid}", $params),
            );
            $params['query']['sid'] = $sub->sid;
            $params['query']['destination'] = "email-rec-request/{$req_sub->sid}?destination=".current_path();
            $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['request_pending']['#markup'] .= ' | ' .
              l('Edit your recommendation request', "node/{$req_sub->nid}/submission/{$req_sub->sid}/edit", $params);
            $content['recommendation_status'][$rec_form->nid]['#attributes']['class'][] = 'status-incomplete';
            $content['recommendation_status'][$rec_form->nid]['title']['#markup'] .= 'Sent';
          }
          else {
            $content['recommendation_status'][$rec_form->nid][$req_sub->sid]['rec_received'] = array(
              '#markup' => 'Recommendation received.',
            );
            $content['recommendation_status'][$rec_form->nid]['#attributes']['class'][] = 'status-complete';
            $content['recommendation_status'][$rec_form->nid]['title']['#markup'] .= 'Received';
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

/**
 * Queries webform_submissions db table with given filters.
 *
 * To be used instead of webform_get_submissions.  New users in beta will
 * not have corresponding user records in legacy, which will result in 
 * empty result sets when using webform_get_submissions, since it joins the 
 * users table.
 *
 * @param $filters
 *   An array of filters to apply to this query.
 *
 * @return array
 *    Array of webform submission objects.
 */
function dosomething_scholarship_rec_get_webform_submission($filter) {
  $query = db_select('webform_submissions', 's');
  $query->fields('s');
  $query->condition('nid', $filter['nid']);
  if (isset($filter['sid'])) {
    $query->condition('sid', $filter['sid']);
  }
  elseif (isset($filter['uid'])) {
    $query->condition('uid', $filter['uid']);
  }
  $result = $query->execute();
  foreach ($result as $row) {
    $submissions[$row->sid] = new stdClass();
    $submissions[$row->sid]->sid = $row->sid;
    $submissions[$row->sid]->nid = $row->nid;
    $submissions[$row->sid]->is_draft = $row->is_draft;
  }
  return $submissions;
}
