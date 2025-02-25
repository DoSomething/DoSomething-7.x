<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Robocalls celebrity flag'),
  'description' => t('Display a particular connection based off of tags.'),
  'all contexts' => TRUE,
  'category' => t('DoSomething'),
  'defaults' => '',
  'render callback' => 'robocalls_flag_render'
);

function robocalls_flag_render($subtype, $conf, $panel_args, $context) {
   $flag = $context['argument_term_1']->data->field_short_name[LANGUAGE_NONE][0]['value'];
   $block = new stdClass();
   $block->content = '<div class="main-robocall-flag' . ($flag == 'Birthday' ? ' birthday' : '') . '">' . $flag . '</div>';
   return $block;
}
