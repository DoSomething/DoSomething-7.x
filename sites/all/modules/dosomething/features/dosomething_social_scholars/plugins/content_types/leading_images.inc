<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Social Scholarship Primary Images'),
  'description' => t('Display Social Scholars images on landing page'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_social_scholars_shared_images_content_type_render'
);

function dosomething_social_scholars_shared_images_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object();
  $block = new StdClass();

  if (!empty($node->field_social_scholars_images))
  {
    $desc = '';
    foreach ($node->field_social_scholars_images[LANGUAGE_NONE] AS $key => $image)
    {
      $images .= l(theme('image_formatter', array(
        'item' => array('uri' => 'public://' . $image['filename']),
        'image_style' => 'social_scholarship_stat_image_190x190'
      )), 'files/' . $image['filename'], array('html' => TRUE));
    }
  }

  $content['send_friends_these_stats'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'dosomething-social-leading-images'
      )
    ),
    'images' => array(
      '#markup' => $images
    ),
  );

  $block->content = $content;
  return $block;
}