<?php
  $q = new EntityFieldQuery;
  $result = $q
    ->entityCondition('entity_type', 'webform_submission_entity')
    ->propertyCondition('nid', $fnid)
    ->propertyOrderBy('submitted', 'DESC')
    ->fieldCondition('field_celeb_date', 'value', array(date('Y-m-d', time()), date('Y-m-d', strtotime('Tomorrow'))), 'between')
    ->execute();
  if (!empty($result))
  {
  	foreach ($result['webform_submission_entity'] AS $key => $r)
  	{
	    $s = (webform_get_submission($fnid, (int)$key));

	    if (strtotime($s->field_celeb_date[LANGUAGE_NONE][0]['value']) == strtotime(date('Y-m-d H:i:00')))
	    {
	    	mail('mchittenden@dosomething.org', 'Sending from Cron Job!', "Here's a message about how this worked.  Good stuff!");
        echo "Found something";
	    }
  	}
  }

mail('mchittenden@dosomething.org', 'Sending a test!', "Here's a message about how this worked.  Good stuff!");

?>