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


    $condition_list = '';
    foreach($this->conditions as $k => $cond) {
      $condition_list .= '<option value="' . $k . '"' . ($condition['condition'] == $k ? ' selected="selected"' : '') . '>' . $cond . '</option>';
    }

    $fieldlist = '';
    if (!empty($this->options['conditions'])) {
      $last_elm = 0;
      foreach ($this->options['conditions'] AS $key => $condition) {
        $last_elm = $key;
        $fieldlist .= '
        <li data-id="' . $key . '" data-type="' . $condition['type'] . '">
          <input type="hidden" name="options[conditions][' . $key . '][type]" value="' . $condition['type'] . '" />
          <div class="form-item form-type-select form-item-field">
            <select class="first-field form-select" id="edit-options-if" name="options[conditions][' . $key . '][field]">';
          foreach ($fields AS $k => $string) {
            $fieldlist .= '<option value="' . $k . '"' . ($k == $condition['field'] ? ' selected="selected"' : '') . '>' . $string . '</option>';
          }
          $fieldlist .= '
          </select>
          </div>
          <div class="form-item form-type-select form-item-options-conditions-condition first">
            <select id="edit-options-conditions-condition" name="options[conditions][' . $key . '][condition]" class="form-select">';

          $fieldlist .= $condition_list;
          
          $fieldlist .= '</select>
          </div>
          <div class="form-item form-type-textfield form-item-options-conditions-equalto">
            <input type="text" id="edit-options-conditions-equalto" name="options[conditions][' . $key . '][equals]" value="' . $condition['equals'] . '" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed" />
          </div>
          <div id="options" class="first">
            <a href="#" class="add-sub" data-type="and">Add "And"</a> <span class="divider">|</span>
            <a href="#" class="add-sub" data-type="or">Add "Or"</a>
          </div>';

        if (!empty($condition['children']) && is_array($condition['children'])) {
          $fieldlist .= '<ul class="sub">';
          foreach ($condition['children'] AS $ck => $cc) {
            $last_elm = $ck;
            $fieldlist .= '
            <li data-id="' . $ck . '">
              <span class="form-item"><img class="tree" src="/sites/all/modules/views_conditional/images/navbit.gif" alt=""> ' . ucfirst($cc['type']) . '</span>
              <input type="hidden" name="options[conditions][' . $key . '][children][' . $ck . '][type]" value="' . $cc['type'] . '" />
              <div class="form-item form-type-select form-item-field">
                <select class="first-field form-select" id="edit-options-if" name="options[conditions][' . $key . '][children][' . $ck . '][field]">';
              foreach ($fields AS $k => $string) {
                $fieldlist .= '<option value="' . $k . '"' . ($k == $cc['field'] ? ' selected="selected"' : '') . '>' . $string . '</option>';
              }
              $fieldlist .= '
              </select>
              </div>
              <div class="form-item form-type-select form-item-options-conditions-condition first">
                <select id="edit-options-conditions-condition" name="options[conditions][' . $key . '][children][' . $ck . '][condition]" class="form-select">';

              $fieldlist .= $condition_list;
              
              $fieldlist .= '</select>
              </div>
              <div class="form-item form-type-textfield form-item-options-conditions-equalto">
                <input type="text" id="edit-options-conditions-equalto" name="options[conditions][' . $key . '][children][' . $ck . '][equals]" value="' . $cc['equals'] . '" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed" />
              </div>
              <div id="options" class="first">
                <a href="#" class="delete">Remove this</a>
              </div>
            </li>';
          }
          $fieldlist .= '</ul>';
        }
        $fieldlist .= '</li>';
      }
      $form['full_count'] = array('#markup' => '<script> var last_elm = ' . $last_elm . '; var condition_options = \'' . $condition_list . '\'; </script>');
    }

    $form['list'] = array('#markup' => '<a href="#" class="add-master" data-type="and">Add "And" field</a> | <a href="#" class="add-master" data-type="or">Add "or" field</a><ul id="conditions-container">' . $fieldlist . '</ul>');

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
    $conditions = &$values['conditions'];

    // Clean up false values.
    foreach ($conditions AS $key => $condition) {
      if ($condition['field'] == "0" && $condition['equals'] == '') {
        unset($conditions[$key]);
      }

      if (!empty($condition['children']) && is_array($condition['children'])) {
        foreach ($condition['children'] as $k => $child) {
          if ($child['field'] == "0" && $child['equals'] == '') {
            unset($conditions[$key]['children'][$k]);
          }
        }
      }
    }

    $form_state['values'] = array_replace_recursive($form_state['values'], $form_state['input']);
    /* 
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
    if (!empty($this->options['conditions'])) {
      $count = count($this->options['conditions']);
      foreach ($this->options['conditions'] as $condition) {
        if (empty($condition['children'])) {
          continue;
        }

        $count += count($condition['children']);
      }

      return t('If !n conditions pass, output !then, else output !else', array('!n' => $count, '!then' => $this->options['then'], '!else' => $this->options['or']));
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
        return ($r == $equals);
        break;

      // Not equal to.
      case 2:
        return ($r !== $equals);
        break;

      // Greater than.
      case 3:
        return ($r > $equals);
        break;

      // Less than.
      case 4:
        return ($r < $equals);
        break;

      // Empty.
      case 5:
        return empty($r);
        break;

      // Not empty.
      case 6:
        return !empty($r);
        break;

      // Contains.
      case 7:
        return (strpos($r, $equals) !== FALSE);
        break;

      // Does NOT contain.
      case 8:
        return (strpos($r, $equals) === FALSE);
        break;
    }
  }

  private function check_conditions($conditions, $children = false) {
    $needed_wins = $wins = 0;
    foreach ($conditions AS $key => $condition) {
      if ($condition['type'] == 'and') {
        $needed_wins++;
      }

      if ($this->passes($condition['field'], $condition['condition'], $condition['equals'])) {
        $wins++;
      }

      if (!empty($condition['children'])) {
        $ret = $this->check_conditions($condition['children'], true);
        $wins += $ret['wins'];
        $needed_wins += $ret['needed_wins'];
      }
    }

    if ($children) {
      return array(
        'wins' => $wins,
        'needed_wins' => $needed_wins
      );
    }
    else {
      return ($wins >= $needed_wins);
    }
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
