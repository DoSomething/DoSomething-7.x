<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_my_somethings_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User info'),
    'icon' => 'icon_user.png',
    'description' => t('Custom testing...'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_my_somethings_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = isset($context->data) ? clone $context->data : NULL;
  $block = new stdClass();
  if ($account) {
    $profile = profile2_load_by_user($account->uid);
    if (isset($profile['main']->field_user_address['und'][0]['locality']) && $profile['main']->field_user_address['und'][0]['administrative_area']) {
      $block->content = '<div><span class="label">' . t('Hometown:') .'</span>' . $profile['main']->field_user_address['und'][0]['locality'] . ', ' . $profile['main']->field_user_address['und'][0]['administrative_area'] . '</div>';
    }  
    if ($member = dosomething_user_my_somethings_role($account)) {
      $block->content .= '<div><span class="label">' . t('Member Status:') . '</span>' . $member . '</div>';
    }
    // TODO: add school info.
    //$block->content .= '<div><span class="label">' . t('School:') .'</span>' . '' . '</div>';
    $block->content .= '<div><span class="label">' . t('Member Since:') .'</span>' . date('m/Y', $account->created) . '</div>';
  }
  else {
    $block->content = '';
  }

  return $block;
}

/**
 * Return user's member role.
 */
function dosomething_user_my_somethings_role($account = NULL) {
  $roles = $account->roles;
  $member = user_role_load_by_name('member');
  if (isset($roles[$member->rid])) {
    return t('Member');
  }
  $active_member = user_role_load_by_name('active member');
  if (isset($roles[$active_member->rid])) {
    return 'Active Member';
  }
  return t('Inactive Member');
}
