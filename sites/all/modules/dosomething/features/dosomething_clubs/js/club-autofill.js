(function($) {
  Drupal.behaviors.clubAutofill = {
    attach: function(context, settings) {
      var initial_value = 'Start typing...';
      var $field = $('input#edit-field-school-reference-und-0-target-id-name');

      $('#page-title').text('Start a Club');

      // If there's no value set a default.
      if ($field.val() === '') {
        $field.css('color', '#CCC').val(initial_value);
      }

      $('#edit-field-club-leader-birthdate-und-0-value-date').attr('placeholder', Drupal.t('MM/DD/YYYY'));
      $('#field-club-leader-birthdate-add-more-wrapper legend span').html('Date of birth <span class="form-required" title="' + Drupal.t('This field is required') + '." style="padding-left: 0px">*</span>')

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

        $('#edit-field-email-und-0-value, #edit-field-phone-required-und-0-value').focusout(function() {
          $.post('/clubs/check-account-exists', { contact: $(this).val() }, function(response) {
            if (response.status == 1) {
              delete response.status;
              $('.form-item-password label').text('Your Password');
              for (i in response) {
                $('body ' + i).val(response[i]);
              }
            }
          });
        });

        if ($('#edit-field-no-school-associate-und').attr('checked') == 'checked' || $('#edit-field-no-school-associate-und').attr('checked') == true) {
          $('#edit-field-school-reference-und-0-target-id-name').val('');
          $('#edit-field-school-reference-und-0-target-id').hide();
          $('#edit-field-noschool-club-name').show();
          $('#club-name-live').show();
          $('#dosomething-club-tag').show();
          $('#dstag').addClass('noschool');
        }

        $('#edit-field-no-school-associate-und').click(function() {
          $('input#edit-field-school-reference-und-0-target-id-name').val('');
          $('#edit-field-school-reference-und-0-target-id').toggle();
          $('.field-name-field-noschool-club-name').toggle();
          $('#club-name-live').toggle();
          if ($('#dstag').hasClass('noschool')) {
            $('#dstag').removeClass('noschool');
          }
          else {
            $('#dstag').addClass('noschool');
          }
          $('#dosomething-club-tag').toggle();
        });

      $('.form-item-field-campaign-list-und').find('label').each(function() {
        var html = $(this).html();
        if (html.indexOf('check back soon') !== -1) {
          var id = $(this).attr('for');
          $('#' + id).attr('disabled', 'disabled');
          $(this).css('color', '#808080');
        }
      });

          $('#edit-field-noschool-club-name-und-0-value').data('val',  $('#edit-field-noschool-club-name-und-0-value').val() ); // save value
          $('#edit-field-noschool-club-name-und-0-value').change(function() { // works when input will be blured and the value was changed
              // console.log('input value changed');
              $('#club-name-live').find('span').text($(this).val());
          });
          $('#edit-field-noschool-club-name-und-0-value').keyup(function() { // works immediately when user press button inside of the input
              if( $('#edit-field-noschool-club-name-und-0-value').val() != $('#edit-field-noschool-club-name-und-0-value').data('val') ){ // check if value changed
                  $('#edit-field-noschool-club-name-und-0-value').data('val',  $('#edit-field-noschool-club-name-und-0-value').val() ); // save new value
                  $(this).change(); // simulate "change" event
              }
          });

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