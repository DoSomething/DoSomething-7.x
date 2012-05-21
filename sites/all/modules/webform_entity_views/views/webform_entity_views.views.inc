<?php

function webform_entity_views_views_plugins() {
  return array(
    'module' => 'webform_entity_views',
    'row' => array(
      'entity_rss' => array(
        'title' => t('Entity as RSS items'),
        'help' => t('Renders a single entity in a specific view mode as an RSS item.'),
        'handler' => 'webform_entity_views_plugin_row_entity_rss',
        'theme' => 'views_view_row_rss',
        'type' => 'feed',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'base' => array('webform_submissions'),
      ),
    ),
  );
}
