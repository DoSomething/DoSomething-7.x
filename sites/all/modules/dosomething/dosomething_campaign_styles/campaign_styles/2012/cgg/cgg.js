(function($) {
Drupal.behaviors.cgg = {
	attach: function(context, settings) {
	  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
    if (window.location.hash) {
      var error = '<div class="messages error"><ul><h2>' + Drupal.t("Hey! Now that you're logged in make sure you submit your vote again so we can record it!") + '</h2></ul></div>';
      $(error).insertBefore('.webform-client-form').css({
        'position': 'relative',
        'top': '-85px',
        'margin': '0px 0 -80px',
        'border-radius': '5px',
        'padding': '11px',
        'padding-left': '20px',
        'height': '55px',
      });
    }
	}	
};

  $.fn.extend({
    dsCGGSubmit: function (url, is_user) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      var loginForm = $('#dosomething-login-login-popup-form');

      // change the text of the popup
      popupForm.find('#edit-title-text label')
        .text("Woot! Almost there.")
        .after('<h2>Be sure your vote is authenticated!</h2>');

      loginForm.find('#edit-title-text--2 label')
        .text("Woot! Almost there.")
        .after('<h2>Make sure your vote is authenticated.</h2>');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination='+url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination='+url);
      loginForm.attr('action', '/user?destination='+url);

      loginForm.find('.connect-with-facebook a').attr('href', loginForm.find('.connect-with-facebook a').attr('href').replace('/redirect_uri=[^&]+/', '/redirect_uri=ahhhhhhh'));

      url = document.location.protocol + '//' + document.location.host + '/' + url;
      popupForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          document.location.href = url;
        }
      });
      loginForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          document.location.href = url;
        }
      });

      var form = popupForm;
      var other = loginForm;
      if (is_user) {
        form = loginForm;
        other = popupForm;
      }

      // Firefox doesn't grab the proper event.srcElement above...
      // ...so we have to fake it.
      other.bind('dialogopen', function(event, ui) {
        $(this).parent().find('a.ui-dialog-titlebar-close').click(function() {
          form.dialog('close');
          document.location.href = url;
        });
      });

      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        dialogClass: 'cgg-pop-up',
        open: function(event, ui) {
          $('.cgg-pop-up a.ui-dialog-titlebar-close').click(function() {
            form.dialog('close');
            document.location.href = url;
          });
        },
      });
    }
  });

})(jQuery);
