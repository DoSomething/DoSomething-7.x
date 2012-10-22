(function($) {
	$(document).ready(function() {
		$('#edit-title').attr('placeholder', 'Search by Title');
		$('#edit-distance-postal-code').attr('placeholder', 'Search by ZIP');
		$('#edit-submit-clubs, #edit-reset').addClass('go-button');
	});
})(jQuery);