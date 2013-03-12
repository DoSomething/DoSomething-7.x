<ul id="contacts">
<?php

$i = 0;
foreach ($contacts AS $e => $s) {
  echo '
  <li>
    <input type="checkbox" class="email-checkbox" checked="checked" name="emails[' . $i  .']" value="' . $s['email'] . '" />
    <strong>' . $s['email'] . '</strong>
    <span>' . $s['name'] . '</span>
  </li>';
  $i++;
}

?>
</ul>