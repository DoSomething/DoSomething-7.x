<?php
// $Id$

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<div id="utility-bar">
  <div class="container">
    UTILITY BAR
  </div>
</div>
<div id="page" class="container">
  <header role="banner">

    <?php if ($site_name): ?>
      <?php if ($title): ?>
        <div id="site-name"><strong>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </strong></div>
      <?php else: /* Use h1 when the content title is empty */ ?>
        <h1 id="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>
    <?php endif; ?>

    <?php print render($page['header']); ?>
    
    <?php if ($main_menu || $secondary_menu): ?>
      <nav role="navigation">
        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
      </nav> <!-- /nav -->
    <?php endif; ?>

  </header>
  
  <div id="main-wrapper" class="clearfix">
    <div role="main">
     
     <div class="main-inner">
       <?php if ($breadcrumb): ?>
         <nav id="breadcrumb"><?php print $breadcrumb; ?></nav>
       <?php endif; ?>

       <?php print $messages; ?>

       <?php print render($page['highlighted']); ?>
       <a id="main-content"></a>
       <?php print render($title_prefix); ?>
       <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
       <?php print render($title_suffix); ?>
       <?php if ($tabs = render($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
       <?php print render($page['help']); ?>
       <?php if ($action_links = render($action_links)): ?><ul class="action-links"><?php print $action_links; ?></ul><?php endif; ?>
       <?php print render($page['content']); ?>
       <?php print $feed_icons; ?>
     </div>

      <div class="main-interior-sidebar">
        <h2>interior sidebar</h2>
        Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec odio. Quisque volutpat mattis eros. Nullam malesuada erat ut turpis. Suspendisse urna nibh, viverra non, semper suscipit, posuere a, pede.
      </div>
    
    </div> <!-- /#main -->
  
    <?php print render($page['sidebar_first']); ?>
  
    <?php // print render($page['sidebar_second']); ?>
    
  </div> <!-- /#main-wrapper -->
    
  <?php print render($page['footer']); ?>
  
</div>





