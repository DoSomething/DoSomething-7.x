<div class="panel-campaign panel-display ds-panel" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if (isset($content['top-first-top-first']) || isset($content['top-first-top-second']) || isset($content['top-first-bottom']) || isset($content['top-second'])): ?>
    <div class="panel-row-top panel-row <?php print $top_row_classes?>">

      <?php if (isset($content['top-first-top-first']) || isset($content['top-first-top-second']) || isset($content['top-first-bottom'])): ?>
        <div class="panel-row-top-first panel-row">

          <?php if (isset($content['top-first-top-first']) || isset($content['top-first-top-second'])): ?>
            <div class="panel-row-top-first-top panel-row <?php print $top_first_top_classes?>">

              <?php if ($content['top-first-top-first']): ?>
                <div class="panel-top-first-top-first panel-panel"><?php print $content['top-first-top-first']; ?></div>
              <?php endif; ?>

              <?php if ($content['top-first-top-second']): ?>
                <div class="panel-top-first-top-second panel-last panel-panel"><?php print $content['top-first-top-second']; ?></div>
              <?php endif; ?>

            </div>
          <?php endif; ?>

          <?php if ($content['top-first-bottom']): ?>
            <div class="panel-top-first-bottom panel-full panel-panel"><?php print $content['top-first-bottom']; ?></div>
          <?php endif; ?>

        </div>
      <?php endif; ?>

      <?php if ($content['top-second']): ?>
        <div class="panel-top-second panel-top-last panel-panel"><?php print $content['top-second']; ?></div>
      <?php endif; ?>

    </div>
  <?php endif; ?>

  <?php if (isset($content['middle-first']) || isset($content['middle-second']) || isset($content['middle-third'])): ?>
    <div class="panel-row-middle panel-row <?php print $middle_row_classes?>">
      <?php if ($content['middle-first']): ?>
        <div class="panel-middle-first panel-panel">
          <?php print $content['middle-first']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['middle-second']): ?>
        <div class="panel-middle-second panel-panel">
          <?php print $content['middle-second']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['middle-third']): ?>
        <div class="panel-middle-third panel-last panel-panel">
          <?php print $content['middle-third']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['low-full']): ?>
    <div class="panel-low-full panel-panel"><?php print $content['low-full']; ?></div>
  <?php endif; ?>

  <?php if (isset($content['bottom-first']) || isset($content['bottom-second'])): ?>
    <div class="panel-row-bottom panel-row <?php print $bottom_row_classes?>">
      <?php if ($content['bottom-first']): ?>
        <div class="panel-bottom-first panel-panel">
          <?php print $content['bottom-first']; ?>
        </div>
      <?php endif; ?>
      <?php if ($content['bottom-second']): ?>
        <div class="panel-bottom-second panel-last panel-panel">
          <?php print $content['bottom-second']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

</div>
