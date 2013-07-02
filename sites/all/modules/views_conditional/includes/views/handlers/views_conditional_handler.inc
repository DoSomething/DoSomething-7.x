<?php

/**
 * @file
 * Handles conditionals in Views.  IF xxx THEN yyy...
 */

class ViewsConditionalHandler extends views_handler_field {
  // Conditional operators.
  public $conditions = array(
    1 => 'Is Equal to',
    2 => 'Is NOT equal to',
    3 => 'Is Greater than',
    4 => 'Is Less than',
    5 => 'Is Empty',
    6 => 'Is NOT empty',
    7 => 'Contains',
    8 => 'Does NOT contain',
  );

  /**
   * Set default values for form elements.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['label']['default'] = NULL;

    $options['if'] = array('default' => '');
    $options['condition'] = array('default' => '');
    $options['conditions'] = array('default' => '');
    $options['equalto'] = array('default' => '');
    $options['then'] = array('default' => '');
    $options['or'] = array('default' => '');

    return $options;
  }

  /**
   * Views form elements.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['#attached']['js'][] = drupal_get_path('module', 'views_conditional') . '/js/field_handler.js';
    $form['#attached']['css'][] = drupal_get_path('module', 'views_conditional') . '/css/field_handler.css';

    $form['relationship']['#access'] = FALSE;

    // Display all labels weighted less than the current label.
    $fields = array(
      0 => '- ' . t('no field selected') . ' -',
    ) + $this->view->display_handler->get_field_labels();

    // We only use fields up to (not including) this one.
    unset($fields[$this->options['id']]);

    $form['condition_title'] = array(
      '#markup' => t('If these conditions pass...'),
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    );

    $form['hidden_field_select'] = array(
      '#type' => 'select',
      '#options' => $fields,
      '#attributes' => array('id' => 'hidden-select'),
    );

    $form['list'] = array(
      '#markup' => '<a href="#" class="add-master" data-type="and">Add "And" field</a> | <a href="#" class="add-master" data-type="or">Add "or" field</a>
<ul id="conditions-container">
  <li data-id="0" data-type="and">
    <input type="hidden" name="options[conditions][0][type]" value="and" />
    <div class="form-item form-type-select form-item-field">
      <select class="first-field form-select" id="edit-options-if" name="options[conditions][0][field]"><option value="0">- no field selected -</option><option value="field_picture">Field: Picture</option><option value="field_embedded_video">Content: Video</option><option value="views_ifempty">Views If Empty: Views If Empty</option><option value="title">Content: Title</option><option value="created">Content: Post date</option><option value="field_subtitle">Content: Subtitle</option><option value="body_1">Campaign Blog Text</option><option value="views_ifempty_1">Views If Empty: Views If Empty</option><option value="body">Content: Body</option></select>
    </div>
    <div class="form-item form-type-select form-item-options-conditions-condition first">
      <select id="edit-options-conditions-condition" name="options[conditions][0][condition]" class="form-select"><option value="1">Is Equal to</option><option value="2">Is NOT equal to</option><option value="3">Is Greater than</option><option value="4">Is Less than</option><option value="5">Is Empty</option><option value="6">Is NOT empty</option><option value="7">Contains</option><option value="8">Does NOT contain</option></select>
    </div>
    <div class="form-item form-type-textfield form-item-options-conditions-equalto">
      <input type="text" id="edit-options-conditions-equalto" name="options[conditions][0][equals]" value="" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed" />
    </div>
    <div id="options" class="first">
      <a href="#" class="add-sub" data-type="and">Add "And"</a> <span class="divider">|</span>
      <a href="#" class="add-sub" data-type="or">Add "Or"</a>
    </div>
  </li>
</ul>');
/*
    $form['if'] = array(
      '#type' => 'select',
      '#title' => t('If this field...'),
      '#options' => $fields,
      '#default_value' => $this->options['if'],
      '#attributes' => array('class' => array('first-field')),
    );

    $form['conditions'] = array(
      '#type' => 'container',
      '#attributes' => array('id' => 'conditions-container'),
    );

    $form['conditions']['one'] = array(
      '#markup' => '#1',
      '#prefix' => '<span class="condition-number">',
      '#suffix' => '</span>',
    );

    $form['conditions']['condition'] = array(
      '#type' => 'select',
      '#title' => t('Condition...'),
      '#options' => $this->conditions,
      '#default_value' => $this->options['condition'],
    );

    $form['conditions']['equalto'] = array(
      '#type' => 'textfield',
      '#title' => t('This value'),
      '#description' => t('Input a value to compare the field against.  Replacement variables may be used'),
      '#default_value' => $this->options['equalto'],
    );

    if (!empty($this->options['conditions']['more'])) {
      $form['conditions']['more'] = array(
        '#type' => 'container',
        '#attribtues' => array('id' => 'more-container'),
      );

      $num = 1;
      foreach ($this->options['conditions']['more']['condition'] as $key => $val) {
        if ($val != "") {
          $form['conditions']['more'][$key] = array(
            '#markup' => '#' . ++$num,
            '#prefix' => '<span class="condition-number">',
            '#suffix' => '</span>',
          );

          $form['conditions']['more']['condition'][$key] = array(
            '#type' => 'select',
            '#title' => t('Condition...'),
            '#options' => $this->conditions,
            '#default_value' => $val,
          );

          $form['conditions']['more']['equalto'][$key] = array(
            '#type' => 'textfield',
            '#title' => t('This value'),
            '#description' => t('Input a value to compare the field against.  Replacement variables may be used'),
            '#default_value' => $this->options['conditions']['more']['equalto'][$key],
          );
        }
      }
    }

    $form['new_conditions'] = array(
      '#type' => 'container',
      '#attributes' => array('id' => 'new-conditions-container'),
    );

    $form['new_condition'] = array(
      '#markup' => l(t('Add another condition'), '', array('fragment' => ' ', 'attributes' => array('id' => 'add-condition'))),
    );*/

    $form['then'] = array(
      '#type' => 'textfield',
      '#title' => t('Then output this...'),
      '#description' => t('Input what should be output.  Replacement variables may be used.'),
      '#default_value' => $this->options['then'],
    );

    $form['or'] = array(
      '#type' => 'textfield',
      '#title' => t('Otherwise, output this...'),
      '#description' => t('Input what should be output if the above conditions do NOT evaluate to TRUE.'),
      '#default_value' => $this->options['or'],
    );

    $form['replacements'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Replacement Variables'),
    );

    $form['replacements']['notice'] = array(
      '#markup' => 'You may use any of these replacement variables in the "equals" or the "output" text fields.  If you wish to use brackets ([ or ]), replace them with %5D or %5E.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $items = array(
      'DATE_UNIX => Current date / time, in UNIX timestamp format (' . REQUEST_TIME . ')',
      'DATE_STAMP => Current date / time, in standard format (' . format_date(REQUEST_TIME) . ')',
    );
    foreach ($this->view->display_handler->get_field_labels() as $item => $title) {
      $items[] = "[$item] => $title";
    }

    $form['replacements']['variables'] = array(
      '#markup' => theme('item_list', array('items' => $items)),
    );
  }

  /**
   * Check that everything is in order.
   */
  public function options_validate(&$form, &$form_state) {
    $values = &$form_state['input']['options'];
    $form_state['values'] = array_replace_recursive($form_state['values'], $form_state['input']);
/*    $eqta = &$values['conditions']['more']['equalto'];
    foreach ($eqta AS $key => $var) {
      if ($key & 1) {
        unset($eqta[$key]);
      }
    }

    $eqta = array_values($eqta);

    // Getting this to work probably is complicated.  We need to overwrite $form_state['values']
    // with $form_state['input'] to properly save the input or removal of items.
    $form_state['values'] = array_replace_recursive($form_state['values'], $form_state['input']);

    if (empty($values['if']) || empty($values['conditions'])) {
      if (empty($values['if'])) {
        form_set_error('if', t("Please specify a valid field to run a condition on."));
      }
      if (empty($values['conditions'])) {
        form_set_error('condition', t("Please select a conditional operator."));
      }
      #if (empty($values['equalto']) && !in_array($values['condition'], array(5, 6))) {
      #  form_set_error('condition', t("Please specify something to compare with."));
      #}
    }*/
  }


  /**
   * Defines summary text for Fields category in Views.
   */
  public function admin_summary() {
    if (!empty($this->options['if']) && !empty($this->options['condition']) && (!empty($this->options['equalto']) || in_array($this->options['condition'], array(5, 6))) && trim($this->options['then']) != '') {
      return t('If !if !condition !equalto, output !then, else output !or', array(
        '!if' => $this->options['if'],
        '!condition' => $this->conditions[$this->options['condition']],
        '!equalto' => $this->options['equalto'],
        '!then' => $this->options['then'],
        '!or' => $this->options['or'],
      ));
    }
    else {
      return t('Invalid field selection');
    }
  }

  /**
   * Remove advanced rendering options from form.
   */
  public function allow_advanced_render() {
    return FALSE;
  }

  /**
   * Defines field alias.  No query manipulation necessary.
   */
  public function query() {
    $this->field_alias = 'views_conditional_' . $this->position;
  }

  /**
   * Cleans a variable for handling later.
   */
  public function clean_var($var, $key) {
    $f = array();
    if (isset($var->view->query->pager->display->handler->options['fields'][$key])) {
      $f = $var->view->query->pager->display->handler->options['fields'][$key];
    }

    $unparsed = trim($var->last_render);
    $parse = TRUE;
    if (!empty($f['element_type'])) {
      $parse = FALSE;
    }

    if (isset($f['alter']['make_link']) && $f['alter']['make_link'] == 1) {
      $parse = FALSE;
    }

    if (isset($f['alter']['prefix']) || isset($f['alter']['suffix'])) {
      $parse = FALSE;
    }

    if ($parse) {
      $unparsed = strip_tags($unparsed);
    }

    return trim($unparsed);
  }

  /**
   * Checks whether a condition passes.
   *
   * @param string $field
   *   The text from the field.  This should have been stripped before getting here.
   * @param integer $condition
   *   A number matching a condition, as defined in public $conditions above.
   * @param string $equals
   *   What the field should ($condition)...
   *
   * @return bool
   */
  protected function passes($field, $condition, $equals) {
    $fields = $this->view->display_handler->get_handlers('field');


    $clean_var = $this->clean_var($fields[$field['field']]);
    // Strip tags on the "if" field.  Otherwise it appears to
    // output as <div class="xxx">Field data</div>...
    // ...which of course makes it dificult to compare.
    $r = trim(strip_tags($fields[$field]->last_render, '<img>'));

    // Run conditions.
    switch ($condition) {
      // Equal to.
      case 1:
        if ($r == $equals) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Not equal to.
      case 2:
        if ($r !== $equals) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Greater than.
      case 3:
        if ($r > $equals) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Less than.
      case 4:
        if ($r < $equals) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Empty.
      case 5:
        if (empty($r)) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Not empty.
      case 6:
        if (!empty($r)) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Contains
      case 7:
        if (stripos($r, $equals) !== FALSE) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;

      // Does NOT contain
      case 8:
        if (stripos($r, $equals) === FALSE) {
          return TRUE;
        }
        else {
          return FALSE;
        }
        break;
    }
  }

  private function check_conditions($conditions) {
    $needed_wins = $wins = 0;
    foreach ($conditions AS $key => $condition) {
      if ($condition['type'] == 'and') {
        $needed_wins++;
      }

      if ($this->passes($condition['field'], $condition['condition'], $condition['equals'])) {
        $wins++;
      }
    }

    return ($wins >= $needed_wins);
  }

  /**
   * Renders the final output based on conditional input.
   */
  public function render($values) {
    $if = $this->options['if'];
    $condition = $this->options['condition'];
    $equalto = $this->options['equalto'];
    $then = $this->options['then'];
    $or = ($this->options['or'] ? $this->options['or'] : '');

    $conditions = $this->options['conditions'];

    $success = $this->check_conditions($conditions);
    if ($success) {
      return $then;
    }
    else {
      return $or;
    }
  }
}
