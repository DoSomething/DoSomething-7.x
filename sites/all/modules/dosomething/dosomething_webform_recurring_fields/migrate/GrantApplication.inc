<?php

// Grant Application
abstract class DSGrantApplicationMigration extends DSBaseMigration {
  public function __construct($node_type) {
    // TODO: this is made up:
    $webform = node_load(329866);
    parent::__construct($webform, $node_type);
  }
}

class DSGrantApplicationAspcaMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct('aspca_grant_app');
    $this->description = 'ASPCA Grant App';
  }
}

class DSGrantApplicationGeneralMigration extends DSBaseMigration {
  public function __construct() {
   parent::__construct('general_grant_app');
    $this->description = 'General Grant Application';
  }
}

class DSGrantApplicationGrantMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct('grant');
    $this->description = 'Grant';
  }
}

class DSGrantApplicationGrantJudgeMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct('grant_judge');
    $this->description = 'Grant Judging Form';
  }
}