<?php

function robocalls_drush_command() {
  return array(
    'robocall' => array(
      'description' => 'Robo Calls / etc.',
      'arguments' => array(
        'fnid' => 'The ID of the webform that runs Robocalls',
      ),
    ),
  );
}

function drush_robocalls_robocall($fnid) {
  date_default_timezone_set('UTC');

  $time = mktime(date('H'), date('i'), 0);
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', $fnid)
    ->propertyCondition('uid', 0, '>')
    ->propertyOrderBy('submitted', 'DESC')
    ->fieldCondition('field_celeb_date', 'value', date('Y-m-d H:i:00', $time), '=')
    ->fieldCondition('field_celeb_send_now', 'value', 0, '=')
    ->fieldCondition('field_mobile_commons_id', 'value', 0, '!=')
    ->execute();
  if (!empty($result))
  {
  	foreach ($result['webform_submission_entity'] AS $key => $r)
  	{
      $s = array_shift(entity_load('webform_submission_entity', array((int) $key)));
      if ($s->field_celeb_date[LANGUAGE_NONE][0]['timezone']) {

        $usertz = new DateTimeZone($s->field_celeb_date[LANGUAGE_NONE][0]['timezone']);
        $t = new DateTime($s->field_celeb_date[LANGUAGE_NONE][0]['value'], $usertz);

        $offset = $t->getOffset();
        $now = array_sum(array($time, $offset));
        $thetime = array_sum(array(strtotime($s->field_celeb_date[LANGUAGE_NONE][0]['value']), $offset));

        $cell = $s->field_celeb_friend_phone[LANGUAGE_NONE][0]['value'];
  	    if ($now == $thetime)
  	    {
          $mid = $s->field_mobile_commons_id[LANGUAGE_NONE][0]['value'];
          robocalls_mcommons_call($cell, '', $mid);
  	    }

       echo (date('Y-m-d H:i:00', $now)) . ' ' . date('Y-m-d H:i:00', $thetime) . " (@" . $cell . ' ... ' . $s->field_celeb_date[LANGUAGE_NONE][0]['value'] . " | " . $t->getOffset() . ")\r\n";
      }
  	}
  }
  else {
    echo "Nothing found ($fnid).";
  }
}

?>