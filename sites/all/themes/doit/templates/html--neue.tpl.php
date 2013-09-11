<!DOCTYPE html>

<html class="no-js">
<head>
    <?php print $head; ?>
    
    <title><?php print $head_title; ?></title>

    <?php print $styles; ?>
    <!--[if lt IE 9]>
        <link rel="stylesheet" href="/sites/all/libraries/ds-neue/assets/ie.css" type="text/css" />
        <script src="/sites/all/libraries/ds-neue/assets/ie/html5.min.js"></script>
        <script src="/sites/all/libraries/ds-neue/assets/ie/rem.min.js"></script>
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