<?php

class DSJsonWebformSubmissionJsonMigrateItems extends MigrateItems implements Iterator {
  // Which webform are we looking at?
  protected $key;
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

  public function __construct($base_url, $key) {
    parent::__construct();

    // TODO: need to make sure this variable is getting set, defaulting to
    // September 25th to make sure I get some data.
    $ts = variable_get('ds_migration_forked_ts', 1317000000);

    $this->key = $key;
    $this->listUrl = "{$base_url}/webform/list/{$key}?page=:page&created_since={$ts}";
    $this->countUrl = "{$base_url}/webform/count?created_since={$ts}";
    $this->getUrl = "{$base_url}/webform/get/:id";

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

    if (!isset($counts[$this->key])) {
      migrate_instrument_start("Retrieve $this->countUrl");
      $json = file_get_contents($this->countUrl);
      migrate_instrument_stop("Retrieve $this->countUrl");

      if ($json) {
        $counts = drupal_json_decode($json);
      }
    }

    migrate_instrument_stop(__METHOD__);

    return isset($counts[$this->key]) ? $counts[$this->key] : 0;
  }

  public function getItem($id) {
    migrate_instrument_start(__METHOD__);

    $url = str_replace(':id', $id, $this->getUrl);
    $json = file_get_contents($url);
    if (!$json) {
      migrate_instrument_stop(__METHOD__);

      $migration = Migration::currentMigration();
      $message =  t('Loading of !objecturl failed:', array('!objecturl' => $item_url));
      $migration->getMap()->saveMessage(
        array($id), $message, MigrationBase::MESSAGE_ERROR);
      return NULL;
    }

    $obj = json_decode($json);
    $item = reset($obj);

    migrate_instrument_stop(__METHOD__);

    return $item;
  }
}


abstract class DSWebformSubmissionMigration extends Migration {
  protected $nid;

  static function fetchFields($base_url, $key) {
    $url = "$base_url/webform/fields/$key";

    $cid = __CLASS__ . ':' . $url;
    $cache = cache_get($cid);
    if ($cache !== FALSE && isset($cache->data)) {
      return $cache->data;
    }

    $json = file_get_contents($url);
    if ($json) {
      $fields = drupal_json_decode($json);
      if ($fields && is_array($fields)) {
        cache_set($cid, $fields);
        return $fields;
      }
    }

    return FALSE;
  }

  public function __construct($nid) {
    parent::__construct(MigrateGroup::getInstance('WebformSubmission'));
    $this->dependencies = array();

    $node_type = 'webform';
    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    // Expedientcy...
    $fields = self::fetchFields($base_url, $nid);

    $this->source = new MigrateSourceMultiItems(
      new DSJsonWebformSubmissionJsonMigrateItems($base_url, $nid),
      $fields
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationWebformSubmission::getKeySchema(),
      MigrateDestinationWebformSubmission::getKeySchema()
    );

    $this->webform = node_load($nid);
    if (!$this->webform) {
      var_dump(t('WARNING: @name has no webform node.', array('@name' => $nid)));
    }

    $clean_src = strtr($node_type, array('_' => '-'));
    $clean_dest = strtr($this->webform->type, array('_' => '-'));
    $this->description = theme('item_list', array(
      'items' => array(
        'd6_fields' => l('Source CCK Fields', "http://dosomething6.local/admin/content/node-type/$clean_src/fields"),
        'd7_fields' => l('Destination Fields (field_*)', "admin/config/content/webform/entities/$clean_dest/fields"),
        'd7_components' => l('Destination Components (data_*)', "node/{$this->webform->nid}/webform"),
      ),
    ));

    $this->issuePattern = 'https://zivtech.unfuddle.com/a#/projects/38035/tickets/by_number/:id:';

    $this->destination = new MigrateDestinationWebformSubmission($this->webform);

    unset($fields['sid'], $fields['nid']);
    $this->addSimpleMappings(array_keys($fields));
    $this->addUnmigratedDestinations(array('sid'));
    $this->addUnmigratedSources(array('nid', 'sid'));
  }
}

class DSWebform649367 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(649367);
  }
}

class DSWebform650078 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(650078);
  }
}

class DSWebform650379 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(650379);
  }
}

class DSWebform650471 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(650471);
  }
}

class DSWebform651742 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(651742);
  }
}

class DSWebform652060 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(652060);
  }
}

class DSWebform674268 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(674268);
  }
}

class DSWebform677734 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(677734);
  }
}

class DSWebform677823 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(677823);
  }
}

class DSWebform678267 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(678267);
  }
}

class DSWebform678942 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(678942);
  }
}

class DSWebform679576 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(679576);
  }
}

class DSWebform679707 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(679707);
  }
}

class DSWebform679745 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(679745);
  }
}

class DSWebform679770 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(679770);
  }
}

class DSWebform680418 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(680418);
  }
}

class DSWebform680674 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(680674);
  }
}

class DSWebform680696 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(680696);
  }
}

class DSWebform680841 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(680841);
  }
}

class DSWebform681182 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(681182);
  }
}

class DSWebform681880 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(681880);
  }
}

class DSWebform681960 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(681960);
  }
}

class DSWebform682136 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(682136);
  }
}

class DSWebform682753 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(682753);
  }
}

class DSWebform682784 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(682784);
  }
}

class DSWebform685503 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(685503);
  }
}

class DSWebform688464 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(688464);
  }
}

class DSWebform688536 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(688536);
  }
}

class DSWebform691486 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(691486);
  }
}

class DSWebform691967 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(691967);
  }
}

class DSWebform696251 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(696251);
  }
}

class DSWebform698605 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(698605);
  }
}
