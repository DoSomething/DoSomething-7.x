(function ($) {

Drupal.behaviors.picsForPetsGlobalAuth = {
  attach: function(context, settings) {
    // Initialize Facebook's Javascript SDK asyncronously.
    var fbAppId = settings.picsforpetsFBAuth.appId;
    window.fbAsyncInit = function() {
      FB.init({
        appId: fbAppId,
        status: true,
        cookie: true
      });
    };
  }
};

})(jQuery);
