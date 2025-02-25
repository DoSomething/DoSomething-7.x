<?php
// $Id$
// @TODO - THIS PREPROCESSED TEMPLATE EXISTS TO MIRROR THE DO IT TEMPLATE STYLES

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<?php if ($utility = render($page['utility'])): ?>
  <div id="utility-bar">
    <div class="container">
      <?php print $utility; ?>
    </div>
  </div>
<?php endif; ?>

<nav role="navigation">
  <?php print render($page['navigation']); ?>
</nav> <!-- /nav -->

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

    <?php print render($page['header']); ?>

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
       <?php print render($page['top_navbar']); ?>
       <?php print render($page['content']); ?>
       <?php print $feed_icons; ?>
     </div>

    </div> <!-- /#main -->

    <?php // print render($page['sidebar_first']); ?>

    <?php // print render($page['sidebar_second']); ?>

  </div> <!-- /#main-wrapper -->

</div>
