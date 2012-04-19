<?php

// Project

class DSProject extends DSJsonWebformMigration {
  public function __construct($node_type, $additional_fields = array()) {
    parent::__construct(MigrateGroup::getInstance('Project'), 'project', $additional_fields);
    $this->description .= 'A volunteer project';
    $this->dependencies[] = 'DSFile';

    $this->addFieldMapping('is_draft')
      ->defaultValue(0);
    $this->addFieldMapping('field_impact_type')
      ->defaultValue(1);
    $this->addFieldMapping('field_essay_build_it', 'field_essay_build_it'); # Field: What's your plan of action? (text_long)
    $this->addFieldMapping('field_essay_see_it', 'field_essay_see_it'); # Field: What's the problem you are trying to solve? (text_long)
    $this->addFieldMapping('field_link', 'field_website_link'); # Field: Web site link (link_field)
    $this->addFieldMapping('field_picture', 'field_project_photo') # Field: Project Photo (image)
      ->arguments(array('file_function' => 'file_fid'))
      ->sourceMigration('DSFile');
    $this->addFieldMapping('field_project_title', 'title'); # Field: Title (text)
    $this->addFieldMapping('field_project_type', 'field_type_of_project'); # Field: Project Type (list_text)
    $this->addFieldMapping('field_webform_videos', 'field_embedded_video') # Field: Video (media)
      ->description('prepareRow() handles saving the embed URL into a file')
      ->arguments(array('file_function' => 'file_fid'));
    $this->addFieldMapping('field_impact_amount', 'field_num_people_impacted'); # Field: How many people has your project helped? (number_integer)
    $this->addFieldMapping('field_others_involved', 'field_others_involved'); # Field: How Can Others Help?  (text_long)
    $this->addFieldMapping('field_update_people_involved', 'field_num_people_involved');  # Field: How many people are directly involved in your project? (number_integer)
    $this->addFieldMapping('taxonomy_vocabulary_5', 'vocab_5') # Field: Issues (taxonomy_term_reference)
      ->description('prepareRow() will pull the tids up from keys to values')
      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_action_guide_reference', 'field_related_action_guide');

    // Handle locative data.
    $this->addAddressFieldMapping('field_webform_address', NULL, array(
      'country'             => 'country',
      'thoroughfare'        => 'address',
      'premise'             => 'address2',
      'locality'            => 'city',
      'administrative_area' => 'state',
      'postal_code'         => 'zip',
    ))->defaultValue('US');

    // We prepared the point data as WKT in the preparerow function.
    $this->addFieldMapping('field_geocode_data', 'point');

    // Null mappings
    $this->addUnmigratedSources(array(
      'changed',
      'status',
      'field_inspired_by_dosomething',
      'field_project_age',
      'field_dosomething_award_winner',
      'field_related_campaign',
      'field_fb_like_count',
      'field_hours_volunteered',
      'field_essay_believe_it',
      'field_num_people_inspired',
      'locations',
    ));


    $this->addUnmigratedDestinations(array(
      'field_project_clubs',
      'field_project_goal',
      'field_project_impact',
      'field_project_start_date',
    ));
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

    $row->vocab_5 = array_keys($row->vocab_5);

    // Extract the zip code from the location:
    $row->country = empty($row->locations[0]['country_name']) ? NULL : $row->locations[0]['country_name'];
    $row->address = empty($row->locations[0]['street']) ? NULL : $row->locations[0]['street'];
    $row->address2 = empty($row->locations[0]['additional']) ? NULL : $row->locations[0]['additional'];
    $row->city = empty($row->locations[0]['city']) ? NULL : $row->locations[0]['city'];
    $row->state = empty($row->locations[0]['province']) ? NULL : $row->locations[0]['province'];
    $row->zip = empty($row->locations[0]['postal_code']) ? NULL : $row->locations[0]['postal_code'];
    $row->lat = empty($row->locations[0]['latitude']) ? NULL : $row->locations[0]['latitude'];
    $row->lon = empty($row->locations[0]['longitude']) ? NULL : $row->locations[0]['longitude'];
    if (!is_null($row->lon) && !is_null($row->lat)) {
      $row->point = "POINT($row->lon $row->lat)";
      $row->nocode = TRUE;
    }
    else {
      $row->point = NULL;
      $row->nocode = FALSE;
    }

    // Map the project types to their new values.
    if (!empty($row->field_type_of_project)) {
      $types = array(
        'project idea' => 2,
        'ongoing project' => 3,
        'completed project' => 4,
        'volunteer experience' => 4,
        'no' => 3,
        'yes' => 4,
      );
      if (isset($types[$row->field_type_of_project])) {
        $row->field_type_of_project = $types[$row->field_type_of_project];
      }
      else {
        print "couldn't map project type $row->field_type_of_project\n";
      }
    }
  }

  public function prepare($entity, $row) {
    // We add the locative data on just before saving. It would have been
    // preferable to do this in the constructor but it was not working properly.
    // This is a pretty solid but less elegant solution. We just mash the geo
    // data array onto the new entity.
    if(!is_null($row->lon) && !is_null($row->lat)) {
      global $conf;
      $conf['geocoder_coding_enabled'] = FALSE;
      $entity->field_geocode_data['und'][0]['lat'] = $row->lat;
      $entity->field_geocode_data['und'][0]['lon'] = $row->lon;
      $entity->field_geocode_data['und'][0]['wkt'] = "POINT($row->lon $row->lat)";
      $entity->field_webform_address['und'][0]['geocoder_no_code'] = TRUE;
    }
    else {
      $row->field_geocode_data['und'][0]['wkt'] = NULL;
      $entity->field_webform_address['und'][0]['geocoder_no_code'] = FALSE;
    }
  }
}
