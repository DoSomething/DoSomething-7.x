(function($) {
	$(document).ready(function() {
		// List out the sections to toggle:
		var projectSections = ["sms-referral", "sms-example", "cta", "action-items", "prizes", "info", "profiles", "faq", "gallery"];
		// Loop through the sections:
		for (var i = 0; i < projectSections.length; i++) {
			// Hide all sections on page load:
			$('.group-project-'+projectSections[i]).hide();
			// Display matching group for any sections checked:
			if ($('#edit-field-project-section-display-und-'+projectSections[i]).is(":checked")) {
				$('.group-project-'+projectSections[i]).show();
			}
			// Create listeners for changes to each checkbox to toggle matching group:
		  $('#edit-field-project-section-display-und-'+projectSections[i]).bind("change", {counter: i}, function (event) {
		     $('.group-project-'+projectSections[event.data.counter]).fadeToggle(this.checked);
		  });
		}
	});
})(jQuery);
