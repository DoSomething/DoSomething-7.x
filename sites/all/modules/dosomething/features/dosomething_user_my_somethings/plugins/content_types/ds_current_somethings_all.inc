<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_current_somethings_all_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Doing It - All'),
    'icon' => 'icon_user.png',
    'description' => t('Current Doing It items on user profile'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_current_somethings_all_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $block->title = t('Doing It');
  $elements = dosomething_user_my_somethings_display($uid, 'current');
  $block->content = l('<< Back to profile', 'user/' . $uid, array('attributes' => array('class' => 'back')));
  $block->content .= drupal_render($elements);
  return $block;
}

