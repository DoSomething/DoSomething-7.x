<?php
/**
 * @file
 * Admin page callback for the Optimizely module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * 
 * If there are only three arguments in the path it builds the add form and
 * adds a record. Otherwise it builds the update form where the fourth
 * argument is the record ID (oid) in the optimizely table.
 *
 * @parm
 *   $form: Array of form elements
 *
 * @parm
 *   &$form_submit: Array of the stae of the form elements
 *
 * @parm
 *   $target_oid: When an update of a record, $target_oid will have a value
 *
 * @return
 *   $form: An array of the form elements
 */
function optimizely_add_update_form($form, &$form_submit, $target_oid = NULL) {
  
  $form = array();
  $form['#attached'] = array(
      'css' => array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'optimizely') . '/css/optimizely.css',
    ),
  );

  $account_id = variable_get('optimizely_id', 0);

  if ($target_oid == NULL) {

    $form_action = 'Add';

    $intro_message = '';

    $form['optimizely_oid'] = array(
      '#type' => 'value',
      '#value' => NULL,
    );

    // Enable form element default - blank, unselected
    $enabled = FALSE;
    $project_code = FALSE;

  }
  else {

    $form_action = 'Update';

    $query = db_select('optimizely', 'o')
      ->fields('o')
      ->condition('o.oid', $target_oid, '=');

    $record = $query->execute()
      ->fetchObject();

    $form['optimizely_oid'] = array(
      '#type' => 'value',
      '#value' => $target_oid,
    );

    $form['optimizely_original_path'] = array(
      '#type' => 'value',
      '#value' => implode("\n", unserialize($record->path)),
    );

    $enabled = $record->enabled;
    $record->project_code == 0 ? $project_code = 'Undefined' : $project_code = $record->project_code;

  }

  // If we are updating the default record, make the form element inaccessible
  $form['optimizely_project_title'] = array(
    '#type' => 'textfield',
    '#disabled' => $target_oid == 1 ? TRUE : FALSE,
    '#title' => t('Project Title'),
    '#default_value' => $target_oid ? check_plain($record->project_title) : '',
    '#description' => check_plain($target_oid) == 1 ? t('Default project, this field can not be changed.') : t('Descriptive name for the project entry.'),
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => TRUE,
    '#weight' => 10,
  );

  $form['optimizely_project_code'] = array(
    '#type' => 'textfield',
    '#disabled' => $target_oid == 1 ? TRUE : FALSE,
    '#title' => t('Optimizely Project Code'),
    '#default_value' => $project_code == FALSE ? '' : check_plain($project_code),
    '#description' => check_plain($target_oid) == 1 ?
      t('The Optimizely account value has not been set under <a href="/admin/config/system/optimizely/settings">ACCOUNT INFO</a>.') :
      t('The Optimizely javascript file name used in the snippet as provided by the Optimizely website for the project.'),
    '#size' => 30,
    '#maxlength' => 100,
    '#required' => TRUE,
    '#weight' => 20,
  );

  $form['optimizely_include'] = array(
    '#type' => 'radios',
    '#title' => t('Include/Exclude Optimizely Snippet on specific pages or paths.'),
    '#description' => t('Include/Exclude Optimizely snippet / javascript on specific pages or paths. The use of wildcards ("*") and "<front>" is supported.'),
    '#default_value' => $target_oid ? $record->include : 1,
    '#options' => array(
      1 => 'Only the listed pages',
      0 => 'All pages except those listed',
    ),
    '#weight' => 30,
  );

  $form['optimizely_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Set Path Where Optimizely Code Snippet Appears'),
    '#default_value' => $target_oid ? implode("\n", unserialize($record->path)) : '',
    '#description' => t('Enter the path where you want to insert the Optimizely Snippet.
      For Example: "/clubs/*" causes the snippet to appear on all pages below "/clubs" in the URL but not
      on the actual "/clubs" page itself.'),
    '#cols' => 100,
    '#rows' => 6,
    '#resizable' => FALSE,
    '#required' => FALSE,
    '#weight' => 40,
  );

  $form['optimizely_enabled'] = array(
    '#type' => 'radios',
    '#title' => t('Enable/Disable Project'),
    '#default_value' => $target_oid ? $record->enabled : 0,
    '#options' => array(
      1 => 'Enable project',
      0 => 'Disable project',
    ),
    '#weight' => 25,
    '#attributes' => $enabled ? array('class' => array('enabled')) : array('class' => array('disabled')),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $form_action,
    '#weight' => 100,
  );
  
  $form['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/config/system/optimizely'),
    '#weight' => 101,
  );

  return $form;

}

/*
 * Pass through function to allow parameters to a form via a hook_menu call
 *
 * @return
 *   Call to drupal_get_form for the optimizely_add_update_form form that
 *   includes the additional parameter $target_project
 */
function optimizely_add_update_update($target_project) {  
  return drupal_get_form('optimizely_add_update_form', $target_project);
}

/**
 * Validate form submissions from optimizely_add_update_form().
 *
 * Check to make sute the project code is unique except for the default
 * entry which uses the account ID but should support an additional entry
 * to allow for custom settings.
 */
function optimizely_add_update_form_validate($form, &$form_state) {

  // Validate that the project code entered is a number
  if (!ctype_digit($form_state['values']['optimizely_project_code'])) {
    form_set_error('optimizely_project_code', t('The project code !code must only contain digits.', array('!code' => $form_state['values']['optimizely_project_code'])));
  }
  elseif ($form_state['values']['op'] == 'Add') {
    
    // Confirm project_code is unique or the entered project code is also the account ID - SELECT the project title in prep for related form error message
    $query = db_query('SELECT project_title FROM {optimizely} WHERE
      project_code = :project_code ORDER BY oid DESC', array(':project_code' => $form_state['values']['optimizely_project_code']));
    
    $query_count = $query->rowCount();
   
    // Flag submission if existing entry is found with the same project code value AND it's not an SINGLE entry to replace the "default" entry.
    if ($query_count > 0 || ($form_state['values']['optimizely_project_code'] != variable_get('optimizely_id', FALSE) && $query_count >= 2)) {
      
      // Get the title of the project that already had the propject code
      $found_entry_title = $query->fetchField();
      
      // Flag the project code form field
      form_set_error('optimizely_project_code', t('The project code (!project_code) already has an entry in the "!found_entry_title" project.', array('!project_code' => $form_state['values']['optimizely_project_code'], '!found_entry_title' => $found_entry_title)));
      
    }
    
  }
  
  // Skip if disabled entry
  if ($form_state['values']['optimizely_enabled']) {
    
    // Confirm that the project paths point to valid site URLs
    $target_paths = preg_split('/[\r\n]+/', $form_state['values']['optimizely_path'], -1, PREG_SPLIT_NO_EMPTY);
    $valid_path = _optimizely_valid_paths($target_paths);
    if (!is_bool($valid_path)) {
      form_set_error('optimizely_path', t('The project path "!project_path" is not a valid path. The path or alias could not be resolved as a valid URL resolving to content.',
         array('!project_path' => $valid_path)));
    }
    
    // There must be only one Optimizely javascript call on a page. Check paths to ensure there are no duplicates  
    // http://support.optimizely.com/customer/portal/questions/893051-multiple-code-snippets-on-same-page-ok-
    list($error_title, $error_path) = _optimizely_unique_paths($target_paths, $form_state['values']['optimizely_include'], $form_state['values']['optimizely_oid']);
  
    if (!is_bool($error_title)) {
      form_set_error('optimizely_path', t('The path "!error_path" will result in a duplicate entry based on the other project path settings. Optimizely does not allow more than one project to be run on a page.', array('!error_path' => $error_path)));
    }
  
  }
  
}

/**
 * Process form submissions from optimizely_add_update_form().
 *
 * Either "Add"s or "Update"s a record from the optimizely_add_update_form() form.
 */
function optimizely_add_update_form_submit($form, &$form_state) {

  // Catch form submitted values and prep for processing
  $oid = $form_state['values']['optimizely_oid'];

  $project_title = check_plain($form_state['values']['optimizely_project_title']);
  $project_code = check_plain($form_state['values']['optimizely_project_code']);

  // @totdo - Add support for "<front>" to allow use of check_plain() on ['optimizely_path']
  $path_array = preg_split('/[\r\n]+/', $form_state['values']['optimizely_path'], -1, PREG_SPLIT_NO_EMPTY);

  $include = check_plain($form_state['values']['optimizely_include']);
  $enabled = check_plain($form_state['values']['optimizely_enabled']);

  // Process add or edit submission
  // No ID value included in submission - add new entry
  if (!isset($oid))  {

    db_insert('optimizely')
      ->fields(array(
        'project_title' => $project_title,
        'include' => $include,
        'path' => serialize($path_array),
        'project_code' => $project_code,
        'enabled' => $enabled,
      ))
      ->execute();

    drupal_set_message(t('The project entry has been created.'), 'status');

    // Rebuild the provided paths to ensure Optimizely javascript is now included on paths
    if ($enabled) {
      optimizely_refresh_cache($path_array, $include);
    }

  } // $oid is set, update exsisting entry
  else {

    db_update('optimizely')
      ->fields(array(
        'project_title' => $project_title,
        'include' => $include,
        'path' => serialize($path_array),
        'project_code' => $project_code,
        'enabled' => $enabled,
      ))
      ->condition('oid', $oid)
      ->execute();

    drupal_set_message(t('The project entry has been updated.'), 'status');

    // Path originally set for project - to be compaired to the updated value to determine what cache paths needs to be refreshed
    $original_path_array = preg_split('/[\r\n]+/', $form_state['values']['optimizely_original_path'], -1, PREG_SPLIT_NO_EMPTY);

    optimizely_refresh_cache($path_array, $include, $original_path_array);

  }

  // Return to project listing page
  drupal_goto('admin/config/system/optimizely');

}

/**
 * Menu callback. Enter the Optimizely account details.
 */
function optimizely_account_settings_form($form_state) {
  
  $form = array();
  $form['#attached'] = array('css' => array
    (
      'type' => 'file',
      'data' => drupal_get_path('module', 'optimizely') . '/css/optimizely.css',
    ),
  );

  $form['optimizely_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Optimizely ID Number'),
    '#default_value' => variable_get('optimizely_id', ''),
    '#description' => t('Your Optimizely account ID. This is the number after <q>/js/</q> in the Optimizely Tracking Code that\'s applied to the web
												pages of the site.'),
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
 * Validation for optimizely_account_settings_form form
 */
function optimizely_account_settings_form_validate($form, &$form_state) {
  if (!preg_match('/^\d+$/', $form_state['values']['optimizely_id'])) {
    form_set_error('optimizely_id', t('Your Optimizely ID should be numeric.'));
  }
}

/**
 * Process submisison from optimizely_setup_account_settings_form form. This includes saving the
 * entered Optimizely account ID to the varable database table, updating the default optimizely (oid)
 * record with the project ID which is also the account ID.
 */
function optimizely_account_settings_form_submit($form, &$form_state) {

  // Write the variable table
  variable_set('optimizely_id', $form_state['values']['optimizely_id']);

  // Update the default project / experiement entry with the account ID value
  db_update('optimizely')
    ->fields(array(
        'project_code' => $form_state['values']['optimizely_id'],
      ))
    ->condition('oid', '1')
    ->execute();

  // Inform the administrator that the default project / experiement entry is ready to be enabled.
  drupal_set_message(t('The default project entry is now ready to be enabled. This will apply the default Optimizely project tests site wide.'), 'status');

  // Redirect back
  drupal_goto('/admin/config/system/optimizely');

}

/**
 * Menu callback. Displays a list of Optimizely projects as records in the Optimizely database table.
 */
function optimizely_project_list_form() {
  
  $form = array();
  
  // Load css and js files specific to optimizely admin pages
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'optimizely') . '/css/optimizely.css',
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'optimizely') . '/js/optimizely-admin.js',
  );
  
  $prefix  = '<ul class="admin-links">';
  $prefix .= '  <li>' . l(t('Add Project Entry'), 'admin/config/system/optimizely/add_update') . '</li>';
  $prefix .= '</ul>';
  
  $form['projects'] = array(
    '#prefix' => $prefix . '<div id="optimizely-project-listing">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'optimizely_projects_table'
  );

  // Lookup account ID setting to trigger "nag message".
  $account_id = variable_get('optimizely_id', 0);
  
  // Begin building the query.
  $query = db_select('optimizely', 'o')
    ->orderBy('oid')
    ->fields('o');

  // Fetch the result set.
  $result = $query->execute();

  // Build each row of the table
  foreach ($result as $project_count => $row) {
    
    // Deal with "<front>" as one of the paths
    $paths = unserialize($row->path);
    
    $project_paths = '<ul>';
    foreach ($paths as $path) {
      if ($path == '<front>') {
        $path = htmlspecialchars('<front>');
      }
      $project_paths .= '<li>' . $path . '</li>';
    }
    $project_paths .= '</ul>';

    // Build Delete link
    if ($row->oid != 1) {
      $edit_link = l(t('Update'), 'admin/config/system/optimizely/add_update/' . $row->oid);
      $delete_link = ' / ' . l(t('Delete'), 'admin/config/system/optimizely/delete/' . $row->oid);
      $default_entry_class = array('');
    }
    else {
      $edit_link = l(t('Update'), 'admin/config/system/optimizely/add_update/' . $row->oid);
      $delete_link = ' / ' . 'Default Entry';
      $default_entry_class = array('default-entry');
    }
    
    $row->enabled ? $checked = "'#checked' => 'checked'" : $checked = '';
    
    // Build form elements in cluding enable checkbox and data columns
    $form['projects'][$project_count]['enable'] = array(
      '#type' => 'checkbox',
      '#attributes' => array(
        'id' => 'project-enable-' . $row->oid,
        'name' => 'project-' . $row->oid,
        $row->enabled ? "'#checked' => 'checked'" : '',
      ),
      '#default_value' => $row->enabled,
      '#extra_data' => array('field_name' => 'project_enabled'),
      '#suffix' => '<div class="status-container status-' . $row->oid . '"></div>'
    );
    
    $form['projects'][$project_count]['#project_title'] = $row->project_title;
    $form['projects'][$project_count]['#admin_links'] = $edit_link . $delete_link;
    
    if ($row->include) {
      $include = t('Include:') . ' ' . $project_paths;
    }
    else {
      $include = t('Exclude:') . ' ' . $project_paths;
    }
    $form['projects'][$project_count]['#paths'] = $include;
    
    if ($account_id == 0 && $row->oid == 1) {
      $project_code = t('Set <strong>') .
        l(t('Optimizely account ID'), 'admin/config/system/optimizely/settings') .
        t('</strong> to enable default project site wide.');
    }
    else {
      $project_code = $row->project_code;
    }
    $form['projects'][$project_count]['#project_code'] = $project_code;
    $form['projects'][$project_count]['#oid'] = $row->oid;
    
  }
  
return $form;
  
}


/*
 * Theme function to define the output of the project listing in a table format within a form.
 * The form is need to support the enable column which is a checkbox form element. 
 */
function theme_optimizely_projects_table($vars) {
      
  $element = $vars['element'];

  $rows = array();
  foreach (element_children($element) as $key) {
    
    $rows[] = array(
      'class' => array(
        'project-row-' . $element[$key]['#project_code']['#value']
      ),
      'id' => array(
        'project-' . $element[$key]['#oid']['#value']
      ),
      'data' => array(
        array(
          'class' => $element[$key]['enable']['#value'] ? 'enable-column enabled' : 'enable-column disabled',
          'data' => render($element[$key]['enable']),
        ),
        array(
          'class' => $element[$key]['enable']['#value'] ? 'project-title-column enabled' : 'project-title-column disabled',
          'data' => render($element[$key]['#project_title']),
        ),
        array(
          'class' => $element[$key]['enable']['#value'] ? 'admin-links-column enabled' : 'admin-links-column disabled',
          'data' => render($element[$key]['#admin_links']),
        ),
        array(
          'class' => $element[$key]['enable']['#value'] ? 'paths-column enabled' : 'paths-column disabled',
          'data' => render($element[$key]['#paths']),
        ),
        array(
          'class' => $element[$key]['enable']['#value'] ? 'project-code-column enabled' : 'project-code-column disabled',
          'data' => render($element[$key]['#project_code']),
        ),
      ),
    );
    
  }

  $header = array(t('Enabled'), t('Project Title'), t('Update / Delete'), t('Paths'), t('Project Code'));
 
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Menu callback. Get confirmation to delete a record from the Optimizely table.
 */
function optimizely_delete_page($form, &$form_state, $vars = NULL) {
  return drupal_build_form('optimizely_delete_page_confirm', $form_state);
}

/**
 * Build a confirm form for deletion of record in Optimizely table.
 */
function optimizely_delete_page_confirm($form, &$form_state, $vars = NULL) {

  $form['oid'] = array(
    '#type' => 'value',
    '#value' => $vars,
  );

  $heading = t('Delete');
  $cancel_path = array('path' => 'admin/config/system/optimizely');
  $caption  = '<p>' . t('Are you sure you want to delete this configuration?') . '<p>' .
              '<p>' . t('This action cannot be undone.') . '</p>';
  $yes = t('Delete');
  $no = t('Cancel');

  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);

}

/**
 * Submit function for the confirm deletion form. Delete the entry in the
 * database and return the user to the Project listing page.
 */
function optimizely_delete_page_confirm_submit($form, &$form_state) {  

  // target $oid
  $oid = $form_state['values']['oid'];
  
  // Lookup entry details before delete
  $query = db_select('optimizely', 'o')
    ->fields('o', array('path', 'include', 'enabled'))
    ->condition('o.oid', $oid, '=');

  $record = $query->execute()
    ->fetchObject();
    
  // Delete entry in database based on the target $oid
  $query = db_delete('optimizely')
    ->condition('oid', $oid);
  $query->execute();

  // Only clear page cache for entries that are active when deleted
  if ($record->enabled) {
    
    // Always serialize when saved 
    $path_array = unserialize($record->path);
    $include = $record->include;
    
    optimizely_refresh_cache($path_array, $include);
    
  }

  // Inform the user of the entry being deleted and return them to the
  // listing page.
  drupal_set_message(t('The project entry has been deleted.'), 'status');
  drupal_goto('/admin/config/system/optimizely');

}

/**
 * AJAX callback for click event on project enable checkbox.
 *
 * @return
 *   json response details for AJAX call. 
 */
function optimizely_ajax_enable() {
  
  // Default
  $unique_path = FALSE;
  
  // Retrieve the json POST values
  $target_oid = $_POST['target_oid'];
  $target_enable = $_POST['target_enable'];
  
  // Only check path values if project is being enabled,
  // Project is currently disabled (FALSE) and is now being enabled (TRUE)
  if ($target_enable == TRUE) {
  
    // Lookup the current project settings
    $query = db_select('optimizely', 'o')
      ->fields('o', array('path', 'include'))
      ->condition('o.oid', $target_oid, '=');
  
    $result = $query->execute()->fetchObject();
      
    $target_paths = unserialize($result->path);
    $target_include = $result->include;
    
    // Check that the paths are valid for the newly enabled project
    $valid_paths = _optimizely_valid_paths($target_path_array);
    
    // Check to see if the enable project has path entries that will result in
    // duplicates with other enable projects
    if ($valid_paths)  {
      list($unique_path, $null) = _optimizely_unique_paths($target_paths, $target_include, $target_oid);
    }
    
  }
  
  // The newly enabled project has unique paths OR the target project is
  // currently enabled (TRUE) and will now be disbaled
  if ($target_enable == FALSE || $unique_path === TRUE)  {
    
    // Toggle $target_enable
    $target_enable ? $target_enable = 1 : $target_enable = 0;
  
    // Update database with new enable setting for project entry
    $results = db_update('optimizely')
      ->fields(array(
        'enabled' => (int) $target_enable,
      ))
      ->condition('oid', $target_oid)
      ->execute();
      
    // Refresh cache on project paths, this includes both enable and disabled
    // projects as there will be a need to clear the js calls in both cases
    optimizely_refresh_cache($target_paths, $target_include);
    
    // Tell AJAX request of status to trigger jquery
    drupal_json_output(array('status' => 'updated', 'oid' => $target_oid, 'target_enable' => $target_enable));
      
  }
  else {
    drupal_json_output(array('status' => 'rejected', 'oid' => $target_oid));
  }
    
}

/**
 * optimizely_refresh_cache()
 *
 * @parm
 *   $path_array - An array of the target paths entries that the cache needs to
 *   be cleared. Each entry can also contain wildcards /* or variables "<front>".
 *   
 * @parm
 *   $include - Flag if the paths are include or exclude
 */
function optimizely_refresh_cache($path_array, $include = TRUE, $original_path_array = NULL) {

  // Determine protocol
  $protocol = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on') ? 'https' : 'http';
  $cid_base = $protocol . '://' . $_SERVER['HTTP_HOST'] . '/';
  
  // If update of project that includes changes to the path, clear cache on all
  // paths to add/remove Optimizely javascript call
  if (isset($original_path_array)) {
    $path_array = array_merge($path_array, $original_path_array);
  }

  // Loop through every path value
  foreach ($path_array as $path_count => $path) {

    $recursive = NULL;

    // Apply to all paths when there's a '*' path entry (default project entry
    // for example) or it's an exclude path entry (don't even try to figure out
    // the paths, just flush all page cache
    if ((strpos($path, '*') !== 0) || (!$include)) {

      if (strpos($path, '<front>') === 0) {
        $cid = $cid_base . '/' . variable_get('site_frontpage', 'node');
        $recursive = FALSE;
      }
      elseif (strpos($path, '/*') > 0)  {
        $cid = $cid_base . substr($path, 0, strlen($path) - 2);
        $recursive = TRUE;
      }
      else {
        $cid = $cid_base . $path;
        $recursive = FALSE;
      }

      cache_clear_all($cid, 'cache_page', $recursive);

    }
    else {
      cache_clear_all('*', 'cache_page', TRUE);
      break;
    }

  }
  
  // Varnish
  if (module_exists('varnish')) {
    varnish_expire_cache($path_array);
    drupal_set_message(t('Successfully purged cached page from Varnish.'));
  }

  drupal_set_message(t('Page cache has been cleared based on the project path settings.'), 'status');

}

/*
 * Compare target path against the project paths to conform they're unique
 *
 * @parm
 *   $target_paths - the paths entered for a new project entry OR
 *   the paths of an exsisting project entry that has been enabled.
 *
 * @parm
 *   $target_include = TRUE : the include setting for if the paths are include
 *   or excluded
 *   
 * @parm
 *   $target_paths = NULL : the oid of the project entry that has been enabled
 *
 * @return
 *   $project_title can be TRUE if the $target_paths are unique OR the name of
 *   the project_title
 *   which has a duplicate path entry.
 *
 * @return
 *   $target_path  the path that is a duplicate that must be addressed to
 *   enable or create the new project entry. 
 */
function _optimizely_unique_paths($target_paths, $target_include = TRUE, $target_oid = NULL) {
  
  // Collect all of the exsisting project paths grouped by include or exclude
  // and enabled,
  $query = db_select('optimizely', 'o')
    ->fields('o', array('oid', 'project_title', 'path', 'include'))
    ->condition('o.enabled', 1, '=');
    
  // Add target_oid to query when it's an update, $target_oid is will be defined
  if ($target_oid != NULL) {
    $query = $query->condition('o.oid', $target_oid, '<>');
  }

  $result = $query->execute();
  
  $all_project_include_paths = array();
  $all_project_exclude_paths = array();

  // Build array of all the project entry paths
  foreach ($result as $row) {

    // Collect all of the path values and merge into collective array, one each
    // for include and exclude
    $project_paths = unserialize($row->path);
    
    if ($row->include) {
      $all_project_include_paths = array_merge($all_project_include_paths, $project_paths);
    }
    else {
      $all_project_exclude_paths = array_merge($all_project_exclude_paths, $project_paths);
    }

  }
  
  // Include or not include matching path values
  if ($target_include) {
    
    // Check all of the paths for all of the active project entries to make sure
    // the paths are unique
    foreach ($target_paths as $target_path) {
  
      // Remove wildcard notation
      if (strpos($target_path, '*') !== FALSE) {
        
        $target_path = substr($target_path, 0, strpos($target_path, '*'));
        
        // Compare base $target_path with all of the project paths. With a
        // wildcard removed the base $target_path will match duplicate entries
        // in other projects as a potential duplicate
        foreach ($all_project_include_paths as $project_oid => $project_path) {
          if (strpos($project_path, $target_path) !== FLASE) {
            return array($project_oid, $project_path);
          }
        }
        
      }
      
      // Search for target path in all other target project paths
      if (in_array($target_path, $all_project_include_paths)) {
        return array($row->project_title, $target_path);
      }
  
    }
   
  }
  else {
    
    foreach ($target_paths as $target_path) {
    
      if (in_array($target_path, $all_project_exclude_paths)) {
        return array($row->project_title, $target_path);
      }
      
    }
    
    // Exclude path
    $common_paths = array_intersect($target_paths, $all_project_include_paths);

    if (count($common_paths) !== 0) {
      return array($row->project_title, $common_paths[0]);
    }
    
  }

  return array(TRUE, NULL);

}

/**
 * _optimizely_valid_paths()
 * 
 * Validate the target paths with drupal_lookup_path.
 *
 * @parm
 *   $target_paths: An array of the paths to validate.
 *
 * @return
 *   boolean of TRUE if the paths are valid or a string of the path that failed.
 */
function _optimizely_valid_paths($target_paths) {
  
   // Validate entered paths to confirm the paths exist on the website
  foreach ($target_paths as $project_path) {
    
    // Deal with wildcards
    if (strpos($project_path, '*') !== FALSE) {
      $project_path = substr($project_path, 0, strpos($project_path, '*'));
    }
    
    // Skip validation if <front> is path value
    if (strpos($project_path, '<front>') === FALSE) {
    
      // Test for valid path
      $path_found = drupal_lookup_path('source', $project_path);
      if (!$path_found) {
        return $project_path;
      }
      
    }
    
  }
  
  return TRUE;
  
}
