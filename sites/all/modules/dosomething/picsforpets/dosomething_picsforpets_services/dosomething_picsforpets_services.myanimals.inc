<?php

/**
  * Service to post a share to the database.
  */
function dosomething_picsforpets_services_get_my_animals($info) {
  $fb_id = $info['uid'];

  $results = db_query("
    SELECT
    DISTINCT webform_submissions.sid AS sid,
    node.created AS node_created,
    theimg.uri AS file_managed_field_data_field_fb_app_image_uri,
    `anim_name`.`field_fb_app_animal_name_value` AS `animal_name`,
    `anim_age`.`field_fb_app_age_value` AS `animal_age`,
    `anim_type`.`field_fb_app_animal_type_value` AS `animal_type`,
    `anim_other`.`field_fb_app_other_value` AS `animal_other`,
    GROUP_CONCAT(`anim_three_words`.`field_fb_app_three_words_value`) AS `animal_three_words`,
    CONCAT(`anim_address`.`field_pfp_address_locality`, ',', `anim_address`.`field_pfp_address_administrative_area`) AS `animal_address`,
    `anim_shelter`.`field_fb_app_shelter_name_value` AS `animal_shelter`,
    DATE_FORMAT((DATE_ADD('19700101', INTERVAL webform_submissions.submitted SECOND) + INTERVAL -14400 SECOND), '%Y%m%d%H%i') AS webform_submissions_submitted_minute
  FROM `webform_submissions` webform_submissions
  LEFT JOIN `field_data_field_fb_app_animal_name` AS `anim_name` ON (`anim_name`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN `field_data_field_fb_app_animal_type` AS `anim_type` ON (`anim_type`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN `field_data_field_fb_app_age` AS `anim_age` ON (`anim_age`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN `field_data_field_fb_app_other` AS `anim_other` ON (`anim_other`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN `field_data_field_fb_app_three_words` AS `anim_three_words` ON (`anim_three_words`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN field_data_field_pfp_address AS `anim_address` ON (`anim_address`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN field_data_field_fb_app_shelter_name AS `anim_shelter` ON (`anim_shelter`.`entity_id` = `webform_submissions`.`sid`)
  LEFT JOIN `field_data_field_fb_app_image` `anim_img` ON webform_submissions.sid = `anim_img`.entity_id AND (`anim_img`.entity_type = 'webform_submission_entity' AND `anim_img`.deleted = '0')
  LEFT JOIN `file_managed` `theimg` ON `anim_img`.field_fb_app_image_fid = `theimg`.fid
  LEFT JOIN `node` node ON webform_submissions.nid = node.nid
  LEFT JOIN `field_data_field_fb_app_published` `anim_published` ON webform_submissions.sid = `anim_published`.entity_id AND (`anim_published`.entity_type = 'webform_submission_entity' AND `anim_published`.deleted = '0')
  LEFT JOIN `fb_user_shares` fb_user_shares ON webform_submissions.sid = fb_user_shares.entity_id
  WHERE (( (webform_submissions.uid = '778374') )AND(( (node.type IN  ('fb_app_data_gathering_form')) AND (`anim_published`.field_fb_app_published_value IN  ('1')) )))
  ORDER BY webform_submissions_submitted_minute ASC
  ")->fetchAll();

  $count = count($results);

  return json_encode(array(
  	'count' => $count,
    'results' => $results
  ));
}