<?php

function dosomething_drives_drive_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Drive Module'),
    'description' => t('Drive information module.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_drives_drive_content_type_render($subtype, $conf, $panel_args, $context) {
  $sid = arg(2);
  $submission = reset(entity_load('webform_submission_entity', array($sid)));
  $campaign_group = og_load(reset(entity_load('node', array($submission->nid)))->group_audience[LANGUAGE_NONE][0]['gid']);
  $campaign = reset(entity_load('node', array($campaign_group->etid)));
  $group = og_get_group('webform_submission_entity', $sid);
  $leader_name = dosomething_drives_drive_get_name($submission);
  $drive = dosomething_drives_drive_get_drives($group->gid);
  $drive_nid = dosomething_drives_get_drive_nid($campaign_group);
  $is_admin = (og_user_access($group->gid, 'administer group') || user_access('administer group')) && !$conf['disable_admin_functions'];

  drupal_add_js(array('dosomething_drives' => array('gid' => $group->gid)), 'setting');

  $content = array();
  $content['header'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="drive-info-wrapper">',
    '#attributes' => array(
      'class' => array('drive-info-header'),
    ),
  );

  // get the drive associated with this sign up form

  // get the member list (use a function!)

  $content['header']['title'] = dosomething_drives_drive_title($submission, $conf['team_name'], $leader_name, $campaign->title);
  $content['header']['description'] = dosomething_drives_drive_description($submission);
  $content['header']['countdown'] = dosomething_drives_drive_countdown($drive);

  $content['content']['drive_info'] = dosomething_drives_drive_info($drive, $drive_nid, $group->gid, $is_admin);
  $content['content']['drive_share'] = dosomething_drives_drive_share();
  $content['content']['participants'] = dosomething_drives_drive_participants($group, $leader_name, $campaign, $is_admin);

  $content['#attached']['js'] = array(
    drupal_get_path('module', 'teams') . '/teams.js' => array(),
  );

  $block = new StdClass();
  $block->content = $content;
  return $block;
}

function dosomething_drives_drive_content_type_admin_title($subtype, $conf, $context) {
  return t('Drive Module');
}

function dosomething_drives_drive_info($drive, $drive_nid, $gid, $is_admin) {
  // if there is no drive for this team
  $return = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-info'),
    ),
  );

  if (is_null($drive)) {
    if ($is_admin) {
      $return['submit'] = array(
        '#markup' => l('submit drive information', "node/$drive_nid", array('query' => array('destination' => request_path(), 'gid' => $gid))),
      );
    }
    else {
      $return['text'] = array(
        '#markup' => 'Awaiting confirmation from the drive leader.',
      );
    }
  }
  // yay, there's a drive! show it!
  else {
    $return += dosomething_drives_drive_get_info($drive, $is_admin);
  }
  return $return;
}

function dosomething_drives_drive_get_info($drive, $is_admin) {
  $print = array('name_line', 'thoroughfare', 'premise', 'locality', 'administrative_area');
  $real = array('Location', 'Address', 'Address 2', 'City', 'State');
  $wherea = $drive->field_drive_location[LANGUAGE_NONE][0];
  $where_out = array();
  foreach ($print as $key => $field) {
    if (!empty($wherea[$field])) {
      $where_out["{$real[$key]}"] = $wherea[$field];
    }
  }

  $where = '';
  foreach ($where_out AS $label => $info) {
    $where .= '<div>' . $label . ': <span>' . $info . '</span></div>';
  }

  $when = strtotime($drive->field_drive_date[LANGUAGE_NONE][0]['value']);
  $when = date('m/d/Y g:iA', $when);
  $gid = $drive->group_audience[LANGUAGE_NONE][0]['gid'];
  // TODO: do stuff with $when to make it pretty

  $return = array(
    'header' => array(
      '#markup' => '<h3>Logistics</h3>',
    ),
    'details' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('drive-info-info-details'),
      ),
      'where' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('drive-info-where'),
        ),
        'div' => array(
          '#markup' => "$where",
        ),
      ),
     'when' => array(
     '#type' => 'container',
     '#attributes' => array(
        'class' => array('drive-info-when'),
       ),
     'div' => array(
         '#markup' => "When: <span>$when</span>",
       ),
   ),

    ),
  );
  if ($is_admin) {
    $return['edit-link'] = array(
      '#markup' => l('edit drive info', "node/{$drive->nid}/submission/{$drive->sid}/edit", array('query' => array('destination' => request_path(), 'gid' => $gid))),
    );
  }
  return $return;
}

function dosomething_drives_drive_share() {
  drupal_add_js(drupal_get_path('module', 'dosomething_drives') . '/js/twitter.js');
#  $url = url(request_path(), array('absolute' => TRUE));
  return array(
    '#type' => 'container',
    '#suffix' => '</div> <!-- .drive-info-wrapper -->',
    '#attributes' => array(
      'class' => array('drive-share'),
    ),
    'div' => array(
      '#markup' => '<h3>Share this drive</h3><a href="#" class="drive-facebook fb-share-drive">Share on Facebook</a>
      <a href="https://twitter.com/share?url=' . $url . '&hashtags=GiveASpit&text=Give a spit about cancer! Get your cheek swabbed and you could save a life; it\'s that simple." class="drive-twitter" target="_blank">Share on Twitter</a>',
    ),
  );
}

function dosomething_drives_drive_participants($group, $leader_name, $campaign, $is_admin) {
  global $user;
  $members = teams_get_member_uids($group->gid);
  $members = entity_load('user', $members);

  $members = dosomething_drives_drive_create_participant_list($group->gid, $members, $is_admin);

  // check if the current user is the creator of the club.
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-participants'),
    ),
    'title' => array(
      '#markup' => 'Participants',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    ),
    'list' => array(
      '#theme' => 'item_list',
      '#items' => $members,
      '#attributes' => array('class' => array('drive-participants-list')),
    ),
    'action_link' => dosomething_drives_drive_action_link($group->gid, $leader_name, $campaign),
  );
}

function dosomething_drives_drive_create_participant_list($gid, $members, $admin) {
  global $user;
  $return = array();
  foreach ($members as $member) {
    $name = array();
    $name['name'] = teams_full_name($member->uid);
    if ($admin && $user->uid != $member->uid) {
      $name['form'] = drupal_render(drupal_get_form('teams_remove_member_form', $gid, $member->uid));
    }
    $return[] = array(
      'data' => implode(' ', $name),
      'id' => 'team-member-' . $member->uid,
    );
  }
  return $return;
}

function dosomething_drives_drive_countdown($drive) {
  if (!is_null($drive)) {
    $countdown = strtotime($drive->field_drive_date[LANGUAGE_NONE][0]['value']) - time();
    if ($countdown <= 0) {
      $countdown = 'This drive already happened.';
    }
    else {
      $countdown = format_interval($countdown, 2);
    }

    return array(
      '#type' => 'container',
      '#attributes' => array('class' => array('drive-info-countdown')),
      'div' => array(
        '#markup' => "<h2>Countdown:</h2> <span>$countdown</span>",
      ),
    );
  }
}

function dosomething_drives_drive_title($drive, $type, $leader, $campaign) {
  switch($type) {
    case 'field_webform_school_reference':
      $entity = reset(entity_load('ds_school', array($drive->field_webform_school_reference[LANGUAGE_NONE][0]['target_id'])));
      $title = $entity->name;
      $tagline = "{$entity->street}, {$entity->city}, {$entity->state} {$entity->zip}";
      break;
    default:
      $title = $drive->field_team_name[LANGUAGE_NONE][0]['value'];
      break;
  }

  $subtitle = $campaign . ' Drive';

  $return = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('drive-info-title')),
    'wrapper' => array(
      'title' => array(
        '#markup' => $title,
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'subtitle' => array(
        '#markup' => $subtitle,
        '#prefix' => '<h3>',
        '#suffix' => '</h3>'
      ),
    ),
  );
  if (isset($tagline)) {
    $return['wrapper']['tagline'] = array(
      '#markup' => $tagline,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }
  return $return;
}

function dosomething_drives_drive_description($drive) {
  $cid = dosomething_drives_get_drive_cid(node_load($drive->nid));
  $goal = $drive->data[$cid]['value'][0];
  return array(
    '#type' => 'container',
    '#attributes' => array('class' => array('drive-info-description')),
    'div' => array(
      '#markup' => "<h2>Goal:</h2> <span>$goal</span>",
    ),
  );
}

function dosomething_drives_drive_action_link($gid, $leader, $campaign) {
  $join_url = "drive/join/$gid";

  $return = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-action-link'),
    ),
  );

  if (og_is_member($gid)) {
    $options = array(
      'fragment' => ' ',
      'external' => TRUE,
      'attributes' => array(
        'class' => array('go-button trigger-invite-popup'),
      ),
    );
    $return['test'] = array(
      '#markup' => l(t('Invite more friends'), '', $options),
    );
    $return['popup'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('invite-module')),
      'content' => dosomething_drives_drive_invite_module($gid),
    );
  }
  else {
    $add = array();
    if (user_is_logged_in()) {
    }
    else {
      drupal_add_library('dosomething_login', 'ds.ajax.popup');
      $add['onclick'] = "jQuery(body).dsAjaxPopup('$join_url', false, null, null); return false;";
    }

    $return['button'] = array(
      '#markup' => l("Join $leader's Drive", $join_url, array('attributes' => array('class' => array('go-button'))+$add)),
    );
    $return['start_drive'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('drive-action-link-text')),
      'text' => array(
        '#markup' => 'or ' . l('Start', 'node/'.$campaign->nid) . ' your own drive',
      ),
    );
  }
  return $return;
}

function dosomething_drives_drive_invite_module($gid) {
  global $user;
  $fb_connected = fboauth_fbid_load($user->uid);

  drupal_add_js(array('campaignPath' => arg(1)), 'setting');
  drupal_add_js(drupal_get_path('module', 'dosomething_drives') . '/js/popup-form.js');

  $return = array();
  $return['header'] = array(
    '#markup' => 'Invite friends through:',
    '#prefix' => '<h2>',
    '#suffix' => '</h2><div id="teams-notification-area"></div>',
  );

  $return['facebook'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('invite-module-facebook')),
  );

  if ($fb_connected) {
    drupal_add_library('dosomething_general', 'fb-friend-finder');
    $return['facebook']['button'] = array(
      '#type' => 'button',
      '#value' => 'Invite Facebook friends',
      '#attributes' => array(
        'class' => array('fb-friend-finder-init', 'go-button'),
      ),
    );
  }
  else {
    $fb_link = fboauth_action_link_properties('connect', current_path());
    $fb_url = url($fb_link['href'], array('query' => $fb_link['query']));

    $return['facebook']['description'] = array(
      '#markup' => 'Facebook',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    );
    $return['facebook']['button'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('connect-with-facebook')),
      '#children' => l('Connect thru Facebook', $fb_url),
    );
  }

  $return['or'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('invite-module-or')),
    'content' => array(
      '#markup' => 'or',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    ),
  );

  // TODO: this also feels hacky. Different invite form being used if it's for TFJ
  if (stripos(current_path(), 'jeans') !== FALSE) {
    $return['phone'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('invite-module-email')),
    );

    $return['phone']['description'] = array(
      '#markup' => 'Cell Phone',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    );

    $return['phone']['form'] = drupal_get_form('sms_flow_team_invite_form', $gid);
  }
  else {
    $return['email'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('invite-module-email')),
    );

    $return['email']['description'] = array(
      '#markup' => 'email',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    );
    $return['email']['form'] = drupal_get_form('teams_add_member_form', $gid);
  }

  return $return;
}

function dosomething_drives_drive_get_name($submission) {
  $name = teams_full_name($submission->uid);
  return $name;
}

function dosomething_drives_drive_get_drives($gid) {
  $q = new EntityFieldQuery();
  $result = $q
    ->entityCondition('entity_type', 'og_membership')
    ->propertyCondition('gid', $gid)
    ->propertyCondition('entity_type', 'webform_submission_entity')
    ->execute();

  $memberships = entity_load('og_membership', array_keys($result['og_membership']));
  foreach ($memberships as $membership) {
    $load[] = $membership->etid;
  }
  $subs = entity_load('webform_submission_entity', $load);

  $return = NULL;
  foreach ($subs as $sub) {
    if ($sub->bundle == 'drive_form') {
      $return = $sub;
    }
  }
  return $return;
}

function dosomething_drives_drive_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['team_name'] = array(
    '#type' => 'select',
    '#title' => 'Field for team name',
    '#options' => array(
      'field_team_name' => t('Team name'),
      'field_webform_school_reference' => t('School name'),
    ),
    '#default_value' => $conf['team_name'],
  );

  $form['disable_admin_functions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable team member removal by leader.'),
    '#default_value' => $conf['disable_admin_functions'],
  );
  return $form;
}

function dosomething_drives_drive_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('disable_admin_functions', 'team_name') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
