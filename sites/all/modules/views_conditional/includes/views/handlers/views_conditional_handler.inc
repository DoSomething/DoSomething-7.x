<?php

/**
 * @file
 * A views handler to output an alterate field when a field is empty.
 */

class views_conditional_handler extends views_handler_field {
  /**
   * Set default values for form elements.
   */
  function option_definition() {
    $options = parent::option_definition();
    // Never display the label of this field.
    $options['label']['default'] = NULL;

    $options['if'] = array('default' => '');
    $options['condition'] = array('default' => '');
    $options['equalto'] = array('default' => '');
    $options['then'] = array('default' => '');

    return $options;
  }

  /**
   * Add our form elements.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['relationship']['#access'] = FALSE;

    // Scan all the fields and add them as options for our field selectors.
    $fields = array(
      0 => '- ' . t('no field selected') . ' -',
    ) + $this->view->display_handler->get_field_labels();

    // We only use fields up to (not including) this one.
    unset($fields[$this->options['id']]);

    $form['if'] = array(
      '#type' => 'select',
      '#title' => t('If this field...'),
      '#options' => $fields,
      '#default_value' => $this->options['if'],
    );

    $form['condition'] = array(
      '#type' => 'select',
      '#title' => t('Is...'),
      '#options' => array(
          1 => 'Equal to',
          2 => 'NOT equal to',
          3 => 'Greater than',
          4 => 'Less than'
      ),
      '#default_value' => $this->options['condition']
    );

    $form['equalto'] = array(
      '#type' => 'textfield',
      '#title' => t('This value'),
      '#description' => t('Input a value to compare the field against.'),
      '#default_value' => $this->options['equalto'],
    );

    $form['then'] = array(
      '#type' => 'textfield',
      '#title' => t('Then output this...'),
      '#description' => t('Input what should be output.'),
      '#default_value' => $this->options['then'],
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate($form, &$form_state) {
    /*$values = &$form_state['values']['options'];
    if (empty($values['emptyfield']) || empty($values['outputfield'])) {
      if (empty($values['emptyfield'])) {
        form_set_error('emptyfield', t('Empty field must be specified.'));
      }
      if (empty($values['outputfield'])) {
        form_set_error('outputfield', t('Output field must be specified.'));
      }
    }
    elseif ($values['emptyfield'] == $values['outputfield']) {
      form_set_error('outputfield', t('The output field must be different from the empty field.'));
    }*/
  }

  /**
   * Add some summary text to the UI that explains what this field will do.
   */
  function admin_summary() {
    if (!empty($this->options['if']) && !empty($this->options['condition']) && !empty($this->options['equalto']) && !empty($this->options['then'])) {
      $options = array(
        1 => 'Equal to',
        2 => 'NOT equal to',
        3 => 'Greater than',
        4 => 'Less than'
      );

      return t('If !if is !condition !equalto, output !then', array(
        '!if' => $this->options['if'],
        '!condition' => $options[$this->options['condition']],
        '!equalto' => $this->options['equalto'],
        '!then' => $this->options['then']
      ));
    }
    else {
      return t('Invalid field selection');
    }
  }

  /**
   * Remove advanced rendering options from form.
   */
  function allow_advanced_render() {
    return FALSE;
  }

  /**
   * Do not involve the query at all for this field.
   */
  function query() {
    $this->field_alias = 'views_conditional_' . $this->position;
  }

  /**
   * Render the output.
   */
  function render($values) {
    $if = $this->options['if'];
    $condition = $this->options['condition'];
    $equalto = $this->options['equalto'];
    $then = $this->options['then'];

    $fields = $this->view->display_handler->get_handlers('field');

    $r = trim(strip_tags($fields["$if"]->last_render));

    switch ($condition) {
      // Equal to
      case 1:
        if ($r == $equalto) {
          return $then;
        }
      break;
      // Not equal to
      case 2:
        if ($r !== $equalto) {
          return $then;
        }
      break;
      // Greater than
      case 3:
        if ($r > $equalto) {
          return $then;
        }
      break;
      // Less than
      case 4:
        if ($r < $equalto) {
          return $then;
        }
      break;
    }
  }

}
