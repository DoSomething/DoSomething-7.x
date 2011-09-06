<?php

// Campaign Signup
abstract class DSCampaignSignupMigration extends DSBaseMigration {
  public function __construct($node_type) {
    // TODO: this is made up:
    $webform = node_load(29784);
    parent::__construct($webform, $node_type);
  }
}

class DSCampaignSignupEbdMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('ebd_signup');
    $this->description = 'Epic Book Drive Signup';
  }
}

class DSCampaignSignupGysMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('gys_2011');
    $this->description = 'Green Your School 2011';
  }
}

class DSCampaignSignupHealthySchoolsMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('healthy_schools');
    $this->description = 'Healthy Schools';
  }
}

class DSCampaignSignupIncreaseYourGreenMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('increaseyourgreen_signup');
    $this->description = 'Increase Your Green Signup';
  }
}

class DSCampaignSignupScavengerMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('scavenger_2011_signup');
    $this->description = 'scavenger_2011_signup';
  }
}

class DSCampaignSignupStaplesMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('staples_2011_signup');
    $this->description = 'Staples 2011 Signup';
  }
}

class DSCampaignSignupTackleHungerMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('tackle_hunger');
    $this->description = 'Tackle Hunger';
  }
}