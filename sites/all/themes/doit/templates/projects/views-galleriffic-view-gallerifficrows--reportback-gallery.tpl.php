<?php
/**
 * @file
 * template for views galleriffic row
 */
?>
<?php if ($fields['slide']->content): ?>
  <li class="gallery-thumb">
    <a class="thumb" href="<?php print $fields['slide']->content; ?>" title="<?php  if($fields['title']) { print $fields['title']->stripped;} ?>" name="<?php if($fields['title']) { print $fields['title']->stripped; }?>"><img src="<?php print $fields['thumbnail']->content; ?>" alt="<?php  if($fields['title']) { print $fields['title']->stripped; } ?>" /></a>
  </li>
<?php endif; ?>
