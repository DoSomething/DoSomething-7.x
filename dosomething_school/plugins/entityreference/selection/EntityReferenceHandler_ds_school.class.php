<?php

/**
 * Override for the DoSomething School type.
 */
class EntityReferenceHandler_ds_school extends EntityReference_SelectionHandler_Generic {
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    global $user;

    $query = parent::buildEntityFieldQuery($match, $match_operator);

    // Only let them see schools owned by themselves or admin.
    $query->propertyCondition('uid', array(1, $user->uid), 'IN');
    return $query;
  }
}

