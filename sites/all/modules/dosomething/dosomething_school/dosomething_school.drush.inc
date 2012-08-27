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

  $items['dosomething-school-postsecondary-load'] = array(
    'description' => "Parse the USDE postsecondary institution CSV data and load it into the database.",
    'arguments' => array(
      'file' => 'Path to the Accreditation*.csv file to import.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('dspsl'),
  );

  return $items;
}

function drush_dosomething_school_postsecondary_load($path) {
  if (empty($path)) {
    drush_set_error('DRUSH_MISSING_FILE_PARAM', 'No accreditation file was supplied.');
    return;
  }

  if (!realpath($path)) {
    // a relative path was probably passed. try resolving it with that.
    $path = drush_cwd() . '/' . $path;
    if (!file_exists($path)) {
      drush_set_error('DRUSH_BAD_FILE_PARAM', "No file could be found at $path");
      return;
    }
  }

  $file = new SplFileObject($path);
  $total = count(file($file)) - 1;
  // first line contains field names
  $map = $file->fgetcsv();

  $count = 0;
  $row = $file->fgetcsv();
  // for some reason the csv seems to produce an array with one key and a null
  // val after the last record, so consider that case to mark EOF.
  while ($file->valid() && (1 !== count($row))) {
    // If we don't have 25 records, something broke in the csv parsing. bail.
    if (25 !== count($row)) {
      drush_set_error('DRUSH_BAD_CSV_DELIMITING', dt("Bad record record count on line @count. Likely a problem with the csv delimiting/escaping in the source file.", array('@count' => $count + 2)));
      return;
    }
    $row = array_combine($map, $row);

    $record = array();
    $record['school_id'] = $record['gsid'] = str_pad($row['Institution_ID'], 9, '9', STR_PAD_LEFT);
    $record['uid'] = 1;
    $record['name'] = substr($row['Institution_Name'], 0, 127);
    $record['street'] = $row['Institution_Address'];
    $record['city'] = $row['Institution_City'];
    $record['state'] = $row['Institution_State'];
    $record['zip'] = trim($row['Institution_Zip'], '"');
    $record['level'] = 'Postsecondary';
    $record['lat'] = $record['lon'] = '';
    $record['notes'] = $row['Program_Name'];
    // Indicate this is a postsecondary school.
    $record['type'] = 2;

    // Check if there's an existing record...
    $schools = entity_load_multiple_by_name('ds_school', FALSE, array('gsid' => $record['gsid']), TRUE);
    $school = reset($schools);
    if ($school) {
      foreach ($record as $key => $value) {
        $school->$key = $value;
      }
    }
    else {
      $school = $record;
    }
    entity_save('ds_school', $school);

    $count++;
    print "\rImporting records... ($count/$total)";
    if ($count % 1000 == 0) {
      entity_get_controller('ds_school')->resetCache();
    }

    // queue up the next row
    $row = $file->fgetcsv();
  }

  drush_print(dt('Imported @count records.', array('@count' => $count)));
  return;
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
    'id',
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

      // Rename the id field to school_id
      $row['school_id'] = $row['id'];
      unset($row['id']);

      /// Indicate this is a secondary school.
      $row['school_type'] = 1;

      // Check if there's an existing record...
      $schools = entity_load_multiple_by_name('ds_school', FALSE, array('gsid' => $row['gsid']), TRUE);
      $school = reset($schools);
      if ($school) {
        foreach ($row as $key => $value) {
          $school->$key = $value;
        }
      }
      else {
        $school = $row;
      }
      entity_save('ds_school', $school);

      print "\rImported $count records.";
      if ($count % 1000 == 0) {
        entity_get_controller('ds_school')->resetCache();
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