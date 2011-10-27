<div class="panel-one-two panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel panel-full">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="panel-row-bottom panel-row <?php print $bottom_row_classes; ?>">
      <?php if ($content['left']): ?>
        <div class="panel-first panel-panel">
          <?php print $content['left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['right']): ?>
        <div class="panel-second panel-last panel-panel">
          <?php print $content['right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
