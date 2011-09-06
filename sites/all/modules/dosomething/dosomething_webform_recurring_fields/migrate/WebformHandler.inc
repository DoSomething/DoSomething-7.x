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
    switch (dosomething_recurring_fields_type_to_table($webform->type)) {
      case 'ds_webform_campaign_su':
        $fields['name'] = 'Name';
        $fields['email'] = 'Email Address';
        $fields['mobile'] = 'Mobile phone number';
        $fields['zip'] = 'Zip code';
        break;

      case 'ds_webform_grant_app':
        $fields['name'] = 'Name';
        $fields['email'] = 'Email Address';
        $fields['school'] = 'School/Drive Name';
        $fields['mobile'] = 'Mobile phone number';
        $fields['zip'] = 'Zip code';
        break;

      case 'ds_webform_scholarship_app':
      case 'ds_webform_campaign_rb':
        $fields['name'] = 'Name';
        break;
    }
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