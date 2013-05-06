<?php

$name = check_plain($row->_field_data['sid']['entity']->data[2]['value'][0]);
$shelter = check_plain($row->_field_data['sid']['entity']->data[4]['value'][0]);
$state = check_plain($row->_field_data['sid']['entity']->data[5]['value'][0]);
$link = l(t("$shelter, $state"), 'http://www.petfinder.com/awo/index.cgi?location=' . $state . '&keyword=' . urlencode($shelter));

?>

<div class="crazy-submission s-<?php echo $row->sid; ?> a-<?php echo $row->users_webform_submissions_uid; ?>">
<div class="pet-name pn-<?php echo $row->sid; ?>"><?php echo t("$name, $state"); ?></div>
<div class="fb-and-pic">
<?php if (user_access('flag campaign submissions')): ?><div class="flag"><a href="/cas/<?php echo $campaign; ?>/flag/<?php echo $row->sid; ?>" data-sid="<?php echo $row->sid; ?>"><span><?php echo t('Flag'); ?></span></a></div><?php endif; ?>
<div class="fb-picture"></div>
<div class="s-<?php echo $row->sid; ?>-picture simg"><?php echo theme('image_style', array('style_name' => 'crazy_image_dimensions', 'path' => $row->field_field_cas_image[0]['rendered']['#item']['uri'], 'width' => 480, 'height' => 480)); ?></div>
</div>
<!-- buttons -->
<div class="buttons">
	<?php echo t("Adopt !name at !shelter", array('!name' => $name, '!shelter' => $link)); ?>
</div> <!-- end buttons -->
<p class="author"><?php echo $row->field_field_user_first_name[0]['rendered']['#markup']; ?></p>
<div class="dateline"><?php echo $row->webform_submissions_submitted; ?></div>
</div>