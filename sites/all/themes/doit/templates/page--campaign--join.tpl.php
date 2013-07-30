<?php
// $Id$

/**
 * @file
 * Page template for campaign join.
 */

// Yes, it's ugly defining a variable here...  
// But it's also prettier than printing this out every time below. 
$campaign = $page['content']['system_main'];
?>

<div class="join wrapper nid-<?php print $campaign['nid']; ?>">

  <section class="form-container">
    <a class="logo-ds" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="/sites/all/themes/doit/images/logo-ds.png" alt="DoSomething.org" />
    </a>

    <img class="image-hero" src="<?php print $campaign['gate_image_src']; ?>" alt="<?php print $campaign['gate_image_alt']; ?>" />

    <?php print render($campaign['form']); ?>

    <div class="field-content">
      <h1 class="headline" style="color:<?php print $campaign['gate_color']; ?> !important;"><?php print $campaign['gate_headline']; ?></h1>
      <h2 class="subheadline"><?php print $campaign['gate_subheadline']; ?></h2>
      <p class="description"><?php print $campaign['gate_description']; ?></p>
    </div>

  </section>

</div> <!-- /.wrapper -->
