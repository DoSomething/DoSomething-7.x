<?php

$plugin = array(
  'title' => t('DoSomething School Reference'),
  'handler' => 'EntityReferenceHandler_ds_school',
);

/**
 * Override for the DoSomething School type.
 */
class EntityReferenceHandler_ds_school extends EntityReferenceHandler_base {
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    global $user;

    $query = parent::buildEntityFieldQuery($match, $match_operator);

    // Only let them see schools owned by themselves or admin.
    $query->propertyCondition('uid', array(1, $user->uid), 'IN');

    return $query;
  }
}
