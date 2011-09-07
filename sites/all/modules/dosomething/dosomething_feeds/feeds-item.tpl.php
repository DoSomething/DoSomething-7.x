<?php dpm($item); ?>
<item>
  <title><?php print $item->node_title;  ?></title>
  <link><?php print $item->path ?></link>
  <pubDate><?php print date('r', $item->node_created); ?></pubDate>
  <description><![CDATA[<?php print strip_tags($item->field_body[0]['rendered']['#markup']); ?>]]></description>

  <?php foreach ($item->term_paths as $term_path) { ?>
    <category domain="<?php print $term_path['path'] ?>"><?php print $term_path['title'] ?></category>
  <?php } ?>
<?php 
//TODO: There should be media here: either images from the node or video links. EXAMPLE:
//<media:content url="http://www.dosomething.org/files/imagecache/140x105/files/pictures/actionguide/
//print $feed_item->filename  
//" type="
//print $feed_item->filemime  
//" width="140" height="105"></media:content>
?>
<content:encoded><![CDATA[<?php print $item->field_body[0]['rendered']['#markup']; ?>]]></content:encoded>
<guid><?php print $item->path ?></guid>
</item>
