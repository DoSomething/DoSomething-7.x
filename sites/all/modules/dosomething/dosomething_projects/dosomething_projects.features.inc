<?php
/**
 * @file
 * dosomething_projects.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dosomething_projects_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function dosomething_projects_default_search_api_index() {
  $items = array();
  $items['project_api_index'] = entity_import('search_api_index', '{
    "name" : "Project API index",
    "machine_name" : "project_api_index",
    "description" : null,
    "server" : "solr_dosomething",
    "item_type" : "webform_submission_entity",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "taxonomy_vocabulary_5" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_essay_build_it" : { "type" : "text" },
        "field_essay_see_it" : { "type" : "text" },
        "field_update_people_involved" : { "type" : "integer" },
        "field_project_title" : { "type" : "text" },
        "field_project_goal" : { "type" : "text" },
        "field_others_involved" : { "type" : "text" },
        "field_webform_project_summary" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "field_webform_address:administrative_area" : { "type" : "string" },
        "field_geocode_data:latlon" : { "type" : "string", "real_type" : "location" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "project_report" : "project_report" } }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "location" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "fields" : { "field_geocode_data:latlon" : true },
            "location_searchtype" : "1"
          }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_essay_build_it" : true,
              "field_essay_see_it" : true,
              "field_project_title" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "field_essay_build_it" : true,
              "field_essay_see_it" : true,
              "field_project_title" : true,
              "field_project_goal" : true,
              "field_others_involved" : true,
              "field_webform_project_summary" : true
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
            "fields" : [],
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
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
