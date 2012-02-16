<?php

/**
 * @file
 * Drush support for the migrate module
 */

/**
 * Implementation of hook_drush_help().
 */
function dosomething_club_migrate_drush_help($section) {
  switch ($section) {
    case 'dosomething-club-migrate-start':
      return dt('Begin the process of migrating club OG data from database records.');
  }
}

/**
 * Implementation of hook_drush_command().
 */
function dosomething_club_migrate_drush_command() {
  $items['dosomething-club-migrate-start'] = array(
    'description' => 'Begin the migration of club OG data from our database records.',
    'aliases' => array('dsmog'),
  );
  return $items;
}

function drush_dosomething_club_migrate_start() {
  drush_print('starting club OG migration');

  $batch = array(
    'operations' => array(
      array('dosomething_club_migrate_batch_start', array()),
    ),
    'finished' => 'dosomething_club_migrate_finished',
    'title' => t('Processing club OG data.'),
    'init_message' => t('Statring club OG data update...'),
    'progress_message' => t('Processed @current out of @total OG actions.'),
    'error_message' => t('Error updating OG action... Batch has encountered an error.'),
  );
  batch_set($batch);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();

}

function dosomething_club_migrate_batch_start(&$context) {
  $records_to_update = 1;
  if (empty($context['sandbox'])) {
    // Find the number of group actions that need to be rerun.
    // OG actions that need to be replayed are those that have an id in the
    // dosome_migrating_og_membership_change table but without the same id
    // stored in the dosomething_club_migrate_status table.

    $context['sandbox']['max'] = (int)
      db_query('
        SELECT COUNT(ogchange.id)
        FROM {dosome_migrating_og_membership_change} ogchange
        WHERE ogchange.id NOT IN (SELECT id FROM {dosomething_club_migrate_status})')
      ->fetchField();
    if(!$context['sandbox']['max']) {
      $context['sandbox']['max'] = 0;
    }
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
  }
  if ($context['sandbox']['max'] > 0) {
    $data = db_query_range('
        SELECT ogchange.id AS cid, ogchange.uid AS uid, ogchange. gid AS gid, ogchange.op AS op, ogchange.changed AS changed
        FROM {dosome_migrating_og_membership_change} ogchange
        WHERE ogchange.id NOT IN (SELECT id FROM {dosomething_club_migrate_status})
        AND ogchange.id > :id
        ORDER BY cid ASC', 0, $records_to_update, array(':id' => $context['sandbox']['current']))
      ->fetchAllAssoc('cid');
    //Loop through the change ids (cid) and replay the action.
    foreach ($data as $record) {
      $cid = $record->cid;
      $nid = $record->gid;
      $uid = $record->uid;
      $op = $record->op;

      // First find the group. Group gid in d6 is a nid so look up the mapping
      // of clubs in the migration mapping table.
      $dest_nid = db_query('
        SELECT destid1
        FROM {migrate_map_dsjsonclub}
        WHERE sourceid1 = :gid', array(':gid' => $nid))
      ->fetchField();
      // If mapping found set to new mapping other take the original.
      $nid = $dest_nid !== FALSE ? $dest_nid : $nid;

      // Now we have a node id so let's find the gid. In D7 there is a different
      // group id (gid) associated with every group entity because more than
      // nodes can be groups.
      $etids = array();
      $etids[] = $nid;
      $group_array = og_get_group_ids('node', $etids);
      $gid = isset($group_array[$nid]) ? $group_array[$nid] : FALSE;

      // Check to see if the uid was mapped only if we got a gid.
      if ($gid) {
        $dest_uid = db_query('
          SELECT destid1
          FROM ((SELECT sourceid1, destid1 FROM migrate_map_dsjsonnewuser) UNION (SELECT sourceid1, destid1 FROM migrate_map_dsjsonchangeduser)) mappeduid
          WHERE sourceid1 = :uid', array(':uid' => $uid))
        ->fetchField();

        // If mapping found set to new mapping other take the original.
        $uid = $dest_uid !== FALSE ? $dest_uid : $uid;
      }

      if ($gid && $uid) {
        switch ($record->op) {
          case 'admin new' :
            // In the case of new administrators it may be the case that a user
            // was given the group (i.e. they became the author) but we don't need
            // to worry about this because the other migration scripts should
            // account for uid changes.

            // Try to add the user to the group. Will throw an error if they are
            // already a member.
            try {
              $membership = og_membership_create($gid, $uid, OG_ADMINISTRATOR_ROLE)
              $membership->save();
            }
            catch (Exception $e) {
              drush_log('Attempted to duplicate a membership. Adding role to membership instead.', 'warning');
              //Add admin member role to group user for group
              og_role_grant($gid, $uid, OG_ADMINISTRATOR_ROLE);
            }
            $row = stdClass();
            $row->cid = $cid;
            //TODO possible scenarion to consider is that we have done the club memebership saving but fail to record that it happened.
            // Alternative solution is to start but recording that we've done this row and bail out if the record doens't write using try/catch.
            $status = drupal_write_record('dosomething_club_migrate_status', $row);
            if (!$status) {
              drush_log("An issue was encounterd. We processed the change but failed to record this is the database. The change id was $cid - You may want to manually enter this into the table that tracks processed changes.", 'error');
            }
            break;

          case 'user approve' :
            break;

          case 'user delete' :
            break;

          case 'user deny' :
            break;

          case 'user insert' :
            break;

          case 'user update' :
            break;

          default :
            // Do nothing.
        }
      }
      else {
        $message = "Issue detected on replay of id $cid. Group or user missing."
      }
      $context['sandbox']['progress'] += 1;
      $context['sandbox']['current'] = $cid;
      $context['results'][] = $cid;
      $context['message'] = 'Processed record id ' . $cid;
    }
    drush_log($context['sandbox']['progress'] / $context['sandbox']['max'] * 100 . ' percent complete', 'ok');
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
}

function dosomething_club_migrate_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'Replayed one OG action on clubs.', 'Replayed @count OG actions on clubs.');
  }
  else {
    $message = 'There was an error. ';
    $message .= format_plural(count($results), 'Replayed one OG action on clubs.', 'Replayed @count OG actions on clubs.');
  }
  drush_print($message);
}

