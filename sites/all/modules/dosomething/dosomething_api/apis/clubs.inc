<?php

/**
  * Service to post a share to the database.
  */
function dosomething_api_clubs_api() {
  /**
   *  Clubs.
   *  Returns:
   *    - Nid
   *    - Creation time
   *    - Title
   *    - User-defined title (if not associated with a school)
   *    - Blurb about club
   *    - Total member count
   *    - Member User IDs
   *    - School reference ID
   *    - School Name
   *    - School level (by grade)
   *    - School city
   *    - School state
   *    - School ZIP
   *    - List o' campaigns (see loop below)
   *    - List o' projects (see loop below)
   */
  $default_fields = array(
    'nid', 'created', 'title'
  );

  $c = db_select('node', 'n')
    ->fields('n', $default_fields);

  // User generated title for club (if not associated with a school)
  $c->leftJoin('field_data_field_noschool_club_name', 'club_name', 'club_name.entity_id = n.nid');
  $c->addField('club_name', 'field_noschool_club_name_value', 'user_title');

  // Small blurb of information about club.
  $c->leftJoin('field_data_field_club_blurb', 'blurb', 'blurb.entity_id = n.nid');
  $c->addField('blurb', 'field_club_blurb_value', 'blurb');

  // Club Organic Group -- used for other joins
  $c->leftJoin('og', 'o', "n.nid = o.etid AND o.entity_type = 'node'");

  // Club OG membership -- used to get member count
  $c->leftJoin('og_membership', 'm', "m.gid = o.gid AND m.entity_type = 'user'");
  $c->addExpression("COUNT(DISTINCT m.etid)", 'member_count');

  // Club User information -- used to get member User IDs
  $c->leftJoin('users', 'u', 'u.uid = m.etid');
  $c->addExpression("GROUP_CONCAT(DISTINCT u.uid)", 'member_uids');

  // School entity -- gathers reference school ID
  $c->leftJoin('field_data_field_school_reference', 'school', "school.entity_id = n.nid AND (school.entity_type = 'node' AND school.deleted = '0')");
  $c->addField('school', 'field_school_reference_target_id', 'school_id');

  // Actual school information.  Should be self explanatory
  $c->leftJoin('ds_school', 's', 's.sid = school.field_school_reference_target_id');
  $c->addField('s', 'name', 'school_name');
  $c->addField('s', 'level', 'school_level');
  $c->addField('s', 'city', 'school_city');
  $c->addField('s', 'state', 'school_state');
  $c->addField('s', 'zip', 'school_zip');

  $c->condition('n.type', 'club');
  $c->groupBy('n.nid ASC');

  /**
   *  ----------------------------------------------------
   *  And so begins the filtering...
   *  ----------------------------------------------------
   */

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
      $c->condition('n.created', $btw, 'BETWEEN');
    }
    else if (strtotime($start)) {
      // Only one value -- finds projects created on a particular date.
      $c->condition('n.created', strtotime($start), '=');
    }
  }

  // Range: Default range is 0, 25
  $range = array(0, 25);

  // Offset
  $offset = intval($_GET['offset']);
  if (!empty($offset)) {
    $range[0] = $offset;
  }

  // Limit
  $limit = intval($_GET['limit']);
  if (!empty($limit)) {
    $range[1] = $limit;
  }

  // Sets the range
  $c->range($range[0], $range[1]);

  // Title searching -- inclusive by default.
  $title = strval(htmlspecialchars(trim($_GET['title'])));
  if (!empty($title)) {
    $c->condition('n.title', '%' . $title . '%', 'LIKE');
  }

  // State searching.  Allowable states are in the $allowed_states array.
  $allowed_states = array('AL', 'AK', 'AB', 'AS', 'AZ', 'AR', 'AA', 'AE', 'AP', 'BC', 'CA', 'CO', 'CT', 'DE', 'DC', 'FL', 'GA', 'GU', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MB', 'MH', 'MD', 'MA', 'MI', 'FM', 'MN', 'MS', 'MO', 'MT', 'NE', 'NV', 'NB', 'NH', 'NJ', 'NM', 'NY', 'NF', 'NC', 'ND', 'MP', 'NT', 'NS', 'OH', 'OK', 'ON', 'OR', 'PW', 'PA', 'PE', 'PR', 'QC', 'RI', 'SK', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VI', 'VA', 'WA', 'WV', 'WI', 'WY', 'YT');
  $states = strval(htmlspecialchars(trim($_GET['state'])));
  if (!empty($states) && in_array($states, $allowed_states)) {
    $c->condition('s.state', $states, '=');
  }

  // Search for clubs that a member owns.
  $uid = intval($_GET['uid']);
  if (!empty($uid)) {
    $c->condition('n.uid', $uid);
  }

  // Sorting -- defaults to node.created desc, node.title asc
  // It is possible to sort by 'created' and 'title'
  // To add searchable columns: Add elements to $allowed_sorts array
  $allowed_sorts = array('created', 'title');

  $sort = array('', 'ASC');
  $sort_by = strval(htmlspecialchars(trim($_GET['sort_by'])));
  if (!empty($sort_by) && in_array($sort_by, $allowed_sorts)) {
    $sort[0] = $sort_by;
  }
  else {
    $c->orderBy('n.created', 'DESC');
    $c->orderBy('n.title');
  }

  // Sort order -- ASC or DESC only.
  $sort_order = strval(htmlspecialchars(trim($_GET['sort_order'])));
  if (!empty($sort_order) && in_array($sort_order, array('ASC', 'DESC')) && !empty($sort_by)) {
    $sort[1] = $sort_order;
  }

  // If the API is called with a sort by parameter, set that as the orderby
  if (!empty($sort[0])) {
    $c->orderBy($sort[0], $sort[1]);
  }

  // Run the query.
  $r = $c->execute();

  $final = array();
  foreach ($r->fetchAll() AS $key => $club) {
    // Get all campaigns assocaited with the club.
    $camps = db_query("
      SELECT
        IF (`new_camps`.`field_campaign_list_nid`, `new_camps`.`field_campaign_list_nid`, `old_camps`.`field_camp_value`) AS `camps`
      FROM `field_data_field_camp` AS `old_camps`
        LEFT JOIN `field_data_field_campaign_list` AS `new_camps` ON (`new_camps`.`entity_id` = `old_camps`.`entity_id`)
      WHERE
        `old_camps`.`entity_id` = " . $club->nid
    )->fetchAll();

    // Add to clubs "Campaigns" key
    $club->campaigns = dosomething_general_array_vals_multi($camps);

    // Get all projects associated with a club -- created by any member of the club.
    $projects = db_query("
      SELECT DISTINCT nid
      FROM webform_submissions AS `projects`
      WHERE `projects`.`uid` IN (" . ($club->member_uids ? $club->member_uids : 0) . ")
        AND `projects`.`bundle` = 'project_report'
      ORDER BY `projects`.`sid` ASC
    ")->fetchAll();

    // Add to "Projects" key
    $club->projects = dosomething_general_array_vals_multi($projects);

    // Adds "path" key to final array
    $club->path = drupal_lookup_path('alias', 'node/' . $club->nid);

    // Add to larger array that will be encoded later.
    $final[] = $club;
  }

  echo json_encode($final);
  drupal_exit();
}