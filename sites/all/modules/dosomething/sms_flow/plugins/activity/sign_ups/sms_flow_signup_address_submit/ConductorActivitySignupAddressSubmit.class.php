<?php

/**
 * 
 */
class ConductorActivitySignupAddressSubmit extends ConductorActivity {

  public $addr1Context;
  public $cityContext;
  public $stateContext;
  public $zipContext;
  public $nameContext;
  public $campaignNid;

  public function run() {
    $state = $this->getState();

    $data = array();
    $data['nid'] = $this->campaignNid;
    $data['address1'] = $state->getContext($this->addr1Context);
    $data['address2'] = '';
    $data['city'] = $state->getContext($this->cityContext);
    $data['state'] = $state->getContext($this->stateContext);
    $data['zip'] = $state->getContext($this->zipContext);
    $data['name'] = $state->getContext($this->nameContext);
    $data['email'] = $state->getContext($this->emailContext);

    $sid = dosomething_campaign_submit_signup_address($data);

    $state->markCompleted();
  }
}