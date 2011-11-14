<?php

abstract class DSBaseWebformMigration extends Migration {
  protected $webform;

  /**
   * @param $group
   * @param $node_type
   *   Source node type.
   */
  public function __construct($group = NULL, $node_type) {
    parent::__construct($group);

    $webform_nids = variable_get('webform_migrate_webform_mapping', array());
    $this->webform = node_load($webform_nids[$node_type]);
    if (!$this->webform) {
      var_dump(t('WARNING: @name has no webform node.', array('@name' => $node_type)));
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

    $this->sourceItemReviewPattern = "http://dosomething6.local/node/:id:/edit";
    $this->destinationItemReviewPattern = "http://dosomething.local/node/{$this->webform->nid}/webform-results/:id:/edit";

    $this->destination = new MigrateDestinationWebformSubmissionEntity($this->webform);

    $this->addFieldMapping('uid', 'uid')
      ->description("User ids should be a direct mapping.");
    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
    $this->addFieldMapping('submitted', 'created')
      ->description("Use the node creation date as the webform submission date.");
    $this->addFieldMapping('remote_addr')
      ->defaultValue('127.0.0.1')
      ->description("I don't think we have an IP to use as the submission so I'm using the loopback.");
    $this->addFieldMapping('path', 'path');

    $this->addUnmigratedSources(array('nid', 'promote', 'sticky', 'language'));
    $this->addUnmigratedDestinations(array('sid'));
  }

  protected function addAddressFieldMapping($dest_field, $country_source_field = NULL, array $mapping) {
    $arguments = array();
    foreach ($mapping as $dest_role => $source_field) {
      $arguments[$dest_role] = array('source_field' => $source_field);
      // Add a null mapping so it's not flagged as unmapped.
      $this->addFieldMapping(NULL, $source_field)->description(t("Maps to %role in %field", array('%role' => $dest_role, '%field' => $dest_field)));
    }
    return $this->addFieldMapping($dest_field, $country_source_field)
      ->arguments($arguments);
  }

}

