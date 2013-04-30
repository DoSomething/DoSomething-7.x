<?php

if ($campaign_path = create_and_share_get_campaign_path($campaign)) {
  if (file_exists($campaign_path . '/templates/' . $template . '-notification.tpl.php')) {
  	require_once $campaign_path . '/templates/' . $template . '-notification.tpl.php';
  }
  else {
?>
<h1>Could not find '<?php echo $template; ?>' template</h1>
<?php
  }
}
?>