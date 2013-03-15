(function ($) {
  Drupal.behaviors.robocalls_front = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],
    previewing: false,

    attach: function(context, settings) {
      // Show name and preview/share on hover
      $('.views-field-nothing').mouseover(function() {
        $(this).find('.name, .preview-share').show();
      });

      // Hide name and preview/share on mouseout
      $('.views-field-nothing').mouseout(function() {
        $(this).find('.name, .preview-share').hide();
      });

      // Annoying fix for the ??? "celebrity" preview bar.
      $('a[data-tid="9501"]').parent().parent().remove();

      // Share a celebrity from the gallery.
      if ($('.share-single-celeb').length) {
        $('.share-single-celeb').click(function() {
          var elm = $(this).parent().parent().parent();
          var img = document.location.origin + elm.find('img').attr('src');
          var name = elm.find('.name a').text();
          var href = document.location.origin + elm.find('.name a').attr('href');

          // Share the celebrity on Facebook.
          Drupal.behaviors.fb.feed({
            'feed_document': href,
            'feed_title': name + ' will prank your friends!',
            'feed_picture': img,
            'feed_description': name + ' can prank dial your friends from DoSomething.org\'s Project Prank!',
            'feed_allow_multiple': true,
            'feed_require_login': true,
          });

          return false;
        });
      }

      if ($('.facebook-share-call').length) {
        // If we've sent a call, let us share that call.
        $('.facebook-share-call').click(function() {
          var call = Drupal.settings.call;
          Drupal.behaviors.fb.feed({
            'feed_document': call.celeb_path,
            'feed_title': 'I just prank called my friends with a call from ' + call.celeb_name + '!',
            'feed_picture': call.celeb_image,
            'feed_caption': '',
            'feed_description': 'Seriously, check out DoSomething.org\'s Project Prank.',
            'feed_allow_multiple': true,
            'feed_require_login': true
          });
          return false;
        });
      }

      /**
       *  Basic stuff:
       *   - Builds "fake" input fields from celebrity information
       *   - Adds "fake" input fields to form.
       */
      var new_field, f = '';
      // Fake fields
      new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

      // Celebrity select list.
      var celebs = '';
      if (typeof Drupal.settings.calloffame != 'undefined') {
        for (i in Drupal.settings.calloffame.celebs) {
          celebs += '<option value="' + i + '">' + Drupal.settings.calloffame.celebs[i] + '</option>';
        }
      }

      // Select and inpout...
      select = '<select name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select robo-select-celeb"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
      input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="additional-friends form-text" placeholder="Friend\'s Number" />';

      // Add fields x2, with replacement variables..replaced.
      n = Drupal.behaviors.robocalls.friends_field_count;
      for (var i = n; i < (n + 2); i++) {
        f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
        Drupal.behaviors.robocalls.friends_field_count++;
      }

      // Add to form
      $(f).insertAfter('#webform-component-friends-info--primary-friend');
      $('.additional-friends').mask("(999) 999-9999");
      // Confirm that first select option is called "Select Call"
      $('option[value=""]').text('Select Call');

      $('#edit-submitted-friends-info-primary-friend-select-call').change(function() {
        var s = $(this).find(':selected').val();
        $('.robo-select-celeb').each(function() {
          // Ensure we're only overriding select boxes that don't have something pre-chosen
          if ($(this).find(':selected').val() == "") {
            // Set the value of the select box to this value.
            $(this).val(s);
          }
        });
      });

      // Add 3 more friends when you click the "Add more friends" link.
      $('.add-more-friends-front').click(function() {
        var n = Drupal.behaviors.robocalls.friends_field_count;
        if (n >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
          return false;
        }

        var new_field, f = '';
        new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

        select = '<select name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select robo-select-celeb"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
        input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="additional-friends form-text" placeholder="Friend\'s Number" />';

        n = Drupal.behaviors.robocalls.friends_field_count;
        for (var i = n; i < (n + 3); i++) {
          f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
          Drupal.behaviors.robocalls.friends_field_count++;
        }

        if (Drupal.behaviors.robocalls.friends_field_count >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
        }

        $(f).appendTo('#webform-component-friends-info').queue(function() {
          $('.additional-friends').mask("(999) 999-9999");
          if ($('#edit-submitted-friends-info-primary-friend-select-call').val() != "") {
            $('.robo-select-celeb').each(function() {
              if ($(this).val() == "") {
                $(this).val($('#edit-submitted-friends-info-primary-friend-select-call').val());
              }
            });
          }
        });
        return false;
      });
    }
  };
})(jQuery);
