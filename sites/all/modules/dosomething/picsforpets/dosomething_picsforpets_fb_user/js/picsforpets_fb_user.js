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
      // FB comments may need to be re-parsed following init.
      var comments = $('.fb-social-comments-plugin');
      FB.XFBML.parse(comments[0]);
    };
  }
};

})(jQuery);
