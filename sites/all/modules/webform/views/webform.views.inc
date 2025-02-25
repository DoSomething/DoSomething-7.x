<?php

/**
 * @file
 * Views hooks implemented for the Webform module.
 */

function webform_views_data() {

  /**
   * Webform table definitions.
   */
  $data['webform']['table']['group'] = t('Webform');
  $data['webform']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
      'type' => 'INNER',
    ),
  );

  // status
  $data['webform']['status'] = array(
    'title' => t('Status'),
    'help' => t('The open or closed status of a webform.'),
    'field' => array(
      'handler' => 'webform_handler_field_webform_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'label' => t('Status'),
      'handler' => 'webform_handler_filter_webform_status',
      'type' => 'open-closed',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  /**
   * Submissions table definitions.
   */
  $data['webform_submissions']['table']['group'] = t('Webform submissions');
  $data['webform_submissions']['table']['base'] = array(
    'field' => 'sid',
    'title' => t('Webform submissions'),
    'help' => t('Submissions generated from Webform forms.'),
  );

  // SID.
  $data['webform_submissions']['sid'] = array(
    'title' => t('Sid'),
    'help' => t('The submission ID of the submission.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Sid'),
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Submission data as a field loads the entire submission.
  $data['webform_submissions']['value'] = array(
    'title' => t('Value'),
    'help' => t('The value of a component as submitted by a user.'),
    'real field' => 'sid',
    'group' => t('Webform submission data'),
    'field' => array(
      'handler' => 'webform_handler_field_submission_data',
    ),
  );

  // NID.
  $data['webform_submissions']['nid'] = array(
    'title' => t('Node'),
    'help' => t('The webform node this submission was generated from.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Webform Node'),
    ),
  );

  // UID.
  $data['webform_submissions']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user who sent the webform submission.'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Webform Submission User'),
    ),
  );

  // Is draft.
  $data['webform_submissions']['is_draft'] = array(
    'title' => t('Draft'),
    'help' => t('Whether or not the submission is a draft.'),
    'field' => array(
      'handler' => 'webform_handler_field_is_draft',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'webform_handler_filter_is_draft',
    ),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
  );

  // Submitted timestamp.
  $data['webform_submissions']['submitted'] = array(
    'title' => t('Submitted'),
    'help' => t('The date this submission was submitted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Submitted'),
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  // Add date module support, if present.
  if (module_exists('date')) {
    $data['webform_submissions']['submitted']['filter']['handler'] = 'date_views_filter_handler_simple';
  }

  // IP Address (remote_addr).
  $data['webform_submissions']['remote_addr'] = array(
    'title' => t('Remote address'),
    'help' => t('The remote IP address of the user that submitted this submission.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Remote address'),
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // View submission link.
  $data['webform_submissions']['view_submission'] = array(
    'field' => array(
      'title' => t('View link'),
      'help' => t('Provide a simple link to view the submission.'),
      'handler' => 'webform_handler_field_submission_link',
      'link_type' => 'view',
    ),
  );

  // Edit submission link.
  $data['webform_submissions']['edit_submission'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the submission.'),
      'handler' => 'webform_handler_field_submission_link',
      'link_type' => 'edit',
    ),
  );

  // Delete submission link.
  $data['webform_submissions']['delete_submission'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the submission.'),
      'handler' => 'webform_handler_field_submission_link',
      'link_type' => 'delete',
    ),
  );

  // Relation to webform_submitted_data table.
  $data['webform_submissions']['data'] = array(
    'title' => t('Data'),
    'help' => t('Relates to a webform submission data'),
    'real field' => 'sid',
    'relationship' => array(
      'handler' => 'webform_handler_relationship_submission_data',
      'base' => 'webform_submitted_data',
      'base field' => 'sid',
      'label' => t('Submission Data'),
    ),
  );

  /**
   * Submission data table definitions.
   */
  $data['webform_submitted_data']['table']['group'] = t('Webform submission data');

  // Raw access to the submitted values. This usually will only be used for
  // sorts and filters, since the 'value' field for the submission will often
  // be faster and easier to configure than the raw values.
  $data['webform_submitted_data']['data'] = array(
    'table' => 'webform_submitted_data',
    'title' => t('Data field'),
    'help' => t('The value of a component as submitted by a user.'),
    'real field' => 'data',
    'field' => array(
      'title' => t('Value (raw)'), // Distinguish from the normal value handler.
      'help' => t('The raw value from the database as submitted by a user. Use only when needing to sort on a field value.'),
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'webform_handler_filter_submission_data',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Number field for multi-value fields.
  $data['webform_submitted_data']['no'] = array(
    'title' => t('Value delta'),
    'help' => t('The delta value of the submitted data in a multi value component (such as checkboxes).'),
    'real field' => 'no',
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function webform_views_data_alter(&$data) {
  // Webform submission from node.
  $data['node']['webform_submission'] = array(
    'title' => t('Webform submission'),
    'help' => t('Webform submissions of the given Webform node.'),
    'real field' => 'nid',
    'relationship' => array(
      'base' => 'webform_submissions',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Webform Submission'),
    ),
  );
  $data['node']['table']['join']['webform_submissions'] = array(
    'field' => 'nid',
    'left_field' => 'nid',
    'left_table' => 'webform_submissions',
  );
  // Submission count (node).
  $data['node']['webform_submission_count_node'] = array(
    'group' => t('Webform'),
    'field' => array(
      'title' => t('Webform submission count'),
      'help' => t('The number of webform submissions on this node.'),
      'handler' => 'webform_handler_field_submission_count',
      'count_type' => 'node',
    ),
  );


  // Webform submission of user.
  $data['users']['webform_submission'] = array(
    'title' => t('Webform submission'),
    'help' => t('Webform submissions of the given user.'),
    'real field' => 'uid',
    'relationship' => array(
      'base' => 'webform_submissions',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Webform Submission'),
    ),
  );
  // Submission count (user).
  $data['users']['webform_submission_count_user'] = array(
    'field' => array(
      'title' => t('Webform submission count'),
      'help' => t('The number of webform submissions for this user.'),
      'handler' => 'webform_handler_field_submission_count',
      'count_type' => 'users',
    ),
  );

  // Link for editing the webform.
  $data['node']['webform_edit'] = array(
    'group' => t('Webform'),
    'field' => array(
      'title' => t('Webform edit link'),
      'help' => t('Provide a simple link to edit the webform components and configuration.'),
      'handler' => 'webform_handler_field_node_link_edit',
    ),
  );

  // Link for viewing webform results.
  $data['node']['webform_results'] = array(
    'group' => t('Webform'),
    'field' => array(
      'title' => t('Webform results link'),
      'help' => t('Provide a simple link to view the results of a webform.'),
      'handler' => 'webform_handler_field_node_link_results',
    ),
  );

  // Webform form content.
  $data['node']['webform_form_body'] = array(
    'group' => t('Webform'),
    'field' => array(
      'title' => t('Webform form body'),
      'help' => t('The Webform form body display for this node.'),
      'handler' => 'webform_handler_field_form_body',
    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function webform_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'webform') . '/views',
    ),
    'handlers' => array(
      'webform_handler_field_submission_link' => array(
        'parent' => 'views_handler_field',
        'file' => 'webform_handler_field_submission_link.inc',
      ),
      'webform_handler_field_submission_data' => array(
        'parent' => 'views_handler_field',
        'file' => 'webform_handler_field_submission_data.inc',
      ),
      'webform_handler_field_submission_count' => array(
        'parent' => 'views_handler_field',
        'file' => 'webform_handler_field_submission_count.inc',
      ),
      'webform_handler_field_node_link_edit' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'webform_handler_field_node_link_results' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'webform_handler_field_form_body' => array(
        'parent' => 'views_handler_field',
        'file' => 'webform_handler_field_form_body.inc',
      ),
      'webform_handler_field_is_draft' => array(
        'parent' => 'views_handler_field',
        'file' => 'webform_handler_field_is_draft.inc',
      ),
      'webform_handler_filter_is_draft' => array(
        'parent' => 'views_handler_filter_in_operator',
        'file' => 'webform_handler_filter_is_draft.inc',
      ),
      'webform_handler_field_webform_status' => array(
        'parent' => 'views_handler_field_boolean',
        'file' => 'webform_handler_field_webform_status.inc',
      ),
      'webform_handler_filter_webform_status' => array(
        'parent' => 'views_handler_filter_boolean_operator',
        'file' => 'webform_handler_filter_webform_status.inc',
      ),
      'webform_handler_relationship_submission_data' => array(
        'parent' => 'views_handler_relationship',
        'file' => 'webform_handler_relationship_submission_data.inc',
      ),
    ),
  );
}

/**
 * Menu callback; Provide a list of Webform nodes for use in autocomplete.
 */
function webform_views_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $or = db_or();

    // Strings with nid: in them can be used as direct matches.
    $matches = array();
    if (preg_match('/nid:([0-9]+)/', $string, $matches)) {
      $or->condition('n.nid', (int) $matches[1]);
    }
    // Otherwise match on title and optionally indirect NIDs.
    else {
      $or->condition('n.title', '%' . db_like($string) . '%', 'LIKE');
      if (is_numeric($string)) {
        $or->condition('n.nid', (int) $string);
      }
    }

    $options = array();
    $query = db_select('node', 'n')
      ->fields('n', array('nid', 'title'))
      ->condition($or);
    $query->innerJoin('webform', 'w', 'w.nid = n.nid');
    $result = $query
      ->range(0, 10)
      ->execute();
    foreach ($result as $node) {
      $options[$node->title . ' [nid:' . $node->nid . ']'] = check_plain($node->title) . ' [nid:' . $node->nid . ']';
    }
  }

  drupal_json_output($options);
}

/**
 * Shared form for the Webform submission data field and relationship handler.
 */
function _webform_views_options_form(&$form, &$form_state, $nid, $cid) {
  form_load_include($form_state, 'inc', 'webform', 'includes/webform.components');
  $node = $nid ? node_load($nid) : NULL;

  $form['webform_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform node'),
    '#default_value' => isset($node) ? $node->title . ' [nid:' . $node->nid . ']' : '',
    '#ajax' => array(
      'path' => views_ui_build_form_url($form_state),
      'event' => 'blur',
    ),
    '#autocomplete_path' => 'webform/autocomplete',
    '#description' => t('Enter the title or NID of the Webform whose values should be made available.'),
    '#submit' => array('views_ui_config_item_form_submit_temporary'),
    '#executes_submit_callback' => TRUE,
  );

  $components = array();
  if (isset($node->webform['components'])) {
    $components = $node->webform['components'];
  }

  $type_options = array();
  foreach (webform_components() as $key => $component) {
    $type_options[$key] = check_plain($component['label']);
  }

  $options = webform_component_list($node, NULL, TRUE , TRUE);
  $form['webform_cid'] = array(
    '#title' => t('Component data'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $cid,
    '#dependency' => array('edit-options-component-type' => array($type)),
    '#access' => count($components),
    '#description' => t('Select the component whose values should be made available.'),
  );
}

/**
 * Validate handler for webform_views_options_form().
 */
function _webform_views_options_validate(&$form, &$form_state) {
  // Just store the checked components of the selected type.
  if (empty($form_state['values']['options']['webform_nid'])) {
    form_error($form['webform_nid'], t('Webform NID is required.'));
  }
  else {
    $nid = preg_replace('/^.*?nid:([0-9]+).*?$/', '$1', $form_state['values']['options']['webform_nid']);
    if (!($nid && ($node = node_load($nid)) && !empty($node->webform['components']))) {
      form_error($form['webform_nid'], t('The specified node is not valid.'));
    }
  }
}

/**
 * Submit handler for webform_views_options_form().
 */
function _webform_views_options_submit(&$form, &$form_state) {
  // Save the NID as just the number instead of the title.
  $nid = preg_replace('/^.*?nid:([0-9]+).*?$/', '$1', $form_state['values']['options']['webform_nid']);
  $form_state['values']['options']['webform_nid'] = $nid;
}
