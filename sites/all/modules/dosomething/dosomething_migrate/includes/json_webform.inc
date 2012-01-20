<?php

abstract class DSJsonWebformMigration extends DSBaseWebformMigration {

  public function __construct($group = NULL, $node_type, $additional_fields = array()) {
    parent::__construct($group, $node_type);
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    $additional_fields = isset($additional_fields) ? $additional_fields : array();

    $this->source = new MigrateSourceMultiItems(
      new DSNodeJsonMigrateItems($base_url, $node_type),
      DSJsonNodeMigration::fetchFields($base_url, $node_type) + $additional_fields
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );
  }

  protected function fidFromEmField($value, $uid) {
    $wrappers = file_get_stream_wrappers();
    $scheme = file_uri_scheme($value);
    if (empty($wrappers[$scheme])) {
      var_dump("couldn't find a stream wrapper for $scheme");
      return NULL;
    }

    $file = file_uri_to_object($value);
    if (empty($file->fid)) {
      $file->uid = $uid;
      file_save($file);
    }
    return $file->fid;
  }
}
