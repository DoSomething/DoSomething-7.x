<?php

class dosomething_causes_handler_field_link extends views_handler_field_custom {
  function option_definition() {
    $options = parent::option_definition();

    $options['dosomething_causes_link_type'] = array('default' => 'go');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['dosomething_causes_link_type'] = array(
      '#type' => 'radios',
      '#title' => t('DoSomething Causes Link Type'),
      '#default_value' => $this->options['dosomething_causes_link_type'],
      '#options' => array(
        'go' => t('Go link'),
        'title' => t('Title link'),
      ),
    );
  }
  function render($values) {
    // If we set a custom value, use that.
    if (!empty($values->dosomething_causes_link)) {
      if ($this->options['dosomething_causes_link_type'] == 'go') {
        $this->options['alter'] = array();
        return $values->dosomething_causes_link;
      }
      $this->options['alter']['path'] = $values->dosomething_causes_link;
    }

    // Return the text, so the code never thinks the value is empty.
    return $this->options['alter']['text'];
  }
}
