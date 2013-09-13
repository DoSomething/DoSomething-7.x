<?php

/**
 * @file
 * dosomething_reportback.views.inc
 *
 * Makes dosomething_reportbacks tables avaiable to Views.
 **/

/**
 * Implements hook_views_data().
 */
function dosomething_reportback_views_data() {

  // Define dosomething_reportbacks:
  $data['dosomething_reportbacks']['table']['group'] = t('Reportbacks');
  $data['dosomething_reportbacks']['table']['base'] = array(
    'field' => 'rbid',
    'title' => t('Reportbacks'),
    'help' => t('Dosomething Reportbacks table.'),
    'weight' => -10,
  );
  $data['dosomething_reportbacks']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  $data['dosomething_reportbacks']['nid'] = array(
    'title' => t('Reportback node nid'),
    'help' => t('Reportback node nid.'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Reportback Node Nid'),
      'title' => t('Reportback Node Nid'),
      'help' => t('The Node Nid the Reportback is for.'),
    ),
  );
  $data['dosomething_reportbacks']['data'] = array(
    'title' => t('Reportbacks Data'),
    'help' => t('Serialized Reportback Data.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['dosomething_reportbacks']['rbid'] = array(
    'title' => t('Reportback ID'),
    'help' => t('Reportback id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['dosomething_reportbacks']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('User id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users',
      'handler' => 'views_handler_relationship',
      'label' => t('Reportback Author'),
    ),
  );
  $data['dosomething_reportbacks']['timestamp'] = array(
    'title' => t('Date submitted'),
    'help' => t('Date submitted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Define dosomething_reportback_files:
  $data['dosomething_reportback_files']['table']['group'] = t('Reportbacks');
  $data['dosomething_reportback_files']['table']['base'] = array(
    'field' => 'rbid',
    'title' => t('Reportback Files'),
    'help' => t('Dosomething Reportback Files table.'),
    'weight' => -10,
  );
  $data['dosomething_reportback_files']['table']['join'] = array(
    'dosomething_reportbacks' => array(
      'left_field' => 'rbid',
      'field' => 'rbid',
    ),
    'file_managed' => array(
      'left_field' => 'fid',
      'field' => 'fid',
    ),
  );
  $data['dosomething_reportback_files']['rbid'] = array(
    'title' => t('Reportback Files Rbid'),
    'help' => t('Reportback Rbid that references a reportback.'),
    'relationship' => array(
      'base' => 'dosomething_reportbacks',
      'base field' => 'rbid',
      'handler' => 'views_handler_relationship',
      'label' => t('Reportback Rbid'),
      'title' => t('Reportback Rbid'),
      'help' => t('The Reportback Rbid the Reportback Files is for.'),
    ),
  );
  $data['dosomething_reportback_files']['fid'] = array(
    'title' => t('Reportback Image file id'),
    'help' => t('The id of the Reportback image file.'),
    'field' => array(
      'handler' => 'views_handler_field_file',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'file_managed',
      'handler' => 'views_handler_relationship',
      'label' => t('Reportback Image File'),
    ),
  );

  return $data;
}