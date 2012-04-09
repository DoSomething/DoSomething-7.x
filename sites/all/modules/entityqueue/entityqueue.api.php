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
 * Alter the allowed queue types.
 *
 * @param array $types
 *   An array of queue types.
 */
function hook_entityqueue_type_get_name_alter(&$types) {
  $types['my_new_type'] = t('My New Type');
}

/**
 * @} End of "addtogroup hooks".
 */
