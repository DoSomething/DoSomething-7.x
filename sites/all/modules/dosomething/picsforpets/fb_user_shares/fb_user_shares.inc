<?php

require_once(DRUPAL_ROOT . '/' . libraries_get_path('facebook') . '/facebook.php');
// Facebook allows a maximum of 50 batch requests per query.
define('PICS_BATCH_LIMIT', 50);

// Do Something App
$config = array(
	'appId' => '105775762330',
	'secret' => '68e767e16e139277b1e7d2e2ba16a4f6'
);
// Initialize Facebook
$facebook = new Facebook($config);

// EntityFieldQuery to check for adopted, but un-messaged, pets.
$q = new EntityFieldQuery;
$result = $q
	->entityCondition('entity_type', 'webform_submission_entity')
	->propertyCondition('nid', 724609)
	->propertyCondition('uid', 0, '>')
	->propertyOrderBy('submitted', 'DESC')
	->fieldCondition('field_sent_adopted_message', 'value', array(NULL, 0), 'IN')
	->fieldCondition('field_fb_app_adopted', 'value', 1, '=')
	->execute();

if (!empty($result['webform_submission_entity'])) {
	foreach ($result['webform_submission_entity'] AS $key => $r) {
		// Grab the submission information.
		$s = array_shift(entity_load('webform_submission_entity', array((int) $key)));

		// If we haven't sent the notifications yet...
		if (empty($s->field_sent_adopted_message[LANGUAGE_NONE][0]['value'])) {

			// Grab the sharers for that particular pet.
			$shares = db_select('fb_user_shares', 's')
				->fields('s', array('fb_user_id'))
				->condition('entity_id', $s->sid, '=')
				->orderBy('sid', 'DESC')
				->distinct()
				->execute();
			$r = $shares->fetchAll();
			
			$b = $i = 0;
			$batches = array();
			foreach ($r AS $key => $id) {
				//$id->fb_user_id;
				$animal_name = $s->field_fb_app_animal_name[LANGUAGE_NONE][0]['value'];

				// Send a Facebook to the user.
				/*$r = $facebook->api('/' . $id->fb_user_id . '/notifications', 'POST', array(
				  'access_token' => '105775762330|pmFm2r3S-p7merbypvN2EANG4UI',
				  'href' => 'http://www.dosomething.org',
				  'template' => $animal_name . ' got adopted thanks to you! Click to share more pets on Pics for Pets.'
				));*/

				// If we've reached the batch limit, create a new batch request.
				if ($i == PICS_BATCH_LIMIT) {
					$b++;
					$i = 0;
				}

				// Single batch request.
				$batches["$b"][] = array(
					'method' => 'POST',
					'relative_url' => '/' . $id->fb_user_id . '/notifications',
					'body' => 'access_token=105775762330|pmFm2r3S-p7merbypvN2EANG4UI&href=http://www.dosomething.org&template=' . $animal_name . ' has been adopted, thanks in part to your shares! Check out the new additions to the gallery to share more animals that need homes on Pics for Pets.'
				);

				$i++;
			}

			if (!empty($batches)) {
				foreach ($batches AS $key => $batch) {
					$b = json_encode($batch);
					$res = $facebook->api('?batch=' . urlencode($b), 'POST');

					//print_r($res);
				}
			}

			// Update the adopted message field to reflect the sent messages, so we don't spam everyone forever.
			$s->field_sent_adopted_message[LANGUAGE_NONE][0]['value'] = 1;
			// And re-save the entity.
			@entity_save('webform_submission_entity', $s);
		}
	}
}