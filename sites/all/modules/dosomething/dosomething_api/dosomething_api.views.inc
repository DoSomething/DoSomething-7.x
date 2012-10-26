<?php

/**
 * Implements hook_views_data()
 */
function dosomething_api_views_data() {
  $data = array();
  $data['field_data_field_club_zip']['nearby'] = array(
    'title' => t('Nearby'), // The item it appears as on the UI,
    'real field' => 'field_data_field_club_zip',
    'help' => t('Finds clubs near a particular zip code.'), // The help that appears on the UI,
    'sort' => array(
      'handler' => 'dosomething_api_handler_nearby_sort',
    ),
  );

  return $data;
}
