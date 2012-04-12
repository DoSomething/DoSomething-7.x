<?php
/**
 * @file
 * Views area handlers.
 */

class dosomething_projects_general_handler_area_more_link extends views_handler_area_text {

  function option_definition() {
    return array();
  }

  function options_form(&$form, &$form_state) {
  }

  function options_validate($form, &$form_state) {
  }

  function render($empty = FALSE) {
    $output = '';
    $parents = taxonomy_get_parents($this->view->args[0]);
    if (empty($parents)) {
      return $output;
    }
    $term = reset($parents);
    $term_id = $term->tid;
    $output = "<a href='/resources?cause=" . $term_id . "' class='more-link-right'>More »</a>";
    return $output;
  }
}
