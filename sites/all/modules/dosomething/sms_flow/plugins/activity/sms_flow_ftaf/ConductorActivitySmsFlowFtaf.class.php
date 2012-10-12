<?php

/**
 *
 */
class ConductorActivitySmsFlowFtaf extends ConductorActivity {
  
  public function run($workflow) {
  	echo "[ConductorActivitySmsFlowFtaf]\n";
  	$state = $this->getState();
  	$mobile = $state->getContext('sms_number');

  	$state->setContext('sms_response', t('[SMS Flow FTAF]'));
  	$state->markCompeted();
  }
}
