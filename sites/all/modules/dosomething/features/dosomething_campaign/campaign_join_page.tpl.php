<p>I need all of the markup</p>

<p>You have three variables available:</p>
<ul>
  <li>node (The full node object of the campaign.  Grab the title out of there)</li>
  <li>uid (<?php print $uid; ?>)</li>
  <li>form</li>
</ul>

<?php print render($form); ?>
