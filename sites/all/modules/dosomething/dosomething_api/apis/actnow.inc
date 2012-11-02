<?php

function dosomething_api_actnow_api() {
  /**
   *  Action Guides.
   *  Returns:
   *    - Nid
   *    - Title
   *    - User ID of author
   *    - Created date
   *    - Last Changed date
   *    - Body text
   *    - Short description of the action guide
   *    - Issues tags
   *    - Who? tags
   *    - Time tags
   *    - Where tags
   *    - File information (the image on the page)
   */
  // Base query
  $acts = db_select('node', 'n')
    ->condition('n.type', 'action_guide')
    ->condition('n.status', 1);

  // Set default selected fields here.
  $default_fields = array(
    'nid',
    'title',
    'uid',
    'created',
    'changed'
  );

  // Allows to show only certain columns.
  if (!empty($_GET['show'])) {
    // Allowed values are set in this array.  More can be added by appending to this array.
    $shows = array(
      'all',
      'title',
      'body'
    );

    if (in_array($_GET['show'], $shows)) {
      if ($_GET['show'] == 'all') {
        $acts->fields('n', $default_fields);
      }
      else {
        $show = array();
        foreach (explode(',', $_GET['show']) AS $section) {
          switch ($section) {
            case 'title':
              $show[] = 'title';
            break;
            case 'body':
              $show[] = 'body';
            break;
          }
        }

        $acts->fields('n', $show);
      }
    }
  }
  else {
    $acts->fields('n', $default_fields);
  }

  // Action Guide body text
  $acts->join('field_data_body', 'b', 'b.entity_id = n.nid');
  $acts->fields('b', array('body_value'));

  // Action guide short description
  $acts->join('field_data_field_description', 'd', 'd.entity_id = n.nid');
  $acts->fields('d', array('field_description_value'));

  // Action Guide issues tags
  $acts->join('field_data_taxonomy_vocabulary_5', 'i5', 'i5.entity_id = n.nid');
  $acts->addExpression("GROUP_CONCAT(DISTINCT i5.taxonomy_vocabulary_5_tid)", 'issues_tags');

  // Action Guide who? tags
  $acts->join('field_data_taxonomy_vocabulary_3', 'i3', 'i3.entity_id = n.nid');
  $acts->addExpression('GROUP_CONCAT(DISTINCT i3.taxonomy_vocabulary_3_tid)', 'who_tags');

  // Action guide Time tags
  $acts->join('field_data_taxonomy_vocabulary_4', 'i4', 'i4.entity_id = n.nid');
  $acts->addExpression('GROUP_CONCAT(DISTINCT i4.taxonomy_vocabulary_4_tid)', 'time_tags');

  // Action guide where tags
  $acts->join('field_data_taxonomy_vocabulary_2', 'i2', 'i2.entity_id = n.nid');
  $acts->addExpression('GROUP_CONCAT(DISTINCT i2.taxonomy_vocabulary_2_tid)', 'where_tags');

  // Action guide file information
  $acts->join('field_data_field_picture', 'p', 'p.entity_id = n.nid');
  $acts->join('file_managed', 'f', 'f.fid = p.field_picture_fid');
  $acts->fields('f', array('fid', 'filename', 'uri', 'filemime', 'filesize', 'timestamp'));

  // Group by to make sure we display them all.
  $acts->groupBy("n.nid");

  // Filter by title.
  $title = strval(htmlspecialchars(trim($_GET['title'])));
  if (!empty($title)) {
    $acts->condition('title', '%' . $title . '%', 'LIKE');
  }

  // Filtered by creation date.
  if (!empty($_GET['created'])) {
    dosomething_api_date_sort($acts, $_GET['created'], 'condition', 'created');
  }

  // Filter by changed date
  if (!empty($_GET['changed'])) {
    dosomething_api_date_sort($acts, $_GET['changed'], 'condition', 'changed');
  }

  // Filter by a user ID (author)
  if (intval($_GET['user']) && !empty($_GET['user'])) {
    $acts->condition('uid', intval($_GET['user']));
  }

  // Sort by: Change this array to allow sorting by different columns.
  $allowed_sorts = array('created', 'changed', 'title');

  $sort = false;
  $sort_by = strval(htmlspecialchars(trim($_GET['sort_by'])));
  $order = array('', 'ASC');
  if (!empty($sort_by) && in_array($sort_by, $allowed_sorts)) {
    $order[0] = $sort_by;
    $sort = true;
  }
  else {
    $acts->orderBy('n.created', 'DESC');
    $acts->orderBy('n.title');
  }

  // Sort order: Must be used in conjunction with Sort By
  $sort_order = strval(htmlspecialchars(trim($_GET['sort_order'])));
  if (!empty($sort_order) && in_array($sort_order, array('ASC', 'DESC')) && !empty($sort_by)) {
    $order[1] = $sort_order;
    $sort = true;
  }

  if ($sort) {
    $acts->orderBy($order[0], $order[1]);
  }

  // Handles offset and limit
  dosomething_api_handle_offset_and_limit($acts);

  // Runs the query
  $r = $acts->execute();

  $no_html_tags = false;
  if (!empty($_GET['no_html_tags'])) {
    $no_html_tags = true;
  }

  $a = $r->fetchAll();
  foreach ($a AS $key => $act) {
    // Creates a path parameter to show the node alias
    $a["$key"]->path = drupal_lookup_path('alias', 'node/' . $act->nid);
    if ($no_html_tags) {
      $a["$key"]->body_value = strip_tags($a["$key"]->body_value);
    }
    // Places the image information in a sub array
    $a["$key"]->media = array(
      'image' => array(
        'fid' => $act->fid,
        'filename' => $act->filename,
        'uri' => $act->uri,
        'filemime' => $act->filemime,
        'filesize' => $act->filesize,
        'timestamp' => $act->timestamp,
      )
    );

    // Removes leftover file information.
    unset($a["$key"]->fid, $a["$key"]->filename, $a["$key"]->uri, $a["$key"]->filemime, $a["$key"]->filesize, $a["$key"]->timestamp);
  }

  echo json_encode($a);
  drupal_exit();
}