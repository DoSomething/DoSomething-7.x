<?php

function dosomething_drives_drive_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Drive Module'),
    'description' => t('Drive information module.'),
    'category' => t('DoSomething'),
  );
}

function dosomething_drives_drive_content_type_render($subtype, $conf, $panel_args, $context) {
  $content = array();
  $content['header'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-header'),
    ),
  );
  $content['header']['title'] = dosomething_drives_drive_title();
  $content['header']['description'] = dosomething_drives_drive_description();
  $content['header']['countdown'] = dosomething_drives_drive_countdown();

  $content['content']['drive_info'] = dosomething_drives_drive_info();
  $content['content']['drive_share'] = dosomething_drives_drive_share();
  $content['content']['participants'] = dosomething_drives_drive_participants();

  $block = new StdClass();
  $block->content = $content;
  return $block;
}

function dosomething_drives_drive_content_type_admin_title($subtype, $conf, $context) {
  return t('Drive Module');
}

function dosomething_drives_drive_info() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-info'),
    ),
  ) + dosomething_drives_drive_get_info();
}

function dosomething_drives_drive_get_info() {
  return array(
    'header' => array(
      '#markup' => '<h3>Logistics</h3>',
    ),
    'details' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('drive-info-info-details'),
      ),
      'when' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('drive-info-when'),
        ),
        'div' => array(
          '#markup' => 'When: DATE',
        ),
      ),
      'where' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('drive-info-where'),
        ),
        'div' => array(
          '#markup' => 'Where: 19 W 21st St, 11215',
        ),
      ),
    ),
  );
}

function dosomething_drives_drive_share() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-share'),
    ),
    'div' => array(
      '#markup' => 'Share my drive and stuff',
    ),
  );
}

function dosomething_drives_drive_participants() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-participants'),
    ),
    'title' => array(
      '#markup' => 'Participants',
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    ),
    'list' => array(
      '#theme' => 'item_list',
      '#items' => array('Chris J.', 'Barry C.'),
      '#attributes' => array(
        'class' => array('drive-participants-list'),
      ),
    ),
    'action_link' => dosomething_drives_drive_action_link(),
  );
}

function dosomething_drives_drive_countdown() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-countdown'),
    ),
    'div' => array(
      '#markup' => 'Countdown: 1 day, 3 hours, 21 minues',
    ),
  );
}

function dosomething_drives_drive_title() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-title'),
    ),
    'div' => array(
      '#markup' => "Barry's Drive",
    ),
  );
}

function dosomething_drives_drive_description() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('drive-info-description'),
    ),
    'div' => array(
      '#markup' => 'Goal: 1000 bananas',
    ),
  );
}

function dosomething_drives_drive_action_link() {
  return array(
    '#markup' => l('Join Barry\'s Drive', 'http://www.cnn.com', array('attributes' => array('class' => array('go-button')))),
  );
}
