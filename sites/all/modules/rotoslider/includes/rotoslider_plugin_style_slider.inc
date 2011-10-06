<?php
/**
 * @file
 * Contains the default style plugin.
 */

/**
 * Default style plugin to render rows one after another with no
 * decorations.
 *
 * @ingroup views_style_plugins
 */
class rotoslider_plugin_style_slider extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options['rotoslider'] = array(
      'contains' => array(
      'title' => array('default' => ''),
      'text' => array('default' => ''),
      'image' => array('default' => ''),
      ),
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = $this->display->handler->get_field_labels();
    $form['rotoslider'] = array(
      '#type' => 'fieldset',
      '#title' => t('Select fields'),
    );
    $form['rotoslider']['title'] = array(
      '#type' => 'select',
      '#title' => t('Title'),
      '#options' => $options,
      '#default_value' => $this->options['rotoslider']['title'],
    );
    $form['rotoslider']['text'] = array(
      '#type' => 'select',
      '#title' => t('Description'),
      '#options' => $options,
      '#default_value' => $this->options['rotoslider']['text'],
    );
    $form['rotoslider']['image'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#options' => $options,
      '#default_value' => $this->options['rotoslider']['image'],
    );
  }
}
