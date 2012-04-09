<?php

class DSIntentions extends DSJsonWebformMigration {
  public function __construct($node_type, $additional_fields = array()) {
    parent::__construct(MigrateGroup::getInstance('Project'), 'ididthis', $additional_fields);
    $this->description .= 'Move the ididthis nodes into project webforms.';
    $this->addFieldMapping('is_draft')
        ->defaultValue(0);

    $this->addFieldMapping('field_project_type', 'field_completed_didthis')->description('data altered in prepareRow');
    $this->addFieldMapping('field_action_guide_reference', 'field_did_nid');
    $this->addFieldMapping('field_num_people_impacted', 'field_number_of_people_your_act');
    $this->addFieldMapping('field_update_people_involved', 'field_hours_volunteered_0');
    $this->addFieldMapping('field_project_title', 'title');

    $this->addUnmigratedSources(array(
      'status',
      'changed',
    ));
  }

  public function prepare($entity, $row) {

  }
}
