<?php

$plugin = array(
  'title' => t('Invite Friends'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_invite'
);


function dosomething_picsforpets_general_content_type_render_invite($subtype = '', $conf = array(), $context = NULL) {
  $path = libraries_get_path('facebook');
  if (!empty($path)) {
    require_once(DRUPAL_ROOT . '/' . $path . '/facebook.php');
  }
  else {
    drupal_set_message('You are missing the Facebook SDK');
    return;
  }

  $facebook = new Facebook(array(
    'appId' => variable_get('dosomething_picsforpets_fb_user_app_id', ''),
    'secret' => variable_get('dosomething_picsforpets_fb_user_app_secret', ''),
  ));
  $user = $facebook->getUser();
  if ($user) {
    try {
      $user_profile = $facebook->api('/me');
    } catch (FacebookApiException $e) {
      error_log($e);
      $user = null;
    }
  }

  // Render array for Invite Friends button.
  $output = '<div id="picsforpets-invite-friends-image"></div>';
  $output .= '<div id="picsforpets-invite-friends-text">' . t('Invite Friends') . '</div>';

  $block = new stdClass();
  $block->content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'picsforpets-invite-friends',
    ),
    '#children' => $output,
    '#attached' => array(
      'js' => array(
        array('data' => array('fb_access_token' => $facebook->getAccessToken()), 'type' => 'setting'),
        ctools_attach_js('invite_friends', 'dosomething_picsforpets_general'),
      ),
    ),
  );
  return $block;
}
