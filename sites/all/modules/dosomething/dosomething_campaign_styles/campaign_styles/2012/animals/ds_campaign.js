(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

   var contactForm = $('.pane-campaign-sign-up');
   $('#section0').append(contactForm);
	      
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
