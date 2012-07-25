<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Share Images'),
  'description' => t('Display images for a particular node when the form is submitted..'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_social_scholars_image_display_content_type_render'
);

function dosomething_social_scholars_image_display_content_type_render($subtype, $conf, $panel_args, $context) {
  $cur = menu_get_object();
  $three = true;
  if ($cur->nid <> 723323)
  {
    $node = node_load(723323);
    $three = false;
    $width = '100%';
  }
  else $node = $cur;
  $block = new StdClass();

  $width = ($width ? $width : '225px');

  if (!empty($node->field_social_scholars_images))
  {
    foreach ($node->field_social_scholars_images[LANGUAGE_NONE] AS $key => $image)
    {
      $images .= '<img src="/files/' . $image['filename'] . '" style="width: ' . $width . '; margin: 2px;margin: 10px; margin-top: 18px;" alt="" />';
      $link = 'http://www.facebook.com/dialog/feed?'
      . 'app_id=105775762330&'
      . 'link=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']) . '&'
      . 'picture=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . '/files/' . $image['filename']) . '&'
      . 'name=' . urlencode($node->title).  '&'
      . 'caption=' . urlencode($node->title) . '&'
      . 'display=popup&'
      . 'redirect_uri=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);

      $shares .= '<div style="float: left; width: ' . $width . '; margin: 10px; text-align: center;"><a href="' . $link . '" class="fb-share-image-link"><img src="/files/fb.png" class="fb-share" style="width: 16px; margin: 0px auto" alt="" /></a></div>';
    }
  }

  #echo '<pre>', print_r($node), '</pre>';

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
  'or' => array(
    '#markup' => '<img src="/files/or.png" />'
  ),
  'mills' => array(
    '#markup' => '<a href="/petition/put-end-to-puppy-mills"><img src="/files/mills.png" class="or-image" /></a>',
  )
  );

  $block->content = $content;
  return $block;
}