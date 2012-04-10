(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      //do stuff. no need for document.ready
    }
  };

	// PROJECT IDEAS DROPDOWN FUNCTIONALITY
	$(document).ready(function() {
		$('#recycling').click(function () {
			$('#recycling-ideas').slideToggle();
		});
	});

	$(document).ready(function() {
		$('#energy-ideas').hide();
		$('#energy').click(function () {
			$('#energy-ideas').slideToggle();
		});
	});

	$(document).ready(function() {
		$('#green-agriculture-ideas').hide();
		$('#green-agriculture').click(function () {
			$('#green-agriculture-ideas').slideToggle();
		});
	});

	$(document).ready(function() {
		$('#bring-it-home-ideas').hide();
		$('#bring-it-home').click(function () {
			$('#bring-it-home-ideas').slideToggle();
		});
	});

	$(document).ready(function() {
		$('#other-ideas').hide();
		$('#other').click(function () {
			$('#other-ideas').slideToggle();
		});
	});

})(jQuery);

