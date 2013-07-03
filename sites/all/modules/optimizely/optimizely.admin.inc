<?php
/**
 * @file
 * Admin page callback for the Optimizely module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * If there are only three arguments in the path it builds the add form and adds a record.
 * Otherwise it builds the update form where the fourth argument is the record ID (oid) in
 * in the optimizely table.
 */
function optimizely_add_update_form($form, &$form_submit, $target_oid = NULL) {

  // Load css specific to optimizely admin pages
  drupal_add_css(drupal_get_path('module', 'optimizely') . '/css/optimizely.css');

  $account_id = variable_get('optimizely_id', 0);

  if (!$target_oid) {

    $form_action = 'Add';

    $intro_message = '';

    $form['optimizely_oid'] = array(
      '#type' => 'value',
      '#value' => NULL,
    );

    // Enable form element default - blank, unselected
    $enabled = FALSE;

  }
  else {

    $form_action = 'Update';

    $intro_message = '<p>' . t('In order to use this module, you\'ll need an <a href="@url">Optimizely account</a>.
      A Free 30 day trial account is available.' . '</p>',
      array('@url' => url('http://optimize.ly/OZRdc0')));

    if ($account_id == 0) {

      $intro_message .= t('<ul><li><strong>Add the account ID to the <a href="@account">Account Info</a> settings page to be
        able to enable this entry</strong>.</li></ul>',
        array('@account' => url('admin/config/system/optimizely/settings')));

    }

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

    // Enable form element current setting
    $enabled = $record->enabled;

  }

  // @todo : move text content to template file (tpl)
  $form['optimizely_introduction'] = array(
    '#type' => 'markup',
    '#markup' => $intro_message . '<p>' . t('The configuration and setup for the actual A/B tests is done by logging into your account on the
      <a href="@url">Optimizely website</a>.') . '</p>',
    '#weight' => 0,
  );

  // If we are updating the default record, make the form element inaccessible
  $form['optimizely_project_title'] = array(
    '#type' => 'textfield',
    '#access' => $target_oid == 1 ? FALSE : TRUE,
    '#title' => t('Project Title'),
    '#default_value' => $target_oid ? $record->project_title : '',
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => TRUE,
    '#weight' => 10,
  );

  $form['optimizely_project_code'] = array(
    '#type' => 'textfield',
    '#access' => $target_oid == 1 ? FALSE : TRUE,
    '#title' => t('Optimizely Project Code'),
    '#default_value' => $target_oid ? $record->project_code : '',
    '#description' => t('The Optimizely file name used in the snippet.'),
    '#size' => 30,
    '#maxlength' => 100,
    '#required' => TRUE,
    '#weight' => 20,
  );

  $form['optimizely_include'] = array(
    '#type' => 'radios',
    '#access' => $target_oid == 1 ? FALSE : TRUE,
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
    '#access' => $target_oid == 1 ? FALSE : TRUE,
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
    '#access' => ($target_oid == 1 && $account_id == 0) ? FALSE : TRUE,
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
    '#access' => ($target_oid == 1 && $account_id == 0) ? FALSE : TRUE,
    '#value' => $form_action,
    '#weight' => 100,
  );

  return $form;

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
  
  // todo: the snippet must be only one per page / path - unique to the path, can only load one sniipet per page.
  // http://support.optimizely.com/customer/portal/questions/893051-multiple-code-snippets-on-same-page-ok-
  
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
 * Menu callback. Enter the Optimizely ID number.
 */
function optimizely_setup_account_settings_form($form_state) {

  // Load css file specific to optimizely admin pages
  drupal_add_css(drupal_get_path('module', 'optimizely') . '/css/optimizely.css');

  // @todo : Move markup to template

  $form['optimizely_introduction'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('In order to use this module, you need an <a href="@url">Optimizely</a> account. A Free 30 day trial account is available.',
                  array('@url' => url('http://www.optimizely.com/'))) . '</p><p>' .
                  t('Most of the configuration and setup for the A/B and other tests is done by logging into your account on the Optimizely website.') .
                  '</p><p>' . t('The default Project js file (snippet) uses the Optimizely account ID. If there are no entries in the <a href="@url">Project
                  Listing</a> page the ID will be used as a default value for the Optimizely javascript file site wide.</p>',
                  array('@url' => url('/admin/config/system/optimizely'))));

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
 * Validation for optimizely_setup_account_settings_form form
 */
function optimizely_setup_account_settings_form_validate($form, &$form_state) {
  if (!preg_match('/^\d+$/', $form_state['values']['optimizely_id'])) {
    form_set_error('optimizely_id', t('Your Optimizely ID should be numeric.'));
  }
}

/**
 * Process submisison from optimizely_setup_account_settings_form form. This includes saving the
 * entered Optimizely account ID to the varable database table, updating the default optimizely (oid)
 * record with the project ID which is also the account ID.
 */
function optimizely_setup_account_settings_form_submit($form, &$form_state) {

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
 * Menu callback. Displays a list of records in the Optimizely table.
 */
function optimizely_list_page() {

  // Load css file specific to optimizely admin pages
  drupal_add_css(drupal_get_path('module', 'optimizely') . '/css/optimizely.css');

  // Display link at the top of the table
  // @ todo : Move to template
  $output  = '<ul class="admin-links">';
  $output .= '  <li>' . l(t('Add Project Entry'), 'admin/config/system/optimizely/add_update') . '</li>';
  $output .= '</ul>';

  // Lookup account ID setting to trigger "nag message".
  $account_id = variable_get('optimizely_id', 0);

  // Begin building the query.
  $query = db_select('optimizely', 'o')
    ->extend('PagerDefault')
    ->orderBy('oid')
    ->fields('o')
    ->limit(10);

  // Fetch the result set.
  $result = $query->execute();

  // Headers for theme_table().
  $header = array('Project Title', 'Update / Delete', 'Include / Exclude', 'Paths', 'Project Code', 'Enabled');

  // Build each row of the table
  foreach ($result as $row) {
  
    // Deal with "<front>" as one of the paths
    $paths = unserialize($row->path);
    $project_paths = '';
    
    foreach ($paths as $path) {
      if ($path == '<front>') {
        $path = htmlspecialchars('<front>');
      }
      $project_paths .= $path . '<br/>';
    }

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

    $rows[] = array(
      'class' => $default_entry_class,
      'data' => array(
        array(
          'data' => $row->project_title,
          'class' => $row->enabled ? 'title-column enabled' : 'title-column disabled',
        ),
        array(
          'data' => $edit_link . $delete_link,
          'class' => $row->enabled ? 'delete-column enabled' : 'delete-column disabled',
        ),
        array(
          'data' => $row->include ? t('Include Paths') : t('Exclude Paths'),
          'class' => $row->enabled ? 'include-column enabled' : 'include-column disabled',
        ),
        array(
          'data' => $project_paths,
          'class' => $row->enabled ? 'path-column enabled' : 'path-column disabled',
        ),
        array(
          'data' => ($account_id == 0 && $row->oid == 1) ? t('Set <strong>') . l(t('Optimizely account ID'), 'admin/config/system/optimizely/settings') . t('</strong> to enable default project site wide.') : $row->project_code,
          'class' => ((!$row->enabled) || ($account_id == 0 && $row->oid == 1)) ? 'code-column disabled' : 'code-column enabled',
        ),
        array(
          'data' => $row->enabled ? t('Enabled') : l(t('Disabled'), 'admin/config/system/optimizely/add_update/' . $row->oid),
          'class' => $row->enabled ? 'enable-column enabled' : 'enable-column disabled',
        ),

      ),

    );

  }

  // Format output.
  $output .= theme('table', array('attributes' => array('class' => array('projects')), 'header' => $header, 'rows' => $rows)) . theme('pager');

  return $output;

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
  $caption  = t('<p>Are you sure you want to delete this configuration?</p>') .
              t('<p>This action cannot be undone.</p>');
  $yes = t('Delete');
  $no = t('Cancel');

  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);

}

/**
 * Submit function for the confirm deletion form. Delete the entry in the database
 * and return the user to the Project listing page.
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

  // Inform the user of the entry being deleted and return them to the listing page.
  drupal_set_message(t('The project entry has been deleted.'), 'status');
  drupal_goto('/admin/config/system/optimizely');

}

/**
 * optimizely_refresh_cache()
 *
 * @parm $path_array
 *   An array of the target paths entries that the cache needs to be cleared. Each entry can also
 *   contain wildcards /* or variables "<front>".
 * @parm $include
 *   Flag if the paths are include or exclude
 */
function optimizely_refresh_cache($path_array, $include = TRUE, $original_path_array = NULL) {

  // Determine protocol
  $protocol = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on') ? 'https' : 'http';
  $cid_base = $protocol . '://' . $_SERVER['HTTP_HOST'] . '/';
  
  // If update of project that includes changes to the path, clear cache on all paths
  // to add/remove Optimizely javascript call
  if (isset($original_path_array)) {
    $path_array = array_merge($path_array, $original_path_array);
  }

  // Loop through every path value
  foreach ($path_array as $path_count => $path) {

    $recursive = NULL;

    // Apply to all paths when there's a '*' path entry (default project entry for example)
    // or it's an exclude path entry (don't even try to figure out the paths, just flush all page cache
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

  drupal_set_message(t('Page cache has been cleared based on the project settings.'), 'status');

  // Varnish
  if (module_exists('varnish')) {
    varnish_expire_cache($path_array);
    drupal_set_message(t('Successfully purged cached page from Varnish.'));
  }

}