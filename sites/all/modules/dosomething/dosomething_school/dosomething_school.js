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
          , $country = $('select.ds-school-country')
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
            $addressFields.fadeIn(400, function(){
              if($country.val() == 'CA') {
                $('.form-item-submitted-field-webform-school-reference-und-0-target-id-zip').css('visibility', 'hidden');
              }
              else {
                $('.form-item-submitted-field-webform-school-reference-und-0-target-id-zip').css('visibility', 'visible');
              }
            });
          }
        };
        $schoolName.blur(schoolHandler);
        // Run it after it's attached to hide the fields if it's an existing
        // school. NOTE: if we're using form states this might not be necessary.
        schoolHandler();

        populateSelects($('select.ds-school-country').val());

        // When either select changes, we need to update the autocomplete URL.
        $selects.change(function(e) {

          // Set the type val equal to "1" if country is Canada
	        var typeVal = $('select.ds-school-country').val() == 'CA' ? 1 : $type.val();

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
                .val(val.match('.*autocomplete/') + typeVal + '/' + $state.val());
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
        populateSelects($(this).val());
      });
    }
  };

  function populateSelects(country) {
    var $wrapper;
    if ($('.field-name-field-webform-school-reference').length > 0) {
      $wrapper = $('.field-name-field-webform-school-reference');
    }
    else if ($('#edit-field-school-reference').length > 0) {
      $wrapper = $('#edit-field-school-reference');
    }

    var $state = $wrapper.find('select.ds-school-state'),
      $type = $wrapper.find('select.ds-school-type'),
      url = '/ds_school/data_by_country/' + country;

    $.getJSON(url, function(data) {
      $state.find('option').remove();
      $type.find('option').remove();
      $('<option/>').val('').html('School State').appendTo($state);
      $('<option/>').val('').html('School Type').appendTo($type);

      for(var abbrev in data.regions) {
        if (data.regions.hasOwnProperty(abbrev)) {
          $('<option/>').val(abbrev).html(data.regions[abbrev]).appendTo($state);
        }
      }
      for(var type in data.types) {
        if (data.types.hasOwnProperty(type)) {
          $('<option/>').val(type).html(data.types[type]).appendTo($type);
        }
      }

    });
  }

}(jQuery));

