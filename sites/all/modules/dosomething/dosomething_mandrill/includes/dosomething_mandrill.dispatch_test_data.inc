<?php
/*
 * @file
 * Test data for hook_mail()
 */
function dosomething_mandrill_dispatch_test_data($op) {
  
  switch ($op):
    
    // Note: 'to' is a string not an array. The Mandrill module will take care of
    // converting it to an array. The value could also be passed as an array if there
    // was a need to send to more than one address
    case 'petition':
      
      // dosomething_subscribe.module, ln 302
      
      $to = 'dlee+petitions-dispatchtest-petition-01@dosomething.org';
      $key = 'petition';
      $message = array(
        'FNAME' => 'First',    // $first_name
        'LNAME' => 'Last',     // $last_name
        'TITLE' => 'Test Petition Title 123456789012345678901234567890', // $node->title
        'URL' => '/test/path'  // $form['#action']
      );

      break;
  
    default:
      
      $message = 'Error: dosomething_mandrill_dispatch_test_data() - invalid operation (op: ' . $op . ')';
      $to = 'Error: dosomething_mandrill_dispatch_test_data() - invalid operation (op: ' . $op . ')';
      
  endswitch;
  
  return array($to, $key, $message);

}