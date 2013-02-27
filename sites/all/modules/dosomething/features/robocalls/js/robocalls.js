(function ($) {
  Drupal.behaviors.robocalls = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],

    attach: function(context, settings) {
      $('.views-field-nothing').hover(function() {
        $(this).find('.hover-state').show();
      });


      if ($('.facebook-share-celeb').length) {
        Drupal.behaviors.fb.feed({
          'feed_document': document.location.href,
          'feed_title': 'MLK',
          'feed_picture': document.location.origin + $('.celeb-image').find('img').attr('src'),
          'feed_caption': 'Check out this call.',
          'feed_description': 'I just sent a call from DoSomething.org\'s Project Prank!',
          'feed_allow_multiple': true,
          'feed_require_login': true,
          'feed_selector': '.facebook-share-celeb'
        }, function(response) {
          console.log(response);
        });
      }
      else if ($('.facebook-share-call').length) {
        $('.facebook-share-call').click(function() {
          var call = Drupal.settings.call;
          Drupal.behaviors.fb.feed({
            'feed_document': call.celeb_path,
            'feed_title': call.celeb_name,
            'feed_picture': call.celeb_image,
            'feed_caption': 'Check out this call.',
            'feed_description': 'I just sent a call from DoSomething.org\'s Project Prank!',
            'feed_allow_multiple': true,
            'feed_require_login': true
          });
          return false;
        });
      }

      var new_field, f = '';
      new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

      var celebs = '';
      if (typeof Drupal.settings.calloffame != 'undefined') {
        for (i in Drupal.settings.calloffame.celebs) {
          celebs += '<option value="' + i + '">' + Drupal.settings.calloffame.celebs[i] + '</option>';
        }
      }

      select = '<select name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select robo-select-celeb"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
      input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" placeholder="Friend\'s Number" />';

      n = Drupal.behaviors.robocalls.friends_field_count;
      for (var i = n; i < (n + 2); i++) {
        f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
        Drupal.behaviors.robocalls.friends_field_count++;
      }

      $(f).insertAfter('#webform-component-friends-info--primary-friend');
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

      $('.add-more-friends-front').click(function() {
        var n = Drupal.behaviors.robocalls.friends_field_count;
        if (n >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
          return false;
        }

        var new_field, f = '';
        new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

        select = '<select name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select robo-select-celeb"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
        input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" placeholder="Friend\'s Number" />';

        n = Drupal.behaviors.robocalls.friends_field_count;
        for (var i = n; i < (n + 3); i++) {
          f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
          Drupal.behaviors.robocalls.friends_field_count++;
        }

        if (Drupal.behaviors.robocalls.friends_field_count >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
        }

        $(f).appendTo('#webform-component-friends-info');
        return false;
      });

      $('.add-more-friends').click(function() {
        var str = '';
        var n = Drupal.behaviors.robocalls.celeb_friends_field_count;

        for (i = n; i < (n + 3); i++) {
          str += '<div class="field-type-text field-name-field-celeb-friend-phone-5 field-widget-telwidget form-wrapper" id="edit-submitted-field-celeb-friend-phone-5"><div id="submitted-field-celeb-friend-phone-5-add-more-wrapper"><div class="form-item form-type-telfield form-item-submitted-field-celeb-friend-phone-5-und-0-value"><label for="edit-submitted-field-celeb-friend-phone-5-und-0-value">Friend\'s Number #5 </label><input placeholder="Friend\'s Number" type="tel" id="edit-submitted-field-celeb-friend-phone-5-und-0-value" name="submitted[additional_friends][' + i + ']" value="" size="20" maxlength="64" class="form-text form-tel"></div></div></div>';
          Drupal.behaviors.robocalls.celeb_friends_field_count++;
        }

        $(str).appendTo($('#webform-component-your-friends-info'));
        return false;
      });
    }
  };
})(jQuery);