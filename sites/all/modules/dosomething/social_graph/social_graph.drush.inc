<?php

function social_graph_drush_command() {
  return array(
  	'graph-migrate-users' => array(
  	   'description' => 'Migrates users table into Graph Users table.',
  	),
  );
}

function drush_social_graph_graph_migrate_users() {
  $page = variable_get('gum', 1);
  $count = variable_get('gum_load_count', 15000);
  $done = variable_get('gum_done', 0);

  drush_print("Getting " . $count . " users, starting from " . $done . "...");

  $users = db_select('users', 'u')
    ->fields('u', array('uid', 'mail'));
  $users->leftJoin('fbconnect_users', 'f', 'f.uid = u.uid');
  $users->fields('f', array('fbuid'));
  $users->range($done, $count);
  $u = $users->execute()->fetchAll();

  $t = count($u);
  $i = 1;
  foreach ($u AS $key => $us) {
    if ($us->uid > 0) {
      $p = profile2_load_by_user($us, 'main');
      $first_name = $p->field_user_first_name[LANGUAGE_NONE][0]['value'];
      $last_name = $p->field_user_last_name[LANGUAGE_NONE][0]['value'];
      $mobile = $p->field_user_mobile[LANGUAGE_NONE][0]['value'];

      social_graph_add_user(array(
        'uid' => $us->uid,
        'fbid' => $us->fbuid,
        'email' => $us->mail,
        'cell' => $us->mobile,
        'first_name' => $first_name,
        'last_name' => $last_name,
        'created' => REQUEST_TIME,
        'ipaddress' => '',
        'inviter_guid' => 0,
        'extra' => '',
      ));

      drush_print("Finished {$i} of {$t}");
      $i++;
    }
  }

  $finished = $done + $count;
	drush_print("Finished " . $finished);
	variable_set('gum', ++$page);
  variable_set('gum_done', $finished);
}