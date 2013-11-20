<?php

/**
 * For use with the MLK 2013 SMS game. Users are prompted to send invites
 * to friends by replying with their phone numbers.
 *
 * We save that relationship between the inviter and the numbers they invited
 * for use letter.
 */
class ConductorActivityMLKGameInvite extends ConductorActivity {

  /**
   * Mobile Commons opt-in path for the Alpha inviter.
   *
   * @var int
   */
  public $alpha_optin = 140061;

  /**
   * Mobile Commons opt-in path for the Beta invitee.
   *
   * @var int
   */
  public $beta_optin = 140071;

  /**
   * Game ID for the MLK game.
   *
   * @var int
   */
  public $game_id = 1;

  /**
   * Game type override.
   *
   * @var string
   */
  public $type_override = 'sms_game';

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $user_response = $_REQUEST['args'];
    preg_match_all('#(?:1)?(?<numbers>\d{3}\d{3}\d{4})#i', preg_replace('#[^0-9]#', '', $user_response), $numbers);
    $numbers = $numbers['numbers'];
    
    $response = '';
    if (count($numbers) > 0) {
      $response .= 'We sent invites to these numbers:';
      foreach ($numbers as $number) {
        $response .= ' ' . $number;
      }
      $response .= '. Once one of your friends joins the cause, you\'ll be able to continue.';
    }
    else {
      $response .= 'Did you reply with any phone numbers? You\'ll need some help with this one. Text MLKFRIENDS to get some friends to join you.';
    }

    // Get user's first name to send in text. Default to mobile number if name can't be found.
    $inviter_name = $mobile;
    $account = dosomething_api_user_lookup($mobile);
    if ($account) {
      $profile = profile2_load_by_user($account);
      if (isset($profile['main'])) {
        $inviter_name = $profile['main']->field_user_first_name[LANGUAGE_NONE][0]['value'];
      }
    }

    $args = array(
      'mlk_game_inviter' => $inviter_name,
    );

    // Setup values and call sms_flow_start to save the alpha-beta relationship and opt-in users into next paths
    $form['details']['nid'] = $this->game_id;
    sms_flow_start($mobile, $this->alpha_optin, $this->beta_optin, $numbers, $form, $args, FALSE, $this->type_override);
    
    $state->setContext('sms_response', $response);
    $state->markCompleted();
  }

}