<?php

/**
 * @file
 * Node template file for the Project content type.
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
