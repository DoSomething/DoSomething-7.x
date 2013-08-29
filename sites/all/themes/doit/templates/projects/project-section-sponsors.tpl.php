<?php foreach ($sponsors as $sponsor): ?>
<?php if (isset($sponsor['url'])): ?><a href="<?php print $sponsor['url']; ?>" target="_blank"><?php endif; ?>
<img src="<?php print $sponsor['image']['uri']; ?>"" alt="<?php print $sponsor['image']['alt']; ?>"">
<?php if (isset($sponsor['url'])): ?></a><?php endif; ?>
<?php endforeach; ?>
