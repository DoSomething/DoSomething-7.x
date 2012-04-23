<?php

abstract class DSWebformEntitySubmissionMigration extends Migration {
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
        'd6_fields' => l('Source CCK Fields', "http://old.dosomething.org/admin/content/node-type/$clean_src/fields"),
        'd7_fields' => l('Destination Fields (field_*)', "admin/config/content/webform/entities/$clean_dest/fields"),
        'd7_components' => l('Destination Components (data_*)', "node/{$this->webform->nid}/webform"),
      ),
    ));

    $this->issuePattern = 'https://zivtech.unfuddle.com/a#/projects/38035/tickets/by_number/:id:';

    $this->sourceItemReviewPattern = "http://old.dosomething.org/node/{$source_nid}/submission/:id:/edit";
    $this->destinationItemReviewPattern = "http://dosomething.org/node/{$this->webform->nid}/submission/:id:/edit";

    $this->destination = new MigrateDestinationWebformSubmissionEntity($this->webform);

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



class DSWebform736100 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(736100, 721439);
    $this->addFieldMapping('data_i_want_to_receive_more_energy_saving_opportunities_from_the_epa', 'data_i_want_to_receive_more_energy_saving_opportunities_for_the_epa');
    $this->addFieldMapping('data_email_1', 'data_friend_email_1');
    $this->addFieldMapping('data_email_2', 'data_friend_email_2');
    $this->addFieldMapping('data_email_3', 'data_friend_email_3');
    $this->addFieldMapping('data_email_4', 'data_friend_email_4');
    $this->addFieldMapping('data_email_5', 'data_friend_email_5');
  }
  function applyFieldMappings($fields) {
    unset($fields['data_legal']);
    $this->addUnmigratedDestinations(array('data_legal'));
    parent::applyFieldMappings($fields);
  }

  public function prepare($entity, $row) {
    $state = $row->data_state;
    $gsid = $row->data_gsid[0];
    $state = $state[0];
    if (is_numeric($gsid)) {
      $entity->field_webform_school_reference['und'][0]['target_id'] = $gsid;
    }
    if ($gsid == 'null') {
      unset($entity->field_webform_school_reference);
    }
    if (is_null($gsid)) {
      unset($entity->field_webform_school_reference);
    }

    // Convert the found id into a unique id.
    if (isset($entity->field_webform_school_reference['und'][0]['target_id'])) {
      $unique_gsid = db_query('SELECT sid FROM {ds_school} WHERE school_id = :sid AND state = :state', array(':sid' => $entity->field_webform_school_reference['und'][0]['target_id'], ':state' => $state))->fetchField();
      $entity->field_webform_school_reference['und'][0]['target_id'] = $unique_gsid;
    }
    else {
      unset($entity->field_webform_school_reference);
    }
    if (!$unique_gsid) {
      unset($entity->field_webform_school_reference);
    }
    // Clean the phone number.
    $entity->field_webform_mobile['und'][0]['value'] = preg_replace('/\D/', '', $row->data_phone_number);
    $entity->field_webform_email['und'][0]['email'] = $row->data_email_address;
  }
}

class DSWebform748361 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(748361, 721441);
  }

  function applyFieldMappings($fields) {
    unset($fields['data_email_address'], $fields['data_phone_number']);
    $this->addFieldMapping('field_webform_email', 'data_email_address');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    parent::applyFieldMappings($fields);
    /*
    $this->addUnmigratedSources(array('data_sign_up_messaging', 'data_state', 'data_name_of_school'));
    $this->addUnmigratedDestinations(array(
      'data_sign_up_messaging',
      'data_email_address',
      'data_phone_number',
      'data_state',
      'data_name_of_school',
    ));
    */
  }

  public function prepare($entity, $row) {
    $state = $row->data_state;
    $gsid = $row->data_gsid[0];
    $state = $state[0];
    if (is_numeric($gsid)) {
      $entity->field_webform_school_reference['und'][0]['target_id'] = $gsid;
    }
    if ($gsid == 'null') {
      unset($entity->field_webform_school_reference);
    }
    if (is_null($gsid)) {
      unset($entity->field_webform_school_reference);
    }

    // Convert the found id into a unique id.
    if (isset($entity->field_webform_school_reference['und'][0]['target_id'])) {
      $unique_gsid = db_query('SELECT sid FROM {ds_school} WHERE school_id = :sid AND state = :state', array(':sid' => $entity->field_webform_school_reference['und'][0]['target_id'], ':state' => $state))->fetchField();
      $entity->field_webform_school_reference['und'][0]['target_id'] = $unique_gsid;
    }
    else {
      unset($entity->field_webform_school_reference);
    }
    if (!$unique_gsid) {
      unset($entity->field_webform_school_reference);
    }
    // Clean the phone number.
    $entity->field_webform_mobile['und'][0]['value'] = preg_replace('/\D/', '', $row->data_phone_number);
    $entity->field_webform_email['und'][0]['email'] = $row->data_email_address;
  }
}



class DSWebform748186 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(748186, 721424);
  }
  function applyFieldMappings($fields) {
    unset($fields['data_email'], $fields['data_phone_number']);
    $this->addFieldMapping('field_webform_email', 'data_email');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    parent::applyFieldMappings($fields);
  }
}

class DSWebform737152 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(737152, 719314);
  }
  function applyFieldMappings($fields) {
    unset($fields['data_email'], $fields['data_phone_number']);
    $this->addFieldMapping('field_webform_email', 'data_email');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    parent::applyFieldMappings($fields);
  }
}

class DSWebform735506 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(735506, 719317);
  }
  function applyFieldMappings($fields) {
    unset($fields['data_email'], $fields['data_phone_number']);
    $this->addFieldMapping('field_webform_email', 'data_email');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    parent::applyFieldMappings($fields);
  }
}

class DSWebform748159 extends DSWebformEntitySubmissionMigration {
  function __construct() {
    parent::__construct(748159, 719307);
  }
  function applyFieldMappings($fields) {
    unset($fields['data_email'], $fields['data_phone_number']);
    $this->addFieldMapping('field_webform_email', 'data_email');
    $this->addFieldMapping('field_webform_mobile', 'data_phone_number');
    parent::applyFieldMappings($fields);
  }
}
