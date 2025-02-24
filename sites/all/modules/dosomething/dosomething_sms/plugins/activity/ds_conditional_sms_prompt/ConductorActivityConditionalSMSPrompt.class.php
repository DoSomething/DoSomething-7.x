<?php

/**
 * Checks whether or not to run an SMS Prompt activity if previous context values
 * match a given set. Otherwise, skips this activity.
 */
class ConductorActivityConditionalSMSPrompt extends ConductorActivitySMSPrompt {
  // Context of a previous activity to check against
  public $conditional_check = '';

  // Values to compare against the conditional_check context value. If any match,
  // then execute the normal sms_prompt parent activity
  public $run_on_conditional_values = array(); 

  public $check_type = 'array';
  public $isset_type = 'set';

  // Add more options for this activity
  public function option_definition() {
    $options = parent::option_definition();
    $options['conditional_check'] = array('default' => '');
    $options['run_on_conditional_values'] = array('default' => array());
    $options['check_type'] = array('default' => 'array');
    $options['isset_type'] = 'set';
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();

    // Get value of a previous context to check against
    $check_val = strtolower($state->getContext($this->conditional_check));

    // Cycle through conditional values looking for a match
    $bMatchFound = FALSE;
    if ($this->check_type == 'array') {
      foreach ($this->run_on_conditional_values as $success_val) {
        // Only looking for matches at the beginning of the string
        $pos = strpos($check_val, strtolower($success_val));
        if ($pos === 0) {
          $bMatchFound = TRUE;
        }
      }
    }
    else if ($this->check_type == 'isset') {
      if ($state->getContext($this->conditional_check) === FALSE) {
        if ($this->isset_type != 'set') {
          $bMatchFound = TRUE;
        }
      }
    }

    // If successfully found a matching value, then execute as an sms prompt
    if ($bMatchFound) {
      parent::run();
    }
    // Otherwise, end this activity and continue
    else {
      $state->markCompleted();
    }
  }
}
