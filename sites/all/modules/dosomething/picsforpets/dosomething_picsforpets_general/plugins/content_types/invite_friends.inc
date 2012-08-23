<?php

$plugin = array(
  'title' => t('Invite Friends'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_invite'
);


function dosomething_picsforpets_general_content_type_render_invite($subtype = '', $conf = array(), $context = NULL) {
  require_once 'sites/all/libraries/facebook-php-sdk/src/facebook.php';
  $facebook = new Facebook(array(
    //'appId'  => '459236750767188', // zivtechdev
    'appId' => '288011551281047', // picsforpets
    'secret' => '71e0c74f92f64c1bbd426bfa2a08120c',
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
