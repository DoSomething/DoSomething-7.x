<?php

namespace SocialGraph\Service;

class User extends \SocialGraphService {
  /**
   *  @var integer $uid;
   *    The user's Drupal ID.
   *
   *  @Graph\Column(name="uid", type="integer", required="false")
   *  @Graph\Validate(regex="\d+")
   *  @Graph\OneInGroup("social")
   */
  protected $uid;

  /**
   *  @var string $first_name;
   *    The user's first name.
   *
   *  @Graph\Column(name="first_name", type="varchar", length="255", required="false")
   *  @Graph\Validate(regex="[A-Za-z\-\s\']+")
   */
  protected $first_name;

  /**
   *  @var string $last_name;
   *    The user's last name.
   *
   *  @Graph\Column(name="last_name", type="varchar", length="255", required="false")
   *  @Graph\Validate(regex="[A-Za-z\s\-\']+")
   */
  protected $last_name;

  /**
   *  @var object $facebook
   *    The user's facebook credentials.
   *  
   *  @Graph\Contains("\SocialGraph\Services\Facebook")
   */
  protected $facebook;

  public function __construct() { }

  public function add($args) {
	  $this->add_property($args[1], $args[0]);
  }

  public function update($email) {

  }

  public function delete($email) {

  }
}
