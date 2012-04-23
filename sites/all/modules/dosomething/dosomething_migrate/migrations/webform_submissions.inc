<?php

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

  public function __construct($source_nid, $destination_nid = NULL) {
    parent::__construct(MigrateGroup::getInstance('WebformSubmission'));
    $this->dependencies = array();

    $node_type = 'webform';
    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.dev.zivtech.com/migrate');

    // Expedientcy...
    $fields = self::fetchFields($base_url, $source_nid);

    $this->source = new MigrateSourceMultiItems(
      new DSWebformSubmissionJsonMigrateItems($base_url, $source_nid),
      $fields
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationWebformSubmission::getKeySchema(),
      MigrateDestinationWebformSubmission::getKeySchema()
    );

    $destination_nid = isset($destination_nid) ? $destination_nid : $source_nid;
    $this->webform = node_load($destination_nid);
    if (!$this->webform) {
      var_dump(t('WARNING: @name is not a webform node.', array('@name' => $destination_nid)));
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

    $this->sourceItemReviewPattern = "http://www.dosomething.org/node/{$nid}/webform-results/:id:/edit";
    $this->destinationItemReviewPattern = "http://dosomething.local/node/{$this->webform->nid}/webform-results/:id:/edit";

    $this->destination = new MigrateDestinationWebformSubmission($this->webform);

    unset($fields['sid'], $fields['nid']);
    // Let sub migrations have a chance to modify the simple mappings.
    $this->applyFieldMappings($fields);
    $this->addUnmigratedDestinations(array('sid'));
    $this->addUnmigratedSources(array('nid', 'sid'));
  }

  function applyFieldMappings($fields) {
    $this->addSimpleMappings(array_keys($fields));
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

/* TODO Find out why this was removed and if we need to add it back and migrate it again.
class DSWebform682753 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(682753);
  }
}
*/

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
    $mappings = $this->getFieldMappings();
    $mappings['data_file']
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $mappings['data_picture']
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
  }
}

class DSWebform688536 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(688536);
    $mappings = $this->getFieldMappings();
    $mappings['data_file']
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
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

