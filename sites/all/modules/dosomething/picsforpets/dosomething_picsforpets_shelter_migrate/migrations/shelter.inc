<?php

/**
 * @file
 *   Class for migrating shelters into PicsforPets app.
 */

class PFPShelterMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('pfp_shelter'));
    $this->description = t('Shelter import for picsforpets');
    $csv = drupal_get_path('module', 'dosomething_picsforpets_shelter_migrate') . '/data/shelters_to_import.csv';
    $this->source = new MigrateSourceCSV($csv, array(), array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('shelter');
    // Instantiate the MigrateMap
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple field mappings.
    $this->addFieldMapping('title', 'shelter_name');
    $this->addFieldMapping('field_pfp_hours', 'hours3');
    $this->addFieldMapping('field_pfp_contact_email_address', 'email');
  }

  public function prepareRow($row) {
    // Clear off extra spaces
    if (!empty($row->hours)) {
      while (strpos($row->hours, '  ') !== FALSE) {
        $row->hours = str_replace('  ', ' ', $row->hours);
        // If the first character is a space, cut it off.
        if (strpos(' ', $row->hours) === 0) {
          $row->hours = substr($row->hours, 1);
        }
      }
    }
    if (!empty($row->hours2)) {
      while (strpos($row->hours2, '  ') !== FALSE) {
        $row->hours2 = str_replace('  ', ' ', $row->hours2);
        // If the first character is a space, cut it off.
        if (strpos(' ', $row->hours2) === 0) {
          $row->hours2 = substr($row->hours2, 1);
        }
      }
    }
    $row->hours3 = !empty($row->hours2) ? $row->hours . "\n\n" . $row->hours2 : $row->hours;
  }

  public function prepare($node, stdClass $row) {
    // Just prep work we're not actually using this yet.
    $country = strlen($row->zip) == 5 ? 'US' : 'CA';

    // Prep tha address data.
    $address_info = array(
      'thoroughfare' => $row->address,
      'locality' => $row->city,
      'administrative_area' => $row->state,
      'postal_code'=> $row->zip,
      'country' => 'US',
    );
    // Set address data on the node.
    foreach ($address_info as $key => $value) {
      $node->field_pfp_address[LANGUAGE_NONE][0][$key] = $value;
    }
    // Set the link data on the node.
    $node->field_pfp_shelter_website[LANGUAGE_NONE][0]['url'] = $row->link_url;
    $node->field_pfp_shelter_website[LANGUAGE_NONE][0]['title'] = $row->link_title;

    // Phone number throws extra characters if it gets an empty string so just
    // don't set it if there is none.
    if (!empty($row->phone)) {
      $node->field_pfp_phone_number[LANGUAGE_NONE][0]['value'] = $row->phone;
    }
  }
}
