(function ($) {
Drupal.behaviors.picsforpetsRedirect = {
  attach: function (context, settings) {
    var iframe = (window.location != window.parent.location) ? true : false;
    if (!iframe) {
      var fbLoginURL = 'https://www.facebook.com/dialog/oauth/';
      window.location.href =
        fbLoginURL + '?client_id=' + settings.picsforpetsFBAuth.appId + '&redirect_uri=' + settings.picsforpetsFBAuth.app_secure_url;
    }
  }
};
}(jQuery));
