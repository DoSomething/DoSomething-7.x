<?php

if ($campaign = create_and_share_is_campaign_page()) {
  $path = create_and_share_get_campaign_path($campaign) . '/templates/header.tpl.php';
  if (file_exists($path)) {
    require_once $path;
  }
}

?>