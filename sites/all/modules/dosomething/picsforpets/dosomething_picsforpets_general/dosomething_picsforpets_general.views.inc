<?php

/**
 * Implements hook_views_data().
 *
 * @caveat This is a quick (not too dirty) module-specific solution that extends
 * our genericized fb_user_share module for use with webform_entity type views.
 *
 * Ultimately we want a query like:
 * @code
 *   db_query("SELECT sid FROM {webform_submissions} ws
 *     JOIN {fb_user_shares} fs ON fs.entity_id = ws.sid
 *       AND fs.entity_type = 'webform_submission_entity'
 *     JOIN fboauth_users fo ON fo.fbid = fs.fb_user_id
 *     WHERE ((fs.fb_user_id = ':fbid')) OR ((ws.uid = :uid))
 *     WHERE fo.uid = :uid", array(':uid' => $user->uid, ':fbid' => fboauth_fbid_load($user->uid)));
 * @endcode
 *
 * This is accomplished by joining {webform_submissions} to {fb_user_shares},
 * and views ORing with:
 * - Add existing Filter handler for the current user to {webform_submissions}
 * - Add new Filter handler for the current user Facebook ID to {fb_user_shares}
 *
 * @see views_handler_filter_user_current::query()
 * @see views_handler_filter_user_current_fbid::query()
 */
function dosomething_picsforpets_general_views_data() {
  $data = array();

  $data['fb_user_shares']['table']['join'] = array(
    'webform_submissions' => array(
      'left_field' => 'sid',
      'field' => 'entity_id',
    ),
  );

  $data['webform_submissions']['uid'] = array(
    'filter' => array(
      'title' => t('UID'),
      'handler' => 'views_handler_filter_user_current',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function dosomething_picsforpets_general_views_data_alter(&$data) {
  $data['fb_user_shares']['fb_user_id']['filter']['handler'] = 'views_handler_filter_user_current_fbid';
}
