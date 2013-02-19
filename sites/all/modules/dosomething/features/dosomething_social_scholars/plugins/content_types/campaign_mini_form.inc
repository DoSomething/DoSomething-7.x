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
  $node = menu_get_object();
  $block = new StdClass();

  $campaign = end($context)->data;
  $alias = drupal_get_path_alias('node/' . $campaign->nid);

  global $user;
  $mail = $mobile = '';
  if ($user->uid > 0) {
    $mail = $user->mail;
    $p = profile2_load_by_user($user, 'main');

    if (isset($p->field_user_mobile[LANGUAGE_NONE])) {
      $mobile = $p->field_user_mobile[LANGUAGE_NONE][0]['value'];
    }
  }

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

  $block->content = $content;
  return $block;
}