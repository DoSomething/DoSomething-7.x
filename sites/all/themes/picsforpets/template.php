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
      'attributes' => array('class' => array('footer-gallery')),
    );
    $links[] = array(
      'title' => 'Prizes',
      'href' => 'pics-for-pets/prizes',
      'attributes' => array('class' => array('footer-prizes')),
    );
    $links[] = array(
      'title' => 'Be a Fur-tographer',
      'href' => 'pics-for-pets/furtographer',
      'attributes' => array('class' => array('footer-furtography')),
    );
    $links[] = array(
      'title' => 'Questions',
      'href' => 'pics-for-pets/questions',
      'attributes' => array('class' => array('footer-questions')),
    );
    $variables['page']['footer']['picsforpets_menu'] = array(
      '#theme' => 'links',
      '#links' => $links,
      '#attributes' => array('class' => array('picsforpets-menu')),
    );
    $variables['page']['footer']['picsforpets_furtographer'] = drupal_get_form('dosomething_picsforpets_furtographer_dialog');
  }
}
