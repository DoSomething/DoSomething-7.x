<?php

/*
 * Test data in arrays.
 *
 * The contents of this include file are used to generate arrays of test data based
 * on keys ($op) defined in dosomething_mandrill_mail (hook_mail). The arrays are injected
 * into dosomething_mandrill_dispatch() just before sending messages to Mandrill.
 * This allows for debugging with "real" from the database but only sending test
 * messages.
 *
 * @param string $op
 *   The operation (key) to be performed in collecting test data.
 *
 * @param boolean|integer $test_flag
 *   Test flag that triggers the use of test data. When the flag is an integer
 *   invalid data is sent.
 */
function dosomething_mandrill_test_data($op, $test_flag=NULL) {
  
  switch ($op) {

    case 'dsevent-birthday':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_birthday($test_flag);
      break;

    case 'dsevent-reg-90':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_reg_90($test_flag);
      break;

    case 'dsevent-reg-365':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_reg_365($test_flag);
      break;

    case 'dsdrip-momm13-1':
    case 'dsdrip-momm13-2':
    case 'dsdrip-momm13-3':
    case 'dsdrip-momm13-4':
    case 'dsdrip-momm13-5':
      list($message_test, $to_test) = dosomething_mandrill_test_dsdrip_momm13($test_flag);
      break;

  }

  return array($message_test, $to_test);
}

/*
 * Populates array of test data for hook_mail key: dsevent-birthday
 *
 * @param boolean|integer $test_flag
 *   Test flag that triggers the use of test data. When the flag is an integer
 *   invalid data is sent.
 */
function dosomething_mandrill_test_dsevent_birthday($test_flag) {

  $message_test = array(
    'message' => array(
      'global_merge_vars' => array(
        0 => array(
          'content' => dosomething_mandrill_campaign_listing(),
          'name' => 'CAMPAIGNS'
        ),
      ),
      'merge_vars' => array(
        0 => array(
          'rcpt' => 'dlee+dsevent-birthday-01@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => '43',
              'name' => 'AGE'
            ),
            1 => array(
              'content' => 'Dee',
              'name' => 'FNAME'
            )
          )
        ),
        1 => array(
          'rcpt' => 'dlee+dsevent-birthday-02@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => '3',
              'name' => 'AGE'
            ),
            1 => array(
              'content' => 'DeeThree',
              'name' => 'FNAME'
            )
          )
        )
      ),
      'to' => array(
        0 => array(
          'email' => 'dlee+dsevent-birthday-01@dosomething.org',
          'name' => 'TheDee',
        ),
        1 => array(
          'email' => 'dlee+dsevent-birthday-02@dosomething.org',
          'name' => 'TheDeeThree',
        )
      )
    )
  );

  $to_test = array(
    0 => array(
      'email' => 'dlee+dsevent-birthday-01@dosomething.org',
      'name' => 'TheDee'
    ),
    1 => array(
      'email' => 'dlee+dsevent-birthday-02@dosomething.org',
      'name' => 'TheDeeThree'
    )
  );

  return array($message_test, $to_test);
}

/*
 * Populates array of test data for hook_mail key: dsevent-reg-90
 *
 * @param boolean|integer $test_flag
 *   Test flag that triggers the use of test data. When the flag is an integer
 *   invalid data is sent.
 */
function dosomething_mandrill_test_dsevent_reg_90($test_flag) {

  $message_test = array(
    'message' => array(
      'global_merge_vars' => array(
        0 => array(
          'content' => dosomething_mandrill_campaign_listing(),
          'name' => 'CAMPAIGNS'
        ),
      ),
      'merge_vars' => array(
        0 => array(
          'rcpt' => 'dlee+dsevent-90days-01@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => 'Dee',
              'name' => 'FNAME'
            )
          )
        ),
        1 => array(
          'rcpt' => 'dlee+dsevent-90days-02@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => 'DeeThree',
              'name' => 'FNAME'
            )
          )
        )
      ),
      'to' => array(
        0 => array(
          'email' => 'dlee+dsevent-90days-01@dosomething.org',
          'name' => 'TheDee',
        ),
        1 => array(
          'email' => 'dlee+dsevent-90days-02@dosomething.org',
          'name' => 'TheDeeThree',
        )
      )
    )
  );

  $to_test = array(
    0 => array(
      'email' => 'dlee+dsevent-90days-01@dosomething.org',
      'name' => 'TheDee'
    ),
    1 => array(
      'email' => 'dlee+dsevent-90days-02@dosomething.org',
      'name' => 'TheDeeThree'
    )
  );

  return array($message_test, $to_test);
}

/*
 * Populates array of test data for hook_mail key: dsevent-reg-365
 *
 * @param boolean|integer $test_flag
 *   Test flag that triggers the use of test data. When the flag is an integer
 *   invalid data is sent.
 */
function dosomething_mandrill_test_dsevent_reg_365($test_flag) {

  $message_test = array(
    'message' => array(
      'global_merge_vars' => array(
        0 => array(
          'content' => dosomething_mandrill_campaign_listing(),
          'name' => 'CAMPAIGNS'
        ),
      ),
      'merge_vars' => array(
        0 => array(
          'rcpt' => 'dlee+dsevent-365days-01@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => 'Dee',
              'name' => 'FNAME'
            ),
            1 => array(
              'content' => '2nd',
              'name' => 'MEMBERSHIP_YEAR'
            )
          )
        ),
        1 => array(
          'rcpt' => 'dlee+dsevent-365days-02@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => 'DeeThree',
              'name' => 'FNAME'
            ),
            1 => array(
              'content' => '1st',
              'name' => 'MEMBERSHIP_YEAR'
            )
          )
        )
      ),
      'to' => array(
        0 => array(
          'email' => 'dlee+dsevent-365days-01@dosomething.org',
          'name' => 'TheDee',
        ),
        1 => array(
          'email' => 'dlee+dsevent-365days-02@dosomething.org',
          'name' => 'TheDeeThree',
        )
      )
    )
  );

  $to_test = array(
    0 => array(
      'email' => 'dlee+dsevent-365days-01@dosomething.org',
      'name' => 'TheDee'
    ),
    1 => array(
      'email' => 'dlee+dsevent-365days-02@dosomething.org',
      'name' => 'TheDeeThree'
    )
  );
      
  return array($message_test, $to_test);
}

/*
 * Populates array of test data for hook_mail key: dsdrip-momm13-x
 *
 * @param boolean|integer $test_flag
 *   Test flag that triggers the use of test data. When the flag is an integer
 *   invalid data is sent.
 */
function dosomething_mandrill_test_dsdrip_momm13($test_flag) {

  // Create different target email addresses for various tests running at the
  // same time
  $id_one = rand(0, 100);
  $id_two = rand(0, 100);

  // Bad data - missing 'rcpt
  if ($test_flag === 1) {

    // Missing 'message'
    $message_test = array(
      'message' => array(
        'merge_vars' => array(
          0 => array(
            'rcpt' => '',
            'vars' => array(
              0 => array(
                'content' => 'Dee',
                'name' => 'FNAME'
              )
            )
          ),
          1 => array(
            'rcpt' => 'dlee+dsevent-dsdrip-momm-fail02@dosomething.org',
            'vars' => array(
              0 => array(
                'content' => 'DeeThree',
                'name' => 'FNAME'
              )
            )
          )
        ),
        'to' => array(
          0 => array(
            'email' => '',
            'name' => 'Dee',
          ),
          1 => array(
            'email' => 'dlee+dsevent-dsdrip-momm-fail' . $id_one . '@dosomething.org',
            'name' => 'DeeThree',
          )
        )
      )
    );

    $to_test = array(
      0 => array(
        'email' => '',
        'name' => 'TheDee'
      ),
      1 => array(
        'email' => 'dlee+dsevent-dsdrip-momm-fail' . $id_one . '@dosomething.org',
        'name' => 'TheDeeThree'
      )
    );

  } // Good data
  else {

    $message_test = array(
      'message' => array(
        'merge_vars' => array(
          0 => array(
            'rcpt' => 'dlee+dsdrip-momm-' . $id_one . '@dosomething.org',
            'vars' => array(
              0 => array(
                'content' => 'Dee',
                'name' => 'FNAME'
              )
            )
          ),
          1 => array(
            'rcpt' => 'dlee+dsdrip-momm-' . $id_two . '@dosomething.org',
            'vars' => array(
              0 => array(
                'content' => 'DeeThree',
                'name' => 'FNAME'
              )
            )
          )
        ),
        'to' => array(
          0 => array(
            'email' => 'dlee+dsdrip-momm-' . $id_one . '@dosomething.org',
            'name' => 'TheDee',
          ),
          1 => array(
            'email' => 'dlee+dsdrip-momm-' . $id_two . '@dosomething.org',
            'name' => 'TheDeeThree',
          )
        )
      )
    );

    $to_test = array(
      0 => array(
        'email' => 'dlee+dsdrip-momm-' . $id_one . '@dosomething.org',
        'name' => 'TheDee'
      ),
      1 => array(
            'email' => 'dlee+dsdrip-momm-' . $id_two . '@dosomething.org',
        'name' => 'TheDeeThree'
      )
    );

  }

  return array($message_test, $to_test);
}
