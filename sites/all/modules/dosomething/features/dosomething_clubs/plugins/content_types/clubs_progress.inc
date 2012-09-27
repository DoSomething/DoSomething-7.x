<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Clubs Pizza Party Progress Bar'),
  'description' => t('Displays a progress bar as progress towards a pizza party.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_clubs_progress_content_type_render'
);

function dosomething_clubs_progress_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object();
  $gid = og_get_group('node', $node->nid)->gid;
  $query = db_select('og_membership', 'om');
  $query->fields('om', array('etid', 'state'));
  $query->condition('om.entity_type', 'user', '=');
  $query->condition('om.gid', $gid, '=');
  $query->condition('om.state', OG_STATE_ACTIVE, '=');
  $count = $query->execute()->rowCount();
  $submission_count = $count;

  $goal = 10;
  $percent = round($submission_count / $goal * 100, 4);
  if ($percent > 100) $percent = 100;

  $done_shrink = false;
  if ($submission_count < $goal) {
    $progress_label = t('!count / !total members needed for a !pizza!', array(
      '!count' => number_format($submission_count),
      '!total' => number_format($goal),
      '!pizza' => l(t('free pizza party'), 'pizza')
    ));
  }
  else {
    $member = og_is_member($gid);
    if ($member) {
      global $user;
      if ($user->uid == $node->uid) {
        // Club leader...
        $progress_label = t('Congrats! Check your email Tuesday for !pizza redemption!', array(
          '!pizza' => l(t('pizza party'), 'pizza')
        ));
        $done_shrink = true;
      }
      else {
        // Club member...
        $progress_label = t('Ask your club leader about redeeming your free !pizza!', array(
          '!pizza' => l(t('pizza party'), 'pizza')
        ));
        $done_shrink = true;
      }
    }
    else {
      // Non-club-member
      $progress_label = t('This club earned a !pizza! Interested?', array(
        '!pizza' => l(t('free pizza'), 'pizza')
      ));
    }
  }

  $content = array(
    'progress-bar' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'progress-bar-wrapper',
        'style' => ($done_shrink ? ' width: 44%' : '')
      ),
      'progress-bar-progress' => array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'progress-bar',
          'style' => "width: $percent%",
        ),
      ),
    ),
    'label-wrapper' => array(
      '#type' => 'container',
      '#attributes' => array('id' => 'signatures-text'),
      'signatures' => array(
        '#type' => 'container',
        '#attributes' => array('id' => 'signatures-label'),
        'markup' => array(
          '#markup' => $progress_label
        ),
      ),
    ),
  );

  $block = new StdClass();
  $block->content = $content;
  return $block;
}