(function ($) {

Drupal.behaviors.dosomethingFBApps = {
  attach: function (context, settings) {
    var $context = $(context);
    var $form = $context.find('#dosomething-fb-apps-enter-zip-form');
    $form.hide();
    settings.dosomethingFBApps = settings.dosomethingFBApps || {
      fbZip : false,
      fbClickMe : false,
      fbAnimalSelected : ''
    };

    // Crazy autosubmit if we land on a view page and need our sort options
    // reset.
    if (settings.dosomethingFBApps.fbClickMe) {
      // Set the select and click the button.
      $context.find('select[name=field_fb_app_animal_type_value]').val(settings.dosomethingFBApps.fbAnimalSelected);
      $context.find('select[name=sort_by]').val('closest_to_me');
      $context.find('#edit-submit-pics-for-pets-gallery').click();
    }

    // Only make the pop occur if we are on the 'closest to me setting' and we
    // don't have a zip.
    $context.find('#views-exposed-form-pics-for-pets-gallery-panel-pane-1 select[name=sort_by]').change(function() {
      if ($(this).val() == 'closest_to_me' && !settings.dosomethingFBApps.fbZip) {
        // Stash the selcted animal filter for later use.
        settings.dosomethingFBApps.fbAnimalSelected = $('select[name=field_fb_app_animal_type_value]').val();
        var dialog = $form.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          top: 180,
          width: 550,
        });
      }
    });
  }
};

})(jQuery);
