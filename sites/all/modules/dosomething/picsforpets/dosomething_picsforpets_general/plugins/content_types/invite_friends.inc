<?php

$plugin = array(
  'title' => t('Invite Friends'),
  'single' => TRUE,
  'category' => array(t('Facebook')),
  'render callback' => 'dosomething_picsforpets_general_content_type_render'
);

function dosomething_picsforpets_general_content_type_render($subtype, $conf, $context = NULL) {
  $block->content = '<div id="invite-friends">Invite Friends</div>';
  return $block;
}
