<?php
/**
 * @file
 * Content parent permission email.
 */
?>

<?php print $full_name ?> has requested to be a member of <?php print check_plain(variable_get('site name', 'Do Something.org')); ?>.

<p>Go to this link to give your permission: <?php print $link; ?></p>

