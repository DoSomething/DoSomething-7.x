<?php

define('FOOTLOCKER_NOMINATION_EMAIL_FIELD', 'your_email');

function dosomething_scholarship_rec_footlocker_metrics() {
  drupal_set_title('Foot Locker metrics');

  if (!isset($_GET['password']) || (isset($_GET['password']) && substr_count($_GET['password'], '|') != 3)) {
    return drupal_get_form('dosomething_scholarship_rec_fl_password');
  }

  list($nomination, $application, $required, $optional) = explode('|', $_GET['password']);

  $header = array('Metric', 'Count');
  $rows = array(
    array('Total nominations', dosomething_scholarship_rec_fl_nominations($nomination)),
    array('Unique nominators', dosomething_scholarship_rec_fl_unique_nominators($nomination)),
    array('Started applications', dosomething_scholarship_rec_fl_started_apps($application)),
    array('Submitted applications', dosomething_scholarship_rec_fl_complete_apps($application)),
    array('Submitted applications that have requested a required recommendation', dosomething_scholarship_rec_fl_rec_requested($application, $required)),
    array('Submitted applications that have completed required recommendations', dosomething_scholarship_rec_fl_rec_completed($application, $required)),
    array('Submitted applications that have requested an optional recommendation', dosomething_scholarship_rec_fl_rec_requested($application, $optional)),
    array('Submitted applications that have completed optional recommendations', dosomething_scholarship_rec_fl_rec_completed($application, $optional)),
  );

  return array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => $header,
    '#attributes' => array(
    ),
  );
}

function dosomething_scholarship_rec_fl_password($form, &$form_state) {
  return array(
    '#method' => 'get',
    'password' => array(
      '#type' => 'textfield',
      '#title' => 'Password',
      '#required' => TRUE,
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Submit',
    ),
  );
}

/**
 * Fetch the number of total nominations.
 */
function dosomething_scholarship_rec_fl_nominations($nomination_nid) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  return webform_get_submission_count($nomination_nid);
}

/**
 * Fetch the number of unique nominators.
 */
function dosomething_scholarship_rec_fl_unique_nominators($nomination_nid) {
  $node = node_load($nomination_nid);
  $email_cid = webform_get_cid($node, FOOTLOCKER_NOMINATION_EMAIL_FIELD, 0);
  $res = db_query('SELECT count(distinct data) FROM webform_submitted_data WHERE nid=:nid AND cid=:cid', array(':nid' => $nomination_nid, ':cid' => $email_cid))->fetchColumn();
  return $res;
}

/**
 * Fetch the number of applications that have been started.
 */
function dosomething_scholarship_rec_fl_started_apps($app_nid) {
  return db_query('SELECT count(*) from webform_submissions WHERE nid=:nid', array(':nid' => $app_nid))->fetchColumn();
}

/**
 * Fetch the number of submitted applications.
 */
function dosomething_scholarship_rec_fl_complete_apps($app_nid) {
  return db_query('SELECT count(*) from webform_submissions WHERE nid=:nid AND is_draft=0', array(':nid' => $app_nid))->fetchColumn();
}

/**
 * Fetch the number of apps taht are complete and have requested recommendations.
 */
function dosomething_scholarship_rec_fl_rec_requested($app_nid, $request_nid) {
  $query = db_select('webform_submissions', 'ws');
  $query->addJoin('INNER', 'field_data_field_application', 'app_ref', 'app_ref.field_application_target_id=ws.sid');
  $query->addJoin('INNER', 'webform_submissions', 'ws2', 'ws2.sid=app_ref.entity_id');
  $query
    ->condition('ws.is_draft', 0)
    ->condition('ws2.nid', $request_nid)
    ->addExpression('COUNT(distinct field_application_target_id)');
  return $query->execute()->fetchColumn();
}

/**
 * Fetch the number of apps that are complete and have completed recommendations.
 */
function dosomething_scholarship_rec_fl_rec_completed($app_nid, $request_nid) {
  $query = db_select('webform_submissions', 'ws');
  $query->addJoin('INNER', 'field_data_field_application', 'app_ref', 'app_ref.field_application_target_id=ws.sid');
  $query->addJoin('INNER', 'webform_submissions', 'w2', 'w2.sid=app_ref.entity_id');
  $query->addJoin('INNER', 'field_data_field_rec_request', 'req_ref', 'req_ref.field_rec_request_target_id=app_ref.entity_id');
  $query
    ->condition('ws.is_draft', 0)
    ->condition('w2.nid', $request_nid)
    ->addExpression('COUNT(distinct field_application_target_id)');
  return $query->execute()->fetchColumn();
}
