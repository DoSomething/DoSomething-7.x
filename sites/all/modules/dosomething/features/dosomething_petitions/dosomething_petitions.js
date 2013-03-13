(function ($) {
  Drupal.behaviors.dosomethingPetitions = {
    'twitter_message': Drupal.t('I just signed this petition! Now, it\'s YOUR turn: step up and sign here'),

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
 
      if (!url) {
        url = document.location.pathname.replace(/\//, '');
      }

      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("Shared.");
      if (!popupForm.find('h2.now').length) {
        popupForm.find('#edit-title-text label').append($('<h2 class="now">Now become a member of DoSomething.org and reap the benefits, such as scholarships, pizza parties and more.</h2>'));
      }

      loginForm.find('#edit-title-text--2 label')
        .text("Shared.");
      if (!loginForm.find('h2.now').length) {
        loginForm.find('#edit-title-text label').append($('<h2 class="now">Now become a member of DoSomething.org and reap the benefits, such as scholarships, pizza parties and more.</h2>'));
      }

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      var form = popupForm;
      var other = loginForm;
      if (is_user) {
        form = loginForm;
        other = popupForm;
      }

      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        dialogClass: 'petition-pop-up',
        open: function(event, ui) {},
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
