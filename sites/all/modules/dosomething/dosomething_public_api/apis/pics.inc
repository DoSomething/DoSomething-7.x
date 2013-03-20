<?php

function dosomething_api_pics_api() {
  $result = db_select('webform_submissions', 's')
    ->fields('s', array('sid', 'submitted'));

  $result->leftJoin('fb_user_shares', 'shares', 'shares.entity_id = s.sid');
  $result->leftJoin('field_data_field_fb_app_shelter_reference', 'shelter_ref', "shelter_ref.entity_id = s.sid AND (shelter_ref.entity_type = 'webform_submission_entity' AND shelter_ref.deleted = 0)");
  $result->leftJoin('node', 'shelter', 'shelter.nid = shelter_ref.field_fb_app_shelter_reference_target_id');
  $result->addField('shelter', 'nid', 'shelter_nid');

  $result->leftJoin('field_data_field_fb_app_image', 'pet_image', 'pet_image.entity_id = s.sid');
  $result->leftJoin('file_managed', 'pimg', 'pimg.fid = pet_image.field_fb_app_image_fid');
  $result->addField('pimg', 'filename', 'pet_image');

  $result->leftJoin('field_data_field_fb_app_animal_name', 'pet_name', 'pet_name.entity_id = s.sid');
  $result->addField('pet_name', 'field_fb_app_animal_name_value', 'pet_name');

  $result->leftJoin('field_data_field_pfp_address', 'pet_address', 'pet_address.entity_id = shelter.nid');
  $result->addExpression("CONCAT(pet_address.field_pfp_address_locality, ', ', pet_address.field_pfp_address_administrative_area)", 'pet_address');

  $result->leftJoin('field_data_field_fb_app_share_count', 'share_count', 'share_count.entity_id = s.sid');
  $result->addField('share_count', 'field_fb_app_share_count_value', 'share_count');

  $result->leftJoin('field_data_field_fb_app_three_words', 'three_words', 'three_words.entity_id = s.sid');
  $result->addExpression('GROUP_CONCAT(DISTINCT three_words.field_fb_app_three_words_value)', 'three_words');

  $result->leftJoin('fb_user_shares', 'fb_user_shares', 'fb_user_shares.entity_id = s.sid');

  $result->leftJoin('field_data_field_fb_app_published', 'published', "published.entity_id = s.sid AND (published.entity_type = 'webform_submission_entity' AND published.deleted = 0)");

  $result->condition('published.field_fb_app_published_value', 1);
  $or = db_or();
  $or->condition('fb_user_shares.fb_user_id', $fbid);
  $or->condition('s.uid', $uid);
  $result->condition($or);

  $result->groupBy('s.sid');
  $result->orderBy('share_count', 'DESC');
  $result->range(0, 18);

  $results = $result->execute()->fetchAll();

  $count = count($results);

  echo '<pre>', print_r($results), '</pre>';
  drupal_exit();

/*  return json_encode(array(
    'count' => $count,
    'results' => $results
  ));*/
}