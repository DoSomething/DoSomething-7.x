<?php

/**
 * @file
 * Used for admin pages in dosomething_subscribe functionality. 
 **/

/**
 * Returns a system_settings_form used to set dosomething_subscribe variables.
 */
function dosomething_subscribe_admin_settings_form() {
  $form = array();
  // Prefix all variable names with dosomething_subscribe:
  $prefix = 'dosomething_subscribe_';
  $form['header'] = array(
    '#markup' => "<p>". t("Most forms have their Mailchimp and Mobilecommons values set on the node edit form.") . " " . l(t('View Subscription Report'), 'admin/reports/dosomething_subscribe') . "</p><p>" . t("These settings are for forms/nodes that don't.") . "</p>",
  );
  // Default values (for when none are set but email/cell is present):
  $form['defaults'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default Groups'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Default groups to use if none are specified on a node.'),
  );
  $form['defaults'][$prefix . 'mailchimp_default'] = array(
    '#type' => 'textfield',
    '#title' => t('MailChimp'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'mailchimp_default'),
  );
  $form['defaults'][$prefix . 'mobilecommons_default'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobilecommons'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'mobilecommons_default'),
  );
  // User registration values:
  $form['user_register'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Registration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Groups to use for user registration.'),
  );
  $form['user_register'][$prefix . 'mailchimp_user_register'] = array(
    '#type' => 'textfield',
    '#title' => t('MailChimp'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'mailchimp_user_register'),
  );
  $form['user_register'][$prefix . 'mobilecommons_user_register'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobilecommons'),
    '#required' => TRUE,
    '#default_value' => variable_get($prefix . 'mobilecommons_user_register'),
  );
  // Node types to use for User Profile signups:
  $form['signup_node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup Node Types'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Node types that should submit email and/or mobile data upon node and/or webform submission.'),
  );
  $form['signup_node_types'][$prefix . 'signup_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node types'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(array_keys(node_type_get_types())),
    '#default_value' => variable_get($prefix . 'signup_node_types'),
  );
  $form['signup_node_types'][$prefix . 'signup_user_profile_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('User Profile Signup Node types'),
    '#required' => FALSE,
    '#description' => t('Node types that should pull email/mobile from the User Profile if fields are not present.  Note: this list is populated from the Signup Node Types.'),
    '#options' => drupal_map_assoc(_dosomething_subscribe_get_signup_node_types()),
    '#default_value' => variable_get($prefix . 'signup_user_profile_node_types'),
  );
  return system_settings_form($form);
}

/**
 * dosomething_subscribe_page_status_report() - Page callback for Subcribe Status report. Report generates of all webforms and
 * what the MailChimp and Mobile Commons groups are assigned to the form.
 *
 * @param NONE
 *   
 * @return - call to dosomething_subscribe_forms_report template to generate report
 *   results as interactive table.
 */
function dosomething_subscribe_page_status_report() {
  
  // Add CSS to format table
  drupal_add_css(
    drupal_get_path('module', 'dosomething_subscribe') . '/css/dosomething_subscribe_admin.css',
    array('group' => CSS_DEFAULT, 'every_page' => FALSE));
  
  // Collect uptodate details about MailChimp groups
  list($MC_groupNames, $MC_currentGroup_subscribers, $MC_groupingIdByGroup_Subscribers) = dosomething_subscribe_mailchimp_group_info();
  
  // Respond to user input for column sorting
  if (isset($_GET['sort']) && isset($_GET['order'])) {
    
    // Sort it Ascending or Descending?
    if($_GET['sort'] == 'asc') {
      $sort = 'ASC';
    }
    else {
      $sort = 'DESC';
    }
 
    // Which column will be sorted
    switch($_GET['order']){
      
      case 'Title':
        $order = 'n.title';
        break;
      
      case 'Date':
        $order = 'n.changed';
        break;
      
      case 'Type':
        $order = 'west.type';
        break;
      
      case 'MailChimpGroup':
        $order = 'fdfmgi.field_mailchimp_group_id_value';
        break;
      
      case 'MobileGroup':
        $order = 'fdfmo.field_mc_optin_value';
        break;
      
      default:
        $order = 'n.title';
    }
    
  }
  else {
  
    // Default sort
    $sort = 'ASC';
    $order = ' n.title';
    
  }
  
  // Form name search
  $search = check_plain($_GET['search']);
  if ($search != '') {        
    $search_bits = explode('+', $search);
  }

  $query = db_select('webform_entity_submission_type', 'west');
  
  // Join webform_entity_submission_type table to node table to get general node details about
  // each webform_entity_submission_type entry
  $query->leftJoin('node', 'n', 'n.type = west.type');
  
  // MailChimp
  $query->leftJoin('field_data_field_mailchimp_group_id', 'fdfmgi', 'n.nid = fdfmgi.entity_id');
  
  // Mobile Commons
  $query->leftJoin('field_data_field_mc_optin', 'fdfmo', 'n.nid = fdfmo.entity_id');
  
  // Fields of interest in all joined tables
  $query->fields('n', array('nid', 'title', 'created', 'changed'))
        ->fields('west', array('type'))
        ->fields('fdfmgi', array('field_mailchimp_group_id_value'))
        ->fields('fdfmo', array('field_mc_optin_value'));
        
  // TO-DO - Add MailChimp Group lookup to confirm valid Group / Interest Group
  // assignment and to show number of email addresses assigned to group to indicate
  // activity.
  // http://apidocs.mailchimp.com/api/1.3/listinterestgroupings.func.php
  // listInterestGroupings(string apikey, string id)
        
  // Loop through title search words to create AND condition for target terms
  if (count($search_bits) > 1) {
    
    $db_or = db_or();
    foreach($search_bits as $search_bit => $search_bit_text) {
      $db_or->condition('n.title', '%'. $search_bit_text .'%', 'LIKE');
    }
    $query->condition($db_or);
    
  }
  elseif (isset($search_bits)) {
    $query->condition('n.title', '%'. $search .'%', 'LIKE');
  }
  
  // Sorting by column - dynamic based on user selection
  $query->orderBy($order, $sort);
  
  // Extra functionality for query - enable column sorting and pager
  $query = $query->extend('TableSort')
                 ->extend('PagerDefault')
                 ->limit(30);

  // Submit query for processing
  $results = $query->execute();
  
  $row_count = 0;
  
  // Build details on each entry for listing as table
  foreach ($results as $form_row) {
    
    $row_count++;
    
    // Date details in readable format
    $date_details = date('M j, Y', $form_row->created) .' / '.  date('M j, Y', $form_row->changed);
    
    // Check to see if MailChimp group ID setting is valid, highlight if not
    if ($form_row->field_mailchimp_group_id_value == NULL) {
      $cell['data'] = 'Undefined';
      $cell['class'] = 'warning';
    }
    elseif (in_array($form_row->field_mailchimp_group_id_value, $MC_groupNames) == FALSE) {
      $cell['data'] = $form_row->field_mailchimp_group_id_value;
      $cell['class'] = 'alert';
    } else {
      $cell['data'] = $form_row->field_mailchimp_group_id_value .' ('. $MC_currentGroup_subscribers[$form_row->field_mailchimp_group_id_value] . ' subscribers)';
      $cell['class'] = 'confirmed';
    }

    $rows[] = array(
      $form_row->title,
      $date_details,
      $form_row->type,
      $cell,
      $form_row->field_mc_optin_value, 
      l('Edit', 'node/' . $form_row->nid . '/edit'),
    );
    
  }
  
  // Prepare table header
  $header = array(
    array(
      'data' => t('Title'),
      'field' => 'n.title',
      'sort' => 'ASC',
    ),
    array(
      'data' => t('Date'),
      'field' => 'n.changed',
    ),
    array(
      'data' => t('Type'),
      'field' => 'west.type',
    ),
    array(
      'data' => t('MailChimpGroup'),
      'field' => 'fdfmgi.field_mailchimp_group_id_value',
    ),
    array(
      'data' => t('MobileGroup'),
      'field' => 'fdfmo.field_mc_optin_value',
    ),
    t('Edit'),
  );
  
  // Table theme options
  $forms_listing = theme('table', 
    array(
      "header" => $header,
      "rows" => $rows,
      "attributes" => array("width"=>"100%"),
      "sticky" => true, // Table header will be sticky
      "caption" => "",
      "colgroups" => array(),
      "empty" => t("No results found!") // The message to be displayed if table is empty
    )
  ).theme("pager");
  
  return theme('dosomething_subscribe_forms_report',
           array(
             'forms_listing' => $forms_listing,
           )
         );
}

/**
 * dosomething_subscribe_webform_search_form - FAPI definition of form elements for
 * search field on report page.
 * 
 * @return $form - array of form elements.
 */
function dosomething_subscribe_webform_search_form() {
  
  $search = check_plain($_GET['search']);
  $sort = check_plain($_GET['sort']);
  $order = check_plain($_GET['order']); 
  
  $form['dosomething_subscribe_webform_title_keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform Title Search'),
    '#default_value' => !empty($search) ? urldecode($search) : '',
    '#description' => t('Search webforms by title.'),
    '#size' => 35,
    '#maxlength' => 60,
    '#required' => FALSE,
  );
  
  $form['dosomething_subscribe_webform_sort']  = array(
    '#type' => 'value',
    '#value' => isset($sort) ? $sort : NULL ,
  );
  
  $form['dosomething_subscribe_webform_order']  = array(
    '#type' => 'value',
    '#value' => isset($order) ? $order : NULL,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );
  
  return $form;

}

/**
 * dosomething_subscribe_webform_search_form_submit() - Submit functionality for
 * search field on report page. 
 *
 * @param $form
 *   FAPI details for form
 *
 * @param &$form_state
 *   Current status of form elements on submission
 *   
 * @return - NONE
 */
function dosomething_subscribe_webform_search_form_submit($form, &$form_state) {
  
  $title_search = str_replace(' ', '+', $form['dosomething_subscribe_webform_title_keyword']['#value']);
  
  $parmaters = array(
    'search' => $title_search,
    'sort'   => $form['dosomething_subscribe_webform_sort']['#value'],
    'order'  => $form['dosomething_subscribe_webform_order']['#value'],
  );
  
  // Redirect back to form with search parameters
  drupal_goto('/admin/reports/dosomething_subscribe', array('query'=>$parmaters));
  
}