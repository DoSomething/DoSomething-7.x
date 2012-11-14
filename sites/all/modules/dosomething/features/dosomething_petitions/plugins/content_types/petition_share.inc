<?php

function dosomething_petitions_petition_share_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Petition Sharing'),
    'description' => t('Petition share widget.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_petitions_petition_share_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object();

  $content = array();
  $content['getmore'] = array(
    '#markup' => t('Get more signatures on this petition:'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#weight' => -1
  );

  contact_scraper::add_scraper_button($content, 0, array('style' => 'display: inline-block'));
  if (preg_match('#\/petition\/put-end-to-bullying#i', request_uri())) {
    $content['invite_by_email'] = array(
      '#markup' => l(t('Share with email'), 'contact-scraper/' . $node->nid, array(
        'attributes' => array(
          'class' => array('invite-by-email-link'),
          'onclick' => 'return invite_find_emails(' . $node->nid . ')'
        ),
      )),
      '#prefix' => '<p id="invite-by-email">',
      '#suffix' => '</p>',
      '#weight' => 0,
    );
  }
  $content['or'] = array(
    '#prefix' => '<p style="position: relative;">',
    '#suffix' => '</p>',
    '#markup' => 'OR',
    '#attributes' => array(
      'style' => 'text-align: center; position: relative; top: -10px;'
    ),
    '#weight' => 1
  );

  $content['fb'] = array(
    '#markup' => l('Share on Facebook', '', array(
      'attributes' => array(
        'id' => 'petition-fb',
      ),
      'fragment' => ' ',
      'external' => TRUE,
    )),
    '#weight' => 10
  );

  $content['form'] = drupal_get_form('dosomething_petitions_email_form', $node->nid);

  /*$content['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'dosomething_petitions') . '/fb.js',
    ),
  );*/

  $block = new StdClass();
  $block->title = 'Share this Petition';
  $block->content = $content;
  return $block;
}

function dosomething_petitions_petition_share_content_type_admin_title($subtype, $conf, $context) {
  return t('Share petition');
}