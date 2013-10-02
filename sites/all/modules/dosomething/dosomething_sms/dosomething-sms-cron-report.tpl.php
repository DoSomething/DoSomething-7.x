<?php

	// Loop through results          
	foreach ($workflows as $workflow_name => $workflow) {

		$max_y = $workflows[$workflow_name]['max_y'];

		// Append the title of the workflow
?>

    <br /><br /><strong><?php print $workflow_name ?></strong>
    <table width="100%" border="0">

<?php
		foreach ($workflow as $activity_counter => $activity) {
			
			if ($activity['activity_name'] == NULL) {
				break;
			}
?>

			<tr>
      
<?php
			for ($column_count = 0; $column_count <= $max_y; $column_count++) {

				if ($activity['y'] == $column_count) {
?>

					<td class="activity" style="text-align:center; background-color:#7ba7cf; border-color:#000000; margin:10px; padding:10px;">
					  <span style="font-weight:bold;"><?php print $activity['activity_name'] ?></span> (<?php print $activity['activity_count'] ?>)
					</td>
					
<?php
					// End of flow at this level, render down pointer
					if (($activity['x'] != $workflow[$activity_counter + 1]['x']) && ($column_count + 1 == $workflow[$activity_counter + 1]['y'])) {
						
						foreach ($activity['activity_outputs'] as $output) {
							
							if ($output == 'end') {
								break;
							}

?>

							<td style="text-align:center; font-weight:bold; background-color: #dcdcdc; margin:10px; padding:10px;">-v</td>
              
<?php
							$column_count++;
							
						}
					
					}
					
				} // Vertical marker
				elseif ($activity['y'] > $column_count) {
?>

					<td class="vertical-marker" style="text-align:center; font-weight:bold; background-color: #dcdcdc; margin:10px; padding:10px;">|</td>
          
<?php
				} // Flow left market
				elseif ($activity['activity_name'] == 'end') {
?>

					<td class="end-column" style="text-align:center; font-weight:bold; background-color: #dcdcdc; margin:10px; padding:10px;"><|</td>
          
<?php
				} // Empty cell
				else {
?>

					<td>&nbsp;</td>
          
<?php
				}

			}
?>

			</tr>
      
<?php
		}
?>

		</table>
    
<?php
	}
?>