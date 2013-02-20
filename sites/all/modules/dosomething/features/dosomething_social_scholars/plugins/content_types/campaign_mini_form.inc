<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Share a Stat Campaign Shortform'),
  'description' => t('Displays the shortform for a selected campaign on Share a Stat.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'dosomething_social_scholars_sas_campaign_shortform_content_type_render'
);

function dosomething_social_scholars_sas_campaign_shortform_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new StdClass();

  // Get the campaign in question.
  $campaign = end($context)->data;

  // Get user information, if possible.
  global $user;
  $mail = $mobile = '';
  if ($user->uid > 0) {
    $mail = $user->mail;
    $p = profile2_load_by_user($user, 'main');

    if (isset($p->field_user_mobile[LANGUAGE_NONE])) {
      $mobile = $p->field_user_mobile[LANGUAGE_NONE][0]['value'];
    }
  }

  // Get the group ID for the campaign in question.
  $gid = og_get_group('node', $campaign->nid)->gid;

  // Get the node ID for the campaign short form...for the campaign in question.
  $sf = db_select('field_data_group_audience', 'ga')
    ->fields('ga', array('entity_id'))
    ->condition('entity_type', 'node')
    ->condition('bundle', 'campaign_contact_form')
    ->condition('group_audience_gid', $gid)
    ->range(0, 1)
    ->execute();
  $short_form = reset($sf->fetchAll());

  // Try and get the alias for the campaign short form.
  $alias = drupal_get_path_alias('node/' . $short_form->entity_id);

  // Styling information.
  $campaign_nid = $campaign->nid;
  require_once drupal_get_path('module', 'dosomething_social_scholars') . '/style_config.php';

  if (!empty($campaign_styles[$campaign_nid])) {
    $s = $campaign_styles[$campaign_nid]['shortform'];
    $css = '
      .dosomething-share-a-stat-campaign-short-form .webform-client-form {
        background: ' . $s['background'] . ' !important;
        color: ' . $s['font_color'] . ' !important;
      }

      .webform-client-form h3 {
        color: ' . $s['font_color'] . ' !important;
      }
    ';
    drupal_add_css($css, array(
      'type' => 'inline',
      'group' => CSS_THEME,
      'weight' => 10000,
    ));
  }

  // Build the container.
  $content['shortform'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'dosomething-share-a-stat-campaign-short-form'
      )
    ),
    'campaign-short-form' => array(
      '#markup' => theme('sas-campaign-short-form', array(
        'alias' => $alias,
        'nid' => $campaign->nid,
        'email' => $mail,
        'mobile' => $mobile,
      )),
    ),
  );

  // Set the block content and return it
  $block->content = $content;
  return $block;
}