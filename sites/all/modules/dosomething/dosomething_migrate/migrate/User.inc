<?php

class DSUserMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct();
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://dosomething6.local/migrate');

    $fields = array();
    $json = file_get_contents("{$base_url}/user/fields");
    if ($json) {
      $fields = drupal_json_decode($json);
    }

    $this->source = new MigrateSourceList(
      new DSUserListJSON($base_url, $node_type),
      new DSUserItemJSON($base_url, $node_type),
      $fields
    );

    $this->destination = new MigrateDestinationUser();

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationUser::getKeySchema()
    );

    // $this->highwaterField = array(
    //   'name' => 'changed',
    //   'type' => 'int',
    // );

    $this->addFieldMapping('uid', 'uid');

  }
}

class DSUserProfileMigration extends DSBaseMigration {
  public function __construct() {
    parent::__construct();
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://dosomething6.local/migrate');

    $fields = array();
    $json = file_get_contents("{$base_url}/user/fields");
    if ($json) {
      $fields = drupal_json_decode($json);
    }

    $this->source = new MigrateSourceList(
      new DSUserListJSON($base_url, $node_type),
      new DSUserItemJSON($base_url, $node_type),
      $fields
    );

    $this->destination = new MigrateDestinationProfile2('main');

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationProfile2::getKeySchema()
    );

    $this->addFieldMapping('uid', 'uid');

    $arguments = array(
      'thoroughfare' => array('source_field' => 'profile_address1'),
      'premise' => array('source_field' => 'profile_address2'),
      'locality' => array('source_field' => 'profile_city'),
      'administrative_area' => array('source_field' => 'profile_state'),
      'postal_code' => array('source_field' => 'profile_zip'),
    );
    $this->addFieldMapping('field_user_address')
        ->defaultValue('US')
        ->arguments($arguments);
    // Since the excerpt is mapped via an argument, add a null mapping so it's
    // not flagged as unmapped.
    foreach ($arguments as $dest => $argument) {
      $this->addFieldMapping(NULL, $argument['source_field'])->description(t("Maps to %dest in field_user_address", array('%dest' => $dest)));
    }

    $this->addFieldMapping('field_user_hearabout', 'profile_hearabout');
    $this->addFieldMapping('field_user_is_over13', 'profile_over13')->defaultValue(0);
    $this->addFieldMapping('field_user_first_name', 'profile_fname');
    $this->addFieldMapping('field_user_last_name', 'profile_lname');
    $this->addFieldMapping('field_user_birthday', 'profile_bday')->defaultValue(NULL);
    $this->addFieldMapping('field_user_gender', 'profile_gender');
    $this->addFieldMapping('field_user_preferred_cause', 'profile_preferred_cause')->description('Mapped to node ids in prepareRow().');
    $this->addFieldMapping('field_user_why_do_you', 'profile_why_do_you');
    $this->addFieldMapping('field_user_mobile', 'profile_cell')->defaultValue('');
    $this->addFieldMapping('field_user_mobile_optin', 'profile_receive')->defaultValue(0);
    $this->addFieldMapping('field_user_newsletter_optin', 'profile_newsletter')->defaultValue(0);

    $this->addUnmigratedSources(array(
      'name', 'pass', 'mail', 'roles', 'theme', 'signature', 'signature_format',
      'created', 'access', 'login', 'status', 'timezone', 'language', 'picture',
      'init',
    ));
    $this->addUnmigratedDestinations(array(
      'revision_uid', 'language', 'path',
    ));
  }

  public function prepareRow($row) {
    // Translate the strings into cause node ids.
    $map = array(
      'Animal Welfare' => 29060,
      'Disaster Response & Relief' => 29085,
      'Discrimination' => 29086,
      'Education' => 29102,
      'Environment' => 29109,
      'Health & Fitness' => 29111,
      'HIV & Sexuality' => 29113,
      'International Human Rights' => 29124,
      'Poverty' => 29150,
      'Violence & Bullying' => 29128,
      'War Peace & Politics' => 29148,
    );
    $row->profile_preferred_cause = isset($map[$row->profile_preferred_cause]) ? $map[$row->profile_preferred_cause] : NULL;

    // Make sure these an integers.
    $row->profile_receive = (int) $row->profile_receive;
    $row->profile_newsletter = (int) $row->profile_newsletter;

    // There's a lot of garbage in the birthday field. Excude anything that
    // doesn't have a number (other than zero to filter out 0/0/0) and some
    // kind of separator.
    #print "bday before:" . $row->profile_bday . "\n";
    if (preg_match('![1-9]+[- ,\.\/]!', $row->profile_bday) && ($timestamp = strtotime($row->profile_bday))) {
      $row->profile_bday = $timestamp;
    }
    else {
      $row->profile_bday = NULL;
    }
    #print "bday after :" . ($row->profile_bday ? gmdate('c', $row->profile_bday) : '') . "\n";
  }
}

class DSUserListJSON extends DSListJSON {
  public function __construct($base_url) {
    parent::__construct("{$base_url}/user/list/{$type}?page=:page", array());
    $this->countUrl = "{$base_url}/user/count";
  }
}

class DSUserItemJSON extends DSItemJSON {
  public function __construct($base_url) {
    parent::__construct("{$base_url}/user/get/:id", array());
  }
}