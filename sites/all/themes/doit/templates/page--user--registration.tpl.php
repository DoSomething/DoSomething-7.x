<?php
// $Id$

/**
 * @file
 * Page template for custom user registration.
 */
?>
<div id="page" class="container">
  <header role="banner">
    <div id="site-name"><strong>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
    </strong></div>
  </header>
  <div id="main-wrapper" class="clearfix">
    <div role="main">
     <div class="main-inner">
       <?php print $messages; ?>
       <?php print render($page['highlighted']); ?>
       <a id="main-content"></a>
       
       <?php print render($title_prefix); ?>
       <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
       <?php print render($title_suffix); ?>

       <h2><?php print $page['gate_description']; ?></h2>

       <?php print render($page['content']); ?>

       <div class="sidebar">
         <h2><?php print $page['gate_sidebar_headline']; ?></h2>
         <p><?php print $page['gate_sidebar_description']; ?></p>
         <p><?php print $page['gate_sidebar_footer']; ?></p>
       </div>

     </div>
    </div> <!-- /#main -->
  </div> <!-- /#main-wrapper -->
</div>