<?php


/**
 * Implementation of template_preprocess_page().
 */
function picsforpets_preprocess_page(&$variables) {
  if (arg(0) == 'pics-for-pets' && !arg(1)) {
    return;
  }
  else {
    $links[] = array(
      'title' => 'Gallery',
      'href' => 'pics-for-pets/gallery',
    );
    $links[] = array(
      'title' => 'Prizes',
      'href' => 'pics-for-pets/prizes',
    );
    $links[] = array(
      'title' => 'Be a Fur-tographer',
      'href' => 'pics-for-pets/furtographer',
    );
    $links[] = array(
      'title' => 'Questions',
      'href' => 'pics-for-pets/questions',
    );
    $variables['page']['footer'] = array(
      '#theme' => 'links',
      '#links' => $links,
    );
  }
}
