<rss version="2.0"
  xmlns:content="http://purl.org/rss/1.0/modules/content/"
  xmlns:wfw="http://wellformedweb.org/CommentAPI/"
  xmlns:dc="http://purl.org/dc/elements/1.1/"
  xmlns:atom="http://www.w3.org/2005/Atom"
  xmlns:media="http://search.yahoo.com/mrss/">
  <channel>
    <title><?php print $title ?></title>
    <atom:link href="<?php print url(current_path(), array('absolute' => TRUE)) ?>" rel="self" type="application/rss+xml" />
    <link><?php print url(current_path(), array('absolute' => TRUE)) ?></link>
    <description><?php print $description ?></description>
    <pubDate><?php print date('r', REQUEST_TIME); ?></pubDate>
    <language>en</language>
    <items>
      <?php 
        foreach ($items as $item) {
          print $item;
        }
      ?>
    </items>
  </channel>
</rss>
