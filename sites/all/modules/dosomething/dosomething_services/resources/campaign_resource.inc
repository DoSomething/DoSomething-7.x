<?php
/**
 * @file
 * Web service resource for DoSomething.org campaigns.
 */

function _campaign_resource_definition() {
  $definition = array(
    'campaign_signup' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieve whether or not a user is signed up for a campaign.',
          'file' => array('type' => 'inc', 'module' => 'dosomething_services', 'name' => 'resources/campaign_resource'),
          'callback' => '_campaign_signup_retrieve',
          'access callback' => '_campaign_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'nid',
              'type' => 'int',
              'description' => 'The node ID of the campaign.',
              'source' => array('path' => 0),
              'optional' => FALSE,
            ),
            array(
              'name' => 'uid',
              'type' => 'int',
              'description' => 'The user ID to check for signup info.',
              'source' => array('param' => 'uid'),
              'optional' => FALSE,
            ),
          ),
        ),
        'create' => array(
          'file' => array('type' => 'inc', 'module' => 'dosomething_services', 'name' => 'resources/campaign_resource'),
          'callback' => '_campaign_signup_create',
          'access callback' => '_campaign_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'nid',
              'type' => 'int',
              'description' => 'Node ID of the campaign to submit a sign up for.',
              'source' => array('data' => 'nid'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'uid',
              'type' => 'int',
              'description' => 'User ID of the user submitting a sign up.',
              'source' => array('data' => 'uid'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'data',
              'type' => 'array',
              'description' => 'Array of supplementary sign up data.',
              'source' => array('data' => 'data'),
              'optional' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  return $definition;
}

/**
 * Access check callback for the campaign resource.
 */
function _campaign_resource_access($op = 'view', $args = array()) {
  $account = user_load($args[1]);

  if ($op == 'view') {
    return user_view_access($account);
  }
  elseif ($op == 'create') {
    $nid = $args[0];
    $node = node_load($nid);
    if (!$node) {
      return services_error(t('The node @nid does not exist.', array('@nid' => $nid)), 406);
    }

    // Checking 'view' access because we're just creating a sign up submission for that node
    return node_access('view', $node);
  }
}

/**
 * Find out if a given user has signed up for a given campaign.
 *
 * @param int $nid
 *   Node ID of the campaign to check.
 * @param int $uid
 *   User ID to search for.
 */
function _campaign_signup_retrieve($nid, $uid) {
  $signed_up = dosomething_signups_is_user_signed_up($uid, $nid);

  $return = new stdClass();
  $return->signed_up = $signed_up;

  return $return;
}

/**
 * Create a user sign up for a given campaign.
 *
 * @param int $nid
 *   Node ID of the campaign to sign up for.
 * @param int $uid
 *   User ID to sign up.
 * @param array $data
 *   Supplementary data for the campaign sign up.
 */
function _campaign_signup_create($nid, $uid, $data) {
  $addl_data = NULL;
  if (is_array($data) && isset($data['data'])) {
    $addl_data = $data['data'];
  }

  // Create the initial sign up
  if (!dosomething_signups_is_user_signed_up($uid, $nid)) {
    dosomething_signups_insert_signup($uid, $nid, $addl_data);
  }
  // Or update an already existing one
  else {
    dosomething_signups_update_signup_data($uid, $nid, $addl_data);
  }

  // Add additional address data, if any
  if (is_array($data)) {
    $addr_data = array();
    $addr_data['uid'] = $uid;
    $addr_data['nid'] = $nid;
    $addr_data['address1'] = isset($data['address1']) ? $data['address1'] : '';
    $addr_data['address2'] = isset($data['address2']) ? $data['address2'] : '';
    $addr_data['city'] = isset($data['city']) ? $data['city'] : '';
    $addr_data['state'] = isset($data['state']) ? $data['state'] : '';
    $addr_data['zip'] = isset($data['zip']) ? $data['zip'] : '';
    $addr_data['name'] = isset($data['name']) ? $data['name'] : '';
    $addr_data['email'] = isset($data['email']) ? $data['email'] : '';

    dosomething_campaign_submit_signup_address($addr_data);
  }

  $return = new stdClass();
  $return->signed_up = TRUE;

  return $return;
}
