<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Social Scholarship Social Images'),
  'description' => t('Display images for a particular node when the form is submitted..'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_social_scholars_image_display_content_type_render'
);

function dosomething_social_scholars_image_display_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = node_load(723646);
  $block = new StdClass();

  drupal_add_css(drupal_get_path('module', 'dosomething_social_scholars') . '/dosomething_share_a_stat.css', array(
    'group' => CSS_THEME,
    'weight' => 10
  ));

  drupal_add_js(drupal_get_path('module', 'dosomething_social_scholars') . '/dosomething_share_a_stat.js');

  $width = '225px';

  if (!empty($node->field_social_scholars_images))
  {
    $desc = '';
    foreach ($node->field_social_scholars_images[LANGUAGE_NONE] AS $key => $image)
    {
      if ($key == 0)
          $desc = '4-5 million animals die in shelters every year.  Do something about it! Click here to share this state with your friends and you could win a $5,000 scholarship.';
      else if ($key == 1)
          $desc = 'There are 7 million animal across shelters in the US.  Do something about it! Click here to share this stat with your friends and you could win a $5,000 scholarship.';
      else if ($key == 2)
          $desc = 'More than 25 million animals are used in testing in the US each year.  Do something about it! Click here to share this stat with your friends and you could win a $5,000 scholarship.';

      $link = 'http://www.facebook.com/dialog/feed?'
      . 'app_id=105775762330&'
      . 'link=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']) . '&'
      . 'picture=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . '/files/' . $image['filename']) . '&'
      . 'name=' . urlencode($node->title).  '&'
      . 'caption=' . urlencode($node->title) . '&'
      . 'description=' . urlencode($desc) . '&'
      . 'display=popup&'
      . 'redirect_uri=' . urlencode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);

      $images .= '<a href="' . $link . '" class="fb-share-image-link"><img src="/files/' . $image['filename'] . '" style="width: ' . $width . '; margin: 2px;margin: 10px; margin-top: 18px;" alt="" /></a>';
      $shares .= '<div style="float: left; width: ' . $width . '; margin: 10px; text-align: center;"><a href="' . $link . '" class="fb-share-image-link"><img src="/' . drupal_get_path('module', 'dosomething_social_scholars') . '/images/fb.png" class="fb-share" style="width: 16px; margin: 0px auto" alt="" /></a></div>';
    }
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
  'or' => array(
    '#markup' => '<img src="/' . drupal_get_path('module', 'dosomething_social_scholars') . '/images/or.png" />'
  ),
  'mills' => array(
    '#markup' => '<a href="/petition/put-end-to-puppy-mills"><img src="/' . drupal_get_path('module', 'dosomething_social_scholars') . '/images/mills.png" class="or-image" /></a>',
  )
  );

  $block->content = $content;
  return $block;
}