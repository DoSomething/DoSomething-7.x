<?php


class DSUserJsonMigrateItems extends DSJsonMigrateItems {
  public function __construct($base_url, $query_arg) {
    $this->listUrl = "{$base_url}/user/list?&page=:page&{$query_arg}";
    $this->countUrl = "{$base_url}/user/count&{$query_arg}";
    $this->getUrl = "{$base_url}/user/get/:id";
    parent::__construct();
  }
}

abstract class DSJsonUserMigration extends Migration {
  static function fetchFields($base_url) {
    $cid = "DSJsonUserMigration:$base_url";
    $cache = cache_get($cid);
    if ($cache !== FALSE && isset($cache->data)) {
      return $cache->data;
    }

    $json = file_get_contents("{$base_url}/user/fields");
    if ($json) {
      $fields = drupal_json_decode($json);
      if ($fields && is_array($fields)) {
        cache_set($cid, $fields);
        return $fields;
      }
    }

    return FALSE;
  }

  public function __construct($query_args) {
    parent::__construct(MigrateGroup::getInstance('Users'));

    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    $this->source = new MigrateSourceMultiItems(
      new DSUserJsonMigrateItems($base_url, $query_args),
      self::fetchFields($base_url)
    );
  }
}

class DSJsonNewUser extends DSJsonUserMigration {
  public function __construct() {
    // TODO: need to make sure this variable is getting set, defaulting to
    // September 25th to make sure I get some data.
    $ts = variable_get('ds_migration_forked_ts', 1317000000);
    parent::__construct("created_since={$ts}");

    $this->dependencies = array();

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationUser::getKeySchema()
    );

    $this->destination = new MigrateDestinationUser();
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addSimpleMappings(array(
      'uid',
      'name',
      'mail',
      'login',
      'access',
      'timezone',
      'language',
      'signature',
      'signature_format',
      'status',
      'init',
    ));
    $this->addUnmigratedSources(array(
      'created',  // Shouldn't be changing.
      'picture',  // Not in use.
      'theme',    // Theme will change
      'profile_hearabout', // All these are handled by DSJsonProfile
      'profile_address1',
      'profile_address2',
      'profile_city',
      'profile_state',
      'profile_zip',
      'profile_over13',
      'profile_fname',
      'profile_lname',
      'profile_bday',
      'profile_gender',
      'profile_preferred_cause',
      'profile_why_do_you',
      'profile_cell',
      'profile_receive',
      'profile_newsletter',
      ));
  }
}

class DSJsonChangedUser extends DSJsonUserMigration {
  public function __construct() {
    // TODO: need to make sure this variable is getting set, defaulting to
    // September 25th to make sure I get some data.
    $ts = variable_get('ds_migration_forked_ts', 1317000000);
    parent::__construct("changed_since={$ts}");

    $this->dependencies = array('DSJsonNewUser');

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationUser::getKeySchema()
    );

    // We want to update existing users.
    $this->destination = new MigrateDestinationUser();
    $this->systemOfRecord = Migration::DESTINATION;
    $this->addSimpleMappings(array(
      'uid',
      'name',
      'mail',
      'login',
      'access',
      'timezone',
      'language',
      'signature',
      'signature_format',
      'status',
      'init',
    ));
    $this->addUnmigratedSources(array(
      'created',  // Shouldn't be changing.
      'picture',  // Not in use.
      'theme',    // Theme will change
      'profile_hearabout', // All these are handled by DSJsonProfile
      'profile_address1',
      'profile_address2',
      'profile_city',
      'profile_state',
      'profile_zip',
      'profile_over13',
      'profile_fname',
      'profile_lname',
      'profile_bday',
      'profile_gender',
      'profile_preferred_cause',
      'profile_why_do_you',
      'profile_cell',
      'profile_receive',
      'profile_newsletter',
    ));
    $this->addUnmigratedDestinations(array(
      'is_new',
      'created',  // Shouldn't be changing.
      'picture',  // Not in use.
      'path',     // Auto generated.
      'theme',    // Default is fine.
      'pathauto', // Let it happen.
    ));
    #$this->addFieldMapping('pass', ''); # User: Password (plain text)
    #$this->addFieldMapping('roles', ''); # User: Role IDs
  }
}

class DSJsonProfile extends DSJsonUserMigration {
  public function __construct() {
    // TODO: need to make sure this variable is getting set, defaulting to
    // September 25th to make sure I get some data.
    $ts = variable_get('ds_migration_forked_ts', 1317000000);
    parent::__construct("changed_since={$ts}");

    // Get existing user's profiles migrated, then create users.
    $this->dependencies = array('DSSqlUserProfile', 'DSJsonNewUser', 'DSJsonChangedUser');

    $this->destination = new MigrateDestinationProfile2('main');

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationUser::getKeySchema(),
      MigrateDestinationProfile2::getKeySchema()
    );

    $this->addFieldMapping('uid', 'uid')->sourceMigration(array('DSJsonNewUser', 'DSJsonChangedUser'));
    $this->addFieldMapping('field_user_hearabout', 'profile_hearabout');
    $this->addFieldMapping('field_user_is_over13', 'profile_over13');
    $this->addFieldMapping('field_user_first_name', 'profile_fname');
    $this->addFieldMapping('field_user_last_name', 'profile_lname');
    $this->addFieldMapping('field_user_birthday', 'profile_bday')->defaultValue(NULL);
    $this->addFieldMapping('field_user_gender', 'profile_gender');
    $this->addFieldMapping('field_user_preferred_cause', 'profile_preferred_cause')->description('Mapped to node ids in prepareRow().');
    $this->addFieldMapping('field_user_why_do_you', 'profile_why_do_you');
    $this->addFieldMapping('field_user_mobile', 'profile_cell')->defaultValue('');
    $this->addFieldMapping('field_user_mobile_optin', 'profile_receive');
    $this->addFieldMapping('field_user_newsletter_optin', 'profile_newsletter');

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

    #$this->addFieldMapping('field_user_age', ''); # Field: Age (text)
    #$this->addFieldMapping('field_user_confirm_email', ''); # Field: Confirm Email (email)
    #$this->addFieldMapping('field_user_email', ''); # Field: Email (email)
    #$this->addFieldMapping('field_user_email_updates', ''); # Field: I would also like to receive email updates from DoSomething.org (list_boolean)
    #$this->addFieldMapping('field_user_official_rules', ''); # Field: I have read and accept the <a href="/">Official Rules</a> (list_boolean)
    #$this->addFieldMapping('field_user_phone_number', ''); # Field: Phone Number (text)

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
    $row->profile_receive = isset($row->profile_receive) ? (int) $row->profile_receive : 0;
    $row->profile_newsletter = isset($row->profile_newsletter) ? (int) $row->profile_newsletter : 0;

    // Trim long cellphone numbers.
    $row->profile_cell = substr($row->profile_cell, 0, 32);

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
