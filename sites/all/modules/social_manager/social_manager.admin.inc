<?php

function social_manager_add_form($form, &$form_state) {
  if (!isset($form_state)) {
    $step = 1;
  }
  else {
    $step = $form_state['input']['step'] + 1;
  }

  $form['step'] = array(
    '#type' => 'hidden',
    '#value' => $step,
  );

  switch ($step) {
    case 1:
      $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#description' => t('A descriptive tag to denote this action.'),
        '#attributes' => array('placeholder' => t('Title')),
      );

      $form['pages'] = array(
        '#type' => 'textarea',
        '#title' => t('Pages'),
        '#description' => t('What pages should this action apply on? Please specify one per line. Use * as the wildcard character.  Example: blog/* matches blog/, blog/7-facts-about-kittens, etc.'),
        '#attributes' => array('placeholder' => t('Effective pages.  One per line.')),
      );

      $form['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => t('This action is enabled.'),
        '#default_value' => 1,
      );

      $form['action'] = array(
        '#type' => 'select',
        '#title' => t('Action to perform'),
        '#description' => t('What action should be performed on the specified page(s)?'),
        '#options' => array(0 => t('Select an action...')) + social_manager_get_services(),
      );
    break;
    case 2:
      $action = explode(':', $form_state['input']['action']);
      $form += social_manager_load_action($action[0], $action[1]);
    break;
  }

  $form['#multistep'] = TRUE;
  $form['#redirect'] = FALSE;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => ($step == 1) ? t('Continue') : t('Submit'),
  );

  $form['#submit'][] = 'social_manager_add_submit';
  return $form;
}

function social_manager_load_action($service, $action, array $data = array()) {
  module_load_include('inc', 'social_manager', 'services/' . $service);
  $class = ucfirst($service) . "Service";
  $method = "{$action}Action";

  $form = array();
  $class::$method($form, $data);

  return $form;
}

function social_manager_add_submit($form, &$form_state) {
  $values = &$form_state['input'];
  if ($values['step'] == 1) {
    $form_state['multistep_values'][$values['step']] = $values;
    $form_state['step'] = 2;
  }
  else {
    $form_state['multistep_values'][$values['step']] = $values;
    $form_state['complete'] = TRUE;

    $mvals = $form_state['multistep_values'];
    $service = explode(':', $mvals[1]['action']);

    // Remove actual form tokens.
    $bad = array('step', 'op', 'form_build_id', 'form_token', 'form_id');
    foreach ($bad AS $nono) {
      unset($mvals[2][$nono]);
    }

    $record = array(
      'title' => $mvals[1]['title'],  // Machine name of the action
      'service' => $service[0],       // The service that the action will be run against.
      'type' => $service[1],          // The action type within that service.
      'paths' => $mvals[1]['pages'],  // The path(s) that the action will trigger on.
      'data' => serialize($mvals[2]), // Serialized array of data to store.
      'settings' => 1,                // The state of the action (whether or not it's enabled).
    );
    drupal_write_record('social_actions', $record);
    social_manager_reload_cache();

    drupal_set_message(t('New action successfully added.'));
    drupal_goto('admin/structure/social');
  }

  if (isset($form_state['multistep_values']['form_build_id'])) {
    $values['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }
  $form_state['multistep_values']['form_build_id'] = $values['form_build_id'];
  $form_state['rebuild'] = TRUE;
}

function social_manager_add() {
  $content = 'hi';
  $content .= drupal_render(drupal_get_form('social_manager_add_form'));
  return $content;
}

function social_manager_manage_list() {
  $actions = db_select('social_actions', 'a')
    ->fields('a', array('aid', 'title', 'service', 'type', 'paths', 'settings'))
    ->execute()
    ->fetchAll();

  $headers = array('#', 'Title', 'Service', 'Action', 'Path(s)', 'Enabled', 'Actions');
  $rows = array();
  foreach ($actions AS $key => $row) {
    module_load_include('inc', 'social_manager', 'services/' . $row->service);
    $class = ucfirst($row->service) . 'Service';

    $r = array(
      'data' => array(
        l($row->aid, 'admin/structure/social/edit/' . $row->aid),
        l(t($row->title), 'admin/structure/social/edit/' . $row->aid),
        $class::$title,
        $class::$actions[$row->type],
        implode(', ', explode("\r\n", $row->paths)),
        ($row->settings & 1) ? t('Yes') : t('No'),
      ),
    );

    $operations = array(
      array(
        'title' => t('Edit'),
        'href' => 'admin/structure/social/edit/' . $row->aid,
      ),
      array(
        'title' => t('Delete'),
        'href' => 'admin/structure/social/delete/' . $row->aid,
        'query' => array('token' => drupal_get_token('delete_' . $row->aid))
      ),
    );

    if ($row->settings & 1) {
      $operations[] = array(
        'title' => t('Disable'),
        'href' => 'admin/structure/social/disable/' . $row->aid,
        'query' => array('token' => drupal_get_token('disable_' . $row->aid)),
      );
    }
    else {
      $operations[] = array(
        'title' => t('Enable'),
        'href' => 'admin/structure/social/enable/' . $row->aid,
        'query' => array('token' => drupal_get_token('enable_' . $row->aid)),
      );
    }

    $ops = theme('links__ctools_dropbutton', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))));

    $r['data'][] = array('data' => $ops, 'class' => array('page-manager-page-operations'));
    $rows[] = $r;
  }

  $content = l(t('+ Add New Action'), 'admin/structure/social/add');
  $content .= theme('table', array('header' => $headers, 'rows' => $rows));
  return $content;
}

function social_manager_edit_form($form, $form_state, $aid) {
  $action = db_select('social_actions', 'a')
    ->fields('a')
    ->condition('aid', $aid, '=')
    ->execute()
    ->fetchAll();
  $action = reset($action);

  $form['aid'] = array(
    '#type' => 'hidden',
    '#value' => $aid,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('A descriptive tag to denote this action.'),
    '#attributes' => array('placeholder' => t('Title')),
    '#default_value' => check_plain($action->title),
  );

  $form['pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#description' => t('What pages should this action apply on? Please specify one per line. Use * as the wildcard character.  Example: blog/* matches blog/, blog/7-facts-about-kittens, etc.'),
    '#attributes' => array('placeholder' => t('Effective pages.  One per line.')),
    '#default_value' => check_plain($action->paths),
  );

  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('This action is enabled.'),
    '#default_value' => !empty($action->settings) && ($action->settings & 1), 
  );

  $form['action'] = array(
    '#type' => 'select',
    '#title' => t('Action to perform'),
    '#description' => t('What action should be performed on the specified page(s)?'),
    '#options' => array(0 => t('Select an action...')) + social_manager_get_services(),
    '#default_value' => $action->service . ':' . $action->type,
    '#disabled' => TRUE,
  );

  $form['action_value'] = array(
    '#type' => 'hidden',
    '#default_value' => $action->service . ':' . $action->type,
  );

  $action->data = unserialize($action->data);
  $form += social_manager_load_action($action->service, $action->type, $action->data);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
  );

  $form['#submit'][] = 'social_manager_edit_submit';
  return $form;
}

function social_manage_edit($id) {
  $content .= drupal_render(drupal_get_form('social_manager_edit_form', $id));
  return $content;
}

function social_manager_edit_submit($form, &$form_state) {
  $values = $form_state['input'];
  $values['enabled'] = (!empty($values['enabled']) ? 1 : 0);

  $data = $values;
  $bad = array('aid', 'action_value', 'title', 'pages', 'enabled', 'op', 'form_build_id', 'form_token', 'form_id');
  foreach ($bad AS $nono) {
    unset($data[$nono]);
  }

  $action = explode(':', $values['action_value']);
  $class = ucfirst($action[0]) . 'Service';
  $method = $action[1] . 'Submit';

  if (method_exists($class, $method)) {
    $class::$method($values);
  }

  db_update('social_actions')
    ->fields(array(
      'title' => $values['title'],
      'paths' => $values['pages'],
      'data' => serialize($data),
      'settings' => $values['enabled'],
    ))
    ->condition('aid', $values['aid'])
    ->execute();

  social_manager_reload_cache();

  drupal_set_message(t('Changes saved.'));
  drupal_goto('admin/structure/social');
}

function social_manager_get_services() {
  $files = scandir(drupal_get_path('module', 'social_manager') . '/services');
  
  $options = array();
  foreach ($files AS $file) {
    if ($file != '.' && $file != '..') {
      include_once drupal_get_path('module', 'social_manager') . '/services/' . $file;
      $service = ucfirst(str_replace('.inc', '', $file));
      $method = "{$service}Service";

      $actions = $method::getActions();

      // @todo find a better way to do this.
      $replaceable = array_flip($actions['actions']);
      array_walk($replaceable, function(&$val) use ($actions) {
        $val = strtolower($actions['title']) . ':' . $val;
      });
      $replaceable = array_flip($replaceable);

      $options[$actions['title']] = $replaceable;
    }
  }

  return $options;
}

function social_manager_enable_disable($state, $id) {
  if ($state == 'enable') $setting = 1;
  elseif ($state == 'disable') $setting = 0;

  db_update('social_actions')
    ->fields(array(
      'settings' => $setting
    ))
    ->condition('aid', $id)
    ->execute();

  social_manager_reload_cache();
  drupal_set_message(t('Action with ID #!id successfully !stated', array('!id' => $id, '!state' => $state)));
  drupal_goto('admin/structure/social');
}