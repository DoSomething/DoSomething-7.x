<?php

/**
 * Callback function for blog menu. 
 */
function dosomething_blog_ds_blog_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('DS Blog Menu'),
    'description' => t('Blog menu/filters'),
   // 'defaults' => '',
   // 'required context' => '',
    'category' => t('Menus'),
  );
}

/**
 * Output function blog menu.
 */
function dosomething_blog_ds_blog_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $vocab = taxonomy_vocabulary_machine_name_load('blog_type');
  $vocab_tree = taxonomy_get_tree($vocab->vid);
  foreach ($vocab_tree as $term) {
    switch ($term->name) {
      case 'Awe-Some Ones':
        $awesome = $term->tid;
        break;
      case 'Celebs Gone Good':
        $celebs = $term->tid;
        break;
      case 'DoSomething Staff':
        $staff = $term->tid;
        break;
      case 'News':
        $news = $term->tid;
        break;
    }  
  }  
  $output = new stdClass();
  $output->content = array(
      'blog_menu' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'blog_menu',
        ),  
      ),  
      'links' => array(
        '#theme' => 'links',
        '#links' => array(
          'all' => array(
            'title' => 'All',
            'html' => TRUE,
            'href' => 'blog/all', 
          ),  
          'awesome' => array(
            'title' => 'Awe-Some Ones',
            'html' => TRUE,
            'href' => 'blog/' . $awesome, 
          ),  
          'celebs' => array(
            'title' => 'Celebs Gone Good',
            'html' => TRUE,
            'href' => 'blog/' . $celebs, 
          ),  
          'staff' => array(
            'title' => 'DoSomething Staff',
            'html' => TRUE,
            'href' => 'blog/' . $staff, 
          ),  
          'news' => array(
            'title' => 'News',
            'html' => TRUE,
            'href' => 'blog/' . $news, 
          ),  
        ),
      ),
    ),
  );
  return $output;
}
