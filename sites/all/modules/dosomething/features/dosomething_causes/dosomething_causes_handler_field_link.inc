<?php

class dosomething_causes_handler_field_link extends views_handler_field_custom {
  function render($values) {
    // If we set a custom value, use that.
    if (!empty($values->dosomething_causes_link)) {
      $this->options['alter'] = array();
      return $values->dosomething_causes_link;
    }

    // Return the text, so the code never thinks the value is empty.
    return $this->options['alter']['text'];
  }
}
