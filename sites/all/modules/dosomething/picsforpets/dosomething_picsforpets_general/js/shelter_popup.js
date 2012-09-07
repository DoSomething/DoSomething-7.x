(function ($) {
Drupal.behaviors.picsforpetsShelterPopup = {
  attach: function (context, settings) {
    var $context = $(context);
    // Instantiate the selected shelter if it has not already been done.
    settings.picsforpetsShelterOptions = settings.picsforpetsShelterOptions || {
      selectedResult : {
        address : '',
        city : '',
        state : '',
        shelter_name : '',
        shelter_zip : '',
        shelter_nid : '',
        hours : ''
     }
    };

    // Set all the address form values that are found in settings.
    if (settings.picsforpetsShelterOptions.selectedResult.shelter_name) {
      $('#edit-field-fb-app-shelter-name-und-0-value').attr(
        {value : settings.picsforpetsShelterOptions.selectedResult.shelter_name}
      );
    }
    if (settings.picsforpetsShelterOptions.selectedResult.address) {
      $('#edit-field-fb-app-address-und-0-value').attr(
        {value : settings.picsforpetsShelterOptions.selectedResult.address}
      );
    }
    if (settings.picsforpetsShelterOptions.selectedResult.city) {
      $('#edit-field-fb-app-city-und-0-value').attr(
        {value : settings.picsforpetsShelterOptions.selectedResult.city}
      );
    }
    if (settings.picsforpetsShelterOptions.selectedResult.shelter_zip) {
      $('#edit-field-fb-app-zip-und-0-value').attr(
        {value : settings.picsforpetsShelterOptions.selectedResult.shelter_zip}
      );
    }

    // Handle the autofill of the shelter reference
    if (settings.picsforpetsShelterOptions.selectedResult.shelter_name != '' && settings.picsforpetsShelterOptions.selectedResult.shelter_nid != '') {
      $('#edit-field-fb-app-shelter-reference-und-0-target-id').attr(
        {value : settings.picsforpetsShelterOptions.selectedResult.shelter_name + ' (' + settings.picsforpetsShelterOptions.selectedResult.shelter_nid + ')'}
      );
    }

    if (settings.picsforpetsShelterOptions.selectedResult.state != '') {
      $('#edit-field-fb-app-state-und option[value="_none"]').attr(
        {"selected" : ""}
      );
      $('#edit-field-fb-app-state-und option[value=' + settings.picsforpetsShelterOptions.selectedResult.state + ']').attr(
        {"selected" : "selected"}
      );
    }

    // Set the variable.
    var $searchForm = $context.find('#dosomething-picsforpets-shelters-options-form');
    if (!$searchForm.hasClass('pics-popup')) {
      // Hide the form element to start.
      $searchForm.hide();
      $searchForm.addClass('pics-popup');
    }

    // Check to see if we should dismiss the modal.
    if (settings.picsforpetsShelterOptions.dismiss) {
      dismiss();
    }

    $context.find('.shelter-locator-popup').once('shelter-locater-popup').click(function (e) {
        // Initially we should hide the results box.
        $results = $searchForm.find('#edit-results');
        $results.hide();

        var $height = $(window).height();
        var $width = $(window).width();
        var $docHeight = $(document).height();
        var $modalWidth = 555;
        var $xPos = parseInt(($width - $modalWidth) / 2);
        var $topPos = 280;
        var $modalHeight = 500;
        $searchForm
          .addClass('ui-dialog-content')
          .addClass('ui-widget-content')
          .css('display', 'block')
          .css('width', 'auto')
          .css('min-height', '114px')
          .css('height', 'auto')
          .wrap('<div class="ui-dialog ui-widget ui-widget-content ui-corner-all " style="display: block; z-index: 1002; position: fixed; overflow: scroll; outline: 0px none; max-height: ' + $modalHeight + 'px; width: ' + $modalWidth + 'px; top: ' + $topPos + 'px; left: ' + $xPos + 'px;" tabindex="-1" role="dialog" aria-labelledby="ui-dialog-title-dosomething-picsforpets-shelters-options-form">')
          .before('<div class="ui-dialog-titlebar ui-widget-header ui-corner-all ui-helper-clearfix"><span id="ui-dialog-title-dosomething-picsforpets-shelters-options-form" class="ui-dialog-title">' + Drupal.t('Find Your Shelter') +  '</span><a class="ui-dialog-titlebar-close ui-corner-all" role="button"><span class="ui-icon ui-icon-closethick">close</span></a>');
        $('.ui-dialog')
          .after('<div class="ui-widget-overlay" style="width: ' + $width + 'px; height: ' +  $docHeight + 'px; z-index: 1001;">');

        $('.ui-icon-closethick', $searchForm.parent()).click(dismiss);
        $searchForm.show();
        return false;
    });
    function dismiss() {
      $('.ui-widget-overlay').remove();
      // Cleanup
      var $alteredForm = $('#dosomething-picsforpets-shelters-options-form');
      $alteredForm.removeClass('ui-dialog-content');
      $alteredForm.removeClass('ui-widget-content');
      $alteredForm.attr(
        {style : ''}
      );
      $alteredForm.hide();
      $('.ui-dialog.ui-widget.ui-widget-content.ui-corner-all').replaceWith($alteredForm);
      $('.field-name-field-fb-app-shelter-name').removeClass('element-hidden');
      $('.field-name-field-fb-app-address').removeClass('element-hidden');
      $('.field-name-field-fb-app-city').removeClass('element-hidden');
      $('.field-name-field-fb-app-state').removeClass('element-hidden');
      $('.field-name-field-fb-app-zip').removeClass('element-hidden');
      return false;
    }
  }
};
}(jQuery));
