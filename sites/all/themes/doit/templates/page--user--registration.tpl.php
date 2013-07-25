<?php
// $Id$

/**
 * @file
 * Page template for custom user registration.
 */
?>



<div class="wrapper">

  <section class="desktop-container">
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <img class="image-hero" src="<?php print $page['gate_image_src']; ?>" alt="<?php print $page['gate_image_alt']; ?>" />

    <div class="field-content">
      <?php if ($page['gate_subheadline']): ?>
      <h2 class="subheadline" style="color: <?php print $page['gate_color']; ?> !important;"><?php print $page['gate_subheadline']; ?></h2>
      <?php endif; ?>
      <?php if ($page['gate_description']): ?><p class="description"><?php print $page['gate_description']; ?></p><?php endif; ?>
    </div>

  </section>

  <section class="form-container">

    <div class="toolbar desktop"><?php print $variables['page']['gate_link']; ?></div>
    <div class="toolbar mobile"><?php print $variables['page']['gate_link']; ?></div>

    <div class="field-content">
      <?php if ($page['gate_headline']): ?>
      <h1 class="headline" style="color:<?php print $page['gate_color']; ?> !important;"><?php print $page['gate_headline']; ?></h1>
      <?php endif; ?>
      <?php if ($page['gate_subheadline']): ?><h2 class="subheadline"><?php print $page['gate_subheadline']; ?></h2><?php endif; ?>
      <?php if ($page['gate_description']): ?><p class="description"><?php print $page['gate_description']; ?></p><?php endif; ?>
    </div>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>
    <?php if ($page['gate_go_back_link']): ?><div class="go-back"><?php print $page['gate_go_back_link']; ?></div><?php endif; ?>
  </section>

  <div class="disclaimer">
    Clicking "Finish" won't sell your soul, but it means you agree to our <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.
  </div>

</div> <!-- /.container -->

