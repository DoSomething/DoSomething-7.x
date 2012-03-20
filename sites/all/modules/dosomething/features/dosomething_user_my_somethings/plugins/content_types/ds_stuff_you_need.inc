<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_stuff_you_need_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User - Stuff You Need To Do'),
    'icon' => 'icon_user.png',
    'description' => t('Current Doing It items'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_stuff_you_need_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $block->title = t('Complete Your Profile');
  $elements = dosomething_user_my_somethings_stuff_need_display($uid, 'current');
  $block->content .= drupal_render($elements);
  return $block;
}

