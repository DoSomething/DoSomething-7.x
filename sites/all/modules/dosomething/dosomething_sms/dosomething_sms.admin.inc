<?php
/**
 * @file
 * Admin page callback for the DoSomething SMS module.
 */

/**
 * Builds and returns the Optimizely Add/Update form.
 * If there are only 3 arguments in the path it builds the add form and it adds a record.
 * Otherwise it builds the update form where the fourth argument is the record ID in
 * in the optimizely table.
 */
function dosomething_sms_settings_form() {

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration of DoSomething.org SMS cron()'),
  );
  
  $form['configuration']['dosomething_sms_cron_enable'] = array(
    '#type' => 'radios',
    '#title' => t('Cron Status'),
    '#options' => array(
      TRUE => t('Enabled'),
      FALSE => t('Disabled'),
    ),
    '#default_value' => 'dosomething_sms_cron_disabled',
  );
  
  $form['configuration']['dosomething_sms_cron_interval'] = array(
    '#type' => 'select',
    '#title' => t('Cron interval'),
    '#description' => t('Time after which cron_example_cron will respond to a processing request.'),
    '#default_value' => variable_get('dosomething_sms_cron_interval', 60 * 60),
    '#options' => array(
      60 * 60 => t('1 hour'),
      60 * 60 * 24 * 1 => t('1 day'),
      60 * 60 * 24 * 2 => t('2 days'),
      60 * 60 * 24 * 5 => t('5 days'),
      60 * 60 * 24 * 7 => t('1 week'),
      60 * 60 * 24 * 7 * 2 => t('2 weeks'),
      60 * 60 * 24 * 7 * 4 => t('4 weeks'),
    ),
  );
  
  $form['testing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Test DoSomething.org SMS Cron'),
  );

  $form['testing']['dosomething_sms_cron_test'] = array(
    '#type' => 'markup',
    '#markup' => '<ul><li>Test <a href="/admin/settings/dosomething_sms/test">DoSomething SMS Cron</a> job.</li></ul>',
  );

  return system_settings_form($form);
  
}

function dosomething_sms_settings_form_validate($form, &$form_state) {
  
  $maxdisp = $form_state['values']['onthisdate_maxdisp'];
  if (!is_numeric($maxdisp)) {
    form_set_error('onthisdate_maxdisp', t('You must enter an integer for the maximum number of links.'));
  }
  elseif ($maxdisp <= 0) {
    form_set_error('onthisdate_maxdisp', t('Maximum number of links must be positive.'));
  }
}

/**
 * Test hook_cron()
 **/
function dosomething_sms_testcron() {
  
  $enabled = variable_get('dosomething_sms_cron_enable', FALSE);
  
  // Run job every interval (week by default)
  $interval = variable_get('dosomething_sms_cron_interval', 60 * 60 * 24 * 7);
  $next_run = variable_get('dosomething_sms_cron_next_execution', time() + $interval);
  
  $bla = date('D d M Y - H:i:s', $interval);
  $bla2 = date('D d M Y - H:i:s', $next_run);
  
  $next_run = $next_run - 10000000;

  // Check to see if it's time to run the cleanup task, default to now plus the interval for next run if nothing found for setting
  if (time() >= $next_run) {
   
    /* 
    // Delete entries that are older than a week (interval - dosomething_sms_interval)
    $number_deleted = db_delete('conductor_instance_pointer')
                      ->condition('timestamp', $next_run, '>=')
                      ->execute();
    */
    
    $number_deleted = db_query('
      SELECT
       COUNT(pid)
      FROM
        {conductor_instance_pointer}
      WHERE
        timestamp >= :next_run',
      array(':next_run' => $next_run))->fetchField();

    /**               
     * Create report to see where users are getting stuck
     * 
     * SELECT
     *   workflow_name,
     *   activity_name,
     *   count(activity_name)
     * FROM
     *   conductor_instance_pointer
     * GROUP BY
     *   activity_name
     * ORDER BY
     *   workflow_name
     */

 /*    
    $results = db_select('conductor_instance_pointer', 'cip')
              ->fields('cip', array('workflow_name', 'activity_name'))
              ->groupBy('cip.activity_name')
              ->orderBy('cip.workflow_name', 'DESC')
              ->execute();
 */
 
    $results = db_query('
      SELECT
        workflow_name,
        activity_name,
        COUNT(activity_name) AS activity_name_count
      FROM
        conductor_instance_pointer
      GROUP BY
        activity_name
      ORDER BY
        workflow_name'
    );

//    $results->addExpression('COUNT(activity_name)', 'activity_name_count');
//    $results->execute();
               
    // Headers for theme_table().  
    $header = array('Workflow Name', 'Activity Name', 'Activity Name Count');
    
    // Loop through results          
    foreach ($results as $row) {
       
      $rows[] = array(
        $row->workflow_name,
        $row->activity_name,
        $row->activity_name_count,
      );
       
    }
  
    // Format output.
    $output = theme('table', array('header' => $header, 'rows' => $rows));

    // Send Report
    $to = 'dlee@dosomething.org';
    $language = '';
    $from = 'dosomething@dosomething.org';
    
    $params['subject'] = 'dosomething_sms cron Report - '. date('l - j F Y');
    
    $params['body']  = t('<p>Cron run at %current_time. %number_deleted entries deleted.</p><p>',
                         array('%current_date' => date_iso8601(time(0)), '%number_deleted' => $number_deleted));
    $params['body'] .= theme('table', array('header' => $header, 'rows' => $rows));
    $params['body'] .= t('</p><p>See you on the next run at %next_run.', array('%next_run' => $next_run));
    
    // drupal_mail($module, $key, $to, $language, $params = array(), $from = NULL, $send = TRUE)
    $result = drupal_mail('dosomething_mandrill', 'dosomething-plain', $to, language_default(), $params,  $from, TRUE);
  
    if (isset($result['result']) && $result['result'] == 'true') {
      drupal_set_message(t('Mandrill test email sent from %from to %to.', array('%from' => $result['from'], '%to' => $result['to'])), 'status');
    }

    // Log report in Watchdog
    watchdog('dosomething_sms', 'Cron run at %current_time. %number_deleted entries deleted.', array('%current_date' => date_iso8601(time(0)), '%number_deleted' => $number_deleted), WATCHDOG_ERROR);
    
    // Schedule new cron run
    variable_set('dosomething_sms_cron_next_execution', time() + $interval);
    
  }
  
  return;
    
}