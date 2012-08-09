<?php

$plugin = array(
  'title' => t('Pics for Pets: Share'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render_share'
);

function dosomething_picsforpets_general_content_type_render_share($subtype, $conf, $context = NULL) {
  $request = drupal_http_request('https://graph.facebook.com/' . DOSOMETHING_FB_APPS_URL . '/' . $_GET['q']);
  $graph = drupal_json_decode($request->data);
  if (!isset($graph['shares'])) {
    $graph['shares'] = 0;
  }
  else {
    // TODO: update the field for number of shares.
  }
  if ($graph['shares'] < 200) {
    $text = t('200 shares gets me a toy!');
  }
  else if($graph['shares'] < 500) {
    $text = t('500 shares gets me food!');
  }
  else if($graph['shares'] < 1000) {
    $text = t('1000 shares gets me a bed!');
  }
  else {
    $text = t('Help me find a home');
  }


  $output = '<h1>' . $text . '</h1>';
  $output .= '<div class="fb-share-me">' . t('Share me') . '</div>';
  $output .= '<span class="picsforpets-share-count-arrow">&nbsp;</span>';
  $output .= '<span class="picsforpets-share-count">' . $graph['shares'] . '</span>';

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
        array('data' => array('dosomething_picsforpets_general' => array('app_url' => DOSOMETHING_FB_APPS_URL)), 'type' => 'setting'),
      ),
    ),
  );
  return $block;
}
