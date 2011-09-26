<?php 
//Make fields that are of LatLonType use the proximity filter handler
function geofield_proximity_filter_views_data_alter(&$data){
  foreach (search_api_index_load_multiple(FALSE) as $index) {
    if(is_array($index->options['fields'])){
      foreach($index->options['fields'] as $field_name => $field){
        if($field['type'] == 'LatLonType'){
          $data['search_api_index_'. $index->machine_name][$field_name]['filter']['handler'] = 'geofield_proximity_filter_handler';
        }
      }
    }
  }
}