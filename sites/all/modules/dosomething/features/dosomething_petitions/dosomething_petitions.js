(function ($) {
  Drupal.behaviors.dosomethingPetitions = {
    'twitter_message': 'I just signed a petition on DoSomething.org',

    attach: function (context, settings) {

      if (window.location.hash && window.location.hash == '#contacts') {
        $('.hidden-email-link').click();
      }
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

      if ($('#petition-twitter').length) {
        $('#petition-twitter').click(function() {
          var url = 'https://twitter.com/intent/tweet?original_referer=' + document.location.href.replace('#', '') + '&text=' + encodeURIComponent(Drupal.behaviors.dosomethingPetitions.twitter_message) + '&tw_p=tweetbutton&url=' + Drupal.settings.petition.short_url + '&via=dosomething';
          window.open(url, '_tweet', 'toolbar=no,location=no,directories=no,status=no, menubar=no,scrollbars=no,resizable=no,width=600,height=300');
          return false;
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

      //fName = $('#edit-submitted-field-webform-first-name-und-0-value--2').val();
      //lName = $('#edit-submitted-field-webform-last-name-und-0-value--2').val();
      //e_or_m = $('#edit-submitted-field-webform-email-or-cell-und-0-value--2').val();

      //var is_email = Drupal.dsRegistration.validEmail(e_or_m);
      //var is_mobile = Drupal.dsRegistration.validPhone(e_or_m);

      // set the values on the popup form based on user input
      //loginForm.find('input[name="name"]').val(e_or_m);

      //if (is_email) {
      //  popupForm.find('input[name="email"]').val(e_or_m);
      //}
      //if (is_mobile) {
      //  popupForm.find('input[name="cell"]').val(e_or_m);
      //}
      //popupForm.find('input[name="first_name"]').val(fName);
      //popupForm.find('input[name="last_name"]').val(lName);

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("Shared.")
        .after('<h2>Now become a member of DoSomething.ogr and reap the benefits, such as scholarships, pizza parties and more.</h2>');

      loginForm.find('#edit-title-text--2 label')
        .text("Shared.")
        .after('<h2>Now sign in to keep track of the actions you take on your profile.  It\'ll make it easy to add to your college applications or resume.</h2>');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      //popupForm.bind('dialogbeforeclose', function (event, ui) {
      //  if ($(event.srcElement).hasClass('ui-icon-closethick')) {
      //    window.location.reload();
      //  }
      //});
      //loginForm.bind('dialogbeforeclose', function (event, ui) {
      //  if ($(event.srcElement).hasClass('ui-icon-closethick')) {
      //    window.location.reload();
      //  }
      //});

      var form = popupForm;
      var other = loginForm;
      if (is_user) {
        form = loginForm;
        other = popupForm;
      }

      // Firefox doesn't grab the proper event.srcElement above...
      // ...so we have to fake it.
      //other.bind('dialogopen', function(event, ui) {
      //  $(this).parent().find('a.ui-dialog-titlebar-close').click(function() {
      //    form.dialog('close');
      //    window.location.reload();
      //  });
      //});

      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        dialogClass: 'petition-pop-up',
        open: function(event, ui) {
          //$('.petition-pop-up a.ui-dialog-titlebar-close').click(function() {
          //  form.dialog('close');
          //  window.location.reload();
          //});
        },
      });
    }
  });
})(jQuery);

function close_scraper_and_load_long_form() {
  jQuery('#contacts-scraper-dialog').dialog('close');
  jQuery.fn.dsPetitionSubmit();
}

function stretch_scraper() {
}

function load_fb() {
  // $.dialog('close') won't work with contacts-scraper-dialog and the animations from above.
  // Instead we have to completely remove the dialogs.
  jQuery('#contacts-scraper-dialog').remove();
  jQuery('.email-scraper-dialog').remove();
  jQuery('#petition-fb').click();
}