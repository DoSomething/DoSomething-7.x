<?php

function dosomething_campaign_styles_campaign_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Campaign Navigation'),
    'description' => t('Navigation for campaign'),
    'category' => t('Menus'),
  );
}

function dosomething_campaign_styles_campaign_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $context = og_context();
  $block = new stdClass();
  $plugin_name = dosomething_campaign_styles_pluginify_path(drupal_get_path_alias('node/' . $context->etid));
  $plugin = ctools_get_plugins('dosomething_campaign_styles', 'campaign_style', $plugin_name);

  $campaign_links = array();
  foreach ($plugin['menu'] as $num => $link) {
    if (!isset($link['validate'])) {
      $link['href'] = drupal_lookup_path('source', $link['href']);
    }
    $campaign_links['campaign_nav_'.$num] = $link;
  }
  $block->content = theme('links', array('links' => $campaign_links));
  return $block;
}

function dosomething_campaign_styles_campaign_menu_content_type_admin_title($subtype, $conf, $context) {
  return t('Campaign Navigation');
}
