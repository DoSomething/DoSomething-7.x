<?php

/**
  * Service to post a share to the database.
  */
function dosomething_picsforpets_services_get_my_animals($uid, $fbid) {
  $results = db_query("
    SELECT
  DISTINCT webform_submissions.sid AS sid,
  node_field_data_field_fb_app_shelter_reference.nid AS `shelter_nid`,
  webform_submissions.submitted AS `submitted`,
  `thefile`.`filename` AS `pet_image`,
  `pet_name`.`field_fb_app_animal_name_value` AS `pet_name`,
  CONCAT(`pet_address`.`field_pfp_address_locality`, ', ', `pet_address`.`field_pfp_address_administrative_area`) AS `pet_address`,
  `share_count`.`field_fb_app_share_count_value` AS `share_count`,
  GROUP_CONCAT(DISTINCT `three_words`.`field_fb_app_three_words_value`) AS `three_words`
FROM 
`webform_submissions` webform_submissions

LEFT JOIN `field_data_field_fb_app_shelter_reference` field_data_field_fb_app_shelter_reference ON webform_submissions.sid = field_data_field_fb_app_shelter_reference.entity_id AND (field_data_field_fb_app_shelter_reference.entity_type = 'webform_submission_entity' AND field_data_field_fb_app_shelter_reference.deleted = '0')
LEFT JOIN `node` node_field_data_field_fb_app_shelter_reference ON field_data_field_fb_app_shelter_reference.field_fb_app_shelter_reference_target_id = node_field_data_field_fb_app_shelter_reference.nid
LEFT JOIN `field_data_field_fb_app_image` AS `pet_image` ON (`pet_image`.`entity_id` = `webform_submissions`.`sid`)
LEFT JOIN `field_data_field_fb_app_animal_name` AS `pet_name` ON (`pet_name`.`entity_id` = `webform_submissions`.`sid`)
LEFT JOIN `field_data_field_pfp_address` AS `pet_address` ON (`pet_address`.`entity_id` = node_field_data_field_fb_app_shelter_reference.nid)
LEFT JOIN `field_data_field_fb_app_share_count` AS `share_count` ON (`share_count`.`entity_id` = `webform_submissions`.`sid`)
LEFT JOIN `field_data_field_fb_app_three_words` AS `three_words` ON (`three_words`.`entity_id` = `webform_submissions`.`sid`)
LEFT JOIN `file_managed` AS `thefile` ON (`thefile`.`fid` = `pet_image`.`field_fb_app_image_fid`)
LEFT JOIN `node` node ON webform_submissions.nid = node.nid
LEFT JOIN `field_data_field_fb_app_published` field_data_field_fb_app_published ON webform_submissions.sid = field_data_field_fb_app_published.entity_id AND (field_data_field_fb_app_published.entity_type = 'webform_submission_entity' AND field_data_field_fb_app_published.deleted = '0')
LEFT JOIN `fb_user_shares` fb_user_shares ON webform_submissions.sid = fb_user_shares.entity_id
WHERE (( (node.type IN  ('fb_app_data_gathering_form')) AND (field_data_field_fb_app_published.field_fb_app_published_value IN  ('1')) )AND(( (fb_user_shares.fb_user_id = '" . $fbid . "') )OR( (webform_submissions.uid = '" . $uid . "') )))
GROUP BY webform_submissions.sid DESC
ORDER BY share_count DESC
LIMIT 18 OFFSET 0
  ")->fetchAll();

  $count = count($results);

  return json_encode(array(
  	'count' => $count,
    'results' => $results
  ));
}