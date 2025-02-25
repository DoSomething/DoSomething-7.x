<div class="panel-one-three-two panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel panel-full panel-row">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['mid-left'] || $content['mid-center'] || $content['mid-right']): ?>
    <div class="panel-row panel-row-middle <?php print $mid_row_classes?>">
      <?php if ($content['mid-left']): ?>
        <div class="panel-first panel-panel">
           <?php print $content['mid-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-center']): ?>
        <div class="panel-second panel-panel">
           <?php print $content['mid-center']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['mid-right']): ?>
        <div class="panel-third panel-last panel-panel">
           <?php print $content['mid-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['bottom-left'] || $content['bottom-right']): ?>
    <div class="panel-row panel-row-bottom <?php print $bottom_row_classes?>">
      <?php if ($content['bottom-left']): ?>
        <div class="panel-first panel-panel">
           <?php print $content['bottom-left']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['bottom-right']): ?>
        <div class="panel-second panel-last panel-panel">
           <?php print $content['bottom-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['footer']): ?>
    <div class="panel-footer panel-panel panel-full panel-row">
      <?php print $content['footer']; ?>
    </div>
  <?php endif; ?>

</div>
