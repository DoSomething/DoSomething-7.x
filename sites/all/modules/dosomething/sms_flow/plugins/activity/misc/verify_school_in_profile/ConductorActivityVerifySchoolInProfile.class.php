<?php

/**
 * Enum-style class specifying the type of response the user replies back with
 * after being prompted to verify the school.
 */
class UserResponseType {
  const YES = 0;
  const NO = 1;
  const INVALID = 2;
};

/**
 * After determining the user does have a school set in his profile, this activity
 * will prompt the user to verify the school that we do have for them and handle
 * his response accordingly.
 */
class ConductorActivityVerifySchoolInProfile extends ConductorActivity {
  
  // Message sent to user asking her to verify the school we have in her
  // profile. Use @school_name to insert the school name into the message.
  public $question = '';

  // Message sent to user if they reply with an invalid response
  public $invalid_response_msg = '';

  // Name of the output activity to go to if the school in the user profile is correct
  public $output_school_correct = '';

  // Name of the output activity to go to if the school in the user profile is incorrect
  public $output_school_incorrect = '';

  public function run() {
    $state = $this->getState();

    $userResponse = $state->getContext($this->name . ':message');
    if ($userResponse === FALSE) {
      $mobile = $state->getContext('sms_number');
      $schoolSid = $state->getContext('school_sid');

      // Get school name from the ds_school database
      $schoolName = db_query('SELECT name FROM ds_school WHERE `sid` = :sid', array(':sid' => $schoolSid))->fetchField();

      // Verify with the user that we have the correct school
      $state->setContext('selected_school_name', $schoolName);
      $state->setContext('sms_response', t($this->question, array('@school_name' => $schoolName)));

      // Await response
      $state->markSuspended();
    }
    else {
      $userResponse = trim(strtoupper($userResponse));
      $words = explode(' ', $userResponse);
      $firstWord = $words[0];

      // If response is yes, continue to questions
      if ($firstWord == 'Y' || $firstWord == 'YA' || $firstWord == 'YEA' || $firstWord == 'YES') {
        self::selectNextOutput(UserResponseType::YES);
      }
      // If response is no, continue to school searching
      elseif ($firstWord == 'N' || $firstWord == 'NO') {
        // Clear the selected_school_name context
        unset($state->context['selected_school_name']);

        self::selectNextOutput(UserResponseType::NO);
      }
      // If response is invalid, notify user and go to End
      else {
        $state->setContext('sms_response', $this->invalid_response_msg);
        self::selectNextOutput(UserResponseType::INVALID);
      }
    }
  }

  /**
   * Modify the outputs array to select the correct one to go to based on the
   * user's response to the verification prompt.
   */
  private function selectNextOutput($responseType) {
    if ($responseType == UserResponseType::YES) {
      // Go to the output activity for case where the school is correct
      $this->removeOutput($this->output_school_incorrect);
      $this->removeOutput('end');
    }
    elseif ($responseType == UserResponseType::NO) {
      // Go to the output activity for case where the school is incorrect
      $this->removeOutput($this->output_school_correct);
      $this->removeOutput('end');
    }
    else {
      // Go to the 'end' activity
      $this->removeOutput($this->output_school_correct);
      $this->removeOutput($this->output_school_incorrect);
    }

    $this->getState()->markCompleted();
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers(ConductorWorkflow $workflow = NULL) {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

}