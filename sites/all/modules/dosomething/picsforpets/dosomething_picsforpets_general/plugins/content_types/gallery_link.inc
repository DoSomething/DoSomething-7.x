<?php

$plugin = array(
  'title' => t('Gallery link'),
  'single' => TRUE,
  'category' => array(t('Picsforpets')),
  'render callback' => 'dosomething_picsforpets_general_content_type_gallery_link'
);


function dosomething_picsforpets_general_content_type_gallery_link($subtype = '', $conf = array(), $context = NULL) {

  // Select a random submission from the database.
  $webform_id = variable_get('picsforpets_animal_form_id', NULL);
  $sid = db_query_range('SELECT sid FROM {webform_submissions} WHERE bundle = :bundle AND nid = :nid ORDER BY RAND()', 0, 1,
    array(':bundle' => 'fb_app_data_gathering_form', ':nid' => $webform_id))->fetchField();

  // Build the markup for the link.
  $output = '<div class="picsforpets-scholarship"><a href="/pics-for-pets/gallery">' . t('$5k Scholarship') . '</a></div>';
  $path = drupal_get_path_alias('node/' . $webform_id);
  $output .= '<div class="picsforpets-gallery"><a href="/' . $path . '/submission/' . $sid . '">' . t('Take me to the paw-trait gallery') . '</a></div>';

  $block = new stdClass();
  $block->content = array(
    '#markup' => $output,
  );
  return $block;
}
