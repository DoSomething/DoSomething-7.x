<?php

/**
  * Service to post a share to the database.
  */
function dosomething_api_clubs_api($title, $club_state, $sort_by, $sort_order) {
  $range = array(0, 25);

  $offset = intval($_GET['offset']);
  if (!empty($offset)) {
    $range[0] = $offset;
  }

  $limit = intval($_GET['limit']);
  if (!empty($limit)) {
    $range[1] = $limit;
  }

  $title = strval(htmlspecialchars(trim($_GET['title'])));
  if (!empty($title)) {
    $where .= " AND `node`.`title` LIKE '%" . mysql_real_escape_string($title) . "%'";
  }

  $allowed_states = array('AL', 'AK', 'AB', 'AS', 'AZ', 'AR', 'AA', 'AE', 'AP', 'BC', 'CA', 'CO', 'CT', 'DE', 'DC', 'FL', 'GA', 'GU', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MB', 'MH', 'MD', 'MA', 'MI', 'FM', 'MN', 'MS', 'MO', 'MT', 'NE', 'NV', 'NB', 'NH', 'NJ', 'NM', 'NY', 'NF', 'NC', 'ND', 'MP', 'NT', 'NS', 'OH', 'OK', 'ON', 'OR', 'PW', 'PA', 'PE', 'PR', 'QC', 'RI', 'SK', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VI', 'VA', 'WA', 'WV', 'WI', 'WY', 'YT');
  $states = strval(htmlspecialchars(trim($_GET['state'])));
  if (!empty($states) && in_array($states, $allowed_states)) {
    $where .= " AND `s`.`state` = '" . mysql_real_escape_string($states) . "'";
  }

  $sort = '';
  $sort_by = strval(htmlspecialchars(trim($_GET['sort_by'])));
  $allowed_sorts = array('created', 'title');
  if (!empty($sort_by) && in_array($sort_by, $allowed_sorts)) {
    $sort = $sort_by;
  }
  else {
    $sort = '`node`.`created` DESC, `node`.`title` ASC';
  }

  $sort_order = strval(htmlspecialchars(trim($_GET['sort_order'])));
  if (!empty($sort_order) && in_array($sort_order, array('ASC', 'DESC')) && !empty($sort_by)) {
    $sort .= " $sort_order";
  }


  // Title, club_state, sort_by, sort_order, 
  $c = db_query("
    select
    node.nid,                     # Club ID
    node.created,                   #club created date
    node.title,                   # Club titlem
    `cname`.`field_noschool_club_name_value` AS `user_title`,
    `blurb`.`field_club_blurb_value` AS `blurb`, #club blurb
    COUNT(DISTINCT ogm.etid) AS `member_count`,   # club member count
    GROUP_CONCAT(DISTINCT `ogu`.`uid`) AS `member_uids`,
    `school`.field_school_reference_target_id AS `school_id`,     # School ID
    `s`.`name` AS `school_name`,          #school name
    `s`.`level` AS `school_level`,          #school_level
    `s`.`city` AS `school_city`,          #school city
    `s`.`state` AS `school_state`,          #school state
    `s`.`zip` AS `school_zip`           #school zip
  FROM node
    LEFT JOIN `og` og_node ON node.nid = og_node.etid AND og_node.entity_type = 'node'
    LEFT JOIN `og_membership` AS `ogm` ON (`ogm`.`gid` = `og_node`.`gid` AND `ogm`.`entity_type` = 'user')
    LEFT JOIN `users` AS `ogu` ON (`ogu`.`uid` = `ogm`.`etid`)
    LEFT JOIN `field_data_field_club_blurb` AS `blurb` ON (`blurb`.`entity_id` = `node`.`nid`)
    LEFT JOIN `field_data_field_noschool_club_name` AS `cname` ON (`cname`.`entity_id` = `node`.`nid`)
    LEFT JOIN `field_data_field_school_reference` AS `school` ON (
      `school`.`entity_id` = `node`.`nid` AND (
        `school`.`entity_type` = 'node' AND `school`.`deleted` = '0'
      )
    )
    LEFT JOIN `ds_school` AS `s` ON (`s`.`sid` = `school`.`field_school_reference_target_id`)
  WHERE node.type = 'club'
  " . $where . "
  GROUP BY `node`.`nid` ASC
  ORDER BY {$sort}
  LIMIT {$range[0]}, {$range[1]}
  ");

  $final = array();
  foreach ($c->fetchAll() AS $key => $club) {
    // This is bad practice.  But it's fast for now.
    $camps = db_query("
      SELECT
        IF (`new_camps`.`field_campaign_list_nid`, `new_camps`.`field_campaign_list_nid`, `old_camps`.`field_camp_value`) AS `camps`
      FROM `field_data_field_camp` AS `old_camps`
        LEFT JOIN `field_data_field_campaign_list` AS `new_camps` ON (`new_camps`.`entity_id` = `old_camps`.`entity_id`)
      WHERE
        `old_camps`.`entity_id` = " . $club->nid
    )->fetchAll();

    $club->campaigns = dosomething_general_array_vals_multi($camps);

    $projects = db_query("
      SELECT DISTINCT nid
      FROM webform_submissions AS `projects`
      WHERE `projects`.`uid` IN (" . ($club->member_uids ? $club->member_uids : 0) . ")
        AND `projects`.`bundle` = 'project_report'
      ORDER BY `projects`.`sid` ASC
    ")->fetchAll();

    $club->projects = dosomething_general_array_vals_multi($projects);
    $club->path = drupal_lookup_path('alias', 'node/' . $club->nid);
    $final[] = $club;
  }

  echo json_encode($final);
  drupal_exit();
}