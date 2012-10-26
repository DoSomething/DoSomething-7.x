<?php

/**
  * Service to retrieve My Animals, based off of a user ID and a Facebook ID.
  */
function dosomething_picsforpets_services_get_my_animals($uid, $fbid) {
  $result = db_select('webform_submissions', 's')
    ->fields('s', array('sid', 'submitted'));

  // Pet Image
  $result->leftJoin('field_data_field_fb_app_image', 'pet_image', 'pet_image.entity_id = s.sid');
  $result->leftJoin('file_managed', 'pimg', 'pimg.fid = pet_image.field_fb_app_image_fid');
  $result->addField('pimg', 'filename', 'pet_image');

  // Animal Name
  $result->leftJoin('field_data_field_fb_app_animal_name', 'pet_name', 'pet_name.entity_id = s.sid');
  $result->addField('pet_name', 'field_fb_app_animal_name_value', 'pet_name');

  // Used for filtering by facebook User ID
  $result->leftJoin('fb_user_shares', 'fb_user_shares', 'fb_user_shares.entity_id = s.sid');

  // Used to make sure the pet is published.
  $result->leftJoin('field_data_field_fb_app_published', 'published', "published.entity_id = s.sid AND (published.entity_type = 'webform_submission_entity' AND published.deleted = 0)");

  $result->condition('published.field_fb_app_published_value', 1);
  $or = db_or();
  $or->condition('fb_user_shares.fb_user_id', $fbid);
  $or->condition('s.uid', $uid);
  $result->condition($or);

  $result->groupBy('s.sid');
  $result->orderBy('sid', 'DESC');
  $result->range(0, 18);

  $results = $result->execute()->fetchAll();

  $count = count($results);

  return json_encode(array(
    'count' => $count,
    'results' => $results
  ));
}