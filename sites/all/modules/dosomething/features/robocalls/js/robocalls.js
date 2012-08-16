var button;
var userInfo;

function remove_fb_bday_choice() {
  if (confirm('Remove this person from your Facebook choice? We can\'t send them a message unless they\'re listed here.')) {
    jQuery('#well-send-to').find('li').remove();
    jQuery('#well-send-to').hide();
  }
  return false;
}

(function ($) {
  $.fn.extend({
    dsRobocallsDone: function (name, cause, limit) {
      delete Drupal.behaviors.dosomethingLoginRegister;

      var popupForm = $('#dosomething-robocalls-submitted-message');
      if (name && cause) {
        html = popupForm.html();
        replaced = html.replace('#name#', name).replace('#cause#', cause);

        $('#dosomething-robocalls-submitted-message').html(replaced);
        if (limit > 0)
        {
         $('#dosomething-robocalls-submitted-message label p').html("Wait!");
         $('#dosomething-robocalls-submitted-message label h2').html('This phone number has already been called today.');
         $('#dosomething-robocalls-submitted-message div.separator').prepend('<div class="robocalls-awesome-and-sharing" style="font-size: 13pt; font-weight: normal; margin-bottom: 15px;">This number has already been called for this date.  Connect with them on Facebook?</div>');
        }

        $('#robocalls-twitter-button')
          .attr('href',
              $('#robocalls-twitter-button').attr('href') + encodeURIComponent('Awesome.  I just had ' + name + ' call my friend to say "Do Something about ' + cause + '."'));
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
        .text("Call Me, Maybe?")
      var hash2 = ($('#register-benefits').length);
      if (!hash2) {
        popupForm.find('#edit-title-text label').after('<h2 id="register-benefits">Just Sign Up to Make the Call Definitely Happen.</h2>');
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

jQuery(document).ready(function() {
  var auds = jQuery('span.file').find('a');
  if (auds.length > 1) {
    auds.each(function(e) {
      var na = jQuery('<audio></audio>');
      na.attr('src', jQuery(this).attr('href'));
      jQuery(this).parent().append(na);

      jQuery(this).click(function() {
        jQuery(this).parent().find('audio').trigger('play');
        return false;
      });
    });
  }

  var timed = jQuery('.robocalls-timed-form-times');
  if (timed.length > 0) {
    jQuery('#edit-submitted-field-celeb-date-und-0-value-day, #edit-submitted-field-celeb-date-und-0-value-month, #edit-submitted-field-celeb-date-und-0-value-year').parent().hide();
    jQuery('#edit-submitted-field-celeb-date-und-0-value-day').parent().parent().prepend(jQuery('#pointless-hidden-box').val());
    //jQuery('.fieldset-wrapper').prepend('<div style="clear: both">hi!</div>');
  }

  if (jQuery('#robocalls_preview_link').length > 0) {
    jQuery('#robocalls_preview_link').click(function() {
      jQuery('#robocalls-preview-audio').trigger('play');
      return false;
    });
  }

  jQuery('#edit-field-celeb-send-now-und').click(function() {
    jQuery('#edit-submitted-field-celeb-date').toggle();
  });

  button = jQuery('.robocalls-fb-find-friends-birthdays');
  if (button.length > 0) {
     button.click(function() {
       window.open('/sites/all/modules/dosomething/features/robocalls/facebook_popup.php', 'fbinfo', 'location=no,width=350,height=400,resizable=no,scrollbars=no,status=no,titlebar=no,toolbar=no');
       return false;
     });
  }
});