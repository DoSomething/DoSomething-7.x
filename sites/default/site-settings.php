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
  'fb_social_appid' => '93836527897', 
  'fb_social_base_url' => 'http://dosomething.zivtech.com',
);

