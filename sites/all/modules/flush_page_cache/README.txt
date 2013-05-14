
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Features
 * Use Cases
 * Recommended Modules
 * Installation
 * Example Custom Settings
 * Maintainers


INTRODUCTION
------------

Easing the pain when you need to flush...Drupal's cache.

Flushing Drupal's cache on a large site can feel like you're waiting to takeoff
on the tarmac at JFK. The delay comes from the fact that when you clear Drupal's
cache, it clears everything. Most of time you just want to flush the cache
for specific object on a page.

The 'Flush page cache' module solves this problem by flushing only the cached
objects for a single page. Additionally, you can define custom objects and
cache tables to be cleared on specific pages.


FEATURES
--------

- Many button placement options including: in the page footer or with a block.
  If you use the Administration Menu module, a link is included here as well.

- The ability to define specific cache objects to be cleared when flushing page
  caches.

- Varnish integration, which also purges the cached page from Varnish.


USE CASES
---------

- You have nodes nested in views nested in a panel page. You've edited a node
  that's displayed on this page, but you want the change to be seen immediately.

- You have a large team of non-technical content editors who frequently run into
  the scenario above and you want to give them an easy, one-button solution to
  their content being updated in the lists they manage.

- You've just cleared the entire website's cache through the normal means and
  for whatever reason, a few pages are rendered and cached in a broken state.


RECOMMENDED MODULES
-------------------

- Administration Menu: Provides a theme-independent administration interface.
  http://drupal.org/project/admin_menu

- Memcache: High performance integration with memcache.
  http://drupal.org/project/memcache

- APC - Alternative PHP Cache: Provides a user cache for storing application
  data.
  http://drupal.org/project/apc

- Varnish: Provides integration with the Varnish HTTP accelerator.
  http://drupal.org/project/varnish


INSTALLATION
------------

1. Download and enable the flush_page_cache module in the usual Drupal way.

2a.If you're using Drupal default caching you will need to add the following to
   your settings.php file:

    // Wrapper class for extending DrupalDatabaseCache to support flushing a page's cache.
    $conf['cache_backends'][] = './sites/all/modules/sandbox/flush_page_cache/flush_page_cache.cache.inc';
    $conf['cache_default_class'] = 'FlushPageCacheDrupalDatabaseCache';

   See the notes section below for an explanation.

2b.If you're using a contrib module, you will need to build the flush page cache
   wrapper class. Below is an example of the wrapper class for the Memcache module.
   Please since the memcache.inc in being required in settings.php you do not
   need to add it to the $conf['cache_backends'][].

    // Wrapper class for extending MemCacheDrupal to support flushing a page's cache.
    require_once DRUPAL_ROOT . 'sites/all/modules/memcache/memcache.inc';
    class FlushPageCacheMemCacheDrupal extends MemCacheDrupal {
      function get($cid) {
        // Handle flush page cache request by deleting the cached object and returning FALSE.
        if (function_exists('flush_page_cache_requested') && flush_page_cache_requested()) {
          return FALSE;
        }

        return parent::get($cid);
      }
    }
    $conf['cache_default_class'] = 'FlushPageCacheMemCacheDrupal';

    See the notes section below for an explanation.

3. Give the appropriate permissions to the appropriate roles on the permissions
   page. The "flush page cache" permission allows a user to see the button and
   perform the action and should only be given to trusted roles.

4. Optionally, you may configure additional settings on the form located at
   'Configuration > Development > Flush_page_cache'
   (admin/config/development/flush_page_cache). See the notes section below on what you
   may want to add in the "custom settings" area on this page.

5. Optionally, you may place the "Flush page cache" block on your pages. It's
   recommended you only allow this for trusted roles. It may be useful to
   style this block to a fixed position on the page for ease of use.


NOTES
-----

- This module works by forcing Drupal's cache_get() function to always delete
  the cached object and return a NULL object.

  This module extends the default cache class (ie 'DrupalDatabaseCache')
  to create flush page cache class (ie 'FlushPageCacheDrupalDatabaseCache'
  which just contains the extra code required to support flushing a page's cache.

- Modules implement caching mechanisms in very diverse ways; for example, they
  may cache by role or by language or even by user. Because of the way this
  module works, it may only clear the cache for you. To get around this, you can
  define custom cache IDs, tables, and paths on the configuration page.


EXAMPLE CUSTOM SETTINGS
-----------------------

- If you want to clear all view caches for the "blog" view when you flush the
  cache at http://example.com/blog, add the following custom setting:

  Path = blog
  Cache ID = blog:
  Table = cache_views_data
  Wildcard = TRUE

- If you want to clear block 12's cache on all paths beginning with "about", add
  the following custom setting:

  Path = about/*
  Cache ID = block:12:
  Table = cache_block
  Wildcard = TRUE

- If you want to clear the entire page cache every time you flush a page's cache
  (this is a horrible idea, but it's possible) add the following custom setting:

  Path = *
  Cache ID = *
  Table = cache_page
  Wildcard = TRUE

This is a very extensible system, since it basically adds a GUI to Drupal's
cache_clear_all() function. You may need to do some research into how Drupal and
some contrib modules store their cached objects before you can use this fully.


MAINTAINERS
-----------------

- Eric Peterson (iamEAP)
  http://drupal.org/user/1467594

- Jacob Rockowitz (jrockowitz)
  http://drupal.org/user/371407
