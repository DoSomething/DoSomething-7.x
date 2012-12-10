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

  $items['dosomething-school-canada-load'] = array(
    'description' => "Parse the Canadian Libraries, Schools, and Academic Book Retailers database and load it into the database.",
    'arguments' => array(
      'file' => 'Path to the csv file to import. Note that their data may have to be manually transformed into CSV from XLS beforehand.'
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('dscsl'),
  );

  return $items;
}

function drush_dosomething_school_canada_load($path) {
  if (empty($path)) {
    drush_set_error('DRUSH_MISSING_FILE_PARAM', 'No Canadian datasource csv file was supplied.');
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

  // Create some anonymous functions for specialized string manipulation.
  $tc = function($string) {
    $smallwords = array(
      'of', 'a', 'the', 'and', 'an', 'or', 'nor', 'but', 'is', 'if', 'then',
      'else','when', 'at', 'from', 'by', 'on', 'off', 'for', 'in', 'out', 'over',
      'to', 'into', 'with',
    );

    $words = explode(' ', strtolower(trim($string)));
    foreach ($words as &$word) {
      if (!in_array($word, $smallwords)) {
        $word = ucwords($word);
      }
    }

    return implode(' ', $words);
  };

  $id = function($src_id) {
    static $province_map = array(
      'AB' => 10,
      'SK' => 11,
      'BC' => 12,
      'MB' => 13,
      'NB' => 14,
      'NL' => 15,
      'NS' => 16,
      'NT' => 17,
      'NU' => 18,
      'ON' => 19,
      'PE' => 20,
      'QC' => 21,
      'YT' => 22,
    );
    // Sometimes their db sucks and they put in spaces. why, oh why...
    $src_id = str_replace(' ', '', $src_id);

    if (!preg_match('/[A-Z]{3,4}[0-9]{1,4}/', $src_id)) {
      throw new Exception('ID follows an unexpected pattern: ' . $src_id);
    }

    // Ignore the leading S (it's always the same) and grab the province bit.
    $province = substr($src_id, 1, 2);

    if (!isset($province_map[$province])) {
      throw new Exception(sprintf('Unrecognized province "%s" found in institution ID.', $province));
    }

    $calculated_id = $province_map[$province];

    if (!is_numeric($src_id[3])) {
      $calculated_id .= ord($src_id) . substr($src_id, 4);
    }
    else {
      $calculated_id .= substr($src_id, 3);
    }

    // Finally, pad with leading 8's so we're in a separate numeric space from the other dbs.
    return str_pad($calculated_id, 9, '8', STR_PAD_LEFT);
  };

  $file = new SplFileObject($path);
  // $file->setFlags(SplFileObject::DROP_NEW_LINE | SplFileObject::READ_AHEAD | SplFileObject::SKIP_EMPTY);
  $file->setFlags(SplFileObject::DROP_NEW_LINE | SplFileObject::SKIP_EMPTY | SplFileObject::READ_CSV);
  $total = count(file($file)) - 1;
  $map = $file->fgetcsv();

  // $ignored is the number ignored; $count is the number of the record being
  // processed in the current step of the loop, $imported is the number
  // successfully imported
  $ignored = $count = $imported = 0;
  while ($row = $file->fgetcsv()) {
    $count++;
    // If we don't have 25 records, something broke in the csv parsing. bail.
    if (25 !== count($row)) {
      drush_set_error('DRUSH_BAD_CSV_DELIMITING', dt("Bad record record count on line @count. Likely a problem with the csv delimiting/escaping in the source file.", array('@count' => $count + 1)));
      return;
    }
    $row = array_combine($map, $row);

    // This database contains a lot of noise we don't want. This excludes
    // schoolboards, preschool, and adult education.
    $ignore_types = array('1', 'J', 'P');
    if (in_array($row['TYPE2'], $ignore_types)) {
      $ignored++;
      continue;
    }
    // Also exclude anything that's not identified as a school by its ID. We
    // shouldn't have any of these, as we don't buy this data, but we need to be
    // safe as this factors into unique ID generation.
    if ($row['ID'][0] !== 'S') {
      $ignored++;
      continue;
    }

    $record = array();
    $record['school_id'] = $record['gsid'] = $id($row['ID']);
    $record['uid'] = 1;
    // No names in the current set exceed 127 characters, but be safe anyway.
    $record['name'] = $tc(substr($row['NAME'], 0, 127));
    $record['street'] = $tc($row['ADD1'] . ' ' . $row['ADD2']);
    $record['city'] = $tc($row['CITY']);
    $record['state'] = $row['PROV'];
    // Replace / with space in the province code, as suggested by the database docs.
    $record['zip'] = str_replace('/', ' ', $row['CODE']);
    // ignore extraneous stuff that's jammed into SPEC after the level info
    $spec = explode(' ', $row['SPEC']);
    $record['level'] = $spec[0];
    $record['site'] = $row['WEBSITE'];
    $record['phone'] = $row['PHONE'];
    $record['country'] = 'Canada';
    $record['email'] = $row['EMAIL'];

    if ($record['gsid'][0] !== '8') {
      print_r($record);
      throw new Exception('Generated ID does not have a leading 8 as expected: problem on line ' . ($count + 1));
    }

    // @todo might not be quite right to call all these 'secondary' schools? good enough for now, though
    $record['type'] = 1;

    // Fill in blanks.
    $record['notes'] = $record['lat'] = $record['lon'] = '';

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

    $imported++;
    print "\rProcessing records... (Imported: $imported | Ignored: $ignored | $count/$total total)";
    if ($count % 1000 == 0) {
      entity_get_controller('ds_school')->resetCache();
    }
  }

  drush_print(dt("\n\nImported @count records.", array('@count' => $count)));
  // drush_print(dt("\n\nImported @processed records, ignoring @ignored source records.", array('@processed' => $processed, '@ignored' => $ignored)));
  return;
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
  // first line contains field names
  $total = count(file($file)) - 1;
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
    $record['notes'] = $row['Program_Name'];
    $record['country'] = 'USA';
    // Indicate this is a postsecondary school.
    $record['type'] = 2;
    // Fill in blanks.
    $record['email'] = $record['site'] = $record['phone'] = $record['lat'] = $record['lon'] = '';

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
      $row['type'] = 1;

      $row['country'] = 'USA';

      // Fill in blanks.
      $row['notes'] = $row['email'] = $row['site'] = $row['phone'] = '';

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
