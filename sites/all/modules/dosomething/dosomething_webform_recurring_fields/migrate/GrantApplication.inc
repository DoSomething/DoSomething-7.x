<?php

// Grant Application

abstract class DSGrantApplicationMigration extends DSBaseNodeMigration {
  public function __construct($node_type) {
    // FIXME: made up node id.
    $webform = node_load(18);
    parent::__construct($webform, $node_type);
  }
}


class DSGrantApplicationAspcaMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('aspca_grant_app');
    $this->description = 'ASPCA Grant App';
    $this->addFieldMapping('name', 'field_your_name');
    $this->addFieldMapping('address', 'field_your_address');
    $this->addFieldMapping('city', 'field_city_0');
    $this->addFieldMapping('state', 'field_state_plain');
    $this->addFieldMapping('zip', 'field_zip_code_0');
    $this->addFieldMapping('mobile', 'field_phone_number_1');
    $this->addFieldMapping('email', 'field_your_email_address');
  }
}

class DSGrantApplicationGeneralMigration extends DSGrantApplicationMigration {
  public function __construct() {
   parent::__construct('general_grant_app');
    $this->description = 'General Grant Application';
  }
}

class DSGrantApplicationGrantMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant');
    $this->description = 'Grant';
  }
}

class DSGrantApplicationGrantJudgeMigration extends DSGrantApplicationMigration {
  public function __construct() {
    parent::__construct('grant_judge');
    $this->description = 'Grant Judging Form';
  }
}