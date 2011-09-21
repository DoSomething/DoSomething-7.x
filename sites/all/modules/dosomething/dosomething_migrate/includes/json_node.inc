<?php

abstract class DSJsonNodeMigration extends DSBaseMigration {
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
    parent::__construct($group);
    $this->dependencies = array();

    $webform_nids = variable_get('webform_migrate_webform_mapping', array());
    $webform = node_load($webform_nids[$node_type]);
    if (!$webform) {
      var_dump(t('WARNING: @name has no webform node.', array('@name' => $node_type)));
    }
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

    // HEY! Keep this in sync with DSSqlNodeMigration.
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
