<div class="panel-one-two panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="panel-bottom">
      <?php if ($content['left']): ?>
        <div class="panel-first panel-panel">
          <?php print $content['left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['right']): ?>
        <div class="panel-last panel-panel">
          <?php print $content['right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
