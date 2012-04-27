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
      return dt('Update the references on grant_judge nodes to point to the webform submissions.');
    case 'dosomething-migrate-update-noderefs':
      return dt('Update the references on webform submissions on nodes of type "scholarship application" so that they point to the newly migrated sid values of project report backs and campaign report backs.');
    case 'dosomething-migrate-noderef-to-entityref-update':
      return dt('Update references on nodes of type "project_update", "grant_alumni", "final_grant_update", "awards_archive", "dsaward_app" so that they point to the newly migrated sid values of project report backs and campaign report backs.');
    case 'dosomething-sql-profile-rollback':
      return dt('temp function to help rollback profiles');
    case 'dosomething-migrate-create-redirect-from-migration-alias':
      return dt('For each migration, grab the URL aliases and create a redirect on the new site.');
    case 'dosomething-migrate-update-user-roles':
      return dt('Fix the membership roles for all users within the given uid range.');
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
  $items['dosomething-migrate-sql-profile-rollback'] = array(
    'description' => 'temp function to help rollback profiles',
    'aliases' => array('dsspr'),
  );
  $items['dosomething-migrate-create-redirect-from-migration-alias'] = array(
    'description' => 'For each migration, create a url alias to point to the content on the new site.',
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'aliases' => array('dsma'),
  );
  $items['dosomething-migrate-update-user-roles'] = array(
    'description' => 'Fix the membership roles for all users within the given uid range.',
    'aliases' => array('dsmuppet'),
    'arguments' => array(
      'first_uid' => 'The uid of the first user to update.',
      'last_uid' => 'The uid of the last user to update.',
    ),
  );
  return $items;
}

function drush_dosomething_migrate_sql_profile_rollback() {
  $confirm = drush_confirm('Are you sure you want to delete all profiles. This cannot be undone.');
  if ($confirm === FALSE) {
    return;
  }
  drush_print('deleting all profiles -- this is not a joke.');
  $pids = db_select('profile', 'p')
    ->fields('p', array('pid'))
    ->execute()
    ->fetchCol();
  $chunks = array_chunk($pids, 50);
  foreach ($chunks as $chunk) {
    profile2_delete_multiple($chunk);
  }
}



/**
 * For each migration, grab the URL aliases and create a redirect on the new site.
 */
function drush_dosomething_migrate_create_redirect_from_migration_alias() {

  $migrations = drush_dosomething_migrate_create_redirect_from_migration_alias_migration_list();

  foreach ($migrations as $migration_table => $base_path) {
    drush_log(dt('Starting syncronization of migration of legacy paths to new redirects for migration @migration.', array('@migration' => substr($migration_table, 14))), 'ok');
    $batch = array(
      'operations' => array(
        array('drush_dosomething_migrate_batch_process_redirects', array($migration_table, $base_path)),
      ),
      'finished' => 'drush_dosomething_migrate_batch_process_redirects_finished',
      'title' => dt('Migrate legacy URLs as redirects.'),
      'init_message' => dt('Beginning to migrate legacy URLs as redirects for @table.', array('@table' => substr($migration_table, 14))),
      'progress_message' => dt('Processed @current out of @total.'),
      'error_message' => dt('Error migrating legacy URLs as redirects... Batch has encountered an error.'),
    );
    batch_set($batch);
    $batch =& batch_get();
    $batch['progressive'] = FALSE;
    drush_backend_batch_process();
  }
}

/**
 * Formerly, this migrated old url_aliases to redirects.  Now it
 * ensures that we ONLY have new aliases and not redirects.
 *
 * @param $migration_table
 *   The migrate module mapping from old id to new id.
 * @param $base_path
 *   The base path for the entity (e.g. webform-submission or node).
 * @param $context
 *   The sandbox and other context for this batch operation.
 */
function drush_dosomething_migrate_batch_process_redirects($migration_table, $base_path, &$context) {
  $d6_database = variable_get('d6_database', 'dosomething_prod');

  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $query = "SELECT count(sourceid1) FROM {{$migration_table}} JOIN {$d6_database}.url_alias ddurl ON ddurl.src = CONCAT('node/', sourceid1)";
    $context['sandbox']['max'] = db_query($query)->fetchColumn();
  }

  $limit = 1000;
  $query = "SELECT sourceid1, destid1, src, dst FROM {{$migration_table}} JOIN {$d6_database}.url_alias ddurl ON ddurl.src = CONCAT('node/', sourceid1) ORDER BY sourceid1 ASC";
  $results = db_query_range($query, $context['sandbox']['progress'], $limit)->fetchAll();

  // Construct an array of paths to check for.
  $paths = array_map(function ($value) use ($base_path) { return $base_path . '/' . $value->destid1; }, $results);

  if (!empty($paths) && count($paths)) {
    // Delete any existing aliases for these paths.
    db_delete('url_alias')
      ->condition('source', $paths, 'IN')
      ->execute();
    // Delete any existing redirects for these paths.
    db_delete('redirect')
      ->condition('redirect', $paths, 'IN')
      ->execute();
    foreach ($results as $result) {
      $real_path = $base_path . '/' . $result->destid1;
      // Ensure we haven't already aliased this one.
      $edit = array(
        'source' => $real_path,
        'alias' => $result->dst,
        'language' => LANGUAGE_NONE,
      );
      try {
        path_save($edit);
        $context['message'] = dt('Now creating an alias from @source to @destination.', array('@source' => $result->dst, '@destination' => $real_path));
      }
      catch (PDOException $e) {
        $context['message'] = dt('Hot damn. @alias already existed with some other path!!!!', array('@alias' => $result->dst));
      }
      $context['sandbox']['progress']++;
      $context['results'][] = $real_path;

    }
  }
  $args = array(
    '@progress' => $context['sandbox']['progress'],
    '@max' => $context['sandbox']['max'],
    '@migration' => substr($migration_table, 14),
    '@migration_number' => array_search($migration_table, array_keys(drush_dosomething_migrate_create_redirect_from_migration_alias_migration_list())) + 1,
    '@migrations' => count(drush_dosomething_migrate_create_redirect_from_migration_alias_migration_list()),
  );
  $context['message'] = dt('Progress = @progress out of @max for migration @migration (@migration_number/@migrations)', $args, 'error');
  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function drush_dosomething_migrate_batch_process_redirects_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One alias processed.', '@count aliases processed.');
  }
  else {
    $message = 'There was an error. ';
    $message .= format_plural(count($results), 'One alias processed.', '@count aliases processed.');
  }
  drush_print($message);
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
      WHERE er.field_project_title_reference_target_id IS NULL')
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
      drush_print($mapping_result);
      if ($mapping_result) {
        $submission->field_project_title_reference['und'][0]['target_id'] = $mapping_result;
        $submission->field_project_title_reference['und'][0]['target_type'] = 'webform_submission_entity';
        webform_submission_update($node, $submission);
        drush_log('Updating webform submission: ' . $data['sid'] . '. Data is now mapped to: ' . $mapping_result, 'ok');
      }
      
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
  drush_log($message, 'ok');
}

/**
 * Provide a list of the migrations and their destination base path.
 *
 * drush_dosomething_migrate_create_redirect_from_migration_alias() needs a list
 * of migrations and the base path they map to to create redirects from legacy
 * aliases.
 */
function drush_dosomething_migrate_create_redirect_from_migration_alias_migration_list() {
  return array(
    // Definitely migrating.
    'migrate_map_dsproject' => 'webform-submission',
    'migrate_map_dsintentions' => 'webform-submission',
    'migrate_map_dscampaignreportbackbullying' => 'webform-submission',
    'migrate_map_dscampaignreportbackcampaignbfb2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackcampaignbfb2012' => 'webform-submission',
    'migrate_map_dscampaignreportbackcampaignebd2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackcampaigngys2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackcampaignhunt2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackcancer2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackcannedfood' => 'webform-submission',
    'migrate_map_dscampaignreportbackewaste2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackgys2012' => 'webform-submission',
    'migrate_map_dscampaignreportbackhealthyschoolsreport' => 'webform-submission',
    'migrate_map_dscampaignreportbackmacys2011' => 'webform-submission',
    'migrate_map_dscampaignreportbackmakeartsaveart' => 'webform-submission',
    'migrate_map_dscampaignreportbacksaveourmusic' => 'webform-submission',
    'migrate_map_dscampaignreportbacksfsreportgallery' => 'webform-submission',
    'migrate_map_dscampaignreportbacksports' => 'webform-submission',
    'migrate_map_dscampaignreportbackstaplesreason' => 'webform-submission',
    'migrate_map_dscampaignreportbacktfj2012' => 'webform-submission',
    'migrate_map_dscampaignreportbacktfjcontestsignup' => 'webform-submission',
    'migrate_map_dscampaignreportbacktrashy2011' => 'webform-submission',
    'migrate_map_dscampaignreportbacktroopletter' => 'webform-submission',
    'migrate_map_dsgrantapplicationaspca' => 'webform-submission',
    'migrate_map_dsgrantapplicationgeneral' => 'webform-submission',
    'migrate_map_dsgrantapplicationgrant' => 'webform-submission',
    'migrate_map_dsscholarshipapplicationatt' => 'webform-submission',
    'migrate_map_dsscholarshipapplicationgeneral' => 'webform-submission',
    'migrate_map_dsscholarshipapplicationsixflags' => 'webform-submission',

    // Clubs need to be migrated, but they're nodes.
    'migrate_map_dsjsonclubevent' => 'node',
    'migrate_map_dsjsonclub' => 'node',

    // Signups almost certainly don't need to come over.
    // 'migrate_map_dscampaignsignupcancer2011' => 'webform-submission',
    // 'migrate_map_dscampaignsignupdecadeofthanks' => 'webform-submission',
    // 'migrate_map_dscampaignsignupebd' => 'webform-submission',
    // 'migrate_map_dscampaignsignupewaste2011' => 'webform-submission',
    // 'migrate_map_dscampaignsignupgys' => 'webform-submission',
    // 'migrate_map_dscampaignsignuphealthyschools' => 'webform-submission',
    // 'migrate_map_dscampaignsignupincreaseyourgreen' => 'webform-submission',
    // 'migrate_map_dscampaignsignupscavenger' => 'webform-submission',
    // 'migrate_map_dscampaignsignupstaples' => 'webform-submission',
    // 'migrate_map_dscampaignsignuptacklehunger' => 'webform-submission',
  );
}

/**
 * Fix the membership roles for all users within the given uid range.
 */
function drush_dosomething_migrate_update_user_roles($first_uid = NULL, $last_uid = NULL) {
  foreach (array($first_uid, $last_uid) as $input) {
    if (!is_int($input) && !ctype_digit($input)) {
      return drush_set_error('dosomething_migrate_member_role_fix', t('Invalid uid.'));
    }
  }

  $confirm = drush_confirm('Are you sure you want to update the roles on these users?');
  if ($confirm === FALSE) {
    return;
  }

  $roles = user_roles();
  $rids = array_flip(array_intersect($roles, dosomething_roles_get_membership_role_hierarchy()));
  for ($uid = $first_uid; $uid <= $last_uid; $uid++) {
    if ($account = user_load($uid)) {
      if (dosomething_roles_user_is_staff_member($account) || dosomething_roles_user_is_too_old($account)) {
        drush_print(sprintf('Skipping user %d', $uid));
        continue;
      }

      $new_role = dosomething_roles_get_member_role($uid);
      $new_rid = $rids[$new_role];

      db_delete('users_roles')->condition('rid', $rids, 'IN')->condition('uid', $uid, '=')->execute();
      db_insert('users_roles')->fields(array('uid' => $uid, 'rid' => $new_rid ))->execute();
      drush_print(sprintf('Updated user %d to %s', $uid, $new_role));
    }
  }
}
