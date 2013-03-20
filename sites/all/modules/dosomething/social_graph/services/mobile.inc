<?php

/**
 *  Mobile service: Handles phone numbers and SMS sending.
 */
class mobile extends SocialGraphService {
  /**
   *  @var varchar(255) $cell;
   *    The user's cell phone number.
   *
   *  @Graph\Column(name="cell", type="varchar", length="255", required="false")
   *  @Graph\Validate(regex="\d{3}\-?\d{3}\-?\d{4}")
   *  @Graph\OneInGroup("social")
   */
  protected $cell;

  public function __construct() {}

  public function add($cell) {
    $this->add_property('cell', $cell);
  }

  public function update($email) {

  }

  public function delete($email) {

  }
}
