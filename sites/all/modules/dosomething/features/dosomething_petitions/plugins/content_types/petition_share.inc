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

  drupal_add_library('dosomething_contact_picker', 'contact_picker');

  $content['invite_by_email'] = array(
    '#markup' => l(t('Share with email'), 'contact-scraper/' . $node->nid, array(
      'attributes' => array(
        'class' => array('contact-picker'),
        'data-nid' => $node->nid,
      ),
    )),
    '#prefix' => '<p id="invite-by-email">',
    '#suffix' => '</p>',
    '#weight' => 0,
  );
  $content['or'] = array(
    '#prefix' => '<p class="or">',
    '#suffix' => '</p>',
    '#markup' => 'OR',
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


  $content['twitter_or'] = array(
    '#prefix' => '<p class="or">',
    '#suffix' => '</p>',
    '#markup' => 'OR',
    '#weight' => 15,
  );

  $content['twitter'] = array(
    '#markup' => l('Share on Twitter', '', array(
      'attributes' => array(
        'id' => 'petition-twitter',
      ),
      'fragment' => ' ',
      'external' => TRUE,
    )),
    '#weight' => 20
  );

  $block = new StdClass();
  $block->title = 'Share this Petition';
  $block->content = $content;
  return $block;
}

function dosomething_petitions_petition_share_content_type_admin_title($subtype, $conf, $context) {
  return t('Share petition');
}
