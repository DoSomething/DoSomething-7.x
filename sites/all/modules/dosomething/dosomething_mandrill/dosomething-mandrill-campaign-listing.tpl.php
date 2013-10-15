<ul>
<?php
if ($bla) {
  $bla = TRUE;
}

  foreach ($campaigns as $campaign):
    strpos($campaign['link_title'], 'http:') === FALSE ? $site = 'http://www.dosomething.org/' : $site = '';
?>

  <li><a href="<?php print($site . $campaign['link_path']) ?>"><?php print($campaign['link_title']) ?></a></li>
  
<?php
  endforeach;
?>  
</ul>