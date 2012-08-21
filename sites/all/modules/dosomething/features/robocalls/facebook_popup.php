<?php

if ($_GET['code']) {
    echo <<< html
<script type="text/javascript" src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
<script type="text/javascript">
<!--
    $(document).ready(function() {
        console.log('Just logged in.  Trying to alter the click state.');
        window.opener.alter_click();
        window.opener.pop();
        window.close();
    });
-->
</script>
html;
}

if (intval($_GET['post_id']))
{
    echo <<< html
<script type="text/javascript" src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
<script type="text/javascript">
<!--
    $('#edit-fb-container', window.opener.document).html("Okay! We've sent your Facebook message.");
    window.close();
-->
</script>
html;
    exit;
}
/* Rendered useless: Varnish removes all non-Drupal cookies.
if ($uid)
{
    if ($user = $facebook->api('/me/friends?fields=id,name,picture'))
    {
echo <<< html
<html>
 <head>
    <title>Facebook | Post on a Friend's Wall</title>
<link rel="stylesheet" type="text/css" href="/sites/all/modules/dosomething/features/robocalls/css/robocalls_facebook.css" />

<script type="text/javascript" src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
<script type="text/javascript">
<!--
    $(function() {
        $('li').click(function(e) {
            var id = ($(this).find('a').attr('class').replace('friend-', ''));
            window.location.href = 'http://www.facebook.com/dialog/feed?app_id=169271769874704&display=popup&to=' + id + '&description={$ROBOCALLS_FB_DESCRIPTION}&redirect_uri=http://localhost:8080/sites/all/modules/dosomething/features/robocalls/facebook_popup.php';
            window.resizeTo(500, 350);
        });
    });
-->
</script>
<style type="text/css">
<!--
-->
</style>
 </head>
<body>
<div id="pageheader" class=""><div class="platform_dialog_header" id="header_container"><div class="lfloat"><h2 id="homelink">Choose A Friend to Post on their Wall</h2></div></div></div>
html;
    echo '<ul>';
    foreach ($user['data'] AS $key => $friend)
    {
        $info[$friend['name']] = array(
            'id' => $friend['id'],
            'name' => $friend['name'],
     #       'birthday' => $friend['birthday'],
            'photo' => $friend['picture']['data']['url']
        );
    }

    ksort($info);
    foreach ($info AS $k => $f)
    {
        $r .= '<li>';
        $r .= '<input type="hidden" name="info" value="' . $f['birthday'] . '" />';
        $r .= '<img src="' . $f['photo'] . '" style="float: left" alt="" />';
        $r .= '<a href="http://www.facebook.com/' . $f['id'] . '" class="friend-' . $f['id'] . '">' . $f['name'] . '</a>';
        #$r .= '<div>Birthday: ' . $friend['birthday'] . '</div>';
        $r .= '</li>';
    }
        
        echo $r;
        echo '</ul></body></html>';
    } 
    else
    {
        $params = array(
            'redirect_uri' => 'http://' . $_SERVER['HTTP_HOST'] . '/sites/all/modules/dosomething/features/robocalls/facebook_popup.php',
            'display' => 'popup'
        );

        $login_url = $facebook->getLoginUrl();
        header("Location: " . $login_url);  
    }
}
else
{
    $params = array(
        'redirect_uri' => 'http://' . $_SERVER['HTTP_HOST'] . '/sites/all/modules/dosomething/features/robocalls/facebook_popup.php',
        'display' => 'popup'
    );

    $login_url = $facebook->getLoginUrl($params); 
    header("Location: " . $login_url);
}
*/
?>