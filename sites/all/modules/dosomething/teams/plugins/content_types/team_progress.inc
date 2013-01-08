<?php

/**
 * @file
 * Create a progress bar for a team based on how many challenges to date they've
 * completed. This is only really useful for The Hunt campaign.
 *
 * To use this content type, we assume one webform will be filled out by users
 * per day, so we set a start date and then type in, one per line, the NIDs
 * of the webform in order of their relevance. In other words, the first NID
 * entered will be counted towards the total on start_date, the first and second
 * will be counted on start_date+1.
 */

function teams_team_progress_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Team Progress'),
    'description' => t('Team Progress'),
    'category' => t('DoSomething'),
  );
}

function teams_team_progress_content_type_render($subtype, $conf, $panel_args, $context) {
  // Grab the challenges from the pane config array and convert to array
  $challenges = explode("\n", $conf['challenges']);

  // make some bad assumptions about the current URL
  $team_id = arg(2);
  $group = og_get_group('webform_submission_entity', $team_id);
  $uids = teams_get_member_uids($group->gid);

  // filter the submission query based on uid and nid
  module_load_include('inc', 'webform', 'includes/webform.submission');
  $filter = array(
    'nid' => $challenges,
    'uid' => $uids,
  );

  // load up the nodes and submissions based on the challenge NIDs
  $nodes = node_load_multiple($challenges);
  $submissions = webform_get_submissions($filter);

  // convert the date to a DateTime object
  $date_string = implode('/', $conf['start_date']);
  $date = DateTime::createFromFormat('n/j/Y', $date_string);
  $now = new DateTime;

  // find the difference between NOW() and the start_date on the panel config
  $diff = $date->diff($now);
  if ($diff->invert) {
    $block = new StdClass;
    $block->content = 'Challenges are starting on ' . $date_string . '.';
    return $block;
  }

  $diff = $diff->d;

  // 
  $challenges = array();
  $challenge_count = 0;
  $nodes_backup = $nodes;

  // loop through from day 1 to day NOW, storing the available challenges into
  // $challenges array.
  for ($i = 0; $i <= $diff; $i++) {
    $current = array_shift($nodes);
    $items = explode("\n", $current->webform['components'][1]['extra']['items']);
    foreach ($items as $item) {
      $item = explode('|', $item);
      $challenges[$current->nid][$item[0]] = $item[1];
      $challenge_count++;
    }
  }
  $nodes = $nodes_backup;

  // count up the completed challenges from the users.
  $challenges_for_count = $challenges;
  foreach ($submissions as $sub) {
    foreach ($sub->data[1]['value'] as $val) {
      $completed[$sub->nid][] = array(
        'uid' => $sub->uid,
        'challenge' => $val,
      );
      unset($challenges_for_count[$sub->nid][$val]);
    }
  }

  // store an array of challenges that are complete in pretty text format.
  $doneit = array();
  foreach ($completed as $nid => $done) {
    foreach ($done as $text) {
      $name = dosomething_general_get_full_name($text['uid']);
      if ($name == ' ') $name = '{name unavailable}';

      $doneit[] = $name . ' did: ' . teams_team_progress_val($nodes[$nid], 1, $text['challenge']);
    }
  }
  if (empty($doneit)) {
    $doneit[] = 'No challenges completed yet!';
  }

  // do some maths to figure out how many challenges aren't completed (we don't use this for now,
  // but down the road we could use it to show what they still have to complete.)
  $remaining = 0;
  $incomplete = array();
  foreach ($challenges_for_count as $nid => $c) {
    $remaining += count($c);
    if (count($c) > 0) {
      $incomplete[] = $nodes[$nid]->title;
    }
  }

  // yay math.
  $percent_done = round(($challenge_count - $remaining) / $challenge_count * 100);

  $content = array(
    'progress-bar' => array(
      '#type' => 'container',
      '#prefix' => '<div class="progress-bar-wrapper"><h3>PROGRESS</h3>',
      '#suffix' => '<p>' . $percent_done . '% of available challenges completed</p></div>',
      '#attributes' => array(
        'class' => 'progress-bar',
        'style' => 'width:100%',
      ),
      'progress-bar-progress' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => 'progress-bar-progress',
          'style' => "width:$percent_done%;height:100%",
        ),
      ),
    ),
    'activity' => array(
      '#theme' => 'item_list',
      '#items' => $doneit,
      '#prefix' => '<div class="activity-feed-wrapper"><h3>ACTIVITY FEED</h3>',
      '#suffix' => '</div>',
    ),
  );
  $block = new StdClass;
  $block->content = $content;

  return $block;
}

function teams_team_progress_val($node, $cid, $val) {
  $values = explode("\n", $node->webform['components'][$cid]['extra']['items']);
  $mapped = array();
  foreach ($values as $value) {
    $temp = explode('|', $value);
    $mapped[$temp[0]] = $temp[1];
  }
  return $mapped[$val];
}

function teams_team_progress_content_type_admin_title($subtype, $conf, $context) {
  return t('Team Progress');
}

function teams_team_progress_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['challenges'] = array(
    '#type' => 'textarea',
    '#title' => t('Challenge NIDs'),
    '#description' => t('NIDs for the challenges. One per line, in order from Day 1 to Day n.'),
    '#default_value' => $conf['challenges'],
  );
  $form['start_date'] = array(
    '#type' => 'date',
    '#title' => t('Challenges start date'),
    '#description' => t('Start date for the challenges.'),
    '#default_value' => $conf['start_date'],
  );

  return $form;
}

function teams_team_progress_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('challenges', 'start_date') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}


