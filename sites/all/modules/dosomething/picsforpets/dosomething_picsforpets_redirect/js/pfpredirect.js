(function ($) {
Drupal.behaviors.picsforpetsRedirect = {
  attach: function (context, settings) {
    var iframe = (window.location != window.parent.location) ? true : false;
    if (!iframe) {
      settings.picsforpetsFBAuth = settings.picsforpetsFBAuth || {app_secure_url : "https://apps.facebook.com/picsforpets"};
      window.location.href = settings.picsforpetsFBAuth.app_secure_url;
    }
  }
};
}(jQuery));
