<h2>Your friends are crazy</h2>
<p>Connect with Facebook to see their stories.</p>
<p>Once connected, you will be able to help your friends by vouching for their story, or call BS on them.</p>
<p class="connect-with-facebook"><a href="https://www.facebook.com/login.php?api_key=<?php echo variable_get('fboauth_id'); ?>&skip_api_login=1&display=page&cancel_url=http%3A%2F%2F<?php echo CRAZY_DOMAIN; ?>%2Ffboauth%2Fconnect%3Fdestination%3D<?php echo $source; ?>%26error_reason%3Duser_denied%26error%3Daccess_denied%26error_description%3DThe%2Buser%2Bdenied%2Byour%2Brequest.&fbconnect=1&next=https%3A%2F%2Fwww.facebook.com%2Fdialog%2Fpermissions.request%3F_path%3Dpermissions.request%26app_id%3D<?php echo variable_get('fboauth_id'); ?>%26redirect_uri%3Dhttp%253A%252F%252F<?php echo CRAZY_DOMAIN; ?>%252Ffboauth%252Fconnect%253Fdestination%253D<?php echo $source; ?>%26display%3Dpage%26response_type%3Dcode%26perms%3Demail%252Cuser_birthday%26fbconnect%3D1%26from_login%3D1%26client_id%3D<?php echo variable_get('fboauth_id'); ?>&rcount=1" onclick="return Drupal.behaviors.dsCrazyScripts.fb_status();">Connect with Facebook</a></p>