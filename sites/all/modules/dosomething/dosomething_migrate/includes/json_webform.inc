<?php

abstract class DSJsonWebformMigration extends DSBaseWebformMigration {
  static function fetchFields($base_url, $node_type) {
    $cid = "DSBaseNodeMigration:$base_url";
    $cache = cache_get($cid);
    if ($cache !== FALSE && is_array($cache->data)) {
      return $cache->data[$node_type];
    }

    $json = file_get_contents($base_url . '/node/fields');
    if ($json) {
      $fields = drupal_json_decode($json);
      if ($fields && is_array($fields)) {
        cache_set($cid, $fields);
        return $fields[$node_type];
      }
    }

    return FALSE;
  }


  public function __construct($group = NULL, $node_type) {
    parent::__construct($group, $node_type);
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    $this->source = new MigrateSourceList(
      new DSNodeListJSON($base_url, $node_type),
      new DSNodeItemJSON($base_url, $node_type),
      self::fetchFields($base_url, $node_type)
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );
  }
}

class DSNodeListJSON extends DSListJSON {
  protected $type;

  public function __construct($base_url, $type) {
    parent::__construct("{$base_url}/node/list/{$type}?page=:page", array());
    $this->countUrl = "{$base_url}/node/count";
    $this->type = $type;
  }

  public function computeCount() {
    $data = parent::computeCount();
    return $data[$this->type];
  }
}

class DSNodeItemJSON extends DSItemJSON {
  public function __construct($base_url, $type) {
    parent::__construct("{$base_url}/node/get/:id", array());
  }

  protected function loadJSONUrl($item_url) {
    $item = parent::loadJSONUrl($item_url);

    return $item;
  }
}
