(function ($) {
  /**
   * Our school name look up widget needs to change its URL when the selects
   * change.
   */
  Drupal.behaviors.dsSchoolAutocomplete = {
    attach: function (context) {
      $('.field-widget-dosomething-school-autocomplete:not(.dsschool-processed)', context).each( function(index, element) {
        var $wrapper = $(element)
          , $selects = $wrapper.find('select')
          , $state = $wrapper.find('select.ds-school-state')
          , $type = $wrapper.find('select.ds-school-type')
          , $schoolName = $wrapper.find('input.form-autocomplete')

        // If they enter a new school name we need to have them provide
        // additional information.
        function schoolHandler(event) {
          var value = $schoolName.val() || ''
            , $addressFields = $wrapper.find('div.form-type-textfield:not([role=application])');

          // FIXME figure out how to do this with form states... it seems so much nicer.
          if (value == '' || value.match(/.+\((\d+)\)/)) {
            $addressFields.fadeOut();
          }
          else {
            $addressFields.fadeIn();
          }
        };
        $schoolName.blur(schoolHandler);
        // Run it after it's attached to hide the fields if it's an existing
        // school. NOTE: if we're using form states this might not be necessary.
        schoolHandler();

        // When either select changes, we need to update the autocomplete URL.
        $selects.change(function(e) {
          $schoolName
            .unbind() // Unbind the previous autocomplete handlers.
            .val('')  // Empty its value.
            .each(function(i) {
              // Update the URL stored in the hidden input element.
              var $autocomplete = $('#' + this.id + '-autocomplete'),
                  val = $autocomplete.val();
              $autocomplete
                // Mark as not processed.
                .removeClass('autocomplete-processed')
                // Update autocomplete URL.
                .val(val.match('.*autocomplete/') + $type.val() + '/' + $state.val());
              // Remove the ARIA element.
              $('#' + this.id + '-autocomplete-aria-live').remove();
            })
            .blur(schoolHandler);
          // Now re-generate the autocomplete.
          Drupal.behaviors.autocomplete.attach($wrapper);

          // Make sure our blur hander gets reattached.
          $schoolName.blur(schoolHandler);
        });
      }).addClass('dsschool-processed');
    }
  };

  /**
   * Our school name look up widget needs to change its URL when the selects
   * change.
   */
  Drupal.behaviors.dsSchoolCountryChange = {
    attach: function (context) {
      $('select.ds-school-country', context).change( function() {
        var $wrapper = $('#field-webform-school-reference-add-more-wrapper')
          , $country = $(this)
          , $state = $wrapper.find('select.ds-school-state')
          , $level = $wrapper.find('select.ds-school-type')
          , $zip_wrapper = $('.field-name-field-webform-school-zip')
          , selected_country = $country.val();

        url = '/ds_school/region_by_country/' + $country.val();
	$.getJSON(url, function(data) {
          $state.empty();
          $level.empty();
          $('<option/>').val('').html('School State').appendTo($state);
          if (selected_country != 'US')  
            $zip_wrapper.hide().find('#edit-field-webform-school-zip-und-0-value').val('');
          else
            $zip_wrapper.show();
          
          for(var abbrev in data) {
            if (data.hasOwnProperty(abbrev)) {
              $('<option/>').val(abbrev).html(data[abbrev]).appendTo($state);
            }
          }	
          console.log(data);
        });

      });
    }
  };
}(jQuery));

