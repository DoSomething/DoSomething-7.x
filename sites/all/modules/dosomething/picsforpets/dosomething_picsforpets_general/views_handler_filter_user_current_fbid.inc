<?php

/**
 * Filter handler for the current user Facebook ID.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_user_current_fbid extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t("Is the logged in user's Facebook account");
  }

  function query() {
    $this->ensure_my_table();

    $field = $this->table_alias . '.' . $this->real_field . ' ';
    $or = db_or();

    // Do we already have the global user somewhere?
    global $user;
    $fbid = fboauth_fbid_load($user->uid);

    if (empty($this->value)) {
      $or->condition($field, $fbid, '<>');
      if ($this->accept_null) {
        $or->isNull($field);
      }
    }
    else {
      $or->condition($field, $fbid, '=');
    }
    $this->query->add_where($this->options['group'], $or);
  }
}
