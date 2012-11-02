(function ($) {
  Drupal.behaviors.dosomethingHurricane = {
  	attach: function(context, settings) {
  		var loggedIn = !$('body').hasClass('not-logged-in');

  		/*if (!loggedIn) {
  			$('#bullytext-game .submit-btn').click(function() {
	  			Drupal.behaviors.dosomethingBullyGame.loginBox(function() {
	  				window.location.href = window.location.href + '?submitted=true';
	  			});
	  			return false;
	  		});
  		}*/

      $('#hurricane-text form').validate({
      	rules: {
      		'person[first_name]': {
      			required: true
      		},
      		'person[phone]': {
      			required: true
      		},
      		'friends[]': {
      			required: true
      		}
      	},

      	submitHandler: function(form) {
	  		if (!loggedIn) {
          Drupal.behaviors.dosomethingBullyGame.postSubmit();
	  			Drupal.behaviors.dosomethingBullyGame.loginBox(function() {
            window.location.href = window.location.href + '?submitted=true';
	  			});
	  			return false;
	  		}
	  		else {
	      		form.submit();
	      	}
      	}
      });
  	},

    postSubmit: function() {
      $.post(
        document.location.href,
        { 'do': 'submit-hurricane', 'stuff': $('#hurricane-text form').serialize() },
        function(response) {
          alert(response);
        }
      );
    },

  	loginBox: function(callback) {
  	  // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      delete Drupal.behaviors.dosomethingPetitions;

      if (typeof callback !== 'function') {
      	var callback = function() {
      		window.location.reload();
      	}
      }

      var url = document.location.href.replace(location.protocol + '\/\/' + document.domain + (document.location.port ? ':' + document.location.port : '') + '\/', '') + '?submitted=true';
      var is_user = true;
      var loginForm = $('#dosomething-login-login-popup-form');
      var popupForm = $('#dosomething-login-register-popup-form');

      // make sure users get directed to the right page
      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      loginForm.attr('action', '/user?destination=' + url);

      popupForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          callback();
        }
      });
      loginForm.bind('dialogbeforeclose', function (event, ui) {
        if ($(event.srcElement).hasClass('ui-icon-closethick')) {
          callback();
        }
      });

      var form = popupForm;
      var other = loginForm;

      // Firefox doesn't grab the proper event.srcElement above...
      // ...so we have to fake it.
      other.bind('dialogopen', function(event, ui) {
        $(this).parent().find('a.ui-dialog-titlebar-close').click(function() {
          form.dialog('close');
          callback();
        });
      });

      // popup!
      form.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
        dialogClass: 'bully-pop-up',
        open: function(event, ui) {
          $('.petition-pop-up a.ui-dialog-titlebar-close').click(function() {
            form.dialog('close');
            callback();
          });
        },
      });
  	}
  };
})(jQuery);