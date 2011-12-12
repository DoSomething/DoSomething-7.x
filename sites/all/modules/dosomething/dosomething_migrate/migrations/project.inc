<?php

// Project

class DSProject extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('Project'), 'project');
    $this->description .= 'A volunteer project';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('is_draft')
        ->defaultValue(0);
    // $this->addFieldMapping('data_did_you_cover_another_artists_song_in_your_video_or_was_it_an_original', 'field_botb_cover')
    //   ->description('Select field keys are unchanged.');
    $this->addFieldMapping('field_essay_build_it', 'field_essay_build_it'); # Field: What's your plan of action? (text_long)
    $this->addFieldMapping('field_essay_see_it', 'field_essay_see_it'); # Field: What's the problem you are trying to solve? (text_long)
    $this->addFieldMapping('field_link', 'field_website_link'); # Field: Web site link (link_field)
    $this->addFieldMapping('field_picture', 'field_project_photo') # Field: Project Photo (image)
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_project_report_zip', 'locations'); # Field: Locations (text)
    $this->addFieldMapping('field_project_title', 'title'); # Field: Title (text)
    $this->addFieldMapping('field_project_type', 'field_type_of_project'); # Field: Project Type (list_text)
    $this->addFieldMapping('field_webform_videos', 'field_embedded_video') # Field: Video (media)
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));
    #$this->addFieldMapping('taxonomy_vocabulary_5', ''); # Field: Issues (taxonomy_term_reference)

    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5');
// field_type_of_project Node: Is this a... (text)
// field_inspired_by_dosomething Node: Did DoSomething.org’s content or programs inspire you to start, or help you to grow your project? (number_integer)
// field_project_age Node: Current age (NOTE: this section is for people 25 and younger) (number_integer)
// field_dosomething_award_winner  Node: DoSomething Award Winner? (text)
// field_related_action_guide  Node: OPTIONAL - Link DoSomething action guides or fact pages to this project (nodereference)
// field_related_campaign  Node: Related Campaign or Program (text)
// field_hours_volunteered Node: Total hours volunteered (to date) (number_integer)

    $this->addUnmigratedSources(array('changed', 'status'));
  }

  public function prepareRow($row) {
    // emfields
    foreach (array('field_embedded_video') as $name) {
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

    // Extract the zip code from the location:
    $row->locations = empty($row->locations[0]->postal_code) ? NULL : $row->locations[0]->postal_code;
  }
}

