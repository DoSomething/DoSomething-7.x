<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

  <div id="page">

    <header role="banner" class="clearfix">

      <div id="ds-logo">Do Something</div>

      <?php if ($logo): ?>
        <a href="/fb/pics-for-pets/gallery" title="Gallery" rel="home" id="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php if ($site_name || $site_slogan): ?>
        <hgroup id="name-and-slogan">
          <?php if ($site_name): ?>
            <h1 id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
          <?php endif; ?>

          <?php if ($site_slogan): ?>
            <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        </hgroup> <!-- /#name-and-slogan -->
      <?php endif; ?>

      <?php print render($page['header']); ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
      <?php print render($title_suffix); ?>

    </header> <!-- /header -->

    <?php if ($main_menu || $secondary_menu): ?>
      <nav role="navigation">
        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
      </nav> <!-- /nav -->
    <?php endif; ?>

    <div id="main-wrapper" class="clearfix">

      <?php print render($page['sidebar_first']); ?>

      <div role="main">
        <?php print render($page['highlighted']); ?>
        <a id="main-content"></a>
        <?php if ($tabs = render($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links = render($action_links)): ?><ul class="action-links"><?php print $action_links; ?></ul><?php endif; ?>
        <div id="slideshow-wrapper">
        <?php print render($page['content']); ?>
        </div>
        <?php print $feed_icons; ?>
      </div> <!-- /main -->

      <?php print render($page['sidebar_second']); ?>

    </div> <!-- /#main -->

    <?php print render($page['footer']); ?>

    <?php print $messages; ?>

  </div> <!-- /#page -->
