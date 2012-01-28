<?php

class DSFile extends Migration {
  static function fetchFields($base_url) {
    $cid = __CLASS__ . ':' . $base_url;
    $cache = cache_get($cid);
    if ($cache !== FALSE && isset($cache->data)) {
      return $cache->data;
    }

    $json = file_get_contents("{$base_url}/file/fields");
    if ($json) {
      $fields = drupal_json_decode($json);
      if ($fields && is_array($fields)) {
        cache_set($cid, $fields);
        return $fields;
      }
    }

    return FALSE;
  }

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('File'));
    $this->dependencies = array();

    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    $this->source = new MigrateSourceMultiItems(
      new DSFileJsonMigrateItems($base_url),
      self::fetchFields($base_url)
    );

    $this->map = new MigrateSQLMap($this->machineName,
      MigrateDestinationFile::getKeySchema(),
      MigrateDestinationFile::getKeySchema()
    );

    $this->destination = new MigrateDestinationFile(array(
      'copy_file' => FALSE,
      'copy_blob' => FALSE,
      'preserve_files' => TRUE,
    ));

    $this->addSimpleMappings(array('filename', 'filemime', 'status', 'timestamp', 'uid'));
    $this->addUnmigratedDestinations(array('fid', 'uri', 'path', 'contents'));
    $this->addUnmigratedSources(array('fid', 'filepath', 'filesize'));

    $this->filesPath = variable_get('file_directory_path', conf_path() . '/files');
  }

  // Helper function to convert disc file paths into URIs.
  static function convertPathToURI($path) {
    // We know that all file paths in the old site start with "files/" so we
    // strip it off.
    return file_stream_wrapper_uri_normalize('public://' . substr($path, 6));
  }

  // Helper function to a file id from a known uri.
  static function getFIDFromURI($uri) {
    $fid = db_select('file_managed', 'f')
      ->fields('f', array('fid'))
      ->condition('uri', $uri)
      ->execute()
      ->fetchField();
    return $fid;
  }

  public function prepare($entity, $row) {
    if (!is_file($row->filepath)) {
      $dir = dirname($row->filepath);
      if ($dir && !is_dir($dir)) {
        print "creating directory '$dir'\n";
        drupal_mkdir($dir);
      }
      // Make sure there's a file on the disk.
      if (variable_get('ds_copy_files', FALSE)) {
        print "fetching 'http://www.dosomething.org/{$row->filepath}'\n";
        copy('http://www.dosomething.org/' . $row->filepath, $row->filepath);
      }
      else {
        print "faking '{$row->filepath}'\n";
        touch($row->filepath);
      }
    }
    $entity->uri = self::convertPathToURI($row->filepath);

    if (empty($entity->fid)) {
      // If the file is already in the file_managed table trick this migrate into
      // becoming an update rather than an insert.
      $fid = self::getFIDFromURI($entity->uri);
      if ($fid) {
        var_dump("we would expect a pdo error.");
        $entity->fid = $fid;
      }
    }
  }

  protected function createStub($migration, $source_key) {
    $fid = $source_key[0];
    $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

    $x = new DSFileJsonMigrateItems($base_url);
    $old_file = $x->getItem($fid);
    if (!$old_file) {
      return NULL;
    }

    $uri = self::convertPathToURI($old_file->filepath);

    // Check if this uri is in the files table.
    $new_fid = self::getFIDFromURI($uri);
    if($new_fid) {
      print "found fid {$old_file->fid}\n";
      return array($new_fid);
    }

    // Create a new one since there is not an existing one.
    $new_file = $old_file;
    $new_file->uri = $uri;
    unset($new_file->fid, $new_file->filepath);
    if (drupal_write_record('file_managed', $new_file)) {
      print "migrated fid {$old_file->fid} to new fid {$new_file->fid}\n";
      return array($new_file->fid);
    }
  }
}
