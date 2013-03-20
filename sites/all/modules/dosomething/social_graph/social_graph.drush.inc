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
	$count = variable_get('gum_load_count', 25000);
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
         $u[$key]->first_name = $p->field_user_first_name[LANGUAGE_NONE][0]['value'];
         $u[$key]->last_name = $p->field_user_last_name[LANGUAGE_NONE][0]['value'];
         $u[$key]->mobile = $p->field_user_mobile[LANGUAGE_NONE][0]['value'];

         $graph = new SocialGraph();
         $graph->addFacebook($u[$key]->fbuid);
         $graph->addEmail($u[$key]->mail);
         $graph->addMobile($u[$key]->mobile);
         $graph->addUserUid($u[$key]->uid);
         $graph->addUserFirstName($u[$key]->first_name);
         $graph->addUserLastName($u[$key]->last_name);
         $graph->createGraphUser();


         drush_print("Finished {$i} of {$t}");
         $i++;
      }
   }

   $finished = $done + $count;
	drush_print("Finished " . $finished);
	variable_set('gum', ++$page);
  variable_set('gum_done', $finished);
}