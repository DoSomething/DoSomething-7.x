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
          message: 'This is the message.',
          name: 'This is the name.',
          caption: 'This is the caption.',
          picture: 'http://files.dosomething.org/files/campaigns/spit/logo.png',
          description: 'This is the description',
          link: window.location.href
        };
        for (var i in friends) {
          FB.api('/'+friends[i]+'/feed', 'post', fbObj, function(response) {
            console.log(response)
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
