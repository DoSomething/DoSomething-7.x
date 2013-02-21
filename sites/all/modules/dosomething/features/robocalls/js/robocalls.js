(function ($) {
  Drupal.behaviors.robocalls = {
    friends_field_count: 1,

    attach: function(context, settings) {
      if (typeof Drupal.behaviors.fb !== 'undefined') {
        Drupal.behaviors.fb._feed_callback = function() {
          $('.robocalls-fb-find-friends-birthdays').html('Message(s) sent!');
        }
      }

      Drupal.behaviors.robocalls.friends_field_count

      var new_field, f = '';
      new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call"><label for="edit-submitted-friends-info-primary-friend-select-call">Select Call </label>#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number"><label for="edit-submitted-friends-info-primary-friend-friends-number">Friend\'s Number </label>#INPUT</div></div></fieldset>';

      select = '<select id="edit-submitted-friends-info-primary-friend-select-call" name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select"><option value="" selected="selected">- None -</option><option value="0">None</option><option value="9587">Dr. Martin Luther King</option><option value="9579">iJustine</option><option value="9499">Maci Bookout</option><option value="9449">Randall (Honey Badger)</option><option value="9580">iJustine</option><option value="9452">Hayden Panettiere</option><option value="9492">Bella Thorne</option><option value="9451">Harry Shum Jr</option><option value="9450">Randall (Honey Badger)</option><option value="9493">Shanae Grimes</option><option value="9456">Tyler Oakley</option><option value="9497">Maci Bookout</option></select>';
      input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" />';

      n = Drupal.behaviors.robocalls.friends_field_count;
      for (var i = n; i < (n + 2); i++) {
        f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
        Drupal.behaviors.robocalls.friends_field_count++;
      }

      $(f).insertAfter('#webform-component-friends-info--primary-friend');

      $('#cof-descriptive a').click(function() {
        var new_field, f = '';
        new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call"><label for="edit-submitted-friends-info-primary-friend-select-call">Select Call </label>#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number"><label for="edit-submitted-friends-info-primary-friend-friends-number">Friend\'s Number </label>#INPUT</div></div></fieldset>';

        select = '<select id="edit-submitted-friends-info-primary-friend-select-call" name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select"><option value="" selected="selected">- None -</option><option value="0">None</option><option value="9587">Dr. Martin Luther King</option><option value="9579">iJustine</option><option value="9499">Maci Bookout</option><option value="9449">Randall (Honey Badger)</option><option value="9580">iJustine</option><option value="9452">Hayden Panettiere</option><option value="9492">Bella Thorne</option><option value="9451">Harry Shum Jr</option><option value="9450">Randall (Honey Badger)</option><option value="9493">Shanae Grimes</option><option value="9456">Tyler Oakley</option><option value="9497">Maci Bookout</option></select>';
        input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" />';

        n = Drupal.behaviors.robocalls.friends_field_count;
        console.log(n);
        for (var i = n; i < (n + 3); i++) {
          f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
          Drupal.behaviors.robocalls.friends_field_count++;
        }

        $(f).insertAfter('#webform-component-friends-info--primary-friend');
        return false;
      });

      var auds = $('span.file').find('a');
      if (auds.length > 1) {
        var a = 0;

        auds.each(function(e) {
          a++;
          var na = $('<audio></audio>');
          $(this).addClass('preview-' + a);
          na.attr('src', $(this).attr('href'));
          $(this).parent().append(na);

          $(this).click(function() {
            // Stop any other previews.
            var a = $(this).attr('class').replace('preview-', '');
            $('audio').trigger('pause');
            if (!$(this).hasClass('paused')) {
              $(this).parent().find('audio').trigger('play');
              $(this).addClass('paused');
            }
            else {
              $(this).parent().find('audio').trigger('pause');
              $(this).removeClass('paused');
            }
            return false;
          });
        });
      }

      var timed = $('.robocalls-timed-form-times');
      if (timed.length > 0) {
        $('#edit-submitted-field-celeb-date-und-0-value-day, #edit-submitted-field-celeb-date-und-0-value-month, #edit-submitted-field-celeb-date-und-0-value-year').parent().hide();
        $('#edit-submitted-field-celeb-date-und-0-value-day').parent().parent().prepend($('#pointless-hidden-box').val());
      }

      if ($('#robocalls_preview_link').length > 0) {
        var previewing = false;
        $('#robocalls_preview_link').click(function() {
          if (!previewing) {
            previewing = true;
            $('#robocalls-preview-audio').trigger('play');
            $(this).find('img').attr('src', '/sites/all/modules/dosomething/features/robocalls/images/pause-preview.png');
          }
          else {
            previewing = false;
            $('#robocalls-preview-audio').trigger('pause');
            $(this).find('img').attr('src', '/sites/all/modules/dosomething/features/robocalls/images/robocall-preview.png');
          }
          return false;
        });
      }

      $('#edit-submitted-field-celeb-send-now-und').click(function() {
        $('#edit-submitted-field-celeb-date').toggle();
      });
    }
  };

  $.fn.extend({
    dsRobocallsDone: function (name, cause, limit) {
      delete Drupal.behaviors.dosomethingLoginRegister;

      var popupForm = $('#dosomething-robocalls-submitted-message');
      if (name && cause) {
        html = popupForm.html();
        replaced = html.replace('#name#', name).replace('#cause#', cause);

        // If we reach the limited number of calls, change the message.
        $('#dosomething-robocalls-submitted-message').html(replaced);
        if (limit > 0) {
         $('#dosomething-robocalls-submitted-message label p').html("Womp womp...");
         $('#dosomething-robocalls-submitted-message label h2').html('This phone number has already received this call today.  Try sending them a call from another celeb.');
         //$('#dosomething-robocalls-submitted-message div.separator').prepend('<div class="robocalls-awesome-and-sharing" style="font-size: 13pt; font-weight: normal; margin-bottom: 15px;">This number has already been called for this date.  Connect with them on Facebook?</div>');
         /*var fbb = $('.robocalls-fb-button-container').html();
         $('.with-links').html('<p style="clear: both; margin: 20px">' + fbb + '</p>');
         $('.robocalls-fb-find-friends-birthdays').click(function() {
            window.open('/sites/all/modules/dosomething/features/robocalls/facebook_popup.php', 'fbinfo', 'location=no,width=350,height=400,resizable=no,scrollbars=no,status=no,titlebar=no,toolbar=no');
            return false;
          });*/
        }

        var twitter_desc = '';
        switch (name) {
          case 'Justin Long':
            twitter_desc = 'Help your friends find their V-Spot this November 6th with a phone call from @dosomething and @JustinLong: http://dsorg.us/RdnfDl';
          break;
          case 'Tyler Oakley':
            if (cause == 'Voting') {
              twitter_desc = 'Help your friends find their V-Spot this November 6th with a phone call from @dosomething and @TylerOakley: http://dsorg.us/Rp5TRM';
            }
            else {
              twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @tyleroakley: http://dsorg.us/QNoi9j';
            }
          break;
          case 'Randall (Honey Badger)':
            if (cause == 'Animals') {
              twitter_desc = 'Let your friends know about shelter animals in need with a phone call from @dosomething and @Randallsanimals: http://dsorg.us/TCsr0G';
            }
            else {
              twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @randallsanimals: http://dsorg.us/T72khv';
            }
          break;
          case 'Hayden Panettiere':
            twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @haydenpanettier: http://dsorg.us/O15SAU';
          break;
          case 'Bella Thorne':
            twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @bellathorne: http://dsorg.us/Se77Bl';
          break;
          case 'Harry Shum Jr':
            twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @iharryshum: http://dsorg.us/T6Qt2S';
          break;
          case 'Shenae Grimes':
            twitter_desc = 'Wish your friend a happy birthday with a phone call from @dosomething and @shenaegrimes: http://dsorg.us/RXkqH3';
          break;
        }
        
        twitter_desc = encodeURIComponent(twitter_desc);

        $('#robocalls-twitter-button')
          .attr('href',
              $('#robocalls-twitter-button').attr('href') + twitter_desc);
      }

      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        height: 325,
        'dialogClass': 'robocalls-submitted-message-dialog'
      });

      var msie = /*@cc_on!@*/0;
      if (!msie) {
        var h = new Object();
        history.pushState(h, '', window.location.href.replace(/\?done=.+/, ''));
      }
    }
  });

  $.fn.extend({
    dsRobocallsSubmit: function (url, cell) {
      delete Drupal.behaviors.dosomethingLoginRegister;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      e_or_m = cell;
      var is_mobile = true;

      if (is_mobile) {
        popupForm.find('input[name="cell"]').val(e_or_m);
      }

      popupForm.find('#edit-title-text label')
        .text("Almost there!")
      var hash2 = ($('#register-benefits').length);
      if (!hash2) {
        popupForm.find('#edit-title-text label').after('<h2 id="register-benefits">Just sign up or sign in to send the call.</h2>');
      }

      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      $('#dosomething-login-login-popup-form').attr('action', '/user?destination=' + url);

      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });
    }
  });
})(jQuery);