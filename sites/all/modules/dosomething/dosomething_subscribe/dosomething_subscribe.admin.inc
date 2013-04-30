<?php

/**
 * @file
 * Used for admin pages in dosomething_subscribe functionality. 
 **/

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