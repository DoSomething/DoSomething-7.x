<?php

/**
 * Given the systolic and diastolic values, sends response back with what their numbers mean.
 */
class ConductorActivitySmsBloodPressureResults extends ConductorActivity {

  public $systolic;
  public $diastolic;
  public $hypotension_msg;
  public $desired_msg;
  public $prehypertension_msg;
  public $hypertension1_msg;
  public $hypertension2_msg;
  public $hypertensive_crisis_msg;
  public $error_msg;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Get systolic and diastolic numbers from activity context
    $systolicNum = $state->getContext($this->systolic . ':message');
    $diastolicNum = $state->getContext($this->diastolic . ':message');

    $systolicNum = intval($systolicNum);
    $diastolicNum = intval($diastolicNum);

    // Default to error message
    $response = $this->error_msg;

    // Hypertensive Crisis. Systolic [180,infinity]. Diastolic [110,infinity]
    if ($systolicNum >= 180 || $diastolicNum >= 110) {
      $response = $this->hypertensive_crisis_msg;
    }
    // Stage 2 Hypertension. Systolic [160,180). Diastolic [100,110)
    elseif ($systolicNum >= 160 || $diastolicNum >= 100) {
      $response = $this->hypertension2_msg;
    }
    // Stage 1 Hypertension. Systolic [140,160). Diastolic [90,100)
    elseif ($systolicNum >= 140 || $diastolicNum >= 90) {
      $response = $this->hypertension1_msg;
    }
    // Prehypertension. Systolic [120,140). Diastolic [80,90)
    elseif ($systolicNum >= 120 || $diastolicNum >= 80) {
      $response = $this->prehypertension_msg;
    }
    // Desired. Systolic [90,120). Diastolic [60,80)
    elseif ($systolicNum >= 90 && $diastolicNum >= 60) {
      $response = $this->desired_msg;
    }
    // Hypotension. Systolic (0,90). Diastolic (0,60)
    elseif($systolicNum > 0 || $diastolicNum > 0) {
      $response = $this->hypotension_msg;
    }

    // If response is numeric, send to Mobile Commons as an opt-in path
    if (is_numeric($response)) {
      sms_mobile_commons_opt_in($mobile, $response);
      $state->setContext('ignore_no_response_error', TRUE);
    }
    // Else return the message from here
    else {
      $state->setContext('sms_response', $response);
    }

    $state->markCompleted();
  }
}