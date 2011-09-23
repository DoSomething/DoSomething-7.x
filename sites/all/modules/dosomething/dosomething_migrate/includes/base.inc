<?php

abstract class DSBaseWebformMigration extends Migration {
  protected $webform;

  public function __construct($group = NULL, $node_type) {
    parent::__construct($group);

    $webform_nids = variable_get('webform_migrate_webform_mapping', array());
    $this->webform = node_load($webform_nids[$node_type]);
    if (!$this->webform) {
      var_dump(t('WARNING: @name has no webform node.', array('@name' => $node_type)));
    }

    $this->issuePattern = 'https://zivtech.unfuddle.com/a#/projects/38035/tickets/by_number/:id:';

    $this->destination = new MigrateDestinationWebformSubmissionEntity($this->webform);

    $this->addFieldMapping('sid', 'nid')
      ->description("Make the node id the submission id for easy redirection if we need to.");
    $this->addFieldMapping('uid', 'uid')
      ->description("User ids should be a direct mapping.");
    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')
      ->description("Use the node creation date as the webform submission date.");
    $this->addFieldMapping('remote_addr')
      ->defaultValue('127.0.0.1')
      ->description("I don't think we have an IP to use as the submission so I'm using the loopback.");
    $this->addFieldMapping('path', 'path')
      ->issuePriority(MigrateFieldMapping::ISSUE_PRIORITY_LOW)
      ->description("Not sure if the webform submissions support paths.");
    $this->addUnmigratedSources(array('promote', 'sticky', 'language'));
  }

  // public function prepareRow($row) {
  //   var_dump($row);
  // }

  // public function prepare($entity, stdClass $row) {
  //   var_dump($row);
  //   var_dump($entity);
  // }
}

abstract class DSBaseUserMigration extends Migration {
  public function __construct($group = NULL) {
    parent::__construct($group);

    $this->issuePattern = 'https://zivtech.unfuddle.com/a#/projects/38035/tickets/by_number/:id:';
  }
}
