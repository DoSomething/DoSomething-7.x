<?php

/**
 * A handler to provide a field for Facebook Social plugins.
 *
 * @ingroup views_field_handlers
 */
class fb_social_handler_field extends views_handler_field {

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['fb_social_plugins'] = array('default' => '');
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $presets = fb_social_get_presets();
    foreach ($presets as $preset) {
      $preset_list[$preset->name] = $preset->name;
    }

    $form['fb_social_plugins'] = array(
      '#title' => t('Facebook Social Preset'),
      '#options' => array('' => '<select>') + $preset_list,
      '#type' => 'select',
      '#default_value' => $this->options['fb_social_plugins'],
      '#description' => t('Choose a Facebook Social Preset'),
    );

  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  function query() {
    // Provide an field alias but don't actually alter the query.
    $this->field_alias = 'fb_social_' . $this->position;
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {

    if (!empty($this->options['fb_social_plugins'])) {
      if (!empty($values->nid)) {
        $url = url('node/' . $values->nid, $options = array('absolute' => TRUE));
      }
      else {
        $url = NULL;
      }
      $presets = fb_social_get_presets();
      $preset = $presets[$this->options['fb_social_plugins']];
      $value = fb_social_preset_view($preset, $url);
    }

    return $value;
  }
}
