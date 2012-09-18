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
  $sid = db_query_range("SELECT sid FROM {webform_submissions} w LEFT JOIN {field_data_eq_webform_submission_entity} eq ON w.sid=eq.eq_webform_submission_entity_target_id AND eq.entity_id=(SELECT queue_id FROM {entityqueue} WHERE name='pics_for_pets_curated') WHERE w.bundle = :bundle AND w.nid = :nid ORDER BY eq.eq_webform_submission_entity_target_id DESC, RAND()", 0, 1,
    array(':bundle' => 'fb_app_data_gathering_form', ':nid' => $webform_id))->fetchField();

  // Build the markup for the link.
  $path = drupal_get_path_alias('node/' . $webform_id);
  $output = '<div class="picsforpets-scholarship">' . l('$5k Scholarship', $path . '/submission/' . $sid) . '</div>';
  $output .= '<div class="picsforpets-gallery">' . l('Take me to the paw-trait gallery', $path . '/submission/' . $sid) . '</div>';

  $block = new stdClass();
  $block->content = array(
    '#markup' => $output,
  );
  return $block;
}
