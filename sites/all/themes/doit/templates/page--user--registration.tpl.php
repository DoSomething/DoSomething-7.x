<?php
// $Id$

/**
 * @file
 * Page template for custom user registration.
 */
?>
<div id="gate">
  <div class="container">

    <div class="logo-ds">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
    </div>

    <?php print $messages; ?>
    <?php print render($page['highlighted']); ?>
   
    <?php print render($title_prefix); ?>
    <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
    <?php print render($title_suffix); ?>

    <h2><?php print $page['gate_description']; ?></h2>

    <img class="image-hero desktop" src="http://www.dosomething.org/files/u/misc/squirrel.jpg" alt="High Five!" />

    <img class="image-join desktop" src="" alt="Join the Campaign" />

    <?php print render($page['content']); ?>

    <h2><?php print $page['gate_sidebar_headline']; ?></h2>
    <p><?php print $page['gate_sidebar_description']; ?></p>
    <p><?php print $page['gate_sidebar_footer']; ?></p>

  </div> <!-- /.container -->
</div> <!-- /#gate -->

