<?php

$plugin = array(
  'title' => t('Featured Project Switcher'),
  'single' => TRUE,
  'content_types' => array('dosomething_project_switcher'),
  'render callback' => 'dosomething_project_switcher_content_type_render',
  'category' => t('DoSomething'),
);

function dosomething_project_switcher_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $element = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'featured-project-switcher',
      ),
    ),
  );
  $path = 'projects/featured-projects/';
  ctools_include('jump-menu');
  $targets = array(
    url($path) => t('All Featured Projects'),
    url($path . 'grant-winners') => t('Grant Winners'),
    url($path . 'scholarship-winners') => t('Scholarship Winners'),
    url($path . 'pod') => t('Featured Projects of the Day'),
    url($path . 'club') => t('Club Projects'),
  );
  $default = url($path);
  if (isset($targets[url($path . arg(2))])) {
    $default = url($path . arg(2));
  }
  $options['default_value'] = $default;
  $options['choose'] = '';
  $element['form'] = drupal_get_form('ctools_jump_menu', $targets, $options);
  $block->content = $element;
  return $block;
}

