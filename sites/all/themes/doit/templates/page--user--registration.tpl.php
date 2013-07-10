<?php
// $Id$

/**
 * @file
 * Page template for custom user registration.
 */
?>

<div class="wrapper">

  <section class="desktop-container">
    <div class="toolbar desktop"><a href="/user/login">sign in</a></div>
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <?php print $messages; ?>
    <?php print render($page['highlighted']); ?>

    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>

    <img class="image-hero" src="/sites/all/themes/doit/images/gate-bg.jpg" alt="High Five!" />

    <?php if ($page['gate_sidebar_headline']) { print '<h2 class="sidebar-headline">' . $page['gate_sidebar_headline'] . '</h2>';} ?>
    <?php if ($page['gate_sidebar_description']) { print '<p class="sidebar-description">' . $page['gate_sidebar_description'] . '</p>';} ?>
    <?php //if ($page['gate_sidebar_footer']) { print '<p class="sidebar-footer">' . $page['gate_sidebar_footer'] . '</p>';} ?>

  </section>

  <section class="form-container">
    <div class="toolbar mobile"><a href="/user/login">sign in</a></div>
    <?php if ($page['gate_description']) { print '<h1 class="gate-description">' . $page['gate_description'] . '</h1>';} ?>
    <?php /*
    <img class="image-join" src="" alt="Join the Campaign" />
    */ ?>
    <?php print render($page['content']); ?>
  </section>

  <div class="disclaimer">
    Clicking "Finish" won't sell your soul, but it means you agree to our <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.
  </div>

</div> <!-- /.container -->

