<?php

// Scholarship Application

abstract class DSScholarshipApplicationMigration extends DSBaseMigration {
  public function __construct($node_type) {
    // TODO: this is made up:
    $webform = node_load(18);
    parent::__construct($webform, $node_type);
  }
}


class DSScholarshipApplicationGeneralMigration extends DSScholarshipApplicationMigration {
  public function __construct($webform) {
    parent::__construct('general_scholarship_app');
    $this->description = 'General Scholarship Application';
    $this->addFieldMapping('name', 'field_name');
    $this->addFieldMapping('school', 'field_plumgrant_highschool');
    $this->addFieldMapping('email', 'field_email');
    $this->addFieldMapping('mobile', 'field_phone_number');
    $this->addFieldMapping('zip', 'field_zip_code_2');
  }
}

class DSScholarshipApplicationAttMigration extends DSScholarshipApplicationMigration {
  public function __construct() {
    parent::__construct('scholarships_att');
    $this->description = 'Scholarships ATT';
  }
}

class DSScholarshipApplicationSixFlagsMigration extends DSScholarshipApplicationMigration {
  public function __construct() {
    parent::__construct('sixflags_scholarships_app');
    $this->description = 'Six Flags Friends Scholarships';
    $this->addFieldMapping('name', 'field_plumgrant_name');
    $this->addFieldMapping('school', 'field_plumgrant_highschool');
    $this->addFieldMapping('email', 'title');
    $this->addFieldMapping('mobile', 'field_yacapp_phone');
    $this->addFieldMapping('zip', 'field_zip_code');
  }
}