<?php

/**
 * @file
 * Row style plugin for displaying entities rss feed items.
 */

/**
 * Plugin class for displaying Views results with entity_view.
 */
class webform_entity_views_plugin_row_entity_rss extends entity_views_plugin_row_entity_view {

  /**
   * Overridden to construct RSS output based on the entity.
   */
  function render($values) {
    global $base_url;

    if ($entity = $this->get_value($values)) {
      $id = entity_id($this->entity_type, $entity);
      $uri = entity_uri($this->entity_type, $entity);
      $link = url($uri['path'], $uri['options'] + array('absolute' => TRUE));

      $render = $this->rendered_content[$id];
      // TODO: Document why #theme should be unset.
      unset($render['#theme']);

      $entity->rss_namespaces = array();
      $rss_elements = array(
        array(
          'key' => 'pubDate',
          'value' => gmdate('r', $entity->submitted),
        ),
        array(
          'key' => 'dc:creator',
          'value' => $entity->uid,
        ),
        array(
          'key' => 'guid',
          'value' => $id . ' at ' . $base_url,
          'attributes' => array('isPermaLink' => 'false'),
        ),
      );

      if (!empty($entity->rss_namespaces)) {
        $this->view->style_plugin->namespaces = array_merge($this->view->style_plugin->namespaces, $entity->rss_namespaces);
      }

      $item = new stdClass();
      $item->description = drupal_render($render);
      $item->title = entity_label($this->entity_type, $entity);
      $item->link = $link;
      $item->elements = $rss_elements;
      $item->id = $id;

      return theme($this->theme_functions(), array(
        'view' => $this->view,
        'options' => $this->options,
        'row' => $item
      ));
    }
  }
}
