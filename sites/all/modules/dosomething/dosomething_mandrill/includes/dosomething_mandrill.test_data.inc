<?php

/*
 * Generate test data
 */
function dosomething_mandrill_test_data($op) {
  
  switch ($op):
  
    case 'BLA':
    
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
              'rcpt' => 'dlee+dsevent-BLA-01@dosomething.org',
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
              'rcpt' => 'dlee+dsevent-BLA-02@dosomething.org',
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
              'email' => 'dlee+dsevent-BLA-01@dosomething.org',
              'name' => 'TheDee',
            ),
            1 => array(
              'email' => 'dlee+dsevent-BLA-02@dosomething.org',
              'name' => 'TheDeeThree',
            )
          )
        )
      );
      
      $to_test = array(
        0 => array(
          'email' => 'dlee+dsevent-BLA-01@dosomething.org',
          'name' => 'TheDee'
        ),
        1 => array(
          'email' => 'dlee+dsevent-BLA-02@dosomething.org',
          'name' => 'TheDeeThree'
        )
      );
      
      break;
    
    case 'dsevent-birthday':
      
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
      
      break;
    
    case 'dsevent-reg-90':
      
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
      
      break;

    case 'dsevent-reg-365':
      
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
      
      break;
    
    case 'dsdrip-momm13-1':
      
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
      
      $to_test = array(
        0 => array(
          'email' => 'dlee+dsevent-dsdrip-momm-01@dosomething.org',
          'name' => 'TheDee'
        ),
        1 => array(
          'email' => 'dlee+dsevent-dsdrip-momm-02@dosomething.org',
          'name' => 'TheDeeThree'
        )
      );
      
      break;
  
    default:
      
      $message_test = 'Error - invalid operation (op)';
      $to_test = 'Error - invalid operation (op)';
      
  endswitch;
  
  return array($message_test, 'dotest@dosomething.org');
      
}