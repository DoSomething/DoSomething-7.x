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
