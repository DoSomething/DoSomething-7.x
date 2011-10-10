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
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
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
      if (!empty($values->nid)) {
        $url = url('node/' . $values->nid, $options = array('absolute' => TRUE));
      }
      else {
        $url = NULL;
      }
      $value = dosomething_blocks_social_node_plugins($url);
    }

    return $value;
  }
}
