<?php

$plugin = array(
  'title' => t('Gallery link'),
  'single' => TRUE,
  'category' => array(t('Picsforpets')),
  'render callback' => 'dosomething_picsforpets_general_content_type_gallery_link'
);


function dosomething_picsforpets_general_content_type_gallery_link($subtype = '', $conf = array(), $context = NULL) {

  // Select a random submission from the database.
  $sid = db_query('SELECT entity_id FROM field_data_field_fb_app_share_count ORDER BY RAND() LIMIT 1')->fetchField();

  // Build the markup for the link.
  $output = '<div class="picsforpets-scholarship"><a href="/pics-for-pets/gallery">' . t('$5k Scholarship') . '</a></div>';
  $output .= '<div class="picsforpets-gallery"><a href="/webform-submission/' . $sid . '">' . t('Take me to the paw-trait gallery') . '</a></div>';

  $block = new stdClass();
  $block->content = array(
    '#markup' => $output,
  );
  return $block;
}
