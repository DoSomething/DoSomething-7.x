(function ($) {
  Drupal.behaviors.jeans12_nav = {
    attach: function (context, settings) {

    // this is lazy
    var rsvp = '/rsvp';
    if (window.location.pathname.substring(urlCount,30) == rsvp){
      $('#block-dosomething-campaign-styles-campaign-nav').hide();
    }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
