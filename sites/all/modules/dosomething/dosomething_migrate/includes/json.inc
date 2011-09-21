<?php

abstract class DSListJSON extends MigrateListJSON {
  protected $countUrl;

  public function computeCount() {
    $count = NULL;

    migrate_instrument_start(__METHOD__);

    migrate_instrument_start("Retrieve $this->countUrl");
    $json = file_get_contents($this->countUrl);
    migrate_instrument_stop("Retrieve $this->countUrl");

    if ($json) {
      $data = drupal_json_decode($json);
      $count = $data;
    }

    migrate_instrument_stop(__METHOD__);

    return $count;
  }

  public function getIdList() {
    migrate_instrument_start(__METHOD__);

    $cid = 'DSListJSON:' . $this->listUrl;
    $cache = cache_get($cid);
    if ($cache !== FALSE && is_array($cache->data)) {
      migrate_instrument_stop(__METHOD__);
      return $cache->data;
    }

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
        migrate_instrument_stop(__METHOD__);
        return NULL;
      }
      $data = drupal_json_decode($json);
      if ($data) {
        // Keep track of how many new ids come back in a request. Once we stop
        // seeing new ones we'll stop fetching.
        $old_count = count($ids);
        $ids = array_merge($ids, $this->getIDsFromJSON($data));
        $new_ids = count($ids) - $old_count;
      }

      // Go until there are no more new ids coming back.
    } while ($new_ids > 0);

    cache_set($cid, $ids);

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
    $item = reset($obj);

    migrate_instrument_stop(__METHOD__);

    return $item;
  }
}