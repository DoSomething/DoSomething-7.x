<!DOCTYPE html>

<html class="no-js">
<head>
    <meta charset="utf-8">
    <title>DS Neue Campaigns</title>

    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1" />
    <?php print $styles; ?>
    <link rel="shortcut icon" href="/favicon.ico" />
    <!--[if lt IE 9]>
        <link rel="stylesheet" href="/assets/ie.css" type="text/css" />
        <script src="/assets/ie/html5.min.js"></script>
  <![endif]-->
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $scripts; ?>
  <?php print $page_bottom; ?>
  <?php if (extension_loaded('newrelic')) print newrelic_get_browser_timing_footer(); ?>
</body>
</html>