<?php
// $Id$

/**
 * @file
 * Admin page callback for the Optimizely module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * If there are only 3 arguments in the path it builds the add form and it adds a record.
 * Otherwise it builds the update form where the fourth argument is the record ID in
 * in the optimizely table.
 */

function optimizely_add_update_form($form, &$form_submit) {

  $arg = check_plain(arg(4));
	if (!$arg) {
		$form_action = 'Add';	
  } else {
		$query = db_select('optimizely', 'op')
			->condition('op.oid', $arg, '=')
			->fields('op');		
		$result = $query->execute();
		$record = $result->fetch();
		
		$form['oid'] = array(
  	'#type' => 'value',
  	'#value' => $arg,  	
  	);
  	$form_action = 'Update';    	
  }	

  $form['introduction'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('In order to use this module, you need an <a href="@url">Optimizely</a> account. A Free 30 day trial account is available.',
                  array('@url' => url('http://www.optimizely.com/'))) . '</p><p>' .
                  t('Most of the configuration and setup for the A/B and other tests is done by logging into your account on the Optimizely website.') . '</p>',
  );
  
  $form['project_title'] = array(
  	'#type' => 'textfield',
  	'#title' => t('Optimizely Project Title'),
  	'#default_value' => arg(4) ? $record->project_title : '',
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
  );  	
  	
  $form['project_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Optimizely Project Code'),
    '#default_value' => arg(4) ? $record->project_code : '',
    '#description' => t('The Optimizely file name used in the snippet.'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['optimizely_onoff'] = array(
    '#type' => 'radios',
    '#title' => t('Show Optimizely snippet on specific pages'),
    //'#description' => t('To start using Optimizely, this setting must be enabled. This setting can be used to globally disable Optimizely from working on your site without disabling yours tests on the Optimizely website.'),
    '#default_value' => arg(4) ? $record->onoff : 'on',
    '#options' => array(
    	'on' => 'Only the listed pages',
      'off' => 'All pages except those listed',      
    ),
  );
  
    $form['enabled'] = array(
    '#type' => 'radios',
  	'#title' => t('Enable/Disable Project'),
  	'#default_value' => arg(4) ? $record->enabled : 0,
    '#options' => array(
    	1 => 'Enable project',
      0 => 'Disable project',      
    ),
  );

    $form['optimizely_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Set Path Where Optimizely Code Snippet Appears'),
    '#default_value' => arg(4) ? implode("\n", unserialize($record->path)) : '',
    '#description' => t('Enter the path where you want to insert the Optimizely Snippet.
    		Note: "clubs/*" causes the snippet to appear on all pages below "clubs/" but not
    		on the actual "clubs" page itself.'),
    '#cols' => 100,
    '#rows' => 6,
    '#resizable' => FALSE,
    '#required' => FALSE,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $form_action,
  );
  
  return $form;
}

/**
 * Menu callback. Enter the Optimizely ID number.
 */
function optimizely_setup_account_id($form_state) {
  $form['introduction'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('In order to use this module, you need an <a href="@url">Optimizely</a> account. A Free 30 day trial account is available.',
                  array('@url' => url('http://www.optimizely.com/'))) . '</p><p>' .
                  t('Most of the configuration and setup for the A/B and other tests is done by logging into your account on the Optimizely website.') . '</p><p>'.
                  t('The default Project js file (snippet) uses the account ID. If there\'s no entries in 
                  the <a href="@url">List Of Products</a> page this will be used as a default site wide.',
                  array('@url' => url('admin/config/system/optimizely/list'))) . '</p>',
  );

  $form['optimizely_onoff'] = array(
    '#type' => 'radios',
    '#title' => t('Show Optimizely snippet on specific pages'),
    '#default_value' => variable_get('optimizely_onoff', 'on'),
    '#options' => array(
      'on' => 'Only the listed pages',
      'off' => 'All pages except those listed',
    ),
  );

  $form['optimizely_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Optimizely ID Number'),
    '#default_value' => variable_get('optimizely_id', 'NONE'),
    '#description' => t('Your numeric account ID. This is the number after <q>/js/</q> in the Optimizely Tracking Code.'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}

/**
 * Menu callback. Displays a list of records in the Optimizely table.
 */
function optimizely_list_page() {

  // Begin building the query.
  $query = db_select('optimizely', 'op')
    ->extend('PagerDefault')
    ->orderBy('oid')
    ->fields('op')
    ->limit(10);
    
  // Fetch the result set.
  $result = $query->execute();


  foreach ($result as $row) {
    $rows[] = array(
      $row->project_title,
      l(t('Update'), 'admin/config/system/optimizely/' . $row->oid),
      l(t('Delete'), 'admin/config/system/optimizely/delete/' . $row->oid),
			$row->onoff,
      implode('<br />', unserialize($row->path)),
      $row->project_code,
      $row->enabled ? t('Enabled') : t('Disabled'),
    );
  }

  // Headers for theme_table().  
  $header = array('Project Title', 'Update', 'Delete','Only the Paths/Pages Listed', 'Paths/Pages', 'Project Code', 'Enabled');
  
  // Format output.
  $output = theme('table', array('header' => $header, 'rows' => $rows)) . theme('pager');

  return $output;

}


/**
 * Menu callback. Get confirm to delete a record from the Optimizely table.
 */
function optimizely_delete_page($form, &$form_state, $arg1) {
  return drupal_build_form('optimizely_delete_page_confirm',  &$form_state);
}


/**
 * Build a confirm form for deletion of record in Optimizely table.
 */
function optimizely_delete_page_confirm($form, &$form_state, $arg1) {
  $form['oid'] = array(
  	'#type' => 'value',
  	'#value' => $arg1,
  );
  $caption = '<p>' . t('This action cannot be undone.') . '</p>';
  $heading = t('Are you sure you want to delete this configuration?');
  $cancel_path = 'admin/config/system/optimizely/list';
  $yes = t('Delete');
  $no = t('Cancel');
  
  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);
}


/**
 * Submit function for the confirm deletion form.
 */
function optimizely_delete_page_confirm_submit($form, &$form_state) {
  $oid = $form_state['values']['oid'];
	$query = db_delete('optimizely')
		->condition('oid', $oid);  
  $query->execute();
	optimizely_flush_all_caches();
  drupal_goto('admin/config/system/optimizely/list'); 
}

/**
 * Either Adds or Updates a record from the setup form
 */
function optimizely_add_update_form_submit($form, &$form_state) {

	$project_title = check_plain($form_state['values']['project_title']);
	$project_code = check_plain($form_state['values']['project_code']);
	//$optimizely_path = check_plain($form_state['values']['optimizely_path']);
	$optimizely_path = $form_state['values']['optimizely_path'];
	$path_array = preg_split('/[\r\n]+/', $optimizely_path, -1, PREG_SPLIT_NO_EMPTY);
	$onoff = check_plain($form_state['values']['optimizely_onoff']);
	$enabled = check_plain($form_state['values']['enabled']);

  if ($form['submit']['#value'] == 'Add') {
		db_insert('optimizely')
			->fields(array(
				'project_title' => $project_title,
				'onoff' => $onoff,
				'path' => serialize($path_array),
				'project_code' => $project_code,
				'enabled' => $enabled,
			))
			->execute();
	} else if ($form['submit']['#value'] == 'Update') {
	
		$oid = $form_state['values']['oid'];
		db_update('optimizely')
			->fields(array(
				'project_title' => $project_title,
				'onoff' => $onoff,
				'path' => serialize($path_array),
				'project_code' => $project_code,
				'enabled' => $enabled,
			))
			->condition('oid', $oid)
			->execute();	
	}
	optimizely_flush_all_caches();
  drupal_goto('admin/config/system/optimizely/list');   
}

/**
 * Flushes all the caches.  Needed when updating, adding
 * and deleting projects. Without it, the Optimizely snippet
 * appear, or does not appear in the appropriate pages
 * when not logged in as an administrator.
 */
function optimizely_flush_all_caches()
{
  drupal_flush_all_caches();
  drupal_set_message('all caches flushed.');  
}

