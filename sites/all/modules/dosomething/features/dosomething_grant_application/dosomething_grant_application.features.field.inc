<?php
/**
 * @file
 * dosomething_grant_application.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_grant_application_field_default_fields() {
  $fields = array();

  // Exported field: 'node-grant_application-body'.
  $fields['node-grant_application-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '-4',
      ),
    ),
  );

  // Exported field: 'node-grant_application-field_mailchimp_group_id'.
  $fields['node-grant_application-field_mailchimp_group_id'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mailchimp_group_id',
      'field_permissions' => array(
        'type' => '1',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mailchimp_group_id',
      'label' => 'Mailchimp Interest Group',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-grant_application-field_mc_optin'.
  $fields['node-grant_application-field_mc_optin'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mc_optin',
      'field_permissions' => array(
        'type' => '1',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mc_optin',
      'label' => 'Mobile Commons Opt-In Path',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '34',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_geocode_data'.
  $fields['webform_submission_entity-grant_application-field_geocode_data'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_geocode_data',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'geofield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_geocode_data',
      'label' => 'Geocode Data',
      'required' => 0,
      'settings' => array(
        'local_solr' => array(
          'enabled' => FALSE,
          'lat_field' => 'lat',
          'lng_field' => 'lng',
        ),
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'geocoder',
        'settings' => array(
          'geocoder_field' => array(
            'field_webform_address' => 'field_webform_address',
          ),
          'geocoder_handler' => 'google',
        ),
        'type' => 'geocoder',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_address'.
  $fields['webform_submission_entity-grant_application-field_webform_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_address',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addressfield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => array(
        0 => array(
          'element_key' => 'webform_submission_entity|grant_application|field_webform_address|und|0',
          'thoroughfare' => '',
          'premise' => '',
          'locality' => '',
          'administrative_area' => '',
          'postal_code' => '',
          'country' => 'US',
          'organisation_name' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_address',
      'label' => 'Address',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(
            'CA' => 'CA',
            'UM' => 'UM',
            'US' => 'US',
          ),
          'format_handlers' => array(
            'address' => 'address',
            'name-full' => 0,
            'name-oneline' => 0,
            'organisation' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_birthdate'.
  $fields['webform_submission_entity-grant_application-field_webform_birthdate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_birthdate',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'profile2_private' => FALSE,
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_birthdate',
      'label' => 'Birth Date',
      'required' => 1,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '1900:+0',
        ),
        'type' => 'date_select',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_email'.
  $fields['webform_submission_entity-grant_application-field_webform_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_email',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'email',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_email',
      'label' => 'Email',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_mobile'.
  $fields['webform_submission_entity-grant_application-field_webform_mobile'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_mobile',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '100',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_mobile',
      'label' => 'Mobile Phone Number',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_name'.
  $fields['webform_submission_entity-grant_application-field_webform_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_name',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_name',
      'label' => 'Name',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_project_dates'.
  $fields['webform_submission_entity-grant_application-field_webform_project_dates'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_project_dates',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'profile2_private' => FALSE,
        'timezone_db' => '',
        'todate' => 'optional',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'deleted' => '0',
      'description' => 'If your project is ongoing, feel free to leave the end date blank',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'value',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_project_dates',
      'label' => 'Project Dates',
      'required' => 1,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_project_submission'.
  $fields['webform_submission_entity-grant_application-field_webform_project_submission'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_project_submission',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'entityreference_entity_field',
        'handler_settings' => array(
          'author_only' => 0,
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'field_essay_build_it:value',
            'property' => 'sid',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'project_report' => 'project_report',
          ),
          'title_field' => 'field_project_title',
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'webform_submission_entity',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Start typing the Title of your DoSomething.org Project Posting',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => 1,
          ),
          'type' => 'entityreference_label',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_project_submission',
      'label' => 'Your DoSomething project posting',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_project_summary'.
  $fields['webform_submission_entity-grant_application-field_webform_project_summary'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_project_summary',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Tell us about your project in 1-2 sentences.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_project_summary',
      'label' => 'Project Summary',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_project_website'.
  $fields['webform_submission_entity-grant_application-field_webform_project_website'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_project_website',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'profile2_private' => FALSE,
        'title' => 'optional',
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Give us the full URL to your website, including the "http://" part (e.g. http://www.example.com).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'default',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_project_website',
      'label' => 'Personal project website URL',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_school'.
  $fields['webform_submission_entity-grant_application-field_webform_school'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_school',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_school',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'webform_submission_entity-grant_application-field_webform_school_reference'.
  $fields['webform_submission_entity-grant_application-field_webform_school_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_webform_school_reference',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'ds_school',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'none',
            'property' => 'sid',
            'type' => 'none',
          ),
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'ds_school',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'grant_application',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'webform_submission_entity',
      'field_name' => 'field_webform_school_reference',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
        'webform_entity' => array(
          'pid' => '0',
          'weight' => '',
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'dosomething_school',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'dosomething_school_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Birth Date');
  t('Body');
  t('Email');
  t('Geocode Data');
  t('Give us the full URL to your website, including the "http://" part (e.g. http://www.example.com).');
  t('If your project is ongoing, feel free to leave the end date blank');
  t('Mailchimp Interest Group');
  t('Mobile Commons Opt-In Path');
  t('Mobile Phone Number');
  t('Name');
  t('Personal project website URL');
  t('Project Dates');
  t('Project Summary');
  t('School');
  t('Start typing the Title of your DoSomething.org Project Posting');
  t('Tell us about your project in 1-2 sentences.');
  t('Your DoSomething project posting');

  return $fields;
}
