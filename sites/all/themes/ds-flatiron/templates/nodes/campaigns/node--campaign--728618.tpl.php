<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>

    <?php
      
      require('node-field-variables.php');

    ?>

    <section class="header">
      <div class="section-container">
        <a class="logo-dosomething" href="//www.dosomething.org/">
          <img src="<?php print($files_source . 'logo-ds.png'); ?>" alt="DoSomething.org logo" />
        </a>
        <a class="log-out" href="/user/logout">log out</a>
        <img class="logo-campaign" src="<?php print($files_source . 'logo-' . $cmp_short . '.png'); ?>" alt="<?php print($cmp_name); ?> logo" />
        <?php if ($sponsor): ?>
          <img class="logo-sponsor" src="<?php print($files_source . 'logo-' . $sponsor . '.png'); ?>" alt="<?php print($sponsor); ?> logo" />
        <?php endif; ?>
      </div> <!-- .section-container -->
    </section> <!-- .header -->
    
    <?php if (!isset($complete)): ?>

      <?php /* TODO - PREVENT THOSE WHO HAVEN'T SUBMITTED THE REPORT BACK FROM FROM SEEING THIS SECTION */ ?>

      <section class="project">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-project.png') ?>" alt="The Project" />
          <h1><?php print($project[1]); ?></h1>
          <h1><?php print($project[2]); ?></h1>
        </div> <!-- .section-container -->
      </section> <!-- .project -->

      <section class="challenge">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-challenge.png'); ?>" alt="your challenge" />
          <h2><?php print($challenge[1]); ?></h2>
          <h2><?php print($challenge[2]); ?></h2>
        </div> <!-- .section-container -->
      </section> <!-- .challenge -->

      <section class="scholarship">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-scholarship.png'); ?>" alt="scholarship" />
          <h2><?php print($scholarship[1]); ?></h2>
          <h2><?php print($scholarship[2]); ?></h2>
          <div class="official-rules-wrapper">
            <a class="official-rules-link" href="<?php print($files_source . 'official-rules.pdf'); ?>">official rules</a>
          </div> <!-- .official-rules-wrapper -->

          <div class="contact-form contact-form-individual">
            <?php print render($content['contact']['individual']); ?>
          </div>  <!-- .contact-form (individual) -->

          <div class="contact-form contact-form-group">
            <?php print render($content['contact']['team']); ?>
          </div>  <!-- .contact-form (group) -->

          <div class="report-back-form">
            <h2><?php print($scholarship[2]); ?></h2>
            <?php print render($content['report_back']); ?>
          </div>  <!-- .report_back -->

        </div> <!-- .section-container -->
      </section> <!-- .scholarship -->

      <section class="cause">
        <div class="section-container">

          <?php for ($i=1;$i<5;$i++): ?>
            <div class="cause-facts <?php if($i == 1){ print("active-fact"); } ?>">
              <img class="bg-header" src="<?php print($files_source . 'h-cause' . $i . '.png'); ?>" alt="why <?php print($cause_subject); ?>?" />
              <ul>
                <?php for ($j=1;$j<5;$j++): ?>
                  <li><p><?php print($cause[$i][$j]); ?></p></li>
                <?php endfor; ?>
              </ul>
              <a class="cause-link" href="#"><?php print($cause['links'][$i]); ?></a>
            </div> <!-- .cause-facts -->
          <?php endfor; ?>

        </div> <!-- .section-container -->
      </section> <!-- .cause -->

    <?php else: ?>

      <?php if (isset($shared)): ?>

        <section class="thanks">
          <div class="section-container">
            <h2><?php print($thanks[1]); ?></h2>
          </div> <!-- .section-container -->
        </section>

      <?php endif; ?>

      <section class="success">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-success.png'); ?>" alt="grand slam!" />
          <h1><?php print($success[1]); ?></h1>
          <h1><?php print($success[2]); ?></h1>
        </div> <!-- .section-container -->
      </section> <!-- .section -->
    
      <section class="share">
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

              <div class="share-alpha-name share-alpha-wrapper">
                <label>Your First Name:</label>
                <input class="share-input" type="text" name="person[first_name]" placeholder="Your name:"/>
              </div>

              <div class="share-alpha-mobile share-alpha-wrapper">
                <label>Your Cell #:</label>
                <input class="share-input" type="text" name="person[phone]" placeholder="You cell #:" />
              </div>

              <label class="share-beta-mobile">Friend's Cell #s:</label>

              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>
              <input class="share-input" type="text" name="friends[]" placeholder="Friend's cell #:"/>

              <input type="hidden" name="opt_in_path" value="<?php print($alpha_opt_in); ?>" />
              <input type="hidden" name="friends_opt_in_path" value="<?php print($beta_opt_in); ?>" />

              <input type="submit" class="form-submit" value="invite friends" />

            </form> 

            <div class="campaign-opt-in">

              <p>Message &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help.</p>

              <div class="official-rules-wrapper">
                <a class="official-rules-link" href="<?php print($files_source . 'official-rules.pdf'); ?>">official rules</a>
              </div> <!-- .official-rules-wrapper -->

            </div> <!-- .campaign-opt-in -->

        </div> <!-- .section-container -->
      </section> <!-- .section -->
    <?php endif; ?>

    <section class="footer">
      <div class="section-container">
        <p>Questions? E-mail <a href="mailto:<?php print($cmp_url); ?>@dosomething.org"><?php print($cmp_url); ?>@dosomething.org</a>!</p>
      </div>
    </section> <!-- .footer -->

  </div>
</div>
