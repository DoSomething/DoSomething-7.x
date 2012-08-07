<?php

#define node id here
$node = ;

$n = node_load($node);

$start = strtotime($n->field_campain_date[LANGUAGE_NONE][0]['value']);
$end = strtotime($n->field_campain_date[LANGUAGE_NONE][0]['value2']);

$fg_color = ($n->field_campaign_foreground_color[LANGUAGE_NONE][0][value]);
$bg_color = ($n->field_campaign_background_color[LANGUAGE_NONE][0][value]);

$today = time();

if ($today < $start OR $today > $end)
{
  echo "This one looks dead.";
}
else
{
  echo "This one's still movin'.";
}

?>
