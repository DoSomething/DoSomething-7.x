<?php

class DSFileJsonMigrateItems extends DSJsonMigrateItems {
  public function __construct($base_url) {
    $ts = variable_get('ds_migration_forked_ts', 1317000000);

    $this->listUrl = "{$base_url}/file/list/?page=:page&created_since={$ts}";
    $this->countUrl = "{$base_url}/file/count?created_since={$ts}";
    $this->getUrl = "{$base_url}/file/get/:id";
    parent::__construct();
  }
}

class DSFile extends Migration {
  static function fetchFields($base_url) {
    $url = "$base_url/file/fields/";

    $cid = __CLASS__ . ':' . $url;
    $cache = cache_get($cid);
    if ($cache !== FALSE && isset($cache->data)) {
      return $cache->data;
    }

    $json = file_get_contents($url);
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

    $entity->uri = file_stream_wrapper_uri_normalize('public://' . str_replace($this->filesPath, '', $row->filepath));
  }

  protected function createStub($migration, $source_key) {
    $fid = $source_key[0];

    // First check for an existing file.
    $file = file_load($fid);
    if ($file) {
      print "found existing $fid\n";
      return array($file->fid);
    }

    // Check if it wasn't upgraded yet.
    $file = db_select('files', 'f')
      ->fields('f')
      ->condition('fid', $fid)
      ->execute()
      ->fetchAssoc();
    if ($file) {
      // Migrate record from files to files_managed.
      $file['uri'] = file_stream_wrapper_uri_normalize('public://' . str_replace($this->filesPath, '', $file['filepath']));
      if (drupal_write_record('file_managed', $file)) {
        print "migrated fid $fid from {files} to {file_managed}\n";
        return array($file['fid']);
      }
    }
  }
}
