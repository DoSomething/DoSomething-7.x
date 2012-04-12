<?php

/**
 * Callback function for school counter.
 */
function dosomething_schools_school_counter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething School Counter'),
    'description' => t('School related statistics'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('School Entity'), 'entity:ds_school'),
  );
}

/**
 * Query and render school counter.
 */
function dosomething_schools_school_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $content = dosomething_schools_main_info($context->data->sid);

  $block->content = $content;

  return $block;

}
