<?php

/**
 * Checks whether we have the user's school_id. If we do, then it skips this
 * step. Otherwise, prompts user to enter state and school name and waits
 * for the response.
 */
class ConductorActivityTeamsCheckUser extends ConductorActivitySMSPrompt {

  public function run($workflow) {
    $state = $this->getState();

    $mobile = $state->getContext('sms_number');

    if ($mobile[0] == '1') $mobile = substr($mobile, 1);

    // If we have a user with this mobile, lets update their info.
    $account = sms_flow_get_or_create_user_by_cell($mobile);
    if ($account) {
      $profile = profile2_load_by_user($account, 'main');
    }

    // Because $profile could be an object, make sure to cast to array first
    $profile = (array)$profile;
    if (!empty($profile['main']->field_user_first_name[LANGUAGE_NONE][0]['value'])) {
      $state->setContext($this->name . ':has_name', 'true');
    }

    $state->markCompleted();
  }
}
