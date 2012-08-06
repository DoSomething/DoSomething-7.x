<?php

/**
 * Implements hook_views_data()
 */
function dosomething_fb_apps_views_data() {

  $data['webform_submissions']['submitted_asc'] = array(
    'title' => t('Oldest'),
    'real field' => 'submitted',
    'help' => t('Oldest webform submission.'), // The help that appears on the UI,
    'sort' => array(
      'handler' => 'dosomething_fb_apps_handler_oldest_sort',
    ),
  );

  $data['field_data_field_fb_app_share_count']['table']['group'] = t('dosomething_fb_app');

  $data['field_data_field_fb_app_share_count']['least_shared'] = array(
    'title' => t('Least Shared'), // The item it appears as on the UI,
    'real field' => 'field_fb_app_share_count_value',
    'help' => t('Least shared submissions on fb.'), // The help that appears on the UI,
    'sort' => array(
      'handler' => 'dosomething_fb_apps_handler_least_shared_sort',
    ),
  );

  return $data;
}
