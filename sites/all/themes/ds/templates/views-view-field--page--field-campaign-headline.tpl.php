<?php
/**
 * Set headline color on current_campaigns view.
 */
if (!empty($row->field_field_campaign_foreground_color)) {
  print '<div class="campaigns-headline" style="background-color:#' . $row->field_field_campaign_foreground_color[0]['raw']['safe_value'] . '">' . $output . '</div>';
}  
else {
  print '<div class="campaigns-headline" style="background-color:#D00012">' . $output . '</div>';
}
?>
