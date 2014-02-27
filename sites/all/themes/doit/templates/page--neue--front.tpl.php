<nav id="top" class="utility">
  <div class="page-width">
    <a href="#" class="utility-link mobile-menu-link js-menu-toggle">Menu</a>
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
    <h1>Join over 2.5 million young people taking action. </h1>
    <p>Make the world suck less. Pick a campaign below to get started.</p>
  </div>
</div>

<div class="page-width gutters">

<?php if( strtotime('now') > strtotime("2014-3-01 01:00:00") ) { ?>

  <!-- homepage after specified date -->

  <div class="row">
      <div class="column span_12 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/pbj-featured.jpg'); background-position: center center;">
      <a class="full-link" href="/pbj"><span>Do This</span></a>
      <div class="headline big red">
        <h3>Collect peanut butter for your local food bank.</h3>
        <a href="/pbj" class="btn primary large">Do This</a>
      </div>
    </div>
  </div>

  <div class="row">
    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/wyr-small.jpg'); background-position: top center;">
     <a class="full-link" href="/wyr"><span>Do This</span></a>
     <div class="headline yellow">
       <div class="headline-row"><h4>Challenge your friends to a game of "Would You Rather?"</h4></div>
       <div class="headline-row"><p class="homepage-block-cta"><a href="/wyr" class="btn primary large">Do This</a></p></div>
     </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/pregtext.jpg'); background-position: center center;">
      <a class="full-link" href="/baby"><span>Do This</span></a>
      <div class="headline yellow">
        <div class="headline-row"><h4>Impregnate your friends' phones!</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/baby" class="btn primary large">Do This</a></p></div>
      </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/bullytext-block.jpg'); background-position: center center;">
      <a class="full-link" href="/bullytext"><span>Do This</span></a>
      <div class="headline purple">
        <div class="headline-row"><h4>Everyone has the power to stop bullying. Learn how.</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/bullytext" class="btn primary large">Do This</a></p></div>
      </div>
    </div>
  </div>

<?php } else { ?>

  <!-- homepage before specified date -->

    <div class="row">
      <div class="column span_12 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/t4j-feature-2.jpg'); background-position: center center;">
      <a class="full-link" href="/teensforjeans"><span>Do This</span></a>
      <div class="headline big teal">
        <h3>Collect jeans for homeless youth in your community.</h3>
        <a href="/teensforjeans" class="btn primary large">Do This</a>
      </div>
    </div>
  </div>

  <div class="row">
    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/wyr-small.jpg'); background-position: top center;">
     <a class="full-link" href="/wyr"><span>Do This</span></a>
     <div class="headline yellow">
       <div class="headline-row"><h4>Challenge your friends to a game of "Would You Rather?"</h4></div>
       <div class="headline-row"><p class="homepage-block-cta"><a href="/wyr" class="btn primary large">Do This</a></p></div>
     </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/bullytext-block.jpg'); background-position: center center;">
      <a class="full-link" href="/bullytext"><span>Do This</span></a>
      <div class="headline purple">
        <div class="headline-row"><h4>Everyone has the power to stop bullying. Learn how.</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/bullytext" class="btn primary large">Do This</a></p></div>
      </div>
    </div>

    <div class="column span_4 feature-block fixed" style="background-image: url('//www.dosomething.org/files/u/pbj-homepage-sm.jpg'); background-position: center center;">
      <a class="full-link" href="/pbj"><span>Do This</span></a>
      <div class="headline red">
        <div class="headline-row"><h4>Collect peanut butter for your local food bank.</h4></div>
        <div class="headline-row"><p class="homepage-block-cta"><a href="/pbj" class="btn primary large">Do This</a></p></div>
      </div>
    </div>
  </div>

<?php } ?>

  <div class="row section callout">
    <a href="/campaigns" class="btn tertiary">See All Campaigns</a>
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
      <i title="H&amp;M" class="sprite sprite-hm"></i>
      <i title="Salt" class="sprite sprite-salt"></i>
      <i title="American Express" class="sprite sprite-amex"></i>
      <i title="Google" class="sprite sprite-google"></i>
    </p>
  </div>
</div>


<div class="footer-wrapper">
    <?php print render($page['footer']); ?>
</div>
