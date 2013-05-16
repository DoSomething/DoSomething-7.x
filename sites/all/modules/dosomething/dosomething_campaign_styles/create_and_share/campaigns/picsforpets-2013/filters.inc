<?php

/**
 *  @file
 *  Filters allow us to show only specific content on specific pages.  Example filters:
 *    - "/friends" filter shows only posts from your facebook friends
 *    - "/time-week" filter shows only posts from the previous week.
 *
 *  The possibility are endless.  All of the following filters are anonymous functions that
 *  respond to a specific path being viewed (specified as the key in each filter, using a
 *  regular expression syntax).  Each filter is run within hook_views_query_alter()
 *  with four (4) parameters passed into the callback function:
 *    - $match: The output from preg_match, as defined by your regular expression path.
 *    - &$view: (alter-able) instance of the view object.
 *    - &$query: (alter-able) instance of the views query object.
 *    - $settings: The settings for the current campaign.
 *
 *  Altering the query parameter allows us to change the actual view query, and, as a result,
 *  the output of the query.  Each filter creates a responsive path -- when the campaign is
 *  constructed, it enables any routes that match any regular expression key found below.
 *
 */

/**
 * General settings -- Algorithm across all filters.
 */
$filter['^(' . $settings['campaign_root'] . ')'] = function($match, &$view, &$query) use ($settings) {    // Make sure we're only viewing posts from this node.
  // Make sure we're only showing posts from the campaign we're looking at.
  $query->where[1]['conditions'][] = array(
    'field' => 'node.nid',
    'value' => $settings['campaign_nid'],
    'operator' => '=',
  );

  // If the algorithm is enabled, use it!
  if ($settings['allow_ranking_algorithm']) {
    $query->fields['real_weight'] = array(
      'field' => '((((webform_submissions.submitted - ' . REQUEST_TIME . ') + ' . $settings['algorithm']['grace_period'] . ') / ' . $settings['algorithm']['weight_divisor'] . ') + field_data_field_' . $settings['fields']['weight']['field'] . '.field_' . $settings['fields']['weight']['field'] . '_value)',
      'table' => '',
      'alias' => 'real_weight',
    );

    $query->orderby[0]['field'] = 'real_weight';
  }
};

/**
 * Front page filter.  Shows only posts from the last week.
 */
$filter['^(' . $settings['campaign_root'] . ')$'] = function($match, &$view, &$query) {
};

/**
 * Single post filter.
 */
$filter['^(' . $settings['campaign_root'] . ')/(?<showid>[0-9]+)$'] = function($match, &$view, &$query) {
  // We want to ignore featured pets on the singular view.
  if ($view->current_display == 'attachment_1') {
    $query->where[1]['conditions'][] = array(
      'field' => 1,
      'value' => 2,
      'operator' => '=',
    );
  }
  else {
    // The ID of the submission.
    $showid = $match['showid'];

    // Show only the specific post.
    $query->where[1]['conditions'][] = array(
      'field' => 'webform_submissions.sid',
      'value' => $showid,
      'operator' => '=',
    );

    // Okay to show promoted pets on the singular view.
    unset($query->where[1]['conditions'][4]);
  }
};

/**
 * Cats / dogs / other bullshit
 */
$filter['^(' . $settings['campaign_root'] . ')\/((?<type>(cat|dog|other))s?)?\-?((?<state>(AL|AK|AS|AZ|AR|CA|CO|CT|DE|DC|FL|GA|GU|HI|ID|IL|IN|IA|KS|KY|LA|ME|MH|MD|MA|MI|MN|MS|MO|MT|NE|NV|NH|NJ|NM|NY|NC|ND|MP|OH|OK|OR|PW|PA|PR|RI|SC|SD|TN|TX|UT|VT|VI|VA|WA|WV|WI|WY)))?(?!featured)'] = function($match, &$view, &$query) use ($settings) {
  // What's this? There's an attachment that loads featured pets at the top 
  // of the page, and it causes issues for filter pages.  This loads a basic
  // false statement into the query so it doesn't show up on the filter pages.
  if ($view->current_display == 'attachment_1') {
    $query->where[1]['conditions'][] = array(
      'field' => 1,
      'value' => 2,
      'operator' => '=',
    );
  }
  else {
    // Show promoted pets organically in filtered pages.
    unset($query->where[1]['conditions'][4]);

    // Cat / dog / other
    if (!empty($match['type'])) {
      $query->where[1]['conditions'][2]['value'] = $match['type'];
      $query->where[1]['conditions'][2]['operator'] = '=';
    }

    // State abbreviations (New York = NY, &etc.)
    if (!empty($match['state'])) {
      $query->where[1]['conditions'][3]['value'] = $match['state'];
      $query->where[1]['conditions'][3]['operator'] = '=';
    }
  }
};

/**
 * Featured pets.
 */
$filter['^(' . $settings['campaign_root'] . ')\/featured'] = function($match, &$view, &$query) use ($settings) {
  // Ignore the featured attachment.  We're looking at featured pets anyway.
  if ($view->current_display == 'attachment_1') {
    $query->where[1]['conditions'][] = array(
      'field' => 1,
      'value' => 2,
      'operator' => '=',
    );
  }
  else {
    // Change the "promoted_value IS NULL" condition to "promoted_value = 1".  Shows only promoted pets.
    $query->where[1]['conditions'][4]['value'] = 1;
    $query->where[1]['conditions'][4]['operator'] = '=';
  }
};