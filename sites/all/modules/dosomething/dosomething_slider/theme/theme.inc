<?php

/**
 * @file
 * Theme functions for the DoSomething Slider.
 */

/**
 * Returns HTML for a JS slider.
 *
 * @param $variables
 *   An associative array containing:
 *   - items: An associative array of items to be displayed in the slider. Each
 *     item should be itself an array, with the following elements:
 *     - title: The slider item text.
 *     - image: The image URL.
 *     - text: The description associated with this item.
 *   - header: A single item to be displayed as the initial state of the slider.
 *     The array must contain the following elements:
 *     - title: The title of the slider set.
 *     - image: The image URL to be used in the default state.
 *     - text: The description of the slider set.
 */
function theme_dosomething_slider_slider($variables) {
  $items = $variables['items'];
  $heading = $variables['heading'];

  static $count;
  $count++;

  $images = array();
  $links = array();
  $text = array();
  foreach ($items as $item) {
    $key = drupal_html_class($item['title'] . '-' . $count);
    $links[$key] = array(
      'title' => $item['title'],
      'href' => "#",
      'external' => TRUE,
      'attributes' => array(
        'data-key' => $key,
      ),
    );
    $images[$key] = array(
      '#theme' => 'image',
      '#path' => $item['image'],
      '#alt' => $item['title'],
      '#attributes' => array(
        'data-key' => $key,
      ),
    );
    $text[$key] = array(
      '#type' => 'container',
      '#attributes' => array(
        'data-key' => $key,
        'class' => array(
          'dosomething-slider-text',
        ),
      ),
      'heading' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'heading',
          ),
        ),
        '#children' => $item['title'],
      ),
      'text' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'text',
          ),
        ),
        '#children' => $item['text'],
      ),
    );
  }

  $path = drupal_get_path('module', 'dosomething_slider');
  $element = array(
    '#attached' => array(
      'css' => array(
        $path . '/css/dosomething_slider.css',
      ),
      'js' => array(
        $path . '/js/dosomething_slider.js',
      ),
    ),
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'dosomething-slider',
      ),
    ),
    'image' => array(
      '#theme' => 'image',
      '#path' => $heading['image'],
      '#alt' => $heading['title'],
      '#attributes' => array(
        'class' => array(
          'dosomething-slider-image',
        ),
      ),
    ),
    'images' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-slider-images',
        ),
      ),
      'images' => $images,
    ),
    'description' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-slider-description',
        ),
      ),
      '#children' => $heading['text'],
    ),
    'descriptions' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-slider-descriptions',
        ),
      ),
      'text' => $text,
    ),
    'menu' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'dosomething-slider-menu',
        ),
      ),
      'links' => array(
        '#theme' => 'links',
        '#attributes' => array(
          'class' => array(
            'dosomething-slider-nav',
          ),
        ),
        '#links' => $links,
        '#heading' => array(
          'text' => $heading['title'],
          'level' => 'div',
          'class' => array(
            'heading',
          ),
        ),
      ),
    ),
  );

  return drupal_render($element);
}
