<?php

/**
 * Extends ConductorActivitySMSPrompt. Asks user a question and expects an MMS 
 * image in return.
 */
class ConductorActivityMMSPrompt extends ConductorActivitySMSPrompt {
  
  public function run($workflow) {
    $state = $this->getState();

    // If :has_prompted is not set, then this is first time through the activity
    // and should prompt the user with the question
    if ($state->getContext($this->name . ':has_prompted') === FALSE) {
      $state->setContext($this->name . ':has_prompted', TRUE);
      parent::run();
    }
    // Process user's response, expecting any mms to be in $_REQUEST['mms_image_url']
    // If none is set, end the activity regardless
    else {
      $mms_image_url = $_REQUEST['mms_image_url'];
      if (!empty($mms_image_url)) {
        $state->setContext($this->name . ':mms', $mms_image_url);
      }
      
      $state->markCompleted();
    }
  }

}