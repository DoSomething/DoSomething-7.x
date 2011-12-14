<?php

// Project

class DSProject extends DSJsonWebformMigration {
  public function __construct($node_type) {
    parent::__construct(MigrateGroup::getInstance('Project'), 'project');
    $this->description .= 'A volunteer project';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('is_draft')
        ->defaultValue(0);
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
    $this->addFieldMapping('field_num_people_impacted', 'field_num_people_impacted'); # Field: How many people has your project helped? (number_integer)
    $this->addFieldMapping('field_others_involved', 'field_others_involved'); # Field: How Can Others Help?  (text_long)
    $this->addFieldMapping('field_update_people_involved', 'field_num_people_involved');  # Field: How many people are directly involved in your project? (number_integer)
    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5'); # Field: Issues (taxonomy_term_reference)

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

