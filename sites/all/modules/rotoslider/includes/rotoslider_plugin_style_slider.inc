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
        'image' => array('default' => ''),
        'text' => array('default' => ''),
      ),
    );
    $options['settings'] = array(
      'contains' => array(
        'speed' => array('default' => '1000'),
        'percentage' => array('default' => '20'),
      ),
    );
    $options['initial'] = array(
      'contains' => array(
        'default' => array('default' => ''),
        'title' => array('default' => ''),
        'image' => array('default' => ''),
        'text' => array('default' => ''),
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
    $form['fields']['image'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#options' => $options,
      '#default_value' => $this->options['fields']['image'],
    );
    $form['fields']['text'] = array(
      '#type' => 'select',
      '#title' => t('Description'),
      '#options' => $options,
      '#default_value' => $this->options['fields']['text'],
    );

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('JS Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
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

    $form['initial'] = array(
      '#type' => 'fieldset',
      '#title' => t('Initial slide'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['initial']['default'] = array(
      '#type' => 'checkbox',
      '#title' => t('Provide a custom initial slide'),
      '#description' => t('If unchecked, the first slide will be the initial slide.'),
      '#default_value' => $this->options['initial']['default'],
    );
    $form['initial']['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $this->options['initial']['title'],
      '#dependency' => array('edit-style-options-initial-default' => array(1)),
    );
    $form['initial']['image'] = array(
      '#type' => 'textfield',
      '#title' => t('Image'),
      '#description' => t('Either an external URL, or a URI with a stream wrapper like "public://".'),
      '#default_value' => $this->options['initial']['image'],
      '#dependency' => array('edit-style-options-initial-default' => array(1)),
    );
    $form['initial']['text'] = array(
      '#type' => 'textarea',
      '#title' => t('Description'),
      '#default_value' => $this->options['initial']['text'],
      '#dependency' => array('edit-style-options-initial-default' => array(1)),
    );
  }
}
