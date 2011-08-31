<item>
<title><?php print $row['title'];  ?></title>';
<link><?php print url($row['path'], $options = array('absolute' => TRUE,));  ?></link>';
<pubDate><?php print $row['created']  ?></pubDate>';
<description><![CDATA[<?php print strip_tags($row['body'])  ?>]]></description>';

foreach ($view->result[$key]->field_taxonomy_vocabulary_5 as $term) {
  $tid = $term['raw']['tid'];
  $parent = "";
  $parents = taxonomy_get_parents($tid);
  $first = reset($parents);
  if ($first) {
    $parent = str_replace(" ", "+", $first->name . "/");
  }
  $main_part = str_replace(" ", "+", $term['rendered']['#title']);
  $items .= '<category domain="http://www.dosomething.org/whatsyourthing/<?php print $parent . $main_part  ?>"><?php print $term['rendered']['#title']  ?></category>';
}
//TODO: There should be media here: either images from the node or video links. EXAMPE:
//<media:content url="http://www.dosomething.org/files/imagecache/140x105/files/pictures/actionguide/<?php print $feed_item->filename  ?>" type="<?php print              $feed_item->filemime  ?>" width="140" height="105"></media:content>
$items .= '<content:encoded><![CDATA[<?php print $row['body']  ?>]]></content:encoded>';
$items .= '<guid><?php print $row['path']  ?></guid>';
$items .= '</item>';
}

