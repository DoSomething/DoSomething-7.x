<?php

/**
 * @file
 * Views integration for Facebook user shares.
 */

/**
 * Implements hook_views_data().
 */
function fb_user_shares_views_data() {
  $data = array();

  // Label for Views UI.
  $data['fb_user_shares']['table']['group'] = t('Facebook user shares');

  // Define the base table.
  $data['fb_user_shares']['table']['base'] = array(
    'field' => 'sid',
    'title' => t('Facebook user shares'),
    'help' => t("Stores metadata for Facebook user shares of Drupal entities."),
  );

  // Expose the fields.
  $data['fb_user_shares']['sid'] = array(
    'title' => t('Share ID'),
    'help' => t('Unique Facebook user share ID.'),
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

  $data['fb_user_shares']['fb_user_id'] = array(
    'title' => t('Facebook user ID'),
    'help' => t('Facebook user ID.'),
    // Currently this schema field is a varchar due to length issues, so treat
    // this as a string.
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

  $data['fb_user_shares']['entity_type'] = array(
    'title' => t('Entity type'),
    'help' => t('The entity type this data is attached to.'),
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

  $data['fb_user_shares']['entity_id'] = array(
    'title' => t('Entity id'),
    'help' => t('The id of the entity being shared.'),
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

  $data['fb_user_shares']['system_path'] = array(
    'title' => t('System path'),
    'help' => t('The source path to redirect from.'),
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

  $data['fb_user_shares']['created'] = array(
    'title' => t('Created'),
    'help' => t('The Unix timestamp when the share was created.'),
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

  return $data;
}
