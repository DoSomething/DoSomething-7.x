<?php

function dosomething_campaign_styles_campaign_sign_up_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Campaign Sign-up/Report-Back'),
    'description' => t('Campaign Sign-up/Report back auto-switching widget'),
    'category' => t('DoSomething'),
  );
}

function dosomething_campaign_styles_campaign_sign_up_content_type_render($subtype, $conf, $panel_args, $context) {
  if ($context = og_context()) {
    global $user;

    $query = new EntityFieldQuery;
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', array('campaign_contact_form', 'campaign_sign_up', 'campaign_report_back'), 'IN')
      ->fieldCondition('group_audience', 'gid', $context->gid, '=')
      ->execute();

    // create up to three variables with names from the propertyCondition above ($campaign_contact_form, $campaign_sign_up, $campaign_report_back)
    foreach ($result['node'] as $res) {
      ${$res->type} = $res->nid;
    }

    // load up the campaign node
    $campaign_entity = array_shift(entity_load($context->entity_type, array($context->etid)));

    // populate the block with the webform block form
    $block = (object)module_invoke('webform', 'block_view', 'client-block-'.$campaign_contact_form);

    // if the campaign field label_pre_sign is filled out, make it the title of this block
    if (isset($campaign_entity->field_label_pre_sign[LANGUAGE_NONE][0]['value'])) {
      $block->title = $campaign_entity->field_label_pre_sign[LANGUAGE_NONE][0]['value'];
    }

    if (user_is_logged_in()) {
      // get the sign ups of this user if any exist
      $query = new EntityFieldQuery;
      $sign_ups = $query
        ->entityCondition('entity_type', 'webform_submission_entity')
        ->propertyCondition('uid', $user->uid)
        ->propertyCondition('nid', $campaign_sign_up)
        ->execute();

      // if the user has filled out a sign-up form, replace the block with the html from the campaign node
      if (!empty($sign_ups)) {
        $block = new stdClass();
        $block->content = $campaign_entity->field_report_back_html[LANGUAGE_NONE][0]['value'];
        if (isset($campaign_entity->field_label_post_sign[LANGUAGE_NONE][0]['value'])) {
          $block->title = $campaign_entity->field_label_post_sign[LANGUAGE_NONE][0]['value'];
        }
      }

    }
    // if the block is empty, return nothing so it doesn't get rendered
    if (empty($block->content)) {
      return;
      //$block->content = 'There was a problem loading the sign up form for this campaign. Please email help@dosomething.org if you see this message.';
    }

    return $block;
  }
}

function dosomething_campaign_styles_campaign_sign_up_content_type_admin_title($subtype, $conf, $context) {
  return t('Campaign Sign-Up');
}

function dosomething_campaign_styles_campaign_sign_up_content_type_edit_form($form, &$form_state) {
  return $form;
}

/*
function dosomething_campaign_styles_campaign_sign_up_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('pre_sign_up', 'post_sign_up') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
 */
