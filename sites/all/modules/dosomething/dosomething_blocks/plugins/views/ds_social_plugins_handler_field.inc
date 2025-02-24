<?php

/**
 * A handler to provide a field for DoSomething social plugins.
 *
 * @ingroup views_field_handlers
 */
class ds_social_plugins_handler_field extends views_handler_field {

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $modules = dosomething_blocks_social_plugins_modules();
    $options['module_options'] = $modules;
    $options['options']['fb_social_preset'] = array('default' => '');
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $modules = dosomething_blocks_social_plugins_modules();
    $options = $this->options['module_options'] ? $this->options['module_options'] : array();
    $form['module_options'] = array(
      '#title' => t('Social plugins to include.'),
      '#type' => 'checkboxes',
      '#options' => $modules,
      '#description' => t('Leave blank to include all.'),
      '#default_value' => $options,
    );

    // Facebook Social options.
    $presets = array();
    $preset_list = array();
    $presets = fb_social_get_presets();
    foreach ($presets as $preset) {
      $preset_list[$preset->name] = $preset->name;
    }

    $form['options']['fb_social_preset'] = array(
      '#title' => t('Facebook Social Preset'),
      '#options' => array('' => '<select>') + $preset_list,
      '#type' => 'select',
      '#default_value' => $this->options['options']['fb_social_preset'],
      '#description' => t('Choose a Facebook Social Preset'),
      '#dependency' => array(
        'edit-options-module-options-fb-social' => array(1),
      ),
    );

    $form['options']['url_field'] = array(
      '#title' => t('URL to link to'),
      '#type' => 'textfield',
      '#default_value' => $this->options['options']['url_field'],
      '#description' => t('URL to link to. You can use tokens from the replacement patterns below. Leave blank for the default URL.'),
    );

    $form['options']['tweet_text'] = array(
      '#title' => t('Twitter tweet text'),
      '#type' => 'textfield',
      '#default_value' => $this->options['options']['tweet_text'],
      '#description' => t('Text to tweet. You can use tokens from the replacement patterns below. Leave blank for page title.'),
    );
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  function query() {
    // Provide an field alias but don't actually alter the query.
    $this->field_alias = 'ds_social_plugins_' . $this->position;
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {
    if (!$this->options['exclude']) {
      $modules = $this->options['module_options'];
      $options = $this->options['options'];

      if (!empty($options['tweet_text'])) {
        $options['tweet_text'] = $this->tokenize_value($options['tweet_text']);
      }

      if (!empty($options['url_field'])) {
        $url = $this->tokenize_value($options['url_field']);
      }
      else if (!empty($values->nid)) {
        $url = url('node/' . $values->nid, $options = array('absolute' => TRUE));
      }
      else {
        $url = NULL;
      }
      
      $value = dosomething_blocks_social_node_plugins($url, $modules, $options);
    }

    return $value;
  }
}
