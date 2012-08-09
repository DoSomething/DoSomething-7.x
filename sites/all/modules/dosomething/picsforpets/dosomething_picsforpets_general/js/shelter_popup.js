(function ($) {
Drupal.behaviors.picsforpetsShelterPopup = {
  attach: function (context, settings) {
    // Instantiate the selected shleter if it has not already been done.
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
    // Set all the address form values
    $('#edit-submitted-find-your-shelter-field-fb-app-shelter-name-und-0-value').attr(
      {value : settings.picsforpetsShelterOptions.selectedResult.shelter_name}
    );
    $('#edit-submitted-find-your-shelter-field-fb-app-address-und-0-value').attr(
      {value : settings.picsforpetsShelterOptions.selectedResult.address}
    );
    $('#edit-submitted-find-your-shelter-field-fb-app-city-und-0-value').attr(
      {value : settings.picsforpetsShelterOptions.selectedResult.city}
    );
    $('#edit-submitted-find-your-shelter-field-fb-app-zip-und-0-value').attr(
      {value : settings.picsforpetsShelterOptions.selectedResult.shelter_zip}
    );
    $('edit-submitted-find-your-shelter-field-fb-app-shelter-reference-und-0-target-id').attr(
      {value : settings.picsforpetsShelterOptions.selectedResult.shelter_nid}
    );
    if (settings.picsforpetsShelterOptions.selectedResult.state != '') {
      $('#edit-submitted-find-your-shelter-field-fb-app-state-und option[value="_none"]').attr(
        {"selected" : ""}
      );
      $('#edit-submitted-find-your-shelter-field-fb-app-state-und option[value=' + settings.picsforpetsShelterOptions.selectedResult.state + ']').attr(
        {"selected" : "selected"}
      );
    }
    /*$('#').attr(
      {value: settings.picsforpetsShelterOptions.selectedResult.shelter_name}
    );
    $('#').attr(
      {value: settings.picsforpetsShelterOptions.selectedResult.shelter_name}
    );
    */
    var $searchForm = $('#dosomething-picsforpets-shelters-options-form', context);
    if (!$searchForm.hasClass('pics-popup')) {
      $searchForm.hide(); 
      $searchForm.addClass('pics-popup'); 
    }
    //*
    $('.shelter-locator-popup', context).click(function(e) {
        $searchForm
          .addClass('ui-dialog-content')
          .addClass('ui-widget-content')
          .css('display', 'block')
          .css('width', 'auto')
          .css('min-height', '114px')
          .css('height', 'auto')
          .wrap('<div class="ui-dialog ui-widget ui-widget-content ui-corner-all " style="display: block; z-index: 1002; outline: 0px none; height: auto; width: 550px; top: 479px; left: 678px;" tabindex="-1" role="dialog" aria-labelledby="ui-dialog-title-dosomething-picsforpets-shelters-options-form">')
          .before('<div class="ui-dialog-titlebar ui-widget-header ui-corner-all ui-helper-clearfix"><span id="ui-dialog-title-dosomething-picsforpets-shelters-options-form" class="ui-dialog-title">' + Drupal.t('Find Your Shelter') +  '</span><a class="ui-dialog-titlebar-close ui-corner-all" role="button"><span class="ui-icon ui-icon-closethick">close</span></a>');
        $('.ui-dialog')
          .after('<div class="ui-widget-overlay" style="width: 1905px; height: 1572px; z-index: 1001;">');
        
        $('.ui-icon-closethick', $searchForm.parent()).click(function() {
          $searchForm.parent().hide();
          $('.ui-widget-overlay').remove();
          // Cleanup
          var $alteredForm = $('#dosomething-picsforpets-shelters-options-form');
          $alteredForm.removeClass('ui-dialog-content')
          $alteredForm.removeClass('ui-widget-content')
          $('.ui-dialog.ui-widget.ui-widget-content.ui-corner-all').replaceWith($alteredForm);
          return false;
        });
        $searchForm.show();
        return false;
    });
  }
};
}(jQuery));
