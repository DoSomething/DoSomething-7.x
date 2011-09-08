<?php

// Campaign Signup

abstract class DSCampaignSignupMigration extends DSBaseNodeMigration {
  public function __construct($node_type) {
    // FIXME: made up node id.
    $webform = node_load(18);
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
    $this->addFieldMapping('name', 'title');
    $this->addFieldMapping('school', 'field_school_name');
    $this->addFieldMapping('email', 'field_campaign_email');
    $this->addFieldMapping('mobile', 'field_campaign_phone_0');
  }
}

class DSCampaignSignupTackleHungerMigration extends DSCampaignSignupMigration {
  public function __construct() {
    parent::__construct('tackle_hunger');
    $this->description = 'Tackle Hunger';
  }
}