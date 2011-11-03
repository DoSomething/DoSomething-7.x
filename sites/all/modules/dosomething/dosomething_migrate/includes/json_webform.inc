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


    $this->source = new MigrateSourceMultiItems(
      new DSNodeJsonMigrateItems($base_url, $node_type),
      self::fetchFields($base_url, $node_type)
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );
  }

  protected function fidFromEmField($value, $uid) {
    $file = file_uri_to_object($value);
    if (empty($file->fid)) {
      $file->uid = $uid;
      file_save($file);
    }
    return $file->fid;
  }
}

class DSNodeJsonMigrateItems extends DSJsonMigrateItems {
  // Which node type are we looking at?
  protected $type;

  public function __construct($base_url, $type) {
    $this->listUrl = "{$base_url}/node/list/{$type}?page=:page";
    $this->countUrl = "{$base_url}/node/count";
    $this->getUrl = "{$base_url}/node/get/:id";
    $this->type = $type;
    parent::__construct();
  }

  public function computeCount() {
    $counts = &drupal_static(__METHOD__, NULL);

    migrate_instrument_start(__METHOD__);

    if (is_null($counts)) {
      // Try and fetch it.
      migrate_instrument_start("Retrieve $this->countUrl");
      $json = file_get_contents($this->countUrl);
      migrate_instrument_stop("Retrieve $this->countUrl");

      if ($json) {
        $counts = drupal_json_decode($json);
      }
    }

    migrate_instrument_stop(__METHOD__);

    return isset($counts[$this->type]) ? $counts[$this->type] : 0;
  }
}
