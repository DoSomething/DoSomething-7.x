<?php

class DSUserMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct();
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://dosomething6.local/migrate');

    $fields = array();
    $json = file_get_contents("{$base_url}/user/fields");
    if ($json) {
      $data = drupal_json_decode($json);
      $fields = $data[$node_type];
    }

    $this->source = new MigrateSourceList(
      new DSUserListJSON($base_url, $node_type),
      new DSUserItemJSON($base_url, $node_type),
      $fields
    );

    $this->destination = new MigrateDestinationUser();

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationUser::getKeySchema()
    );

    // $this->highwaterField = array(
    //   'name' => 'changed',
    //   'type' => 'int',
    // );
  }
}

class DSUserListJSON extends DSListJSON {
  public function __construct($base_url) {
    parent::__construct("{$base_url}/user/list/{$type}?page=:page", array());
    $this->countUrl = "{$base_url}/user/count";
  }
}

class DSUserItemJSON extends DSItemJSON {
  public function __construct($base_url) {
    parent::__construct("{$base_url}/user/get/:id", array());
  }
}