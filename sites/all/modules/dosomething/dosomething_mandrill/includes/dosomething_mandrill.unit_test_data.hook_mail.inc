<?php
/*
 * @file
 * Test data for hook_mail()
 */

 /*
  * Test data that returns $message, $params, $to
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
      
  endswitch;
  
  return array($message, $params, $to);

}