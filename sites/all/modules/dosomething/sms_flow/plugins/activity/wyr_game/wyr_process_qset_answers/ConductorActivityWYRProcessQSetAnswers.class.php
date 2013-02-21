<?php

/**
 * Process the user's answer to the last question. 
 */
class ConductorActivityWYRProcessQSetAnswers extends ConductorActivity {

  // Unique identifier for the SMS game
  public $game_id;

  // Type of entry to submit to the sms_flow_records table
  public $type_override;

  // Opt-in path that has triggered this workflow. And in turn should also
  // be forwarded along to any invited friends.
  private $incoming_opt_in_path;

  // User's answer to Q4. Equals 0 for invalid, 1 for option 1, and 2 for option 2.
  private $user_answer;

  // Array containing answers and responses grouped by the opt-in path the user is coming from
  private $answer_sets = array(
    '142223' => array(
      'opt1_valid_answers' => array('eat tuna', 'a', 'a eat tuna', 'a eat tuna every day for a month', 'a eat tuna every day', 'a tuna every day for a month', 'a tuna every day', 'a) eat tuna', 'a) eat tuna every day for a month', 'a) eat tuna every day', 'a) tuna every day for a month', 'a) tuna every day', 'a. eat tuna', 'a. eat tuna every day for a month', 'a. eat tuna every day', 'a. tuna every day for a month', 'a. tuna every day'),
      'opt2_valid_answers' => array('eat ramen', 'b', 'b eat tuna', 'b eat ramen every day for a month', 'b eat ramen every day', 'b ramen every day for a month', 'b ramen every day', 'b) eat ramen', 'b) eat ramen every day for a month', 'a) eat ramen every day', 'b) ramen every day for a month', 'b) ramen every day', 'b. eat ramen', 'b. eat ramen every day for a month', 'b. eat ramen every day', 'b. ramen every day for a month', 'b. ramen every day'),
      'sms_response_opt1' => 'That would cost less than $1000, but that\'s pretty nasty. Want better avice on saving $$? Text TIPS. Or, text a friend\'s number to see what they\'d do.',
      'sms_response_opt2' => 'That would cost less than $300/yr, but it\'s not very healthy. Want better advice on saving $$? Text TIPS. Or, text a friend\'s number to see what they\'d do',
    ),
    '142503' => array(
      'opt1_valid_answers' => array('get internet at the library', 'a', 'a) access the internet only at the library', 'a) access internet at the library', 'a) go to the library', 'access the internet at the library', 'go to the library', 'the library', 'library', 'a access the internet only at the library', 'a access internet at the library', 'a go to the library'),
      'opt2_valid_answers' => array('only get internet w ur parents home', 'b', 'b) only with my parents watching at home', 'only with my parents watching', 'only with my parents', 'my parents watching', 'get internet with my parents watching', 'get internet w my parents at home', 'b) only with my parents watching', 'b) only with my parents', 'b) my parents watching', 'b) get internet with my parents watching', 'b) get internet w my parents at home'),
      'sms_response_opt1' => 'Internet can be $100-500 per year, yikes! Want some easier ways to save money? Text TIPS. Or, text a friend\'s number to see what they\'d do',
      'sms_response_opt2' => 'Internet can be $100-500 per year, yikes! Want some easier ways to save money? Text TIPS. Or, text a friend\'s number to see what they\'d do',
    ),
    '143053' => array(
      'opt1_valid_answers' => array('have a flip phone', 'swap my smartphone for a flip phone', 'get a flip phone', 'flip phone', 'a', 'a) have a flip phone', 'a) swap my smartphone for a flip phone', 'a) get a flip phone', 'a) flip phone', 'a have a flip phone', 'a swap my smartphone for a flip phone', 'a get a flip phone', 'a flip phone'),
      'opt2_valid_answers' => array('give up your car', 'swap my car for a bike', 'swap my car for a bicycle', 'swap my car', 'get a bike', 'get a bicycle', 'swap my car', 'b', 'b)', 'b swap my car for a bike', 'b swap my car for a bicycle', 'b swap my car for a bicycle', 'b swap my car', 'b get a bike', 'b get a bicycle', 'b swap my car', 'b) swap my car for a bike', 'b) swap my car for a bicycle', 'b) swap my car for a bicycle', 'b) swap my car', 'b) get a bike', 'b) get a bicycle', 'b) swap my car'),
      'sms_response_opt1' => 'That could save you up to $500/yr, but then you lose Angry Birds. Want an easier way to save money? Text TIPS. Or, respond w/ a friends number to see what they\'d do',
      'sms_response_opt2' => 'That could save you up to $2000/yr in gas. Not bad. Want an easier way to save money? Text TIPS. Or, respond w a friends number to see what they\'d do',
    ),
  );

  public function run($workflow) {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    $ftaf_number = $state->getContext($this->name . ':message');
    if ($ftaf_number === FALSE) {
      // Get opt-in path from parameters
      $this->incoming_opt_in_path = $_REQUEST['opt_in_path_id'];

      // Get WYR answers
      $q1_answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q1_answer');
      $q2_answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q2_answer');
      $q3_answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q3_answer');
      $q4_answer = self::getMobileCommonsProfileValue($mobile, 'profile_wyr_q4_answer');

      // Since question 4 is the answer the user is sending to this activity, we can also
      // check the args parameters if q4_answer is still empty
      if (empty($q4_answer)) {
        $q4_answer = $_REQUEST['args'];
      }

      // Normalize answer
      $q4_answer = self::normalizeAnswer($q4_answer, $this->incoming_opt_in_path);

      // Update Mobile Commons with normalized answer
      self::updateMobileCommonsProfile($mobile, 'wyr_q4_answer', $q4_answer);

      // Get any previous answers for this user from the DB
      $answers = sms_flow_game_get_answers($mobile, $this->game_id);

      if (empty($answers)) {
        $answers = array();
      }

      // Save new answers to the DB
      $answers[$this->incoming_opt_in_path] = array();
      $answers[$this->incoming_opt_in_path][] = $q1_answer;
      $answers[$this->incoming_opt_in_path][] = $q2_answer;
      $answers[$this->incoming_opt_in_path][] = $q3_answer;
      $answers[$this->incoming_opt_in_path][] = $q4_answer;

      sms_flow_game_set_answers($mobile, $this->game_id, $answers);

      // Find Alpha inviter, if any, and send Alpha the feedback message
      $alpha_mobile = sms_flow_find_alpha(substr($mobile, -10), $this->game_id, $this->type_override);
      if ($alpha_mobile) {
        $alpha_msg = "Your friend ($mobile) said they'd rather $q1_answer, $q2_answer, $q3_answer, and $q4_answer. Want to play more. Text WYR.";
        sms_mobile_commons_send($alpha_mobile, $alpha_msg);
      }

      // Send response back to the user
      if ($this->user_answer == 1) {
        $sms_response = $this->answer_sets[$this->incoming_opt_in_path]['sms_response_opt1'];
      }
      else {
        $sms_response = $this->answer_sets[$this->incoming_opt_in_path]['sms_response_opt2'];
      }

      $state->setContext('sms_response', $sms_response);
      $state->markSuspended();
    }
    else {
      $state->setContext('ftaf_prompt:message', $ftaf_number);
      $state->setContext('ftaf_beta_optin', $this->incoming_opt_in_path);
      $state->setContext('ftaf_id_override', $this->game_id);
      $state->setContext('ftaf_type_override', $this->type_override);

      $state->markCompleted();
    }
  }

  /**
   * Implements ConductorActivity::getSuspendPointers().
   */
  public function getSuspendPointers() {
    return array(
      'sms_prompt:' . $this->getState()->getContext('sms_number')
    );
  }

  /**
   * Search through possible answers, and if one matches, return the value at
   * the first index of the array to be the answer.
   */
  private function normalizeAnswer($answer, $opt_in_path_id) {
    $answer = strtolower($answer);
    if (in_array($answer, $this->answer_sets[$opt_in_path_id]['opt1_valid_answers'])) {
      $this->user_answer = 1;
      return $this->answer_sets[$opt_in_path_id]['opt1_valid_answers'][0];
    }
    elseif (in_array($answer, $this->answer_sets[$opt_in_path_id]['opt2_valid_answers'])) {
      $this->user_answer = 2;
      return $this->answer_sets[$opt_in_path_id]['opt2_valid_answers'][0];
    }
    else {
      $this->user_answer = 0;
      return NULL;
    }
  }

  /**
   * Updates Mobile Commons profile
   */
  private function updateMobileCommonsProfile($mobile, $update_field, $update_value) {
    $url = "https://secure.mcommons.com/api/profile_update";

    $fields = array(
      'phone_number' => urlencode($mobile),
      $update_field => urlencode($update_value),
    );

    $fields_query = http_build_query($fields);

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_POST, count($fields));
    curl_setopt($ch, CURLOPT_POSTFIELDS, $fields_query);
    curl_exec($ch);
    curl_close($ch);
  }

  /**
   * Gets value from Mobile Commons profile field. Checks the $_REQUEST
   * parameters first. If not there, then goes straight to the profile.
   */
  private function getMobileCommonsProfileValue($mobile, $field_name) {
    // Pull the value from $_REQUEST parameters if they're there
    if (!empty($_REQUEST[$field_name])) {
      return $_REQUEST[$field_name];
    }
    // Otherwise go to Mobile Commons for the value
    else {
      $url = "https://secure.mcommons.com/api/profile?phone_number=$mobile";

      $ch = curl_init();
      curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      curl_setopt($ch, CURLOPT_USERPWD, "developers@dosomething.org:80276608");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
      curl_setopt($ch, CURLOPT_URL, $url);
      $xml = curl_exec($ch);
      curl_close();

      // Strip off 'profile_' from the beginning of the string
      $field_name = str_replace('profile_', '', $field_name);
      return self::getFieldValueFromXml($xml, $field_name);
    }
  }

  /**
   * Use regex to parse xml and pull field value out
   */
  private function getFieldValueFromXml($xml, $field_name) {
    $pattern = '#\<custom_column name\="' . $field_name . '"\>(.*?)\<\/custom_column\>#is';
    preg_match($pattern, $xml, $patternMatches);
    if (count($patternMatches) >= 2) {
      return trim($patternMatches[1]);
    }

    return NULL;
  }
}
