<?php

/**
 * Generate 'Stuff Youve Done' pane.
 */
function dosomething_user_my_somethings_ds_stuff_youve_done_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User - Stuff You\'ve Done'),
    'icon' => 'icon_user.png',
    'description' => t('Stuff user has done'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User - Stuff Youve Done' content type.
 */
function dosomething_user_my_somethings_ds_stuff_youve_done_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $elements = dosomething_user_my_somethings_stuff_need_display($uid, 'past');
  $block->content = drupal_render($elements);
  return $block;
}

