<?php
// $Id$

/**
 * @file
 * Page template for campaign join.
 */
$campaign = $page['content']['system_main'];
?>

<div class="join wrapper">

  <section class="form-container">
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <img class="image-hero" src="<?php print $campaign['gate_image_src']; ?>" alt="<?php print $campaign['gate_image_alt']; ?>" />

    <?php print render($campaign['form']); ?>

    <div class="field-content">
      <h1 class="headline"><?php print $campaign['gate_headline']; ?></h1>
      <h2 class="subheadline"><?php print $campaign['gate_subheadline']; ?></h2>
      <p class="description"><?php print $campaign['gate_description']; ?></p>
    </div>

  </section>

</div> <!-- /.wrapper -->
