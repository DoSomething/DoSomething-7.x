<?php
/**
 * @file
 * dosomething_schools.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_schools_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function dosomething_schools_default_search_api_index() {
  $items = array();
  $items['school_location_index'] = entity_import('search_api_index', '{
    "name" : "School location index",
    "machine_name" : "school_location_index",
    "description" : null,
    "server" : "solr_dosomething",
    "item_type" : "ds_school",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "sid" : { "type" : "integer" },
        "uid" : { "type" : "integer" },
        "gsid" : { "type" : "integer" },
        "name" : { "type" : "text" },
        "level" : { "type" : "text" },
        "city" : { "type" : "text" },
        "state" : { "type" : "text" },
        "zip" : { "type" : "text" },
        "lat_lon" : { "type" : "string", "real_type" : "location" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : false } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "location" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "lat_lon" : true }, "location_searchtype" : "1" }
        },
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "level" : true,
              "city" : true,
              "state" : true,
              "zip" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "level" : true,
              "city" : true,
              "state" : true,
              "zip" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "name" : true,
              "level" : true,
              "city" : true,
              "state" : true,
              "zip" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "level" : true,
              "city" : true,
              "state" : true,
              "zip" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
