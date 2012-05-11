<?php

/**
 * Activity to get a user's school ID from their mCommons profile.
 */
class ConductorActivityDSGetSchoolID extends ConductorActivity {
  public function run($workflow) {
    $state = $this->getState();

    // Mobile number to check profile for school id
    $mobile = $state->getContext('sms_number');

    $gateway = sms_gateways('gateways');
    $config = $gateway['sms_mobile_commons']['configuration'];
    $api_send_url = $config['sms_mobile_commons_custom_url'];
    $auth_string = $config['sms_mobile_commons_email'] . ':' . $config['sms_mobile_commons_password'];

    // Remove http or https at beginning of string.
    $api_send_url = str_replace('https://', '', $api_send_url);
    $api_send_url = str_replace('http://', '', $api_send_url);
    
    $api_check_user_url = 'https://' . $api_send_url . '/api/profile?phone_number=' . $mobile;

    $ch = curl_init();
    curl_setopt($ch,CURLOPT_HTTPAUTH,CURLAUTH_BASIC);
    curl_setopt($ch,CURLOPT_USERPWD,$auth_string); 
    curl_setopt($ch,CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch,CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch,CURLOPT_URL,$api_check_user_url);
    $mc_profile_xml = curl_exec($ch);
    curl_close($ch);

    $mc_profile = new SimpleXMLElement($mc_profile_xml);
    $error_check = $mc_profile->xpath("error");
    if (empty($error_check)) {
      $school_id_arr = $mc_profile->xpath("profile/custom_columns/custom_column[@name='School ID']");
      if (!empty($school_id_arr[0])) {
        $school_id = self::getCustomColumnValue($school_id_arr[0]);

        if (!empty($school_id)) {
          $this->getState()->setContext('school_id', $school_id);
        }
      }
    }

    $state->markCompeted();
  }

  /**
   * Pulls the value out of a custom_column tag 
   * @param $xml_obj SimpleXMLElement object for a custom_column
   * @return string of custom_column value
   */
  private function getCustomColumnValue($xml_obj) {
    // if it fails, just return the object back
    $return = $xml_obj;

    $xml_str = $xml_obj->asXml();
    if ($xml_str != '') {
      $value_start = strpos($xml_str, '>');
      if ($value_start !== FALSE) {
        $cull1 = substr($xml_str, $value_start+1);

        $value_end = strpos($cull1, '</');
        if ($value_end !== FALSE)
          $return = substr($cull1, 0, $value_end);
      }
    }

    return trim($return);
  }
}
                
