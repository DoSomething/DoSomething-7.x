<?php

/**
 * Given the mdata_id that the request comes from, the activity selects a 
 * random Mobile Commons opt-in path to send the user to. It also ensures that
 * the same opt-in path does not get sent again until they're all exhausted.
 */
class ConductorActivityMobileCommonsRandomPath extends ConductorActivity {
  
  // Entity containing info for each grouped set of opt-in paths to be randomized
  // Expected elements:
  // $sets = array(
  //           array(
  //             'mdata_id'     //
  //             'game_id'      // Unique identifier for an SMS game
  //             'opt_in_paths' // Array of possible opt-in paths to send the user to
  //             'path_special' // Specific opt-in path to send user to after a specific number of times through this randomizer
  //             'send_to_special_on' // If > 0, send user to path_special on this iteration through the randomizer
  //           ),
  //           ...
  //         )
  public $sets = array();

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');
    $mdataID = intval($_REQUEST['mdata_id']);

    // Find the set with the matching mdata_id
    $setIndex = -1;
    for ($i = 0; $i < count($this->sets); $i++) {
      if ($this->sets[$i]['mdata_id'] == $mdataID) {
        $setIndex = $i;
        break;
      }
    }

    if ($setIndex >= 0) {
      $set = $this->sets[$setIndex];
      if (count($set['opt_in_paths']) == 0) {
        watchdog('sms_flow_game', 'ConductorActivityMobileCommonsRandomPath set missing opt_in_paths for mdata_id = ' . $mdataID);
      }
      else {
        // Check DB for question sets we already sent this user to
        $started_paths = sms_flow_game_get_paths($mobile, $set['game_id']);

        // Randomly select opt-in path to send user to
        $opt_in_path = 0;
        if (isset($set['send_to_special_on']) && $set['send_to_special_on'] > 0
            && isset($set['path_special']) && $set['path_special'] > 0
            && count($started_paths) == $set['send_to_special_on'] - 1) {
          $opt_in_path = $set['path_special'];
        }
        else {
          $path_selected = FALSE;
          $iter = 0; // fail safe against an infinite loop
          while (!$path_selected && $iter < 1000) {
            $iter++;
            $selected_idx = rand(0, count($set['opt_in_paths']) - 1);
            $opt_in_path = $set['opt_in_paths'][$selected_idx];

            // Ensure selected path hasn't already been chosen for the user
            if (empty($started_path)
                || count($started_paths) == count($set['opt_in_paths'])
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
            sms_flow_game_create_record($mobile, $set['game_id']);
          }

          // Update existing record, adding the newly selected path
          $started_paths[] = $opt_in_path;
          sms_flow_game_set_paths($mobile, $set['game_id'], $started_paths);
        }
        catch (Exception $e) {
          watchdog('sms_flow_game', 'ConductorActivityMobileCommonsRandomPath exception - ' . $e->getMessage());
        }
      }

      $state->setContext('ignore_no_response_error', TRUE);
    }
    else {
      $state->setContext('sms_response', 'Sorry. We\'ve run into a problem. :(');
    }

    $state->markCompleted();
  }
}