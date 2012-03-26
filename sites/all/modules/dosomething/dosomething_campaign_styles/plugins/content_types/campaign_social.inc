<?php

function dosomething_campaign_styles_campaign_social_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Campaign Sharing'),
    'description' => t('Like, Tweet, G+ buttons for Campaigns'),
    'category' => t('DoSomething'),
  );
}

function dosomething_campaign_styles_campaign_social_content_type_render($subtype, $conf, $panel_args, $context) {
  if ($context = og_context()) {
    $block = new stdClass();
    $entity = array_shift(entity_load($context->entity_type, array($context->etid)));
    if (isset($entity->field_campaign_facebook_language) && isset($entity->field_campaign_twitter_language)) {
      $uri = entity_uri($context->entity_type, $entity);
      $uri['options']['absolute'] = true;

      drupal_add_css(drupal_get_path('module', 'dosomething_campaign_styles') . '/css/ds_campaign_social.css');
      $block->content = theme('ds_campaign_social', array(
        'url' => url($uri['path'], $uri['options']),
        'facebook_language' => $entity->field_campaign_facebook_language[LANGUAGE_NONE][0]['value'],
        'twitter_language' => $entity->field_campaign_twitter_language[LANGUAGE_NONE][0]['value'],
      ));

      return $block;
    }
  }
}

function dosomething_campaign_styles_campaign_social_content_type_admin_title($subtype, $conf, $context) {
  return t('Campaign Like Buttons');
}
