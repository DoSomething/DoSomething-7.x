<?php

function _profile_resource_definition() {
  if (!module_exists('profile2')) {
    return array();
  }

  $definition = array(
    'profile' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves a user\'s profile',
          'file' => array('type' => 'inc', 'module' => 'dosomething_services', 'name' => 'resources/profile_resource'),
          'callback' => '_profile_resource_retrieve',
          'access callback' => '_profile_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'uid',
              'type' => 'int',
              'description' => 'The UID of the user to retrieve the profile for.',
              'source' => array('path' => 0),
              'optional' => FALSE,
            ),
          ),
        ),
        'update' => array(
          'help' => 'Update a user\'s profile',
          'file' => array('type' => 'inc', 'module' => 'dosomething_services', 'name' => 'resources/profile_resource'),
          'callback' => '_profile_resource_update',
          'access callback' => '_profile_resource_access',
          'access arguments' => array('update'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'uid',
              'type' => 'int',
              'description' => 'Unique identifier for this user',
              'source' => array('path' => 0),
              'optional' => FALSE,
            ),
            array(
              'name' => 'data',
              'type' => 'array',
              'description' => 'The profile object with updated information',
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        ),
      ),
    ),
  );

  return $definition;
}

/**
 * Access check callback for profile resource.
 */
function _profile_resource_access($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], array('account', 'data'));
  }

  // Check if the user exists if appropriate.
  if ($op != 'create' && $op != 'register' ) {
    $account = user_load($args[0]);
    if (!$account) {
      return services_error(t('There is no user with ID @uid.', array('@uid' => $args[0])), 406);
    }
  }

  global $user;
  if ($op == 'view') {
    return user_view_access($account);
  }
  elseif ($op == 'update') {
    return ($user->uid == $account->uid || user_access('administer users'));
  }
  else {
    return FALSE;
  }
}

/**
 * Get the profile info for a user.
 *
 * @param $uid UID of the user to get the profile info of
 *
 * @return User's profile2 object
 */
function _profile_resource_retrieve($uid) {
  $account = user_load($uid);
  if ($account) {
    $profile = profile2_load_by_user($account, 'main');
    if ($profile) {
      return $profile;
    }
  }
  
  return services_error(t('Unable to retrieve the profile for uid @uid.', array('@uid' => $uid)), 404);
}

/**
 * Update the profile of an existing user.
 *
 * @param $uid UID of the user
 * @param $updateFields Fields to modify for this user's profile
 *
 * @return The modified user profile object.
 */
function _profile_resource_update($uid, $updateFields) {
  $account = user_load($uid);
  if ($account) {
    $profile = profile2_load_by_user($account, 'main');
    if ($profile) {
      foreach ($updateFields as $key => $value) {
        // Support for fields to update are explicitly handled here
        switch ($key) {
          case 'field_user_first_name':
          case 'field_user_last_name':
          case 'field_user_mobile':
            $profile->{$key}[LANGUAGE_NONE][0]['value'] = $value;
            break;
          case 'field_user_birthday':
            $bday = new DateObject(strtotime($value));
            $bday = $bday->format(DATE_FORMAT_DATETIME);
            $profile->field_user_birthday[LANGUAGE_NONE][0]['value'] = $bday;
            break;
          case 'postal_code':
            $profile->field_user_address[LANGUAGE_NONE][0][$key] = $value;
            break;
        }
      }

      profile2_save($profile);

      return $profile;
    }
  }
  
  return services_error(t('Unable to update the profile for uid @uid.', array('@uid' => $uid)), 404);
}