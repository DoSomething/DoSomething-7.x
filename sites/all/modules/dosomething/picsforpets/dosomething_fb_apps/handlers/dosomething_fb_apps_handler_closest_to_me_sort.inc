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

    // If a pet does not have a zipcode, get the zipcode from its shelter.
    // TODO, get zip for pets without shelter.

    $join = new views_join();

    $join->construct('field_data_field_pfp_address', $this->table_alias, $this->real_field, 'entity_id');

    $this->address_table = $this->query->ensure_table('shelter_address', $this->relationship, $join);
    $this->zip_field = $this->query->add_field($this->address_table, 'field_pfp_address_postal_code');


    // Get the lat/lon of the zipcode.
/*
    $this->query->addJoin('INNER', 'zipcodes', 'zipcodes', 'zip = ' . shelter_address.field_pfp_address_postal_code);

    $distance = (((ACOS(SIN(($lat * PI()/180)) * SIN((zipcodes.latitude * PI()/180)) + COS(($lat * PI()/180)) * COS((zipcodes.latitude * PI()/180)) * COS((($lon - zipcodes.longitude) * PI()/180)))) * 180/PI()) * 60 * 1.1515);

    $this->field_alias = $this->query->add_field(NULL, $distance, 'distance');
*/
    $this->query->add_orderby($this->address_table, 'field_pfp_address_postal_code', 'DESC');

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




/**
 * @}
 */
