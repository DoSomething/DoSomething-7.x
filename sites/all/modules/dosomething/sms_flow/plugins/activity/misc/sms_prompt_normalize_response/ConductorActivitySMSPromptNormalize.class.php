<?php

/**
 * Extends ConductorActivitySMSPrompt. Prompts user for a response, then takes
 * that response and normalizes it against any known options.
 */
class ConductorActivitySMSPromptNormalize extends ConductorActivitySMSPrompt {

  // Expected structure of array
  // array(
  //   array(<normalized value>, <unnormalized response 1>, ..., <unnormalized repsonse n>),
  //   ...
  // );
  public $normalizedGroups = array();

  public function run($workflow) {
    parent::run();

    $state = $this->getState();
    $message = $state->getContext($this->name . ':message');
    if ($message !== FALSE) {
      foreach ($this->normalizedGroups as $group) {
        if (in_array($message, $group)) {
          // First item in array will be the normalized response
          $normalizedResponse = $group[0];
          $state->setContext($normalizedResponse, $this->name . ':message');
          break;
        }
      }
    }
  }

}