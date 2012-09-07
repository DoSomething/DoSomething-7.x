(function($) {
  Drupal.behaviors.clubAutofill = {
    attach: function(context, settings) {
      var initial_value = 'Start typing...';
      var $field = $('input#edit-field-school-reference-und-0-target-id-name');

      // If there's no value set a default.
      if ($field.val() === '') {
        $field.css('color', '#CCC').val(initial_value);
      }

      // And monitor it for changes.
      $field
        .focus(function() {
          if ($field.val() === initial_value || $field.val() === '') {
            $field.css('color', '#000').val('');
          }
        })
        .blur(function () {
          if ($field.val() === '') {
            $field.css('color', '#CCC').val(initial_value);
          }
        });

        $('#edit-field-no-school-associate-und').click(function() {
          $('input#edit-field-school-reference-und-0-target-id-name').val('');
          $('#edit-field-school-reference-und-0-target-id').toggle();
          $('.field-name-field-noschool-club-name').toggle();
        });

      $('.form-item-field-campaign-list-und').find('label').each(function() {
        var html = $(this).html();
        if (html.indexOf('check back soon') !== -1) {
          var id = $(this).attr('for');
          $('#' + id).attr('disabled', 'disabled');
          $(this).css('color', '#808080');
        }
      });

      if ($('#edit-field-no-school-associate-und').attr('checked') == 'checked' || $('#edit-field-no-school-associate-und').attr('checked') == true) {
        $('#edit-field-school-reference-und-0-target-id-name').val('');
        $('#edit-field-school-reference').hide();
        $('#edit-field-noschool-club-name').show();
      }

      // COPPA Parent's birthday for club member signup
      if ($('.form-item-parent-email').length > 0) {
        // Show parent's email field if a person isn't old enough
        $('#edit-field-club-leader-birthdate-und-0-value-date').focusout(function() {
          var val = $(this).val();
          var d = new Date(val);
          var bday = (d.getTime() / 1000);

          var now_date = new Date();
          var y = now_date.getFullYear();
          var now = now_date.getTime() / 1000;

          var o13 = parseInt(y - 13);
          var then_13 = new Date(o13, now_date.getMonth(), now_date.getDay());
          var then = then_13.getTime() / 1000;

          if ((now - then) > (now - bday)) {
            $('.form-item-parent-email').show();
          }
          else {
            $('.form-item-parent-email').hide();
          }
        });

        // Page preloaded with birth date (like an error page) -- show the parent's email if appropriate
        var dval = $('#edit-field-club-leader-birthdate-und-0-value-date').val();
        if (dval != '') {
          $('#edit-field-club-leader-birthdate-und-0-value-date').focusout();
        }
      }
    }
  }
}(jQuery));