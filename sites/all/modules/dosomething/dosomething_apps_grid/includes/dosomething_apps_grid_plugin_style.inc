<?php

/**
 * @file
 * Contains the Dosomething Apps Grid style plugin.
 */

class dosomething_apps_grid_plugin_style extends views_plugin_style {
  function option_definition() {
    $options = array(
      'fields' => array(
        'contains' => array(
          'banner' => array('default' => ''),
          'image' => array('default' => ''),
          'text' => array('default' => ''),
          'footer' => array('default' => ''),
          'link' => array('default' => ''),
        ),
      ),
      'settings' => array(
        'contains' => array(
          'last_adjust' => array('default' => FALSE, 'bool' => TRUE),
          'last_every_nth' => array('default' => ''),
        ),
      ),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['#pre_render'][] = 'views_ui_pre_render_add_fieldset_markup';
    $form['fields'] = array(
      '#type' => 'fieldset',
      '#title' => t('Fields'),
    );
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings'),
    );

    $fields = $this->dosomething_apps_grid_fields();
    $fields_optional = array('' => t('- None -')) + $fields;

    $form['fields']['banner'] = array(
      '#type' => 'select',
      '#title' => t('Banner'),
      '#description' => t("Choose the field for the banner."),
      '#options' => $fields_optional,
      '#default_value' => $this->options['fields']['banner'],
    );
    $form['fields']['image'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#description' => t('Choose the field for the image'),
      '#options' => $this->dosomething_apps_grid_fields('image'),
      '#default_value' => $this->options['fields']['image'],
      '#required' => TRUE,
    );
    $form['fields']['text'] = array(
      '#type' => 'select',
      '#title' => t('Text'),
      '#description' => t('Choose the field for the text'),
      '#options' => $fields,
      '#default_value' => $this->options['fields']['text'],
      '#required' => TRUE,
    );
    $form['fields']['footer'] = array(
      '#type' => 'select',
      '#title' => t('Footer'),
      '#description' => t("Choose the field for the footer."),
      '#options' => $fields_optional,
      '#default_value' => $this->options['fields']['footer'],
    );
    $form['fields']['link'] = array(
      '#type' => 'select',
      '#title' => t('Link'),
      '#description' => t("Choose the value for the 'Go' button."),
      '#options' => $fields_optional,
      '#default_value' => $this->options['fields']['link'],
    );

    $form['settings']['last_adjust'] = array(
      '#type' => 'checkbox',
      '#title' => t('Adjust the first/last class'),
      '#default_value' => $this->options['settings']['last_adjust'],
    );
    $form['settings']['last_every_nth'] = array(
      '#type' => 'textfield',
      '#size' => 3,
      '#title' => t('FIRST/LAST every n<sup>th</sup>'),
      '#default_value' => $this->options['settings']['last_every_nth'],
      '#dependency' => array('edit-style-options-settings-last-adjust' => array(1)),
    );
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    $options = &$form_state['values']['style_options'];
    if (empty($options['settings']['last_adjust'])) {
      $options['settings']['last_every_nth'] = 0;
    }
  }

  /**
   * Wrapper around views_plugin_display::get_field_labels().
   *
   * @param array|string|null $type
   *   Either a string or array of field types.
   *
   * @return array
   *   An associative array of field labels, keyed by their field id.
   *
   */
  function dosomething_apps_grid_fields($type = NULL) {
    $this->view->init_handlers();
    $labels = $this->display->handler->get_field_labels();
    // If specific field types are needed, restrict the options.
    if (isset($type)) {
      // Allow both single and multiple types.
      if (!is_array($type)) {
        $type = array($type);
      }
      foreach ($this->view->field as $id => $field) {
        if (!isset($field->field_info) || !in_array($field->field_info['type'], $type)) {
          unset($labels[$id]);
        }
      }
    }
    return $labels;
  }
}
