<?php

/**
 * @file
 * Migration for nodequeues to entityqueues.
 */

/**
 * Implements hook_drush_command().
 */
function dosomething_entityqueue_drush_command() {
  $items['dosomething-entityqueue-migrate'] = array(
    'description' => 'Migrate nodequeues to entityqueue.',
    'aliases' => array('dseqm'),
  );

  return $items;
}

/**
 * Migrates Drupal 6 nodequeues to Drupal 7 entityqueues.
 */
function drush_dosomething_entityqueue_migrate() {
  $entityqueues = db_select('entityqueue', 'e')
    ->fields('e')
    ->execute()
    ->fetchAllAssoc('queue_id');

  // Find all of the nodequeues.
  db_set_active('dosomething6');
  $query = db_select('nodequeue_queue', 'nq');
  $queue_id = $query->addField('nq', 'qid', 'queue_id');
  $nodequeues = $query
    ->fields('nq', array('title', 'size', 'name'))
    ->execute()
    ->fetchAllAssoc($queue_id);

  // Find the node types for each queue.
  $types = db_select('nodequeue_types', 'nt')
    ->fields('nt')
    ->execute();

  // Get the bundles for each queue.
  $entity_info = entity_get_info('node');
  db_set_active('default');
  $webform_map = variable_get('webform_migrate_webform_mapping', array());
  foreach ($types as $delta => $row) {
    if (isset($webform_map[$row->type])) {
      $nodequeues[$row->qid]->type[] = 'webform_submission_entity';
      $entity = entity_load_single('node', $webform_map[$row->type]);
      $nodequeues[$row->qid]->data['target_bundles'][] = $entity->type;
    }
    else {
      if (isset($entity_info['bundles'][$row->type])) {
        $nodequeues[$row->qid]->type[] = 'node';
        $nodequeues[$row->qid]->data['target_bundles'][] = $row->type;
      }
    }
  }

  /*
  // Find the nodes for each queue.
  $nodes = db_select('nodequeue_nodes', 'nn')
    ->fields('nn')
    ->execute();
  foreach ($nodes as $delta => $row) {
    $nodequeues[$row->qid]->nodes[$row->position] = $row->nid;
  }
  //*/

  foreach ($nodequeues as $nodequeue) {
    $nodequeue = (array) $nodequeue;
    // Don't create a queue if there is no type.
    if (!isset($nodequeue['type'])) {
      continue;
    }
    // Don't create a queue if there is more than one type.
    if (count(array_flip($nodequeue['type'])) > 1) {
      continue;
    }
    // Don't overwrite this queue.
    if (isset($entityqueues[$nodequeue['queue_id']])) {
      continue;
    }

    // Set the entity type.
    $nodequeue['type'] = reset($nodequeue['type']);
    // Move the size into the data array.
    $nodequeue['data']['max_size'] = $nodequeue['size'];

    // Set the defaults for this queue.
    $nodequeue += array(
      'label' => $nodequeue['title'],
      'subqueue' => TRUE,
      'module' => 'dosomething_entityqueue',
      'is_new' => TRUE,
      'uid' => 1,
    );

    // Create and save the queue.
    $entityqueue = entityqueue_create($nodequeue);
    entityqueue_save($entityqueue);
  }
}
