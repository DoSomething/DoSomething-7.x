<div class="panel-one-two-one panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>
  <?php if ($content['mid-left'] | $content['mid-right']): ?>
    <div class="panel-row panel-row-middle">
      <?php if ($content['mid-left']): ?>
        <div class="panel-mid-left panel-panel">
           <?php print $content['mid-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-right']): ?>
        <div class="panel-mid-right panel-panel">
           <?php print $content['mid-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if ($content['bottom']): ?>
    <div class="panel-bottom panel-panel">
      <?php print $content['bottom']; ?>
    </div>
  <?php endif; ?>
</div>
