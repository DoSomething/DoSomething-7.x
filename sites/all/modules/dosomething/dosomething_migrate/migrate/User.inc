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
    // $this->addFieldMapping('profile_address1', 'field_profile_location');
    // $this->addFieldMapping('profile_address2', 'field_profile_location');
    // $this->addFieldMapping('profile_city', 'field_profile_location');
    // $this->addFieldMapping('profile_state', 'field_profile_location');
    // $this->addFieldMapping('profile_zip', 'field_profile_location');
    $this->addFieldMapping('field_profile_hearabout', 'profile_hearabout');
    $this->addFieldMapping('field_profile_over13', 'profile_over13')->defaultValue(0);
    $this->addFieldMapping('field_user_first_name', 'profile_fname');
    $this->addFieldMapping('field_user_first_name', 'profile_lname');
    $this->addFieldMapping('field_profile_bday', 'profile_bday')->defaultValue(NULL);
    $this->addFieldMapping('field_profile_gender', 'profile_gender');
    $this->addFieldMapping('field_profile_preferred_cause', 'profile_preferred_cause')->description('Mapped to node ids in prepareRow().');
    $this->addFieldMapping('field_profile_why_do_you', 'profile_why_do_you');
    $this->addFieldMapping('field_profile_cell', 'profile_cell')->defaultValue('');
    $this->addFieldMapping('field_profile_receive', 'profile_receive')->defaultValue(0);
    $this->addFieldMapping('field_profile_newsletter', 'profile_newsletter')->defaultValue(0);
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