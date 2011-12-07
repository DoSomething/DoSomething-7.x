<?php

function dosomething_causes_views_data() {
  $data = array();
  $data['taxonomy_term_data']['dosomething_causes_term_node_tid'] = array(
    'title' => t('Has taxonomy term ID, parent, child, or sibling term ID '),
    'help' => t('Display content if it has the selected taxonomy terms, sibling terms, or children of the selected terms.'),
    'real field' => 'tid',
    'argument' => array(
      'handler' => 'dosomething_causes_views_handler_argument_term_node_tid',
      'name field' => 'name',
      'accept depth modifier' => TRUE,
    ),
  );
  return $data;
}

/*
 * Break x,y,z and x+y+z. and x, y, z into an array. Numeric only.
 * This is an alternate version of views_break_phrase() to allow comma-space style input
 * and to treat all inputs as an OR.
 *
 * @param $str
 *   The string to parse.
 * @param $handler
 *   The handler object to use as a base. If not specified one will
 *   be created.
 *
 * @return $handler
 *   The new handler object.
 */
function dosomething_causes_views_break_phrase($str, &$handler = NULL) {
  if (!$handler) {
    $handler = new stdClass();
  }

  // Set up defaults:

  if (!isset($handler->value)) {
    $handler->value = array();
  }

  $handler->operator = 'or';

  if (empty($str)) {
    return $handler;
  }

  if (preg_match('/^([0-9]+[+ ])+[0-9]+$/', $str)) {
    // The '+' character in a query string may be parsed as ' '.
    $handler->value = preg_split('/[+ ]/', $str);
  }
  elseif (preg_match('/^([0-9]+,)*[0-9]+$/', $str)) {
    $handler->value = explode(',', $str);
  }
  elseif (preg_match('/^([0-9]+, )*[0-9]+$/', $str)) {
    $handler->value = explode(', ', $str);
  }
  

  // Keep an 'error' value if invalid strings were given.
  if (!empty($str) && (empty($handler->value) || !is_array($handler->value))) {
    $handler->value = array(-1);
    return $handler;
  }

  // Doubly ensure that all values are numeric only.
  foreach ($handler->value as $id => $value) {
    $handler->value[$id] = intval($value);
  }

  return $handler;
}