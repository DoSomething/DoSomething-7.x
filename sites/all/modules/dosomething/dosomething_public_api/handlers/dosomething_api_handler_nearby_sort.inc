<?php
/**
 * @defgroup views_sort_handlers Views' sort handlers
 * @{
 * Handlers to tell Views how to sort queries
 */

/**
 * Base sort handler that has no options and performs a simple sort
 */
class dosomething_api_handler_nearby_sort extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    global $user;
    $fbid = fboauth_fbid_load($user->uid);
    $fb_zip = db_query('SELECT zip FROM {ds_fb_user_zips} WHERE fbid = :fbid', array('fbid' => $fbid))->fetchField();
    $user->fb_zip = $fb_zip;
    if (isset($_GET['zip'])) {
      $fb_zip = $_GET['zip'];
    }

    $this->ensure_my_table();

    // We set a default Lat and Lon for sorting.
    $lat = 39.95;
    $lon = -75.16;
    // Fetch the user's lat and lon and override the default.
    if ($fb_zip) {
      // Clean the zipcode
      dosomething_picsforpets_shelters_clean_zip($fb_zip);
      $latlon = db_query_range('SELECT latitude, longitude FROM {zipcodes} WHERE zip = :zip', 0, 1, array(':zip' => $fb_zip))->fetchAssoc();
      if ($latlon) {
        $lat = $latlon['latitude'];
        $lon = $latlon['longitude'];
      }
    }

    // Get zip from pet shelter.
    // Not every pet has an associated shelter. In order to work around this we
    // actually look up the lat and lon for the shelters based on the animal.
    $join = new views_join();
    $join->construct('field_data_field_pfp_address', $this->table_alias, $this->real_field, 'entity_id');
    $this->address_table = $this->query->ensure_table('shelter_address', $this->relationship, $join);
    $this->shelter_zip_field = $this->query->add_field($this->address_table, 'field_pfp_address_postal_code');

    // Get zip from pet.

    $join2 = new views_join();
    $join2->construct('field_data_field_fb_app_zip', 'webform_submissions', 'sid', 'entity_id');
    $this->query->ensure_table('field_data_field_fb_app_zip');

    // Get the lat/lon of the zipcode in each case.

    $join = new views_join();
    $join->construct('zipcodes', 'field_data_field_fb_app_zip', 'field_fb_app_zip_value', 'zip');
    $this->zip_table = $this->query->add_relationship('zipcodes', $join, 'field_data_field_fb_app_zip');
    $this->lat_field2 = $this->query->add_field($this->zip_table, 'latitude');
    $this->lon_field2 = $this->query->add_field($this->zip_table, 'longitude');

    $join = new views_join();
    $join->construct('zipcodes', 'shelter_address', 'field_pfp_address_postal_code', 'zip');
    $this->zip_table2 = $this->query->add_relationship('zipcodes2', $join, 'field_data_field_pfp_address');
    $this->lat_field = $this->query->add_field($this->zip_table2, 'latitude', 'lat2');
    $this->lon_field = $this->query->add_field($this->zip_table2, 'longitude', 'lon2');

    // Get the non-null lat/lon

    $lat_field = "GREATEST(ifnull(zipcodes2.latitude, zipcodes.latitude), ifnull(zipcodes.latitude, zipcodes2.latitude))";
    $lon_field = "GREATEST(ifnull(zipcodes2.longitude, zipcodes.longitude), ifnull(zipcodes.longitude, zipcodes2.longitude))";

    // Order by the distance.

    $this->query->add_orderby(NULL, "coalesce((((ACOS(SIN(($lat * PI()/180)) * SIN(($lat_field * PI()/180)) + COS(($lat * PI()/180)) * COS(($lat_field * PI()/180)) * COS((($lon - $lon_field) * PI()/180)))) * 180/PI()) * 60 * 1.1515), 100000000000)", 'ASC', 'distance');
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
