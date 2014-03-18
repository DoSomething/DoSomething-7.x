<?php
// $Id$

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<!-- HEADER from ds-neue v2.0.23 -->
<div class="nav--wrapper">
  <nav class="main">
    <a class="logo" href="http://www.dosomething.org"><img src="/sites/all/libraries/ds-neue/assets/images/ds-logo.png" alt="DoSomething.org"></a>
    <a class="hamburger js-toggle-mobile-menu" href="#">&#xe606;</a>
    <div class="menu">
      <ul class="primary-nav">
        <li>
          <a href="/campaigns">
            <strong>Explore Campaigns</strong>
            <span>Any cause, anytime, anywhere.</span>
          </a>
        </li>
        <li>
          <a href="/about/any-cause-anytime-anywhere">
            <strong>What is Do Something?</strong>
            <span>Young people + social change.</span>
          </a>
        </li>
      </ul>

      <div class="secondary-nav">
        <ul>
          <li class="searchfield">
            <form action="/search/?s=#" method="get" accept-charset="utf-8">
              <input type="search" name="s" id="search" value="" />
            </form>
          </li>
          <li><a class="secondary-nav-item js-modal-link" data-cached-modal="#modal--auth-login" href="/user/login">Log In</a></li>
        </ul>
      </div>
    </div>
  </nav>
</div>

<div id="page" class="container">


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

    <?php print render($page['sidebar_first']); ?>

    <?php // print render($page['sidebar_second']); ?>

  </div> <!-- /#main-wrapper -->

</div>

<!-- DELETE ME -->
<?php /*print render($page['footer']);*/ ?>

<!-- New footer override -->
<div class="footer--wrapper">
  <footer class="main">
      <div class="social tablet">
        <ul>
          <li><a class="social-link" title="dosomething on Facebook" href="https://www.facebook.com/dosomething">&#xe600;</a></li>
          <li><a class="social-link" title="@dosomething on Twitter" href="https://twitter.com/dosomething">&#xe603;</a></li>
          <li><a class="social-link" title="@dosomething on Tumblr" href="http://dosomething.tumblr.com">&#xe602;</a></li>
          <li><a class="social-link" title="@dosomething on Instagram" href="http://instagram.com/dosomething">&#xe604;</a></li>
          <li><a class="social-link" title="dosomething1 on YouTube" href="http://www.youtube.com/dosomething1">&#xe601;</a></li>
        </ul>
      </div>
      <div class="col help js-footer-col">
        <h4>Help</h4>
        <ul>
           <li><a href="/about/get-in-touch">Contact Us</a></li>
           <li><a href="/about/hotline">Hotlines</a></li>
           <li><a href="/about/frequently-asked-questions">FAQ</a></li>
        </ul>
      </div>
      <div class="col knowus js-footer-col">
        <h4>Get to Know Us</h4>
        <ul>
          <li><a href="/about/our-partners">Partners</a></li>
          <li><a href="/about/please-give-us-your-money">Donate</a></li>
          <li><a href="http://www.tmiagency.org/">TMI Agency</a></li>
        </ul>
      </div>
      <div class="col about js-footer-col">
        <h4>About</h4>
        <ul>
          <li><a href="/about/any-cause-anytime-anywhere">What is Do Something?</a></li>
          <li><a href="/about/our-team">Our Team</a></li>
          <li><a href="/about/were-hiring">Jobs</a></li>
          <li><a href="/about/internships">Internships</a></li>
          <li><a href="/about/old-people">Old People</a></li>
          <li><a href="/about/sexy-financials">Sexy Financials</a></li>
          <li><a href="/about/dosomethingorg-around-globe">International</a></li>
        </ul>
      </div>

      <div class="social mobile">
        <ul>
          <li><a class="social-link" title="dosomething on Facebook" href="https://www.facebook.com/dosomething">&#xe600;</a></li>
          <li><a class="social-link" title="@dosomething on Twitter" href="https://twitter.com/dosomething">&#xe603;</a></li>
          <li><a class="social-link" title="@dosomething on Tumblr" href="http://dosomething.tumblr.com">&#xe602;</a></li>
          <li><a class="social-link" title="@dosomething on Instagram" href="http://instagram.com/dosomething">&#xe604;</a></li>
          <li><a class="social-link" title="dosomething1 on YouTube" href="http://www.youtube.com/dosomething1">&#xe601;</a></li>
        </ul>
      </div>

      <div class="subfooter">
        <div class="tagline">Any cause, anytime, anywhere. *mic drop*</div>
        <ul class="utility">
          <li><a href="/about/privacy-policy">Privacy Policy</a></li>
          <li><a href="/about/terms-service">Terms of Service</a></li>
        </ul>
      </div>
  </footer>
</div>

