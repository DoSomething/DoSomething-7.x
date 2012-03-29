(function($) {
  Drupal.behaviors.clubAutofill = {
    attach: function(context, settings) {
      var initial_value = 'Start typing...';
      var $field = $('input#edit-field-school-reference-und-0-target-id-name');
      $field.css('color', '#CCC').val(initial_value);

      $field.focus(function() {
        if ($field.val() === initial_value || $field.val() === '') {
          $field.css('color', '#000').val('');
        }
      });

      $field.blur(function () {
        if ($field.val() === '') {
          $field.css('color', '#CCC').val(initial_value);
        }
      });
    }
  }
}(jQuery));
