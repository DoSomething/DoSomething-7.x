<?php

class DSJsonClubMigration extends DSJsonNodeMigration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('Club'), 'club');
    $this->description = 'club migration';
    $this->dependencies = array('DSJsonNewUser', 'DSJsonChangedUser', 'DSFile');

    $this->addFieldMapping('uid', 'uid')->sourceMigration(array('DSJsonNewUser', 'DSJsonChangedUser'));
    $this->addSimpleMappings(array(
      'title',
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
      'language',
      'path',
      'field_name_last',
      'field_name',
      'field_phone_required',
      'field_email',
      'field_club_leader_birthdate',
      'field_camp',
      'field_club_address',
      'field_club_city',
      'field_club_state',
      'field_club_zip',
      'field_club_agreement',
    ));

    $this->addFieldMapping('field_club_picture', 'field_club_picture')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    $this->addFieldMapping('field_project_photo', 'field_project_photo')
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');

    #convert to media.
    $this->addFieldMapping('field_club_video', 'field_club_video')
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));

    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5')
      ->separator(',');
    $this->addFieldMapping('taxonomy_vocabulary_17', 'vocab_17')
      ->separator(',');


    $this->addUnmigratedSources(array(
      'nid',
      'field_club_expected_members',
      'field_club_member_1_email',
      'field_club_picture',
      'field_club_member_2_email',
      'field_project_photo',
      'field_club_leader_birthdate',
      'field_club_member_3_email',
      'field_club_member_4_email',
      'field_club_project_idea_1',
      'field_field_club_country',
      'field_club_project_idea_2',
      'field_club_is_school',
      'field_club_project_idea_other',
      'field_club_student_leader_first',
      'field_club_leader_last_name',
      'field_club_leader_email',
      'field_other_value',
      'field_school',
      'field_school_level',
      'field_yacapp_school_type',
      'field_clubs_meeting_location',
      'field_club_intended_role',
      'field_club_url',
      'locations',
    ));
    $this->addUnmigratedDestinations(array(
      'nid',
      'is_new',
      'revision_uid',
      'revision',
      'log',
      'tnid',
      'og_roles_permissions',
      'og_node_link',
      'group_group',
      'field_club_verified',
      'comment',
      'pathauto',
    ));
  }
  public function prepare($entity, $row) {
    $entity->uid = !$entity->uid ? $row->uid : $entity->uid;
  }

  public function prepareRow($row) {
    // Fix bad dates caused by only storing 2 digits for the year.
    $date = $row->field_club_leader_birthdate;
    $year = substr($date, 0, 4);
    $year = $year > 2012 ? $year -= 100 : $year;
    $year = $year <= 1912 ? $year += 100 : $year;
    $date = substr($date, 4);
    $date = $year . $date;
    $row->field_club_leader_birthdate = $date;

    // emfields
    foreach (array('field_club_video') as $name) {
      if (!empty($row->$name)) {
        if (is_array($row->$name)) {
          foreach ($row->$name as &$value) {
            $value = $this->fidFromEmField($value, $row->uid);
          }
        }
        else {
          $row->$name = $this->fidFromEmField($row->$name, $row->uid);
        }
      }
    }
    $terms = "";
    if (!empty($row->vocab_5)) {
      foreach ($row->vocab_5 as $term) {
        $terms .= $term . ',';
      }
      $row->vocab_5 = trim($terms, ',');
    }

    $terms = "";
    if (!empty($row->vocab_17)) {
      foreach ($row->vocab_17 as $term) {
        $terms .= $term . ',';
      }
      $row->vocab_17 = trim($terms, ',');
    }
  }
}
