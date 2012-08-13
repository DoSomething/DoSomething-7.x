var button;
var userInfo;

window.fbAsyncInit = function() {
  FB.init({
        appId: '169271769874704',
        status: true, 
        cookie: true,
        xfbml: true,
        oauth: true
  });

  FB.getLoginStatus(updateButton);
  FB.Event.subscribe('auth.statusChange', updateButton);
}

function updateButton(response) {
    button = jQuery('.robocalls-fb-find-friends-birthdays');
    
    button.click(function() {
      window.open('/sites/all/modules/dosomething/features/robocalls/facebook_popup.php', 'fbinfo', 'location=no,width=350,height=400,resizable=no,scrollbars=no,status=no,titlebar=no,toolbar=no');
      return false;
    });

    return false;
}

function remove_fb_bday_choice()
{
  if (confirm('Remove this person from your Facebook choice? We can\'t send them a message unless they\'re listed here.'))
  {
    jQuery('#well-send-to').find('li').remove();
    jQuery('#well-send-to').hide();
  }
  return false;
}

(function ($) {
  $.fn.extend({
    dsRobocallsDone: function (name, cause) {
      delete Drupal.behaviors.dosomethingLoginRegister;

      var popupForm = $('#dosomething-robocalls-submitted-message');
      if (name && cause)
      {
        html = popupForm.html();
        replaced = html.replace('#name#', name).replace('#cause#', cause);

        $('#dosomething-robocalls-submitted-message').html(replaced);
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

      var h = new Object();
      history.pushState(h, '', window.location.href.replace(/\?done=.+/, ''));
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
      if (!hash2)
      {
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
  if (jQuery('#edit-submitted-field-celebrity-chooser-und').length > 0)
  {
    jQuery('#edit-submitted-field-celebrity-chooser-und').change(function() {
      jQuery('#edit-submitted-field-celeb-tid-und-0-value').val(jQuery(this).val());
    });
  }

  var auds = jQuery('span.file').find('a');
  if (auds.length > 1)
  {
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

  if (jQuery('#robocalls_preview_link').length > 0)
  {
    jQuery('#robocalls_preview_link').click(function() {
      jQuery('#robocalls-preview-audio').trigger('play');
      return false;
    });
  }
});

