<?php

/**
 *  Email service: handles all email addresses and email sending.
 */
class email extends SocialGraphService {
  /**
   *  @var varchar(255) $email;
   *    The user's Drupal ID.
   *
   *  @Graph\Column(name="email", type="varchar", length="255", required="false")
   *  @Graph\Validate(function="valid_email_address")
   *  @Graph\OneInGroup("social")
   */
  protected $email;

  public function __construct() {
  }

  public function add($email) {
    $this->add_property('email', $email);
  }

  public function update($email) {

  }

  public function delete($email) {

  }
}
