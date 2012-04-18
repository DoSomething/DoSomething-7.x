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

  public function __construct($nid) {
    parent::__construct(MigrateGroup::getInstance('WebformSubmission'));
    $this->dependencies = array();

    $node_type = 'webform';
    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.dev.zivtech.com/migrate');

    // Expedientcy...
    $fields = self::fetchFields($base_url, $nid);

    $this->source = new MigrateSourceMultiItems(
      new DSWebformSubmissionJsonMigrateItems($base_url, $nid),
      $fields
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationWebformSubmission::getKeySchema(),
      MigrateDestinationWebformSubmission::getKeySchema()
    );
    // We need to remap the original webform node to a new one. We create a
    // remapping array and use it here to load the proper node.
    $mapping = array(
      736100 => 721439,
      748361 => 721441,
    );
    $webform_nid = isset($mapping[$nid]) ? $mapping[$nid] : $nid;
    $this->webform = node_load($webform_nid);
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

    $this->sourceItemReviewPattern = "http://www.dosomething.org/node/{$nid}/webform-results/:id:/edit";
    $this->destinationItemReviewPattern = "http://dosomething.local/node/{$this->webform->nid}/webform-results/:id:/edit";

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

class DSWebform736100 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(736100);
    $this->addFieldMapping('data_i_want_to_receive_more_energy_saving_opportunities_from_the_epa', 'data_i_want_to_receive_more_energy_saving_opportunities_for_the_epa');
    $this->addFieldMapping('data_email_1', 'data_friend_email_1');
    $this->addFieldMapping('data_email_2', 'data_friend_email_2');
    $this->addFieldMapping('data_email_3', 'data_friend_email_3');
    $this->addFieldMapping('data_email_4', 'data_friend_email_4');
    $this->addFieldMapping('data_email_5', 'data_friend_email_5');
    $this->addUnmigratedDestinations(array('data_legal'));
  }
}

class DSWebform748361 extends DSWebformSubmissionMigration {
  function __construct() {
    parent::__construct(748361);
    $this->addFieldMapping('field_webform_email', 'data_email_address');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    $this->addUnmigratedSources(array('data_sign_up_messaging', 'data_state', 'data_name_of_school'));
    $this->addUnmigratedDestinations(array(
      'data_sign_up_messaging',
      'data_email_address',
      'data_phone_number',
      'data_state',
      'data_name_of_school',
      'field_webform_email',
      'field_webform_mobile',
    ));
  }

  public function prepare($entity, $row) {
    if (is_numeric((int) $row->data_gsid)) {
      $entity->field_webform_school_reference['und'][0]['target_id'] = $row->data_gsid;
    }
    // Clean the phone number.
    $entity->field_webform_mobile['und'][0]['value'] = preg_replace('/\D/', '', $row->data_phone_number);;
    $entity->field_webform_email['und'][0]['email'] = $row->data_email_address;
  }
}
