<?php
class GeofieldProximityFilterAlterLatlontype extends SearchApiAbstractAlterCallback {
  
  protected $field_options;
  
  public function alterItems(array &$items){
  
  }
  
  public function supportsIndex(SearchApiIndex $index) {
    return (bool) $this->getGeofieldFields();
  }
  
  private function getGeofieldFields(){
    if (!isset($this->field_options)) {
      $this->field_options = array();
      $wrapper = $this->index->entityWrapper(NULL, FALSE);
      
      foreach ($wrapper as $key => $child) {
        $info = $child->info();        
        if ($info['getter callback'] == 'geofield_entity_metadata_field_getter') {
          $this->field_options[$key] = $info['label'];
        }
      }
    }

    return $this->field_options;
  }
  /**
   * Display a form for configuring this callback.
   *
   * @return array
   *   A form array for configuring this callback, or FALSE if no configuration
   *   is possible.
   */
  public function configurationForm() {
    $options = $this->getGeofieldFields();
    $this->options += array('fields' => array());
    $form['fields'] = array(
      '#title' => t('Geofields'),
      '#description' => t('Select the geofields you wish to store in Solr as LatLonType'),
      '#type' => 'select',
      '#multiple' => TRUE,
      '#options' => $options,
      '#default_value' => $this->options['fields'],
    );

    return $form;
  }

  /**
   * Submit callback for the form returned by configurationForm().
   *
   * This method should both return the new options and set them internally.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   *
   * @return array
   *   The new options array for this callback.
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    // Change the saved type of fields in the index, if necessary.
    $fields = &$this->index->options['fields'];
    $geofields = $this->getGeofieldFields();
    foreach($geofields as $fieldname => $fieldlabel){
      if(!empty($values['fields'][$fieldname])){
         $fields[$fieldname]['type'] = 'LatLonType';
      }
      else{
        $fields[$fieldname]['type'] = 'string';
      }
    }
      
    $this->index->save();

    return parent::configurationFormSubmit($form, $values, $form_state);
  }
}
