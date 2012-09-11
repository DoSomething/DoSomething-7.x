(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

   var contactForm = $('.pane-campaign-sign-up');
   $('.webform').append(contactForm);

  // on lines 9-10 terrible things happen
  $('#campaign-opt-in br').remove();
  $('.ctia_top').append('&nbsp;');

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
