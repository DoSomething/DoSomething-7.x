<?php

/**
 * Callback function for club counter.
 */
function dosomething_clubs_club_counter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club Counter'),
    'description' => t('Club related statistics'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
}

/**
 * Query and render array for club counters.
 */
function dosomething_clubs_club_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  global $user;

  $node = $context->data;
  $group = og_context();

  drupal_add_library('system', 'drupal.ajax');
  drupal_add_js(drupal_get_path('module', 'dosomething_clubs') . '/js/club-ajax.js');

  if (isset($node->field_club_picture[LANGUAGE_NONE][0]['uri'])) {
    $image = $node->field_club_picture[LANGUAGE_NONE][0];
    $image_style = 'action_results_thumbnail';
  }
  else {
    $image = array(
      'uri' => 'sites/all/modules/dosomething/features/dosomething_clubs/club-nopic-01.png',
      'title' => 'DoSomething Club',
      'alt' => 'DoSomething Clubs Default image',
    );
    $image_style = NULL;
  }

  $see_all = '';
  $member_link = '';
  // Anonymous user.
  $membership = og_get_group_membership($group->gid, 'user', $user->uid);

  global $show_invite_link;
  $show_invite_link = false;
  if (isset($membership->state) && $membership->state == OG_STATE_ACTIVE && isset($group->gid)) {
    $member_link = '';
    $show_invite_link = true;
  }
  else if (isset($membership->state) && $membership->state == OG_STATE_PENDING) {
    $member_link = 'Your membership is pending.';

    $nag = db_select('dosomething_clubs_nag', 'n')
      ->fields('n', array('uid'))
      ->condition('timestamp', array(strtotime('24 hours ago'), REQUEST_TIME), 'BETWEEN')
      ->condition('clubid', $node->nid, '=')
      ->condition('uid', $user->uid)
      ->range(0, 1)
      ->execute();
    if (!$nag->rowCount()) {
      $member_link .= '<div>' . l(t('Remind the club leader'), 'clubs/remind-approve/' . $user->uid . '/' . $node->nid) . '</div>';
    }
  }
  else {
    if (isset($group->gid)) {
      $f = drupal_get_form('dosomething_clubs_join_form', $group->gid);
      $member_link = drupal_render($f);
    }
  }

  $location = '';
  $school_name = '';
  if (!empty($node->field_school_reference )) {
    $school = entity_load('ds_school', array($node->field_school_reference[LANGUAGE_NONE][0]['target_id']));
    $school = array_shift($school);
    $school_name = $school->name;
    $location = $school->city . ', ' . $school->state;
  }
  else {
    $school_name = $node->title;
    $location = $node->field_club_city[LANGUAGE_NONE][0]['value'] . ', ' . $node->field_club_state[LANGUAGE_NONE][0]['value'];
  }

  $link = 'http://www.facebook.com/sharer/sharer.php?u=http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];

  $edit_photo_perm = '';
  $edit_link = array();
  if ($user->uid == $node->uid || user_access('administer group', $user) || in_array(DSCLUBS_ADMIN_ROLE, og_get_user_roles($group->gid, $user->uid))) {
    $edit_photo_perm = ' admin-manage';

    $edit_link = array(
      '#markup' => l(t('Edit'), 'node/add/club', array(
        'attributes' => array(
          'id' => 'club-edit-logo',
          'class' => $node->nid
        )
      )),
      '#prefix' => '<div class="edit-logo">',
      '#suffix' => '</div>'
    );
  }

  if (dosomething_clubs_is_club_admin($group->gid)) {
    $blurb = '<div class="blurb-wrapper">';
    $blurb .= '<span class="edit"><a href="/node/' . $node->nid . '/edit">EDIT</a></span>';
    $blurb .= '<div class="blurb-text">';
    $text = $t = '';
    if (isset($node->field_club_blurb[LANGUAGE_NONE][0]['value'])) {
      $t = $node->field_club_blurb[LANGUAGE_NONE][0]['value'];
      $text = $t;
    }
    else {
      $t = '<span class="blurb-placeholder">' . t('Insert your club\'s status update here...') . '</span>';
    }

    $blurb .= '<textarea name="blurb" maxlength="140" placeholder="Insert your club\'s status update here...">' . $text . '</textarea>';
    $blurb .= '<span class="blurb-placeholder">' . $t . '</span>';

    $blurb .= '<div style="clear: both"></div></div></div>';
  }
  else {
    $blurb = (isset($node->field_club_blurb[LANGUAGE_NONE][0]['value']) ? $node->field_club_blurb[LANGUAGE_NONE][0]['value'] : '');
  }

  $output = array(
    'container' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-stats',
        ),
      ),
      'left' => array(
        'image' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('club-image' . $edit_photo_perm)
          ),
          'edit' => $edit_link,
          'logo' => array(
            '#theme' => 'image_formatter',
            '#item' => $image,
            '#image_style' => $image_style,
          ),
        ),
        'container' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'dosomething-club-facts'
            ),
          ),
          'school_name' => array(
            '#markup' => $school_name,
            '#prefix' => '<div class="school-name">',
            '#suffix' => '</div>',
          ),
          'location' => array(
            '#markup' => $location,
            '#prefix' => '<div class="school-location">',
            '#suffix' => '</div>',
          ),
          'blurb' => array(
            '#markup' => $blurb,
            '#prefix' => '<p class="club-blurb">',
            '#suffix' => '</p>'
          ),
          'member_link' => array(
            '#markup' => $member_link,
            '#prefix' => '<div class="invite-link">',
            '#suffix' => '</div>',
          ),
          /*'share_on_facebook' => array(
            '#markup' => t('Share on Facebook'),
            '#prefix' => '<a href="' . $link . '" id="clubs-share-on-facebook">',
            '#suffix' => '</a>',
          ),*/
          'see_all' => array(
            '#markup' => $see_all,
            '#prefix' => '<div class="see-all-members">',
            '#suffix' => '</div>',
          ),
        ),
      ),
      'right' => array(
        '#markup' => dosomething_clubs_club_counter_right(),
      ),
    ),
  );

  $block->content = $output;
  return $block;
}

/**
 * Return themed right side counter content.
 */
function dosomething_clubs_club_counter_right() {
  $group = og_context();
  $n = menu_get_object();
  $items = array();

  // Get all users for the group.
  $query = db_select('og_membership', 'om');
  $query->fields('om', array('etid', 'state'));
  $query->condition('om.entity_type', 'user', '=');
  $query->condition('om.gid', $group->gid, '=');
  #$query->condition('om.state', OG_STATE_ACTIVE, '=');
  $results = $query->execute();
  $members = array();
  $pending = 0;
  while ($result = $results->fetchObject()) {
    if ($result->state == 1) {
      $members[] = $result->etid;
    }
    else {
      $pending++;
    }
  }

  $member_count = count($members);

  $items['total_members'] = array(
    'title' => l(t('Total Members'), '#', array('attributes' => array('class' => array('member-popup-trigger')))),
    'value' => $member_count,
  );

  $counts = array(
    'project_report' => 0,
    'campaign_report_back' => 0,
  );
  if (!empty($members)) {
    foreach ($counts as $node_type => $count) {
      // From those members, count all their Campaign Reports Backs
      $query = db_select('webform_submissions', 'w');
      $query->innerJoin('node', 'n', 'w.nid = n.nid');
      $result = $query->condition('n.type', $node_type, '=')
        ->condition('w.uid', $members, 'IN')
        ->countQuery()
        ->execute()
        ->fetchObject();
      $counts[$node_type] = $result->expression;
    }
  }

  $items['actions_taken'] = array(
    'title' => t('Actions Taken'),
    'value' => ($counts['campaign_report_back'] + $counts['project_report'])
  );

  $output[] = array(
    '#theme' => 'dosomething_stats_counter',
    '#items' => $items,
  );

  $mnt = new EntityFieldQuery();
  $memberships_no_titles = $mnt
    ->entityCondition('entity_type', 'og_membership')
    ->propertyCondition('gid', $group->gid)
    ->propertyCondition('entity_type', 'user')
    ->execute();

  $w = $s = '';
  global $user;
  if ($pending && (og_is_member($group->gid) || user_access('administer group', $user) || in_array(DSCLUBS_ADMIN_ROLE, og_get_user_roles($group->gid, $user->uid)))) {
    $w = ' style="width: 110px; float: left;"';
    $s = '<span style="float: right; background: #E01B6A; color: white; padding: 3px; position: relative; top: -5px; border-radius: 5px;" title="' . t('This club has ' . $pending . ' member(s) pending approval.') . '">' . $pending . '</span>';
  }

  $nid = (isset($n->nid) ? $n->nid : 0);
  $gid = (isset($group->gid) ? $group->gid : 0);

  global $show_invite_link;
  $output[] = array(
      '#markup' => '<div class="button-container">' . ($show_invite_link ? l(t('Invite friends'), 'clubs/share/' . $nid, array('attributes' => array('class' => array('go-button')))) : '') . l('<div' . $w . '>' . t('View Members') . '</div>' . $s, 'club/' . $gid . '/members', array('attributes' => array('class' => array('go-button', 'member-popup-trigger')), 'html' => TRUE)) . '</div>',
  );

  return drupal_render($output);
}
