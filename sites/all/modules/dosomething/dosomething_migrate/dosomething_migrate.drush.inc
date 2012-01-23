<?php

/**
 * @file
 * Drush support for the migrate module
 */

/**
 * Implementation of hook_drush_help().
 */
function dosomething_migrate_drush_help($section) {
  switch ($section) {
    case 'drush:dosomething-migrate-review':
      return dt('Review some random records from one or more migrations');
    case 'dosomething-migrate-update-grant-judge':
      return db('Update the references on grant_judge nodes to point to the webform submissions.');
    case 'dosomething-migrate-update-noderefs':
      return dt('Update the references on webform submissions on nodes of type "scholarship application" so that they point to the newly migrated sid values of project report backs and campaign report backs.');
    case 'dosomething-migrate-noderef-to-entityref-update':
      return dt('Update references on nodes of type "project_update", "grant_alumni", "final_grant_update", "awards_archive", "dsaward_app" so that they point to the newly migrated sid values of project report backs and campaign report backs.');
  }
}

/**
 * Implementation of hook_drush_command().
 */
function dosomething_migrate_drush_command() {
  $items['dosomething-migrate-review'] = array(
    'description' => 'Review some random records from on or more migrations',
    'options' => array(
      'all' => 'Process all migrations that come after the specified migration. If no value is supplied, all migrations are processed.',
      'group' => 'Name of the migration group to run',
    ),
    'arguments' => array(
      'migration' => 'Restrict to a single migration. Optional',
    ),
    'drupal dependencies' => array('migrate'),
    'aliases' => array('dsmr'),
  );
  $items['dosomething-migrate-update-grant-judge'] = array(
    'description' => 'Update the references on grant_judge nodes.',
  );
  $items['dosomething-migrate-update-noderefs'] = array(
    'description' => 'Update the references on scholarship applications webform submissions',
    'aliases' => array('dsmunr'),
  );
  $items['dosomething-migrate-noderef-to-entityref-update'] = array(
    'description' => 'Update the node references and convert them to webform references',
    'aliases' => array('dsmneu'),
  );
  return $items;
}

function drush_dosomething_migrate_review($args = NULL) {
  try {
    $migrations = drush_migrate_get_migrations($args);
    foreach ($migrations as $name => $migration) {
      //var_dump($migration);
      $map = $migration->getMap();
      if (!$map instanceof MigrateSQLMap) {
        continue;
      }
      if (!$migration->sourceItemReviewPattern || !$migration->destinationItemReviewPattern) {
        continue;
      }

      drush_print("\n" . dt('Compare @migration items', array('@migration' => $name)) . "\n");

      // Pull some random items from the map.
      $query = $map->getConnection()->select($map->getMapTable(), 'map')
                ->fields('map')
                ->orderBy('rand()')
                ->range(0, 5);
      $result = $query->execute();

      $table = array(array('Source', 'Destination'));
      foreach($result->fetchAll() as $row) {
        $table[] = array(
          str_replace(':id:', $row->sourceid1, $migration->sourceItemReviewPattern),
          str_replace(':id:', $row->destid1, $migration->destinationItemReviewPattern),
        );
      }
      if (count($table) === 1) {
        drush_print(dt('This migration has no imported items.'), 2);
      }
      else {
        drush_print_table($table, TRUE);
      }
    }
  }
  catch (MigrateException $e) {
    drush_print($e->getMessage());
    exit;
  }
}

// Implement drush_hook_COMMAND_validate().
function drush_dosomething_migrate_review_validate($args = NULL) {
  return drush_migrate_validate_common($args);
}

function drush_dosomething_migrate_update_grant_judge() {
  drush_print("Updating grant_judge references from nodes to webform submissions...");

  $source_migrations = array('DSGrantApplicationAspca', 'DSGrantApplicationGeneral', 'DSGrantApplicationGrant');
  $maps = array();
  foreach ($source_migrations as $key) {
    $maps[$key] = Migration::getInstance($key)->getMap();
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'grant_judge')
    ->fieldCondition('field_grant_judge_nid', 'value', '0', '>');
  $result = $query->execute();
  if (empty($result['node'])) {
    drush_print("No nodes found.");
    return;
  }
  foreach ($result['node'] as $nid => $deets) {
    $node = node_load($nid);
    $grant_app_nid = $node->field_grant_judge_nid['und'][0]['value'];
    drush_print("looking up $node->nid: $node->title - references $grant_app_nid");
    $sid = NULL;
    foreach ($maps as $key => $map) {
      if ($sid = $map->lookupDestinationID(array($grant_app_nid))) {
        $sid = reset($sid);
        break;
      }
    }
    if ($sid) {
      drush_print("found $sid, updating.");
      $node->field_grant_judge_application['und'][0]['target_type'] = 'webform_submission_entity';
      $node->field_grant_judge_application['und'][0]['target_id'] = $sid;
      node_save($node);
    }
  }
}

/**
 * Callback function for drush dosomething-migrade-update-noderefs.
 */
function drush_dosomething_migrate_update_noderefs() {
  drush_log('Starting batch update of webform submissions.', 'ok');
  $batch = array(
    'operations' => array(
      array('dosomething_migrate_update_noderefs', array()),
    ),
    'finished' => 'dosomething_migrate_update_nodefres_finished',
    'title' => t('Processing node refs to entity refs'),
    'init_message' => t('Updating node refs to entity refs... Begin.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Error updating node refs... Batch has encountered an error.'),
  );
  batch_set($batch);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}

function dosomething_migrate_update_noderefs(&$context) {
  require_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');
  $records_to_update = 50;
  if (empty($context['sandbox'])) {
    // Find the number of records that need to be updated.
    // Records that need to be updated are those that have a value for a node
    // reference to a project but not an entity reference to a webform submission
    // project.
    $context['sandbox']['max'] = db_query('
      SELECT COUNT(nr.field_webform_project_nid)
      FROM {field_data_field_webform_project} nr
      LEFT JOIN {field_data_field_project_title_reference} er ON nr.entity_id = er.entity_id
      WHERE er.field_project_title_reference_target_id IS NOT NULL')
      ->fetchField();
    if(!$context['sandbox']['max']) {
      $context['sandbox']['max'] = 0;
    }
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
  }
  if ($context['sandbox']['max'] > 0) {
    $action_mapping_tables = array(
      'migrate_map_dscampaignreportbackcampaignbfb2011',
      'migrate_map_dscampaignreportbackcampaignebd2011',
      'migrate_map_dscampaignreportbackcampaigngys2011',
      'migrate_map_dscampaignreportbackcampaignhunt2011',
      'migrate_map_dscampaignreportbackcannedfood',
      'migrate_map_dscampaignreportbackhealthyschoolsreport',
      'migrate_map_dscampaignreportbacksaveourmusic',
      'migrate_map_dscampaignreportbacksfsreportgallery',
      'migrate_map_dscampaignreportbackstaplesreason',
      'migrate_map_dscampaignreportbacktfjcontestsignup',
      'migrate_map_dscampaignreportbacktroopletter',
      'migrate_map_dsproject',
    );

    $result = db_query_range('
      SELECT ws.nid AS nid, nr.entity_id AS sid
      FROM field_data_field_webform_project nr
      LEFT JOIN field_data_field_project_title_reference er ON nr.entity_id = er.entity_id
      LEFT JOIN webform_submissions ws ON ws.sid = nr.entity_id
      WHERE er.field_project_title_reference_target_id IS NULL
      AND nr.entity_id > :sid',
      0, $records_to_update, array(':sid' => $context['sandbox']['current'])
    );
    while ($data = $result->fetchAssoc()) {
      $node = node_load($data['nid']);
      $submission = webform_get_submission($data['nid'], $data['sid'], $reset = FALSE);
      $node_to_map = $submission->field_webform_project['und'][0]['nid'];


      // Find the mapping of the old node id to the new sid.
      $query = "SELECT destid1 FROM (";
      for ($i = 0; $i < count($action_mapping_tables); $i++) {
        if ($i === 0) {
          $query .= "SELECT sourceid1, destid1 FROM $action_mapping_tables[$i]";
        }
        else {
          $query .= " UNION SELECT sourceid1, destid1 FROM $action_mapping_tables[$i]";
        }
      }
      $query .= ") t1 WHERE sourceid1 = $node_to_map";
      $mapping_result = db_query($query)->fetchField();
      $submission->field_project_title_reference['und'][0]['target_id'] = $mapping_result;
      $submission->field_project_title_reference['und'][0]['target_type'] = 'webform_submission_entity';
      webform_submission_update($node, $submission);
      drush_log('Updating webform submission: ' . $data['sid'] . '. Data is now mapped to: ' . $mapping_result, 'ok');
      $context['sandbox']['progress'] += 1;
      $context['sandbox']['current'] = $data['sid'];
      $context['results'][] = $data['sid'];
      $context['message'] = 'processed ' . $data['sid'];
    }

    drush_log($context['sandbox']['progress'] / $context['sandbox']['max'] * 100 . ' percent complete', 'ok');
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
}

function dosomething_migrate_update_nodefres_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One webform submission processed.', '@count webform submissions processed.');
  }
  else {
    $message = 'There was an error. ';
    $message .= format_plural(count($results), 'One webform submission processed.', '@count webform submissions processed.');
  }
  drush_print($message);
}

/**
 * Callback function for drush dosomething-migrate-noderef-to-entityref-update.
 */
function drush_dosomething_migrate_noderef_to_entityref_update() {
  drush_log('Starting batch update. Converting node references into webform submission references.', 'ok');
  $batch = array(
    'operations' => array(
      array('dosomething_migrate_update_nodref_entref', array()),
    ),
    'finished' => 'dosomething_migrate_update_noderef_entref_finished',
    'title' => t('Processing node refs to entity refs'),
    'init_message' => t('Updating node refs. Adding entity refs... Begin.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Error updating node refs... Batch has encountered an error.'),
  );
  batch_set($batch);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}

function dosomething_migrate_update_nodref_entref(&$context) {
  $records_to_update = 100;
  if (empty($context['sandbox'])) {
    // Find the number of records that need to be updated.
    // Records that need to be updated are those that have a value for a node
    // reference to a project but not an entity reference to a webform
    // submission project.
    $context['sandbox']['max'] = (int) db_query("
      SELECT
        COUNT(f.nid)
      FROM (
        (SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_alumni_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_alumni_project} r
        WHERE
          n.nid = r.entity_id
        AND (type = 'awards_archive' OR type ='grant_alumni'))

        UNION

        (SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_project} r
        WHERE
          n.nid = r.entity_id
        AND (type = 'final_grant_update' OR type ='project_update'))

        UNION

        (SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_plumgrant_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_plumgrant_project} r
        WHERE
          n.nid = r.entity_id
        AND type = 'dsaward_app')
      ) AS f

    LEFT JOIN
      {field_data_field_webform_project_submission} er ON er.entity_id = f.nid
    WHERE
      f.source_nid IS NOT NULL
    AND er.field_webform_project_submission_target_id IS NULL")
          ->fetchField();
    if(!$context['sandbox']['max']) {
      $context['sandbox']['max'] = 0;
    }
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
  }
  if ($context['sandbox']['max'] > 0) {
    $result = db_query_range("
      SELECT
        f.nid nid,
        f.type,
        f.source_nid source_nid,
        er.field_webform_project_submission_target_id
      FROM
        ((SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_alumni_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_alumni_project} r
        WHERE
          n.nid = r.entity_id
        AND (type = 'awards_archive' OR type ='grant_alumni')
        )
        UNION
        (SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_project} r
        WHERE
          n.nid = r.entity_id
        AND (type = 'final_grant_update' OR type ='project_update'))
        UNION
        (SELECT
          n.type,
          n.nid,
          r.entity_id,
          n.title,
          r.field_plumgrant_project_nid source_nid
        FROM
          {node} n,
          {field_data_field_plumgrant_project} r
        WHERE
          n.nid = r.entity_id
        AND type = 'dsaward_app')) AS f
      LEFT JOIN
        {field_data_field_webform_project_submission} er ON er.entity_id = f.nid
      WHERE f.source_nid IS NOT NULL
      AND er.field_webform_project_submission_target_id IS NULL
      AND nid > :nid
      ORDER BY nid", 0, $records_to_update, array(':nid' => $context['sandbox']['current'])
    );
    $data = $result->fetchAllAssoc('nid');
    $node_to_old_nid_ref = array();
    foreach ($data as $nid => $node_info) {
      $node_to_old_nid_ref[$nid] = $node_info->source_nid;
    }
    $nodes = node_load_multiple(array_keys($node_to_old_nid_ref));
    // Find the mapping of the old node id to the new sid.
    $node_ref_to_sid_map = db_select('migrate_map_dsproject', 'mm')
      ->fields('mm', array('sourceid1', 'destid1'))
      ->condition('sourceid1', array_values($node_to_old_nid_ref), 'IN')
      ->execute()
      ->fetchAllKeyed();

    foreach ($nodes as $nid => $node) {
      if (isset($node_to_old_nid_ref[$nid]) && isset($node_ref_to_sid_map[$node_to_old_nid_ref[$nid]])) {
        $node->field_webform_project_submission[LANGUAGE_NONE][0]['target_id'] = $node_ref_to_sid_map[$node_to_old_nid_ref[$nid]];
        //They should all be webform submission entities.
        $node->field_webform_project_submission[LANGUAGE_NONE][0]['target_type'] = 'webform_submission_entity';
        node_save($node);
        // Update the mapping table
        $success_records[$node->nid] = array(
          'nid' => $nid,
          'ref_nid' => $node_to_old_nid_ref[$nid],
          'ref_sid' => $node_ref_to_sid_map[$node_to_old_nid_ref[$nid]],
        );
      }
      else {
        // Log to the fail table
        $fail_records[] = $node->nid;
        drush_log("Could not find mapping for reference on node $node->nid. See failure table for full list.", 'warning');
      }
      $context['sandbox']['progress'] += 1;
      $context['sandbox']['current'] = $node->nid;
      $context['results'][] = $node->nid;
      $context['message'] = 'processed ' . $node->nid;
    }

    if (count($success_records)) {
      db_delete('dosomething_project_nid_sid_map')
        ->condition('nid', array_keys($success_records), 'IN')
        ->execute();
      $query = db_insert('dosomething_project_nid_sid_map')
        ->fields(array('nid', 'ref_nid', 'ref_sid'));
      foreach($success_records as $record) {
        $query->values($record);
      }
      $query->execute();
      // Drop the record from the fail table if it is there.
      db_delete('dosomething_project_nid_sid_fails')
        ->condition('nid', array_keys($success_records), 'IN')
        ->execute();
    }
    if (count($fail_records)) {
      db_delete('dosomething_project_nid_sid_fails')
        ->condition('nid', $fail_records, 'IN')
        ->execute();
      $query = db_insert('dosomething_project_nid_sid_fails')
        ->fields(array('nid'));
      foreach($fail_records as $record) {
        $query->values(array('nid' => $record));
      }
      $query->execute();

    }

    drush_log($context['sandbox']['progress'] / $context['sandbox']['max'] * 100 . ' percent complete', 'ok');
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
}

function dosomething_migrate_update_noderef_entref_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One node reference to webform submission mapping processed.', '@count node reference to webform submission mappings processed.');
  }
  else {
    $message = 'There was an error. ';
    $message .= format_plural(count($results), 'One node reference to webform submission mapping processed.', '@count node reference to webform submission mappings processed.');
  }
  drush_print($message);
}

