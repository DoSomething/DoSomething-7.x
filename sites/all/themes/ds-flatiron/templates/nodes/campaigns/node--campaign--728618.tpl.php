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
        <?php /* FIXME - OFFICIAL RULES LINK ON FILES SERVER */ ?>
        <a class="official-rules" href="<?php print($files_source . 'official-rules.pdf'); ?>">official rules</a>

        <div class="contact-form contact-form-individual">
          <?php print render($content['contact']['individual']); ?>
        </div>  <!-- .contact-form (individual) -->

        <div class="contact-form contact-form-group">
          <?php print render($content['contact']['team']); ?>
        </div>  <!-- .contact-form (group) -->

        <div class="report-back">
          <h2><?php print($scholarship[1]); ?></h2>
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

    <section class="footer">
      <div class="section-container">
        <p>Questions? E-mail <a href="mailto:<?php print($cmp_url); ?>@dosomething.org"><?php print($cmp_url); ?>@dosomething.org</a>!</p>
      </div>
    </section> <!-- .footer -->

  </div>
</div>
