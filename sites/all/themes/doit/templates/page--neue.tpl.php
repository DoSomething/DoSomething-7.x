<nav id="top" class="utility">
  <div class="flexwidth-wrapper">
    <a href="#" class="utility-link js-menu-toggle">Menu</a>
    <ul class="utility-links">
      <li class="search">
        <?php print render($page['utility']['dosomething_blocks_dosomething_utility_bar']['search']); ?>
      </li>
      <li><a class="utility-link" href="/help">Help</a></li>
      <?php if(!$logged_in): ?>
      <li><a class="utility-link" href="/user/login">Sign In</a></li>
      <?php else: ?>
      <li><a class="utility-link" href="/user/logout">Log out</a></li>
      <?php endif; ?>
    </ul>
  </div>
</nav>

<div class="masthead-wrapper">
  <nav class="masthead">
    <a class="logo" href="<?php print $front_page; ?>"><img src="/<?php print path_to_theme(); ?>/images/ds-logo.png" alt="DoSomething.org"></a>
    <?php print render($page['navigation']); ?>
  </nav>
</div>

<?php print $messages; ?>
<?php if ($tabs = render($tabs)): ?><div class="pager legal"><?php print $tabs; ?></div><?php endif; ?>
<?php print render($page['content']); ?>

<div class="footer-wrapper">
  <?php print render($page['footer']); ?>
</div>
