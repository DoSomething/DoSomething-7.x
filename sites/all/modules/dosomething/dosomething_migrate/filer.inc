<?php

function createStub($migration, $source_key) {
  $fid = $source_key[0];
  $base_url = variable_get('ds_migrate_url', 'http://zivtech:zivtech@dosomething6.zivtech.com/migrate');

  $x = new DSFileJsonMigrateItems($base_url);
  $old_file = $x->getItem($fid);
  if (!$old_file) {
    return NULL;
  }

  $uri = file_stream_wrapper_uri_normalize('public://' . substr($old_file->filepath, 6));
  //var_dump($fid, $old_file, $uri);

  // Check if this uri is in the files table.
  $new_fid = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('uri', $uri)
    ->execute()
    ->fetchField();
  if($new_fid) {
    print "found fid {$old_file->fid}\n";
    return array($new_fid);
  }

  $new_file = $old_file;
  unset($new_file->fid, $new_file->filepath);
  $new_file->uri = $uri;
  if (drupal_write_record('file_managed', $new_file)) {
    print "migrated fid {$old_file->fid} to new fid {$new_file->fid}\n";
    return array($new_file->fid);
  }
}

createStub(NULL, array(3156));
createStub(NULL, array(100656));
createStub(NULL, array());
