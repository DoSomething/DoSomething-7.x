(function ($) {
  // do stuff
  Drupal.behaviors.driveModulePopup = {
    attach: function (context, settings) {
      $module = $('.invite-module');
      if (window.location.hash != '#invite-popup') {
        $module.not('.popup-processed').addClass('popup-processed').hide();
      }
      else {
        triggerPopup();
      }
      $trigger = $('.trigger-invite-popup').not('.popup-processed').addClass('popup-processed');

      $trigger.click(function () {
        triggerPopup();
        return false;
      });

      Drupal.friendFinder($('.fb-friend-finder-init'), 'publish_stream', function (friends) {
        var fbObj = {
          message: 'Please join my cheek swap drive and help me save a life.',
          name: 'Saving a life is as easy as giving your spit.',
          picture: 'http://files.dosomething.org/files/campaigns/spit/logo.png',
          description: 'Join your friend\'s cheek swab drive to help save the 10,000 blood cancer patients looking for a life saving donation. You can either sign up to donate, or spread the word about your friend\'s awesome drive.',
          link: window.location.href
        };
        for (var i in friends) {
          FB.api('/'+friends[i]+'/feed', 'post', fbObj, function(response) {
          });
        }
      });

      $('.invite-module-facebook').click(function () {
        $module.dialog('option', 'close', function () { return; });
        $module.dialog('close');
      });

      function triggerPopup() {
        $module.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          dialogClass: "invite_friends",
          width: 550,
          close: function () {
            $('body').hide();
            window.location.href = window.location.origin + window.location.pathname;
          }
        });
      }
    }
  };
}(jQuery));
