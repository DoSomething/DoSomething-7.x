<?php

/**
 *  Handles time filters.
 */
$filter['^(' . $settings['campaign_root'] . ')/(time-(.*))$'] = function($match, &$view, &$query) {
  $time = $match[3];
  if ($time == 'today') {
    $quey->where[1]['conditions'][1] = array(
      'field' => 'webform_submissions.submitted',
      'value' => mktime(0, 0, 0),
      'operator' => '>=',
    );
    unset($query->orderby[1]);
  }
  else if ($time == 'all') {
    unset($query->orderby[0]);
  }
};

/**
 *  Friend's filter
 */
$filter['^(' . $settings['campaign_root'] . ')/(friends/)?(?<showid>[0-9]+)$'] = function($match, &$view, &$query) {
  $showid = $match['showid'];
  // Try and find the submission with this ID and mark it as relevant
  $query->fields['ided'] = array(
    'field' => 'IF (webform_submissions.sid = ' . $showid . ', 1, 0)',
    'table' => '',
    'alias' => 'is_the_one',
  );

  // When we're looking for one specific element, we can show it first in the list
  // by doing "is_the_one DESC" (see "is_the_one" definition above).  Everything else
  // will resume as normal below the post.
  $theone = array(
    'field' => 'is_the_one',
    'direction' => 'DESC',
  );

  $query->where[1]['conditions'][] = array(
    'field' => 'webform_submissions.sid',
    'value' => $showid,
    'operator' => '=',
  );

  // Prepend "is_the_one" order to the beginning of the orderby array.
  array_unshift($query->orderby, $theone);
};

/**
 *  Weekly filter
 */
$filter['^(' . $settings['campaign_root'] . ')$'] = function($match, &$view, &$query) {
  // Monday is always the start of the week.  Get this week's Monday in days (ago).
  $monday = (date('N') - 1);
  if ($monday == 0) {
    $query->where[1]['conditions'][] = array(
      'field' => 'webform_submissions.submitted',
      'value' => mktime(0, 0, 0),
      'operator' => '>=',
    );
  }
  else {
    $query->where[1]['conditions'][] = array(
      'field' => "DATE_FORMAT(ADDTIME(FROM_UNIXTIME(webform_submissions.submitted), SEC_TO_TIME(-18000)), '%Y-%m-%d') >= :last_week AND DATE_FORMAT(ADDTIME(FROM_UNIXTIME(webform_submissions.submitted), SEC_TO_TIME(-18000)), '%Y-%m-%d') <= :today",
      'value' => array(
        ':last_week' => date('Y-m-d', strtotime($monday . ' days ago')),
        ':today' => date('Y-m-d'),
      ),
      'operator' => 'formula',
    );
  }

  unset($query->orderby[1]);
};


/**
 *  Friend's filter
 */
$filter['^(' . $settings['campaign_root'] . ')/friends$'] = function($match, &$view, &$query) {
  $facebook = create_and_share_load_fb();
  module_load_include('inc', 'fboauth', 'includes/fboauth.fboauth');

  global $user;

  if (!$user->uid) {
    drupal_goto('https://www.facebook.com/dialog/oauth?client_id=' . $settings['fb_app_id'] . '&redirect_uri=http://' . $settings['campaign_domain'] . '/fboauth/connect%3Fdestination%3D' . substr(request_uri(), 1) . '&scope=email,user_birthday');
  }

  $fbid = fboauth_fbid_load($user->uid);
  if (!empty($fbid)) {
    $friends = $facebook->api('/' . $fbid . '/friends');

    // Include yourself.
    $f = array(0 => $fbid,);
    foreach ($friends['data'] AS $key => $friend) {
      $f[] = $friend['id'];
    }
  }
  else {
    drupal_goto('https://www.facebook.com/dialog/oauth?client_id=' . $settings['fb_app_id'] . '&redirect_uri=http://' . $settings['campaign_domain'] . '/fboauth/connect%3Fdestination%3D' . substr(request_uri(), 1) . '&scope=email,user_birthday');
  }

  if (empty($ids)) {
    $ids = array($user->uid);
  }

  if (!empty($ids)) {
    // Create a database condition class to narrow viewable posts down to just your friends.
    $s = new DatabaseCondition();
    $s->condition('webform_submissions.uid', $ids);
    $c = &$s->conditions();
    $c['#conjunction'] = 'OR';

    // remove the view's filter criteria to be replaced by the new conditional.
    unset($query->where[1]['conditions'][1]);

    // Add the conditional to the query.
    $query->where[1]['conditions'][] = array(
      'field' => $s,
    );
  }
};

/**
 *  General settings -- Algorithm across all filters.
 */
$filter['^(' . $settings['campaign_root'] . ')'] = function($match, &$view, &$query, $settings) {
  // Make sure we're only viewing posts from this node.
  $node = menu_get_object();
  $query->where[1]['conditions'][] = array(
    'field' => 'node.nid',
    'value' => $node->nid,
    'operator' => '=',
  );

  $query->fields['real_weight'] = array(
    'field' => '((((webform_submissions.submitted - ' . REQUEST_TIME . ') + ' . $settings['algorithm']['grace_period'] . ') / ' . $settings['algorithm']['weight_divisor'] . ') + field_data_field_' . $settings['fields']['weight']['field'] . '.field_' . $settings['fields']['weight']['field'] . '_value)',
    'table' => '',
    'alias' => 'real_weight',
  );

  $query->orderby[0]['field'] = 'real_weight';
};
