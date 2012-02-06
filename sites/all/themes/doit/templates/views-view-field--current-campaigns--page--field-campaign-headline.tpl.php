<?php
/**
 * Set background color on current_campaigns view.
 */
if (!empty($row->field_field_campaign_foreground_color)) {
  print '<div class="campaigns-headline-container" style="background-color:#' . $row->field_field_campaign_foreground_color[0]['raw']['safe_value'] . '">' . $output . '</div>';
}  
else {
  print '<div class="campaigns-headline-container" style="background-color:#FFC756">' . $output . '</div>';
}
?>
