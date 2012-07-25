<?php

$plugin = array(
  'title' => t('Invite Friends'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_invite'
);

function dosomething_picsforpets_general_content_type_render_invite($subtype, $conf, $context = NULL) {
  // Extract the user's access_token from the global PHP variables.
  //$fb_app_id = $GLOBALS['_fb_app']->id;
  //$access_token = $_SESSION['fb_' . $fb_app_id . '_access_token'];
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
