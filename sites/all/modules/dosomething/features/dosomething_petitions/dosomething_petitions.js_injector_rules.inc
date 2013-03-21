<?php
/**
 * @file
 * dosomething_petitions.js_injector_rules.inc
 */

/**
 * Implements hook_js_injector_rule().
 */
function dosomething_petitions_js_injector_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 1;
  $rule->name = 'Petitions landing button';
  $rule->description = 'Petitions button';
  $rule->js = 'jQuery(document).ready(function() { jQuery(\'<a href="/petitions/ideas" class="go-button" style="float: right; margin-top: 25px; padding-top: 6px; font-size: 13pt;">Submit Your Own Petition Ideas</a>\').insertBefore(\'h1\'); });';
  $rule->position = 'header';
  $rule->preprocess = 0;
  $rule->inline = 1;
  $rule->page_visibility = 1;
  $rule->page_visibility_pages = 'petitions';
  $export['Petitions landing button'] = $rule;

  return $export;
}
