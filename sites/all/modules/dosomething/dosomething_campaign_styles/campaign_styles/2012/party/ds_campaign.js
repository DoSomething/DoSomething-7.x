(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      $('#block-dosomething-campaign-styles-campaign-nav a').click(function (event) {
				$('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
				return false;
      });
    }
  };
})(jQuery);