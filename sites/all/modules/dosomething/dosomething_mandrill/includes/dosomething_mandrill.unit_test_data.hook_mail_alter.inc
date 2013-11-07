<?php
/*
 * @file
 * Test data for hook_mandrill_mail_alter()
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
        0 => array(
          'email' => 'dlee+petitions-test01@dosomething.org'
        ),
      ),
    ),
  );
  
  $message = array(
    'body' => '',
    'from' => 'dosomething@dosomething.org',
    'headers' => array(
      'From' => 'noreply@dosomething.org',
      'Return-Path' => 'noreply@dosomething.org',
      'Sender' => 'noreply@dosomething.org'
    ),
    'params' => array(
      'FNAME' => 'First',
      'LNAME' => 'Last',
      'PETITION' => 'New York City Council: Protect Unpaid Interns From Sexual Harassment',
      'PETITIONURL' => 'http://www.dosomething.org/petition/interns',
    ),
    'subject' => 'Thanks for signing the petition: New York City Council: Protect Unpaid Interns From Sexual Harassment',
    'tags' => array(
      0 => 'petition',
      1 => 'New York City Council: Protect Unpaid Interns From',
    ),
    'to' => 'dlee+petitions-test01@dosomething.org',
  );
  
  return array($mandrill_params, $message);
  
}