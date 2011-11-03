<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_current_somethings_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Current Somethings'),
    'icon' => 'icon_user.png',
    'description' => t('Current Somethings on user profiled'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_current_somethings_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;

  $report_backs = dosomething_user_my_somethings_campaign_report_backs($uid);
  $action_guides = dosomething_user_my_somethings_action_guides($uid);
  

  $block = new stdClass();
  
  $block->content = 'test';
  
  return $block;
}

/**
 * Return an array of campaign report backs 
 * that a user has not completed for campaigns they are part of.
 */
function dosomething_user_my_somethings_campaign_report_backs($uid) {
  $user = node_load($uid);
  $groups = og_get_entity_groups('user', $user);
  foreach ($groups as $gid) {
    // Get campaign title and entity_id of its campaign report back.
    $report_back = db_query("SELECT f.entity_id, o.label, n.type from {field_data_field_report_back_reference} f 
                             INNER JOIN {og} o ON f.field_report_back_reference_nid = o.etid 
                             INNER JOIN {node} n ON f.entity_id = n.nid
                             WHERE o.gid = :gid AND n.type = 'campaign_report_back'", array(':gid' => $gid))->fetchObject(); 
    // If campaign report back webform exist, check for user submission.
    if (isset($report_back->entity_id)) {
      $submission = db_query("SELECT sid FROM {webform_submissions} 
                              WHERE nid = :nid AND uid = :uid", 
                              array(':nid' => $report_back->entity_id, ':uid' => $uid))->fetchField();
      // User has not submitted a report back.
      if (!$submission) {
        $report_backs[$report_back->entity_id] = $report_back->label;
      }
    }
  }
  return $report_backs;
}

function dosomething_user_my_somethings_action_guides($uid) {
    $guides = db_query("SELECT w.nid, n.title FROM {webform_submissions} w 
                               INNER JOIN {node} n ON w.nid = n.nid
                               WHERE w.uid = :uid AND bundle = 'action_guide' AND is_draft = 1", array(':uid' => $uid))->fetchAll(); 
    foreach($guides as $guide) {
      $action_guides[$guide->nid] = $guide->title;
    }  
  return $action_guides;
}  
