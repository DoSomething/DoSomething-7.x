<?php
// $Id$

/**
 * @file
 * Page template for campaign join.
 */
$campaign = $page['content']['system_main'];
?>

<div class="wrapper">

  <section class="desktop-container">
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <img class="image-hero" src="<?php print $campaign['gate_image_src']; ?>" alt="<?php print $campaign['gate_image_alt']; ?>" />

    <div class="field-content">
      <h2 class="subheadline"><?php print $campaign['gate_subheadline']; ?></h2>
      <p class="description"><?php print $campaign['gate_description']; ?></p>
    </div>

  </section>

  <section class="form-container">

    <div class="field-content">
      <h1 class="headline"><?php print $campaign['gate_headline']; ?></h1>
      <h2 class="subheadline"><?php print $campaign['gate_subheadline']; ?></h2>
      <p class="description"><?php print $campaign['gate_description']; ?></p>
    </div>

    <?php print render($campaign['form']); ?>
   
  </section>

</div> <!-- /.wrapper -->
