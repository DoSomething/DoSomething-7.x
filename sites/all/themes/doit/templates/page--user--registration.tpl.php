<?php
// $Id$

/**
 * @file
 * Page template for custom user registration.
 */
?>

<?php

  // Cache variables
  $form_headline       = $page['gate_description'];
  $sidebar_headline    = $page['gate_sidebar_headline'];
  $sidebar_description = $page['gate_sidebar_description'];
  $sidebar_footer      = $page['gate_sidebar_footer'];

?>

<div class="container">

  <section class="desktop">
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <?php print $messages; ?>
    <?php print render($page['highlighted']); ?>

    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>

    <img class="image-hero" src="/sites/all/themes/doit/images/gate-bg.jpg" alt="High Five!" />
    <img class="image-join" src="" alt="Join the Campaign" />
  </section>

  <section class="form-container">
    <?php if ($form_headline) { print '<h1 class="sidebar-footer">' . $form_headline . '</h1>';} ?>
    <?php print render($page['content']); ?>
  </section>

  <?php if ($sidebar_headline)    { print '<h2 class="sidebar-headline">'   . $sidebar_headline    . '</h2>'; } ?>
  <?php if ($sidebar_description) { print '<p class="sidebar-description">' . $sidebar_description . '</p>';  } ?>
  <?php if ($sidebar_footer)      { print '<p class="sidebar-footer">'      . $sidebar_footer      . '</p>';  } ?>

  <div class="disclaimer">
    <div id="edit-signup" class="form-item form-type-item">
      <div class="description">
        Clicking "Finish" won't sell your soul, but it means you agree to our
        <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.
      </div>
    </div>
  </div>

</div> <!-- /.container -->

