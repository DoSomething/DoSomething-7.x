<?php

class DSIntentions extends Migration {
  public function __construct($group = NULL) {
    parent::__construct($group);

    $source_type = 'ididthis';
    $webform_type = 'action_guide';

    $query = db_select('node', 'sub');
    $query->innerJoin('content_type_ididthis', 'c', 'sub.vid = c.vid');
    $query->innerJoin('node', 'act', 'act.nid = c.field_did_nid_value');
    $query->innerJoin('users', 'u', 'sub.uid = u.uid');
    $query->leftJoin('content_field_email_1', 'e', 'sub.vid = e.vid');
    $query->addExpression('COALESCE(e.field_email_1_value, u.mail)', 'email');
    $query->fields('sub', array('nid', 'created'))
      ->fields('act', array('nid'))
      ->fields('u', array('uid'))
      ->fields('c', array('field_hours_volunteered_0_value', 'field_number_of_people_your_act_value', 'field_completed_didthis_value'))
      ->condition('sub.type', $source_type)
      ->condition(db_or()->condition('sub.uid', 0, '>')->isNotNull('e.field_email_1_value'));
    $this->source = new MigrateSourceSQL($query, array());

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'sub',
         )
      ),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );

    $this->destination = new MigrateDestinationWebformSubmissionEntity($webform_type);

    $this->addFieldMapping('nid', 'act_nid');
    $this->addFieldMapping('uid', 'uid')
      ->description("User ids should be a direct mapping.");
    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')
      ->description("Use the node creation date as the webform submission date.");
    $this->addFieldMapping('remote_addr')
      ->defaultValue('127.0.0.1')
      ->description("I don't think we have an IP to use as the submission so I'm using the loopback.");
    $this->addFieldMapping('field_action_intention_email', 'email');
    $this->addFieldMapping('field_completed_didthis', 'field_completed_didthis_value');
    $this->addFieldMapping('field_hours_volunteered_0', 'field_hours_volunteered_0_value');
    $this->addFieldMapping('field_number_of_people_your_act', 'field_number_of_people_your_act_value');

    $this->addUnmigratedDestinations(array('path'));
  }
}