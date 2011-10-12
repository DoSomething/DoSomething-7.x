<div class="panel-twocol-a panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['left-top'] | $content['left-bottom-left'] | $content['left-bottom-right']): ?>
    <div class="panel-left panel-panel">
      <?php if ($content['left-top']): ?>
        <div class="panel-left-top panel-panel">
          <?php print $content['left-top']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['left-bottom-left'] | $content['left-bottom-right']): ?>
        <div class="panel-row-bottom">
          <?php if ($content['left-bottom-left']): ?>
            <div class="panel-bottom-left panel-panel">
              <?php print $content['left-bottom-left']; ?>
            </div>
          <?php endif; ?>
          <?php if ($content['left-bottom-right']): ?>
            <div class="panel-bottom-right panel-panel">
              <?php print $content['left-bottom-right']; ?>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </div>

    <?php if ($content['right']): ?>
      <div class="panel-right panel-panel">
        <?php print $content['right']; ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>
</div>
