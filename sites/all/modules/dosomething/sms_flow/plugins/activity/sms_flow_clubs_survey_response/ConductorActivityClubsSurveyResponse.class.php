<?php

/**
 * Determines if user has responded with wanting to join the drive and if an
 * account is already associated with the number.
 *
 * Adjusts outputs array based on user's response.
 */
class ConductorActivityClubsSurveyResponse extends ConductorActivity {

  // Array of responses indicating an acceptance of the invite
  public $accept_responses = array();

  // Message returned to the user if they reject the invite
  public $invite_rejected_message = '';

  public function option_definition() {
    $options = parent::option_definition();
    $options['accept_responses'] = array('default' => array());
    $options['invite_rejected_message'] = array('default' => '');
    return $options;
  }

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $account = _sms_flow_find_user_by_cell($mobile);

    $q = db_select('node', 'n')
      ->fields('n', array('nid', 'uid'))
      ->condition('uid', $account->uid)
      ->condition('type', 'club')
      ->orderBy('created', 'DESC')
      ->range(0, 1)
      ->execute();

    $nodes = array();
    $r = reset($q->fetchAll());

    // Invite accepted
    if (self::hasAcceptResponse($_REQUEST['args'])) {

      $this->removeOutput('process_question2');
      $success_message .= t('Thanks! Go to http://doso.me/4 with your address and club members cell numbers, we’ll ask them shirt sizes and ship you the free shirts! While supplies last!!');
      $state->setContext('sms_response', $success_message);

      db_insert('dosomething_clubs_survey')
        ->fields(array(
          'cell' => $mobile,
          'nid' => $r->nid,
          'replied_y' => 1,
          'timestamp' => REQUEST_TIME,
        ))
        ->execute();
    }
    // Invite rejected. Output should be 'end'
    else if (self::hasDenyResponse($_REQUEST['args'])) {
      $this->removeOutput('end');

      db_insert('dosomething_clubs_survey')
        ->fields(array(
          'cell' => $mobile,
          'nid' => $r->nid,
          'replied_y' => 0,
          'timestamp' => REQUEST_TIME,
        ))
        ->execute();

      $deny_message = t('Righto. Why not? A) Ur club is no longer active B) U haven\'t been able to yet, but u want to C) U graduated D) U don\'t remember registering a DoSomething Club');
      $state->setContext('sms_response', $deny_message);
    }

    $data = array(
      'nid' => $r->nid,
      'uid' => $r->uid,
      'timestamp' => REQUEST_TIME
    );
    drupal_write_record('dosomething_clubs_sms_response', $data);

    $state->markCompleted();
  }

  private function hasAcceptResponse($response) {
    $response = strtolower($response);
    $response = trim($response);

    if (in_array($response, $this->accept_responses)) {
      return TRUE;
    }
    return FALSE;
  }

  private function hasDenyResponse($response) {
    $response = strtolower($response);
    $response = trim($response);

    if (in_array($response, $this->deny_responses)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }
}
