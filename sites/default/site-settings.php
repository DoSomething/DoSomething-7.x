<?php
include_once('./includes/cache.inc');
include_once('./sites/all/modules/memcache/memcache.inc');

/*$conf = array(
  'cache_default_class' => 'MemCacheDrupal',
  'memcache_servers' => array(
    'localhost:11211' => 'default',
  ),
  'memcache_key_prefix' => 'dosomething_',
  'cache_class_cache_form' => 'DrupalDatabaseCache',
);


$conf['ds_migrate_url'] = 'http://10.179.111.41/migrate';*/



$conf['file_directory_path'] = 'sites/default/files';
$conf['file_temporary_path'] = 'sites/default/files/tmp';
$conf['file_private_path'] = 'sites/default/files/private';
