<?php

abstract class DSBaseMigration extends Migration {
  public function __construct($webform, $node_type) {
    parent::__construct();
    $this->dependencies = array();

    $base_url = 'http://dosomething6.local/migrate';

    $fields = array();
    $json = file_get_contents("{$base_url}/node/fields");
    if ($json) {
      $data = drupal_json_decode($json);
      $fields = $data[$node_type];
    }

    $this->source = new MigrateSourceList(
      new DSListJSON($base_url, $node_type),
      new DSItemJSON($base_url, $node_type),
      $fields
    );

    $this->destination = new MigrateDestinationWebformSubmission($webform);

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmission::getKeySchema()
    );

    $this->addFieldMapping('sid', 'nid');
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('is_draft')->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')->defaultValue(time());
    $this->addFieldMapping('remote_addr')->defaultValue('127.0.0.1');

    // $this->addFieldMapping('data_fake1')->defaultValue('fake value');

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

class DSListJSON extends MigrateListJSON {
  protected $type;
  protected $countUrl;

  public function __construct($base_url, $type) {
    parent::__construct("{$base_url}/node/list/{$type}?page=:page", array());
    $this->countUrl = "{$base_url}/node/count";
    $this->type = $type;
  }

  public function computeCount() {
    migrate_instrument_start("Retrieve $this->countUrl");
    $json = file_get_contents($this->countUrl);
    migrate_instrument_stop("Retrieve $this->countUrl");

    if ($json) {
      $data = drupal_json_decode($json);
      return $data[$this->type];
    }
  }

  public function getIdList() {
    migrate_instrument_start(__METHOD__);

    $page = 0;
    $ids = array();
    $migration = Migration::currentMigration();

    do {
      $url = str_replace(':page', $page++, $this->listUrl);
      $new_ids = 0;

      migrate_instrument_start("Retrieve $this->listUrl");
      // We ignore $this->httpOptions
      $json = file_get_contents($url);
      migrate_instrument_stop("Retrieve $this->listUrl");

      if ($json === FALSE) {
        $migration->showMessage(t('Loading of !listurl failed:', array('!listurl' => $this->listUrl)));
        return NULL;
      }
      $data = drupal_json_decode($json);
      if ($data) {
        // Keep track of how many new ids come back in a request. Once we stop
        // seeing new ones we'll stop fetching.
        $old_count = count($ids);
        $ids = $ids + $this->getIDsFromJSON($data);
        $new_ids = count($ids) - $old_count;
      }

      // Go until there are no more new ids coming back.
    } while ($new_ids > 0);

    migrate_instrument_stop(__METHOD__);

    return $ids;
  }
}

class DSItemJSON extends MigrateItemJSON {
  public function __construct($base_url, $type) {
    parent::__construct("{$base_url}/node/get/:id", array());
  }

  protected function loadJSONUrl($item_url) {
    migrate_instrument_start(__METHOD__);

    $json = file_get_contents($item_url);
    $obj = json_decode($json);

    migrate_instrument_stop(__METHOD__);

    return reset($obj);
  }
}
