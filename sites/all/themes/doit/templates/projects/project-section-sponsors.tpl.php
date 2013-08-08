<footer class="sponsor full-width" id="sponsor">
  <h3>Sponsored by:</h3>

  <p>
  	<?php foreach ($sponsors as $sponsor): ?>
    <a href="<?php print $sponsor['url']; ?>"> <img src="<?php print $sponsor['image']['uri']; ?>"" alt="<?php print $sponsor['image']['alt']; ?>""></a>
    <?php endforeach; ?>
  </p>
</footer>