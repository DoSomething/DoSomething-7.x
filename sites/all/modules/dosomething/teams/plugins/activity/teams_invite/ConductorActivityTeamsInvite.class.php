<?php

class ConductorActivityTeamsInvite extends ConductorActivitySMSPrompt {

  public function run($workflow) {
    $state = $this->getState();

    $mobile = $state->getContext('sms_number');

    if ($mobile[0] == '1') $mobile = substr($mobile, 1);

    // use that to call teams_add_member($contact, $gid)

    $account = dosomething_general_find_user_by_cell($mobile);
    $groups = array();
    foreach ($account->group_audience[LANGUAGE_NONE] as $group) {
      $groups[] = $group['gid'];
    }
    $groups = og_load_multiple($groups);

    foreach ($groups as &$group) {
      if ($group->entity_type != 'webform_submission_entity') {
        unset($group);
      }
    }

    if (empty($groups)) {
      $state->setContext('sms_response', t('We had trouble finding a team to add people to. Head over to dosomething.org/hunt and try adding members there.'));
    }
    else {
      $group = end($groups);
      $contact = $state->getContext('get_info:message');
      teams_add_member($contact, $group->gid);
      $state->setContext('sms_response', t('Cool! We invited them to your group.'));
    }

    $state->markCompleted();
  }
}
