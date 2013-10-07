<nav id="top" class="utility">
  <div class="page-width">
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
<div class="full-width wallpaper ds-intro">
  <div class="page-width with-copy">
    <h1>Join over 2.2 million young people taking action. </h1>
    <p>Make the world suck less. Pick a project below to get started.</p>
  </div>
</div>

<div class="page-width gutters">
  <div class="row">
      <div class="column span_12 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/50cans-feature.jpg'); background-position: left center;">
      <a class="full-link" href="/50cans"><span>Do This</span></a>
      <div class="headline big blue">
        <h3>Invite friends to stand up to bullying with the Bully Text.</h3>
        <a href="/50cans" class="btn primary large">Do This</a>
      </div>
    </div>
  </div>

  <div class="row">
    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/survivors-block.jpg'); background-position: center center;">
      <a class="full-link" href="/survivors"><span>Do This</span></a>
      <div class="headline purple">
        <div class="headline-row"><h4>Your challenge is simple. Recycle 50 aluminum cans.</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/survivors" class="btn primary large">Do This</a></p></div>
      </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/fedup-block.jpg'); background-position: center center;">
      <a class="full-link" href="//fedup.dosomething.org/fedup"><span>Do This</span></a>
      <div class="headline red">
        <div class="headline-row"><h4>Petition: Add more diverse Emoji</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="//fedup.dosomething.org/fedup" class="btn primary large">Do This</a></p></div>
      </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/bullytext-block.jpg'); background-position: center center;">
      <a class="full-link" href="/bullytext"><span>Do This</span></a>
      <div class="headline yellow">
        <div class="headline-row"><h4>Everyone has the power to stop bullying. Learn how.</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/bullytext" class="btn primary large">Do This</a></p></div>
      </div>
    </div>
  </div>

  <div class="row homepage-sponsors">
    <h4>Sponsors</h4>
    <p>
      <i title="H&amp;R Block" class="sprite sprite-HRB"></i>
      <i title="Aeropostale" class="sprite sprite-aeropostale"></i>
      <i title="Channel One" class="sprite sprite-channel-one"></i>
      <i title="Fastweb" class="sprite sprite-fastweb"></i>
      <i title="Toyota" class="sprite sprite-toyota"></i>
      <i title="JetBlue" class="sprite sprite-jetblue"></i>
      <i title="AARP" class="sprite sprite-aarp"></i>
      <i title="Sprint" class="sprite sprite-sprint"></i>
      <i title="VH1" class="sprite sprite-vh1"></i>
      <i title="Walmart" class="sprite sprite-walmart"></i>
      <i title="American Express" class="sprite sprite-amex"></i>
    </p>
  </div>
</div>


<div class="footer-wrapper">
    <?php print render($page['footer']); ?>
</div>
