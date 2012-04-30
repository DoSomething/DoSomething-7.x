<?php

/**
 * @file
 * Hooks provided by Entityqueue.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * This hook allows modules to provide their own entity queues.
 *
 * @return array
 *   An associative array containing queues passed through entity_import().
 */
function hook_entityqueue_default_queues() {
  $queues = array();

  $queues['featured_articles'] = entity_import('entityqueue',
    '{
      "name" : "featured_articles",
      "type" : "node",
      "subqueue" : "1",
      "label" : "Featured articles",
      "subqueue_label" : "Featured articles",
      "parent_name" : null,
      "uid" : "1",
      "rdf_mapping" : []
    }');

  return $queues;
}

/**
 * Define a new queue type.
 */
function hook_entityqueue_types() {
  return array(
    'my_node_queue' => array(
      'label' => t('My Node Queue'),
      'base type' => 'node',
    ),
  );
}

/**
 * Alter the queue types.
 */
function hook_entityqueue_types_alter(&$types) {
  $types['my_node_queue']['label'] = t('Your Node Queue');
}

/**
 * @} End of "addtogroup hooks".
 */
