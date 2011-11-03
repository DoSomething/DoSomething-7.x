<?php

class DSJsonMigrateItems extends MigrateItems implements Iterator {
  // Where can we get counts?
  protected $countUrl;
  // Where can we fetch items?
  protected $getUrl;
  // Where can we get ids?
  protected $listUrl;
  // Which page are we on?
  protected $pageNumber = 0;
  // Array of remaining values on this page.
  protected $pageValues;
  // Current value.
  protected $current;
  // Have we reached the end of the list?
  protected $eof;

  public function __construct() {
    parent::__construct();

    // Initialize everything.
    $this->rewind();
  }

  public function __toString() {
    return $this->listUrl;
  }

  /**
   * Try to fetch and parse the page specified by pageValues, populates
   * pageValues with the ids and fills current with the first value.
   */
  protected function fetchPage() {
#var_dump(__METHOD__ . ' ' . $this->pageNumber);
    // Assume there's nothing left so we can be proved wrong.
    $this->pageValues = array();
    $this->eof = TRUE;
    $this->current = FALSE;

    $url = str_replace(':page', $this->pageNumber, $this->listUrl);
    $cid = __CLASS__ . ':' . $url;

    $cache = cache_get($cid);
    if ($cache !== FALSE && isset($cache->data)) {
      $ids = $cache->data;
    }
    else {
      migrate_instrument_start("Retrieve $this->listUrl");
      $jsonString = file_get_contents($url);
      migrate_instrument_stop("Retrieve $this->listUrl");
      if ($jsonString === FALSE) {
        return NULL;
      }
      $jsonArray = drupal_json_decode($jsonString);
      if ($jsonArray === NULL) {
        return NULL;
      }
      $ids = $jsonArray;
      if (!is_array($ids)) {
        return NULL;
      }
      cache_set($cid, $ids);
    }

    $this->pageValues = $ids;
    $this->eof = empty($this->pageValues);
    $this->current = reset($this->pageValues);
#var_dump("IDS $url " . implode(',', $this->pageValues));
  }

  function rewind() {
#var_dump(__METHOD__);
    $this->pageNumber = 0;
    $this->fetchPage();
  }

  function current() {
#var_dump(__METHOD__, $this->current);
    return $this->current;
  }

  function key() {
    return $this->pageNumber . ':' . $this->rowCount;
  }

  function next() {
    $this->current = array_shift($this->pageValues);
#var_dump(__METHOD__, $this->current);
    if ($this->current === NULL) {
      if (!$this->eof) {
        $this->pageNumber += 1;
        $this->fetchPage();
      }
      else {
        $this->current = FALSE;
      }
    }
    return $this->current;
  }

  function valid() {
    $valid = !empty($this->pageValues) || !$this->eof;
    return $valid;
  }

  public function getIdList() {
    return $this;
  }

  public function computeCount() {
    $counts = &drupal_static(__METHOD__);

    migrate_instrument_start(__METHOD__);

    if (!isset($counts[$this->countUrl])) {
      migrate_instrument_start("Retrieve $this->countUrl");
      $json = file_get_contents($this->countUrl);
      migrate_instrument_stop("Retrieve $this->countUrl");

      if ($json) {
        $data = drupal_json_decode($json);
        $counts[$this->countUrl] = $data;
      }
    }
    migrate_instrument_stop(__METHOD__);

    return isset($counts[$this->countUrl]) ? $counts[$this->countUrl] : 0;
  }

  public function getItem($id) {
    $cache = &drupal_static(__METHOD__);

    // Check the prefetch cache.
    if (isset($cache[$id])) {
      return $cache[$id];
    }

    migrate_instrument_start(__METHOD__);

    // Grab the this and the next few records to try to avoid the HTTP overhead.
    $ids = array_merge(array($id, $this->current), array_slice($this->pageValues, 0, 200));

    $url = str_replace(':id', implode(',', $ids), $this->getUrl);
    $json = file_get_contents($url);
    if (!$json) {
      migrate_instrument_stop(__METHOD__);

      $migration = Migration::currentMigration();
      $message =  t('Loading of !objecturl failed:', array('!objecturl' => $item_url));
      $migration->getMap()->saveMessage(
        array($id), $message, MigrationBase::MESSAGE_ERROR);
      return NULL;
    }

    $cache = array();
    foreach (drupal_json_decode($json) as $k => $v) {
      $cache[$k] = (object) $v;
    }

    migrate_instrument_stop(__METHOD__);

    return $cache[$id];
  }
}
