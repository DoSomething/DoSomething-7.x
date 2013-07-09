<?php

// SITE SETTINGS: VAGRANT EDITION
// 
// The Vagrant image builds without importing the DB, but with MySQL ready to
// go. Below are the credentials for connecting to Cerebro, which is fine if
// you're doing non-data-destructive development or testing. If you want your
// own data sandbox, you'll need to
//
// vagrant ssh
// mysql -u root
// ...etc.
//
// ...And update the credentials below.
//
// You can also connect to a DB on your laptop by using those credentials, but
// you'll need to specify your laptop's network IP address instead of 
// "localhost" or 127.0.0.1.
//
// This includes memcache integration. memcached is running in a standard 
// configuration on port 11211.
//
// This includes Varnish integration. The Varnish-served site is available at
// http://localhost:9999/
//
// Note that these settings proxy files from the production site.

// Required for Selenium-based unit testing.
$base_url = 'http://localhost:8888';

// Cerebro QA access.
$databases = array (
  'default' => 
  array (
    'default' => 
    array (
      'database' => 'qa_dosomething',
      'username' => 'qa_dosomething',
      'password' => 'qa_dosomething',
      'host' => 'cerebro.dosomething.org',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

// Local Vagrant access.
/*
$databases = array (
  'default' => 
  array (
    'default' => 
    array (
      'database' => 'drupal_dosomething_20130617',
      'username' => 'root',
      'password' => '',
      'host' => '127.0.0.1',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
*/

include_once('./includes/cache.inc');
include_once('./sites/all/modules/memcache/memcache.inc');

$conf = array(
  'cache_default_class' => 'MemCacheDrupal',
  'memcache_servers' => array(
    'localhost:11211' => 'default',
  ),
  'memcache_key_prefix' => 'ds1_',
  'cache_class_cache_form' => 'DrupalDatabaseCache',
);

$conf['stage_file_proxy_origin'] = 'http://dosomething.org';

// Varnish config
$conf['reverse_proxy'] = TRUE;
$conf['reverse_proxy_addresses'] = array('127.0.0.1');
