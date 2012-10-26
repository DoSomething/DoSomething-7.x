<?php

/**
  * Service to post a share to the database.
  */
function dosomething_api_clubs_api($title, $club_state, $sort_by, $sort_order) {
  // Title, club_state, sort_by, sort_order, 
  $c = db_query("
    select
    node.nid,                     # Club ID
    node.created,                   #club created date
    node.title,                   # Club titlem
    #`blurb`.`field_club_blurb_value` AS `blurb`, #club blurb
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
      LEFT JOIN `field_data_field_school_reference` AS `school` ON (
        `school`.`entity_id` = `node`.`nid` AND (
          `school`.`entity_type` = 'node' AND `school`.`deleted` = '0'
        )
      )
    LEFT JOIN `ds_school` AS `s` ON (`s`.`sid` = `school`.`field_school_reference_target_id`)
  WHERE node.type = 'club'
  GROUP BY `node`.`nid` ASC
  ORDER BY `node`.`title` ASC
  LIMIT 0, 25
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
    $final[] = $club;
  }

  return json_encode($final);
  drupal_exit();
}