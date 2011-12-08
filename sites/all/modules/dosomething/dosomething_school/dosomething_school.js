(function ($) {
  /**
   * Attach behaviors for our custom autocomplete
   */
  Drupal.behaviors.dsSchoolAutocomplete = {
    attach: function (context) {
      var $wrapper = $('.field-widget-dosomething-school-autocomplete', context);
      // When the state select changes we need to update the autocomplete URL.
      $wrapper.find('select:not(.dsschool-processed)').change(function(e) {
        var $state = $(this);
        // Find the associated text box.
        $('input[type=text]', $wrapper)
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
          });
          Drupal.behaviors.autocomplete.attach($wrapper);
      }).addClass('dsschool-processed');
    } //,
  //  detach: function (context) {
  //  }
  };
}(jQuery));