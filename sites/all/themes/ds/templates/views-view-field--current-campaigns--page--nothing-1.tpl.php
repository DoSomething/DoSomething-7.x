<?php
/**
 * Set background color on current_campaigns view.
 */
if (!empty($row->field_field_campaign_background_color)) {
  print '<div class="campaigns-top" style="background-color:#' . $row->field_field_campaign_background_color[0]['raw']['safe_value'] . '">' . $output . '</div>';
}  
else {
  print '<div class="campaigns-top" style="background-color:#FFC756">' . $output . '</div>';
}
?>
