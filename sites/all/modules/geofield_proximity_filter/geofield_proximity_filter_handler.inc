<?php

class geofield_proximity_filter_handler extends SearchApiViewsHandlerFilter {
  // This is always single, because of the distance field's possible dependency
  // on it.
  var $no_single = TRUE;

  function option_definition() {
    $options = parent::option_definition();
    $options['identifier'] = array('default' => 'dist');
    $options['value'] = array(
      'default' => array(
        'address' => '',
        'radius' => 100,
        'search_units' => 'mile',
      ),
    );
    return $options;
  }

  function admin_summary() {
    return '';
  }

  function operator_options() {
    return array(
      'dist' => t('Proximity (Circular)'),
    );
  }
  
  function value_form(&$form, &$form_state) {
    
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        // We need to pretend the user already inputted the defaults, because
        // fapi will malfunction otherwise.
        $form_state['input'][$identifier] = $this->value;
      }
    }

    $form['value'] = array(
      '#tree' => TRUE,
    );

    $form['value']['address'] = array(
      '#type' => 'textfield',
      '#title' => t('Address'),
      '#default_value' => $this->value['address'],
      '#weight' => 2,
    );
    $form['value']['radius'] = array(
      '#type' => 'textfield',
      '#title' => t('Radius').' (miles)',
      '#default_value' => $this->value['radius'],
      '#weight' => 3,
    );
  }
  
  /**
   * (non-PHPdoc)
   * @see sites/all/modules/contrib/views/handlers/views_handler_filter::query()
   */
  function query() {
     if (empty($this->value)) {
      return;
    }

    $options = array_merge($this->options, $this->options['value'], $this->value);
	$address = $options[0]['address'];
  	$radius = floatval($options[0]['radius']) * 1.609344;
  	
  	if ($this->operator == 'dist') {
  	  $handler = geocode_get_handler('google');//calling this just to include the necessary files to use geocoding
  	  if($geometry = geocode_google($address)){
        $location = geofield_get_values_from_geometry($geometry);
        $this->query->setOption('geofilt', array('field' => $this->real_field, 'radius' => $radius, 'point' => array('lat' => $location['lat'], 'lon' => $location['lon'])));
  	  }
    }
  }
}