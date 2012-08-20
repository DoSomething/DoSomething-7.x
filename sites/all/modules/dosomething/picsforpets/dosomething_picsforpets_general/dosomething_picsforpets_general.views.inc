<?php

/**
 * Implements hook_views_data().
 */
function dosomething_picsforpets_general_views_data() {
  $data = array();
  $data['picsforpets_user_shares']['table']['group'] = t('Picsforpets Shares');
  $data['picsforpets_user_shares']['table']['base'] = array(
    'field' => 'fb_user_id',
    'title' => t('Picsforpets Shares'),
    'help' => t("Contains number of facebook shares by fb user uid."),
    'weight' => -10,
  );
  $data['picsforpets_user_shares']['table']['join'] = array(
    'fboauth_users' => array(
      'left_field' => 'fbid',
      'field' => 'uid',
    ),
  );


  $data['picsforpets_user_shares']['entity_id'] = array(
    'title' => t('Entity id'),
    'help' => t('The id of the entity being shared.'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  return $data;
}

