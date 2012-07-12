(function ($) {
  /**
   * Our school name look up widget needs to change its URL when the state
   * changes.
   */
  Drupal.behaviors.dsSchoolAutocomplete = {
    attach: function (context) {
      $('.field-widget-dosomething-school-autocomplete:not(.dsschool-processed)', context).each( function(index, element) {
        var $wrapper = $(element)
          , $state = $wrapper.find('select')
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

        // When the state select changes we need to update the autocomplete URL.
        $state.change(function(e) {
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
                .val(val.substr(0, val.lastIndexOf('/') + 1) + $state.val());
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
}(jQuery));
