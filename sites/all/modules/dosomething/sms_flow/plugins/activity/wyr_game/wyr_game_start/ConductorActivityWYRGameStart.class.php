<?php

/**
 * Starting point for the Would You Rather SMS quiz game. Selects random question
 * set to send the user to. Ensures same question set does not get sent again.
 */
class ConductorActivityWYRGameStart extends ConductorActivity {

  // Unique identifier for the SMS game
  public $game_id;

  // Array of possible opt-in paths to send the user to
  public $opt_in_paths = array();

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Check DB for question sets we already sent this user to
    $started_paths = sms_flow_game_get_paths($mobile, $this->game_id);

    // Randomly select opt-in path to send user to
    $opt_in_path = 0;
    $path_selected = FALSE;
    $iter = 0; // fail-safe against an infinite loop
    while (!$path_selected && $iter < 100) {
      $iter++;
      $selected_idx = rand(0, count($this->opt_in_paths)-1);
      $opt_in_path = $this->opt_in_paths[$selected_idx];

      // Ensure selected path hasn't already been chosen for the user
      if (empty($started_paths) 
          || count($started_paths) == count($this->opt_in_paths)
          || !in_array($opt_in_path, $started_paths)) {
        $path_selected = TRUE;
      }
    }

    // Send user to selected opt-in path
    dosomething_general_mobile_commons_subscribe($mobile, $opt_in_path);

    // If no existing record, create one
    if (empty($started_paths)) {
      sms_flow_game_create_record($mobile, $this->game_id);
    }

    // Update existing record, adding the newly selected path
    $started_paths[] = $opt_in_path;
    sms_flow_game_set_paths($mobile, $this->game_id, $started_paths);
    
    // Allow workflow to end without sending a response back to the user
    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

}
