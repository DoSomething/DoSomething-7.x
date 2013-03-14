<?php

/**
 * Primarily for SMS game use (ex: Would You Rather). Selects random Mobile Commons
 * opt-in path to send the user to. Ensures same opt-in path does not get sent again.
 */
class ConductorActivityGameRandomPath extends ConductorActivity {

  // Unique identifier for the SMS game
  public $game_id;

  // Array of possible opt-in paths to send the user to
  public $opt_in_paths = array();

  // Specific opt-in path to send user to after a specific number of times through this randomizer
  public $path_special = 0;

  // If > 0, send user to path_special on this iteration through the randomizer
  public $send_to_special_on = 0;

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Check DB for question sets we already sent this user to
    $started_paths = sms_flow_game_get_paths($mobile, $this->game_id);

    // Randomly select opt-in path to send user to
    $opt_in_path = 0;
    if ($this->send_to_special_on > 0 
        && $this->path_special > 0
        && count($started_paths) == $this->send_to_special_on - 1) {
      $opt_in_path = $this->path_special;
    }
    else {
      $path_selected = FALSE;
      $iter = 0; // fail-safe against an infinite loop
      while (!$path_selected && $iter < 1000) {
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
    }

    // Send user to selected opt-in path
    dosomething_general_mobile_commons_subscribe($mobile, $opt_in_path);

    try {
      // If no existing record, create one
      if (empty($started_paths)) {
        sms_flow_game_create_record($mobile, $this->game_id);
      }

      // Update existing record, adding the newly selected path
      $started_paths[] = $opt_in_path;
      sms_flow_game_set_paths($mobile, $this->game_id, $started_paths);
    }
    catch (Exception $e) {
      watchdog('sms_flow_game', 'ConductorActivityWYRGameStart exception - ' . $e->getMessage());
    }
    
    // Allow workflow to end without sending a response back to the user
    $state->setContext('ignore_no_response_error', TRUE);
    $state->markCompleted();
  }

}
