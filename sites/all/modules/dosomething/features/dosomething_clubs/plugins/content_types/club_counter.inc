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
  if ($user->uid == 0) {
    $member_link = t('Join the club') . l('Go', 'user/registration', array('query' => array('destination' => 'group/node/' . $node->nid . '/subscribe'), 'attributes' => array('class' => 'go-button')));
  }
  // Logged in non-member.
  elseif (!$membership) {
    $member_link = t('Join the club') . l('Go', 'group/node/' . $node->nid . '/subscribe', array('attributes' => array('class' => 'go-button')));
  }
  else {
    // Pending member.
    if ($membership->state == 2) {
      $member_link = t('Membership Pending');
    }
    // Approved member with edit access.
    elseif ($membership->state == 1 && node_access('update', $node)) {
      $member_link = t('Invite Friends') . l('Go', 'node/' . $node->nid . '/edit', array('attributes' => array('class' => 'go-button')));
      $see_all = l('or see all', 'club/' . $group->gid . '/members');
    }
    // Approved member.
    elseif ($membership->state == 1) {
      $member_link = t('Member');
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
          '#theme' => 'image_formatter',
          '#item' => $image,
          '#image_style' => $image_style,
          '#prefix' => '<div class="club-image">',
          '#suffix' => '</div>',
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
        'member_link' => array(
          '#markup' => $member_link,
          '#prefix' => '<div class="invite-link">',
          '#suffix' => '</div>',
        ),
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
  $items = array();

  // Get all users for the group.
  $query = db_select('og_membership', 'om');
  $query->addField('om', 'etid');
  $query->condition('om.entity_type', 'user', '=');
  $query->condition('om.gid', $group->gid, '=');
  $query->condition('om.state', OG_STATE_ACTIVE, '=');
  $results = $query->execute();
  $members = array();
  while ($result = $results->fetchObject()) {
    $members[] = $result->etid;
  }
  $member_count = count($members);

  $items['total_members'] = array(
    'title' => t('Total Members'),
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
        ->condition('w.uid', $members, 'IN');
        ->countQuery()
        ->execute()
        ->fetchObject();
      $counts[$node_type] = $result->expression;
    }
  }

  $items['campaigns_completed'] = array(
    'title' => t('Campaigns Completed'),
    'value' => $counts['campaign_report_back'],
  );
  $items['projects_uploaded'] = array(
    'title' => t('Projects Uploaded'),
    'value' => $counts['project_report'],
  );

  $output[] = array(
    '#theme' => 'dosomething_stats_counter',
    '#items' => $items,
  );

  return theme('dosomething_stats_counter', array('items' => $items));
}
