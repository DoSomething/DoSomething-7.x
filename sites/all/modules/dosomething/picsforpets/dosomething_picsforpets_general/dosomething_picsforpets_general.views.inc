<?php

/**
 * Implements hook_views_data().
 *
 * @kludge This is a quick (not too dirty) module-specific solution that extends
 * our genericized fb_user_share module for use with webform_entity type views.
 *
 * Ultimately we want a query like:
 * @code
 *   db_query("SELECT sid FROM {webform_submissions} ws
 *     JOIN {fb_user_shares} fs ON fs.entity_id = ws.sid
 *       AND fs.entity_type = 'webform_submission_entity'
 *     JOIN fboauth_users fo ON fo.fbid = fs.fb_user_id
 *     WHERE fo.uid = :uid", array(':uid' => $user->uid));
 * @endcode
 *
 * The rest of this is accomplished by a new Views current user Facebook ID
 * argument default plugin.
 *
 * @see views_plugin_argument_default_current_user_fbid::get_argument()
 */
function dosomething_picsforpets_general_views_data() {
  $data = array();

  $data['fb_user_shares']['table']['join'] = array(
    'webform_submissions' => array(
      'left_field' => 'sid',
      'field' => 'entity_id',
    ),
  );

  return $data;
}
