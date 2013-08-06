<?php
/**
 * @file
 * dosomething_clubs.js_injector_rules.inc
 */

/**
 * Implements hook_js_injector_rule().
 */
function dosomething_clubs_js_injector_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 1;
  $rule->name = 'Clubs Closed message';
  $rule->description = 'Shows the clubs closing message on /clubs pages.';
  $rule->js = 'jQuery(\'<div style="background: #e35a68; padding: 5px; border: 1px solid #950127; color: #fff; margin-bottom: 10px; text-align: center;">Club profile pages will be removed on August 15, 2013. As always, we are excited about your club doing something to change your community but will be retiring this feature. Please email <a href="mailto:clubs@dosomething.org">clubs@dosomething.org</a> if you have questions.</div>\').insertAfter(jQuery(\'#main-content\'));';
  $rule->position = 'footer';
  $rule->preprocess = 0;
  $rule->inline = 1;
  $rule->page_visibility = 1;
  $rule->page_visibility_pages = 'clubs/*
clubs';
  $export['Clubs Closed message'] = $rule;

  return $export;
}
