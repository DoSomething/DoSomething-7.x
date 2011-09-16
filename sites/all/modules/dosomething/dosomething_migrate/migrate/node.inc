<?php

abstract class DSBaseNodeMigration extends DSBaseMigration {
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


  public function __construct($node_type) {
    parent::__construct();
    $this->dependencies = array();

    $webform_nids = variable_get('webform_migrate_webform_mapping', array());
    $webform = node_load($webform_nids[$node_type]);

    $base_url = variable_get('ds_migrate_url', 'http://dosomething6.local/migrate');

    $this->source = new MigrateSourceList(
      new DSNodeListJSON($base_url, $node_type),
      new DSNodeItemJSON($base_url, $node_type),
      self::fetchFields($base_url, $node_type)
    );

    $this->destination = new MigrateDestinationWebformSubmissionEntity($webform);

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );

    $this->highwaterField = array(
      'name' => 'changed',
      'type' => 'int',
    );

    $this->addFieldMapping('sid', 'nid');
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('is_draft')->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')->defaultValue(time());
    $this->addFieldMapping('remote_addr')->defaultValue('127.0.0.1');

    $this->issuePattern = 'https://zivtech.unfuddle.com/a#/projects/38035/tickets/by_number/:id:';

    // $this->addFieldMapping('name')->defaultValue('humbert');
    // $this->addFieldMapping('zip')->defaultValue('zippy');

    // $this->addFieldMapping('data_date')->defaultValue('2011-12-31');
    // $this->addFieldMapping('data_email')->defaultValue('foo@example.com');
    // $this->addFieldMapping('data_file')->defaultValue(11);
    // $this->addFieldMapping('data_markup', 'body')->defaultValue('<p><em>itals!</em></p>');
    // $this->addFieldMapping('data_pagebreak')->defaultValue('IGNORED!');
    // $this->addFieldMapping('data_select')->defaultValue('foo');
    // $this->addFieldMapping('data_text', 'type');
    // $this->addFieldMapping('data_textarea', 'title');
    // $this->addFieldMapping('data_time')->defaultValue('2:03pm');
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

    foreach ($item as $name => &$value) {
      // Flatten out single value fields.
      if (strpos($name, 'field_') === 0 && count($value) == 1) {
        // This looks bad but isset() returns false for null values:
        // http://stackoverflow.com/questions/418066/best-way-to-test-for-a-variables-existence-in-php-isset-is-clearly-broken
        if (is_object($value[0])) {
          if (property_exists($value[0], 'value')) {
            $value = $value[0]->value;
          }
          else if (property_exists($value[0], 'nid')) {
            $value = $value[0]->nid;
          }
          else if (property_exists($value[0], 'uid')) {
            $value = $value[0]->uid;
          }
          else if (property_exists($value[0], 'url')) {
            $value = $value[0]->url;
          }
          else {
            $value = $value[0];
          }
        }
        else {
          $value = $value[0];
        }
      }
    }

    return $item;
  }
}
