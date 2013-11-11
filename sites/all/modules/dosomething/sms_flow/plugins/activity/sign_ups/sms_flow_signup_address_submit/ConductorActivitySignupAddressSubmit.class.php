<?php

/**
 * Gathers data from previous Conductor Activities for a campaign sign up
 * that requires address information. Then submits this data to the appropriate
 * node id.
 */
class ConductorActivitySignupAddressSubmit extends ConductorActivity {

  // Context name to get Street Address 1
  public $addr1Context;

  // Context name to get the address's city
  public $cityContext;

  // Context name to get the address's state
  public $stateContext;

  // Context name to get the address's zipcode
  public $zipContext;

  // Context name to get the person's name to ship to
  public $nameContext;

  // Node id of the campaign the shipping information is being submitted for
  public $campaignNid;

  public function run() {
    $state = $this->getState();
    $mobile = $state->getContext('sms_number');

    // Compile data from other contexts
    $data = array();

    $user = sms_flow_get_or_create_user_by_cell($mobile);
    $data['uid'] = $user->uid;

    $data['nid'] = $this->campaignNid;
    $data['address1'] = $state->getContext($this->addr1Context);
    $data['address2'] = '';
    $data['city'] = $state->getContext($this->cityContext);
    $data['state'] = $state->getContext($this->stateContext);
    $data['zip'] = $state->getContext($this->zipContext);
    $data['name'] = $state->getContext($this->nameContext);
    $data['email'] = '';

    // Then submit the data
    $sid = dosomething_campaign_submit_signup_address($data);

    $state->markCompleted();
  }

}