<?php

$name = check_plain($row->_field_data['sid']['entity']->data[2]['value'][0]);
$shelter = check_plain($row->_field_data['sid']['entity']->data[4]['value'][0]);
$state = check_plain($row->_field_data['sid']['entity']->data[5]['value'][0]);
$link = l(t("$shelter, $state"), 'http://www.petfinder.com/awo/index.cgi?location=' . $state . '&keyword=' . urlencode($shelter));
$promoted = (bool) $row->_field_data['sid']['entity']->field_cas_promoted[LANGUAGE_NONE][0]['value'];
$adopted = (bool) !empty($row->_field_data['sid']['entity']->data[6]['value'][0]);
$blurb = check_plain($row->_field_data['sid']['entity']->data[7]['value'][0]);

?>

<div class="crazy-submission s-<?php echo $row->sid; ?> a-<?php echo $row->users_webform_submissions_uid; ?>">
<?php if ($promoted): ?><div class="promoted-flag"><span><?php echo t('Promoted'); ?></span></div><?php endif; ?>
<div class="pet-name pn-<?php echo $row->sid; ?>"><?php echo t("$name, $state"); ?></div>
<div class="shares">
	<a class="facebook-share fb-<?php echo $row->sid; ?>" data-sid="<?php echo $row->sid; ?>" href="#"><span>Facebook</span></a>
	<span class="fb-<?php echo $row->sid; ?>-count">0</span>
</div>

<div class="fb-and-pic">
<?php if (user_access('flag campaign submissions')): ?><div class="flag"><a href="/cas/<?php echo $campaign; ?>/flag/<?php echo $row->sid; ?>" data-sid="<?php echo $row->sid; ?>"><span><?php echo t('Flag'); ?></span></a></div><?php endif; ?>
<div class="s-<?php echo $row->sid; ?>-picture simg">
	<?php if ($adopted): ?><div class="adopted"><span><?php echo t('Adopted'); ?></span></div><?php endif; ?>
	<?php echo theme('image_style', array('style_name' => $settings['fields']['picture']['style'], 'path' => $row->field_field_cas_image[0]['rendered']['#item']['uri'])); ?>
</div>
</div>
<!-- buttons -->
<div class="buttons">
	<?php echo t("Adopt !name at !shelter", array('!name' => $name, '!shelter' => $link)); ?>
	<?php if (!empty($blurb)): ?><p><?php echo $blurb; ?></p><?php endif; ?>
</div> <!-- end buttons -->
<p class="author"><?php echo $row->field_field_user_first_name[0]['rendered']['#markup']; ?></p>
<div class="dateline"><?php echo $row->webform_submissions_submitted; ?></div>
</div>