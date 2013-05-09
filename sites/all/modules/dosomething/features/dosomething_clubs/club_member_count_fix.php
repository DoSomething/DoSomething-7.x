<?php

/**
 * @file
 * Some club owners are not associated with the og_membership table,
 * making the clubs pull very confusing when there are members in a
 * club that are not specified.
 *
 * Ooops.
 *
 * This script fixes that, by going through all clubs, checking the
 * og_membership table for rows, and if applicable inserting new rows
 * into og_membership.
 */

$query = db_query("
SELECT
n.uid,
o.gid,
(select COUNT(id) FROM og_membership m where m.gid = o.gid) AS ct
FROM node n
inner JOIN og o ON (o.etid = n.nid)
where n.type = 'club'
and n.uid <> 0
group by o.etid
HAVING ct < 1")
->fetchAll();

foreach ($query AS $key => $data) {
  $record = array(
    'type' => 'og_membership_type_default',
    'etid' => $data->uid,
    'entity_type' => 'user',
    'gid' => $data->gid,
    'state' => 1,
    'created' => REQUEST_TIME,
  );

  drupal_write_record('og_membership', $record);
}

drush_print(dt("Done."));