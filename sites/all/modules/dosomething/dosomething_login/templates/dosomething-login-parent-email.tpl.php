<?php
/**
 * @file
 * Content parent permission email.
 */
?>

<p><?php print $full_name ?> has asked to sign up for our site, but first we wanted to run it by you for approval.

<br /><br /><?php print check_plain(variable_get('site name', 'Do Something.org')); ?> is a not-for-profit organization that helps young people make a difference in social causes. We host national campaigns that create a real impact in your community; plus participation never requires money.

<br /><br />If you could be the coolest parent/guardian and click the following link, then %profile[profile_first_name] %profile[profile_last_name] 
can 
be a part 
of our online community: <?php print $link; ?>

<br />If you have any questions, please email <a href="mailto:help@dosomething.org">help@dosomething.org</a>.

<br />You're the best,

<br /><br />DoSomething.org</p>
