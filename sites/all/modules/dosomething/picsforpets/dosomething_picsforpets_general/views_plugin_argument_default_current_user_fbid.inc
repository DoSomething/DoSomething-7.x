<?php

/**
 * @file
 * Contains the current user Facebook ID argument default plugin.
 */

/**
 * Default argument plugin to extract a Facebook ID from the global $user.
 *
 * @todo consider adding this as a patch to fboauth module.
 */
class views_plugin_argument_default_current_user_fbid extends views_plugin_argument_default_current_user {
  function get_argument() {
    $uid = parent::get_argument();
    return fboauth_fbid_load($uid);
  }
}
