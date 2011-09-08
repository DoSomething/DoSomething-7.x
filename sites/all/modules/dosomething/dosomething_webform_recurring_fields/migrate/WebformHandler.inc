<?php

/**
 * Migrate handler to provide fields for our custom webform tables.
 */
class MigrateDSWebformHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('WebformSubmission'));
  }

  public function fields($webform) {
    $fields = array();

    module_load_include('install', 'dosomething_webform_recurring_fields');
    $schema = dosomething_webform_recurring_fields_schema();
    $table = dosomething_recurring_fields_type_to_table($webform->type);
    foreach ($schema[$table]['fields'] as $name => $info) {
      $fields[$name] = $info['description'];
    }
    unset($fields['sid']);

    return $fields;
  }

  public function complete($entity, $source_row, $webform) {
    $all_fields = dosomething_webform_recurring_fields_get_fields();
    if (empty($all_fields[$webform->type])) {
      return;
    }

    $fields = array();
    foreach ($all_fields[$webform->type] as $name => $info) {
      if (!empty($entity->$name)) {
        $fields[$name] = $entity->$name;
      }
    }

    db_merge(dosomething_recurring_fields_type_to_table($webform->type))
      ->key(array('sid' => $entity->sid))
      ->fields($fields)
      ->execute();
  }
}