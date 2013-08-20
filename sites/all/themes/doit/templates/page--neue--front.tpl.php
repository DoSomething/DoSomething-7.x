<nav id="top" class="utility">
  <div class="flexwidth-wrapper">
    <a href="#" class="js-menu-toggle">Menu</a>
    <ul class="utility-links">
      <li>
        <?php print render($page['utility']['dosomething_blocks_dosomething_utility_bar']['search']); ?>
      </li>
      <li id="help-center"><a href="/help">Help</a></li>
      <?php if(!$logged_in): ?>
      <li><a href="/user/login">Sign In</a></li>
      <?php else: ?>
      <li><a href="/user/logout">Log out</a></li>
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
    <h1>Join over 2.1 million other young people taking social action with <strong>DoSomething.org</strong>. Why? Because apathy sucks.</h1>
    <form action="#">
      <input type="text" placeholder="email or cell">
      <input class="btn primary medium" type="submit" value="Sign Up">
    </form>
    <p class="legal">Message &amp; data rates may apply. Text STOP to opt-out, HELP for help.</p>
  </div>
</div>

<div role="main" class="wrapper">
  <h4 class="homepage section-header"><span>Featured Campaigns</span></h4>
  <div class="content-block feature one-col" style="background-image: url('/sites/all/libraries/ds-neue/assets/images/placeholders/feature.jpg');">
    <a class="full-link" href="#"><span>Get Started</span></a>
    <div class="headline big">
      <h3>Everyone has a birthday. Help a homeless teen celebrate theirs.</h3>
      <a href="#" class="btn primary large">Get Started</a>
    </div>
  </div>

  <div class="content-block feature three-col left" style="background-image: url('/sites/all/libraries/ds-neue/assets/images/placeholders/homepage1.jpg'); background-position: center center;">
    <a class="full-link" href="#"><span>Get Started</span></a>
    <div class="headline purple">
      <div class="headline-text"><h3>Change Her Life With $25</h3></div>
      <img class="campaign-logo" src="/sites/all/libraries/ds-neue/assets/images/placeholders/campaign1.png" alt="25,000 Women">
    </div>
  </div>

  <div class="content-block feature three-col" style="background-image: url('/sites/all/libraries/ds-neue/assets/images/placeholders/homepage2.jpg'); background-position: center bottom;">
    <a class="full-link" href="#"><span>Get Started</span></a>
    <div class="headline red">
      <div class="headline-text"><h3>Help Save Shelter Pets Near You</h3></div>
      <img class="campaign-logo" src="/sites/all/libraries/ds-neue/assets/images/placeholders/campaign2.png" alt="Pics for Pets">
    </div>
  </div>

  <div class="content-block feature three-col right" style="background-image: url('/sites/all/libraries/ds-neue/assets/images/placeholders/homepage3.jpg'); background-position: center bottom;">
    <a class="full-link" href="#"><span>Get Started</span></a>
    <div class="headline yellow">
      <div class="headline-text"><h3>Run an Epic Book Drive</h3></div>
      <img class="campaign-logo" src="/sites/all/libraries/ds-neue/assets/images/placeholders/campaign3.png" alt="Epic Book Drive">
    </div>
  </div>

  <div class="homepage-sponsors">
    <h4>Sponsors</h4>
    <p>
      <i title="H&amp;R Block" class="sprite sprite-HRB"></i>
      <i title="Aeropostale" class="sprite sprite-aeropostale"></i>
      <i title="Channel One" class="sprite sprite-channel-one"></i>
      <i title="Fastweb" class="sprite sprite-fastweb"></i>
      <i title="Intel" class="sprite sprite-intel"></i>
      <i title="JetBlue" class="sprite sprite-jetblue"></i>
      <i title="Lenovo" class="sprite sprite-lenovo"></i>
      <i title="Sprint" class="sprite sprite-sprint"></i>
      <i title="VH1" class="sprite sprite-vh1"></i>
      <i title="Walmart" class="sprite sprite-walmart"></i>
    </p>
  </div>
</div>


<div class="footer-wrapper">
    <?php print render($page['footer']); ?>
</div>