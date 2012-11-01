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
    ->propertyOrderBy('submitted', 'DESC');

  // Range: Default range is 0, 25
  $range = array(0, 25);

  dosomething_api_handle_offset_and_limit($result);

  if (!empty($_GET['uid'])) {
    // Filter by a particular User ID
    $uid = intval($_GET['uid']);
    if (!empty($uid)) {
      $result->propertyCondition('uid', $uid, '=');
    }
    else {
      $result->propertyCondition('uid', 0, '>');
    }
  }

  // Filters by title inclusive.
  if (!empty($_GET['title'])) {
    $title = strval(htmlspecialchars(trim($_GET['title'])));
    if (!empty($title)) {
      $result->fieldCondition('field_project_title', 'value', '%' . $title . '%', 'LIKE');
    }
  }

  // Filters by creation time, with either one or two (comma-separated) values.
  // If only one value, finds projects that started on that date
  // If two (comma-separated) values, finds projects within the range defined by the comma-separated values (e.g. last month,today)
  if (!empty($_GET['created'])) {
    dosomething_api_date_sort($result, $_GET['created'], 'propertyCondition', 'start_time');
  }

  // Filters by project "started" time, with either one or two (comma-separated) values.
  // If only one value, finds projects that started on that date
  // If two (comma-separated) values, finds projects within the range defined by the comma-separated values (e.g. last month,today)
  if (!empty($_GET['started'])) {
    dosomething_api_date_sort($result, $_GET['started'], 'fieldCondition', 'field_project_start_date');
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
      if (!empty($s->field_project_start_date[LANGUAGE_NONE][0]['value'])) {
        $time = strtotime($s->field_project_start_date[LANGUAGE_NONE][0]['value']);
      }
      $projects[] = array(
        'sid' => $s->sid,
        'title' => (isset($s->field_project_title) ? $s->field_project_title[LANGUAGE_NONE][0]['value'] : ''),
        'solving' => (isset($s->field_essay_see_it) ? $s->field_essay_see_it[LANGUAGE_NONE][0]['value'] : ''),
        'action' => (isset($s->field_essay_build_it) ? $s->field_essay_build_it[LANGUAGE_NONE][0]['value'] : ''),
        'impact' => array(
          'unfiltered' => (isset($s->field_impact_type) ? $s->field_impact_type[LANGUAGE_NONE][0]['value'] : ''),
          'filtered' => (isset($s->field_impact_type) ? $impacts[$s->field_impact_type[LANGUAGE_NONE][0]['value']] : ''),
        ),
        'count' => (isset($s->field_impact_amount) ? $s->field_impact_amount[LANGUAGE_NONE][0]['value'] : ''),
        'involved' => (isset($s->field_update_people_involved) ? $s->field_update_people_involved[LANGUAGE_NONE][0]['value'] : ''),
        'status' => array(
          'unfiltered' => (isset($s->field_project_type) ? $s->field_project_type[LANGUAGE_NONE][0]['value'] : ''),
          'filtered' => (isset($s->field_project_type) ? $status[$s->field_project_type[LANGUAGE_NONE][0]['value']] : '')
        ),
        'started' => array(
          'day' => date('d', $time),
          'month' => date('m', $time),
          'year' => date('Y', $time),
          'timestamp' => $time
        ),
        'issues' => dosomething_general_array_vals_multi($s->taxonomy_vocabulary_5),
        'media' => array(
          'picture' => (isset($s->field_picture[LANGUAGE_NONE]) ? $s->field_picture[LANGUAGE_NONE][0] : ''),
          'video' => $video
        ),
        'link' => array(
          'title' => (isset($s->field_link[LANGUAGE_NONE]) ? $s->field_link[LANGUAGE_NONE][0]['title'] : ''),
          'url' => (isset($s->field_link[LANGUAGE_NONE]) ? $s->field_link[LANGUAGE_NONE][0]['url'] : '')
        )
      );
    }

    echo json_encode($projects);
  }
  drupal_exit();
}