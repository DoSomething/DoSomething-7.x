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
      'href' => 'pics-for-pets/become-a-furtographer',
      'attributes' => array('class' => array('footer-furtography', 'pics-for-pets-modal')),
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
    $variables['page']['footer']['picsforpets_modal'] = array(
      '#markup' => '<div id="picsforpets-modal-data"></div>',
      '#attached' => array(
        'library' => array(array('system', 'ui.dialog')),
        'js' => array(
          drupal_get_path('module', 'dosomething_picsforpets_general') . '/js/dosomething-picsforpets-dialog.js',
        ),
      ),
    );
  }
}

/**
 * Override of theme_field_multiple_value_form().
 */
function picsforpets_field_multiple_value_form($variables) {

  if ($variables['element']['#field_name'] !== 'field_fb_app_three_words') {
    return theme_field_multiple_value_form($variables);
  }

  // Output multivalue field form without draggable weights.
  $element = $variables['element'];
  $output = '';

  if ($element['#cardinality'] > 1 || $element['#cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
    $table_id = drupal_html_id($element['#field_name'] . '_values');
    $order_class = $element['#field_name'] . '-delta-order';
    $required = !empty($element['#required']) ? theme('form_required_marker', $variables) : '';

    $header = array(
      array(
        'data' => '<label>' . t('!title: !required', array('!title' => $element['#title'], '!required' => $required)) . "</label>",
        'colspan' => 2,
        'class' => array('field-label'),
      ),
    );
    $rows = array();

    // Sort items according to '_weight' (needed when the form comes back after
    // preview or failed validation)
    $items = array();
    foreach (element_children($element) as $key) {
      if ($key === 'add_more') {
        $add_more_button = &$element[$key];
      }
      else {
        $items[] = &$element[$key];
      }
    }
    usort($items, '_field_sort_items_value_helper');

    // Add the items as table rows.
    foreach ($items as $key => $item) {
      $item['_weight']['#attributes']['class'] = array($order_class);
      $delta_element = drupal_render($item['_weight']);
      $cells = array(
        drupal_render($item),
      );
      $rows[] = array(
        'data' => $cells,
      );
    }

    $output = '<div class="form-item">';
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => $table_id, 'class' => array('field-multiple-table'))));
    $output .= $element['#description'] ? '<div class="description">' . $element['#description'] . '</div>' : '';
    $output .= '<div class="clearfix">' . drupal_render($add_more_button) . '</div>';
    $output .= '</div>';
  }
  else {
    foreach (element_children($element) as $key) {
      $output .= drupal_render($element[$key]);
    }
  }

  return $output;
}
