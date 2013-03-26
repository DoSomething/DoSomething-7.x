<?php

namespace SocialGraph\Services;
use SocialGraph\SocialGraphService;

/**
 *  Facebook service: Handles Facebook User ID handling and posting.
 */
class Facebook extends SocialGraphService {
  /**
   *  @var integer $fbid;
   *    The user's Facebook ID;
   *
   *  @Graph\Column(name="fbid", type="integer", required="false")
   *  @Graph\Validate(regex="[0-9]+")
   *  @Graph\OneInGroup("social")
   */
  protected $fbid;

  /**
   *  @var integer $profile_pic
   *    The user's Facebook Profile Picture
   *
   *  @Graph\Column(name="profile_pic", type="varchar", length="255", required="false")
   */
  protected $profile_pic;

  public function __construct() { }

  public function add($fbid) {
    $this->add_property('fbid', $fbid);
  }

  public function update($fbid) {

  }

  public function delete($fbid) {

  }
}
