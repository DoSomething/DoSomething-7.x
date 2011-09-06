<item>
<title><?php print $item->node_title;  ?></title>
<link><?php //print url($item['path'], $options = array('absolute' => TRUE,));  ?></link>
<pubDate><?php print date('r', $item->node_created); ?></pubDate>
<description><![CDATA[<?php print strip_tags($item->field_body[0]['rendered']['#markup']); ?>]]></description>
<?php
foreach ($view->result[$key]->field_taxonomy_vocabulary_5 as $term) {
  $tid = $term['raw']['tid'];
  $parent = "";
  $parents = taxonomy_get_parents($tid);
  $first = reset($parents);
  if ($first) {
    $parent = str_replace(" ", "+", $first->name . "/");
  }
  $main_part = str_replace(" ", "+", $term['rendered']['#title']);
  //print '<category domain="http://www.dosomething.org/whatsyourthing/' .  $parent . $main_part  '">' . $term['rendered']['#title'] . '</category>';
}
?>
<?php //TODO: There should be media here: either images from the node or video links. EXAMPE:
//<media:content url="http://www.dosomething.org/files/imagecache/140x105/files/pictures/actionguide/
//print $feed_item->filename  
//" type="
//print $feed_item->filemime  
//" width="140" height="105"></media:content>
?>
<content:encoded><![CDATA[<?php print $item->field_body[0]['rendered']['#markup']; ?>]]></content:encoded>
<guid><?php //print $item['path']; ?></guid>
</item>
