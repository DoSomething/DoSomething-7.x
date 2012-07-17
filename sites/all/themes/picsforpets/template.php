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

/**
 * Implements hook_ctools_render_alter().
 *
 * This hook gives us access to the panel itself, not just one pane.
 */
function picsforpets_ctools_render_alter(&$info, &$page, &$context) {
  if (!$page || (isset($context['task']['task type']) && $context['task']['task type'] != 'page')) {
    return;
  }

  // If this is a custom page, the name is the machine name, and is stored as
  // the name of the subtask. If it is a system page like node/%node, the name
  // is stored as the name of the handler. These names are global, not per-page.
  // Unless it is customized upon export, it will be in the form of
  // NAME_panel_context_DELTA, for example, node_view_panel_context_3.
  $name = isset($context['subtask']['name']) ? $context['subtask']['name'] : $context['handler']->name;

  switch ($name) {
    case 'webform_submission_view_pet_profile':
      drupal_add_js(drupal_get_path('module', 'dosomething_picsforpets_animals') . '/js/picsforpets-carousel.js');
      drupal_add_js(array('picsforpetsAnimals' => array('sid' => $context['args'][0]->sid)), 'setting');
      // Total number of available pet submissions.
      // TODO: limit to correct node results.
      $total = db_query("SELECT COUNT(sid) FROM webform_submissions")->fetchField();
      drupal_add_js(array('picsforpetsAnimals' => array('total' => $total)), 'setting');
    break;
  }
}
