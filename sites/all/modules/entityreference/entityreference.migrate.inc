<?php

/**
 * @file
 * Support for processing entity reference fields in Migrate.
 */

class MigrateEntityReferenceFieldHandler extends MigrateFieldHandler {
  public function __construct() {
    $this->registerTypes(array('entityreference'));
  }

  public function prepare(stdClass $entity, array $field_info, array $instance, array $values) {
    $arguments = (isset($values['arguments'])) ? $values['arguments'] : array();
    unset($values['arguments']);
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach (array_filter($values) as $value) {
      $return[$language][$delta]['target_id'] = $value;
      if (isset($arguments['type'])) {
        $return[$language][$delta]['target_type'] = $arguments['type'];
      }
      $delta++;
    }

    return isset($return) ? $return : NULL;
  }
}
