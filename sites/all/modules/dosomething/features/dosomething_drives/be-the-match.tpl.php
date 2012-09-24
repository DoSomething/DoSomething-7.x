<p>Email: <?php echo $email; ?></p>
<p>Cell:  <?php echo $mobile; ?></p>
<p>
Address:<br>
<?php echo $address_1; ?><br>
<?php if (!empty($address_2)) echo $address_2, '<br>'; ?>
<?php echo "$city, $state"; ?>
</p>
