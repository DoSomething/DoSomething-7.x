<?php

class DSSqlUserProfile extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('Users'));
    $this->dependencies = array();

    $profile_fields = db_select('profile_field')
      ->fields('profile_field', array('name', 'fid'))
      ->execute()
      ->fetchAllKeyed(0, 1);

    $query = db_select('users', 'u')->fields('u', array('uid'));
    foreach ($profile_fields as $name => $fid) {
      // This isa little dirty but the placeholders weren't working.
      $alias = $query->leftJoin('profile_value', NULL, "%alias.uid = u.uid AND %alias.fid = $fid");
      $query->addField($alias, 'value', $name);
    }

    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationProfile2('main');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'u',
         )
      ),
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
    //$this->addFieldMapping('field_user_preferred_cause', 'profile_preferred_cause')->description('Mapped to node ids in prepareRow().');
    $this->addFieldMapping('field_user_why_do_you', 'profile_why_do_you');
    $this->addFieldMapping('field_user_mobile', 'profile_cell')->defaultValue('');
    $this->addFieldMapping('field_user_mobile_optin', 'profile_receive')->defaultValue(0);
    $this->addFieldMapping('field_user_newsletter_optin', 'profile_newsletter')->defaultValue(0);
    $this->addFieldMapping('taxonomy_vocabulary_5', 'profile_preferred_cause')->arguments(array('source_type' => 'tid'));

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

    // map the orginial node id to the new term id.
    $nid_to_tid_map = array(
      '29060' => '29',
      '29085' => '27',
      '29086' => '23',
      '29102' => '25',
      '29109' => '20',
      '29111' => '26',
      '29113' => '22',
      '29124' => '73',
      '29150' => '21',
      '29128' => '28',
      '29148' => '24',
    );

    $row->profile_preferred_cause = isset($map[$row->profile_preferred_cause]) ? $nid_to_tid_map[$map[$row->profile_preferred_cause]] : NULL;

    // Make sure these an integers.
    $row->profile_receive = isset($row->profile_receive) ? (int) $row->profile_receive : 0;
    $row->profile_newsletter = isset($row->profile_newsletter) ? (int) $row->profile_newsletter : 0;

    // Trim long cellphone numbers.
    $row->profile_cell = substr($row->profile_cell, 0, 32);
    // We're going to remove any non-numeric characters from the phone number.
    $row->profile_cell = preg_replace('/\D/', '', $row->profile_cell);

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

    // A zero value means nothing was selected.
    if (empty($row->profile_gender)) {
      $row->profile_gender = NULL;
    }
    else {
      // They switched the keys to lowercase versions.
      $row->profile_gender = strtolower($row->profile_gender);
    }
  }
}
