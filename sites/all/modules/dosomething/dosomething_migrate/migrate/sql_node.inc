<?php

abstract class DSSqlNodeMigration extends DSBaseMigration {
  public function __construct($node_type) {
    parent::__construct();

    // Do a little dance to get a field list.
    $d = new MigrateDestinationNode($node_type);
    $fields = $d->fields();
    unset($d);

    $query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', $node_type)
      ->condition('n.status', 1);
    $this->source = new MigrateSourceSQL($query, $fields);

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

    // $this->highwaterField = array(
    //   'name' => 'changed',
    //   'type' => 'int',
    // );
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