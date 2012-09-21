<?php

/**
  * Service to post a share to the database.
  */
function dosomething_picsforpets_services_submit_share($info) {
  $pet_id = $info['pet_id'];
  $fb_id = $info['fb_id'];
  $status = 'ok';

  module_load_include('module', 'webform_entity', 'webform_entity');
  $transaction = db_transaction();
  $submission = webform_entity_load_webform_submission($pet_id);
  if (!$submission) {
    watchdog('dosomething_picsforpets', 'Invalid webform submission id submitted as a share.');
    return FALSE;
  }

  $value = 0;
  if (isset($submission->field_fb_app_share_count[LANGUAGE_NONE])) {
    $value = $submission->field_fb_app_share_count[LANGUAGE_NONE][0]['value'];
  }
  $value++;
  $submission->field_fb_app_share_count[LANGUAGE_NONE][0]['value'] = $value;
  webform_entity_save_webform_submission($submission);

  // Log information about this share to the DB.
  $share = new stdClass;
  $share->entity_type = 'webform_submission_entity';
  $share->entity_id = $pet_id;
  $share->system_path = 'webform-submission/' . $pet_id;
  $share->fb_user_id = $fb_id;
  $share->created = REQUEST_TIME;
  drupal_write_record('fb_user_shares', $share);

  // Retrieve the total number of shares for this user.
  $user_shares = db_query("
    SELECT count(fb_user_id)
    FROM {fb_user_shares}
    WHERE fb_user_id = :fbid", array(':fbid' => $fb_id))
    ->fetchField();

  return json_encode(array(
  	'status' => $status,
  	'share-count' => $user_shares
  ));
}