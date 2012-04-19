<?php
/**
 * @file
 * dosomething_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function dosomething_search_default_search_api_index() {
  $items = array();
  $items['node_index'] = entity_import('search_api_index', '{
    "name" : "Node index",
    "machine_name" : "node_index",
    "description" : null,
    "server" : "solr_dosomething",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "100",
      "fields" : {
        "nid" : { "name" : "Node ID", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "vid" : {
          "name" : "Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "is_new" : { "name" : "Is new", "indexed" : 0, "type" : "boolean", "boost" : "1.0" },
        "type" : {
          "name" : "Content type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "title" : { "name" : "Title", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "language" : { "name" : "Language", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "url" : { "name" : "URL", "indexed" : 1, "type" : "uri", "boost" : "1.0" },
        "edit_url" : { "name" : "Edit URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "status" : { "name" : "Status", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "promote" : {
          "name" : "Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "sticky" : {
          "name" : "Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "created" : {
          "name" : "Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "changed" : {
          "name" : "Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author" : {
          "name" : "Author",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "source" : {
          "name" : "Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "log" : {
          "name" : "Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "revision" : {
          "name" : "Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "og_membership" : {
          "name" : "Group memberships",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "og_membership",
          "boost" : "1.0"
        },
        "group" : {
          "name" : "Group",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "group",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_9" : {
          "name" : "Tips and Tools",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_5" : {
          "name" : "Issues",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_4" : {
          "name" : "Time",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_2" : {
          "name" : "Where",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_3" : {
          "name" : "Who",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_pageheader" : {
          "name" : "Page header (above title)",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_editorial_feature_type" : {
          "name" : "Editorial feature type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_is_content_general" : {
          "name" : "Is content general?",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_alumni_project" : {
          "name" : "Enter Name of the Project (already in our system) ",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_city_2" : { "name" : "City", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_contact_information" : {
          "name" : "Contact Information",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_description" : {
          "name" : "Describe what this winner does\\/did",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_people_impacted" : {
          "name" : "People impacted by winner",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_twitter" : {
          "name" : "Twitter Handle ",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_type" : {
          "name" : "Finalist or Winner",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_recipient_age" : {
          "name" : "Recipient\'s Age",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_recipient_birthdate" : {
          "name" : "Recipient\'s Birth Date",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_year_awarded" : {
          "name" : "Year in which award\\/grant was awarded",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_editorial_reference" : {
          "name" : "Content Reference",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "webform_submission_entity",
          "boost" : "1.0"
        },
        "field_webform_project_submission" : {
          "name" : "Enter Name of the Project (already in our system)",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "webform_submission_entity",
          "boost" : "1.0"
        },
        "field_state_plain" : { "name" : "State", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "taxonomy_vocabulary_6" : {
          "name" : "Celebrity Name Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_11" : {
          "name" : "Charity",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_cause_video_author" : {
          "name" : "Video source",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_cause_video_description" : {
          "name" : "Video description",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_emotive_list" : {
          "name" : "Emotional Category the video falls under",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_recommended_content" : {
          "name" : "Related Guides",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_recommended_videos" : {
          "name" : "Recommended Videos",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_17" : {
          "name" : "How did you hear about Do Something Clubs?",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_club_leader_birthdate" : {
          "name" : "Date of birth",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_club_address" : { "name" : "Address", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_club_agreement" : {
          "name" : "Clubs Agreement",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_club_city" : { "name" : "City", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_club_state" : { "name" : "State", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_club_zip" : {
          "name" : "ZIP\\/Postal Code",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "group_group" : {
          "name" : "Group type",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "og_roles_permissions" : {
          "name" : "Group roles and permissions",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_email" : { "name" : "Your Email", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_name_last" : { "name" : "Last Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_phone_required" : {
          "name" : "Your Cell Phone",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_name" : { "name" : "First Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_camp" : {
          "name" : "My Do Something Club is going to work on",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "og_node_link" : {
          "name" : "Add group content",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_easy_idea_120char" : {
          "name" : "Twitter or Mobile abbrv title (120)",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_easy_idea_internal_link" : {
          "name" : "Related stuff on DoSomething.org",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_select_easyidea_pic" : {
          "name" : "select_easyidea_pic",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_grant_type" : {
          "name" : "Select the grant that you received",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_money_for" : {
          "name" : "What was the money for?",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_scholarship_type" : {
          "name" : "Which scholarship?",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_blog_type" : {
          "name" : "Blog type",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_subtitle" : { "name" : "Subtitle", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_blog_causes" : {
          "name" : "Causes\\/Issues",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_editorial_teaser" : { "name" : "Teaser", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_article" : {
          "name" : "Title of Article",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_impressions" : {
          "name" : "Estimated Impressions",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_press_type" : {
          "name" : "Type of Press",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_publication_date" : {
          "name" : "Date of Publication",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_related_campaign" : {
          "name" : "Related Campaign or Program",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "taxonomy_vocabulary_18" : {
          "name" : "DoSomethingU Majors",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dsu_guideteaser" : {
          "name" : "Super short teaser (140 chars)",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsu_guide_type" : {
          "name" : "Type of guide",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "taxonomyextra" : {
          "name" : "Taxonomy upgrade extras",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_query_count" : {
          "name" : "query_count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_update_people_impacted" : {
          "name" : "Updated number of new people\\/animals helped",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_update_people_involved" : {
          "name" : "Updated number of new people involved in the project",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_project" : {
          "name" : "Project",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_campaign_background_color" : {
          "name" : "Background color",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_campaign_causes_issues" : {
          "name" : "Causes\\/Issues",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_campaign_foreground_color" : {
          "name" : "Foreground color",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_campaign_headline" : { "name" : "Headline", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_campaign_call_to_action" : {
          "name" : "Call to action",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_scholarship_application" : {
          "name" : "Scholarship",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_closing_date" : {
          "name" : "Closing Date",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_open_date" : { "name" : "Open Date", "indexed" : 0, "type" : "date", "boost" : "1.0" },
        "field_campaign" : {
          "name" : "Campaign Sign Up",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_infusion_action" : {
          "name" : "InfusionSoft Action ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_mc_campaign" : {
          "name" : "Mobile Commons Campaign ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_mc_optin" : {
          "name" : "Mobile Commons Opt-In Path",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_are_you_yac_club_grant" : {
          "name" : "Are you a member of any of the following? ",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_bc_bio" : { "name" : "Your Bio", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_first_name" : { "name" : "First Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_select_bootcamp_2009" : {
          "name" : "Select the Boot Camp you want to attend",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_plumgrant_email" : {
          "name" : "Email Address",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_city" : { "name" : "City", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_phone_number_1" : {
          "name" : "Phone Number",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_email_0" : { "name" : "Email", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_application_deadline" : {
          "name" : "Application Deadline",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_application_deadline_2" : {
          "name" : "Application Deadline",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_award_focus" : {
          "name" : "Award Focus",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_grantsdb_award_name" : {
          "name" : "Name of Award",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_grantsdb_contact_name" : {
          "name" : "Contact Name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_posters_email" : {
          "name" : "Poster\'s Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_rolling" : {
          "name" : "Grant status",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_type_of_award" : {
          "name" : "Type of Award",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_winners_announced" : {
          "name" : "Winners announced",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_grants_how_many" : { "name" : "How Many?", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_grants_how_much" : { "name" : "How Much?", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_project_age" : { "name" : "Age", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "field_number_people_impacted" : {
          "name" : "Number of people impacted by your project since you won the grant",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_number_people_in_organiza" : {
          "name" : "Number of people involved with your project\\/organization",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_evaluation_of_budget_pred" : {
          "name" : "Were your original predictions regarding budget accurate? Why or why not?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_grant_impact" : {
          "name" : "How did winning a DoSomething grant affect your organization or project?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_project_evolution" : {
          "name" : "How did your project unfold and develop? How was your community impacted by your project?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_project_highlights" : {
          "name" : "List three highlights of your project",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_things_to_do_differently" : {
          "name" : "List three things that you would do differently next time and explain why and how you would do them differently",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_zip_code_2" : { "name" : "Zip Code", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_recommenders_email_0" : {
          "name" : "#2 Recommender\'s Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_name_0" : {
          "name" : "#2 Recommender\'s Name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_phone_numb_0" : {
          "name" : "#2 Recommender\'s Phone Number",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_relationsh_0" : {
          "name" : "#2 Recommender\'s Relationship to you",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_where_did_you_hear" : {
          "name" : "Where did you hear about the Do Something Awards?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_plumgrant_address" : { "name" : "Address", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_plumgrant_project" : {
          "name" : "Your Do Something Project Posting ",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_application_status" : {
          "name" : "Is this application complete?",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dsaward_app_birthdate" : { "name" : "Birthday", "indexed" : 0, "type" : "date", "boost" : "1.0" },
        "field_gender" : { "name" : "Gender", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_plumgrant_legal1" : {
          "name" : "Legal 1",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_plumgrant_legal2" : {
          "name" : "Legal 2",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_plumgrant_legal3" : {
          "name" : "Legal 3",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_plumgrant_legal4" : {
          "name" : "Legal 4",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_recommenders_email" : {
          "name" : "#1 Recommender\'s Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_name" : {
          "name" : "#1 Recommender\'s Name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_phone_number" : {
          "name" : "#1 Recommender\'s Phone Number",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recommenders_relationship" : {
          "name" : "#1 Recommender\'s Relationship to you",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_when_did_your_projectorga" : {
          "name" : "How long has your project\\/organization been in existence?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_plumgrant_videourl" : {
          "name" : "YouTube or Video URL",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_plumgrant_onesentence" : {
          "name" : "Short Description",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_people_impacted" : {
          "name" : "Number of people you have helped",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_nid" : {
          "name" : "Application Node ID",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dsaward_rec_which" : {
          "name" : "Which recommender are you?",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_application_judged" : {
          "name" : "Which application are you judging?",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_category_1" : {
          "name" : "Has identified a problem and clear ways to combat it",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_10" : {
          "name" : "Demonstrates that s\\/he has directly fueled the success of his\\/her work",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_2_0" : {
          "name" : "Is passionate and committed to empowering the community in which s\\/he works",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_3" : {
          "name" : "Has cultivated long-term and respectful relationships within his\\/her community",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_4" : {
          "name" : "Has extensively and tangibly improved the lives of others",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_5" : {
          "name" : "Has created great awareness about his\\/her issue or cause",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_6" : {
          "name" : "Is confident and enthusiastic about being a community leader",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_7" : {
          "name" : "Has a long term vision for the growth and sustainability of his\\/her work",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_8" : {
          "name" : "Is the \\"best-in-class\\" in his\\/her issue",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_category_9" : {
          "name" : "Is Do Something Award winner material",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_comments_or_suggestions_f" : {
          "name" : "Comments will be used by the judging committee, please tell us any other thoughts about this applicant",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_phone_number_optional" : {
          "name" : "Phone Number (optional)",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_problem_description" : {
          "name" : "Please describe your problem or question",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_problem_type" : {
          "name" : "Which section of the site is causing the problem?",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_problem_urgency" : {
          "name" : "On a scale of 1-10 how urgent is this?",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_report_back_reference" : {
          "name" : "Campaign",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_report_back_magic_fields" : {
          "name" : "Enabled Fields",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_signup_magic_fields" : {
          "name" : "Enabled Fields",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_phone_number" : {
          "name" : "Your phone number",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_nominee_email" : {
          "name" : "Nominee\'s Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_nominee_name" : {
          "name" : "Nominee\'s Name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_school" : {
          "name" : "School you attend",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_grant_judge_application" : {
          "name" : "Grant Application",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "webform_submission_entity",
          "boost" : "1.0"
        },
        "field_grant_judge_community" : {
          "name" : "Community focus",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_creativity" : {
          "name" : "Creativity",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_diversity" : {
          "name" : "Diversity",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_focus" : {
          "name" : "Measurable change",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_nid" : {
          "name" : "Application Node ID",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_grant_judge_problem" : {
          "name" : "Long-term problem solving action",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_winner" : {
          "name" : "Grant winner material?",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_grant_judge_youth" : {
          "name" : "Youth led and driven",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_essay_believe_it" : {
          "name" : "Essay 2: Believe It",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_essay_next_steps" : {
          "name" : "Essay 4: Next Steps",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_college_attended" : {
          "name" : "College attended (if applicable)",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "search_api_language" : {
          "name" : "Item language",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "search_api_viewed" : {
          "name" : "Entity HTML output",
          "type" : "text",
          "boost" : "1.0",
          "indexed" : 1
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "action_guide" : "action_guide",
              "blog" : "blog",
              "campaign" : "campaign",
              "cause_video" : "cause_video",
              "club" : "club",
              "club_event" : "club_event",
              "awards_archive" : "awards_archive",
              "dsu_askprof" : "dsu_askprof",
              "easy_idea" : "easy_idea",
              "editorial_content_" : "editorial_content_",
              "grant_alumni" : "grant_alumni",
              "page" : "page",
              "poll" : "poll",
              "press" : "press",
              "scholarship" : "scholarship",
              "dsu_guides" : "dsu_guides",
              "tips_and_tools" : "tips_and_tools"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : "title",
              "field_pageheader" : "field_pageheader",
              "field_city_2" : "field_city_2",
              "field_cause_video_description" : "field_cause_video_description",
              "field_subtitle" : "field_subtitle",
              "field_editorial_teaser" : "field_editorial_teaser",
              "field_article" : "field_article",
              "field_dsu_guideteaser" : "field_dsu_guideteaser",
              "field_campaign_headline" : "field_campaign_headline",
              "field_campaign_call_to_action" : "field_campaign_call_to_action",
              "field_plumgrant_videourl" : "field_plumgrant_videourl",
              "field_plumgrant_onesentence" : "field_plumgrant_onesentence",
              "url" : 0,
              "author" : 0,
              "field_editorial_feature_type" : 0,
              "field_alumni_project" : 0,
              "field_year_awarded" : 0,
              "field_state_plain" : 0,
              "field_related_campaign" : 0,
              "field_project" : 0,
              "field_campaign_causes_issues" : 0,
              "search_api_language" : 0
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_pageheader" : "field_pageheader",
              "field_city_2" : "field_city_2",
              "field_cause_video_description" : "field_cause_video_description",
              "field_subtitle" : "field_subtitle",
              "field_editorial_teaser" : "field_editorial_teaser",
              "field_article" : "field_article",
              "field_dsu_guideteaser" : "field_dsu_guideteaser",
              "field_campaign_headline" : "field_campaign_headline",
              "field_campaign_call_to_action" : "field_campaign_call_to_action",
              "field_plumgrant_videourl" : "field_plumgrant_videourl",
              "field_plumgrant_onesentence" : "field_plumgrant_onesentence",
              "url" : 0,
              "author" : 0,
              "field_editorial_feature_type" : 0,
              "field_alumni_project" : 0,
              "field_year_awarded" : 0,
              "field_state_plain" : 0,
              "field_related_campaign" : 0,
              "field_project" : 0,
              "field_campaign_causes_issues" : 0,
              "search_api_language" : 0
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
              "title" : "title",
              "field_pageheader" : "field_pageheader",
              "field_city_2" : "field_city_2",
              "field_cause_video_description" : "field_cause_video_description",
              "field_subtitle" : "field_subtitle",
              "field_editorial_teaser" : "field_editorial_teaser",
              "field_article" : "field_article",
              "field_dsu_guideteaser" : "field_dsu_guideteaser",
              "field_campaign_headline" : "field_campaign_headline",
              "field_campaign_call_to_action" : "field_campaign_call_to_action",
              "field_plumgrant_videourl" : "field_plumgrant_videourl",
              "field_plumgrant_onesentence" : "field_plumgrant_onesentence",
              "url" : 0,
              "author" : 0,
              "field_editorial_feature_type" : 0,
              "field_alumni_project" : 0,
              "field_year_awarded" : 0,
              "field_state_plain" : 0,
              "field_related_campaign" : 0,
              "field_project" : 0,
              "field_campaign_causes_issues" : 0,
              "search_api_language" : 0
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : { "file" : "", "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc" }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function dosomething_search_default_search_api_server() {
  $items = array();
  $items['solr_dosomething'] = entity_import('search_api_server', '{
    "name" : "Solr DoSomething",
    "machine_name" : "solr_dosomething",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "10.179.104.149",
      "port" : "8000",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
