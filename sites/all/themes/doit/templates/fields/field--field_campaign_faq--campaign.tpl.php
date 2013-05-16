<section class="faq section" id="faq">
  <h2 class="section-header"><span>Frequently Asked Questions</span></h2>
  <?php foreach ($questions as $key => $question): ?>
  <h3<?php print ($key == 1) ? ' class="active"': ''; ?>>
    <?php print $question['question']; ?>
  </h3>
  <div>
    <p><?php print $question['answer']; ?></p>
  </div>
  <?php endforeach; ?>
  <a class="btn btn-cta-large jump-scroll" href="#scholarship"><span>I want to play</span></a>
  <p class="back-to-top"><a class="top-btn jump-scroll" href="#utility-bar">Back to Top</a></p>
</section>
