<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_past_somethings_all_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Done It - All'),
    'icon' => 'icon_user.png',
    'description' => t('Done It items on user profile'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_past_somethings_all_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $block->title = t('Done It');
  $elements = dosomething_user_my_somethings_display($uid, 'past');
  $block->content = l('« Back to profile', 'user/' . $uid, array('attributes' => array('class' => 'back')));
  $block->content .= drupal_render($elements);
  return $block;
}

