<?php
/**
 * @file
 * Content of user impending demotion email.
 */
?>

<p>In <?php print $variables['months']; ?> month(s), your membership is scheduled to be demoted to <em><?php print check_plain($variables['new_role']); ?></em>.  You can continue as <em><?php print check_plain($variables['current_role']); ?></em> if you take the appriopriate actions.</p>

