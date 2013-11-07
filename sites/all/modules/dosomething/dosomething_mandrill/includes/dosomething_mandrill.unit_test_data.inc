<?php

/*
 * Generate test data for hook_mail()
 */
function dosomething_mandrill_unit_test_data_hook_mail($op) {
  
  switch ($op):
    
    // Note: 'to' is a string not an array. The Mandrill module will take care of
    // converting it to an array. The value could also be passed as an array if there
    // was a need to send to more than one address
    case 'petition':
      
      $message = array(
        'body' => '',
        'from' => 'noreply@dosomething.org',
        'headers' => array(
          'From' => 'noreply@dosomething.org',
          'Return-Path' => 'noreply@dosomething.org',
          'Sender' => 'noreply@dosomething.org'
        ),
        'params' => array(
          'FNAME' => 'First',
          'LNAME' => 'Last',
          'TITLE' => 'New York City Council: Protect Unpaid Interns From Sexual Harassment',
          'URL' => '/petition/interns',
        ),
        'subject' => '',
        'to' => 'dlee+petitions-test01@dosomething.org'
      );
      
      $to = 'dlee+petitions-test01@dosomething.org';
      
      $params = array(
        'FNAME' => 'First',
        'LNAME' => 'Last',
        'TITLE' => 'New York City Council: Protect Unpaid Interns From Sexual Harassment',
        'URL' => '/petition/interns',
      );
      
      break;
  
    default:
      
      $message = 'Error - invalid operation (op: ' . $op . ')';
      $to = 'Error - invalid operation (op: ' . $op . ')';
      
  endswitch;
  
  return array($message, $params, $to);

}

/*
 * Generate test data for hook_mandrill_mail_alter()
 */
function dosomething_mandrill_unit_test_data_hook_mandrill_mail_alter($key) {
  
  $mandrill_params = array(
    'message' => array(
      'from_email' => 'noreply@dosomething.org',
      'from_name' => 'DoSomething.org',
      'headers' => array(
        'From' => 'noreply@dosomething.org',
        'Return-Path' => 'noreply@dosomething.org',
        'Sender' => 'noreply@dosomething.org'
      ),
      'subject' => 'Thanks for signing the petition: New York City Council: Protect Unpaid Interns From Sexual Harassment',
      'tags' => array(
        0 => 'dosomething_mandrill_petition'
      ),
      'to' => array(
        'email' => 'dlee+petitions5000@dosomething.org',
      )
    ),
  );
  
  return $mandrill_params;
  
}