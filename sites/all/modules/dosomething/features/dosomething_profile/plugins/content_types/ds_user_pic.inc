<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_profile_ds_user_pic_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Profile Pic'),
    'icon' => 'icon_user.png',
    'description' => t('User pic for profile'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User Pic' content type.
 */
function dosomething_profile_ds_user_pic_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = $context->data;
  $block = new stdClass();
  $block->content = dosomething_profile_ds_user_pic_content($account);  
  return $block;
}

/**
 * Return user profile pic.
 */
function dosomething_profile_ds_user_pic_content($account) {
  return theme('user_picture', array('account' => $account));
}  
