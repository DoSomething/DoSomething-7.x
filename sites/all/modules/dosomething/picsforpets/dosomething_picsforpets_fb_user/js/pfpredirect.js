(function ($) {
Drupal.behaviors.picsforpetsRedirect = {
  attach: function (context, settings) {
    var iframe = (window.location != window.parent.location) ? true : false;
    var loc = window.location.href;
    var l = loc.lastIndexOf('pics-for-pets') + 13;
    var append = window.location.href.substr(l, window.location.href.length);

    if (!iframe) {
      var fbLoginURL = 'https://www.facebook.com/dialog/oauth/';
      window.location.href =
        fbLoginURL + '?client_id=' + settings.picsforpetsFBAuth.appId + '&redirect_uri=' + settings.picsforpetsFBAuth.app_secure_url + append;
    }
  }
};
}(jQuery));
