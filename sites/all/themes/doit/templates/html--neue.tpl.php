<!DOCTYPE html>

<html class="no-js">
<head>
    <meta charset="utf-8">
    <title><?php print $head_title; ?></title>

    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
    <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1" />
    <?php print $styles; ?>
    <link rel="shortcut icon" href="/favicon.ico" />
    <meta property="og:site_name" content="Do Something">
    <meta property="fb:app_id" content="105775762330">
    <meta property="og:url" content="http://www.dosomething.org/front">
    <meta property="og:image" content="http://files.dosomething.org/files/styles/thumbnail/public/garland_logo_0.png">
    <meta property="og:title" content="DoSomething.org">
    <meta property="og:description" content="DoSomething.org is the country's largest organization for young people and social change with 2,000,000 members and counting.">
    <meta property="og:type" content="non_profit">

    <meta property="description" content="DoSomething.org is the country's largest organization for young people and social change with 2,000,000 members and counting.">

    <!--[if lt IE 9]>
        <link rel="stylesheet" href="/sites/all/libraries/ds-neue/assets/ie.css" type="text/css" />
        <script src="/sites/all/libraries/ds-neue/assets/ie/html5.min.js"></script>
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