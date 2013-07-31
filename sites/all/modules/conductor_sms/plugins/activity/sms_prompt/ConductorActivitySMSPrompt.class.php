<?php

/**
 * This is the first activity in any workflow.
 */
class ConductorActivitySMSPrompt extends ConductorActivity {

  public $question = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['question'] = array('default' => '');
    return $options;
  }

  public function question($question) {
    $this->question = $question;
    return $this;
  }


  /**
   * The start method performs no actions.
   */
  public function run() {
    $state = $this->getState();
    if (!$state->getContext('sms_number')) {
      $state->markFailed();
    }
    else if ($state->getContext($this->name . ':message') === FALSE) {
      $state->setContext('sms_response', $this->question);
      $state->markSuspended();
    }
    else {
      $state->markCompleted();
    }
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
