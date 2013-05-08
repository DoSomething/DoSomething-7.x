<?php

/**
 * @file
 * There are over 1,000 clubs that have no account associated with them.
 * Many of those clubs have a valid email attached, though.
 *
 * Of 1,432 clubs with no account but a valid email, 450 have accounts
 * associated with that email.  This file loops through clubs with no
 * account, looks for a user with the email, and update the club node
 * with the valid user ID.
 */

$clubs = db_query("
SELECT
n.nid,
n.uid,
e.field_email_value,
u.uid
from node n
left join field_data_field_email e on (e.entity_id = n.nid)
left join users u on (u.mail = e.field_email_value)
where n.uid = 0
and e.field_email_value is not null
and u.mail is not null
")->fetchAll();

drush_print(dt("Starting..."));
foreach ($clubs as $key => $club) {
  $node = node_load($club->nid);
  if ($node->uid == 0) {
  	$node->uid = $club->uid;
    node_save($node);
  }

  drush_print(dt("Finished club {$club->nid}"));
}

drush_print(dt("Done."));