<div class="panel-two-three panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top-left'] | $content['top-right']): ?>
    <div class="panel-row panel-row-top">
      <?php if ($content['top-left']): ?>
        <div class="panel-top-left panel-panel">
           <?php print $content['top-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['top-right']): ?>
        <div class="panel-top-right panel-panel">
           <?php print $content['top-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if ($content['bottom-left'] | $content['bottom-center'] | $content['bottom-right']): ?>
    <div class="panel-row panel-row-bottom">
      <?php if ($content['bottom-left']): ?>
        <div class="panel-bottom-left panel-panel">
           <?php print $content['bottom-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['bottom-center']): ?>
        <div class="panel-bottom-center panel-panel">
           <?php print $content['bottom-center']; ?>
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
