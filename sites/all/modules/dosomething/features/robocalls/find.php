<?php

if ($_POST['do'] || $_GET['do'] == 'test')
{
	#echo '<link rel="stylesheet" type="text/css" href="ds.style.css" />';
	echo '<ul>';
	foreach ($_POST['vals']['data'] AS $key => $friend)
	{
        if (!$friend['birthday']) continue;
        unset($info);
		$info = array(
			'id' => $friend['id'],
			'name' => $friend['name'],
			'birthday' => $friend['birthday'],
			'photo' => $friend['picture']['data']['url']
		);

		$r = '<li>';
		$r .= '<input type="hidden" name="info" value="' . $friend['birthday'] . '" />';
		$r .= '<img src="' . $friend['picture']['data']['url'] . '" style="float: left" alt="" />';
		$r .= '<a href="http://www.facebook.com/' . $friend['id'] . '">' . $friend['name'] . '</a>';
		$r .= '<div>Birthday: ' . $friend['birthday'] . '</div>';
		$r .= '</li>';
		
		echo $r;
		#echo $friend['picture']['data']['url'] . "\r\n";
	}
	echo '</ul>';

    exit;
}

?>