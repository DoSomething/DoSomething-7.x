<?php

/**
 * @file
 * Contains the Dosomething Apps Grid style plugin.
 */

class dosomething_apps_grid_plugin_style extends views_plugin_style {

  /**
   * Check if there are no results behaviors set.
   */
  function even_empty() {
    return empty($this->view->empty) ? !empty($this->definition['even empty']) : FALSE;
  }

  function option_definition() {
    $options = array(
      'image' => array('default' => ''),
      'text' => array('default' => ''),
      'link' => array('default' => ''),
      'footer' => array('default' => ''),
      'banner' => array('default' => ''),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $fields = $this->dosomething_apps_grid_fields();
    $form['image'] = array(
     '#type' => 'select',
     '#title' => t('Image'),
     '#description' => t('Choose the field for the image'),
     '#options' => $this->dosomething_apps_grid_fields('image'),
     '#default_value' => $this->options['image'],
     '#required' => TRUE,
    );
    $form['text'] = array(
     '#type' => 'select',
     '#title' => t('Text'),
     '#description' => t('Choose the field for the text'),
     '#options' => $this->dosomething_apps_grid_fields(),
     '#default_value' => $this->options['text'],
     '#required' => TRUE,
    );
    $form['footer'] = array(
     '#type' => 'select',
     '#title' => t('Footer'),
     '#description' => t("Choose the field for the footer."),
     '#options' => array('' => t('- None -')) + $this->dosomething_apps_grid_fields(),
     '#default_value' => $this->options['footer'],
    );
    $form['link'] = array(
     '#type' => 'select',
     '#title' => t('Link'),
     '#description' => t("Choose the value for the 'Go' button."),
     '#options' => array('' => t('- None -')) + $this->dosomething_apps_grid_fields(),
     '#default_value' => $this->options['link'],
    );
    $form['banner'] = array(
     '#type' => 'select',
     '#title' => t('Banner'),
     '#description' => t("Choose the field for the banner."),
     '#options' => array('' => t('- None -')) + $this->dosomething_apps_grid_fields(),
     '#default_value' => $this->options['banner'],
    );
  }

  function dosomething_apps_grid_fields_value($field, $field_name, $row, $delta) {
    $item = '';
    if (isset($field->field_info)) {
      $items = $field->get_items($row);
      if (!empty($items)) {
        $item = reset($items);
      }
    }
    else {
      $item = $view->style_plugin->get_field($delta, $field_name);
    }

    if (!is_array($item)) {
      $item = array('rendered' => array('#markup' => $item));
    }

    $element_type = $field->element_type();
    $class = $field->element_classes($delta);
    $prefix = '<' . $element_type;
    if ($class) {
      $prefix .= ' class="' . $class . '"';
    }
    $prefix .= '>';
    $suffix = '</' . $element_type . '>';

    $item['rendered']['#prefix'] = $prefix;
    $item['rendered']['#suffix'] = $suffix;

    return $item;
  }

  function dosomething_apps_grid_fields($type = NULL) {
    $this->view->init_handlers();
    $labels = $this->display->handler->get_field_labels();
    $fields = array();
    foreach ($this->view->field as $id => $field) {
      if (isset($type)) {
        if (!is_array($type)) {
          $type = array($type);
        }
        if (!isset($field->field_info) || !in_array($field->field_info['type'], $type)) {
          continue;
        }
      }
      $fields[$id] = $labels[$id];
    }
    return $fields;
  }
}
