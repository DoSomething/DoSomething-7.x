<?php

/**
 * Migrate handler to provide fields for our custom webform tables.
 */
class MigrateDSWebformHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('WebformSubmission'));
  }

  public function fields($webform) {
    $fields = array();
    switch (dosomething_recurring_fields_type_to_table($webform->type)) {
      case 'ds_webform_campaign_su':
        $fields['name'] = 'Name';
        $fields['email'] = 'Email Address';
        $fields['mobile'] = 'Mobile phone number';
        $fields['zip'] = 'Zip code';
        break;
      case 'ds_webform_grant_app':
        $fields['name'] = 'Name';
        $fields['email'] = 'Email Address';
        $fields['school'] = 'School/Drive Name';
        $fields['mobile'] = 'Mobile phone number';
        $fields['zip'] = 'Zip code';
        break;

      case 'ds_webform_scholarship_app':
      case 'ds_webform_campaign_rb':
        $fields['name'] = 'Name';
        break;
    }
    return $fields;
  }

  public function complete($entity, $source_row, $webform) {
    $all_fields = dosomething_webform_recurring_fields_get_fields();
    if (empty($all_fields[$webform->type])) {
      return;
    }

    $fields = array();
    foreach ($all_fields[$webform->type] as $name => $info) {
      if (!empty($entity->$name)) {
        $fields[$name] = $entity->$name;
      }
    }

    db_merge(dosomething_recurring_fields_type_to_table($webform->type))
      ->key(array('sid' => $entity->sid))
      ->fields($fields)
      ->execute();
  }
}





class DSTestMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->dependencies = array();
    $this->description = 'Create some bullshit webform submissions.';

    $query = db_select('node', 'n')
      ->fields('n', array('nid', 'uid', 'type', 'title', 'created'))
      ->condition('nid', 10, '<');
    $this->source = new MigrateSourceSQL($query);
    // $fields = array(
    //   'nid' => 'Node id',
    //   'title' => 'Title',
    //   'body' => 'body',
    //   'uid' => 'Uid',
    //   'type' => 'type',
    //   'created' => 'created',
    // );
    // $list_url = "http://d6/migrate/node.xml?fields=nid&";
    // $item_url = "http://d6/migrate/node/:id.xml";
    // $this->source = new MigrateSourceList(
    //   new DSMigrateListXML($list_url),
    //   new MigrateItemXML($item_url),
    //   $fields
    // );

    $webform = node_load(18);
    $this->destination = new MigrateDestinationWebformSubmission($webform);

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationNode::getKeySchema(),
      MigrateDestinationWebformSubmission::getKeySchema()
    );

    $this->addFieldMapping('sid', 'nid');
    $this->addFieldMapping('uid', 'uid')->defaultValue(0);
    $this->addFieldMapping('is_draft')->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')->defaultValue(time());
    $this->addFieldMapping('remote_addr')->defaultValue('127.0.0.1');

    $this->addFieldMapping('data_fake1')->defaultValue('fake value');

    $this->addFieldMapping('name')->defaultValue('humbert');
    $this->addFieldMapping('zip')->defaultValue('zippy');

    // $this->addFieldMapping('data_date')->defaultValue('2011-12-31');
    // $this->addFieldMapping('data_email')->defaultValue('foo@example.com');
    // $this->addFieldMapping('data_file')->defaultValue(11);
    // $this->addFieldMapping('data_markup', 'body')->defaultValue('<p><em>itals!</em></p>');
    // $this->addFieldMapping('data_pagebreak')->defaultValue('IGNORED!');
    // $this->addFieldMapping('data_select')->defaultValue('foo');
    // $this->addFieldMapping('data_text', 'type');
    // $this->addFieldMapping('data_textarea', 'title');
    // $this->addFieldMapping('data_time')->defaultValue('2:03pm');
  }
}



class DSMigrateListXML extends MigrateListXML {
  protected function getIDsFromXML(SimpleXMLElement $xml) {
    $ids = array();
    foreach ($xml as $element) {
      $ids[] = (string)$element->nid;
    }
var_dump($ids);
    return array_unique($ids);
  }
}