<?php

abstract class DSListJSON extends MigrateListJSON implements Iterator {
  // Subclasses need to populate this with a URL where we can get a count.
  protected $countUrl;
  // Which page are we on?
  protected $pageNumber;
  // Array of remaining values on this page.
  protected $pageValues;
  // Current value.
  protected $current;
  // Have we reached the end of the list?
  protected $eof;

  public function __construct($list_url, $http_options = array()) {
    parent::__construct($list_url, $http_options);
    $this->listUrl = $list_url;
    $this->httpOptions = $http_options;
    $this->rewind();
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

    return $counts[$this->countUrl];
  }

  public function getIdList() {
    return $this;
  }

  /**
   * Try to fetch and parse the page specified by pageValues, populates
   * pageValues with the ids and fills current with the first value.
   */
  protected function fetchPage() {
#    var_dump(__METHOD__ . ' ' . $this->pageNumber);
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
      $ids = $this->getIDsFromJSON($jsonArray);
      if (!$ids) {
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
#    var_dump(__METHOD__);
    $this->pageNumber = 0;
    $this->fetchPage();
  }

  function current() {
#    var_dump(__METHOD__, $this->current);
    return $this->current;
  }

  function key() {
#    var_dump(__METHOD__);
    return $this->pageNumber . ':' . $this->rowCount;
  }

  function next() {
#    var_dump(__METHOD__);
    $this->current = array_shift($this->pageValues);
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
#    var_dump(__METHOD__, $valid);
    return $valid;
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