<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('User picture'),
  'icon' => 'icon_user.png',
  'description' => t('The picture of a user.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('User'),
);

function ctools_user_picture_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  if (empty($context->data)) {
    return;
  }

  $account = clone $context->data;

  // Check if user has permissions to access the user
  if ($user->uid != $account->uid && !user_access('access user profiles')) {
    return;
  }

  $block = new stdClass();
  $block->module = 'user-profile';
  $block->title = check_plain($account->name);

  $element['user_picture'] = array(
    '#theme' => 'user_picture',
    '#account' => $account,
  );


  $block->content = $element;
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function ctools_user_picture_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user picture', array('@s' => $context->identifier));
}

function ctools_user_picture_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
