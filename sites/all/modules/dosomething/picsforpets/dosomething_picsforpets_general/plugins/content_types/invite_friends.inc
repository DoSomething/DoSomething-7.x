<?php

$plugin = array(
  'title' => t('Invite Friends'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_invite'
);


function dosomething_picsforpets_general_content_type_render_invite($subtype = '', $conf = array(), $context = NULL) {
  // Render array for Invite Friends button.
  $block = new stdClass();
  $block->content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'invite-friends',
    ),
    '#children' => t('Invite Friends'),
    '#attached' => array(
      'js' => array(
        array('data' => array('fb_access_token' => 'access_token'), 'type' => 'setting'),
        ctools_attach_js('invite_friends', 'dosomething_picsforpets_general'),
      ),
    ),
  );
  return $block;
}
