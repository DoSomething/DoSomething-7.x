<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('404 Page Search Block'),
  'description' => t('Displays a search block for the 404 page (or wherever else, really).'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_general_search_block_content_type_render'
);

function dosomething_general_search_block_content_type_render() {
  $block = new StdClass();
  $page = search_api_page_load(1);

  $output = array(
    'something' => array(
      '#markup' => t('Or search the site'),
      '#prefix' => '<h3 class="or-search-the-site">',
      '#suffix' => '</h3>'
    ),
    'search' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'search-from-error',
          'search',
        )
      ),
      'search' => drupal_get_form('search_api_page_search_form_' . $page->machine_name, $page, NULL, TRUE),
    ),
  );

  $block->content = $output;
  return $block;
}