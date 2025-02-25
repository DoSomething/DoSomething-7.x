<div class="panel-one-two-one panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel panel-full">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['mid-left'] || $content['mid-right']): ?>
    <div class="panel-row panel-row-middle <?php print $mid_row_classes; ?>">
      <?php if ($content['mid-left']): ?>
        <div class="panel-first panel-panel">
           <?php print $content['mid-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-right']): ?>
        <div class="panel-second panel-last panel-panel">
           <?php print $content['mid-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['bottom']): ?>
    <div class="panel-bottom panel-panel panel-full">
      <?php print $content['bottom']; ?>
    </div>
  <?php endif; ?>
</div>
