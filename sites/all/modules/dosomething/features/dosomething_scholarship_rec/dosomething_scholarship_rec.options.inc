<?php

function dosomething_scholarship_rec_user_projects($component, $flat, $filter, $arguments) {
  $item = menu_get_item();

  // if we're on an edit page, load up the projects for a particular user.
  // otherwise, load up the submissions for the current user
  if ($item['page_callback'] == 'webform_submission_page' && $item['page_arguments'][2] == 'form') {
    $uid = $item['page_arguments'][1]->uid;
  }
  else {
    $uid = $GLOBALS['user']->uid;
  }

  return _dosomething_scholarship_rec_get_projects_for_uid($uid);
}

function _dosomething_scholarship_rec_get_projects_for_uid($uid) {
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'webform_submission_entity')
    ->entityCondition('bundle', 'project_report')
    ->propertyCondition('uid', $uid)
    ->execute();

  $subs = entity_load('webform_submission_entity', array_keys($entities['webform_submission_entity']));

  $return = array();
  foreach ($subs as $key => $project) {
    $title = $project->field_project_title[LANGUAGE_NONE][0]['value'];
    $link = l($title, 'webform-submission/'.$key);

    $return[$key] = $link;
  }

  return $return;
}
