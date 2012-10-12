<?php

/**
 * Ends an activity, but then also places the user into a new one
 */
class ConductorActivityEndAndStartNew extends ConductorActivityEnd {

	public $next_workflow_name = '';

	public function option_definition() {
		$options = parent::option_definition();
		$options['next_workflow_name'] = array('default' => '');

		return $options;
	}

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $state->markCompeted();

    $state->setContext('start_new_workflow', $this->next_workflow_name);
  }

}
