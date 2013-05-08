<div class="section" id="faq">
<?php foreach ($questions as $key => $question): ?>
  <h4<?php print ($key == 0) ? ' class="activeFAQ"': ''; ?>>
    <?php print $question['question']; ?>
  </h4>
  <div>
    <p><?php print $question['answer']; ?></p>
  </div>
<?php endforeach; ?>
</div>
