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
  dpm($context->data);
  $uid = $context->data->uid;
  $user = node_load($uid);

  $block = new stdClass();
  
  $block->content = 'test';
  
  $groups = og_get_entity_groups('user', $user);
  foreach ($groups as $gid) {
    // Get entity_id campaigns referenced campaign report backs.
    $report_back = db_query("SELECT f.entity_id from {field_data_field_report_back_reference} f 
                             INNER JOIN {og} o ON f.field_report_back_reference_nid = o.etid 
                             WHERE o.gid = :gid", array(':gid' => $gid))->fetchField(); 
    // If campaign report backs webform exist, check for user submission.
    if ($report_back) {
      $submission = db_query("SELECT sid FROM {webform_submissions} 
                              WHERE nid = :nid AND uid = :uid", 
                              array(':nid' => $report_back, ':uid' => $uid))->fetchField();
      // User has not submitted a report back.
      if (!$submission) {
      }
    }
  }


  return $block;
}
