<?php

/**
 * Callback function to supply a list of content types.
 */
function dosomething_user_my_somethings_ds_current_somethings_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS User Current Somethings'),
    'icon' => 'icon_user.png',
    'description' => t('Current Somethings on user profiled'),
    'required context' => new ctools_context_required(t('User'), 'user'),
    'category' => t('User'),
    'defaults' => '',
  );
}

/**
 * Output function for the 'DS User info' content type.
 */
function dosomething_user_my_somethings_ds_current_somethings_content_type_render($subtype, $conf, $panel_args, $context) {
  $uid = $context->data->uid;
  $block = new stdClass();
  $content = dosomething_user_my_somethings_ds_current_somethings_content($uid);
  $block->content = '<h2>' . t('My Current Somethings') . '</h2>';
  $block->content .= theme('table', array('rows' => $content));
  return $block;
}

/**
 * Return content for My Somethings pane.
 */
function dosomething_user_my_somethings_ds_current_somethings_content($uid) {
  $links = array();

  $my_somethings = dosomething_user_my_somethings_current_somethings_links($uid);



  return $links;
}
