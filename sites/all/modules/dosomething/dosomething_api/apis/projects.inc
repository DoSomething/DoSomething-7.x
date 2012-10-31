<?php

// Defines the Node ID that all projects fall under.
define('PROJECT_NID', 718313);

function dosomething_api_projects_api() {
  /**
   *  Projects.
   *  Returns:
   *   - sid: The Project ID
   *   - title: The project title
   *   - solving: What the project hopes to solve
   *   - action: How the project hopes to solve it
   *   - impact: An array of...
   *      - unfiltered: Numeric key representing impact choice
   *      - filtered: Human readable version of Impact
   *   - count: The amonut of impacted people/animals/monies
   *   - involved: Number of people involved with the project
   *   - status: An array.  The status (Started or not) of the project
   *      - unfiltered: Numeric key representing status choice
   *      - filtered: Human readable version of status
   *   - started (optional to the user).  An array containing:
   *      - day: Day the project started
   *      - month: Month the project started
   *      - year: Year the project started
   *      - timestamp: UNIX timestamp version of when the project started.
   *   - issues: Taxonomy term IDs for tagged issues.
   *   - media: An array of media related to the project, including...
   *      - picture: The picture of the project
   *      - video: The Video of the project.
   *   - link (optional to the user): An array of information regarding links related to the project.
   *      - title: The title of the website.
   *      - url: The URL of the website.
   */

  // Builds the query.
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', PROJECT_NID)
    ->propertyCondition('bundle', 'project_report')
    ->propertyOrderBy('submitted', 'DESC')
    ->range(0, 25);

  // Filter by a particular User ID
  $uid = intval($_GET['uid']);
  if (!empty($uid)) {
    $result->propertyCondition('uid', $uid, '=');
  }
  else {
    $result->propertyCondition('uid', 0, '>');
  }

  // Filters by title inclusive.
  $title = strval(htmlspecialchars(trim($_GET['title'])));
  if (!empty($title)) {
    $result->fieldCondition('field_project_title', 'value', '%' . $title . '%', 'LIKE');
  }

  // Filters by creation time, with either one or two (comma-separated) values.
  // If only one value, finds projects that started on that date
  // If two (comma-separated) values, finds projects within the range defined by the comma-separated values (e.g. last month,today)
  $created = strval(htmlspecialchars(trim($_GET['created'])));
  if (!empty($created)) {
    list($start, $end) = explode(',', $created);
    $btw = array();
    if (strtotime($start) && strtotime($end)) {
      $btw = array(strtotime($start), strtotime($end));
      // Between two values -- finds a range of projects created between two dates.
      $result->propertyCondition('start_time', $btw, 'BETWEEN');
    }
    else if (strtotime($start)) {
      // Only one value -- finds projects created on a particular date.
      $result->propertyCondition('start_time', strtotime($start), '=');
    }
  }

  // Filters by project "started" time, with either one or two (comma-separated) values.
  // If only one value, finds projects that started on that date
  // If two (comma-separated) values, finds projects within the range defined by the comma-separated values (e.g. last month,today)
  $started = strval(htmlspecialchars(trim($_GET['started'])));
  if (!empty($started)) {
    list($start, $end) = explode(',', $started);
    $btw = array();
    if (strtotime($start) && strtotime($end)) {
      $s = date('Y-m-d 00:00:00', strtotime($start));
      $e = date('Y-m-d 00:00:00', strtotime($end));

      $btw = array($s, $e);
      // Between two values -- finds a range of projects started between two dates
      $result->fieldCondition('field_project_start_date', 'value', $btw, 'BETWEEN');
    }
    else if (strtotime($start)) {
      // Only one value -- finds projects started on a particular date.
      $result->fieldCondition('field_project_start_date', 'value', date('Y-m-d 00:00:00', strtotime($start)), '=');
    }
  }

  $return = $result->execute();
  if (!empty($return))
  {
    // Human readable impacts
    $impacts = array(
      1 => t('people helped'),
      2 => t('animals helped'),
      3 => t('items collected'),
      4 => t('amount raised')
    );
    // Human readable statuses
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