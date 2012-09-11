(function ($) {
  // do stuff
  Drupal.behaviors.driveModulePopup = {
    attach: function (context, settings) {
      $module = $('.invite-module');
      $module.hide();
      $trigger = $('.trigger-invite-popup');

      $trigger.click(function () {
        $module.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550,
        });
        return false;
      });
    }
  };
}(jQuery));
