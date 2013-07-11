<?php if ($is_scholarship): ?>
  <h1 class="condensed scholarship-title">
    <div><?php echo t('Share this stat with six friends for a chance to win a'); ?></div>
    <?php echo $scholarship_copy; ?>
  </h1>
<?php else: ?>
  <h1 class="condensed scholarship-title"><?php echo t('Share this stat with six friends'); ?></h1>
<?php endif; ?>

<div class="quote-highlight">
  <p><?php echo $stat_tip; ?></p>
</div><!-- quote-highlight -->
