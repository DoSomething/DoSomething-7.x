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
  );
}

/**
 * Query and render array for club counters.
 */
function dosomething_clubs_club_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  $group = og_context();

  $query = new EntityFieldQuery();
  $member_count = $query
    ->entityCondition('entity_type', 'og_membership')
    ->propertyCondition('entity_type', 'user', '=')
    ->propertyCondition('gid', $group->gid, '=')
    ->propertyCondition('state', OG_STATE_ACTIVE, '=')
    ->count()
    ->execute();
  $query = new EntityFieldQuery();

  $projects_count = $query
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->entityCondition('bundle', 'project_report')
    ->fieldCondition('field_project_clubs', 'nid', $group->etid, '=')
    ->count()
    ->execute();

  $output = new stdClass();
  $output->content = array(
    'total-members' => array(
      'content' => array(
        '#prefix' => '<div class="club-counter-row">',
        '#suffix' => '</div>',
        'title' => array(
          '#prefix' => '<span class="club-counter-title">',
          '#suffix' => '</span>',
          '#markup' => t('Total Members'),
        ),
        'count' => array(
          '#prefix' => '<span class="club-counter">',
          '#suffix' => '</span>',
          '#markup' => $member_count,
        ),
      ),
    ),
    'projects-uploaded' => array(
      'content' => array(
        '#prefix' => '<div class="club-counter-row">',
        '#suffix' => '</div>',
        'title' => array(
          '#prefix' => '<span class="club-counter-title">',
          '#suffix' => '</span>',
          '#markup' => t('Projects Uploaded'),
        ),
        'count' => array(
          '#prefix' => '<span class="club-counter">',
          '#suffix' => '</span>',
          '#markup' => $projects_count,
        ),
      ),
    ),
  );

  return $output;
}
