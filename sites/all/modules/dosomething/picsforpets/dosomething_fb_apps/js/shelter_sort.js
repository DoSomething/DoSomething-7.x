(function ($) {

Drupal.behaviors.dosomethingFBApps = {
  attach: function (context, settings) {
    var $context = $(context);
    var $form = $context.find('#dosomething-fb-apps-enter-zip-form');
    $form.hide();
    settings.dosomethingFBApps = settings.dosomethingFBApps || {fbZip : false};
    // Only make the pop occur if we are on the 'closest to me setting' and we
    // don't have a zip.
    $context.find('#views-exposed-form-pics-for-pets-gallery-panel-pane-1 select[name=sort_by]').change(function() {
      if ($(this).val() == 'closest_to_me' && !settings.dosomethingFBApps.fbZip) {
        var dialog = $form.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550,
        });
      }
    });
  }
};

})(jQuery);
