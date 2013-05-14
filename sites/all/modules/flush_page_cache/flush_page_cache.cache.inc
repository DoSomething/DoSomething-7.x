<?php
/**
 * @file
 * Define flush page cache cache class for Drupal default database caching.
 */

class FlushPageCacheDrupalDatabaseCache extends DrupalDatabaseCache {
  function get($cid) {
    // Handle flush page cache request by deleting the cached object and returning FALSE.
    if (function_exists('flush_page_cache_requested') && flush_page_cache_requested()) {
      return FALSE;
    }

    return parent::get($cid);
  }
}
