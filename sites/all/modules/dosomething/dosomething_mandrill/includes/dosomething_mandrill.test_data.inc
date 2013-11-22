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
 */
function dosomething_mandrill_test_data($op) {
  
  switch ($op) {

    case 'dsevent-birthday':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_birthday();
      break;

    case 'dsevent-reg-90':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_reg_90();
      break;

    case 'dsevent-reg-365':
      list($message_test, $to_test) = dosomething_mandrill_test_dsevent_reg_365();
      break;

    case 'dsdrip-momm13-1':
    case 'dsdrip-momm13-2':
    case 'dsdrip-momm13-3':
    case 'dsdrip-momm13-4':
    case 'dsdrip-momm13-5':
      list($message_test, $to_test) = dosomething_mandrill_test_dsdrip_momm13();
      break;

  }

  return array($message_test, $to_test);
}

/*
 * Populates array of test data for hook_mail key: dsevent-birthday
 */
function dosomething_mandrill_test_dsevent_birthday() {

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
 */
function dosomething_mandrill_test_dsevent_reg_90() {

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
 */
function dosomething_mandrill_test_dsevent_reg_365() {

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
 */
function dosomething_mandrill_test_dsdrip_momm13() {

  $message_test = array(
    'message' => array(
      'merge_vars' => array(
        0 => array(
          'rcpt' => 'dlee+dsevent-dsdrip-momm-01@dosomething.org',
          'vars' => array(
            0 => array(
              'content' => 'Dee',
              'name' => 'FNAME'
            )
          )
        ),
        1 => array(
          'rcpt' => 'dlee+dsevent-dsdrip-momm-02@dosomething.org',
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
          'email' => 'dlee+dsevent-dsdrip-momm-01@dosomething.org',
          'name' => 'TheDee',
        ),
        1 => array(
          'email' => 'dlee+dsevent-dsdrip-momm-02@dosomething.org',
          'name' => 'TheDeeThree',
        )
      )
    )
  );

  $to_test = 'doers@dosomething.org';

  return array($message_test, $to_test);
}
