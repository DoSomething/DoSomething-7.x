<item>
  <title><?php print check_plain($item->node_title)  ?></title>
  <link><?php print check_plain($item->path) ?></link>
  <pubDate><?php print date('r', $item->node_created); ?></pubDate>
  <description><![CDATA[<?php print strip_tags($item->field_body[0]['rendered']['#markup']); ?>]]></description>

  <?php foreach ($item->term_paths as $term_path) { ?>
    <category domain="<?php print check_plain($term_path['path']) ?>"><?php print check_plain($term_path['title']) ?></category>
  <?php } ?>
  <?php 
    //TODO: There should be media here: either images from the node or video links. EXAMPLE:
    foreach ($item->images as $image) {
  ?>
      <media:content url="<?php print $image['path']?>" type="<?php print $image['mime']?>" width="<?php print $image['width']?>" height="<?php print $image['height']?>"></media:content>
  <?php
    }
  ?>
<content:encoded><![CDATA[<?php print $item->field_body[0]['rendered']['#markup']; ?>]]></content:encoded>
<guid><?php print check_plain($item->path) ?></guid>
</item>
