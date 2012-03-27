<?php

/**
 * Callback function for third column on club panel.
 */
function dosomething_clubs_club_third_column_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club 3rd Column: Member/Non Member'),
    'description' => t('Shows club members or editor picks depending on user membership'),
    'category' => t('DoSomething'),
  );
}

/**
 * Return content for Club 3rd Column for members and non-members.
 */
function dosomething_clubs_club_third_column_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $block = new stdClass();

  $group = og_context();
  $membership = og_get_group_membership($group->gid, 'user', $user->uid);
  if ($membership) {
    $view = views_get_view('profile');
    $output = $view->preview('panel_pane_1');
    $block->title = t('Editors Picks For You');
  }
  else {
    // TODO:
    $output = '';
  }

  $block->content = $output;
  return $block;
}
