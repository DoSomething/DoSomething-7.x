<?php

/**
 * Callback function for school club members.
 */
function dosomething_schools_school_club_members_all_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething School Club Members - All'),
    'description' => t('Members of a Club related to a School'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('School Entity'), 'entity:ds_school'),
  );
}

/**
 * Render club_members_per_school view.
 */
function dosomething_schools_school_club_members_all_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $gids = dosomething_schools_clubs_gids($context->data->sid);
  $view = views_get_view('club_members_per_school');
  $block->title = t('Club Members');
  $block->content = $view->preview('panel_pane_1', array($gids));

  return $block;

}
