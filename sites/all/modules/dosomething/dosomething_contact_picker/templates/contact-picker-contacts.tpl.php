<?php if ($close): ?>
<div id="return">
<?php endif; ?>

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

<?php if ($close): ?>
</div>

<script type="text/javascript">
<!--
	window.opener.DS.ContactPicker.load_data(document.getElementById('return').innerHTML);
	window.close();
-->
</script>
<?php endif; ?>