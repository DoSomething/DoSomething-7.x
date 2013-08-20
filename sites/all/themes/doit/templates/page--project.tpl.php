<?php if ($utility = render($page['utility'])): ?>
  <nav id="top" class="utility">
    <div class="flexwidth-wrapper">
      <a href="#" class="js-menu-toggle">Menu</a>
      <ul class="utility-links">
        <li id="help-center"><a href="/help">Help Center</a></li>
        <?php if(!$logged_in): ?>
        <li><a href="/user/login">Sign In</a></li>
        <?php else: ?>
        <li><a href="/user/logout">Log out</a></li>
        <?php endif; ?>
      </ul>
    </div>
  </nav>
<?php endif; ?>

<div class="masthead-wrapper">
    <nav class="masthead">
        <a class="logo" href="<?php print $front_page; ?>"><img src="/<?php print path_to_theme(); ?>/images/ds-logo.png" alt="DoSomething.org"></a>
        <?php print render($page['navigation']); ?>
    </nav>
</div>

<div role="main" class="wrapper">
<?php print $messages; ?>
<?php print render($page['content']); ?>
</div>

<div class="footer-wrapper">
    <?php print render($page['footer']); ?>
</div>