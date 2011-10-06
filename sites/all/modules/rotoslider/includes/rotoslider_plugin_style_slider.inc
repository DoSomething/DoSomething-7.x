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
  function option_definition() {
    $options['fields'] = array(
      'contains' => array(
        'title' => array('default' => ''),
        'text' => array('default' => ''),
        'image' => array('default' => ''),
      ),
    );
    $options['settings'] = array(
      'contains' => array(
        'speed' => array('default' => ''),
        'percentage' => array('default' => ''),
      ),
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $options = $this->display->handler->get_field_labels();
    $form['fields'] = array(
      '#type' => 'fieldset',
      '#title' => t('Select fields'),
    );
    $form['fields']['title'] = array(
      '#type' => 'select',
      '#title' => t('Title'),
      '#options' => $options,
      '#default_value' => $this->options['fields']['title'],
    );
    $form['fields']['text'] = array(
      '#type' => 'select',
      '#title' => t('Description'),
      '#options' => $options,
      '#default_value' => $this->options['fields']['text'],
    );
    $form['fields']['image'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#options' => $options,
      '#default_value' => $this->options['fields']['image'],
    );

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('JS Settings'),
    );
    $form['settings']['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Animation speed'),
      '#field_suffix' => 'ms',
      '#size' => 4,
      '#default_value' => $this->options['settings']['speed'],
    );
    $form['settings']['percentage'] = array(
      '#type' => 'textfield',
      '#title' => t('Trigger height'),
      '#field_suffix' => '%',
      '#size' => 2,
      '#default_value' => $this->options['settings']['percentage'],
    );
  }
}
