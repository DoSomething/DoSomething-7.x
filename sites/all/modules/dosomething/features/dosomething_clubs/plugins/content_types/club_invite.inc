<?php

function dosomething_clubs_club_invite_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club Invite'),
    'description' => t('Club invite or join module'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
}

function dosomething_clubs_club_invite_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $block = new stdClass();

  $gid = og_get_group('node', $context->data->nid)->gid;
  $membership = og_get_group_membership($gid, 'user', $user->uid);

  if (isset($membership->state) && $membership->state == OG_STATE_ACTIVE) {
    $form = drupal_get_form('dosomething_clubs_invite_form', $gid);
    $block->content = $form;
  }
  else if (isset($membership->state) && $membership->state == OG_STATE_PENDING) {
    $block->content = 'Your membership is pending.';
  }
  else {
    if (user_is_logged_in()) {
      $block->content = drupal_get_form('dosomething_clubs_join_form', $gid);
    }
    else {
      echo ":)";
      $block->content = drupal_get_form('dosomething_clubs_join_form', $gid);
      // 1. pop up login/register box with ?destination set
      // 2. destination is a new page, with destination URL encoded
      // 3. redirect back to the club page
    }
  }
  return $block;
}
