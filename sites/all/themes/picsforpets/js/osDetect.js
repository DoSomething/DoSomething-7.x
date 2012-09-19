(function ($) {
  Drupal.behaviors.mobileAppDownload = {
    attach: function (context) {
      var is_iOS = false;
      var iDevice = ['iPad', 'iPhone', 'iPod'];
      var isAndroid = false;

      // Check if iOS device from navigator.platform
      var i;
      for (i = 0; i < iDevice.length; i++) {
        if (navigator.platform === iDevice[i]) {
          is_iOS = true;
          break;
        }
      }

      // For Android mobile, check for 'android' and 'mobile'
      var ua = navigator.userAgent.toLowerCase();
      if (ua.indexOf('android') > -1 && ua.indexOf('mobile') > -1) {
        isAndroid = true;
      }

      if (is_iOS || isAndroid) {
        var confirmString;
        var storeLocation;
        if (is_iOS) {
          confirmString = 'Download the Pics for Pets mobile app in the App Store!';
          storeLocation = 'http://itunes.apple.com/app/facebook/id284882215';
        }
        else if (isAndroid) {
          confirmString = 'Download the Pics for Pets mobile app in the Google Play Store!';
          storeLocation = 'https://play.google.com/store/apps/details?id=org.dosomething.android';
        }

        var mobileDetectPrompt = confirm(confirmString);
        if (mobileDetectPrompt == true) {
          window.location = storeLocation;
        }
      }
    }
  }
})(jQuery);
