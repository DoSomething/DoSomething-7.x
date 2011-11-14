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
