<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('New Social Scholarship Social Images'),
  'description' => t('Display images for a particular node when the form is submitted..'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_social_scholars_new_image_display_content_type_render'
);

function dosomething_social_scholars_new_image_display_content_type_render($subtype, $conf, $panel_args, $context) {
  #echo '<pre>', print_r($context), '</pre>';
  $block = new StdClass();

  drupal_add_css(drupal_get_path('module', 'dosomething_social_scholars') . '/dosomething_share_a_stat.css', array(
    'group' => CSS_THEME,
    'weight' => 10
  ));

  drupal_add_js(drupal_get_path('module', 'dosomething_social_scholars') . '/dosomething_social_stat.js');
  if (!user_is_logged_in())
  {
    drupal_add_js(drupal_get_path('module', 'dosomething_social_scholars') . '/dosomething_share_a_stat.js');
  }

  $width = '225px';

  $node = array_shift($context)->data;
  $fblang = array();
  if (!empty($node->field_facebook_share_language[LANGUAGE_NONE])) {
    foreach ($node->field_facebook_share_language[LANGUAGE_NONE] AS $key => $data) {
      $fblang["$key"] = t($data['value']);
    }
  }
  if (!empty($node->field_social_scholars_images))
  {
    $desc = '';
    foreach ($node->field_social_scholars_images[LANGUAGE_NONE] AS $key => $image)
    {
      $_SERVER['HTTP_HOST'] = 'www.dosomething.org';
      $link = 'http://www.facebook.com/dialog/feed?'
      . 'app_id=105775762330&'
      . 'link=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']) . '&'
      . 'picture=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . '/files/' . $image['filename']) . '&'
      . 'name=' . urlencode($node->title).  '&'
      . 'caption=' . urlencode(url(drupal_lookup_path('alias', 'node/' . $node->nid), array('absolute' => TRUE))) . '&'
      . 'description=' . urlencode($fblang["$key"]) . '&'
      . 'display=popup&'
      . 'redirect_uri=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);

      $images .= '<a href="' . $link . '" class="fb-share-image-link"><img src="/files/' . $image['filename'] . '" style="width: ' . $width . '; margin: 2px;margin: 10px; margin-top: 18px;" alt="" /></a>';
      $shares .= '<div style="float: left; width: ' . $width . '; margin: 10px; text-align: center;"><a href="' . $link . '" class="fb-share-image-link"><img src="/' . drupal_get_path('module', 'dosomething_social_scholars') . '/images/fb.png" class="fb-share" style="width: 16px; margin: 0px auto" alt="" /></a></div>';
    }
  }

  $petition = '';
  if (isset($node->field_petition_image[LANGUAGE_NONE][0]['uri'])) {
    $petition = theme('image_formatter', array(
        'item' => array('uri' => $node->field_petition_image[LANGUAGE_NONE][0]['uri']),
        'image_style' => 'social_scholarship_images_petition_735x150',
        'attributes' => array(
          'class' => 'or-image'
        )
      ));

    if (isset($node->field_petition_link[LANGUAGE_NONE][0]['value'])) {
      $petition = l($petition, $node->field_petition_link[LANGUAGE_NONE][0]['value'], array('html' => TRUE, 'absolute' => TRUE));
    }
  }

  if ($node->title) {
    $content['title'] = array(
      '#markup' => '<h1 class="title" id="page-title">' . $node->title . '</h1><p>Share the images below by clicking on an image and sharing on facebook!</p>'
    );
  }

  $content['send_friends_these_stats'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'dosomething-social-sharing-images'
      )
    ),
    'images' => array(
      '#markup' => $images
    ),
    'shares' => array(
      '#markup' => $shares
     ),
  );

  if (!empty($petition)) {
    $content['send_friends_these_stats'] += array(
      'or' => array(
        '#markup' => '<img src="/' . drupal_get_path('module', 'dosomething_social_scholars') . '/images/or.png" class="or-line" />'
      ),
      'mills' => array(
        '#markup' => $petition
      )
    );
  }

  $block->content = $content;
  return $block;
}