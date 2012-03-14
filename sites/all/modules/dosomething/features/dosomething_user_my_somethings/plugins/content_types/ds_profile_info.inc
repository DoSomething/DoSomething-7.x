<?php

/**
 * Callback function to supply a list of content types.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('DS Profile info'),
  'icon' => 'icon_user.png',
  'description' => t('The profile block featured on the MySomethings page.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('User'),
  'defaults' => '',
);

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_profile_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = isset($context->data) ? clone $context->data : NULL;
  $block = new stdClass();
  if ($account) {
    $dosomething_friends = dosomething_profile_my_friends($account->uid);

    $profile = profile2_load_by_user($account->uid, 'main');
    $block->content = theme('dosomething_profile_info', array('account' => $account, 'profile' => $profile, 'dosomething_friends' => $dosomething_friends));
    $block->content .= dosomething_user_my_somethings_counter($account->uid);
  }
  else {
    $block->content = '';
  }

  return $block;
}
