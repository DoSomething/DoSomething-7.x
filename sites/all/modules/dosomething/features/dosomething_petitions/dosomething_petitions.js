(function ($) {
  Drupal.behaviors.dosomethingPetitions = {
    attach: function (context, settings) {
      // check if the browser supports placeholder elements
      var placeholder = (function () {
        var i = document.createElement('input');
        return 'placeholder' in i;
      })();

      $reasonWrapper = $('.form-item-submitted-field-webform-petition-reason-und-0-value');
      $reasonBox = $reasonWrapper.find('.form-textarea-wrapper');
      $reasonLabel = $reasonWrapper.find('label');
      $signatureCheckbox = $('#edit-submitted-field-webform-petition-signature--2');
      $signShortcut = $('#sign-petition-scroller');

      $signatureCheckbox.appendTo($('.pane-node-webform .webform-client-form>div'));

      // add the "Add a reason" link
      $displayReasonLink = $('<a>')
        .attr('id', 'add-reason-link')
        .text('Add one')
        .click(function () {
          $reasonBox.slideToggle();
        });
      
      $reasonBox.hide();
      $reasonLabel.append($displayReasonLink);

      // make the secondary sign button do something
      $signShortcut.click(function () {
        $form = $('.pane-node-webform');
        $('html, body').animate({scrollTop: $form.offset().top}, 300);
        $form
          .css('-webkit-box-shadow', '#18408B 0 0 12px')
          .css('-moz-box-shadow', '#18408B 0 0 12px')
          .css('box-shadow', '#18408B 0 0 12px');
        return false;
      });

      // convert labels to placeholders
      if (placeholder) {
        var $form = $('.webform-client-form, #dosomething-petitions-email-form');
        $form.find('label').each(function (idx, e) {
          e = $(e);
          $field = $('#'+e.attr('for'));
          if ($field.attr('type') == 'text') {
            e.hide();
            $field.attr('placeholder', e.text());
          }
        });
      }
    }
  };

  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
  $.fn.extend({
    dsPetitionSubmit: function (url, is_user) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      fName = $('#edit-submitted-field-webform-first-name-und-0-value--2').val();
      lName = $('#edit-submitted-field-webform-last-name-und-0-value--2').val();
      e_or_m = $('#edit-submitted-field-webform-email-or-cell-und-0-value--2').val();

      var is_email = Drupal.dsRegistration.validEmail(e_or_m);
      var is_mobile = Drupal.dsRegistration.validPhone(e_or_m);

      // set the values on the popup form based on user input
      loginForm.find('input[name="name"]').val(e_or_m);

      if (is_email) {
        popupForm.find('input[name="email"]').val(e_or_m);
      }
      if (is_mobile) {
        popupForm.find('input[name="cell"]').val(e_or_m);
      }
      popupForm.find('input[name="first_name"]').val(fName);
      popupForm.find('input[name="last_name"]').val(lName);

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("You've Signed.")
        .after('<h2>Now get the benefits of being a full member.</h2>');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      // Firefox fix
      $('.ui-icon-closethick').click(function() {
        window.location.reload();
      });

      popupForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          window.location.reload();
        }
      });
      loginForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          window.location.reload();
        }
      });

      var form = popupForm;
      if (is_user) {
        form = loginForm;
      }
      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });
    }
  });

  $.fn.extend({
    dsPetitionsInviteEmails: function (petition) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popup = $('<div></div>').attr('id', 'contacts-scraper-dialog');
      popup.append($('<iframe></iframe>').attr('id', 'email-scraper').css('width', '500px').css('height', '600px').css('border', '0px').css('background', '#fff').attr('src', '/contacts-scraper/' + petition));
      // popup!
      popup.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });

      return false;
    }
  });
})(jQuery);

function base64_decode (data) {
    var b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    var o1, o2, o3, h1, h2, h3, h4, bits, i = 0,
        ac = 0,
        dec = "",
        tmp_arr = [];

    if (!data) {
        return data;
    }

    data += '';

    do { // unpack four hexets into three octets using index points in b64
        h1 = b64.indexOf(data.charAt(i++));
        h2 = b64.indexOf(data.charAt(i++));
        h3 = b64.indexOf(data.charAt(i++));
        h4 = b64.indexOf(data.charAt(i++));

        bits = h1 << 18 | h2 << 12 | h3 << 6 | h4;

        o1 = bits >> 16 & 0xff;
        o2 = bits >> 8 & 0xff;
        o3 = bits & 0xff;

        if (h3 == 64) {
            tmp_arr[ac++] = String.fromCharCode(o1);
        } else if (h4 == 64) {
            tmp_arr[ac++] = String.fromCharCode(o1, o2);
        } else {
            tmp_arr[ac++] = String.fromCharCode(o1, o2, o3);
        }
    } while (i < data.length);

    dec = tmp_arr.join('');

    return dec;
}

function invite_find_emails() {
  var code = jQuery('#invite_data').val();
  jQuery.fn.dsPetitionsInviteEmails(code);
  return false;
}

function launch_fb_share() {
  jQuery('#petition-fb').click();
}

function close_scraper() {
  jQuery('#contacts-scraper-dialog').dialog('close');
}