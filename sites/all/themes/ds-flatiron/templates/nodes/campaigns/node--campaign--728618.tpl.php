<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>

    <?php

      require('node-field-variables.php');

    ?>

    <section class="header" id="header">
      <div class="section-container">
        <a class="logo-dosomething" href="//www.dosomething.org/">
          <img src="<?php print($files_source . 'logo-ds.png'); ?>" alt="DoSomething.org logo" />
        </a>
        <a class="log-out" href="/user/logout">log out</a>
        <img class="logo-campaign" src="<?php print($files_source . 'logo-' . $cmp_short . '.png'); ?>" alt="<?php print($cmp_name); ?> logo" />
        <?php if ($sponsor): ?>
          <img class="logo-sponsor" src="<?php print($files_source . 'logo-' . $sponsor . '.png'); ?>" alt="<?php print($sponsor); ?> logo" />
        <?php endif; ?>

        <div class="header-social">

          <!-- Facebook Like Button -->
          <a href="#" class="header-facebook-share">
            <img src="//www.dosomething.org/files/campaigns/wyr/bg-recommend.png" alt="Recommend" />
          </a>

          <!-- Twitter Tweet Button -->
          <div class="header-twitter-share">
            <a href="https://twitter.com/share" class="twitter-share-button" data-url="http://www.dosomething.org/wyr" data-text="I'm #TeamCrunchy when it comes to my peanut butter! What are you? Pick sides in @dosomething's #PBJSlam now: http://www.dosomething.org/pbj" data-via="dosomething" data-count="none">Tweet</a>
            <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
          </div>

      </div> <!-- .section-container -->
    </section> <!-- .header -->

    <?php if (!isset($complete) && !isset($shared)): ?>

      <?php /* TODO - PREVENT THOSE WHO HAVEN'T SUBMITTED THE REPORT BACK FROM FROM SEEING THIS SECTION */ ?>

      <section class="project" id="project">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-project.png') ?>" alt="The Project" />
          <h1><?php print($project[1]); ?></h1>
          <h1><?php print($project[2]); ?></h1>
        </div> <!-- .section-container -->
      </section> <!-- .project -->

      <section class="challenge" id="challenge">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-challenge.png'); ?>" alt="your challenge" />
          <h2><?php print($challenge[1]); ?></h2>
          <h2><?php print($challenge[2]); ?></h2>
        </div> <!-- .section-container -->
      </section> <!-- .challenge -->

      <section class="scholarship" id="scholarship">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-scholarship.png'); ?>" alt="scholarship" />

          <?php /* Display pre-opt in copy if the user has not submitted the contact form */ ?>
          <?php if (!isset($team) && !isset($individual)): ?>
            <h2><?php print($scholarship[1]); ?></h2>
          <?php endif; ?>

          <div class="contact-form contact-form-individual">
            <?php print render($content['contact']['individual']); ?>
          </div>  <!-- .contact-form (individual) -->

          <div class="contact-form contact-form-group">
            <?php print render($content['contact']['team']); ?>
          </div>  <!-- .contact-form (group) -->

          <?php /* Display post-opt in copy after the user has submitted the contact form */ ?>
          <?php if (isset($team) || isset($individual)): ?>
            <h2><?php print($scholarship[2]); ?></h2>
            <div class="report-back-form">
              <?php print render($content['report_back']); ?>
            </div>  <!-- .report_back -->
          <?php endif; ?>

          <div class="official-rules-wrapper">
            <a class="official-rules-link" href="<?php print($files_source . 'official-rules.pdf'); ?>"  target="_blank">official rules</a>
          </div> <!-- .official-rules-wrapper -->

        </div> <!-- .section-container -->
      </section> <!-- .scholarship -->

      <section class="social" id="social">
        <div class="section-container">

          <img class="bg-header" src="<?php print($files_source . 'h-social.png'); ?>" alt="<?php print($share[0]); ?>" />
          <h2><?php print($share[1]); ?></h2>

          <div class="col-social">
            <img src="<?php print($files_source . 'bg-social1.png'); ?>" alt="<?php print($share[2]); ?>" />
            <a href="#" class="share-link-social share-link-social1">
              <?php print($social[3]); ?>
            </a>
          </div> <!-- .social-col -->

          <div class="col-social">
            <img src="<?php print($files_source . 'bg-social2.png'); ?>" alt="<?php print($share[4]); ?>" />
            <a href="#" class="share-link-social share-link-social2">
              <?php print($social[5]); ?>
            </a>
          </div> <!-- .social-col -->

        </div> <!-- .section-container -->
      </section> <!-- .social -->

      <section class="cause" id="cause">
        <div class="section-container">

          <?php for ($i=1;$i<5;$i++): ?>
            <div class="cause-facts <?php if($i == 1){ print("active-fact"); } ?>">
              <img class="bg-header" src="<?php print($files_source . 'h-cause' . $i . '.png'); ?>" alt="why <?php print($cause_subject); ?>?" />
              <ul>
                <?php for ($j=1;$j<5;$j++): ?>
                  <li><p><?php if (isset($cause[$i][$j])): print($cause[$i][$j]); endif; ?></p></li>
                <?php endfor; ?>
              </ul>
              <a class="cause-link" href="#"><?php if (isset($cause['links'][$i])): print($cause['links'][$i]); endif; ?></a>
            </div> <!-- .cause-facts -->
          <?php endfor; ?>

        </div> <!-- .section-container -->
      </section> <!-- .cause -->

    <?php else: ?>

      <?php if (isset($shared)): ?>

        <section class="thanks" id="thanks">
          <div class="section-container">
            <h2><?php print($thanks[1]); ?></h2>
          </div> <!-- .section-container -->
        </section>

      <?php endif; ?>

      <section class="success" id="success">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-success.png'); ?>" alt="grand slam!" />
          <h1><?php print($success[1]); ?></h1>
          <h1><?php print($success[2]); ?></h1>
        </div> <!-- .section-container -->
      </section> <!-- .section -->

      <section class="share" id="share">
        <div class="section-container">

          <img class="bg-header" src="<?php print($files_source . 'h-share.png'); ?>" alt="spread the word" />
          <img class="bg-share" src="<?php print($files_source . 'bg-share.png'); ?>" alt="text message preview" />

            <?php
              $nid = 'node/' . $node->nid;
              $thanks_redirect_param = array(
                'query' => array(
                  'thanks' => NULL,
                )
              );
            ?>

            <form action="//dosomething.mcommons.com/profiles/join" method="POST">
              <input type="hidden" name="redirect_to" value="<?php print(url($nid, $thanks_redirect_param)); ?>" />

              <div class="share-alpha-name share-input-wrapper">
                <label>Your First Name:</label>
                <input class="share-input" type="text" name="person[first_name]" placeholder="Your name:"/>
              </div>

              <div class="share-alpha-mobile share-input-wrapper">
                <label>Your Cell #:</label>
                <input class="share-input" type="text" name="person[phone]" placeholder="You cell #:" />
              </div>

              <label class="share-beta-mobile">Friend's Cell #s:</label>

              <div class="share-input-wrapper">
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              </div>

              <div class="share-input-wrapper">
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
                <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              </div>

              <input type="hidden" name="opt_in_path" value="<?php print($alpha_opt_in); ?>" />
              <input type="hidden" name="friends_opt_in_path" value="<?php print($beta_opt_in); ?>" />

              <input type="submit" class="form-submit" value="invite friends" />

            </form>

            <div class="campaign-opt-in">

              <p>Message &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help.</p>

              <div class="official-rules-wrapper">
                <a class="official-rules-link" href="<?php print($files_source . 'official-rules.pdf'); ?>" target="_blank">official rules</a>
              </div> <!-- .official-rules-wrapper -->

            </div> <!-- .campaign-opt-in -->

        </div> <!-- .section-container -->

        <!--
        Edvisors tracking pixel
        @todo - Ideally this will be handled in a more automated fashion.  This
        can be achieved by Stashing the Edvisor offer id on the campaign and
        using a a standardize (but themable) webform confirmation page.
        @todo - add a http referrer check as well
        -->
        <!-- Offer Conversion: DoSomething.org -->
        <iframe src="http://tracking.edvisors.com/aff_l?offer_id=98" scrolling="no" frameborder="0" width="1" height="1"></iframe>
        <!-- // End Offer Conversion -->

      </section> <!-- .section -->
    <?php endif; ?>

    <section class="footer" id="footer">
      <div class="section-container">
        <p>Questions? E-mail <a href="mailto:<?php print($cmp_url); ?>@dosomething.org"><?php print($cmp_url); ?>@dosomething.org</a>!</p>
      </div>
    </section> <!-- .footer -->

  </div>
</div>
