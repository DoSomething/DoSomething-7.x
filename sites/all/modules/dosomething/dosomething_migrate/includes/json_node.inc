<?php

abstract class DSJsonNodeMigration extends Migration {

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

  /**
   * @param $group
   * @param $node_type
   *   Source node type.
   * @param $additional_fields
   *   Array of fields to add in because you'll be creating them in prepareRow()
   */
  public function __construct($group = NULL, $node_type, $additional_fields = array()) {
    parent::__construct($group);

    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.dev.zivtech.com/migrate');

    $additional_fields = isset($additional_fields) ? $additional_fields : array();

    $this->source = new MigrateSourceMultiItems(
      new DSNodeJsonMigrateItems($base_url, $node_type),
      DSJsonNodeMigration::fetchFields($base_url, $node_type) + $additional_fields
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationNode::getKeySchema()
    );

    $this->destination = new MigrateDestinationNode($node_type);
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
