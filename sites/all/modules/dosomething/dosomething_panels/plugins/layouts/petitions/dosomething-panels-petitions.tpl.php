<div class="panel-petition panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top-left'] || $content['top-right']): ?>
    <div class="panel-row panel-row-top <?php print $top_row_classes?>">
      <?php if ($content['top-left']): ?>
        <div class="panel-first panel-panel">
           <?php print $content['top-left']; ?>
        </div>
      <?php endif; ?>

      <?php if ($content['top-right']): ?>
        <div class="panel-second panel-last panel-panel">
           <?php print $content['top-right']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['middle']): ?>
    <div class="panel-row panel-row-middle">
      <div class="panel-panel">
        <?php print $content['middle']; ?>
      </div>
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
</div>
