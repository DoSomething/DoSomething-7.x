<div class="panel-one-three-two panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>
  <?php if ($content['mid-left'] | $content['mid-center'] | $content['mid-right']): ?>
    <div class="panel-row panel-row-middle">
      <?php if ($content['mid-left']): ?>
        <div class="panel-mid-left panel-panel">
           <?php print $content['mid-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-center']): ?>
        <div class="panel-mid-center panel-panel">
           <?php print $content['mid-center']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-right']): ?>
        <div class="panel-mid-right panel-panel">
           <?php print $content['mid-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if ($content['bottom-left'] | $content['bottom-right']): ?>
    <div class="panel-row panel-row-bottom">
      <?php if ($content['bottom-left']): ?>
        <div class="panel-bottom-left panel-panel">
           <?php print $content['bottom-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['bottom-right']): ?>
        <div class="panel-bottom-right panel-panel">
           <?php print $content['bottom-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
