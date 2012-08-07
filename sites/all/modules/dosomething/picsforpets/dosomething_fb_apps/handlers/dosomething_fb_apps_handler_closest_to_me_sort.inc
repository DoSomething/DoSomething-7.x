<?php
/**
 * @defgroup views_sort_handlers Views' sort handlers
 * @{
 * Handlers to tell Views how to sort queries
 */

/**
 * Base sort handler that has no options and performs a simple sort
 */
class dosomething_fb_apps_handler_closest_to_me_sort extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->ensure_my_table();

    // TODO: get the user's location

    $lat = 39.95;
    $lon = -75.16;

    // Get zipcode from pet shelter.

    $join = new views_join();

    $join->construct('field_data_field_pfp_address', $this->table_alias, $this->real_field, 'entity_id');

    $this->address_table = $this->query->ensure_table('shelter_address', $this->relationship, $join);
    $this->shelter_zip_field = $this->query->add_field($this->address_table, 'field_pfp_address_postal_code');

    // Get zip from pet.


    // Set the zip field to either the shelter zip or the pet zip.
    // TODO: Join the webform submission zip field.
    $zip_field = "IF(field_pfp_address_postal_code IS NULL, '90210', field_pfp_address_postal_code)";


    // Get the lat/lon of the zipcode.

    $zip_join = new views_join();

    $zip_join->construct('zipcodes', NULL, $zip_field, 'zip');

    $this->zip_table = $this->query->add_relationship('zipcodes', $zip_join, $this->address_table);

    $this->lat_field = $this->query->add_field($this->zip_table, 'latitude');
    $this->lon_field = $this->query->add_field($this->zip_table, 'longitude');

    // Order by the distance.

    $distance = (((ACOS(SIN(($lat * PI()/180)) * SIN(($this->lat_field * PI()/180)) + COS(($lat * PI()/180)) * COS(($this->lat_field * PI()/180)) * COS((($lon - $this->lon_field) * PI()/180)))) * 180/PI()) * 60 * 1.1515);

    $this->field_alias = $this->query->add_field(NULL, $distance, 'distance');

    $this->query->add_orderby(NULL, NULL, 'DESC', 'distance');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['exposed'] = array('default' => FALSE);
    $options['expose'] = array(
      'contains' => array(
        'label' => array('default' => '', 'translatable' => TRUE),
      ),
    );
    return $options;
  }
}
