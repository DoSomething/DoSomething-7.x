<?php

/**
 * Callback function for school Done It.
 */
function dosomething_schools_school_done_it_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething School Done It'),
    'description' => t('School related Done It'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('School Entity'), 'entity:ds_school'),
  );
}

/**
 * Query and render school counter.
 */
function dosomething_schools_school_done_it_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $elements = dosomething_schools_done_it_display($context->data->sid, FALSE);

  $block->content = drupal_render($elements);
  $block->title = t('Done It');

  return $block;

}
