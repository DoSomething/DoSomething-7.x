<?php

/**
 * Implementation of hook_drush_command().
 */
function dosomething_school_drush_command() {
  $items = array();

  $items['dosomething-school-load'] = array(
    'description' => "Parse the GreatSchools XML data and load it into the database.",
    'aliases' => array('dsgsl'),
  );

  return $items;
}

function drush_dosomething_school_load() {
  $path = variable_get('dosomething_school_greatschools_xml', '/var/www/dosomething/private_files/local-greatschools-feed-allinone.xml');
  $r = new XMLReader();
  if (!$r->open($path)) {
    return drush_set_error(dt('Could not open GreatSchools XML at @path', array('@path' => $path)));
  }

  drush_print(dt('Importing records:'));
  $count = 0;
  $fields = array(
    'universal-id',
    'name',
    'street',
    'city',
    'state',
    'zip',
    'level',
    'lat',
    'lon',
  );
  // Elements we don't care about.
  $ignore = array(
    '!\<review\>.+\<\/review\>!ms',
    '!\<survey-answer\>.+\<\/survey-answer\>!ms',
    '!\<census-info\>.+\<\/census-info\>!ms',
  );
  do {
    if ($r->name === 'school' && $r->nodeType != XMLReader::END_ELEMENT) {
      // Pull out the children and remove the chaff to save space.
      $xml = $r->readOuterXML();
      $xml = preg_replace($ignore, '', $xml);

      $row = array('uid' => 1);
      foreach ($fields as $name) {
        // Regexes are much faster than XML parsing.
        preg_match("!\<$name\>(.+)\<\/$name\>!", $xml, $matches);
        if (isset($matches[1])) {
          $row[$name] = $matches[1];
        }
        // else {
        //   drush_log(dt('@property not found in @school_name', array('@property' => $name, '@school_name' => $row['name'])), 'notice');;
        // }
      }

      // Masage the lat and lon to floats.
      $row['lat'] = (float) $row['lat'];
      $row['lon'] = (float) $row['lon'];

      // Rename their id.
      $row['gsid'] = $row['universal-id'];
      unset($row['universal-id']);

      entity_save('ds_school', $row);

      $count++;
      if ($count % 10000 == 0) {
        print $count;
      }
      else if ($count % 1000 == 0) {
        print '.';
      }
    }

    // Schools are always at depth of 2 so decend until we find them.
    if ($r->depth < 3) {
      $valid = $r->read();
    }
    else {
      $valid = $r->next('school');
    }
  } while ($valid);

  drush_print(dt('Imported @count records.', array('@count' => $count)));

}

