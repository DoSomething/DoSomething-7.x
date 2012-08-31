<?php

$plugin = array(
  'title' => t('Pics for Pets: Share'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_share'
);

function dosomething_picsforpets_general_content_type_render_share($subtype, $conf, $context = NULL) {
  if ($submission = menu_get_object('webform_entity_pages_submission')) {
    if (isset($submission->field_fb_app_share_count[LANGUAGE_NONE][0]['value'])) {
      $shares = $submission->field_fb_app_share_count[LANGUAGE_NONE][0]['value'];
    }
  }
  if (!isset($shares)) {
    $shares = 0;
  }
  if ($shares < 200) {
    $text = t('200 shares gets me a toy!');
  }
  else if($shares < 500) {
    $text = t('500 shares gets me food!');
  }
  else if($shares < 1000) {
    $text = t('1000 shares gets me a bed!');
  }
  else {
    $text = t('Help me find a home');
  }


  $output = '<h1>' . $text . '</h1>';
  $output .= '<div class="fb-share-me">' . t('Share me') . '</div>';
  $output .= '<span class="picsforpets-share-count-arrow">&nbsp;</span>';
  $output .= '<span class="picsforpets-share-count">' . $shares . '</span>';

  $block = new stdClass();
  $block->content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'picsforpets-share',
    ),
    '#children' => $output,
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'dosomething_picsforpets_general') . '/js/share.js',
      ),
      'library' => array(
        array('system', 'ui.dialog'),
      ),
    ),
  );
  return $block;
}
