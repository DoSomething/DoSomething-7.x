<?php
include_once('./includes/cache.inc');
include_once('./sites/all/modules/memcache/memcache.inc');

$conf = array(
  'cache_default_class' => 'MemCacheDrupal',
  'memcache_servers' => array(
    'localhost:11211' => 'default',
  ),
  'memcache_key_prefix' => 'dosomething_',
  'cache_class_cache_form' => 'DrupalDatabaseCache',
  // Development versions
  'fbconnect_appid' => '160632053975149',
  'fbconnect_skey' => '63c5ac4d7c73f0f6500a52ebf2b744ad',
);


