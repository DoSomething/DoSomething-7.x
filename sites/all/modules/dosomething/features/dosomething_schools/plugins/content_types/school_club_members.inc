<?php

/**
 * Callback function for school club members.
 */
function dosomething_schools_school_club_members_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething School Club Members'),
    'description' => t('Mememers of a Club related to a School'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('School Entity'), 'entity:ds_school'),
  );
}

/**
 * Render club_members_per_school view.
 */
function dosomething_schools_school_club_members_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $gids = dosomething_schools_clubs_gids($context->data->sid);
  $view = views_get_view('club_members_per_school');
  $content = $view->preview('panel_pane_1', $gids);
  $block->title = t('Club Members');
  $block->content = $content;

  return $block;

}
