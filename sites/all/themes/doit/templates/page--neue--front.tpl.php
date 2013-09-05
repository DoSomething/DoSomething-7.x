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
<div class="ds-intro">
  <div class="flexwidth-wrapper">
    <h1>Join over 2.2 million young people taking action.</h1>
    <h2>Make the world suck less. Pick a project below to get started.</h2>
  </div>
</div>

<div role="main" class="wrapper">
  <div class="content-block feature fixed one-col" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/survivors2-feature.jpg'); background-position: right center;">
    <a class="full-link" href="/survivors"><span>Do This</span></a>
    <div class="headline big purple">
      <h3>Donate your old cell phone to help domestic abuse survivors</h3>
      <a href="/survivors" class="btn primary large">Do This</a>
    </div>
  </div>

  <div class="content-block feature fixed three-col left" style="background-image: url('//www.dosomething.org/files/u/neue-homepage/bullytext-block.jpg'); background-position: center center;">
    <a class="full-link" href="/bullytext"><span>Do This</span></a>
    <div class="headline blue">
      <div class="row"><div class="headline-text"><h3>Invite friends to stand up to bullying</h3></div></div>
      <div class="row"><p class="block-cta"><a href="/bullytext" class="btn primary large">Do This</a></p></div>
    </div>
  </div>

  <div class="content-block feature fixed three-col" style="background-image: url('/sites/all/libraries/ds-neue/assets/images/placeholders/homepage1.jpg'); background-position: center center;">
    <a class="full-link" href="/women"><span>Do This</span></a>
    <div class="headline purple">
      <div class="row"><div class="headline-text"><h3>Unlock a $25 loan for a woman in need</h3></div></div>
      <div class="row"><p class="block-cta"><a href="/women" class="btn primary large">Do This</a></p></div>
    </div>
  </div>

  <div class="content-block feature fixed three-col right" style="background-image: url('http://www.dosomething.org/files/u/neue-homepage/spit-block.png'); background-position: center center;">
    <a class="full-link" href="/spit"><span>Do This</span></a>
    <div class="headline red">
      <div class="row"><div class="headline-text"><h3>Save a life at your next party</h3></div></div>
      <div class="row"><p class="block-cta"><a href="/spit" class="btn primary large">Do This</a></p></div>
    </div>
  </div>

  <div class="homepage-sponsors">
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