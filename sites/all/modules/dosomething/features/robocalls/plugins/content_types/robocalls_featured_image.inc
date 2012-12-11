<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Robocalls Featured Celeb Image'),
  'description' => t('Displays the image for the featured celebrity.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'robocalls_featured_celeb_image'
);

function robocalls_featured_celeb_image($subtype, $conf, $panel_args, $context) {
   $f = db_query("SELECT entity_id FROM field_data_field_celeb_featured_celebrity WHERE field_celeb_featured_celebrity_value = 1 LIMIT 1");
   $f = reset($f->fetchAll());

   $t = taxonomy_term_load($f->entity_id);
   $output = theme('image', array('path' => $t->field_celeb_photo[LANGUAGE_NONE][0]['uri'], 'height' => '317px', 'width' => '210px'));

   $block = new stdClass();
   $block->content = $output;
   return $block;
}
