<?php


define('DRUPAL_ROOT', getcwd());
include_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$errors = array();
$errors[1] = "No username/password entered";
$errors[2] = "username/password not found";

if(empty($_REQUEST['username']) || empty($_REQUEST['password'])) {
  $err = 1;
}
else {
  $uname = mysql_real_escape_string($_REQUEST['username']);
  $pass = mysql_real_escape_string($_REQUEST['password']);
  $uid = user_authenticate($uname, $pass);
  if($uid === FALSE){ $err = 2; }
}

?>
<auth-response>
<?php

if($err) {
?>
<result-type>ERROR</result-type>
<result-description><?php echo $errors[$err]; ?></result-description>
<?php
}
else {
  $account = user_load($uid);
?>
  <result-type>OK</result-type>
  <username><?php echo $account->name; ?></username>
  <real-name><?php echo $account->name; ?></real-name>
<?php } ?>
</auth-response>
