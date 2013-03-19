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
    
    <?php if(!isset($complete)): ?>

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
          <div class="official-rules">
            <a href="<?php print($files_source . 'official-rules.pdf'); ?>">official rules</a>
          </div> <!-- .official-rules -->

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

      <section class="success">
        <div class="section-container">
          <img class="bg-header" src="<?php print($files_source . 'h-success.png'); ?>" alt="grand slam!" />
          <h1><?php print($success[1]); ?></h1>
          <h1><?php print($success[2]); ?></h1>
        </div> <!-- .section-container -->
      </section> <!-- .section -->
    
      <section class="share">
        <div class="section-container">

          <div class="refer5">
          <div class="refer5-inner">  
            <img class="scholar-copy" src="//files.dosomething.org/files/campaigns/alcoa/scholarship-copy.png" alt="share this fact">

            <form action="//dosomething.mcommons.com/profiles/join" method="POST">
              <input type="hidden" name="redirect_to" value="http://www.dosomething.org/redirect-with-message?destination=teensforjeans&message=Thanks%20for%20entering%20the%20Teens%20for%20Jeans%20scholarship.%20Sign%20up%20below%20to%20run%20a%20drive%20and%20be%20eligible%20for%20awesome%20prizes!" />
              <div class="scholar-input your-input">
                <label>Your First Name:</label>
                <input type="text" name="person[first_name]" class="field space-after" placeholder="Your name:"/>
              </div>
              <div class="scholar-input your-input">
                <label>Your Cell #:</label>
                <input type="text" name="person[phone]" class="field space-after" placeholder="You cell #:" />
              </div>
              <img src="//files.dosomething.org/files/campaigns/alcoa/line.png" alt="line">
              <label class="friends">Friend's Cell #'s:</label>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="text" class="field left" name="friends[]" placeholder="Friend's cell #:"/>
              <input type="hidden" name="friends_opt_in_path" value="134511" />
              <input type="hidden" name="opt_in_path" value="134501" />
              <input type="submit" class="go-button" value="Submit" />
            </form> 


            <div id="campaign-opt-in"><span class="ctia_bottom">
              <a class="rules" href="//files.dosomething.org/files/campaigns/jeans12/2013_offical_rules.pdf">Official Rules.</a> 
              Msg &amp; data rates may apply. Text <strong>STOP</strong> to opt-out, <strong>HELP</strong> for help. </span>
            </div>

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
