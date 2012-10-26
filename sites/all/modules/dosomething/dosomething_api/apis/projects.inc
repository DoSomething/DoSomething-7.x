<?php

function dosomething_api_projects_api() {
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', PROJECT_NID)
    ->propertyCondition('uid', 0, '>')
    ->propertyCondition('bundle', 'project_report')
    ->propertyOrderBy('submitted', 'DESC')
    ->range(0, 25);

  $title = strval(htmlspecialchars(trim($_GET['title'])));
  if (!empty($title)) {
    $result->fieldCondition('field_project_title', 'value', '%' . $title . '%', 'LIKE');
  }

  $created = strval(htmlspecialchars(trim($_GET['created'])));
  if (!empty($created)) {
    list($start, $end) = explode(',', $created);
    $btw = array();
    if (strtotime($start) && strtotime($end)) {
      $btw = array(strtotime($start), strtotime($end));
      $result->propertyCondition('start_time', $btw, 'BETWEEN');
    }
    else if (strtotime($start)) {
      $result->propertyCondition('start_time', strtotime($start), '=');
    }
  }

  $started = strval(htmlspecialchars(trim($_GET['started'])));
  if (!empty($started)) {
    list($start, $end) = explode(',', $started);
    $btw = array();
    if (strtotime($start) && strtotime($end)) {
      $s = date('Y-m-d 00:00:00', strtotime($start));
      $e = date('Y-m-d 00:00:00', strtotime($end));

      $btw = array($s, $e);
      $result->fieldCondition('field_project_start_date', 'value', $btw, 'BETWEEN');
    }
    else if (strtotime($start)) {
      $result->fieldCondition('field_project_start_date', 'value', date('Y-m-d 00:00:00', strtotime($start)), '=');
    }
  }

  $return = $result->execute();
  if (!empty($return))
  {
    $impacts = array(
      1 => t('people helped'),
      2 => t('animals helped'),
      3 => t('items collected'),
      4 => t('amount raised')
    );
    $status = array(
      2 => t('project idea'),
      3 => t('ongoing project'),
      4 => t('completed project')
    );
    $projects = array();
    foreach ($return['webform_submission_entity'] AS $key => $r)
    {
      $s = array_shift(entity_load('webform_submission_entity', array((int) $key)));
      if (!empty($s->field_webform_videos[LANGUAGE_NONE][0])) {
        $video = db_select('file_managed', 'f')
          ->fields('f')
          ->condition('fid', $s->field_webform_videos[LANGUAGE_NONE][0])
          ->range(0, 1)
          ->orderBy('fid', 'DESC')
          ->execute();
        $video = $video->fetchAll();
        $video = (array) $video[0];
      }
      $time = strtotime($s->field_project_start_date[LANGUAGE_NONE][0]['value']);
      $projects[] = array(
        'sid' => $s->sid,
        'title' => $s->field_project_title[LANGUAGE_NONE][0]['value'],
        'solving' => $s->field_essay_see_it[LANGUAGE_NONE][0]['value'],
        'action' => $s->field_essay_build_it[LANGUAGE_NONE][0]['value'],
        'impact' => array(
          'unfiltered' => $s->field_impact_type[LANGUAGE_NONE][0]['value'],
          'filtered' => $impacts[$s->field_impact_type[LANGUAGE_NONE][0]['value']],
        ),
        'count' => $s->field_impact_amount[LANGUAGE_NONE][0]['value'],
        'involved' => $s->field_update_people_involved[LANGUAGE_NONE][0]['value'],
        'status' => array(
          'unfiltered' => $s->field_project_type[LANGUAGE_NONE][0]['value'],
          'filtered' => $status[$s->field_project_type[LANGUAGE_NONE][0]['value']]
        ),
        'started' => array(
          'day' => date('d', $time),
          'month' => date('m', $time),
          'year' => date('Y', $time),
          'timestamp' => $time
        ),
        'issues' => dosomething_general_array_vals_multi($s->taxonomy_vocabulary_5),
        'media' => array(
          'picture' => $s->field_picture[LANGUAGE_NONE][0],
          'video' => $video
        ),
        'link' => array(
          'title' => $s->field_link[LANGUAGE_NONE][0]['title'],
          'url' => $s->field_link[LANGUAGE_NONE][0]['url']
        )
      );
    }

    echo json_encode($projects);
  }
  drupal_exit();
}