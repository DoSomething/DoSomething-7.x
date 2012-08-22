<?php

/**
 * Implements hook_views_data().
 */
function dosomething_picsforpets_general_views_data() {
  $data = array();

  // Join the {fb_user_shares} to the {webform_submissions} table on entity ID.
  $data['fb_user_shares']['table']['join'] = array(
    'webform_submissions' => array(
      'left_field' => 'sid',
      'field' => 'entity_id',
    ),
  );

  // Add a custom argument handler onto the Facebook user ID.
  $data['fb_user_shares']['fb_user_id'] = array(
    // Information for automatically generating an argument to find the entity
    // type.
    'argument' => array(
      'handler' => 'views_handler_argument_fb_user_id',
      'click sortable' => TRUE,
      'numeric' => TRUE,
    ),
  );

  return $data;
}
