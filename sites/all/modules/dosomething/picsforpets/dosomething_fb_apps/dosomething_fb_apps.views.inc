<?php

/**
 * Implements hook_views_data_alter().
 */
function dosomething_fb_apps_views_data_alter(&$data) {
 dsm($data);
 $data['field_data_field_pfp_animal_types']['field_pfp_animal_types_value']['filter']['handler'] = 'views_handler_filter_field_list';
}
