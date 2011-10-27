<div class="panel-twocol-a panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-row panel-row-outer <?php print $outer_row_classes?>">

    <?php if (isset($content['left-top']) || isset($content['left-bottom-left']) || isset($content['left-bottom-right'])): ?>
      <div class="panel-outer-left panel-panel">
        <?php if ($content['left-top']): ?>
          <div class="panel-top panel-panel panel-full">
            <?php print $content['left-top']; ?>
          </div>
        <?php endif; ?>

        <?php if (isset($content['left-bottom-left']) || isset($content['left-bottom-right'])): ?>
          <div class="panel-row panel-row-bottom <?php print $bottom_row_classes?>">
            <?php if ($content['left-bottom-left']): ?>
              <div class="panel-first panel-panel">
                <?php print $content['left-bottom-left']; ?>
              </div>
            <?php endif; ?>
            <?php if ($content['left-bottom-right']): ?>
              <div class="panel-second panel-last panel-panel">
                <?php print $content['left-bottom-right']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>

      <?php if ($content['right']): ?>
        <div class="panel-outer-right panel-panel">
          <?php print $content['right']; ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>
  </div>
</div>
