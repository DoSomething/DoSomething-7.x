<div class="panel-campaign panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if (isset($content['logo']) || isset($content['mini-info']) || isset($content['social'])): ?>
    <div class="panel-row-top panel-row <?php print $top_row_classes; ?>">

      <?php if (isset($content['logo'])): ?>
        <div class="panel-row-top-logo panel-panel">
          <?php print $content['logo']; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($content['mini-info']) || isset($content['social'])): ?>
        <div class="panel-row-top-right panel-row panel-row-right <?php print $top_right_classes; ?>">

          <?php if (isset($content['mini-info'])): ?>
            <div class="panel-top-right-mini-info panel-panel"><?php print $content['mini-info']; ?></div>
          <?php endif; ?>

          <?php if (isset($content['social'])): ?>
            <div class="panel-top-right-social panel-last panel-panel"><?php print $content['social']; ?></div>
          <?php endif; ?>

        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['sign-up']) || isset($content['stats'])): ?>
    <div class="panel-row-actions panel-row <?php print $actions_classes?>">
      <?php if (isset($content['sign-up'])): ?>
        <div class="panel-row-actions-sign-up panel-panel"><?php print $content['sign-up']; ?></div>
      <?php endif; ?>
      <?php if (isset($content['stats'])): ?>
        <div class="panel-row-actions-stats panel-panel"><?php print $content['stats']; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['quick-info']) || isset($content['psa'])): ?>
    <div class="panel-row-ad panel-row <?php print $ad_classes; ?>">
      <?php if (isset($content['quick-info'])): ?>
        <div class="panel-row-ad-quick-info panel-panel"><?php print $content['quick-info']; ?></div>
      <?php endif; ?>
      <?php if (isset($content['psa'])): ?>
        <div class="panel-row-ad-psa panel-panel"><?php print $content['psa']; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['flexible-top'])):?>
    <div class="panel-row-flexible panel-row-flexible-top panel-row panel-panel">
      <?php print $content['flexible-top']; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['flexible-mid'])):?>
    middle
    <div class="panel-row-flexible panel-row-flexible-mid panel-row panel-panel">
      <?php print $content['flexible-mid']; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['flexible-bot'])):?>
    bottom
    <div class="panel-row-flexible panel-row-flexible-bot panel-row panel-panel">
      <?php print $content['flexible-bot']; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($content['logos'])):?>
    <div class="panel-row-logos panel-row panel-panel">
      <?php print $content['logos']; ?>
    </div>
  <?php endif; ?>

</div>
