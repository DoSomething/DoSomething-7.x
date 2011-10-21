<?php
if ($content['left-top'] | $content['left-bottom-left'] | $content['left-bottom-right']) {
  $outer_row_classes[] = 'outer-first';
}
if ($content['right']) {
  $outer_row_classes[] = 'outer-second';
}
$outer_row_classes[] = 'panes-' . count($outer_row_classes);
if ((($content['left-top'] | $content['left-bottom-left'] | $content['left-bottom-right'])) && $content['right']) {
  $outer_row_classes[] = 'both';
}
$outer_row_classes = implode(" ", $outer_row_classes);


if ($content['bottom-left']) {
  $bottom_row_classes[] = 'bottom-first';
}
if ($content['bottom-right']) {
  $bottom_row_classes[] = 'bottom-second';
}
$bottom_row_classes[] = 'panes-' . count($bottom_row_classes);
if ($content['bottom-left'] && $content['bottom-right']) {
  $bottom_row_classes[] = 'both';
}
$bottom_row_classes = implode(" ", $bottom_row_classes);

?>

<div class="panel-twocol-a panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-row panel-row-outer <?php print $outer_row_classes?>">

    <?php if ($content['left-top'] | $content['left-bottom-left'] | $content['left-bottom-right']): ?>
      <div class="panel-outer-left panel-panel">
        <?php if ($content['left-top']): ?>
          <div class="panel-top panel-panel">
            <?php print $content['left-top']; ?>
          </div>
        <?php endif; ?>

        <?php if ($content['left-bottom-left'] | $content['left-bottom-right']): ?>
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
