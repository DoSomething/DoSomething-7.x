<?php

abstract class DSSqlNodeMigration extends DSBaseMigration {
  public function __construct($group = NULL, $node_type) {
    parent::__construct($group);

    // Do a little dance to get a field list.
    $d = new MigrateDestinationNode($node_type);
    $fields = $d->fields();
    unset($d);

    $query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', $node_type)
      ->condition('n.status', 1)
      ->orderBy('n.changed');
    $this->source = new MigrateSourceSQL($query, $fields);

    $this->highwaterField = array(
      'name' => 'changed',
      'type' => 'int',
    );

    $webform_nids = variable_get('webform_migrate_webform_mapping', array());
    $webform = node_load($webform_nids[$node_type]);
    if (!$webform) {
      var_dump(t('WARNING: @name has no webform node.', array('@name' => $node_type)));
    }
    $this->destination = new MigrateDestinationWebformSubmissionEntity($webform);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'n',
         )
      ),
      MigrateDestinationWebformSubmissionEntity::getKeySchema()
    );

    // HEY! Keep this in sync with DSJsonNodeMigration.
    $this->addFieldMapping('sid', 'nid')
      ->description("Make the node id the submission id for easy redirection if we need to.");
    $this->addFieldMapping('uid', 'uid')
      ->description("User ids should be a direct mapping.");
    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')
      ->description("Use the node creation date as the webform submission date.");
    $this->addFieldMapping('remote_addr')
      ->defaultValue('127.0.0.1')
      ->description("I don't think we have an IP to use as the submission so I'm using the loopback.");
    $this->addFieldMapping('path', 'path')
      ->issuePriority(MigrateFieldMapping::ISSUE_PRIORITY_LOW)
      ->description("Not sure if the webform submissions support paths.");
    $this->addUnmigratedSources(array('promote', 'sticky', 'language'));
  }

  public function prepareRow($row) {
    $node = node_load($row->nid);
    if ($node === FALSE) {
      return FALSE;
    }

    unset($node->rdf_mapping, $node->data);
    foreach ($node as $name => $value) {
      if ($name === 'body') {
        $row->format = $value['und'][0]['format'];
        $row->summary = $value['und'][0]['summary'];
        $row->body = $value['und'][0]['value'];
      }
      // Flatten out single value fields.
      else if (strpos($name, 'field_') === 0 && count($value) == 1) {
        // This looks bad but isset() returns false for null values:
        // http://stackoverflow.com/questions/418066/best-way-to-test-for-a-variables-existence-in-php-isset-is-clearly-broken
        if (is_object($value['und'][0])) {
          if (property_exists($value['und'][0], 'value')) {
            $row->$name = $value['und'][0]->value;
          }
          else if (property_exists($value['und'][0], 'nid')) {
            $row->$name = $value['und'][0]->nid;
          }
          else if (property_exists($value['und'][0], 'uid')) {
            $row->$name = $value['und'][0]->uid;
          }
          else if (property_exists($value['und'][0], 'url')) {
            $row->$name = $value['und'][0]->url;
          }
          else {
            $row->$name = $value['und'][0];
          }
        }
        else {
          $row->$name = $value['und'][0];
        }
      }
      else {
        $row->$name = $value;
      }
    }

    return $row;
  }
}