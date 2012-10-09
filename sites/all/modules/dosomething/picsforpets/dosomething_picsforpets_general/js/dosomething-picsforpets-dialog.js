(function ($) {

Drupal.behaviors.dosomethingPicsforpetsDialog = {
  attach: function (context, settings) {
    var $furtographyForm = $('#dosomething-picsforpets-general-furtographer-form');
    $furtographyForm.hide();
    // Be a Fur-Tographer link
    $('a.pics-for-pets-modal').click(function() {
      Drupal.behaviors.dosomethingPicsforpetsDialog.call_fb($furtographyForm);
      return false;
    });

    // FAQ links
    if ($('#page-title').text() == 'Frequently Asked Questions') {
      $('div[role=main]').find('a:not(.fieldset-title)').click(function() {
        Drupal.behaviors.dosomethingPicsforpetsDialog.call_fb($furtographyForm);
        return false;
      });
    }

    // Prizes links
    if ($('#page-title').text() == 'Prizes & Scholarships') {
      $('.pop-link').click(function() {
        Drupal.behaviors.dosomethingPicsforpetsDialog.call_fb($furtographyForm);
        return false;
      });
    }
  },

  call_fb: function(elm) {
    FB.getLoginStatus(function(response) {
        if (response.status == 'unknown') {
          // Not logged in.
          FB.login(function(response) {
            if (response.authResponse) {
              Drupal.behaviors.dosomethingPicsforpetsDialog.open_dialog(elm);
            }
          }, { scope: 'publish_actions' });
        }
        else if (response.status == 'not_authorized') {
          // Permissions.
          FB.api('/me/permissions', function (response) {
            var perms = response.data[0];
            if (!perms.publish_actions) {
              FB.ui({
              method: 'permissions.request',
              perms: 'publish_actions',
              display: 'popup'
              }, function(response) {
                // Just making sure that they have this permission.
              });
            }
          });
        }
        else {
          // Logged in.  Open the dialog.
          Drupal.behaviors.dosomethingPicsforpetsDialog.open_dialog(elm);
        }
    });

    return false;
  },

  open_dialog: function(elm) {
    var dialog = elm.dialog({
      resizable: false,
      draggable: false,
      modal: true,
      top: 180,
      position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
      width: 600,
      dialogClass: 'furtographer-pop',
      // Autofocus confuses placeholder text.
      open: function(event, ui) {
        if (typeof FB != 'undefined') { 
          FB.Canvas.scrollTo(0,0);
        }
        $("input").blur();
      }
    });
    
    elm.validate({
      rules: {
        email: {
          required: true,
          email: true
        }
      }
    });
    return false;
  }
};

}(jQuery));
