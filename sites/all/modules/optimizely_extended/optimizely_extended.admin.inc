<?php
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

function optimizely_extended_add_update_form($form, &$form_submit, $vars = NULL) {
	// Target oeid
	$target_oeid = $vars;

	if (!$target_oeid) {
		$form_action = 'Add';
		$form['optimizely_extended_oeid'] = array(
  	'#type' => 'value',
  	'#value' => NULL,  	
  	);	
  } else {
		$query = db_select('optimizely_extended', 'oe')
			->condition('oe.oeid', $target_oeid, '=')
			->fields('oe');		
		$result = $query->execute();
		$record = $result->fetch();
		
		$form['optimizely_extended_oeid'] = array(
  	'#type' => 'value',
  	'#value' => $target_oeid,  	
  	);
  	$form_action = 'Update';    	
  }	

	// @todo: move text content to template file (tpl)
  $form['optimizely_extended_introduction'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('In order to use this module, you need an <a href="@url">Optimizely</a> account. A Free 30 day trial account is available.',
                  array('@url' => url('http://www.optimizely.com/'))) . '</p><p>' .
                  t('Most of the configuration and setup for the A/B and other tests is done by logging into your account on the Optimizely website.') . '</p>',
		'#weight' => 0,
  );
	
	// If we are updating the default record, make the form element inaccessible
	$form['optimizely_extended_project_title'] = array(
		'#type' => 'textfield',
		'#access' => $target_oeid == 1 ? FALSE : TRUE,
		'#title' => t('Project Title'),
		'#default_value' => $target_oeid ? $record->project_title : '',
		'#size' => 60,
		'#maxlength' => 256,
		'#required' => TRUE,
		'#weight' => 10,
	);  	
			
	$form['optimizely_extended_project_code'] = array(
		'#type' => 'textfield',
		'#access' => $target_oeid == 1 ? FALSE : TRUE,
		'#title' => t('Optimizely Project Code'),
		'#default_value' => $target_oeid ? $record->project_code : '',
		'#description' => t('The Optimizely file name used in the snippet.'),
		'#size' => 30,
		'#maxlength' => 100,
		'#required' => TRUE,
		'#weight' => 20,
	);
	
	$form['optimizely_extended_include'] = array(
		'#type' => 'radios',
		'#access' => $target_oeid == 1 ? FALSE : TRUE,
		'#title' => t('Include/Exclude Optimizely Snippet on specific pages or paths.'),
		'#description' => t('Include/Exclude Optimizely snippet / javascript on specific pages or paths. The use of wildcards ("*") and "<front>" is supported.'),
		'#default_value' => $target_oeid ? $record->include : 0,
		'#options' => array(
			1 => 'Only the listed pages',
			0 => 'All pages except those listed',      
		),
		'#weight' => 30,
	);
		
	$form['optimizely_extended_path'] = array(
		'#type' => 'textarea',
		'#access' => $target_oeid == 1 ? FALSE : TRUE,
		'#title' => t('Set Path Where Optimizely Code Snippet Appears'),
		'#default_value' => $target_oeid ? implode("\n", unserialize($record->path)) : '',
		'#description' => t('Enter the path where you want to insert the Optimizely Snippet.
				For Example: "/clubs/*" causes the snippet to appear on all pages below "/clubs" in the URL but not
				on the actual "/clubs" page itself.'),
		'#cols' => 100,
		'#rows' => 6,
		'#resizable' => FALSE,
		'#required' => FALSE,
		'#weight' => 50,
	);	

  $form['optimizely_extended_enabled'] = array(
    '#type' => 'radios',
  	'#title' => t('Enable/Disable Project'),
  	'#default_value' => $target_oeid ? $record->enabled : 0,
    '#options' => array(
    	1 => 'Enable project',
      0 => 'Disable project',      
    ),
		'#weight' => 40,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $form_action,
		'#weight' => 100,
  );
  
  return $form;

}

/**
 * Process form submissions form optimizely_add_update_form().
 *
 * Either "Add"s or "Update"s a record from the optimizely_add_update_form() form. 
 */
function optimizely_extended_add_update_form_submit($form, &$form_state) {

  // Catch form submitted values and prep for processing
	$oeid = $form_state['values']['optimizely_extended_oeid'];
	
	$project_title = check_plain($form_state['values']['optimizely_extended_project_title']);
	$project_code = check_plain($form_state['values']['optimizely_extended_project_code']);

	// @totdo - Add support for "<front>" to allow use of check_plain() on ['optimizely_path']
	//$optimizely_path = check_plain($form_state['values']['optimizely_path']);
	$optimizely_path = $form_state['values']['optimizely_extended_path'];
	$path_array = preg_split('/[\r\n]+/', $optimizely_path, -1, PREG_SPLIT_NO_EMPTY);
	$include = check_plain($form_state['values']['optimizely_extended_include']);
	$enabled = check_plain($form_state['values']['optimizely_extended_enabled']);
	
	//$oeid = $form_state['values']['optimizely_extended_oeid'];
	// Process add or edit submission
	// No ID value included in submission - add new entry
  if (!isset($oeid))  {
		
		db_insert('optimizely_extended')
			->fields(array(
				'project_title' => $project_title,
				'include' => $include,
				'path' => serialize($path_array),
				'project_code' => $project_code,
				'enabled' => $enabled,
			))
			->execute();
			
	} // $oeid is set, update exsisting entry
	else {
			
		db_update('optimizely_extended')
			->fields(array(
				'project_title' => $project_title,
				 'include' => $include,
				'path' => serialize($path_array),
				'project_code' => $project_code,
				'enabled' => $enabled,
			))
			->condition('oeid', $oeid)
			->execute();
			
	}

	// Flush cache for all paths in project entry
	
	/*
	 * function custom_clear_front_page_cache() {
	 *   $front = variable_get('site_frontpage','node');
	 *   $url = url($front, NULL, NULL, TRUE);
	 *   cache_clear_all($url, 'cache_page');
	 *   $url = preg_replace("%$front$%", '', $url);
	 *   cache_clear_all($url, 'cache_page', FALSE);
	 * }
	 */
	
	// $path = flush_page_cache_get_path();
  // $url = flush_page_cache_get_url();
	
	/*
	 * function flush_page_cache_get_path() {
	 *   return parse_url(request_uri(), PHP_URL_PATH);
	 * }
	 */
	
	/*
	 * function flush_page_cache_get_url() {
	 *   $protocol = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on') ? 'https' : 'http';
	 *   return $protocol .'://'. $_SERVER['HTTP_HOST'] . flush_page_cache_get_path();
	 * }
	 */
	
	/*
	 * cache_clear_all($cid = NULL, $bin = NULL, $wildcard = FALSE)
	 *
	 *   $cid: If set, the cache ID to delete. Otherwise, all cache entries that can expire are deleted.
	 *
	 *   $bin: If set, the cache bin to delete from. Mandatory argument if $cid is set.
	 *
	 *   $wildcard: If TRUE, cache IDs starting with $cid are deleted in addition to the exact cache ID
	 *     specified by $cid. If $wildcard is TRUE and $cid is '*', the entire cache bin is emptied.
	 */

	foreach($path_array as $path) {
		cache_clear_all($path, 'cache_page', FALSE);
		// OR
		// cache_clear_all($url, 'cache_page');
	}
	
	// Varnish
  if (module_exists('varnish')) {
    varnish_expire_cache(array($path));
    drupal_set_message(t('Successfully purged this cached page from Varnish.'));
  }

  
	// Return to project listing page
  drupal_goto('admin/config/system/optimizely_extended');
	
}

/**
 * Menu callback. Enter the Optimizely ID number.
 */
function optimizely_extended_setup_account_settings_form($form_state) {
	
	// @todo: Move markup to template
	
  $form['optimizely_extended_introduction'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('In order to use this module, you need an <a href="@url">Optimizely</a> account. A Free 30 day trial account is available.',
                  array('@url' => url('http://www.optimizely.com/'))) . '</p><p>' .
                  t('Most of the configuration and setup for the A/B and other tests is done by logging into your account on the Optimizely website.') .
									'</p><p>'. t('The default Project js file (snippet) uses the Optimizely account ID. If there are no entries in the <a href="@url">Project
									Listing</a> page the ID will be used as a default value for the Optimizely javascript file site wide.</p>',
                  array('@url' => url('/admin/config/system/optimizely_extended'))));

  $form['optimizely_extended_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Optimizely ID Number'),
    '#default_value' => variable_get('optimizely_extended_id', ''),
    '#description' => t('Your Optimizely account ID. This is the number after <q>/js/</q> in the Optimizely Tracking Code that\'s applied to the web pages of the site.'),
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  
  return $form;
  
}

/**
 * Validation for optimizely_extended_setup_account_settings_form form
 */
function optimizely_extended_setup_account_settings_form_validate($form, &$form_state) {
  if (!preg_match('/^\d+$/', $form_state['values']['optimizely_extended_id'])) {
    form_set_error('optimizely_extended_id', t('Your Optimizely ID should be numeric.'));
  }
}

/**
 * Process submisison from optimizely_extended_setup_account_settings_form form. This includes saving the
 * entered Optimizely account ID to the varable database table, updating the default optimizely_extended (oeid)
 * record with the project ID which is also the account ID.
 */
function optimizely_extended_setup_account_settings_form_submit($form, &$form_state) {
	
	// Write the variable table
	variable_set('optimizely_extended_id', $form_state['values']['optimizely_extended_id']);
  
  // Update the default project / experiement entry with the account ID value
	db_update('optimizely_extended')
	  ->fields(array(
				'project_code' => $form_state['values']['optimizely_extended_id'],
			))
		->condition('oeid', '1')
		->execute();
	  
  // Inform the administrator that the default project / experiement entry is ready to be enabled.
	drupal_set_message('The default project entry is now ready to be enabled. This will apply the default Optimizely project tests site wide.', 'status');
	
	// Redirect back
	drupal_goto('admin/config/system/optimizely_extended');
  
}

/**
 * Menu callback. Displays a list of records in the Optimizely table.
 */
function optimizely_extended_list_page() {
	
	// Load css file specific to listing
	drupal_add_css(drupal_get_path('module', 'optimizely_extended') . '/css/optimizely_extended.css');
	
	$output = '<ul>
	             <li><a href="/admin/config/system/optimizely_extended/add_update">Add Project Entry</a></li>
						 </ul>';

  // Begin building the query.
  $query = db_select('optimizely_extended', 'oe')
    ->extend('PagerDefault')
    ->orderBy('oeid')
    ->fields('oe')
    ->limit(10);
    
  // Fetch the result set.
  $result = $query->execute();

  foreach ($result as $row) {
		
		// Delete link
	  if ($row->oeid != 1) {
			$edit_link = l(t('Update'), 'admin/config/system/optimizely_extended/add_update/' . $row->oeid);
		  $delete_link = ' / '. l(t('Delete'), 'admin/config/system/optimizely_extended/delete/' . $row->oeid);
			$default_entry_class = '';
	  }
	  else {
			$edit_link = l(t('Update'), 'admin/config/system/optimizely_extended/add_update/' . $row->oeid);
		  $delete_link = ' / '. 'Default Entry';
			$default_entry_class = ' default-entry';
	  }
		
    $rows[] = array(
			          array(
									'data' => $row->project_title,
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),
								array(
									'data' => $edit_link . $delete_link,
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),
								array(
									'data' => $row->include ? t('Include Paths') : t('Exclude Paths'),
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),
								array(
									'data' => implode('<br />', unserialize($row->path)),
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),
								array(
									'data' => ($row->project_code != 0) ? $row->project_code : t('Set <strong>') . l(t('Optimizely account ID'), 'admin/config/system/optimizely_extended/settings') . t('</strong> to enable default project site wide.'),
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),
								array(
									'data' => $row->enabled ? t('Enabled') : l(t('Disabled'), 'admin/config/system/optimizely_extended/add_update/' . $row->oeid),
									'class' => $row->enabled ? 'enabled' . $default_entry_class : 'disabled' . $default_entry_class,
								),

              );
  }

  // Headers for theme_table().  
  $header = array('Project Title', 'Update / Delete', 'Include / Exclude', 'Paths', 'Project Code', 'Enabled');
  
  // Format output.
  $output .= theme('table', array('header' => $header, 'rows' => $rows)) . theme('pager');

  return $output;

}

/**
 * Menu callback. Get confirm to delete a record from the Optimizely table.
 */
function optimizely_extended_delete_page($form, &$form_state, $vars = NULL) {
  return drupal_build_form('optimizely_extended_delete_page_confirm', &$form_state);
}

/**
 * Build a confirm form for deletion of record in Optimizely table.
 */
function optimizely_extended_delete_page_confirm($form, &$form_state, $vars = NULL) {
  $form['oeid'] = array(
  	'#type' => 'value',
  	'#value' => $vars,
  );
  
  $heading = t('Delete');
	$caption  = '<p>' .t('Are you sure you want to delete this configuration?') . '</p>';
	$caption .= '<p>' . t('This action cannot be undone.') . '</p>';
  $cancel_path = 'admin/config/system/optimizely_extended';
  $yes = t('Delete');
  $no = t('Cancel');
  
  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);
}


/**
 * Submit function for the confirm deletion form.
 */
function optimizely_extended_delete_page_confirm_submit($form, &$form_state) {
  $oeid = $form_state['values']['oeid'];
	$query = db_delete('optimizely_extended')
		->condition('oeid', $oeid);  
  $query->execute();
  
  drupal_goto('admin/config/system/optimizely_extended'); 
}