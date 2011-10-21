<?php
if ($content['mid-left']) {
  $mid_row_classes[] = 'mid-first';
}
if ($content['mid-right']) {
  $mid_row_classes[] = 'mid-second';
}
$mid_row_classes[] = 'panes-' . count($mid_row_classes);
if ($content['mid-left'] && $content['mid-right']) {
  $mid_row_classes[] = 'both';
}
$mid_row_classes = implode(" ", $mid_row_classes);
?>

<div class="panel-one-two-one panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-top panel-panel">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['mid-left'] | $content['mid-right']): ?>
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
    <div class="panel-bottom panel-panel">
      <?php print $content['bottom']; ?>
    </div>
  <?php endif; ?>
</div>
