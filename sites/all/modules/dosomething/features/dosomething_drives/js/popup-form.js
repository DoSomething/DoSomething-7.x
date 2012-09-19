(function ($) {
  // do stuff
  Drupal.behaviors.driveModulePopup = {
    attach: function (context, settings) {
      $module = $('.invite-module').not('.popup-processed').addClass('popup-processed');
      $module.hide();
      $trigger = $('.trigger-invite-popup').not('.popup-processed').addClass('popup-processed');

      $trigger.click(function () {
        $module.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          dialogClass: "invite_friends",
          width: 550,
          close: function () {
            $('body').hide();
            window.location.reload()
          }
        });
        return false;
      });
    }
  };
}(jQuery));
