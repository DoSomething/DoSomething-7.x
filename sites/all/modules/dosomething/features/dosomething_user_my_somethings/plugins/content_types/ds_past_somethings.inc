<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_past_somethings_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Past Somethings'),
    'icon' => 'icon_user.png',
    'description' => t('Past Somethings on user profile'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_past_somethings_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $content = dosomething_user_my_somethings_ds_past_somethings_content($uid);
  $block->content = '<h2>' . t('My Past Somethings') . '</h2>';
  $block->content .= theme('table', array('rows' => $content));
  return $block;
}

/**
 * Return content for My Somethings pane.
 */
function dosomething_user_my_somethings_ds_past_somethings_content($uid) {
  $links = array();
  // Find campaign report backs that a user has completed.
  $report_backs = db_query("SELECT n.nid, n.title FROM {webform_submissions} w
                            INNER JOIN {node} n ON w.nid = n.nid
                            WHERE w.bundle = 'campaign_report_back' AND w.uid = :uid", 
                            array(':uid' => $uid))->fetchAll();
  foreach ($report_backs as $report_back) {
    $links[] = array(
      'title' => $report_back->title,
      'link' => l('View', 'node/' . $report_back->nid),
    );
  }

  // Find action guides that a user has completed.
  $data = db_query("SELECT w.nid, n.title FROM {webform_submissions} w 
                    INNER JOIN {node} n ON w.nid = n.nid
                    WHERE w.uid = :uid AND bundle = 'action_guide' AND is_draft = 0", array(':uid' => $uid))->fetchAll(); 
  foreach($data as $guide) {
    $links[] = array(
       'title' => $guide->title,
       'link' => l('View', 'node/' . $guide->nid),
    );
  }  

  // Find a user's projects where status is completed.
  $projects = db_query("SELECT w.nid, w.sid, t.field_project_title_value FROM {webform_submissions} w 
                      INNER JOIN {field_data_field_project_type} s ON w.sid = s.entity_id
                      INNER JOIN {field_data_field_project_title} t ON w.sid = t.entity_id
                      WHERE w.uid = :uid AND w.bundle = 'project_report' 
                      AND s.field_project_type_value = 4", array(':uid' => $uid))->fetchAll(); 
  foreach ($projects as $project) {
    $links[] = array(
      'title' => $project->field_project_title_value,
      'link' => l('View', 'node/' . $project->nid . '/submission/' . $project->sid),
    );
  } 

  return $links;
}  
