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
    $profile = profile2_load_by_user($account->uid, 'main');
    if (isset($profile->field_user_address['und'][0]['locality']) && $profile->field_user_address['und'][0]['administrative_area']) {
      $block->content = '<div><span class="label">' . t('Hometown:') .'</span>' . $profile->field_user_address['und'][0]['locality'] . ', ' . $profile->field_user_address['und'][0]['administrative_area'] . '</div>';
    }
    $role = dosomething_user_my_somethings_user_role($account);
    $block->content .= '<div><span class="label">' . t('Member Status:') . '</span>' . ucwords($role) . '</div>';

    // TODO: add school info.
    //$block->content .= '<div><span class="label">' . t('School:') .'</span>' . '' . '</div>';
    $block->content .= '<div><span class="label">' . t('Member Since:') .'</span>' . date('m/Y', $account->created) . '</div>';
  }
  else {
    $block->content = '';
  }

  return $block;
}

