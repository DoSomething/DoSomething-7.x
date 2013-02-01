<?php

/**
* @file
*  Template file for Craziest Thing... campaign
*/
?>

<?php if ($utility = render($page['utility'])): ?>
  <div id="utility-bar">
      <div class="container">
          <?php print $utility; ?>
      </div>
  </div>
<?php endif; ?>

<div id="page" class="container">
  <header role="banner">
    <?php if (isset($site_name)): ?>
      <?php if (isset($title)): ?>
        <div id="site-name"><strong>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </strong></div>
      <?php else: /* Use h1 when the content title is empty */ ?>
        <h1 id="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>
    <?php endif; ?>
  </header>

  <div id="main-wrapper" class="clearfix">
    <div role="main">
     <div class="main-inner">
       <?php print $messages; ?>
       <?php print render($page['top_navbar']); ?>
       <?php print render($page['content']); ?>
     </div>
    </div> <!-- /#main -->
  </div> <!-- /#main-wrapper -->
</div>