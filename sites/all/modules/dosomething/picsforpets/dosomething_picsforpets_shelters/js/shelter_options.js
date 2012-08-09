(function ($) {
  Drupal.behaviors.picsforpetsShelterOptions = {
    attach: function (context, settings) {
      settings.picsforpetsShelterOptions = settings.picsforpetsShelterOptions || {
        showSelect : false, 
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
      // Conditionally hide or show the Address Form
      var field = $('.conditional-address-fieldset');
      if ($('.shelter-results-option-list input[name=results]:checked').val() == -1) {
        field.show();
      }
      else {
        field.hide();
      }

      // Conditionally hide or show the select button
      if (settings.picsforpetsShelterOptions.showSelect) {
        $('#edit-select-shelter').show();
      }
      else {
        $('#edit-select-shelter').hide();
      }

      $('.shelter-results-option-list input[name=results]').change(function() {
        var x = $(this).val();
        if (x == -1) {
          field.show();
        }
        else {
          field.hide();
        }
      });
    }
  };
})(jQuery);
