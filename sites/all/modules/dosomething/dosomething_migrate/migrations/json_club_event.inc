<?php

class DSJsonClubEventMigration extends DSJsonNodeMigration {
  public function __construct() {
    // Send in new fields that we need to the constructor.
    $fields = array();
    $fields['og_groups'] = 'Groups';
    parent::__construct(MigrateGroup::getInstance('ClubEvent'), 'club_event', $fields);
    $this->description = 'club event migration';
    $this->dependencies = array('DSJsonNewUser', 'DSJsonChangedUser', 'DSFile', 'DSJsonClub');

    $this->addFieldMapping('uid', 'uid')->sourceMigration(array('DSJsonNewUser', 'DSJsonChangedUser'));
    $this->addSimpleMappings(array(
      'body',
      'title',
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
    ));

    $this->addFieldMapping('group_audience', 'og_groups')->sourceMigration(array('DSJsonClub'));

    $this->addFieldMapping('upload', '')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    $this->addUnmigratedSources(array(
      'nid',
      'language',
      'path',
      'body',
      'format',
      'teaser',
    ));

    $this->addUnmigratedDestinations(array(
      'nid',
      'revision_uid',
      'revision',
      'log',
      'language',
      'tnid',
      'path',
      'comment',
      'pathauto',
      'is_new',
    ));
  }
  public function prepare($entity, $row) {
  }

  public function prepareRow($row) {
    // Get the group off of the incoming row object and assign it to the 'group'
    // property.
    $row->groups = empty($row->og_groups) ? NULL : $row->og_groups;
  }
}
