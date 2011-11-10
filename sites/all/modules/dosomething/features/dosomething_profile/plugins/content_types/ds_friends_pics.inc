<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_profile_ds_friends_pics_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Friends Pics'),
    'icon' => 'icon_user.png',
    'description' => t('Friends pics for profile'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User Freinds Pics' content type.
 */
function dosomething_profile_ds_friends_pics_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $block->content = dosomething_profile_ds_friends_pics_content($uid);  
  return $block;
}

/**
 * Return friends profile pics.
 */
function dosomething_profile_ds_friends_pics_content($uid) {
  $results = db_select('facebook_friends')
    ->fields('facebook_friends', array('fbid'))
    ->execute();
  while ($result = $results->fetchObject()) {
    $uid = db_query('SELECT uid from {fboauth_users} WHERE fbid = :fbid', array(':fbid' => $result->fbid))->fetchField();
    $img[] = theme('dosomething_general_facebook_friend_pic', array('fbid' => $result->fbid, 'uid' =>$uid, 'image_style' => NULL));
  }
  return theme('item_list', array('items' => $img));
}  
