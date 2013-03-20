<?php

/**
 *  Facebook service: Handles Facebook User ID handling and posting.
 */
class facebook extends SocialGraphService {
  /**
   *  @var integer $fbid;
   *    The user's Facebook ID;
   *
   *  @Graph\Column(name="fbid", type="integer", required="false")
   *  @Graph\Validate(regex="[0-9]+")
   *  @Graph\OneInGroup("social")
   */
  protected $fbid;

  public function __construct() { }

  public function add($fbid) {
    $this->add_property('fbid', $fbid);
  }

  public function update($fbid) {

  }

  public function delete($fbid) {

  }
}
