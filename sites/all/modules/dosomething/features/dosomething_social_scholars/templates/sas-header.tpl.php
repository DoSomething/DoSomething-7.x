<?php if ($is_scholarship): ?>
  <img class="scholar-copy" src="//files.dosomething.org/files/u/awesome-things/scholarship-copy2.png" alt="share this fact" />
  <h1 class="condensed"><?php echo $scholarship_copy; ?></h1>
<?php else: ?>
  <h1 class="condensed non-scholarship"><?php echo t('Share this stat with six friends'); ?></h1>
<?php endif; ?>

<div class="quote-highlight">
  <p><?php echo $stat_tip; ?></p>
</div><!-- quote-highlight -->    