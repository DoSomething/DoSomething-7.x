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

  $node = $context->data;

  //TODO: Add default club image. 
  $image = isset($node->field_club_picture[LANGUAGE_NONE][0]['uri']) ? $node->field_club_picture[LANGUAGE_NONE][0] : NULL;

  $invite_link = '';
  if (node_access('update', $node)) {
   $invite_link = t('Invite Friends') . l('Go', 'node/' . $node->nid . '/edit', array('attributes' => array('class' => 'go-button')));
  }

  $output = array(
    'containter' => array(
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
          '#image_style' => 'action_results_thumbnail',
          '#prefix' => '<div class="club-image">',
          '#suffix' => '</div>',
        ),
        'invite_link' => array(
          '#markup' => $invite_link,
          '#prefix' => '<div class="invite-link">',
          '#suffix' => '</div>',
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

  // From those members, count all their Campaign Reports Backs
  $query = db_select('webform_submissions', 'w');
  $query->innerJoin('node', 'n', 'w.nid = n.nid');
  $query->condition('n.type', 'campaign_report_back', '=');
  $query->condition('w.uid', $members, 'IN');
  $count = $query->countQuery()->execute()->fetchObject();
  $campaigns_count = $count->expression;

  $items['campaigns_completed'] = array(
    'title' => t('Campaigns Completed'),
    'value' => $campaigns_count,
  );

  // Get count of Project Reports that reference this Club.
  $query = new EntityFieldQuery();
  $projects_count = $query
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->entityCondition('bundle', 'project_report')
    ->fieldCondition('field_project_clubs', 'nid', $group->etid, '=')
    ->count()
    ->execute();

  $items['projects_uploaded'] = array(
    'title' => t('Projects Uploaded'),
    'value' => $projects_count,
  );

  $output[] = array(
    '#theme' => 'dosomething_stats_counter',
    '#items' => $items,
  );

  return theme('dosomething_stats_counter', array('items' => $items));
}
