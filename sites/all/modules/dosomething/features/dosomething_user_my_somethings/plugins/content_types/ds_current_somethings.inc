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
  $block = new stdClass();
  $content = dosomething_user_my_somethings_ds_current_somethings_content($uid);
  $block->content = '<h2>' . t('My Current Somethings') . '</h2>';
  $block->content .= theme('table', array('rows' => $content));
  return $block;
}

/**
 * Return content for My Somethings pane.
 */
function dosomething_user_my_somethings_ds_current_somethings_content($uid) {
  $links = array();
  // Find campaign report backs that a user has not completed for campaigns they are part of.
  $user = user_load($uid);
  $groups = og_get_entity_groups('user', $user);
  $my_somethings = dosomething_user_my_somethings_get_my_somethings($uid);

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
        $links[] = array(
          'title' => $report_back->label,
          'link' => l('Complete this', 'node/' . $report_back->entity_id),
        );
      }
    }
  }
  
  // Find action guides that a user has saved draft but not complteted.
  $data = db_query("SELECT w.nid, n.title FROM {webform_submissions} w 
                      INNER JOIN {node} n ON w.nid = n.nid
                      WHERE w.uid = :uid AND bundle = 'action_guide' AND is_draft = 1", array(':uid' => $uid))->fetchAll(); 
  foreach($data as $guide) {
    $links[] = array(
       'title' => $guide->title,
       'link' => l('Complete this', 'node/' . $guide->nid),
    );
  }  

  // Find a user's projects where status is idea or ongoing.
  if (isset($my_somethings['project_report']) && count($my_somethings['project_report'])) {
    foreach ($my_somethings['project_report'] as $project) {
      $links[] = array(
        'title' => $project->field_project_title_value,
        'link' => l('Complete this', 'node/' . $project->nid . '/submission/' . $project->sid),
      );
    } 
  }

  return $links;
}  
